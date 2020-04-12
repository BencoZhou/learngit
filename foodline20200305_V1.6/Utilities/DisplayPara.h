/*****************************************************************
 * File: DisplayPara.h
 * Date: 2018/03/25 15:15
 * Copyright@2018-2028: INNOTEK, All Right Reserved
 *
 * Note:
 *
******************************************************************/
#ifndef _DISPLAYPARA_H_
#define _DISPLAYPARA_H_

#include "System.h"

#define PAGE_SIGN											(0xF000)	// �����ֽڱ�ʾ����һҳ���������ֽڱ�ʾҳ���ڵĵڼ�����ť��ת 

// �����洢��ַ
// ǰ��λ��ʾ����ҳ��
// ����λΪ�ؼ�����: 
// 0x00~0x3F ����¼������ݱ�����ʾ��
// 0xF0~0x7F ��ť��ֵ���أ�
// 0x80~0xBF ����ͼ�ꣻ
// 0xC0~0xFF �ı���

#define BACKLIGHT_LEV_MAX								(100)
#define BACKLIGHT_LEV_MIN								(0)
#define BACKLIGHT_INCR									(10)

#define LOCAL_REG_W										(0x80)
#define LOCAL_REG_R										(0x81)
#define VARMEM_W										(0x82)
#define VARMEM_R										(0x83)
#define CURVE_W											(0x84)   

#define BACKLIGHT_ADDR									(0x01)
#define CURVE_ADDR										(0xEB)
#define READ_TIME_ADDR									(0x20)
#define SET_TIME_ADDR									(0x1F)
#define WORK_MODE_ADDR									(0x12)
#define SCREEN_PROTECTION_LIGHT_ADDR					(0x17)
#define START_BACKLIGHT_ADDR							(0x16)
#define SCREEN_PROTECTION_TIME_ADDR						(0x18)
#define SCREEN_CONFIG_EN_ADDR							(0x1D)
#define SCREEN_SET_BPS_ADDR								(0x11)
#define SCREEN_BPS_INIT									(0x07)
#define POPUP_ADDR                                      (0x4F)

#define JUMP_TO_PIC_ADDR								(0x03)

#define COLOR_BALCK										(0xBFFF)	// ����ɫ����������
#define COLOR_EDIT										(0x0AD2)	// ��ԭ���ص�����



void DisplayParaInit(void);
void DisplayParaDealProcess(u8 reg, u16 displayAddr, u8 *pbuf, u8 len);

#endif // _DISPLAYPARA_H_
