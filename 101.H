#ifndef __101_H__
#define __101_H__

#include"UART7.H"
#include"CRC16.h"

#define TRUE 1
#define FALSE 0
#define VALID 0x00
#define INVALID 0x80
#define PROTO_MBUS 6
#define PROTO_DCON 7
#define TUCOMMAND_MBUS 8
#define TUCOMMAND_DCON 8
#define DIAP_LO_101 0
#define DIAP_HI_101 49

typedef unsigned char byte;

typedef struct _Data101_{
	unsigned char addrmodbus;
	unsigned char func_ts_tu_tit;
	unsigned char com_port;
	unsigned char number_reg;
	unsigned char maska_param[32];
	int           cycl_oprosa;
	int           cycl_timer2;
	unsigned char validate;
	unsigned char num_request;
	unsigned char data[255];
	unsigned char timer1;
	unsigned char timer2;
	unsigned short beginTSADDR;
	unsigned char cntValid;
	short int first;//for first request
	unsigned char TUBuffer[8];
	unsigned char TUFlag;
	unsigned char Proto;
	unsigned char *command;
	unsigned char commandlen;
} Data101;

typedef struct _TU101_{
	unsigned char addrmodbus;
	unsigned char com_port;
	unsigned short begin;
	unsigned short end;
	unsigned char proto;
	unsigned char commandlen;
	unsigned char parentTS;
	unsigned char tic;
	unsigned char var_tic;
	unsigned char DCON_OffCommand[8];
} TU101;

int installTU101(unsigned char addrmodbus,
		 unsigned char com_port,
		 unsigned short begin,
		 unsigned short end,
		 unsigned char proto,
		 unsigned char commandlen,
		 unsigned char parentTS,
		 unsigned char tic
		 );

int  install101(unsigned char addrmodbus,
		unsigned char func_ts_tu_tit,
		unsigned char com_port,
		unsigned char number_reg,
		unsigned char *maska_param,
		int           cycl_oprosa,
		int           cycl_timer2,
		unsigned char validate,
		unsigned char num_request,
		unsigned char timer1,
		unsigned char timer2,
		unsigned char proto,
		unsigned char *command,
		unsigned char commandlen
		);
int getCnt101();
int getCntTU101();
unsigned char Busy101(int i);
void To101Data(int i);
int ToCom1Data(unsigned char *data, int len);
int ToCom2Data(unsigned char *data, int len);
int DataTransmitted101(int n);
unsigned char GetTimer1_101(int n);
unsigned char GetTimer2_101(int n);
void ClearCom101();
int DataReceived101(int n);
void SetBusy101(int n);
void ClearBusy101(int n);
short int GetOutputBufCom101(int n);
short int IsCom101(int n);
int validCRC(unsigned char *d, int len);
unsigned char getFunc101(int n);
unsigned char getRegnum101(int n);
unsigned char getDataByte101(int n, int indx);
void installCom(int n);
unsigned char* getMaska(int n);
unsigned char getValid(int n);
unsigned short getBeginAddr(int n);
unsigned char *GetCommand(int n);
unsigned char GetProto(int n);
unsigned char GetTUProto(int n);
unsigned char GetCommandLen(int n);
unsigned char GetTUCommandLen(int n);
int GetCyclTimer2_101DCON(int n);
unsigned char* getData(int n);
void DigitToSymbols(unsigned char digit, unsigned char *hi, unsigned char *lo);
int ReadBuffer101IntoArray( int id, unsigned char *array );
unsigned char GetParentTS(int n);
unsigned char TU_MBUSValid( unsigned char id );
unsigned char TU_DCONValid( unsigned char id );
unsigned char TU_Valid( unsigned char id );
unsigned char SetTic( unsigned char id );
unsigned char DecrementTic( unsigned char id );
void CreateCommandOffDCON( unsigned char id );
unsigned char Get_MODBUS_TU101( unsigned char id );
unsigned char *GetCommandOffDCON( unsigned char id );
unsigned char *GetTUBuffer( unsigned char id );
unsigned char IsData101VALID( unsigned char id );
unsigned char IsAnyDataINVALID();
unsigned char ReadBuffer101DCON( unsigned char id );
unsigned char HandleTU( unsigned char id );
unsigned char SetOIKTrigger();
unsigned char UnsetOIKTrigger();
unsigned char GetOIKTrigger();
unsigned char InitDCONTable();
unsigned char GetComPort101(int id);
#endif