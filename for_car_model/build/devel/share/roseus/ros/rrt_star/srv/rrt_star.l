;; Auto-generated. Do not edit!


(when (boundp 'rrt_star::rrt_star)
  (if (not (find-package "RRT_STAR"))
    (make-package "RRT_STAR"))
  (shadow 'rrt_star (find-package "RRT_STAR")))
(unless (find-package "RRT_STAR::RRT_STAR")
  (make-package "RRT_STAR::RRT_STAR"))
(unless (find-package "RRT_STAR::RRT_STARREQUEST")
  (make-package "RRT_STAR::RRT_STARREQUEST"))
(unless (find-package "RRT_STAR::RRT_STARRESPONSE")
  (make-package "RRT_STAR::RRT_STARRESPONSE"))

(in-package "ROS")





(defclass rrt_star::rrt_starRequest
  :super ros::object
  :slots (_X1 _Y1 _X2 _Y2 _time _time_type ))

(defmethod rrt_star::rrt_starRequest
  (:init
   (&key
    ((:X1 __X1) 0.0)
    ((:Y1 __Y1) 0.0)
    ((:X2 __X2) 0.0)
    ((:Y2 __Y2) 0.0)
    ((:time __time) 0.0)
    ((:time_type __time_type) "")
    )
   (send-super :init)
   (setq _X1 (float __X1))
   (setq _Y1 (float __Y1))
   (setq _X2 (float __X2))
   (setq _Y2 (float __Y2))
   (setq _time (float __time))
   (setq _time_type (string __time_type))
   self)
  (:X1
   (&optional __X1)
   (if __X1 (setq _X1 __X1)) _X1)
  (:Y1
   (&optional __Y1)
   (if __Y1 (setq _Y1 __Y1)) _Y1)
  (:X2
   (&optional __X2)
   (if __X2 (setq _X2 __X2)) _X2)
  (:Y2
   (&optional __Y2)
   (if __Y2 (setq _Y2 __Y2)) _Y2)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:time_type
   (&optional __time_type)
   (if __time_type (setq _time_type __time_type)) _time_type)
  (:serialization-length
   ()
   (+
    ;; float32 _X1
    4
    ;; float32 _Y1
    4
    ;; float32 _X2
    4
    ;; float32 _Y2
    4
    ;; float32 _time
    4
    ;; string _time_type
    4 (length _time_type)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _X1
       (sys::poke _X1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Y1
       (sys::poke _Y1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _X2
       (sys::poke _X2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Y2
       (sys::poke _Y2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _time
       (sys::poke _time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; string _time_type
       (write-long (length _time_type) s) (princ _time_type s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _X1
     (setq _X1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Y1
     (setq _Y1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _X2
     (setq _X2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Y2
     (setq _Y2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _time
     (setq _time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; string _time_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _time_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass rrt_star::rrt_starResponse
  :super ros::object
  :slots (_path_result _time_result ))

(defmethod rrt_star::rrt_starResponse
  (:init
   (&key
    ((:path_result __path_result) nil)
    ((:time_result __time_result) 0.0)
    )
   (send-super :init)
   (setq _path_result __path_result)
   (setq _time_result (float __time_result))
   self)
  (:path_result
   (&optional __path_result)
   (if __path_result (setq _path_result __path_result)) _path_result)
  (:time_result
   (&optional __time_result)
   (if __time_result (setq _time_result __time_result)) _time_result)
  (:serialization-length
   ()
   (+
    ;; bool _path_result
    1
    ;; float32 _time_result
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _path_result
       (if _path_result (write-byte -1 s) (write-byte 0 s))
     ;; float32 _time_result
       (sys::poke _time_result (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _path_result
     (setq _path_result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _time_result
     (setq _time_result (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass rrt_star::rrt_star
  :super ros::object
  :slots ())

(setf (get rrt_star::rrt_star :md5sum-) "4fa07ef2fe36c88d0f047badd795303f")
(setf (get rrt_star::rrt_star :datatype-) "rrt_star/rrt_star")
(setf (get rrt_star::rrt_star :request) rrt_star::rrt_starRequest)
(setf (get rrt_star::rrt_star :response) rrt_star::rrt_starResponse)

(defmethod rrt_star::rrt_starRequest
  (:response () (instance rrt_star::rrt_starResponse :init)))

(setf (get rrt_star::rrt_starRequest :md5sum-) "4fa07ef2fe36c88d0f047badd795303f")
(setf (get rrt_star::rrt_starRequest :datatype-) "rrt_star/rrt_starRequest")
(setf (get rrt_star::rrt_starRequest :definition-)
      "float32 X1
float32 Y1
float32 X2
float32 Y2
float32 time
string time_type
---
bool path_result
float32 time_result
")

(setf (get rrt_star::rrt_starResponse :md5sum-) "4fa07ef2fe36c88d0f047badd795303f")
(setf (get rrt_star::rrt_starResponse :datatype-) "rrt_star/rrt_starResponse")
(setf (get rrt_star::rrt_starResponse :definition-)
      "float32 X1
float32 Y1
float32 X2
float32 Y2
float32 time
string time_type
---
bool path_result
float32 time_result
")



(provide :rrt_star/rrt_star "4fa07ef2fe36c88d0f047badd795303f")


