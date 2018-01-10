#include <ros/ros.h>
#include <ros/console.h>
#include <cmath>
#include <iostream>
#include <visualization_msgs/Marker.h>

#include <nav_msgs/OccupancyGrid.h>
#include <nautonomous_mpc_msgs/StageVariable.h>
#include <nautonomous_mpc_msgs/WaypointList.h>
#include <nautonomous_mpc_msgs/Obstacle.h>
#include <geometry_msgs/Point.h>
#include <nautonomous_planning_and_control_using_search/node_tree.h>
#include <Eigen/Dense>

#define INF 1000000
#define PI 3.141592653589793238462643383279502884197169399375105820974
#define sq2 1.414213562373095048801688724209698078569671875376948073176
#define sq5 2.236067977499789696409173668731276235440618359611525724270

using namespace Eigen;

MatrixXd Heap(100000,2);
MatrixXd CostMatrix(4000000,2);		// Colummn 0: cost, Colummn 1: X-pos, Colummn 2: Y-pos

MatrixXf::Index minRow, minCol;

ros::Subscriber map_sub;
ros::Subscriber start_sub;
ros::Subscriber goal_sub;
ros::Subscriber obstacle_sub;

ros::Publisher map_pub;
ros::Publisher marker_pub;
ros::Publisher marker_2_pub;

int next_node = 1;

nav_msgs::OccupancyGrid map;
nav_msgs::OccupancyGrid temp_map;
nautonomous_mpc_msgs::StageVariable start_state;
nautonomous_mpc_msgs::StageVariable goal_state;
nautonomous_mpc_msgs::StageVariable waypoint;
nautonomous_mpc_msgs::WaypointList Route;
nautonomous_mpc_msgs::Obstacle Obstacle;

node* starting_node = new node();
node* current_node = new node();
node* new_node = new node();
node* final_node = new node();

float minCost = INF;
float temp_x;
float temp_y;
float temp_theta;

float step_size = 5;

float cost_c;
float cost_i;

float map_width = 0;
float map_height = 0;
float map_center_x = 0;
float map_center_y = 0;
float resolution;

float check1 = 0;
float check2 = 0;
float check3 = 0;
float check4 = 0;
float check5 = 0;
float check6 = 0;

std::vector<node>* Network = new std::vector<node>();

geometry_msgs::Point p;
geometry_msgs::Point p1;
geometry_msgs::Point p2;


visualization_msgs::Marker line_list;
visualization_msgs::Marker route_list;

int current_node_nr = 0;
int new_node_nr = 0;
int heap_nr = 0;
int heap_length = 0;
float heap_parent = 0;
float heap_child_left = 0;
float heap_child_right = 0;
int start_node_nr = 0;
int Nx = 0;
int Ny = 0;
float new_cost = 0;

bool useplot = true;

void add_heap_element()
{	
	heap_nr = heap_length;
	heap_length++;
	std::cout << "Add heap element" << std::endl;

	Heap(heap_nr,0) = new_node->getTotalCost();
	Heap(heap_nr,1) = new_node_nr;
		
	while (true)
	{
		if (Heap(heap_nr,0) < Heap((heap_nr-1)/2,0))
		{
			Heap.row(heap_nr).swap(Heap.row((heap_nr-1)/2));
			heap_nr = (heap_nr-1)/2;
		}
		else
		{
			break;
		}
	}
}

void remove_heap_element()
{
	heap_length--;
	std::cout << "Remove heap element" << std::endl;
	Heap.row(0) = Heap.row(heap_length);
	Heap(heap_length,0) = INF;
	Heap(heap_length,1) = INF;
	
	
	heap_nr = 0;
	while (true)
	{
		heap_parent = Heap(heap_nr,0);
		heap_child_left = Heap(2*heap_nr + 1,0);
		heap_child_right = Heap(2*heap_nr + 2,0);
		if ((heap_parent < heap_child_left) && (heap_parent < heap_child_right))
		{
			break;
		}
		else if(heap_child_left < heap_child_right)
		{
			Heap.row(heap_nr).swap(Heap.row(2*heap_nr + 1));
			heap_nr = 2*heap_nr + 1;
		}
		else
		{
			Heap.row(heap_nr).swap(Heap.row(2*heap_nr + 2));
			heap_nr = 2*heap_nr + 2;
		}
	}
}

void get_minimum_node()
{
	minCost = Heap(0,0);
	minRow = CostMatrix(Heap(0,1),1);
	remove_heap_element();
	std::cout << "Cost: " << minCost << std::endl;	
	std::cout << "Row: " << minRow << std::endl;
}

void add_new_node()
{
	new_node_nr = (temp_x - map_center_x) + Nx * (temp_y - map_center_y);

	if (useplot)
	{
		p.x = current_node->getX();
		p.y = current_node->getY();
		line_list.points.push_back(p);
		p.x = temp_x;
		p.y = temp_y;
		line_list.points.push_back(p);
	}
	
	if((temp_x < -(map_width*resolution/2)) || (temp_x > (map_width*resolution/2)) || (temp_y < -(map_height*resolution/2)) || (temp_y > (map_height*resolution/2)))
	{	
		new_node->initializeNode(temp_x, temp_y, temp_theta, INF, new_cost,current_node->getNode(), new_node_nr, false);
	}
	else if((int)map.data[(floor((temp_y-map_center_y)/resolution)-1) * map_width + floor((temp_x-map_center_x)/resolution)] > 50)
	{
		new_node->initializeNode(temp_x, temp_y, temp_theta, INF, new_cost,current_node->getNode(), new_node_nr, false);
	}			
	else
	{	
		new_node->initializeNode(temp_x, temp_y, temp_theta, sqrt(pow(temp_x - goal_state.x,2) + pow(temp_y - goal_state.y,2)), new_cost,current_node->getNode(), new_node_nr, false);	
	}

	std::cout << "Node " << new_node_nr << " is at [" << temp_x << ", " << temp_y << "] at a theta of " << temp_theta << " with a cost of " << new_node->getTotalCost() << std::endl;

	if (new_node->getTotalCost() >= INF)
	{
		// Do nothing
	}
	else if (CostMatrix(new_node_nr,0) >= INF)
	{
		Network->push_back(*new_node);
		current_node->addConnectedNode(next_node);
		CostMatrix(new_node_nr,0) = new_node->getTotalCost();
		CostMatrix(new_node_nr,1) = next_node;
		add_heap_element();
		next_node++;

	}
	else if (new_node->getTotalCost() < Network->at(CostMatrix(new_node_nr,1)).getTotalCost())
	{
		Network->at(CostMatrix(new_node_nr,1)) = *new_node;
		CostMatrix(new_node_nr,0) = new_node->getTotalCost();
		CostMatrix(new_node_nr,1) = next_node;
		add_heap_element();
	}

}

void calculate_route()
{
	// Clear and initialize
	double begin_check4 = ros::Time::now().toSec();	
	p.z = 0.5;

	std::cout << "//////////////////START NEW ROUTE//////////////////" <<std::endl;

	new_node_nr = (start_state.x - map_center_x) + Nx * (start_state.y - map_center_y);
	start_node_nr = new_node_nr;

	starting_node->initializeNode(start_state.x, start_state.y, start_state.theta, sqrt(pow(start_state.x - goal_state.x,2) + pow(start_state.y - goal_state.y,2)), 0.0, 0, new_node_nr, false);

	Network->push_back(*starting_node);

	current_node = starting_node;

	CostMatrix(new_node_nr,0) = 0.0;
	CostMatrix(new_node_nr,1) = 0;

	check4 += ros::Time::now().toSec() - begin_check4;

	std::cout << "//////////////////Generate//////////////////" <<std::endl;
	double begin_check5 = ros::Time::now().toSec();	
	while (current_node->getDistToFinish() > step_size )
	{
		double begin_check2 = ros::Time::now().toSec();	
	
		if ((std::abs(fmod(current_node->getTheta(),0.5*PI)) < 0.01) || (std::abs(fmod(current_node->getTheta(),0.5*PI) - 0.5 * PI) < 0.01) || (std::abs(fmod(current_node->getTheta(),0.5*PI) + 0.5 * PI) < 0.01))
		{
			// Node right forward	
			temp_theta = current_node->getTheta() - 0.25 * PI;
			temp_x = current_node->getX() + step_size * sq2 * cos(temp_theta);
			temp_y = current_node->getY() + step_size * sq2 * sin(temp_theta);
			new_cost = current_node->getCost() + step_size * sq2;
			
			add_new_node();

			// Node forwards
		
			temp_theta = current_node->getTheta();
			temp_x = current_node->getX() + step_size * cos(temp_theta);
			temp_y = current_node->getY() + step_size * sin(temp_theta);
			new_cost = current_node->getCost() + step_size;
	
			add_new_node();

			// Node left forward
		
			temp_theta = current_node->getTheta() +  0.25 * PI;
			temp_x = current_node->getX() + step_size * sq2 * cos(temp_theta);
			temp_y = current_node->getY() + step_size * sq2 * sin(temp_theta);
			new_cost = current_node->getCost() + step_size * sq2;
			
			add_new_node();
		}

		else if ((std::abs(fmod(current_node->getTheta(),0.5*PI) - 0.25*PI) < 0.01) || (std::abs(fmod(current_node->getTheta(),0.5*PI) + 0.25*PI) < 0.01))
		{
			// Node right forward	
			temp_theta = current_node->getTheta() -  0.25 * PI;
			temp_x = current_node->getX() + step_size * cos(temp_theta);
			temp_y = current_node->getY() + step_size * sin(temp_theta);
			new_cost = current_node->getCost() + step_size;
			
			add_new_node();

			// Node forwards
			temp_theta = current_node->getTheta();
			temp_x = current_node->getX() + step_size * sq2 * cos(temp_theta);
			temp_y = current_node->getY() + step_size * sq2 * sin(temp_theta);
			new_cost = current_node->getCost() + step_size * sq2;
			
			add_new_node();

			// Node left forward
			temp_theta = current_node->getTheta() +  0.25 * PI;
			temp_x = current_node->getX() + step_size * cos(temp_theta);
			temp_y = current_node->getY() + step_size * sin(temp_theta);
			new_cost = current_node->getCost() + step_size;
			
			add_new_node();
		}

		else
		{
			std::cout << "Angle: " << fmod(current_node->getTheta(),0.5*PI) << std::endl;
			break;
		}

		check2 += ros::Time::now().toSec() - begin_check2;
		std::cout << "Elapsed time of check 2 is: " << check2 << std::endl;

		double begin_check3 = ros::Time::now().toSec();	

		CostMatrix(CostMatrix(current_node->getNode(),1),0) = INF;
	
		std::cout << "Check minimum node" << std::endl;
		get_minimum_node();

		std::cout << "Network size: " << Network->size() << std::endl;
		std::cout << "Minimum node is: " << minRow << " at " << Network->at(minRow).getNode() << std::endl;
		current_node = &Network->at(minRow);

		check3 += ros::Time::now().toSec() - begin_check3;
		std::cout << "Elapsed time of check 3 is: " << check3 << std::endl;

		double begin_check6 = ros::Time::now().toSec();	
		if (useplot)
		{
			marker_pub.publish(line_list);		
		}
		check6 += ros::Time::now().toSec() - begin_check6;
		std::cout << "Elapsed time of check 6 is: " << check6 << std::endl;

		/*if (next_node > 200)
		{
			break;
		}
		ros::Duration(0.01).sleep();*/
		std::cout << std::endl << std::endl << std::endl;	
	}

	std::cout << "Elapsed time of initialization: " << check4 << std::endl;


	std::cout << "//////////////////Track back//////////////////" <<std::endl;
	p.z = 1.0;
	while (not(current_node->getNode() == start_node_nr))
	{
		p.x = current_node->getX();
		p.y = current_node->getY();
      		route_list.points.push_back(p);
		current_node = &Network->at(CostMatrix(current_node->getPreviousNode(),1));
		p.x = current_node->getX();
		p.y = current_node->getY();
      		route_list.points.push_back(p);
		marker_2_pub.publish(route_list);
	}

	check5 += ros::Time::now().toSec() - begin_check5;
	std::cout << "Elapsed time of route calculation: " << check5 << std::endl;
}

void generate_route()
{
	while (not(current_node->getNode() == 0))
	{
		waypoint.x = current_node->getX();
		waypoint.y = current_node->getY();
		Route.stages.push_back(waypoint);
		current_node = &Network->at(current_node->getPreviousNode());
	}
}

void start_cb (const nautonomous_mpc_msgs::StageVariable::ConstPtr& state_msg)
{
	double begin = ros::Time::now().toSec();	
	start_state = *state_msg;

	ros::Duration(5).sleep();

	calculate_route();
	double end = ros::Time::now().toSec();	
	std::cout << "Elapsed time is: " << end-begin << std::endl;
	std::cout << "Nodes checked: " << next_node << std::endl;
}

void goal_cb (const nautonomous_mpc_msgs::StageVariable::ConstPtr& state_msg)
{
	goal_state = *state_msg;
	final_node->initializeNode(goal_state.x, goal_state.y, goal_state.theta, 0.0, INF, 0, 0, false);
}

void map_cb (const nav_msgs::OccupancyGrid::ConstPtr& map_msg)
{
	std::cout << "map received" << std::endl;
	map = *map_msg;
	temp_map = map;
	
	std::cout << "Data length is: " << map.data.size() <<std::endl;
	map_width = (float)map.info.width;
	map_height = (float)map.info.height;

	Nx = ceil(map_width / step_size);
	Ny = ceil(map_height / step_size);
 
	map_center_x = (float)map.info.origin.position.x;
	map_center_y = (float)map.info.origin.position.y;

	resolution = (float)map.info.resolution;
	std::cout << "Map center: " << map_center_x << ", " << map_center_y <<std::endl;
	std::cout << "Map size: " << map_width << " x " << map_height <<std::endl;
}

void obstacle_cb (const nautonomous_mpc_msgs::Obstacle::ConstPtr& obstacle_msg)
{
	Obstacle = *obstacle_msg;
	map = temp_map;
	for (float i = -Obstacle.major_semiaxis; i < Obstacle.major_semiaxis; i+= resolution)
	{
		for (float j = -Obstacle.minor_semiaxis; j < Obstacle.minor_semiaxis; j+= resolution)
		{
			temp_x = Obstacle.state.pose.position.x + i;
			temp_y = Obstacle.state.pose.position.y + j;
			map.data[(floor((temp_y-map_center_y)/resolution)-1) * map_width + floor((temp_x-map_center_x)/resolution)] = 100;
		}		
	}

	map_pub.publish(map);

	std::cout << "Obstacle map published" << std::endl;
}

int main (int argc, char** argv)
{
	ros::init (argc, argv,"A_star_tree_path_finding_opt");
	ros::NodeHandle nh("");
	ros::NodeHandle nh_private("~");
	
	map_sub = 	nh.subscribe<nav_msgs::OccupancyGrid>("/map",10,map_cb);
	start_sub = 	nh.subscribe<nautonomous_mpc_msgs::StageVariable>("/mission_coordinator/start",10,start_cb);
	goal_sub = 	nh.subscribe<nautonomous_mpc_msgs::StageVariable>("/mission_coordinator/goal",10,goal_cb);
	obstacle_sub = 	nh.subscribe<nautonomous_mpc_msgs::Obstacle>("/mission_coordinator/obstacle",10,obstacle_cb);

	map_pub = 	nh.advertise<nav_msgs::OccupancyGrid>("/map_tree_opt",10);
	marker_pub = nh_private.advertise<visualization_msgs::Marker>("visualization_marker", 10);
	marker_2_pub = nh_private.advertise<visualization_msgs::Marker>("visualization_marker_route", 10);

	Network->reserve(100000);
	std::cout << std::setprecision(8) << std::endl;

	line_list.header.frame_id = "/map";
	line_list.header.stamp = ros::Time::now();
	line_list.ns = "points_and_lines";
	line_list.action = visualization_msgs::Marker::ADD;
	line_list.pose.orientation.w = 1.0;

	line_list.id = 0;
	line_list.type = visualization_msgs::Marker::LINE_LIST;
	line_list.scale.x = 0.2;
	line_list.color.r = 1.0;
	line_list.color.a = 1.0;

	route_list.header.frame_id = "/map";
	route_list.header.stamp = ros::Time::now();
	route_list.ns = "points_and_lines";
	route_list.action = visualization_msgs::Marker::ADD;
	route_list.pose.orientation.w = 1.0;

	route_list.id = 0;
	route_list.type = visualization_msgs::Marker::LINE_LIST;
	route_list.scale.x = 1.0;
	route_list.color.g = 1.0;
	route_list.color.a = 1.0;

	Network->clear();
	CostMatrix = MatrixXd::Ones(4000000,2) * INF;
	Heap = MatrixXd::Ones(100000,2) * INF;
	next_node = 1;

	ros::spin();	
}
