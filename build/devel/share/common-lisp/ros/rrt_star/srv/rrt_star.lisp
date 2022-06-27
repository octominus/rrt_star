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
    :initform 0.0))
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
  "727ba677c1ac4e2fb5cb99c510508116")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rrt_star-request)))
  "Returns md5sum for a message object of type 'rrt_star-request"
  "727ba677c1ac4e2fb5cb99c510508116")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rrt_star-request>)))
  "Returns full string definition for message of type '<rrt_star-request>"
  (cl:format cl:nil "float32 X1~%float32 Y1~%float32 X2~%float32 Y2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rrt_star-request)))
  "Returns full string definition for message of type 'rrt_star-request"
  (cl:format cl:nil "float32 X1~%float32 Y1~%float32 X2~%float32 Y2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rrt_star-request>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rrt_star-request>))
  "Converts a ROS message object to a list"
  (cl:list 'rrt_star-request
    (cl:cons ':X1 (X1 msg))
    (cl:cons ':Y1 (Y1 msg))
    (cl:cons ':X2 (X2 msg))
    (cl:cons ':Y2 (Y2 msg))
))
;//! \htmlinclude rrt_star-response.msg.html

(cl:defclass <rrt_star-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass rrt_star-response (<rrt_star-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <rrt_star-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'rrt_star-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rrt_star-srv:<rrt_star-response> is deprecated: use rrt_star-srv:rrt_star-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <rrt_star-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rrt_star-srv:result-val is deprecated.  Use rrt_star-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <rrt_star-response>) ostream)
  "Serializes a message object of type '<rrt_star-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <rrt_star-response>) istream)
  "Deserializes a message object of type '<rrt_star-response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
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
  "727ba677c1ac4e2fb5cb99c510508116")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'rrt_star-response)))
  "Returns md5sum for a message object of type 'rrt_star-response"
  "727ba677c1ac4e2fb5cb99c510508116")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<rrt_star-response>)))
  "Returns full string definition for message of type '<rrt_star-response>"
  (cl:format cl:nil "bool result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'rrt_star-response)))
  "Returns full string definition for message of type 'rrt_star-response"
  (cl:format cl:nil "bool result~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <rrt_star-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <rrt_star-response>))
  "Converts a ROS message object to a list"
  (cl:list 'rrt_star-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'rrt_star)))
  'rrt_star-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'rrt_star)))
  'rrt_star-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'rrt_star)))
  "Returns string type for a service object of type '<rrt_star>"
  "rrt_star/rrt_star")