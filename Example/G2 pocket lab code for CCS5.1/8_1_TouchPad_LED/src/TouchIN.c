/*=======================TouchIn.c========================
 * （1）将TouchIN_Dect()函数放置于定时中断中，就可以将触摸按键变成普通IO按键使用。
 * （2）全局变量TouchIN的作用相当于PxIN寄存器。
 * （3）触摸按键的识别最终转变为对无中断功能的IO按键识别上来。
  *  Created on: 2013-2-20
 *      Author: Administrator
 *======================================================*/
#include "MSP430G2553.h"
#define KEY_NUM 			2				/*触摸按键数目，根据需要修改*/
//=============具体触摸按键IO宏定义，根据需要添加代码===============
#define 	KEY0_INIT 			P2DIR &= ~BIT0; P2SEL &= ~BIT0; P2SEL2 |= BIT0		/*按键1开启振荡*/
#define 	KEY1_INIT 			P2DIR &= ~BIT5; P2SEL &= ~BIT5; P2SEL2 |= BIT5		/*按键2开启振荡*/
#define 	ALL_OSC_OFF 		P2SEL2 &= ~(BIT0 + BIT5)									/*关闭全部触摸振荡*/
const 	unsigned int	FREQ_THRESHOLD[KEY_NUM]={30000,30000};		/*各按键的识别门限频率 16ms:门限值取30000，1.9ms：门限值取：约3200*/
//==================静态全局变量============================
static unsigned int Freq[KEY_NUM];						//	当前测频值
static unsigned char Key_Buff[KEY_NUM][4]={0};	// 软件FIFO
static unsigned char Key_Num=0;							//	按键编号
//===============全局变量，如有需要可移植到Global.h统一管理================
unsigned char TouchIN;											// 相当于PxIN寄存器作用，支持8个触摸按键
//unsigned int TouchIN;												// 改为此句代码可支持16个触摸按键

/******************************************************************************************************
* 名       称：Key_Measure_Freq()
* 功       能：测量振荡频率
* 入口参数：无
* 出口参数：无
* 说    	明 ： 测量原理是直接对TA0主定时器读数。 如需使用其他定时器，需修改代码。
 ******************************************************************************************************/
void Key_Measure_Freq()
{
	ALL_OSC_OFF	;												//关闭所有振荡IO
	Freq[Key_Num]=TAR;										//当前编号按键的频率被测得
	Key_Num++;													//切换下一振荡IO
	if (Key_Num>=KEY_NUM)		Key_Num=0;	//各触摸按键循环交替
	switch(Key_Num)
	{
		case 0 : KEY0_INIT;	break;							//振荡IO初始化
		case 1 : KEY1_INIT; break;
		default:break;
	}
	TA0CTL = TASSEL_3+MC_2+TACLR;          	//增计数清0，并开始计数
}
/******************************************************************************************************
* 名       称：Key_FIFO()
* 功       能：将当前所测频率与门限电平比较的结果，缓存入4B的软件FIFO
* 入口参数：无
* 出口参数：无
* 说    	明 ： 软件FIFO的作用是保存最近4次的测量判断结果。
 ******************************************************************************************************/
void Key_FIFO()																		//存储连续4次测量数据
{
	Key_Buff[Key_Num][0]=Key_Buff[Key_Num][1];
	Key_Buff[Key_Num][1]=Key_Buff[Key_Num][2];
	Key_Buff[Key_Num][2]=Key_Buff[Key_Num][3];
	if( Freq[Key_Num]<FREQ_THRESHOLD[Key_Num])			//判断是否识别为按键
		Key_Buff[Key_Num][3]=1;
	else
		Key_Buff[Key_Num][3]=0;
}
/******************************************************************************************************
* 名       称：Key_Judge()
* 功       能：按键抗干扰仲裁。
* 入口参数：无
* 出口参数：无
* 说    	明 ： 只有连续4次都识别到按键才算按键被按下。
*                   只有连续4次都识别不到按键才算按键被松开。
 ******************************************************************************************************/
void Key_Judge()										//按键仲裁，只有连续4次测量结果一致，才算数
{
	if(		(Key_Buff[Key_Num][0]==0)&&(Key_Buff[Key_Num][1]==0)
			&&(Key_Buff[Key_Num][2]==0)&&(Key_Buff[Key_Num][3]==0)	)
//		TouchIN=0<<Key_Num;				//按键松开（错误代码）
		TouchIN &=~(1<<Key_Num);				//按键松开（正确代码）
	if(		(Key_Buff[Key_Num][0]==1)&&(Key_Buff[Key_Num][1]==1)
			&&(Key_Buff[Key_Num][2]==1)&&(Key_Buff[Key_Num][3]==1)	)
//		TouchIN =1<<Key_Num;			    //按键按下（错误代码）
		TouchIN |=1<<Key_Num;			    //按键按下
}
/******************************************************************************************************
* 名       称：TouchIN_Dect()
* 功       能：触摸按键检测。
* 入口参数：无
* 出口参数：无
* 说    	明 ： 在定时中断内调用该函数。
*                   调用该函数后，全局变量TouchIN就相当于PxIN了
 ******************************************************************************************************/
void TouchIN_Dect()											//触摸输入检测
{
	Key_Measure_Freq();										//测频
	Key_FIFO();														//软件FIFO缓存最近4次测量数据
	Key_Judge();													//仲裁按键是否按下或松开
}
