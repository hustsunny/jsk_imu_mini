#ifndef _ROS_SERVICE_GetRobotInfo_h
#define _ROS_SERVICE_GetRobotInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/RobotInfo.h"

namespace naoqi_bridge_msgs
{

static const char GETROBOTINFO[] = "naoqi_bridge_msgs/GetRobotInfo";

  class GetRobotInfoRequest : public ros::Msg
  {
    public:

    GetRobotInfoRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETROBOTINFO; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetRobotInfoResponse : public ros::Msg
  {
    public:
      naoqi_bridge_msgs::RobotInfo info;

    GetRobotInfoResponse():
      info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->info.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETROBOTINFO; };
    const char * getMD5(){ return "6a705e4ea65692d6e21188b3537da43d"; };

  };

  class GetRobotInfo {
    public:
    typedef GetRobotInfoRequest Request;
    typedef GetRobotInfoResponse Response;
  };

}
#endif
