#ifndef __TCPSERVERCANFORMAT_H
#define __TCPSERVERCANFORMAT_H



#define TCP_CAN_INPUT_BUFFER_SIZE   16
#define TCP_CAN_OUTPUT_BUFFER_SIZE  16

#define TCP_BUS_TIMEOUT             100   /* in 10ms, timeout in 1s */



// sdo indexes
#if 0
	// entries required by CanOpen
	#define SDO_CO_DEVICE_TYPE      0x100000  
	#define SDO_CO_ERROR_REG        0x100100
	#define SDO_CO_GUARD_TIME       0x100C00
	#define SDO_CO_LIFETIME_FACTOR  0x100D00

	#define	SDO_CO_PRODUCER_HEARTBEAT_TIME  0x101700

	#define SDO_CO_ID_OBJ_ENTRIES       0x101800
	#define SDO_CO_ID_OBJ_VENDOR_ID     0x101801
	#define SDO_CO_ID_OBJ_PRODUCT_CODE  0x101802
	#define SDO_CO_ID_OBJ_REV           0x101803

	#define SDO_CO_SYNC_COBID           0x100500
	#define SDO_CO_SYNC_PERIOD          0x100600
	#define SDO_CO_SYNC_WIN_LEN         0x100700

	#define SDO_SERVER_ENTRIES  		0x120000
	#define SDO_SERVER_COBID_IN    		0x120001  // client to server
	#define SDO_SERVER_COBID_OUT  		0x120002  // server to client
#endif 
// customized entries
#define SDO_IDX_DEVICE_NAME     0x100A00
#define SDO_IDX_HW_VERSION      0x100B00
#define SDO_IDX_FW_NAME         0x100C00
#define SDO_IDX_FW_VERSION      0x100D00

#define SDO_IDX_RESET_CMD       0x600A00
#define SDO_IDX_ZERO_HTD        0x600B00
#define SDO_IDX_HTR_CMD         0x600C00
#define SDO_IDX_HV_CMD	        0x600D00
#define SDO_IDX_PULSETOP_CMD    0x600E00
#define SDO_IDX_TRIG_CMD        0x600F00

#define SDO_IDX_HV_BYP_CMD      0x600800 /* bypass hv or not, internal to ETM */


#define SDO_IDX_EF_REF			0x601000
#define SDO_IDX_EG_REF			0x601001
#define SDO_IDX_EK_REF		    0x601002

#define SDO_IDX_EF_READ			0x602000
#define SDO_IDX_IF_READ		    0x603000

#define SDO_IDX_EC_READ		    0x602001
#define SDO_IDX_EG_READ		    0x602002
#define SDO_IDX_EK_READ		    0x602003

#define SDO_IDX_IKP_READ		0x603001
#define SDO_IDX_HTD_REMAIN      0x604000

#define SDO_IDX_GD_STATE        0x005000
#define SDO_IDX_GD_FAULT        0x006000       

#define SDO_IDX_GD_CTRL_STATE   0x007000 /* read control state, internal to ETM */


typedef struct {
  unsigned int  length;
  unsigned char bytes[8]; 
  // add time stamp?
} CANMSG;


extern void DoTcpCanCommand(void);

extern void InitTcpCan(void);
extern int  TcpCanGotCommand(void); // check whether there is a command in input buffer
//extern signed char CanBufferFull(unsigned char input);  // check whether input or output buffer is full
extern void PutResponseToBuffer(unsigned char length, unsigned char * data);

extern void GenericTCPServer(void);

extern unsigned int GetEthernetResetEnable(void);

#endif
