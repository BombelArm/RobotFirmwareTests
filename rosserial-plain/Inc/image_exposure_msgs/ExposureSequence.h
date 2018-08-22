#ifndef _ROS_image_exposure_msgs_ExposureSequence_h
#define _ROS_image_exposure_msgs_ExposureSequence_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace image_exposure_msgs
{

  class ExposureSequence : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t shutter_length;
      typedef uint32_t _shutter_type;
      _shutter_type st_shutter;
      _shutter_type * shutter;
      typedef float _gain_type;
      _gain_type gain;
      typedef uint16_t _white_balance_blue_type;
      _white_balance_blue_type white_balance_blue;
      typedef uint16_t _white_balance_red_type;
      _white_balance_red_type white_balance_red;

    ExposureSequence():
      header(),
      shutter_length(0), shutter(NULL),
      gain(0),
      white_balance_blue(0),
      white_balance_red(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->shutter_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shutter_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shutter_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shutter_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shutter_length);
      for( uint32_t i = 0; i < shutter_length; i++){
      *(outbuffer + offset + 0) = (this->shutter[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shutter[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shutter[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shutter[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shutter[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.real = this->gain;
      *(outbuffer + offset + 0) = (u_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gain.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gain);
      *(outbuffer + offset + 0) = (this->white_balance_blue >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->white_balance_blue >> (8 * 1)) & 0xFF;
      offset += sizeof(this->white_balance_blue);
      *(outbuffer + offset + 0) = (this->white_balance_red >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->white_balance_red >> (8 * 1)) & 0xFF;
      offset += sizeof(this->white_balance_red);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t shutter_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      shutter_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      shutter_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      shutter_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->shutter_length);
      if(shutter_lengthT > shutter_length)
        this->shutter = (uint32_t*)realloc(this->shutter, shutter_lengthT * sizeof(uint32_t));
      shutter_length = shutter_lengthT;
      for( uint32_t i = 0; i < shutter_length; i++){
      this->st_shutter =  ((uint32_t) (*(inbuffer + offset)));
      this->st_shutter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_shutter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_shutter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_shutter);
        memcpy( &(this->shutter[i]), &(this->st_shutter), sizeof(uint32_t));
      }
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.base = 0;
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gain = u_gain.real;
      offset += sizeof(this->gain);
      this->white_balance_blue =  ((uint16_t) (*(inbuffer + offset)));
      this->white_balance_blue |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->white_balance_blue);
      this->white_balance_red =  ((uint16_t) (*(inbuffer + offset)));
      this->white_balance_red |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->white_balance_red);
     return offset;
    }

    const char * getType(){ return "image_exposure_msgs/ExposureSequence"; };
    const char * getMD5(){ return "81d98e1e20eab8beb4bd07beeba6a398"; };

  };

}
#endif