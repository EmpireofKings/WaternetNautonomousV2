classdef CostsWN < robotics.ros.Message
    %CostsWN MATLAB implementation of nautonomous_mpc_msgs/CostsWN
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2018 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'nautonomous_mpc_msgs/CostsWN' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '751a769bc05e957dbcfa0ec56ae814e0' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Dependent)
        QGoal
        QNGoal
        QU
        QNU
    end
    
    properties (Constant, Hidden)
        PropertyList = {'QGoal', 'QNGoal', 'QNU', 'QU'} % List of non-constant message properties
        ROSPropertyList = {'q_goal', 'qN_goal', 'qN_u', 'q_u'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = CostsWN(msg)
            %CostsWN Construct the message object CostsWN
            import com.mathworks.toolbox.robotics.ros.message.MessageInfo;
            
            % Support default constructor
            if nargin == 0
                obj.JavaMessage = obj.createNewJavaMessage;
                return;
            end
            
            % Construct appropriate empty array
            if isempty(msg)
                obj = obj.empty(0,1);
                return;
            end
            
            % Make scalar construction fast
            if isscalar(msg)
                % Check for correct input class
                if ~MessageInfo.compareTypes(msg(1), obj.MessageType)
                    error(message('robotics:ros:message:NoTypeMatch', obj.MessageType, ...
                        char(MessageInfo.getType(msg(1))) ));
                end
                obj.JavaMessage = msg(1);
                return;
            end
            
            % Check that this is a vector of scalar messages. Since this
            % is an object array, use arrayfun to verify.
            if ~all(arrayfun(@isscalar, msg))
                error(message('robotics:ros:message:MessageArraySizeError'));
            end
            
            % Check that all messages in the array have the correct type
            if ~all(arrayfun(@(x) MessageInfo.compareTypes(x, obj.MessageType), msg))
                error(message('robotics:ros:message:NoTypeMatchArray', obj.MessageType));
            end
            
            % Construct array of objects if necessary
            objType = class(obj);
            for i = 1:length(msg)
                obj(i,1) = feval(objType, msg(i)); %#ok<AGROW>
            end
        end
        
        function qgoal = get.QGoal(obj)
            %get.QGoal Get the value for property QGoal
            qgoal = double(obj.JavaMessage.getQGoal);
        end
        
        function set.QGoal(obj, qgoal)
            %set.QGoal Set the value for property QGoal
            validateattributes(qgoal, {'numeric'}, {'nonempty', 'scalar'}, 'CostsWN', 'QGoal');
            
            obj.JavaMessage.setQGoal(qgoal);
        end
        
        function qngoal = get.QNGoal(obj)
            %get.QNGoal Get the value for property QNGoal
            qngoal = double(obj.JavaMessage.getQNGoal);
        end
        
        function set.QNGoal(obj, qngoal)
            %set.QNGoal Set the value for property QNGoal
            validateattributes(qngoal, {'numeric'}, {'nonempty', 'scalar'}, 'CostsWN', 'QNGoal');
            
            obj.JavaMessage.setQNGoal(qngoal);
        end
        
        function qu = get.QU(obj)
            %get.QU Get the value for property QU
            qu = double(obj.JavaMessage.getQU);
        end
        
        function set.QU(obj, qu)
            %set.QU Set the value for property QU
            validateattributes(qu, {'numeric'}, {'nonempty', 'scalar'}, 'CostsWN', 'QU');
            
            obj.JavaMessage.setQU(qu);
        end
        
        function qnu = get.QNU(obj)
            %get.QNU Get the value for property QNU
            qnu = double(obj.JavaMessage.getQNU);
        end
        
        function set.QNU(obj, qnu)
            %set.QNU Set the value for property QNU
            validateattributes(qnu, {'numeric'}, {'nonempty', 'scalar'}, 'CostsWN', 'QNU');
            
            obj.JavaMessage.setQNU(qnu);
        end
    end
    
    methods (Access = protected)
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.QGoal = obj.QGoal;
            cpObj.QNGoal = obj.QNGoal;
            cpObj.QU = obj.QU;
            cpObj.QNU = obj.QNU;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.QGoal = strObj.QGoal;
            obj.QNGoal = strObj.QNGoal;
            obj.QU = strObj.QU;
            obj.QNU = strObj.QNU;
        end
    end
    
    methods (Access = ?robotics.ros.Message)
        function strObj = saveobj(obj)
            %saveobj Implements saving of message to MAT file
            
            % Return an empty element if object array is empty
            if isempty(obj)
                strObj = struct.empty;
                return
            end
            
            strObj.QGoal = obj.QGoal;
            strObj.QNGoal = obj.QNGoal;
            strObj.QU = obj.QU;
            strObj.QNU = obj.QNU;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.nautonomous_mpc_msgs.CostsWN.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.nautonomous_mpc_msgs.CostsWN;
            obj.reload(strObj);
        end
    end
end
