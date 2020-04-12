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
                                
#define ICO_SHOW								(1)
#define ICO_HIDE								(0)


#define BigtoLittle16(A)   (( ((u16)(A) & 0xff00) >> 8)|	\
                                (( (u16)(A) & 0x00ff) << 8))  


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

void ParaSettingSendData(u32 srcaddr, u32 dstaddr, u8 len);
WirlessPara *WirlessParaGet(void);
/////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// path
//////////////////////////////////////////////////////////////
#define PATH_NUMBERS                    (50)    // ������·��
#define PATH_PER_INDEX                  (40)    // һ��·�����40���豸

typedef struct
{
    u8  type[PATH_NUMBERS][PATH_PER_INDEX];
    u8  area[PATH_NUMBERS][PATH_PER_INDEX];
    u8  mainLine[PATH_NUMBERS][PATH_PER_INDEX];
    u8  viceLine[PATH_NUMBERS][PATH_PER_INDEX];
    u32 id[PATH_NUMBERS][PATH_PER_INDEX];   // ·��ͳ��
    u8  how[PATH_NUMBERS];                  // ÿ��·�����豸����
    u8  index;                              // �ڼ���·����0��ʾ��1��
}PathPara;

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
}DevicePara;

typedef struct
{
    DevicePara dPara[PATH_NUMBERS][PATH_PER_INDEX];
    u8  how[PATH_NUMBERS];                  // ÿ��·�����豸����
    u8  index;                              // �ڼ���·����0��ʾ��1��
}PathParameter;

PathPara *PathParaGet(void);
PathParameter *PathParameterGet(void);

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// foodline device config �����������ò���
//////////////////////////////////////////////////////////////

#define DEVICE_CMD_PARA_CONFIG                          (0x39)

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

FoodlineDevicePara *FoodlineDeviceParaGet(void);

//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
// MassStorage
//////////////////////////////////////////////////////////////

void ParaMassStorageInit(void);
void ParaPathParaSave(void);
void ParaPathParaRead(void);
//////////////////////////////////////////////////////////////

#endif // _PARASETTINGLIB_H_















