#ifndef __MCP23008_H
#define __MCP23008_H
/*
  This module is designed to interface a 16 bit microchip processor with 16 bit I/O Expander

  Only I2C Buses 1 and 2 are supported at this time.
*/

#include "ETM_I2C.h"




typedef struct {
  unsigned int pin_reset;
  unsigned int pin_int_a;
  unsigned int pin_int_b;
  unsigned char address;
  unsigned char i2c_port;
  unsigned char output_latch_a_in_ram;
  unsigned char output_latch_b_in_ram;
  unsigned char input_port_a_in_ram;
  unsigned char input_port_b_in_ram;
} MCP23008;

/*
  This module requires that the I2C bus be initialized externally before calling any of the read or write functions.
  The exact numbers will vary based on the frequency of your OSC and the Frequency that you want the bus to run at.
  Initialization should look something like this.
  Initialization will vary slightly between 24,30, and 33 series chips.
  See i2c.h for more information

*/




/* 
   The MCP23008 has 11 8-bit control registers including 1 configuration Register
   This module will access the ports with IOCON.BANK = 0
*/ 



   #define MCP23008_REGISTER_IODIR                 0x00  //
   #define MCP23008_REGISTER_IPOL                  0x01  //
   #define MCP23008_REGISTER_GPINTEN               0x02
   #define MCP23008_REGISTER_DEFVAL                0x03
   #define MCP23008_REGISTER_INTCON                0x04
   #define MCP23008_REGISTER_IOCON                 0x05  //
   #define MCP23008_REGISTER_GPPU                  0x06
   #define MCP23008_REGISTER_INTF                  0x07
   #define MCP23008_REGISTER_INTCAP                0x08
   #define MCP23008_REGISTER_GPIO                  0x09  
   #define MCP23008_REGISTER_OLAT                  0x0A  //


   #define MCP23008_DEFAULT_IOCON         0b00000000        // Default IOCON settings
   #define MCP23008_U12_IODIR_VALUE       0b00000000        // All gpio are Outputs
   #define MCP23008_U12_IPOL_VALUE        0x00              // Do Not Invert the inputs on Port

/*

  // Test U64 - MCP23017
  i2c_test |= MCP23017WriteSingleByte(&U64_MCP23017, MCP23017_REGISTER_IOCON, MCP23017_DEFAULT_IOCON);
  i2c_test |= MCP23017WriteSingleByte(&U64_MCP23017, MCP23017_REGISTER_IOCON, MCP23017_DEFAULT_IOCON);
  i2c_test |= MCP23017WriteSingleByte(&U64_MCP23017, MCP23017_REGISTER_IOCON, MCP23017_DEFAULT_IOCON);
  i2c_test |= MCP23017WriteSingleByte(&U64_MCP23017, MCP23017_REGISTER_OLATA, U64_MCP23017.output_latch_a_in_ram);
  i2c_test |= MCP23017WriteSingleByte(&U64_MCP23017, MCP23017_REGISTER_IODIRA, MCP23017_U64_IODIRA_VALUE);
  i2c_test |= MCP23017WriteSingleByte(&U64_MCP23017, MCP23017_REGISTER_IPOLA, MCP23017_U64_IPOLA_VALUE);
    
  if ((i2c_test & 0xFF00) == 0xFA00) {
    // There was a fault on the i2c bus, the MCP23017 did not initialize properly
    debug_status_register |= STATUS_DIGITAL_IO_EXP_ERROR;
    global_debug_counter.i2c_bus_error++;
  }
  
  i2c_test = MCP23017ReadSingleByte(&U64_MCP23017, MCP23017_REGISTER_IODIRA);
  if ((i2c_test & 0x00FF) != MCP23017_U64_IODIRA_VALUE) {
    // The MCP Write/Read operation failed
    debug_status_register |= STATUS_DIGITAL_IO_EXP_ERROR;
    global_debug_counter.i2c_bus_error++;
  }

  
    // We only want to update if there is a change in state.  Otherwise we have a lot of unnessary I2C traffic
  if (U64_MCP23017.output_latch_a_in_ram != temp_lat_a) {
    U64_MCP23017.output_latch_a_in_ram = temp_lat_a;
    if (MCP23017WriteSingleByte(&U64_MCP23017, MCP23017_REGISTER_OLATA, U64_MCP23017.output_latch_a_in_ram) != 0) {
      global_debug_counter.i2c_bus_error++;
    }
  }
  

*/
   





#define MCP23008_READ_CONTROL_BIT          0b00000001
#define MCP23008_WRITE_CONTROL_BIT         0b00000000


#define MCP23008_ADDRESS_0                 0b01000000
#define MCP23008_ADDRESS_1                 0b01000010
#define MCP23008_ADDRESS_2                 0b01000100
#define MCP23008_ADDRESS_3                 0b01000110
#define MCP23008_ADDRESS_4                 0b01001000
#define MCP23008_ADDRESS_5                 0b01001010
#define MCP23008_ADDRESS_6                 0b01001100
#define MCP23008_ADDRESS_7                 0b01001110



unsigned int MCP23008WriteSingleByte(MCP23008* ptr_MCP23008, unsigned char MCP23008_register, unsigned char register_data);
/*
  This function will write a single byte to the register specified by location

  This function will return 0x0000 if the operation completes sucessfully
  This function will return 0xFA00 if the operation fails
*/


unsigned int MCP23008ReadSingleByte(MCP23008* ptr_MCP23008, unsigned char MCP23008_register);
/*
  This function will read a single byte from register specified by location

  This function will return 0x00dd if the operation completes sucessfully
  This function will return 0xFAxx if the operation fails
*/

#endif
