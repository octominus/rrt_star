; Auto-generated. Do not edit!


(cl:in-package rrt_star-srv)


;//! \htmlinclude rrt_star-request.msg.html

(cl:defclass <rrt_star-request> (roslisp-msg-protocol:ros-message)
  ((X1
    :reader X1
    :initarg :X1
    :type cl:float
    :initform 0.0)
   (Y1
    :reader Y1
    :initarg :Y1
    :type cl:float
    :initform 0.0)
   (X2
    :reader X2
    :initarg :X2
    :type cl:float
    :initform 0.0)
   (Y2
    :reader Y2
    :initarg :Y2
    :type cl:float
    :initform 0.0)
   (time
    :reader time
    :initarg :time
    :type cl:float
    :initform 0.0)
   (time_type
    :reader time_type
    :initarg :time_type
    :type cl:string
    :initform ""))
)

(cl:defclass rrt_star-request (<rrt_star-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <rrt_star-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'rrt_star-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rrt_star-srv:<rrt_star-request> is deprecated: use rrt_star-srv:rrt_star-request instead.")))

(cl:ensure-generic-function 'X1-val :lambda-list '(m))
(cl:defmethod X1-val ((m <rrt_star-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:X1-val is deprecated.  Use rrt_star-srv:X1 instead.")
  (X1 m))

(cl:ensure-generic-function 'Y1-val :lambda-list '(m))
(cl:defmethod Y1-val ((m <rrt_star-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:Y1-val is deprecated.  Use rrt_star-srv:Y1 instead.")
  (Y1 m))

(cl:ensure-generic-function 'X2-val :lambda-list '(m))
(cl:defmethod X2-val ((m <rrt_star-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:X2-val is deprecated.  Use rrt_star-srv:X2 instead.")
  (X2 m))

(cl:ensure-generic-function 'Y2-val :lambda-list '(m))
(cl:defmethod Y2-val ((m <rrt_star-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:Y2-val is deprecated.  Use rrt_star-srv:Y2 instead.")
  (Y2 m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <rrt_star-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:time-val is deprecated.  Use rrt_star-srv:time instead.")
  (time m))

(cl:ensure-generic-function 'time_type-val :lambda-list '(m))
(cl:defmethod time_type-val ((m <rrt_star-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:time_type-val is deprecated.  Use rrt_star-srv:time_type instead.")
  (time_type m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <rrt_star-request>) ostream)
  "Serializes a message object of type '<rrt_star-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'X1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Y1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'X2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Y2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'time_type))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'time_type))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <rrt_star-request>) istream)
  "Deserializes a message object of type '<rrt_star-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'time_type) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'time_type) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<rrt_star-request>)))
  "Returns string type for a service object of type '<rrt_star-request>"
  "rrt_star/rrt_starRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rrt_star-request)))
  "Returns string type for a service object of type 'rrt_star-request"
  "rrt_star/rrt_starRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<rrt_star-request>)))
  "Returns md5sum for a message object of type '<rrt_star-request>"
  "4fa07ef2fe36c88d0f047badd795303f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rrt_star-request)))
  "Returns md5sum for a message object of type 'rrt_star-request"
  "4fa07ef2fe36c88d0f047badd795303f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rrt_star-request>)))
  "Returns full string definition for message of type '<rrt_star-request>"
  (cl:format cl:nil "float32 X1~%float32 Y1~%float32 X2~%float32 Y2~%float32 time~%string time_type~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rrt_star-request)))
  "Returns full string definition for message of type 'rrt_star-request"
  (cl:format cl:nil "float32 X1~%float32 Y1~%float32 X2~%float32 Y2~%float32 time~%string time_type~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rrt_star-request>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4 (cl:length (cl:slot-value msg 'time_type))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rrt_star-request>))
  "Converts a ROS message object to a list"
  (cl:list 'rrt_star-request
    (cl:cons ':X1 (X1 msg))
    (cl:cons ':Y1 (Y1 msg))
    (cl:cons ':X2 (X2 msg))
    (cl:cons ':Y2 (Y2 msg))
    (cl:cons ':time (time msg))
    (cl:cons ':time_type (time_type msg))
))
;//! \htmlinclude rrt_star-response.msg.html

(cl:defclass <rrt_star-response> (roslisp-msg-protocol:ros-message)
  ((path_result
    :reader path_result
    :initarg :path_result
    :type cl:boolean
    :initform cl:nil)
   (time_result
    :reader time_result
    :initarg :time_result
    :type cl:float
    :initform 0.0))
)

(cl:defclass rrt_star-response (<rrt_star-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <rrt_star-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'rrt_star-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rrt_star-srv:<rrt_star-response> is deprecated: use rrt_star-srv:rrt_star-response instead.")))

(cl:ensure-generic-function 'path_result-val :lambda-list '(m))
(cl:defmethod path_result-val ((m <rrt_star-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:path_result-val is deprecated.  Use rrt_star-srv:path_result instead.")
  (path_result m))

(cl:ensure-generic-function 'time_result-val :lambda-list '(m))
(cl:defmethod time_result-val ((m <rrt_star-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:time_result-val is deprecated.  Use rrt_star-srv:time_result instead.")
  (time_result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <rrt_star-response>) ostream)
  "Serializes a message object of type '<rrt_star-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'path_result) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'time_result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <rrt_star-response>) istream)
  "Deserializes a message object of type '<rrt_star-response>"
    (cl:setf (cl:slot-value msg 'path_result) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'time_result) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<rrt_star-response>)))
  "Returns string type for a service object of type '<rrt_star-response>"
  "rrt_star/rrt_starResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rrt_star-response)))
  "Returns string type for a service object of type 'rrt_star-response"
  "rrt_star/rrt_starResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<rrt_star-response>)))
  "Returns md5sum for a message object of type '<rrt_star-response>"
  "4fa07ef2fe36c88d0f047badd795303f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rrt_star-response)))
  "Returns md5sum for a message object of type 'rrt_star-response"
  "4fa07ef2fe36c88d0f047badd795303f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rrt_star-response>)))
  "Returns full string definition for message of type '<rrt_star-response>"
  (cl:format cl:nil "bool path_result~%float32 time_result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rrt_star-response)))
  "Returns full string definition for message of type 'rrt_star-response"
  (cl:format cl:nil "bool path_result~%float32 time_result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rrt_star-response>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rrt_star-response>))
  "Converts a ROS message object to a list"
  (cl:list 'rrt_star-response
    (cl:cons ':path_result (path_result msg))
    (cl:cons ':time_result (time_result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'rrt_star)))
  'rrt_star-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'rrt_star)))
  'rrt_star-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rrt_star)))
  "Returns string type for a service object of type '<rrt_star>"
  "rrt_star/rrt_star")