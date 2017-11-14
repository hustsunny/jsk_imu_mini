#ifndef _ROS_naoqi_bridge_msgs_EventStamped_h
#define _ROS_naoqi_bridge_msgs_EventStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/String.h"

namespace naoqi_bridge_msgs
{

  class EventStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      std_msgs::String name;
      std_msgs::String data;

    EventStamped():
      header(),
      name(),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->name.serialize(outbuffer + offset);
      offset += this->data.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->name.deserialize(inbuffer + offset);
      offset += this->data.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/EventStamped"; };
    const char * getMD5(){ return "da9da7dab2e8376f0a588b6d053ac972"; };

  };

}
#endif