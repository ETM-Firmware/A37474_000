/*********************************************************************
 *
 *	Generic TCP Server Example Application
 *  Module for Microchip TCP/IP Stack
 *   -Implements an example "ToUpper" TCP server on port 9760 and 
 *	  should be used as a basis for creating new TCP server 
 *    applications
 *
 *********************************************************************
 * FileName:        GenericTCPServer.c
 * Dependencies:    TCP
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
 * Author               Date    	Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Howard Schlunder     10/19/06	Original
 * Microchip            08/11/10    Added ability to close session by
 *                                  pressing the ESCAPE key.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Description of how to run the demo:
 *   1) Connect the ethernet port of the programmed demo board to a 
 *        computer either directly or through a router.
 *   2) Determine the IP address of the demo board.  This can be done several
 *        different ways.
 *      a) If you are using a demo setup with an LCD display (e.g. Explorer 16
 *           or PICDEM.net 2), the IP address should be displayed on the second
 *           line of the display.
 *      b) Open the Microchip Ethernet Device Discoverer from the start menu.
 *           Press the "Discover Devices" button to see the addresses and host
 *           names of all devices with the Announce Protocol enabled on your
 *           network.  You may have to configure your computer's firewall to 
 *           prevent it from blocking UDP port 30303 for this solution.
 *      c) If your board is connected directly with your computer with a
 *           crossover cable: 
 *              1) Open a command/DOS prompt and type 'ipconfig'.  Find the 
 *                   network adaptor that is connected to the board.  The IP
 *                   address of the board is located in the 'Default Gateway'
 *                   field
 *              2) Open up the network status for the network adaptor that
 *                   connects the two devices.  This can be done by right clicking
 *                   on the network connection icon in the network settings folder 
 *                   and select 'status' from the menu. Find the 'Default Gateway'
 *                   field.
 *   3) Open a command/DOS prompt.  Type "telnet ip_address 9760" where
 *        ip_address is the IP address that you got from step 2.
 *   4) As you type characters, they will be echoed back in your command prompt
 *        window in UPPER CASE.
 *   5) Press Escape to end the demo.
 *
 ********************************************************************/
#define __TCPSERVERCANFORMAT_C

#include "TCPIPStack/TCPIPStack/TCPIPConfig.h"

#if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)
#include "TCPIPStack/TCPIPStack/TCPIP.h"


#include "TcpServerCanFormat.h"
#include "..\A37474.h"
#include "..\A37474_CONFIG.h"

// Defines which port the server will listen on
#define SERVER_PORT	9760


unsigned char sdo_reset_cmd_active;	  // logic resumes only when reset isn't active
unsigned char sdo_logic_reset;        // a separate cmd to reset fault
unsigned char sdo_htd_timer_reset; 

unsigned char sdo_htr_enable;
unsigned char sdo_hv_bypass;
unsigned char sdo_hv_enable;
unsigned char sdo_pulsetop_enable;
unsigned char sdo_trig_enable;  


CANMSG tcp_can_in_buffer[TCP_CAN_INPUT_BUFFER_SIZE]; 
CANMSG tcp_can_out_buffer[TCP_CAN_OUTPUT_BUFFER_SIZE]; 

signed char tcp_can_input_get_ptr;  // pointer to get data from buffer
signed char tcp_can_input_put_ptr;  // pointer to put data into buffer

signed char tcp_can_output_get_ptr;  // pointer to get data from buffer
signed char tcp_can_output_put_ptr;  // pointer to put data into buffer


/*****************************************************************************
  Function:
	void GenericTCPServer(void)

  Summary:
	Implements a simple ToUpper TCP Server.

  Description:
	This function implements a simple TCP server.  The function is invoked
	periodically by the stack to listen for incoming connections.  When a 
	connection is made, the server reads all incoming data, transforms it
	to uppercase, and echos it back.
	
	This example can be used as a model for many TCP server applications.

  Precondition:
	TCP is initialized.

  Parameters:
	None

  Returns:
  	None
  ***************************************************************************/
void GenericTCPServer(unsigned int resetTCP)
{
	WORD wMaxGet, wMaxPut;
	int buf_room;
    
	static TCP_SOCKET	MySocket;
	static enum _TCPServerState
	{
		SM_HOME = 0,
		SM_LISTENING,
        SM_CLOSING,
	} TCPServerState = SM_HOME;
    
    if (resetTCP) {
      TCPServerState = SM_CLOSING;
    }

	switch(TCPServerState)
	{
		case SM_HOME:
			// Allocate a socket for this server to listen and accept connections on
			MySocket = TCPOpen(0, TCP_OPEN_SERVER, SERVER_PORT, TCP_PURPOSE_GENERIC_TCP_SERVER);
			if(MySocket == INVALID_SOCKET)
				return;

			TCPServerState = SM_LISTENING;
			break;

		case SM_LISTENING:
			// See if anyone is connected to us
			if(!TCPIsConnected(MySocket))
				return;


			// Figure out how many bytes have been received and how many we can transmit.
			wMaxGet = TCPIsGetReady(MySocket);	// Get TCP RX FIFO byte count

	     	buf_room = (tcp_can_input_get_ptr - tcp_can_input_put_ptr - 1) & (TCP_CAN_INPUT_BUFFER_SIZE - 1);	 /* & 0x0f */
            
            if (wMaxGet >= 8 && buf_room > 0)
            {
				// Transfer the data out of the TCP RX FIFO and into our local processing buffer.
				tcp_can_in_buffer[tcp_can_input_put_ptr].length = TCPGetArray(MySocket, &tcp_can_in_buffer[tcp_can_input_put_ptr].bytes[0], 8);
                
            	tcp_can_input_put_ptr++;
	            tcp_can_input_put_ptr &= (TCP_CAN_INPUT_BUFFER_SIZE - 1);

            }
			
            // any data out?
		    if (tcp_can_output_put_ptr != tcp_can_output_get_ptr)
		    {
            	wMaxPut = TCPIsPutReady(MySocket);	// Get TCP TX FIFO free space
                
                if (wMaxPut >= 8) 
                {
					// Transfer the data out of our local processing buffer and into the TCP TX FIFO.
					TCPPutArray(MySocket, &tcp_can_out_buffer[tcp_can_output_get_ptr].bytes[0], 8);
			
					// No need to perform any flush.  TCP data in TX FIFO will automatically transmit itself after it accumulates for a while.  If you want to decrease latency (at the expense of wasting network bandwidth on TCP overhead), perform and explicit flush via the TCPFlush() API.
                    tcp_can_output_get_ptr++;
			        tcp_can_output_get_ptr &= (TCP_CAN_OUTPUT_BUFFER_SIZE - 1);
		        }       
		          
		    }
	

			break;

		case SM_CLOSING:
			// Close the socket connection.
            TCPClose(MySocket);

			TCPServerState = SM_HOME;
			break;
	}
}

 
//#include "A35975.h"
//#include "Canopen.h"
//#include "A35975_PINS.h"
//#include "config.h"
//#include "faults.h"
//#include "Version.h"
//#include <libpic30.h>


                                                    
/////////////////////////////////////////////////////////////////////////
// InitCan() initializes can1, optionally enabling interrupts
// so it can be used as the main console I/O port.
//
void InitTcpCan(void)
{      
    tcp_can_input_get_ptr = 0;
    tcp_can_input_put_ptr = 0;
    tcp_can_output_get_ptr = 0;
    tcp_can_output_put_ptr = 0;


} // InitCan()

/////////////////////////////////////////////////////////////////////////
// GotCommand() returns TRUE if there is a command in the buffer
//
int TcpCanGotCommand(void)
{
    return (tcp_can_input_put_ptr != tcp_can_input_get_ptr);
}

/////////////////////////////////////////////////////////////////////////
// XmitPtr() returns the transmitter pointer.  It exists to keep
// really smart compilers from optimizing out references to volatile
// data.  We could use the volatile keyword, but for most compilers,
// this is more secure.
//
/**static int XmitPtr(void)
{
    return can_output_get_ptr;
}*/
/////////////////////////////////////////////////////////////////////////
// put_response_to_buffer 
// 
//
void PutResponseToBuffer(unsigned char length, unsigned char * data)
{
   char next_xmit_ptr;
   unsigned char i;
   // rare chance to check output buffer overflow

   next_xmit_ptr = (tcp_can_output_put_ptr + 1) & (TCP_CAN_OUTPUT_BUFFER_SIZE - 1);
   //if (next_xmit_ptr != XmitPtr(); /* can_output_get_ptr */  // overwrite if buffer overflow
   {
      tcp_can_out_buffer[tcp_can_output_put_ptr].length = length;
  	  for (i = 0; i < length; i++)
  			tcp_can_out_buffer[tcp_can_output_put_ptr].bytes[i] = *(data + i);
      tcp_can_output_put_ptr = next_xmit_ptr;
   }
   // else output buffer overflows

}
/////////////////////////////////////////////////////////////////////////
// can_process_command 
// process and answer canopen commands
//
void CanProcessCommand(unsigned char length, unsigned char * data)
{
    unsigned char txData[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    unsigned long sdo_index;
    unsigned char is_upload;
    unsigned int set_value;
    
    if (length < 8) return;	  // ignore comm event
    
    is_upload = data[0] == 0x40 ? 1 : 0;
	sdo_index = ((unsigned long)data[2] << 16) + ((unsigned long)data[1] << 8) + (unsigned long)data[3];
    
    txData[0] = is_upload?  0x42 : 0x60;  // byte 0: server response to expedited upload/download
    txData[1] = data[1];
    txData[2] = data[2];
    txData[3] = data[3];
    
    
    switch (sdo_index) {
    case SDO_IDX_DEVICE_NAME:
    	if (is_upload) {
	    	txData[4] = '7';
	        txData[5] = '4';
	        txData[6] = '7';
	        txData[7] = '4';
        }
        else {
        	txData[4] = 0xff;
            txData[5] = 4;
        }       
     break;
     
    case SDO_IDX_HW_VERSION:
    	if (is_upload) {
        	#if 0
	    	txData[4] = 'C';
	        txData[5] = ' ';
	        txData[6] = ' ';
	        txData[7] = ' ';
            #else
	    	txData[4] = TARGET_CUSTOMER_HARDWARE_REV & 0xff;
	        txData[5] = 0;
	        txData[6] = 0;
	        txData[7] = 0;
            #endif
        }
        else {
        	txData[4] = 0xff;
            txData[5] = 4;
        }    
     break;
   
    case SDO_IDX_FW_NAME:
    	if (is_upload) {
	    	txData[4] = '7';
	        txData[5] = '4';
	        txData[6] = '7';
	        txData[7] = '4';
        }
        else {
        	txData[4] = 0xff;
            txData[5] = 4;
        }    
     break;
      
    case SDO_IDX_FW_VERSION:
    	if (is_upload) {
	    	txData[4] = FIRMWARE_MINOR_REV & 0xff;     
	        txData[5] = FIRMWARE_BRANCH & 0xff;  
	        txData[6] = FIRMWARE_AGILE_REV & 0xff;
	        txData[7] = 0;
        }
        else {
        	txData[4] = 0xff;
            txData[5] = 4;
        }       
     break;

    case SDO_IDX_RESET_CMD:
    	if (is_upload)
            txData[4] = (unsigned char) global_data_A37474.reset_active & 0xff; //sdo_reset_cmd_active;
        else if (data[4] == 0 || data[4] == 0xff) {

      //  	if (!sdo_reset_cmd_active && data[4])  
        	if (data[4])  global_data_A37474.ethernet_reset_cmd = 1;          //sdo_logic_reset = 1;	 
//    		sdo_reset_cmd_active = data[4];	
//            if (sdo_reset_cmd_active)
//            	PIN_HV_ON_SERIAL = !OLL_SERIAL_ENABLE; // turn off hv when reset is active 
        }
        // else	do nothing
        	
     break;

  
    case SDO_IDX_ZERO_HTD:
    	if (is_upload)
            txData[4] = sdo_htd_timer_reset;
        else if (data[4] == 0xff) {        
//          //	if (!sdo_htd_timer_reset) {
//    			sdo_htd_timer_reset = 0xff;	
//                software_skip_warmup = 1; 
//          //  } 
          sdo_htd_timer_reset = 0xff;
          global_data_A37474.heater_warm_up_time_remaining = 300;   //set remaining warmup to 3s
        }
        else
            sdo_htd_timer_reset = 0;	    
     break;
     
     
    case SDO_IDX_HTR_CMD:
    	if (is_upload)
        	txData[4] = sdo_htr_enable;
        else if (data[4] == 0 || data[4] == 0xff) {

          //	if (sdo_htr_enable != data[4]) { // only act when value changes
            	if (data[4])  global_data_A37474.request_heater_enable = 1;
                else  		  global_data_A37474.request_heater_enable = 0;
            
          //  }	 
    		sdo_htr_enable = data[4];	 
        }
        // else	do nothing
     break;

#if 0 // NA for now      
    case SDO_IDX_HV_BYP_CMD:
    	if (is_upload)
        	txData[4] = sdo_hv_bypass;
        else if (data[4] == 0 || data[4] == 0xff) {

        	LogHvControl(0);  // turn off hv where service bypass is changed
            sdo_hv_bypass = data[4];
            
                	 
        }
        // else	do nothing
    
     break;
#endif     
	     
    case SDO_IDX_HV_CMD:
    	if (is_upload)
        	txData[4] = sdo_hv_enable;
        else if (data[4] == 0 || data[4] == 0xff) {

          //	if (sdo_hv_enable != data[4]) { // only act when value changes
//            	if (data[4] && sdo_reset_cmd_active == 0)  PIN_HV_ON_SERIAL = OLL_SERIAL_ENABLE;
//                else if (data[4] == 0)		  			   PIN_HV_ON_SERIAL = !OLL_SERIAL_ENABLE;;	 // either hv off or reset command
                
                if (data[4])  PIN_HV_ON_SERIAL = OLL_SERIAL_ENABLE;
                else          PIN_HV_ON_SERIAL = !OLL_SERIAL_ENABLE;
            
                sdo_hv_enable = data[4];	 
          // }	 
        }
        // else	do nothing
    
     break;

#if 0 // NA for now	     
    case SDO_IDX_PULSETOP_CMD:
    	if (is_upload)
        	txData[4] = sdo_pulsetop_enable;
        else if (data[4] == 0 || data[4] == 0xff) {

          //	if (sdo_pulsetop_enable != data[4]) { // only act when value changes
            	if (data[4])  	LogPulsetopControl(1);
                else   			LogPulsetopControl(0);	 // either hv off or reset command
            
          //  }	 
    		sdo_pulsetop_enable = data[4];	 
        }
        // else	do nothing
        
     break;
#endif 

    case SDO_IDX_TRIG_CMD:
    	if (is_upload)
        	txData[4] = sdo_trig_enable;
        else if (data[4] == 0 || data[4] == 0xff) {

          //	if (sdo_trig_enable != data[4]) { // only act when value changes
            	if (data[4])  	        PIN_BEAM_ENABLE_SERIAL = OLL_SERIAL_ENABLE;
                else   			PIN_BEAM_ENABLE_SERIAL = !OLL_SERIAL_ENABLE;	 
            
          //  }	 
    		sdo_trig_enable = data[4];	 
        }
        // else	do nothing
        
     break;
 

    case SDO_IDX_EF_REF:
    	if (is_upload) {
        	txData[4] = global_data_A37474.heater_voltage_target & 0x00ff;
            txData[5] = (global_data_A37474.heater_voltage_target >> 8) & 0x00ff;
        }
        else {
        	// check max, min range
            set_value  = (unsigned int)data[5] << 8;
            set_value += (unsigned int)data[4];
            global_data_A37474.ethernet_htr_ref = set_value;
//            if (set_value <= MAX_PROGRAM_HTR_VOLTAGE)
//            {                        
//	        	global_data_A37474.heater_voltage_target = set_value;
//            }
        }
    
     break;
			
    case SDO_IDX_EG_REF:
    	if (is_upload) {
        	txData[4] = global_data_A37474.analog_output_top_voltage.set_point & 0x00ff;
            txData[5] = (global_data_A37474.analog_output_top_voltage.set_point >> 8) & 0x00ff;
        }
        else {
        	// check max, min range
            set_value  = (unsigned int)data[5] << 8;
            set_value += (unsigned int)data[4];
            global_data_A37474.ethernet_top_ref = set_value;
//            if (set_value <= TOP_VOLTAGE_MAX_SET_POINT)  
//            {    
//            	ETMAnalogSetOutput(&global_data_A37474.analog_output_top_voltage, set_value);                    
// 			}
       }
        
     break;
			
    case SDO_IDX_EK_REF:
    	if (is_upload) {
        	txData[4] = global_data_A37474.analog_output_high_voltage.set_point & 0x00ff;
            txData[5] = (global_data_A37474.analog_output_high_voltage.set_point >> 8) & 0x00ff;
        }
        else {
        	// check max, min range
            set_value  = (unsigned int)data[5] << 8;
            set_value += (unsigned int)data[4];
            global_data_A37474.ethernet_hv_ref = set_value;
//            if (set_value >= HIGH_VOLTAGE_MIN_SET_POINT && set_value <= HIGH_VOLTAGE_MAX_SET_POINT)  
//            {            
//            	ETMAnalogSetOutput(&global_data_A37474.analog_output_high_voltage, set_value);                    
//            }
        }
        
     break;
		 

    case SDO_IDX_EF_READ:
    	if (is_upload) {
        	txData[4] = global_data_A37474.input_htr_v_mon.reading_scaled_and_calibrated & 0x00ff;
        	txData[5] = (global_data_A37474.input_htr_v_mon.reading_scaled_and_calibrated >> 8) & 0x00ff;        
    	}
     break;
			
    case SDO_IDX_IF_READ:
    	if (is_upload) {
        	txData[4] = global_data_A37474.input_htr_i_mon.reading_scaled_and_calibrated & 0x00ff;
        	txData[5] = (global_data_A37474.input_htr_i_mon.reading_scaled_and_calibrated >> 8) & 0x00ff;        
    	}
     break;
		 
     
    case SDO_IDX_EC_READ:
     	if (is_upload) {
        	txData[4] = global_data_A37474.input_bias_v_mon.reading_scaled_and_calibrated & 0x00ff;
        	txData[5] = (global_data_A37474.input_bias_v_mon.reading_scaled_and_calibrated >> 8) & 0x00ff;        
    	}
     break;
		 
    case SDO_IDX_EG_READ:
    	if (is_upload) {
        	txData[4] = global_data_A37474.input_top_v_mon.reading_scaled_and_calibrated & 0x00ff;
        	txData[5] = (global_data_A37474.input_top_v_mon.reading_scaled_and_calibrated >> 8) & 0x00ff;        
    	}
     break;
		 
    case SDO_IDX_EK_READ:
    	if (is_upload) {
        	txData[4] = global_data_A37474.input_hv_v_mon.reading_scaled_and_calibrated & 0x00ff;
        	txData[5] = (global_data_A37474.input_hv_v_mon.reading_scaled_and_calibrated >> 8) & 0x00ff;
     	}
     break;
		 

    case SDO_IDX_IKP_READ:
    	if (is_upload) {
        	txData[4] = global_data_A37474.input_gun_i_peak.reading_scaled_and_calibrated & 0x00ff;
        	txData[5] = (global_data_A37474.input_gun_i_peak.reading_scaled_and_calibrated >> 8) & 0x00ff;        
    	}
     break;
		
    case SDO_IDX_HTD_REMAIN:
    	if (is_upload) {   
		    if (global_data_A37474.control_state == STATE_HEATER_RAMP_UP) {
		      set_value = (global_data_A37474.heater_ramp_up_time + HEATER_WARM_UP_TIME) / 100;
		    } else if (global_data_A37474.heater_warm_up_time_remaining > 100) {
		      set_value = global_data_A37474.heater_warm_up_time_remaining / 100;
		    } else {
		      set_value = 0;
		    }
        	txData[4] = set_value & 0x00ff;
        	txData[5] = (set_value >> 8) & 0x00ff;        
    	}    
     break;
   

    case SDO_IDX_GD_STATE:
    	if (is_upload) {        
        	txData[4] = global_data_A37474.current_state_msg & 0x00ff;
            txData[5] = (global_data_A37474.current_state_msg >> 8) & 0x00ff;
            
        	if (sdo_htr_enable)      	txData[6] |= 0x0001;
            if (sdo_hv_enable)  	 	txData[6] |= 0x0008;
            if (sdo_pulsetop_enable) 	txData[6] |= 0x0004;
            if (sdo_trig_enable)     	txData[6] |= 0x0010;
            if (sdo_reset_cmd_active)	txData[6] |= 0x0020;
            if (sdo_hv_bypass)			txData[6] |= 0x0040;
            
            if (PIN_CUSTOMER_HV_ON == ILL_PIN_CUSTOMER_HV_ON_ENABLE_HV)  	 			txData[7] |= 0x0008;
            if (PIN_CUSTOMER_BEAM_ENABLE == ILL_PIN_CUSTOMER_BEAM_ENABLE_BEAM_ENABLED)  txData[7] |= 0x0010;
 
     	}    
    
     break;
     
    case SDO_IDX_GD_FAULT:
    	if (is_upload) {
        	set_value = _FAULT_REGISTER;
        	txData[4] = set_value & 0x00ff;
        	txData[5] = (set_value >> 8) & 0x00ff;
            set_value = _WARNING_REGISTER;	
        	txData[6] = set_value & 0x00ff;
        	txData[7] = (set_value >> 8) & 0x00ff;            
    	}
     break;

#if 0  // NA for now    
    case SDO_IDX_GD_CTRL_STATE:	// reserved for debug    
    	if (is_upload) {        
        	txData[4] = read_cycles_in_2s & 0x00ff;
        	txData[5] = (read_cycles_in_2s >> 8) & 0x00ff;
        	txData[6] = (read_cycles_in_2s >> 16) & 0x00ff;
        	txData[7] = (read_cycles_in_2s >> 24) & 0x00ff;
    	}    
    
     break;
#endif
     
    default:
     break;
 
        
    }
     																						  	
    PutResponseToBuffer(8, &txData[0]);													    
																							  
}
																							  
/////////////////////////////////////////////////////////////////////////					  
// DoTcpCanCommand 																		  
// check and process TCP commands (in CAN format)														    
//
void DoTcpCanCommand(void)
{
    CANMSG msg;
    unsigned char i;
    
    msg.length = 0;
    
    if (TcpCanGotCommand())
    {
        msg.length = tcp_can_in_buffer[tcp_can_input_get_ptr].length;
        for (i = 0; i < msg.length; i++)
        	msg.bytes[i] = tcp_can_in_buffer[tcp_can_input_get_ptr].bytes[i];
    	
        tcp_can_input_get_ptr = (tcp_can_input_get_ptr + 1) & (TCP_CAN_INPUT_BUFFER_SIZE - 1);
    }

	if (msg.length) // got command
    {
//    	TCP_bus_timeout_10ms = 0;   // reset can timeout
    	CanProcessCommand(msg.length, &msg.bytes[0]);
    }

    
}

/////////////////////////////////////////////////////////////////////////					  
// GetEthernetResetEnable 																		  
// return reset status														    
//
unsigned int GetEthernetResetEnable(void) 
{
  if (sdo_logic_reset) 
  {
	 sdo_logic_reset = 0;  
	 return 1;
  } 
  else 
     return 0;
  
}

#endif //#if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)

