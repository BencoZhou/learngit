/*****************************************************************
 * File: FoodlineControl.h
 * Date: 2019/12/03 16:00
 * Copyright@2018-2028: INNOTEK, All Right Reserved
 *
 * Note:
 *
******************************************************************/
#ifndef _FOODLINECONTROL_H_
#define _FOODLINECONTROL_H_

#include "System.h"

#define CONTROL_MSGSND_COUNT                (16)


typedef struct
{
    bool isHaveDevice;  // �Ƿ�ѡ�����豸
    bool isHaveAlarm;   // ��ѡ����豸�Ƿ��б���
    bool isClickStart;  // ���������ť
    bool isClickStop;   // ���ֹͣ��ť
}DeviceControlPara;

void ControlMsgBoxInit(void);
void DeviceStateInquire(void);
void DeviceControl(void);
DeviceControlPara *DeviceControlParaGet(void);
void ControlSend_Task(void *Task_Parameters);

#endif // _FOODLINECONTROL_H_



