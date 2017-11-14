#ifndef _ROS_SERVICE_SetTransformableMarkerPose_h
#define _ROS_SERVICE_SetTransformableMarkerPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace jsk_interactive_marker
{

static const char SETTRANSFORMABLEMARKERPOSE[] = "jsk_interactive_marker/SetTransformableMarkerPose";

  class SetTransformableMarkerPoseRequest : public ros::Msg
  {
    public:
      const char* target_name;
      geometry_msgs::PoseStamped pose_stamped;

    SetTransformableMarkerPoseRequest():
      target_name(""),
      pose_stamped()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_target_name = strlen(this->target_name);
      memcpy(outbuffer + offset, &length_target_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_name, length_target_name);
      offset += length_target_name;
      offset += this->pose_stamped.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_target_name;
      memcpy(&length_target_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_name-1]=0;
      this->target_name = (char *)(inbuffer + offset-1);
      offset += length_target_name;
      offset += this->pose_stamped.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETTRANSFORMABLEMARKERPOSE; };
    const char * getMD5(){ return "e19607b29b4528e87feff290fe261191"; };

  };

  class SetTransformableMarkerPoseResponse : public ros::Msg
  {
    public:

    SetTransformableMarkerPoseResponse()
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

    const char * getType(){ return SETTRANSFORMABLEMARKERPOSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetTransformableMarkerPose {
    public:
    typedef SetTransformableMarkerPoseRequest Request;
    typedef SetTransformableMarkerPoseResponse Response;
  };

}
#endif
