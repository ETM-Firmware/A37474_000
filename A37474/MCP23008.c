#include "MCP23008.h"
#include "ETM_I2C.h"

unsigned int MCP23008WriteSingleByte(MCP23008* ptr_MCP23008, unsigned char MCP23008_register, unsigned char register_data) {
  unsigned int error_check;
  
  error_check = WaitForI2CBusIdle(ptr_MCP23008->i2c_port);                                                    // Wait for I2C Bus idle

  error_check |= GenerateI2CStart(ptr_MCP23008->i2c_port);                                                    // Generate start condition 

  error_check |= WriteByteI2C((ptr_MCP23008->address | MCP23008_WRITE_CONTROL_BIT), ptr_MCP23008->i2c_port);  // Write the address to the bus in WRITE MODE
  
  error_check |= WriteByteI2C(MCP23008_register, ptr_MCP23008->i2c_port);                                     // Write the register location to the bus

  error_check |= WriteByteI2C(register_data, ptr_MCP23008->i2c_port);                                         // Write the data to the bus
  
  error_check |= GenerateI2CStop(ptr_MCP23008->i2c_port);                                                     // Generate Stop Condition
  
//  ClrWdt();
  return error_check;
}

unsigned int MCP23008ReadSingleByte(MCP23008* ptr_MCP23008, unsigned char MCP23008_register) {
  unsigned int error_check;
  
  error_check = WaitForI2CBusIdle(ptr_MCP23008->i2c_port);                                                    // Wait for I2C Bus idle

  error_check |= GenerateI2CStart(ptr_MCP23008->i2c_port);                                                    // Generate start condition 

  error_check |= WriteByteI2C((ptr_MCP23008->address | MCP23008_WRITE_CONTROL_BIT), ptr_MCP23008->i2c_port);  // Write the address to the bus in WRITE MODE

  error_check |= WriteByteI2C(MCP23008_register, ptr_MCP23008->i2c_port);                                     // Write the register location to the bus

  error_check |= GenerateI2CRestart(ptr_MCP23008->i2c_port);                                                  // Generate re-start condition 

  error_check |= WriteByteI2C((ptr_MCP23008->address | MCP23008_READ_CONTROL_BIT), ptr_MCP23008->i2c_port);   // Write the address to the bus in READ MODE

  error_check |= ReadByteI2C(ptr_MCP23008->i2c_port);                                                         // Read a byte from the bus
  
  error_check |= GenerateI2CStop(ptr_MCP23008->i2c_port);                                                     // Generate Stop Condition
  
//  ClrWdt();
  return error_check;
}





