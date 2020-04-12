/*****************************************************************
 * File: ParaSettingLib.h
 * Date: 2018/03/28 14:53
 * Copyright@2018-2028: INNOTEK, All Right Reserved
 *
 * Note:
 *
******************************************************************/
#ifndef _PARASETTINGLIB_H_
#define _PARASETTINGLIB_H_

#include "System.h"

#define FOODLINE_STATE                          (0x3200)
#define DEVICE_CMD_PARA_CONFIG                          (0x39)
#define DEVICE_CMD_PATH_CONFIG                          (0x32)
#define DEVICE_CMD_READ_PATH                            (0x33)
#define DEVICE_CMD_FLINE_SET                            (0x36)
#define DEVICE_CMD_FLINE_READ                           (0x38)
                                
#define ICO_SHOW								(1)
#define ICO_HIDE								(0)


#define BigtoLittle16(A)   (( ((u16)(A) & 0xff00) >> 8)|	\
                                (( (u16)(A) & 0x00ff) << 8))  

typedef union
{
    u8 buf;
    struct
    {
        u8 b0:          1;
        u8 b1:          1;
        u8 b2:          1;
        u8 b3:          1;
        u8 b4:          1;
        u8 b5:          1;
        u8 b6:          1;
        u8 b7:          1;
    }b;
}BitOperation;


typedef enum
{
	SYSTEM_TIME_SATE_YEAR = 1,
	SYSTEM_TIME_SATE_MON,
	SYSTEM_TIME_SATE_DAY,
	SYSTEM_TIME_SATE_HOUR,
	SYSTEM_TIME_SATE_MIN,
	SYSTEM_TIME_SATE_MAX,
}SYSTEM_TIME_SATE;

typedef struct
{
	u8 year;
	u8 mon;
	u8 day;
	u8 hour;
	u8 min;
	SYSTEM_TIME_SATE state;
}SystemTime;

typedef struct
{
	u16 currentPage;	// ��ʾ����һҳ
	u16 lastPage;		// �ϴ�����һҳ
	u8  lastItem;		// ��һҳ�ĵڼ���	��1��ʼ1~8
	u8  currentTable;	// ��ǰҳ�ĵڼ���table ��0��ʼ
	u8  piggeryIndexhome;	// ��ҳ���ĵڼ�������
	u16 paraLastPage;		// ��ת��������ʾ����ǰ�Ľ����¼
}ScrInf;        // ��ǰҳ����ʾ��Ϣ

void ParaSettingLibInit(void);
ScrInf *ScrInfGet(void);
//////////////////////////////////////////////////////////////
// send
//////////////////////////////////////////////////////////////
#define SEND_SIZE						(87)

typedef struct
{
    u8 len;
    u8 buffer[SEND_SIZE];
    u8 cmd;
}WirlessPara;

void ParaSettingSendData(u32 srcaddr, u32 dstaddr);
WirlessPara *WirlessParaGet(void);
/////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// path
//////////////////////////////////////////////////////////////
#define PATH_NUMBERS                    (50)    // ������·��
#define PATH_PER_INDEX                  (40)    // һ��·�����40���豸

typedef enum
{
    DEVICE_NAME_NONE = 0,
    DEVICE_NAME_FLINE,              // ��������
    DEVICE_NAME_IN_TOWERS,          // �ϲ�����
    DEVICE_NAME_TOWERS_OUT,         // ��������
    DEVICE_NAME_MAIN_VICE,          // ����բ
    DEVICE_NAME_CONTROL,            // ����
    DEVICE_NAME_RELAY,              // �ź��м�
    DEVICE_NAME_MAX,
}DEVICE_NAME;

typedef union
{
    u32 id;
    struct
    {
        u32 viceLine:   7;
        u32 mainLine:   3;
        u32 area:       3;
        u32 type:       3;
        u32 device:     16;         // �̶�Ϊ0x3200
    }place;
    struct
    {
        u32 useID:      16;         // ·��Э����ʹ�õ�ID
        u32 device:     16;         // �̶�Ϊ0x3200
    }placeNew;
    struct
    {
        u8 rc0:         8;
        u8 rc1:         8;
        u8 rc2:         8;
        u8 rc3:         8;
    }placeRc;
}DevicePara;

typedef struct
{
    u8 next;    // 0xAA��ʾ�ȴ�Ӧ��,δ����0����Ϊͨ��ʧ��
    u8 path;    // �����·��
    u32 id;     // �����ID
}PathAlarmPara;

typedef struct
{
    DevicePara dPara[PATH_NUMBERS][PATH_PER_INDEX];
    u8  how[PATH_NUMBERS];                  // ÿ��·�����豸����
    u8  index;                              // �ڼ���·����0��ʾ��1��
    PathAlarmPara  alarm;
}PathParameter;

typedef struct
{
    DevicePara rcPara[PATH_PER_INDEX];
    u8 path;
    DevicePara readDevice;
}ReadPath;

//PathPara *PathParaGet(void);
PathParameter *PathParameterGet(void);
DevicePara *RcDeviceParaGet(void);
ReadPath *ReadPathGet(void);
u8 PathTrav(u32 id);


//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// foodline device config �����������ò���
//////////////////////////////////////////////////////////////


typedef union
{
    u8 buf;
    struct
    {
        u8 openAlarm:       1;
        u8 regulatingAlarm: 1;
        u8 currentAlarm:    1;
        u8 openphaseAlarm:  1;
        u8 rev:             4;
    }alarm;
}AlarmShield;

typedef union
{
    u8 buf;
    struct
    {
        u8 numberOne:       1;
        u8 numberTwo:       1;
        u8 numberThree:     1;  // [1,0] = [ʹ�ܣ�ʧ��]
        u8 rev:             4;
        u8 conType:         1;  // [1,0]=[���ߣ�����]
    }device;
}MatLevDevice;

typedef struct
{
    AlarmShield shield;     // �澯��������λ Bit0:���Ǹ澯 Bit1:�����ָ澯 Bit2:�����澯 Bit3:ȱ��澯 [1,0] = [ʹ�ܣ�ʧ��]
    u8  stateTime;          // ����״̬�˲�ʱ��
    u8  motorMintime;       // �����ͣ��С���
    u16 overCurMax;         // �����ж������ֵ
    u16 missPhaseMin;       // ȱ���ж���Сֵ
    u8  curAlarmFilTime;    // �����澯�˲�ʱ��
    u16 curCalib;           // ����У׼ϵ��
    u8  motorOnFilTime;     // �����������ʱ��
    MatLevDevice  maleDevice;   // ��λ��
    u8  commSum;            // ��λ��ͨ��״̬���� 3~20
}FoodlineDevicePara;
#define FOODLINEDEVICE_RC_DATA_LEN                         (13)

typedef struct
{
    u8 control;
    u8 sensorSelect;
    u16 overtime;
    u8 rcAlarm; // ������:  1 ���óɹ���       2 ����ʧ�ܡ�3 �ֶ�״̬����ʧ�ܡ�              4  ��λ��������λ��ͨѶʧ��ͨѶʧ�ܡ�                  5 ����˫�������ܷ�ת��
    u16 currentA;
    u16 currentB;
    u16 currentC;
    u8 state;
    BitOperation sensorState;
    BitOperation sensorComm;
    BitOperation alarm;
    u8 manualAuto;
}FoodlineControl;
#define FOODLINECONTROL_RC_DATA_LEN                         (11)


typedef struct
{
    BitOperation alarm;     // �澯��������λ Bit0�������쳣 Bit1�������쳣 [1,0]=[ʹ�ܣ�ʧ��]
    u8 stateTime;           // ����״̬�˲�ʱ�� ��λ0.1SĬ��0.5S 0.1~5s
    u16 openOvertime;        // ������ʱʱ�� ��λS Ĭ��200 0~255s
}SwitchValvePara;
#define SWITCHVALVEPARA_RC_DATA_LEN                         (4)

typedef struct
{
    u8 control;
    u8 rcAlarm; // ������:  1 ���óɹ���       2 ����ʧ�ܡ�3 �ֶ�״̬����ʧ�ܡ�              4  ��λ��������λ��ͨѶʧ��ͨѶʧ�ܡ�                  5 ����˫�������ܷ�ת��
    BitOperation onoff;
    u8 tcock;
    BitOperation alarm;
    u8 manualAuto;
}SwitchValveControl;
#define SVALVECONTROL_RC_DATA_LEN                           (4)

FoodlineDevicePara *FoodlineDeviceParaGet(void);
FoodlineControl *FoodlineControlGet(void);
SwitchValveControl *SwitchValveControlGet(void);
SwitchValvePara *SwitchValveParaGet(void);

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// MassStorage
//////////////////////////////////////////////////////////////

void ParaMassStorageInit(void);
void ParaPathParaSave(void);
void ParaPathParaRead(void);
//////////////////////////////////////////////////////////////
// ˢ����Ļʹ�ò���
//////////////////////////////////////////////////////////////
typedef struct
{
    u8 count;           // ˢ�´���
}ParaRefresh;
ParaRefresh *ParaRefreshGet(void);
//////////////////////////////////////////////////////////////

#endif // _PARASETTINGLIB_H_















