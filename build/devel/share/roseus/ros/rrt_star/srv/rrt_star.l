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
  :slots (_X1 _Y1 _X2 _Y2 ))

(defmethod rrt_star::rrt_starRequest
  (:init
   (&key
    ((:X1 __X1) 0.0)
    ((:Y1 __Y1) 0.0)
    ((:X2 __X2) 0.0)
    ((:Y2 __Y2) 0.0)
    )
   (send-super :init)
   (setq _X1 (float __X1))
   (setq _Y1 (float __Y1))
   (setq _X2 (float __X2))
   (setq _Y2 (float __Y2))
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
   ;;
   self)
  )

(defclass rrt_star::rrt_starResponse
  :super ros::object
  :slots (_result ))

(defmethod rrt_star::rrt_starResponse
  (:init
   (&key
    ((:result __result) nil)
    )
   (send-super :init)
   (setq _result __result)
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass rrt_star::rrt_star
  :super ros::object
  :slots ())

(setf (get rrt_star::rrt_star :md5sum-) "727ba677c1ac4e2fb5cb99c510508116")
(setf (get rrt_star::rrt_star :datatype-) "rrt_star/rrt_star")
(setf (get rrt_star::rrt_star :request) rrt_star::rrt_starRequest)
(setf (get rrt_star::rrt_star :response) rrt_star::rrt_starResponse)

(defmethod rrt_star::rrt_starRequest
  (:response () (instance rrt_star::rrt_starResponse :init)))

(setf (get rrt_star::rrt_starRequest :md5sum-) "727ba677c1ac4e2fb5cb99c510508116")
(setf (get rrt_star::rrt_starRequest :datatype-) "rrt_star/rrt_starRequest")
(setf (get rrt_star::rrt_starRequest :definition-)
      "float32 X1
float32 Y1
float32 X2
float32 Y2
---
bool result
")

(setf (get rrt_star::rrt_starResponse :md5sum-) "727ba677c1ac4e2fb5cb99c510508116")
(setf (get rrt_star::rrt_starResponse :datatype-) "rrt_star/rrt_starResponse")
(setf (get rrt_star::rrt_starResponse :definition-)
      "float32 X1
float32 Y1
float32 X2
float32 Y2
---
bool result
")



(provide :rrt_star/rrt_star "727ba677c1ac4e2fb5cb99c510508116")


