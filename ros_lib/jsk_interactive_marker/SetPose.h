#ifndef _ROS_SERVICE_SetPose_h
#define _ROS_SERVICE_SetPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "visualization_msgs/Marker.h"

namespace jsk_interactive_marker
{

static const char SETPOSE[] = "jsk_interactive_marker/SetPose";

  class SetPoseRequest : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;
      uint8_t markers_length;
      visualization_msgs::Marker st_markers;
      visualization_msgs::Marker * markers;

    SetPoseRequest():
      pose(),
      markers_length(0), markers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset++) = markers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      uint8_t markers_lengthT = *(inbuffer + offset++);
      if(markers_lengthT > markers_length)
        this->markers = (visualization_msgs::Marker*)realloc(this->markers, markers_lengthT * sizeof(visualization_msgs::Marker));
      offset += 3;
      markers_length = markers_lengthT;
      for( uint8_t i = 0; i < markers_length; i++){
      offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(visualization_msgs::Marker));
      }
     return offset;
    }

    const char * getType(){ return SETPOSE; };
    const char * getMD5(){ return "17366a329fecb3acb7212221df9e7b8b"; };

  };

  class SetPoseResponse : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose;

    SetPoseResponse():
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETPOSE; };
    const char * getMD5(){ return "3f8930d968a3e84d471dff917bb1cdae"; };

  };

  class SetPose {
    public:
    typedef SetPoseRequest Request;
    typedef SetPoseResponse Response;
  };

}
#endif
