#ifndef _CARD_H
#define _CARD_H

typedef struct _CMD
{
  unsigned char ReceiveBuffer[14];
  unsigned char ReceivePoint;
}CMD;
/* �ⲿ���� -------------------------------------------------------------------*/
extern xdata CMD Cmd;
/* �ⲿ���� ------------------------------------------------------------------ */
#endif /* __Uart_H */
