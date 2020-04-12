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

typedef enum
{
    SEND_TYPE_INQUIRE = 0,
    SEND_TYPE_CONTROL_START,
    SEND_TYPE_CONTROL_STOP,
    SEND_TYPE_CONTROL,
}SEND_TYPE;

typedef struct
{
    bool isHaveDevice;  // �Ƿ�ѡ�����豸
    bool isHaveAlarm;   // ��ѡ����豸�Ƿ��б���
    bool isClickStart;  // ���������ť
    bool isClickStop;   // ���ֹͣ��ť
    bool isClickShutdown;  // ���ǿ��ֹͣ��ť
    bool isClickReshutdown;   // ����ָ�ֹͣ��ť
    DevicePara  rcDevice;     // �շ��������豸
    u32  maxTime[10];       // ���Է��͵�����ʱ�䳤��
}DeviceControlPara;

void ControlMsgBoxInit(void);
void DeviceStateInquire(void);
void DeviceStopAndInquire(void);                // ȫ��ǿ��ֹͣ
void DeviceControlAndInquire(void); // ����
DeviceControlPara *DeviceControlParaGet(void);
//void InquireSend_Task(void *Task_Parameters);
void ControlSend_Task(void *Task_Parameters);
void StateMachine_Task(void *Task_Parameters);

#endif // _FOODLINECONTROL_H_



