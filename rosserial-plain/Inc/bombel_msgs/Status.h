#ifndef _ROS_bombel_msgs_Status_h
#define _ROS_bombel_msgs_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bombel_msgs
{

  class Status : public ros::Msg
  {
    public:
      typedef uint32_t _stepper1_status_register_type;
      _stepper1_status_register_type stepper1_status_register;
      typedef uint32_t _stepper2_status_register_type;
      _stepper2_status_register_type stepper2_status_register;
      typedef uint32_t _stepper3_status_register_type;
      _stepper3_status_register_type stepper3_status_register;
      typedef uint32_t _stepper1_pos_type;
      _stepper1_pos_type stepper1_pos;
      typedef uint32_t _stepper2_pos_type;
      _stepper2_pos_type stepper2_pos;
      typedef uint32_t _stepper3_pos_type;
      _stepper3_pos_type stepper3_pos;
      typedef uint16_t _encoder1_pos_type;
      _encoder1_pos_type encoder1_pos;
      typedef uint16_t _encoder2_pos_type;
      _encoder2_pos_type encoder2_pos;
      typedef uint16_t _encoder3_pos_type;
      _encoder3_pos_type encoder3_pos;

    Status():
      stepper1_status_register(0),
      stepper2_status_register(0),
      stepper3_status_register(0),
      stepper1_pos(0),
      stepper2_pos(0),
      stepper3_pos(0),
      encoder1_pos(0),
      encoder2_pos(0),
      encoder3_pos(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stepper1_status_register >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stepper1_status_register >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stepper1_status_register >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stepper1_status_register >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepper1_status_register);
      *(outbuffer + offset + 0) = (this->stepper2_status_register >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stepper2_status_register >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stepper2_status_register >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stepper2_status_register >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepper2_status_register);
      *(outbuffer + offset + 0) = (this->stepper3_status_register >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stepper3_status_register >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stepper3_status_register >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stepper3_status_register >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepper3_status_register);
      *(outbuffer + offset + 0) = (this->stepper1_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stepper1_pos >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stepper1_pos >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stepper1_pos >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepper1_pos);
      *(outbuffer + offset + 0) = (this->stepper2_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stepper2_pos >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stepper2_pos >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stepper2_pos >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepper2_pos);
      *(outbuffer + offset + 0) = (this->stepper3_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stepper3_pos >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stepper3_pos >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stepper3_pos >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepper3_pos);
      *(outbuffer + offset + 0) = (this->encoder1_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encoder1_pos >> (8 * 1)) & 0xFF;
      offset += sizeof(this->encoder1_pos);
      *(outbuffer + offset + 0) = (this->encoder2_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encoder2_pos >> (8 * 1)) & 0xFF;
      offset += sizeof(this->encoder2_pos);
      *(outbuffer + offset + 0) = (this->encoder3_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encoder3_pos >> (8 * 1)) & 0xFF;
      offset += sizeof(this->encoder3_pos);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stepper1_status_register =  ((uint32_t) (*(inbuffer + offset)));
      this->stepper1_status_register |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stepper1_status_register |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stepper1_status_register |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stepper1_status_register);
      this->stepper2_status_register =  ((uint32_t) (*(inbuffer + offset)));
      this->stepper2_status_register |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stepper2_status_register |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stepper2_status_register |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stepper2_status_register);
      this->stepper3_status_register =  ((uint32_t) (*(inbuffer + offset)));
      this->stepper3_status_register |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stepper3_status_register |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stepper3_status_register |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stepper3_status_register);
      this->stepper1_pos =  ((uint32_t) (*(inbuffer + offset)));
      this->stepper1_pos |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stepper1_pos |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stepper1_pos |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stepper1_pos);
      this->stepper2_pos =  ((uint32_t) (*(inbuffer + offset)));
      this->stepper2_pos |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stepper2_pos |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stepper2_pos |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stepper2_pos);
      this->stepper3_pos =  ((uint32_t) (*(inbuffer + offset)));
      this->stepper3_pos |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stepper3_pos |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stepper3_pos |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stepper3_pos);
      this->encoder1_pos =  ((uint16_t) (*(inbuffer + offset)));
      this->encoder1_pos |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->encoder1_pos);
      this->encoder2_pos =  ((uint16_t) (*(inbuffer + offset)));
      this->encoder2_pos |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->encoder2_pos);
      this->encoder3_pos =  ((uint16_t) (*(inbuffer + offset)));
      this->encoder3_pos |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->encoder3_pos);
     return offset;
    }

    const char * getType(){ return "bombel_msgs/Status"; };
    const char * getMD5(){ return "dab0a957e9ba6ecedc554d33030652cf"; };

  };

}
#endif
