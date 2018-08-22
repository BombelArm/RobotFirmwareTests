#ifndef _ROS_wfov_camera_msgs_WFOVCompressedImage_h
#define _ROS_wfov_camera_msgs_WFOVCompressedImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/CompressedImage.h"
#include "sensor_msgs/CameraInfo.h"
#include "geometry_msgs/TransformStamped.h"

namespace wfov_camera_msgs
{

  class WFOVCompressedImage : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _time_reference_type;
      _time_reference_type time_reference;
      typedef sensor_msgs::CompressedImage _image_type;
      _image_type image;
      typedef sensor_msgs::CameraInfo _info_type;
      _info_type info;
      typedef float _shutter_type;
      _shutter_type shutter;
      typedef float _gain_type;
      _gain_type gain;
      typedef uint16_t _white_balance_blue_type;
      _white_balance_blue_type white_balance_blue;
      typedef uint16_t _white_balance_red_type;
      _white_balance_red_type white_balance_red;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef geometry_msgs::TransformStamped _worldToCamera_type;
      _worldToCamera_type worldToCamera;

    WFOVCompressedImage():
      header(),
      time_reference(""),
      image(),
      info(),
      shutter(0),
      gain(0),
      white_balance_blue(0),
      white_balance_red(0),
      temperature(0),
      worldToCamera()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_time_reference = strlen(this->time_reference);
      varToArr(outbuffer + offset, length_time_reference);
      offset += 4;
      memcpy(outbuffer + offset, this->time_reference, length_time_reference);
      offset += length_time_reference;
      offset += this->image.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_shutter;
      u_shutter.real = this->shutter;
      *(outbuffer + offset + 0) = (u_shutter.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_shutter.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_shutter.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_shutter.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shutter);
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
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      offset += this->worldToCamera.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_time_reference;
      arrToVar(length_time_reference, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_time_reference; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_time_reference-1]=0;
      this->time_reference = (char *)(inbuffer + offset-1);
      offset += length_time_reference;
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_shutter;
      u_shutter.base = 0;
      u_shutter.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_shutter.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_shutter.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_shutter.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->shutter = u_shutter.real;
      offset += sizeof(this->shutter);
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
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      offset += this->worldToCamera.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "wfov_camera_msgs/WFOVCompressedImage"; };
    const char * getMD5(){ return "5b0f85e79ffccd27dc377911c83e026f"; };

  };

}
#endif