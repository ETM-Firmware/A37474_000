/*********************************************************************
 *
 *  Generic TCP Client Example Application
 *  Module for Microchip TCP/IP Stack
 *   -Implements an example HTTP client and should be used as a basis 
 *	  for creating new TCP client applications
 *	 -Reference: None.  Hopefully AN833 in the future.
 *
 *********************************************************************
 * FileName:        GenericTCPClient.c
 * Dependencies:    TCP, DNS, ARP, Tick
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.05 or higher
 *					Microchip C30 v3.12 or higher
 *					Microchip C18 v3.30 or higher
 *					HI-TECH PICC-18 PRO 9.63PL2 or higher
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2009 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date    Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder     8/01/06	Original
 ********************************************************************/
#define __GENERICTCPCLIENT_C

#define THIS_IS_STACK_APPLICATION

#define IS_MODBUS_MAIN  1


#include "TCPIPStack/TCPIPStack/TCPIPConfig.h"
#include "TCPIPStack/TCPIPStack/TCPIP.h"

#ifdef STACK_USE_GENERIC_TCP_SERVER_EXAMPLE
	#include "TcpServerCanFormat.h" 
#endif

#include <p30F6014a.h>
//#include "TCPmodbus.h"
//#include "A37474.h"



// Declare AppConfig structure and some other supporting stack variables
APP_CONFIG AppConfig;
static unsigned short wOriginalAppConfigChecksum;    // Checksum of the ROM defaults for AppConfig

//#define LED_PUT(a)	do{unsigned char vTemp = (a); LEDOP_IO = vTemp&0x1; LEDA_IO = vTemp&0x4; LEDB_IO = vTemp&0x2;} while(0)

void MODBUSTCPServer(void);
void GenericTCPClient(void);
void InitModbusData(void);


ETMEthernetMessageFromGUI    eth_message_from_GUI[ ETH_GUI_MESSAGE_BUFFER_SIZE ];
ETMEthernetCalToGUI          eth_cal_to_GUI[ ETH_CAL_TO_GUI_BUFFER_SIZE ];

#if 0

static BYTE         data_buffer[MAX_TX_SIZE];
static BYTE         modbus_send_index = 0;

static BYTE         modbus_refresh_index = 0;
static BYTE         modbus_command_request = 0;  /* how many commands from GUI */

//static BYTE         super_user_mode = 0;
static WORD         transaction_number = 0;

static BYTE         modbus_cmd_need_repeat = 0;  


static BYTE         eth_message_from_GUI_put_index;
static BYTE         eth_message_from_GUI_get_index;

static BYTE         eth_cal_to_GUI_put_index;
static BYTE         eth_cal_to_GUI_get_index;

static BYTE         send_high_speed_data_buffer;  /* bit 0 high for buffer A, bit 1 high for buffer B */
#endif

/****************************************************************************
  Function:
    static void InitializeBoard(void)

  Description:
    This routine initializes the hardware.  It is a generic initialization
    routine for many of the Microchip development boards, using definitions
    in HardwareProfile.h to determine specific initialization.

  Precondition:
    None

  Parameters:
    None - None

  Returns:
    None

  Remarks:
    None
***************************************************************************/
static void InitializeBoard(void)
{  
#if 0  
  // LEDs
  LEDA_TRIS = 0;
  LEDB_TRIS = 0;
  LEDOP_TRIS = 0;
  LED_PUT(0x00);
#endif  
    
#if defined(STACK_USE_UART)
  UART2TX_ON_TRIS = 0;
  UART2TX_ON_IO = 0;    // always disable TX1

  UART2TX_ON_TRIS = 0;
  UART2TX_ON_IO = 1;    // always enable TX2

#endif

  // UART
#if defined(STACK_USE_UART)

#if defined(__PIC24E__) || defined(__dsPIC33E__)
#if defined (ENC_CS_IO) || defined (WF_CS_IO)   // UART to be used in case of ENC28J60 or MRF24W
  __builtin_write_OSCCONL(OSCCON & 0xbf);
  RPOR9bits.RP101R = 3; //Map U2TX to RF5
  RPINR19bits.U2RXR = 0;
  RPINR19bits.U2RXR = 0x64; //Map U2RX to RF4
  __builtin_write_OSCCONL(OSCCON | 0x40);
#endif
#if(ENC100_INTERFACE_MODE == 0)                 // UART to be used only in case of SPI interface with ENC624Jxxx
  __builtin_write_OSCCONL(OSCCON & 0xbf);
  RPOR9bits.RP101R = 3; //Map U2TX to RF5
  RPINR19bits.U2RXR = 0;
  RPINR19bits.U2RXR = 0x64; //Map U2RX to RF4
  __builtin_write_OSCCONL(OSCCON | 0x40);

#endif
#endif

  UARTTX_TRIS = 0;
  UARTRX_TRIS = 1;
  UMODE = 0x8000;            // Set UARTEN.  Note: this must be done before setting UTXEN

#if defined(__C30__)
  USTA = 0x0400;        // UTXEN set
#define CLOSEST_UBRG_VALUE ((GetPeripheralClock()+8ul*BAUD_RATE)/16/BAUD_RATE-1)
#define BAUD_ACTUAL (GetPeripheralClock()/16/(CLOSEST_UBRG_VALUE+1))
#else    //defined(__C32__)
  USTA = 0x00001400;        // RXEN set, TXEN set
#define CLOSEST_UBRG_VALUE ((GetPeripheralClock()+8ul*BAUD_RATE)/16/BAUD_RATE-1)
#define BAUD_ACTUAL (GetPeripheralClock()/16/(CLOSEST_UBRG_VALUE+1))
#endif
    
#define BAUD_ERROR ((BAUD_ACTUAL > BAUD_RATE) ? BAUD_ACTUAL-BAUD_RATE : BAUD_RATE-BAUD_ACTUAL)
#define BAUD_ERROR_PRECENT    ((BAUD_ERROR*100+BAUD_RATE/2)/BAUD_RATE)
#if (BAUD_ERROR_PRECENT > 3)
#warning UART frequency error is worse than 3%
#elif (BAUD_ERROR_PRECENT > 2)
#warning UART frequency error is worse than 2%
#endif
    
  UBRG = CLOSEST_UBRG_VALUE;
#endif


  // Deassert all chip select lines so there isn't any problem with 
  // initialization order.  Ex: When ENC28J60 is on SPI2 with Explorer 16, 
  // MAX3232 ROUT2 pin will drive RF12/U2CTS ENC28J60 CS line asserted, 
  // preventing proper 25LC256 EEPROM operation.
#if defined(ENC_CS_TRIS)
  ENC_CS_IO = 1;
  ENC_CS_TRIS = 0;
#endif
}

/*********************************************************************
 * Function:        void InitAppConfig(void)
 *
 * PreCondition:    MPFSInit() is already called.
 *
 * Input:           None
 *
 * Output:          Write/Read non-volatile config variables.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *
 * Note:            None
 ********************************************************************/
// MAC Address Serialization using a MPLAB PM3 Programmer and 
// Serialized Quick Turn Programming (SQTP). 
// The advantage of using SQTP for programming the MAC Address is it
// allows you to auto-increment the MAC address without recompiling 
// the code for each unit.  To use SQTP, the MAC address must be fixed
// at a specific location in program memory.  Uncomment these two pragmas
// that locate the MAC address at 0x1FFF0.  Syntax below is for MPLAB C 
// Compiler for PIC18 MCUs. Syntax will vary for other compilers.
//#pragma romdata MACROM=0x1FFF0
static ROM BYTE SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};
//#pragma romdata

static void InitAppConfig(IPCONFIG* ip_config)
{
    
  // Start out zeroing all AppConfig bytes to ensure all fields are 
  // deterministic for checksum generation
  memset((void*)&AppConfig, 0x00, sizeof(AppConfig));
        
  AppConfig.Flags.bIsDHCPEnabled = 0;
  AppConfig.Flags.bInConfigMode = 0;
  memcpypgm2ram((void*)&AppConfig.MyMACAddr, (ROM void*)SerializedMACAddress, sizeof(AppConfig.MyMACAddr));
  //        {
  //            _prog_addressT MACAddressAddress;
  //            MACAddressAddress.next = 0x157F8;
  //            _memcpy_p2d24((char*)&AppConfig.MyMACAddr, MACAddressAddress, sizeof(AppConfig.MyMACAddr));
  //        }
  
  AppConfig.MyIPAddr.Val = ip_config->ip_addr;
  //AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2<<8ul | MY_DEFAULT_IP_ADDR_BYTE3<<16ul | MY_DEFAULT_IP_ADDR_BYTE4<<24ul;
  AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
  AppConfig.MyMask.Val = MY_DEFAULT_MASK_BYTE1 | MY_DEFAULT_MASK_BYTE2<<8ul | MY_DEFAULT_MASK_BYTE3<<16ul | MY_DEFAULT_MASK_BYTE4<<24ul;
  AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
  AppConfig.MyGateway.Val = MY_DEFAULT_GATE_BYTE1 | MY_DEFAULT_GATE_BYTE2<<8ul | MY_DEFAULT_GATE_BYTE3<<16ul | MY_DEFAULT_GATE_BYTE4<<24ul;
  AppConfig.PrimaryDNSServer.Val = MY_DEFAULT_PRIMARY_DNS_BYTE1 | MY_DEFAULT_PRIMARY_DNS_BYTE2<<8ul  | MY_DEFAULT_PRIMARY_DNS_BYTE3<<16ul  | MY_DEFAULT_PRIMARY_DNS_BYTE4<<24ul;
  AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2<<8ul  | MY_DEFAULT_SECONDARY_DNS_BYTE3<<16ul  | MY_DEFAULT_SECONDARY_DNS_BYTE4<<24ul;
    
  AppConfig.MyRemIPAddr.Val = ip_config->remote_ip_addr;
  //AppConfig.MyRemIPAddr.Val = MY_DEFAULT_REM_IP_ADDR_BYTE1 | MY_DEFAULT_REM_IP_ADDR_BYTE2<<8ul | MY_DEFAULT_REM_IP_ADDR_BYTE3<<16ul | MY_DEFAULT_REM_IP_ADDR_BYTE4<<24ul;
    
    
  // Load the default NetBIOS Host Name
  memcpypgm2ram(AppConfig.NetBIOSName, (ROM void*)MY_DEFAULT_HOST_NAME, 16);
  FormatNetBIOSName(AppConfig.NetBIOSName);
    

  // Compute the checksum of the AppConfig defaults as loaded from ROM
  wOriginalAppConfigChecksum = CalcIPChecksum((BYTE*)&AppConfig, sizeof(AppConfig));
}

void TCPmodbusSetIPAddress(unsigned char byte4, unsigned char byte3, unsigned char byte2, unsigned char byte1) {
  unsigned long temp;
  temp = byte4;
  temp <<= 24;
  AppConfig.MyIPAddr.Val = temp;
  
  temp = byte3;
  temp <<= 16;
  AppConfig.MyIPAddr.Val |= temp;
  
  temp = byte2;
  temp <<= 8;
  AppConfig.MyIPAddr.Val |= temp;
  
  AppConfig.MyIPAddr.Val |= byte1;
}


void TCPmodbusSetRemoteIPAddress(unsigned char byte4, unsigned char byte3, unsigned char byte2, unsigned char byte1) {
  unsigned long temp;
  temp = byte4;
  temp <<= 24;
  AppConfig.MyRemIPAddr.Val = temp;
  
  temp = byte3;
  temp <<= 16;
  AppConfig.MyRemIPAddr.Val |= temp;
  
  temp = byte2;
  temp <<= 8;
  AppConfig.MyRemIPAddr.Val |= temp;
  
  AppConfig.MyRemIPAddr.Val |= byte1;
}

//
// called once for initilization.
//
void TCPmodbus_init(IPCONFIG* ip_config)
{
  // Initialize application specific hardware
  InitializeBoard();

#if 1  //defined(STACK_USE_UART)
  // Initialize stack-related hardware components that may be 
  // required by the UART configuration routines
  TickInit();
#endif

  // Initialize Stack and application related NV variables into AppConfig.
  InitAppConfig(ip_config);
    
 // InitModbusData();

  // Initiates board setup process if button is depressed 
  // on startup
#if defined(STACK_USE_UART)
  DoUARTConfig();
#endif

#ifdef STACK_USE_GENERIC_TCP_SERVER_EXAMPLE 
   InitTcpCan(); 
#endif      

  // Initialize core stack layers (MAC, ARP, TCP, UDP) and
  // application modules (HTTP, SNMP, etc.)
  StackInit();


}
//
// Need to call this task periodically
//
void TCPmodbus_task(void)
{
  static DWORD t = 0;
  _LATB8 = 1;



  // Blink LED0 (right most one) every second.
  if(TickGet() - t >= TICK_SECOND/2ul)
    {
      t = TickGet();
  //    LEDOP_IO ^= 1;
    }

  // This task performs normal stack task including checking
  // for incoming packet, type of packet and calling
  // appropriate stack entity to process it.
  StackTask();
        
  
  // This tasks invokes each of the core stack application tasks
 // StackApplications();  // don't need

#ifdef STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE 
  GenericTCPClient();
#endif

#ifdef STACK_USE_GENERIC_TCP_SERVER_EXAMPLE 
  GenericTCPServer();
  DoTcpCanCommand();
#endif

#ifdef STACK_USE_MODBUS_TCP_SERVER
  MODBUSTCPServer();
#endif

  _LATB8 = 0;

//  ExecuteCommands();

}




