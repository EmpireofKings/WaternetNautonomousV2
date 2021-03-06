classdef AuthenticationRequest < robotics.ros.Message
    %AuthenticationRequest MATLAB implementation of nautonomous_authentication_msgs/AuthenticationRequest
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2014-2018 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'nautonomous_authentication_msgs/AuthenticationRequest' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = 'f15810143ba1dcef2e6e958bcf929ceb' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Dependent)
        Mac
        Token
    end
    
    properties (Constant, Hidden)
        PropertyList = {'Mac', 'Token'} % List of non-constant message properties
        ROSPropertyList = {'mac', 'token'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = AuthenticationRequest(msg)
            %AuthenticationRequest Construct the message object AuthenticationRequest
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
        
        function mac = get.Mac(obj)
            %get.Mac Get the value for property Mac
            mac = char(obj.JavaMessage.getMac);
        end
        
        function set.Mac(obj, mac)
            %set.Mac Set the value for property Mac
            validateattributes(mac, {'char'}, {}, 'AuthenticationRequest', 'Mac');
            
            obj.JavaMessage.setMac(mac);
        end
        
        function token = get.Token(obj)
            %get.Token Get the value for property Token
            token = char(obj.JavaMessage.getToken);
        end
        
        function set.Token(obj, token)
            %set.Token Set the value for property Token
            validateattributes(token, {'char'}, {}, 'AuthenticationRequest', 'Token');
            
            obj.JavaMessage.setToken(token);
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
            cpObj.Mac = obj.Mac;
            cpObj.Token = obj.Token;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.Mac = strObj.Mac;
            obj.Token = strObj.Token;
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
            
            strObj.Mac = obj.Mac;
            strObj.Token = obj.Token;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.nautonomous_authentication_msgs.AuthenticationRequest.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.nautonomous_authentication_msgs.AuthenticationRequest;
            obj.reload(strObj);
        end
    end
end
