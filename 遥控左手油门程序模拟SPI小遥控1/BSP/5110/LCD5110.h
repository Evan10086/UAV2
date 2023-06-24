#ifndef _LCD5110_H_
#define _LCD5110_H_
#include "stm32f10x.h"

#include "Font6_8.h"
#include "Font8_16.h"
#include "Icon10_8.h"
#include "Font16_16.h"
//#include "Bitmap.h"

/******************************************************************************
							宏定义
*******************************************************************************/ 
#define u8 		unsigned char
#define u16 	unsigned short

/******************************************************************************
							全局函数声明
*******************************************************************************/ 




/******************************************************************************
				以下是基本操作和初始化函数
*******************************************************************************/ 

/*---初始化5110---*/
void InitLcd(void);

/*---设置5110行和列坐标----*/
void SetXY(u8 row,u8 column);

/*---清空整个5110屏幕----*/
void LcdClearAll(void);
	
/******************************************************************************
		以下是高度为8的各种操作函数(包括6*8字符和字符串，6*8符号，10*8图标)
*******************************************************************************/ 

//--every row contains 14 characters,there are 6 rows (font = 6 * 8)--//
//-----------------   	row		  ----------------------//
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		column = 0
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		column = 1
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		column = 2
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		column = 3
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		column = 4
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		column = 5
//------------------------------------------------------//

/*---直接写一个ASCII字符(6*8)到5110(不需要坐标，紧跟上个字符或图标)---*/
void WriteChar(u8 value);

/*---直接写一个ASCII字符(6*8)到5110---*/
void PutChar(u8 value,u8 column,u8 row);

/*---直接写一个字符串(6*8)到5110(不需要坐标，紧跟上个字符或图标)---*/
void WriteStr(char * str);

/*--直接写一个字符串(6*8)到5110--*/
void PutStr(char * str,u8 column,u8 row);

/*---画sign(6*8)(不需要坐标，紧跟上个字符或图标)---*/
void WriteSign(char * sign);

/*----画sign(6*8)----*/
void PutSign(char * sign,u8 column,u8 row);

/*---画Icon(10*8)(不需要坐标，紧跟上个字符或图标)---*/
void WriteIcon(char * icon);

/*--画Icon(10*8),row(0~74)--*/
void PutIcon(char * icon,u8 column,u8 row);


/******************************************************************************
		以下是高度为16的各种操作函数(包括8*16字符和字符串，16*16汉字)
*******************************************************************************/ 

//--every row contains 10 characters,there are 3 rows (font = 8 * 16)--//
//-----------       row       ------------//
	//0 1 2 3 ... 81 82 83//	column = 0
	//0 1 2 3 ... 81 82 83//
	//0 1 2 3 ... 81 82 83//	column = 1
	//0 1 2 3 ... 81 82 83//
	//0 1 2 3 ... 81 82 83//	column = 2
	//0 1 2 3 ... 81 82 83//
//-----------------------------------------//

/*-----直接写一个ASCII字符(8*16)到5110------*/
void PutWideChar(u8 value,u8 column,u8 row);

/*--直接写一个字符串(6*8)到5110，自动换行，row(0~76)--*/
void PutWideStr(char * str,u8 column,u8 row);

//--every row contains 5 characters,there are 3 rows (font = 16 * 16)--//
//----------      row       --------------//
	//0 1 2 3 ... 81 82 83//	column = 0
	//0 1 2 3 ... 81 82 83//
	//0 1 2 3 ... 81 82 83//	column = 1
	//0 1 2 3 ... 81 82 83//
	//0 1 2 3 ... 81 82 83//	column = 2
	//0 1 2 3 ... 81 82 83//
//----------------------------------------//

/*-----直接写一个汉字(16*16)到5110------*/
void PutHanzi(char Hanzi[],u8 column,u8 row);

/*--写一串汉字(16*16),自动换行,row(0~58)--*/
void PutHanziStr(char Hanzi[],u8 column,u8 row,u8 num);

/******************************************************************************
		以下是画图的各种操作函数(包括84*48,高度为8的倍数的图片)
*******************************************************************************/ 
//---------------   	x		  --------------------//
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		y = 0
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		y = 1
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		y = 2
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		y = 3
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		y = 4
	//0 1 2 3 4 5 6 7 8 9 10 11 12 13//		y = 5
//----------------------------------------------------//

/*---画picture(84*48)，全屏---*/
void DrawPicture(char bitmap[]);

/*---画picture(高度必须是8的倍数)---*/
void DrawBmp(char bitmap[],u8 x,u8 y,u8 width,u8 height);

#endif
