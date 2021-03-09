/************************************************************************************
*����0x01ָ�����LED1
*����0x02ָ�����LED2
*����0x03ָ�����LED3
*����0x04ָ�����LED4
*����0xffָ���ˮ��
*************************************************************************************/

#include<reg52.h>
#include<card.h>
#define unit unsigned int
#define on 0
#define off 1

	xdata CMD Cmd;
	sbit led1 = P1^0;
	sbit led2 = P1^1;
	sbit led3 = P1^2;
	sbit led4 = P1^3;
	sbit led5 = P1^4;
	sbit led6 = P1^5;
	sbit led7 = P1^6;
	sbit led8 = P1^7;
void delay(unit xms)//��ʱ����
{
	unit i,j;
	for(i=xms;i>0;i--)
		for(j=122;j>0;j--);
}
void UsartConfiguration()//���ڲ������ú���
{
	SCON = 0X50;	//����Ϊ������ʽ1
	TMOD = 0X20;	//���ü�����������ʽ2
	PCON = 0X00;	//SMOD=0,32��Ƶ
	TH1 = 0Xfd;		//��������ʼֵ���ã�������Ϊ9600bit/s
	TL1 = 0Xfd;
	ES = 1;			//�򿪽����ж�
	EA = 1;			//�����ж�
	TR1 = 1;		//�򿪼�����
}


void ControlLED(unsigned char* a)//�ƿغ���
{
	if(a[12] == 0x84&a[13] == 0x36)
	{
		led1 = ~led1;
	}
}

void main()//������
{
	UsartConfiguration();
	while(1);	
}       

void Uart() interrupt 4	//�����жϺ���
{
	static unsigned char date;
	date = 	SBUF;
	RI = 0;
	if(date == 0x7F)
	{
			Cmd.ReceivePoint = 0;		
	}
	Cmd.ReceiveBuffer[Cmd.ReceivePoint++] = date;
	if(Cmd.ReceivePoint == 14)
	{
		ControlLED(Cmd.ReceiveBuffer);
	}
	if(TI){TI = 0;}
}