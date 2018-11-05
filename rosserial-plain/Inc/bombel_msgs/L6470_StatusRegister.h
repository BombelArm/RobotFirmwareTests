#ifndef _ROS_bombel_msgs_L6470_StatusRegister_h
#define _ROS_bombel_msgs_L6470_StatusRegister_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bombel_msgs
{

  class L6470_StatusRegister : public ros::Msg
  {
    public:
      typedef bool _HiZ_type;
      _HiZ_type HiZ;
      typedef bool _BUSY_type;
      _BUSY_type BUSY;
      typedef bool _SW_F_type;
      _SW_F_type SW_F;
      typedef bool _SW_EVN_type;
      _SW_EVN_type SW_EVN;
      typedef bool _DIR_type;
      _DIR_type DIR;
      typedef uint16_t _MOT_STATUS_type;
      _MOT_STATUS_type MOT_STATUS;
      typedef bool _NOTPERF_CMD_type;
      _NOTPERF_CMD_type NOTPERF_CMD;
      typedef bool _WRONG_CMD_type;
      _WRONG_CMD_type WRONG_CMD;
      typedef bool _UVLO_type;
      _UVLO_type UVLO;
      typedef bool _TH_WRN_type;
      _TH_WRN_type TH_WRN;
      typedef bool _TH_SD_type;
      _TH_SD_type TH_SD;
      typedef bool _OCD_type;
      _OCD_type OCD;
      typedef bool _STEP_LOSS_A_type;
      _STEP_LOSS_A_type STEP_LOSS_A;
      typedef bool _STEP_LOSS_B_type;
      _STEP_LOSS_B_type STEP_LOSS_B;
      typedef bool _SCK_MOD_type;
      _SCK_MOD_type SCK_MOD;

    L6470_StatusRegister():
      HiZ(0),
      BUSY(0),
      SW_F(0),
      SW_EVN(0),
      DIR(0),
      MOT_STATUS(0),
      NOTPERF_CMD(0),
      WRONG_CMD(0),
      UVLO(0),
      TH_WRN(0),
      TH_SD(0),
      OCD(0),
      STEP_LOSS_A(0),
      STEP_LOSS_B(0),
      SCK_MOD(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_HiZ;
      u_HiZ.real = this->HiZ;
      *(outbuffer + offset + 0) = (u_HiZ.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->HiZ);
      union {
        bool real;
        uint8_t base;
      } u_BUSY;
      u_BUSY.real = this->BUSY;
      *(outbuffer + offset + 0) = (u_BUSY.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->BUSY);
      union {
        bool real;
        uint8_t base;
      } u_SW_F;
      u_SW_F.real = this->SW_F;
      *(outbuffer + offset + 0) = (u_SW_F.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SW_F);
      union {
        bool real;
        uint8_t base;
      } u_SW_EVN;
      u_SW_EVN.real = this->SW_EVN;
      *(outbuffer + offset + 0) = (u_SW_EVN.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SW_EVN);
      union {
        bool real;
        uint8_t base;
      } u_DIR;
      u_DIR.real = this->DIR;
      *(outbuffer + offset + 0) = (u_DIR.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->DIR);
      *(outbuffer + offset + 0) = (this->MOT_STATUS >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->MOT_STATUS >> (8 * 1)) & 0xFF;
      offset += sizeof(this->MOT_STATUS);
      union {
        bool real;
        uint8_t base;
      } u_NOTPERF_CMD;
      u_NOTPERF_CMD.real = this->NOTPERF_CMD;
      *(outbuffer + offset + 0) = (u_NOTPERF_CMD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->NOTPERF_CMD);
      union {
        bool real;
        uint8_t base;
      } u_WRONG_CMD;
      u_WRONG_CMD.real = this->WRONG_CMD;
      *(outbuffer + offset + 0) = (u_WRONG_CMD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->WRONG_CMD);
      union {
        bool real;
        uint8_t base;
      } u_UVLO;
      u_UVLO.real = this->UVLO;
      *(outbuffer + offset + 0) = (u_UVLO.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->UVLO);
      union {
        bool real;
        uint8_t base;
      } u_TH_WRN;
      u_TH_WRN.real = this->TH_WRN;
      *(outbuffer + offset + 0) = (u_TH_WRN.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->TH_WRN);
      union {
        bool real;
        uint8_t base;
      } u_TH_SD;
      u_TH_SD.real = this->TH_SD;
      *(outbuffer + offset + 0) = (u_TH_SD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->TH_SD);
      union {
        bool real;
        uint8_t base;
      } u_OCD;
      u_OCD.real = this->OCD;
      *(outbuffer + offset + 0) = (u_OCD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->OCD);
      union {
        bool real;
        uint8_t base;
      } u_STEP_LOSS_A;
      u_STEP_LOSS_A.real = this->STEP_LOSS_A;
      *(outbuffer + offset + 0) = (u_STEP_LOSS_A.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->STEP_LOSS_A);
      union {
        bool real;
        uint8_t base;
      } u_STEP_LOSS_B;
      u_STEP_LOSS_B.real = this->STEP_LOSS_B;
      *(outbuffer + offset + 0) = (u_STEP_LOSS_B.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->STEP_LOSS_B);
      union {
        bool real;
        uint8_t base;
      } u_SCK_MOD;
      u_SCK_MOD.real = this->SCK_MOD;
      *(outbuffer + offset + 0) = (u_SCK_MOD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SCK_MOD);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_HiZ;
      u_HiZ.base = 0;
      u_HiZ.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->HiZ = u_HiZ.real;
      offset += sizeof(this->HiZ);
      union {
        bool real;
        uint8_t base;
      } u_BUSY;
      u_BUSY.base = 0;
      u_BUSY.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->BUSY = u_BUSY.real;
      offset += sizeof(this->BUSY);
      union {
        bool real;
        uint8_t base;
      } u_SW_F;
      u_SW_F.base = 0;
      u_SW_F.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->SW_F = u_SW_F.real;
      offset += sizeof(this->SW_F);
      union {
        bool real;
        uint8_t base;
      } u_SW_EVN;
      u_SW_EVN.base = 0;
      u_SW_EVN.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->SW_EVN = u_SW_EVN.real;
      offset += sizeof(this->SW_EVN);
      union {
        bool real;
        uint8_t base;
      } u_DIR;
      u_DIR.base = 0;
      u_DIR.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->DIR = u_DIR.real;
      offset += sizeof(this->DIR);
      this->MOT_STATUS =  ((uint16_t) (*(inbuffer + offset)));
      this->MOT_STATUS |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->MOT_STATUS);
      union {
        bool real;
        uint8_t base;
      } u_NOTPERF_CMD;
      u_NOTPERF_CMD.base = 0;
      u_NOTPERF_CMD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->NOTPERF_CMD = u_NOTPERF_CMD.real;
      offset += sizeof(this->NOTPERF_CMD);
      union {
        bool real;
        uint8_t base;
      } u_WRONG_CMD;
      u_WRONG_CMD.base = 0;
      u_WRONG_CMD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->WRONG_CMD = u_WRONG_CMD.real;
      offset += sizeof(this->WRONG_CMD);
      union {
        bool real;
        uint8_t base;
      } u_UVLO;
      u_UVLO.base = 0;
      u_UVLO.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->UVLO = u_UVLO.real;
      offset += sizeof(this->UVLO);
      union {
        bool real;
        uint8_t base;
      } u_TH_WRN;
      u_TH_WRN.base = 0;
      u_TH_WRN.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->TH_WRN = u_TH_WRN.real;
      offset += sizeof(this->TH_WRN);
      union {
        bool real;
        uint8_t base;
      } u_TH_SD;
      u_TH_SD.base = 0;
      u_TH_SD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->TH_SD = u_TH_SD.real;
      offset += sizeof(this->TH_SD);
      union {
        bool real;
        uint8_t base;
      } u_OCD;
      u_OCD.base = 0;
      u_OCD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->OCD = u_OCD.real;
      offset += sizeof(this->OCD);
      union {
        bool real;
        uint8_t base;
      } u_STEP_LOSS_A;
      u_STEP_LOSS_A.base = 0;
      u_STEP_LOSS_A.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->STEP_LOSS_A = u_STEP_LOSS_A.real;
      offset += sizeof(this->STEP_LOSS_A);
      union {
        bool real;
        uint8_t base;
      } u_STEP_LOSS_B;
      u_STEP_LOSS_B.base = 0;
      u_STEP_LOSS_B.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->STEP_LOSS_B = u_STEP_LOSS_B.real;
      offset += sizeof(this->STEP_LOSS_B);
      union {
        bool real;
        uint8_t base;
      } u_SCK_MOD;
      u_SCK_MOD.base = 0;
      u_SCK_MOD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->SCK_MOD = u_SCK_MOD.real;
      offset += sizeof(this->SCK_MOD);
     return offset;
    }

    const char * getType(){ return "bombel_msgs/L6470_StatusRegister"; };
    const char * getMD5(){ return "89839737b19c6c4c8e9a8f3451aec5bb"; };

  };

}
#endif