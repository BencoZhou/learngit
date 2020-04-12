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
#define COMME_TIMEOUT                       (3)

#define FOOD_UP_PLACE_OK					(1)
#define FOOD_UP_PLACE_NO					(0)

#define FOOD_DOWN_PLACE_OK					(1)
#define FOOD_DOWN_PLACE_NO					(0)

#define FOOD_TOWER_LACK_FOOD				(1)


typedef enum
{
    SEND_TYPE_INQUIRE = 0,
    SEND_TYPE_CONTROL_START,
    SEND_TYPE_CONTROL_STOP,
    SEND_TYPE_CONTROL,
}SEND_TYPE;

typedef enum
{
    CONTROL_COMMAND_STATE_SECCESE = 0,
    CONTROL_COMMAND_STATE_FALSE,
    CONTROL_COMMAND_STATE_OVER,
}CONTROL_COMMAND_STATE;

typedef struct
{
    bool isHaveDevice;  // �Ƿ�ѡ�����豸
    bool isHaveAlarm;   // ��ѡ����豸�Ƿ��б���
    bool isEemergencyStop;  // ���豸�쳣ֹͣ
    bool isClickStart;  // ���������ť
    bool isClickStop;   // ���ֹͣ��ť
    bool isClickShutdown;  // ���ǿ��ֹͣ��ť
    bool isClickReshutdown;   // ����ָ�ֹͣ��ť
    DevicePara  rcDevice;     // �շ��������豸
    u32  maxTime[10];       // ���Է��͵�����ʱ�䳤��
    u8   stateMachineState;
	bool   controlArea[AREA_DEVICE_TOTAL_NUMBER];		//��������
	bool   controlStopArea[AREA_DEVICE_TOTAL_NUMBER];	//�����豸ֹͣ���� 
	bool   controlShutdownArea[AREA_DEVICE_TOTAL_NUMBER];	//�����豸ֹͣ���� 
	bool   controlStopDelayFlag[AREA_DEVICE_TOTAL_NUMBER];	//�����豸ֹͣ���� 
}DeviceControlPara;

void ControlMsgBoxInit(void);
void DeviceStopAndInquire(void);                // ȫ��ǿ��ֹͣ
void DeviceControlAndInquire(void); // ����
DeviceControlPara *DeviceControlParaGet(void);
bool SendTypeInquire(u8 areaIndex,u8 index);
//void InquireSend_Task(void *Task_Parameters);
//void ControlSend_Task(void *Task_Parameters);
void StateMachine_Task(void *Task_Parameters);
void DeviceShutdown(void);   // ǿ�ƹػ�  

#endif // _FOODLINECONTROL_H_



