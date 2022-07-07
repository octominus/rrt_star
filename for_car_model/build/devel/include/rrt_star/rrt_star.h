// Generated by gencpp from file rrt_star/rrt_star.msg
// DO NOT EDIT!


#ifndef RRT_STAR_MESSAGE_RRT_STAR_H
#define RRT_STAR_MESSAGE_RRT_STAR_H

#include <ros/service_traits.h>


#include <rrt_star/rrt_starRequest.h>
#include <rrt_star/rrt_starResponse.h>


namespace rrt_star
{

struct rrt_star
{

typedef rrt_starRequest Request;
typedef rrt_starResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct rrt_star
} // namespace rrt_star


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::rrt_star::rrt_star > {
  static const char* value()
  {
    return "4fa07ef2fe36c88d0f047badd795303f";
  }

  static const char* value(const ::rrt_star::rrt_star&) { return value(); }
};

template<>
struct DataType< ::rrt_star::rrt_star > {
  static const char* value()
  {
    return "rrt_star/rrt_star";
  }

  static const char* value(const ::rrt_star::rrt_star&) { return value(); }
};


// service_traits::MD5Sum< ::rrt_star::rrt_starRequest> should match
// service_traits::MD5Sum< ::rrt_star::rrt_star >
template<>
struct MD5Sum< ::rrt_star::rrt_starRequest>
{
  static const char* value()
  {
    return MD5Sum< ::rrt_star::rrt_star >::value();
  }
  static const char* value(const ::rrt_star::rrt_starRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::rrt_star::rrt_starRequest> should match
// service_traits::DataType< ::rrt_star::rrt_star >
template<>
struct DataType< ::rrt_star::rrt_starRequest>
{
  static const char* value()
  {
    return DataType< ::rrt_star::rrt_star >::value();
  }
  static const char* value(const ::rrt_star::rrt_starRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::rrt_star::rrt_starResponse> should match
// service_traits::MD5Sum< ::rrt_star::rrt_star >
template<>
struct MD5Sum< ::rrt_star::rrt_starResponse>
{
  static const char* value()
  {
    return MD5Sum< ::rrt_star::rrt_star >::value();
  }
  static const char* value(const ::rrt_star::rrt_starResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::rrt_star::rrt_starResponse> should match
// service_traits::DataType< ::rrt_star::rrt_star >
template<>
struct DataType< ::rrt_star::rrt_starResponse>
{
  static const char* value()
  {
    return DataType< ::rrt_star::rrt_star >::value();
  }
  static const char* value(const ::rrt_star::rrt_starResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // RRT_STAR_MESSAGE_RRT_STAR_H