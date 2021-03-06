/*****************************************************************
 * File: Page11TowersOutConfig.h
 * Date: 2019/11/29 11:59
 * Copyright@2018-2028: INNOTEK, All Right Reserved
 *
 * Note:
 *
******************************************************************/
#ifndef _PAGE11TOWERSOUTCONFIG_H_
#define _PAGE11TOWERSOUTCONFIG_H_

#include "System.h"

#define PAGE11_OPENALARM_SHOW                        (0x0B00)
#define PAGE11_REGULATINGALARM_SHOW                  (0x0B01)
#define PAGE11_CURRENTALARM_SHOW                     (0x0B02)
#define PAGE11_OPENPHASEALARM_SHOW                   (0x0B03)
#define PAGE11_OPENALARM_BUTTON                      (0x0B04)
#define PAGE11_REGULATINGALARM_BUTTON                (0x0B05)
#define PAGE11_CURRENTALARM_BUTTON                   (0x0B06)
#define PAGE11_OPENPHASEALARM_BUTTON                 (0x0B07)
#define PAGE11_STATETIME                             (0x0B08)
#define PAGE11_MOTORMINTIME                          (0x0B09)
#define PAGE11_OVERCURMAX                            (0x0B0A)
#define PAGE11_MISSPHASEMIN                          (0x0B0B)
#define PAGE11_CURALARMFILTIME                       (0x0B0C)
#define PAGE11_CURCALIB                              (0x0B0D)
#define PAGE11_MOTORONFILTIME                        (0x0B0E)
#define PAGE11_CONTYPE_SHOW                          (0x0B10)
#define PAGE11_NUMBERTHREE_SHOW                      (0x0B11)
#define PAGE11_NUMBERTWO_SHOW                        (0x0B12)
#define PAGE11_NUMBERONE_SHOW                        (0x0B13)
#define PAGE11_CONTYPE_BUTTON                        (0x0B14)
#define PAGE11_NUMBERTHREE_BUTTON                    (0x0B15)
#define PAGE11_NUMBERTWO_BUTTON                      (0x0B16)
#define PAGE11_NUMBERONE_BUTTON                      (0x0B17)
#define PAGE11_COMMSUM                               (0x0B18)

#define PAGE11_TYPE1                                 (0x0B20)	// 
#define PAGE11_AREA1                                 (0x0B21)
#define PAGE11_MAIN_LINE1                            (0x0B22)
#define PAGE11_VICE_LINE1                            (0x0B23)
#define PAGE11_ID1                                   (0x0B30)	// id 

#define PAGE11_INQUIRY                               (0x0B24)
#define PAGE11_SEND                                  (0x0B25)


void Page11TowersOutConfigInit(void);
void Page11TowersOutConfigProcess(u8 reg, u16 addr, u8 *pbuf, u8 len);
void Page11TowersOutConfigRefresh(void);


#endif // _PAGE11TOWERSOUTCONFIG_H_

