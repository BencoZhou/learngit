/*****************************************************************
 * File: Page6ReadPathConfig.h
 * Date: 2019/11/28 11:15
 * Copyright@2018-2028: INNOTEK, All Right Reserved
 *
 * Note:
 *
******************************************************************/
#ifndef _PAGE6READPATHCONFIG_H_
#define _PAGE6READPATHCONFIG_H_

#include "System.h"

#define PAGE6_DEVICE_PAGES              (5)         // 5ҳ��ÿҳ8���豸
#define PAGE6_DEVICE_PER                (8)         // 5ҳ��ÿҳ8���豸

#define PAGE6_PATH_TYPE1				(0x0600)	// 
#define PAGE6_PATH_AREA1                (0x0601)
#define PAGE6_PATH_MAIN_LINE1           (0x0602)
#define PAGE6_PATH_VICE_LINE1           (0x0603)
#define PAGE6_PATH_INSERT1              (0x0604)
#define PAGE6_PATH_DELETE1              (0x0605)
#define PAGE6_PATH_ID1					(0x0690)	// id + 8
											
#define PAGE6_PATH_INDEX                (0x06FD)    // �ڼ���·����0��ʾ��1��
#define PAGE6_PATH_READ                 (0x06FC)    // ���ð�ť
#define PAGE6_PATH_SAVE                 (0x06F9)    // ���沢����������ִ�������水ť
#define PAGE6_PATH_LEFT_BUTTON          (0x06FE)
#define PAGE6_PATH_RIGHT_BUTTON         (0x06FF)
											
#define PAGE6_PATH_CURRENT_PAGE         (0x06FA)    // ��ǰҳ
#define PAGE6_PATH_TOTAL_PAGES          (0x06FB)    // ��ҳ��
											
#define PAGE6_PATH_ALARM_PATH           (0x06F8)    // ������ʾ
#define PAGE6_PATH_ALARM_ID             (0x06ED)
#define PAGE6_PATH_ALARM_HIDE           (0x06EC)

#define PAGE6_READ_TYPE1				(0x0680)	// 
#define PAGE6_READ_AREA1                (0x0681)
#define PAGE6_READ_MAIN_LINE1           (0x0682)
#define PAGE6_READ_VICE_LINE1           (0x0683)
#define PAGE6_READ_ID1					(0x06D0)	// id + 8


void Page6PathConfigInit(void);
void Page6PathConfigProcess(u8 reg, u16 addr, u8 *pbuf, u8 len);
void Page6PathConfigRefresh(void);

#endif // _PAGE6READPATHCONFIG_H_



