/*********************
LCD1602o�������ó���
*********************/
#include"1602.h"
#include"reg52.h"

/*****************************************
P0------DB0~DB7 
P2.6------RS
P2.5------RW
P2.7------E
*****************************************/
# define LCD_DB P0
sbit LCD_RS=P2^7;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^6;
/******���庯��****************/
# define uchar unsigned char
# define uint unsigned int
void LCD_init(void);//��ʼ��
void LCD_write_command(uchar command);//дָ��
void LCD_write_data(uchar dat);//д����
void LCD_disp_char(uchar x,uchar y,uchar dat);//��ʾ����
//void LCD_check_busy(void);//���æ����
void delay_n40us(uint n);//��ʱ����
//********************************
//*******3?��??��o����y***************
void LCD_init(void)
{
LCD_write_command(0x38);
LCD_write_command(0x0c);
LCD_write_command(0x06);
LCD_write_command(0x01);
delay_n40us(100);//?������
}
//********************************
//********дָ��************
void LCD_write_command(uchar dat)
{
LCD_DB=dat;
LCD_RS=0;
LCD_RW=0;
LCD_E=1;
delay_n40us(2);
LCD_E=0;

}
//*******************************
//********д����*************
void LCD_write_data(uchar dat)
{
LCD_DB=dat;
LCD_RS=1;
LCD_RW=0;
LCD_E=1;/
delay_n40us(2);
LCD_E=0;

}
//********************************
//*******��ʾ����*********
void LCD_disp_char(uchar x,uchar y,uchar dat)
{
uchar address;
if(y==1)
address=0x80+x;
else
address=0xc0+x;
LCD_write_command(address);
LCD_write_data(dat);
}
//********��ʱ����***************
void delay_n40us(uint n)
{ uint i;
uchar j;
for(i=n;i>0;i--)
for(j=0;j<2;j++); //ѭ������
}
