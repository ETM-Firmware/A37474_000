/*
  -------------------------------------------
  This file contains configuration data specific to the A37474 Ethernet Interface Series
  
  Tyler Evans
  3.30.20

  --------------------------------------------
 */

#ifndef __A37474_CONFIG_H
#define __A37474_CONFIG_H

#define Reflexion_A37474_000
//#define Altair_A37474_001
//#define AET_A37474_450
//#define E2V_A37474_002

// Make sure that at least one board is selected
#ifndef Reflexion_A37474_000
#ifndef Altair_A37474_001
#ifndef AET_A37474_450
#ifndef E2V_A37474_002
#error "No Specific Board Selected"
#endif
#endif
#endif
#endif


#ifdef Reflexion_A37474_000
#define __MODE_ETHERNET_INTERFACE
#define __MODE_MODBUS_MONITOR
#define OLL_PIN_CPU_HV_ENABLE_HV_ENABLED        1
#define MAX_HEATER_RAMP_UP_TIME                 42000        // 7min If the heater does not reach it's programed voltage in this time a fault will be generated.
#define HEATER_RAMP_UP_TIME_PERIOD              71           // 710ms During heater ramp up, the heater voltage will be increased every N 10ms.
#define MAX_PROGRAM_HTR_VOLTAGE                 8000         // 8V Limit on what customer can set
#define HEATER_VOLTAGE_MAX_SET_POINT            8000         // 8V Actual limit
#define HEATER_VOLTAGE_MIN_SET_POINT            0            // 0V Lower Limit on Heater Voltage
#define MAX_HEATER_CURRENT_DURING_RAMP_UP       1420         // 1.420 Amps. [mA Units]. Whenever the heater voltage is increased (ramp-up or increasing the set point).  The voltage will be current limited by this current
#define HTR_OC_ABS                              1600         // 1.600 Amps.
#define HTR_UC_ABS                              200          // 200mA.
#define HV_MAX_SET_BOARD_SPEC                   20000        // -20KV
#define HV_MIN_SET_BOARD_SPEC                   0            // 0KV
#define TOP_MAX_SET_BOARD_SPEC                  22000        // 140V
#define TOP_MIN_SET_BOARD_SPEC                  0            // -80V
#define BIAS_OVER_VOLTAGE                       18000        // -180V
#define BIAS_UNDER_VOLTAGE                      14000        // -140V
#define BOARD_DASH_NUMBER                       000
#ifdef  Altair_A37474_001
#error "Multiple boards selected"
#endif
#ifdef  AET_A37474_450
#error "Multiple boards selected"
#endif
#ifdef  E2V_A37474_002
#error "Multiple boards selected"
#endif
#endif


#ifdef Altair_A37474_001
#define __MODE_ETHERNET_INTERFACE
#define __MODE_MODBUS_MONITOR
#define OLL_PIN_CPU_HV_ENABLE_HV_ENABLED        1
#define MAX_HEATER_RAMP_UP_TIME                 21000        // 3.5min.  If the heater does not reach it's programed voltage in this time a fault will be generated.
#define HEATER_RAMP_UP_TIME_PERIOD              30           // 300ms.  During heater ramp up, the heater voltage will be increased every N 10ms.
#define MAX_PROGRAM_HTR_VOLTAGE                 8000         // 8V Limit on what customer can set
#define HEATER_VOLTAGE_MAX_SET_POINT            8000         // 8V Actual limit
#define HEATER_VOLTAGE_MIN_SET_POINT            0            // 0V Lower Limit on Heater Voltage
#define MAX_HEATER_CURRENT_DURING_RAMP_UP       3650         // 3.650 Amps. Whenever the heater voltage is increased (ramp-up or increasing the set point).  The voltage will be current limited by this current
#define HTR_OC_ABS                              3750         // 3.750 Amps
#define HTR_UC_ABS                              0            // 0mA.
#define HV_MAX_SET_BOARD_SPEC                   20000        // -20KV
#define HV_MIN_SET_BOARD_SPEC                   0            // 0KV
#define TOP_MAX_SET_BOARD_SPEC                  22000        // 140V
#define TOP_MIN_SET_BOARD_SPEC                  0            // -80V
#define BIAS_OVER_VOLTAGE                       18000        // -180V
#define BIAS_UNDER_VOLTAGE                      14000        // -140V
#define BOARD_DASH_NUMBER                       001
#ifdef  AET_A37474_450
#error "Multiple boards selected"
#endif
#ifdef  E2V_A37474_002
#error "Multiple boards selected"
#endif
#endif


#ifdef AET_A37474_450
#define __MODE_ETHERNET_INTERFACE
#define __MODE_MODBUS_MONITOR
#define OLL_PIN_CPU_HV_ENABLE_HV_ENABLED        1
#define MAX_HEATER_RAMP_UP_TIME                 30000        // 5.0min.  If the heater does not reach it's programed voltage in this time a fault will be generated.
#define HEATER_RAMP_UP_TIME_PERIOD              30           // 300ms.  During heater ramp up, the heater voltage will be increased every N 10ms.
#define MAX_PROGRAM_HTR_VOLTAGE                 8300         // 8.3 V.  Limit on what customer can set
#define HEATER_VOLTAGE_MAX_SET_POINT            8300         // 8.3V.  Actual limit
#define HEATER_VOLTAGE_MIN_SET_POINT            0            // 0V.  Lower Limit on Heater Voltage
#define MAX_HEATER_CURRENT_DURING_RAMP_UP       5500         // 5.50 Amps
#define HTR_OC_ABS                              5600         // 5.600 Amps
#define HTR_UC_ABS                              0            // 0mA.
#define HV_MAX_SET_BOARD_SPEC                   20000        // -20KV
#define HV_MIN_SET_BOARD_SPEC                   0            // -0KV
#define TOP_MAX_SET_BOARD_SPEC                  40000        // 320V
#define TOP_MIN_SET_BOARD_SPEC                  0            // -80V
#define BIAS_OVER_VOLTAGE                       18000        // -180V
#define BIAS_UNDER_VOLTAGE                      14000        // -140V
#define BOARD_DASH_NUMBER                       450          // for A37474-450Z
#ifdef  E2V_A37474_002
#error "Multiple boards selected"
#endif
#endif


#ifdef E2V_A37474_002
#define __MODE_ETHERNET_INTERFACE
#define __MODE_MODBUS_MONITOR
#define OLL_PIN_CPU_HV_ENABLE_HV_ENABLED        1
#define MAX_HEATER_RAMP_UP_TIME                 21000        // 3.5min.  If the heater does not reach it's programed voltage in this time a fault will be generated.
#define HEATER_RAMP_UP_TIME_PERIOD              30           // 300ms.  During heater ramp up, the heater voltage will be increased every N 10ms.
#define MAX_PROGRAM_HTR_VOLTAGE                 8000         // 8.0 V.  Limit on what customer can set
#define HEATER_VOLTAGE_MAX_SET_POINT            8000         // 8.0V.  Actual limit
#define HEATER_VOLTAGE_MIN_SET_POINT            0            // 0V.  Lower Limit on Heater Voltage
#define MAX_HEATER_CURRENT_DURING_RAMP_UP       3750         // 3.750 Amps
#define HTR_OC_ABS                              4500         // 4.500 Amps
#define HTR_UC_ABS                              0            // 0mA.
#define HV_MAX_SET_BOARD_SPEC                   20000        // -20KV
#define HV_MIN_SET_BOARD_SPEC                   5000         // -5KV
#define TOP_MAX_SET_BOARD_SPEC                  22000        // 140V
#define TOP_MIN_SET_BOARD_SPEC                  0            // -80V
#define BIAS_OVER_VOLTAGE                       18000        // -180V
#define BIAS_UNDER_VOLTAGE                      14000        // -140V
#define BOARD_DASH_NUMBER                       002          // for A37474-002Z
#endif

/*----------------------------------------------------------------------*/
/*
  We have a couple of compile time options (selected by board option):
  __MODE_CAN_INTERFACE        
    In this mode, the gun driver is controlled over the CAN interface.
    The descrete digital/analog is not used.


  __MODE_DISCRETE_INTERFACE
    In this mode, the gun driver is controlled by discrete fiber or signal lines.
    The pulse top, high voltage, and heater references are generated from the external interface
  
  
  __MODE_MODBUS_INTERFACE
    In this mode, the gun driver is controlled by discrete fiber or signal lines.
    The pulse top, high voltage, and heater references are generated from the external interface
  
 
  __MODE_ETHERNET_INTERFACE
    In this mode, the gun driver is controlled by discrete fiber or signal lines.
    The pulse top, high voltage, and heater references are generated from the external interface
 

  __OPTION_ENABLE_CAN
    This is only valid for __MODE_DISCRETE_INTERFACE
    This allows the CAN port to be used for test and debugging while operating in one of these modes

 */


// Make sure that at least one mode is selected
#ifndef __MODE_CAN_INTERFACE
#ifndef __MODE_DISCRETE_INTERFACE
#ifndef __MODE_MODBUS_INTERFACE
#ifndef __MODE_ETHERNET_INTERFACE
#error "No reference Source Selected"
#endif
#endif
#endif
#endif


// Create and check compile time options based on configuration above
#ifdef __MODE_CAN_INTERFACE
#define __CAN_CONTROLS
#define __CAN_ENABLED
#define __CAN_REFERENCE
#ifdef __OPTION_ENABLE_CAN
#error "OPTION_ENABLE_CAN not valid modifier to MODE_CAN_INTERFACE"
#endif
#endif


#ifdef __MODE_DISCRETE_INTERFACE
#define __DISCRETE_CONTROLS
#ifdef  __CAN_REFERENCE
#error "Multiple references selected"
#endif
#ifdef  __MODBUS_REFERENCE
#error "Multiple references selected"
#endif
#endif


#ifdef __MODE_MODBUS_INTERFACE
#define __MODBUS_REFERENCE
#define __MODBUS_CONTROLS
#define __MODBUS_MONITOR
#endif

#ifdef __MODE_ETHERNET_INTERFACE
#define __ETHERNET_REFERENCE
#define __ETHERNET_CONTROLS
#endif

#ifdef __OPTION_ENABLE_CAN
#define __CAN_ENABLED
#endif


// -------------- Interface board Configuration ---------------------

#define SELECT_HV_ENABLE_FIBER                0xFF
#define SELECT_HV_ENABLE_DISCRETE             0xFE
#define SELECT_HV_ENABLE_SERIAL               0xFD
#define SELECT_HV_DISABLE                     0xFC


#define SELECT_BEAM_ENABLE_FIBER              0xFF
#define SELECT_BEAM_ENABLE_DISCRETE           0xFB
#define SELECT_BEAM_ENABLE_SERIAL             0xF7
#define SELECT_BEAM_DISABLE                   0xF3


#define SELECT_HV_ILOCK_ENABLE_FIBER          0xFF
#define SELECT_HV_ILOCK_ENABLE_DISCRETE       0xEF
#define SELECT_HV_ILOCK_ENABLE_SERIAL         0xDF
#define SELECT_HV_ILOCK_EXTERNAL_CONTROL      0xCF


#define PULSE_GATE_FIBER                      0xBF
#define PULSE_GATE_DISCRETE                   0xFF


#ifdef Reflexion_A37474_000
#define CONFIG_SELECT_PIN_BYTE               (SELECT_HV_ENABLE_SERIAL & SELECT_BEAM_ENABLE_SERIAL & SELECT_HV_ILOCK_EXTERNAL_CONTROL & PULSE_GATE_DISCRETE)
#endif
#ifdef Altair_A37474_001
#define CONFIG_SELECT_PIN_BYTE               (SELECT_HV_ENABLE_SERIAL & SELECT_BEAM_ENABLE_SERIAL & SELECT_HV_ILOCK_EXTERNAL_CONTROL & PULSE_GATE_DISCRETE)
#endif
#ifdef AET_A37474_450
#define CONFIG_SELECT_PIN_BYTE               (SELECT_HV_ENABLE_SERIAL & SELECT_BEAM_ENABLE_SERIAL & SELECT_HV_ILOCK_EXTERNAL_CONTROL & PULSE_GATE_DISCRETE)
#endif
#ifdef E2V_A37474_002
#define CONFIG_SELECT_PIN_BYTE               (SELECT_HV_ENABLE_SERIAL & SELECT_BEAM_ENABLE_SERIAL & SELECT_HV_ILOCK_EXTERNAL_CONTROL & PULSE_GATE_DISCRETE)
#endif


// ----------- Timers configurations - ALL Times are in 10ms Units --------------------
#define LED_STARTUP_FLASH_TIME                500      // Time LEDs will flash at startup
#define HEATER_AUTO_RESTART_TIME              500      // Time delay between a heater fault and when the heater gets restarted
#define GUN_DRIVER_POWER_SUPPLY_STARTUP_TIME  100      // Wait this long between enabling High Voltage / Pulse Top / Bias and cheching that they are at correct values
#define HEATER_REGULATION_TIME_PERIOD         5        // (50ms) This is the period that the regulation of the heater voltage takes between increments


// System control Parameters
#define MAX_CONVERTER_LOGIC_ADC_READ_ERRORS   20       // If the ADC read exceeds this number a fault will be created
#define MAX_HEATER_START_UP_ATTEMPTS          5        // If the heater ramp up process does not succeed in this many attempts, a fault will be generated that requires power cycle
#define MAX_DAC_TX_ATTEMPTS                   10       // The pic will attempt to write to the Converter Logic DAC this many times before giving up
#define HEATER_RAMP_UP_INCREMENT              10       // mV Units.  When ramping up the heater voltage it is increased by this amount each HEATER_RAMP_UP_TIME_PERIOD
#define HEATER_REGULATION_INCREMENT           50       // mV Units.  This is the regulation increment for the heater voltage


#define HEATER_VOLTAGE_CURRENT_LIMITED_FAULT_TIME   500 // 5 Seconds
#define CURRENT_LIMITED_FAULT_HOLDOFF_TIME          10  // 10 seconds at the start of heater warmup before current limit fault is timed
#define FAULT_HOLDOFF_STATE                         22


#ifdef __CAN_CONTROLS
#define HEATER_WARM_UP_TIME 100       //18000     // In Can control mode the heater warm up time is enforced by the ECB
#else
#define HEATER_WARM_UP_TIME 6000     // 1 minute
#endif


// ------------- Converter Logic Board ADC Input Settings ---------------------

// DPARKER figure out how to convert the temperature 
// It is in 2's compliment  This only works for positive temperatures
#define ADC_TEMPERATURE_SENSOR_FIXED_SCALE    1.25
#define ADC_TEMPERATURE_SENSOR_FIXED_OFFSET   0

//HV Input
#define ADC_HV_VMON_FIXED_SCALE               .34722
#define ADC_HV_VMON_FIXED_OFFSET              0
#define ADC_HV_VMON_RELATIVE_TRIP_SCALE       MACRO_DEC_TO_CAL_FACTOR_2(.2)
#define ADC_HV_VMON_RELATIVE_TRIP_FLOOR       1000                     
#define ADC_HV_VMON_RELATIVE_TRIP_COUNT       500                       // 500mS

//HV_I Input
#define ADC_HV_IMON_FIXED_SCALE               .10419
#define ADC_HV_IMON_FIXED_OFFSET              0

//Gun I Peak Input
#define ADC_GUN_I_PEAK_FIXED_SCALE            .17313
#define ADC_GUN_I_PEAK_FIXED_OFFSET           0

//HTR Input
#define ADC_HTR_V_MON_FIXED_SCALE             .13875
#define ADC_HTR_V_MON_FIXED_OFFSET            0
#define ADC_HTR_V_MON_RELATIVE_TRIP_SCALE     MACRO_DEC_TO_CAL_FACTOR_2(.2)
#define ADC_HTR_V_MON_RELATIVE_TRIP_FLOOR     200               // Minimum 200mV
#define ADC_HTR_V_MON_RELATIVE_TRIP_COUNT     500               // 500mS

//HTR I Input
#define ADC_HTR_I_MON_FIXED_SCALE             .10419
#define ADC_HTR_I_MON_FIXED_OFFSET            0
#define ADC_HTR_I_MON_OVER_LIMIT_ABSOLUTE     HTR_OC_ABS
#define ADC_HTR_I_MON_UNDER_LIMIT_ABSOLUTE    HTR_UC_ABS
#define ADC_HTR_I_MON_ABSOLUTE_TRIP_TIME      500                 // 500mS

//TOP Input
#define ADC_TOP_V_MON_FIXED_SCALE             .69438
#define ADC_TOP_V_MON_FIXED_OFFSET            0
#define ADC_TOP_V_MON_RELATIVE_TRIP_SCALE     MACRO_DEC_TO_CAL_FACTOR_2(.2)
#define ADC_TOP_V_MON_RELATIVE_TRIP_FLOOR     1000                  // 10 Volts
#define ADC_TOP_V_MON_RELATIVE_TRIP_TIME      500                   // 500mS 

//Bias Input
#define ADC_BIAS_V_MON_FIXED_SCALE            .34688
#define ADC_BIAS_V_MON_FIXED_OFFSET           0
#define ADC_BIAS_V_MON_OVER_LIMIT_ABSOLUTE    BIAS_OVER_VOLTAGE
#define ADC_BIAS_V_MON_UNDER_LIMIT_ABSOLUTE   BIAS_UNDER_VOLTAGE
#define ADC_BIAS_V_MON_ABSOLUTE_TRIP_TIME     500                      // 500mS 

//24V Input
#define ADC_24_V_MON_FIXED_SCALE              .41688
#define ADC_24_V_MON_FIXED_OFFSET             0

//Temp Input
#define ADC_TEMPERATURE_MON_FIXED_SCALE       .08331
#define ADC_TEMPERATURE_MON_FIXED_OFFSET      20400



// --------------------- Converter Logic Board DAC output Settings -------------- //

//HV Ouput
#define DAC_HIGH_VOLTAGE_FIXED_SCALE          3.0000
#define DAC_HIGH_VOLTAGE_FIXED_OFFSET         0
#define HIGH_VOLTAGE_MAX_SET_POINT            HV_MAX_SET_BOARD_SPEC
#define HIGH_VOLTAGE_MIN_SET_POINT            HV_MIN_SET_BOARD_SPEC

//Top Output
#define DAC_TOP_VOLTAGE_FIXED_SCALE           1.5000
#define DAC_TOP_VOLTAGE_FIXED_OFFSET          0
#define TOP_VOLTAGE_MAX_SET_POINT             TOP_MAX_SET_BOARD_SPEC
#define TOP_VOLTAGE_MIN_SET_POINT             TOP_MIN_SET_BOARD_SPEC

//Heater Output
#define DAC_HEATER_VOLTAGE_FIXED_SCALE        7.5188
#define DAC_HEATER_VOLTAGE_FIXED_OFFSET       0



// ------------- A37474 Internal PIC ADC Input Settings --------------------- //
#define POS_5V_FIXED_SCALE                    .15259                            // 1mV per lsb
#define POS_5V_FIXED_OFFSET                   0

#define POS_15V_FIXED_SCALE                   .32328
#define POS_15V_FIXED_OFFSET                  0

#define NEG_15V_FIXED_SCALE                   .32328                           // Change this
#define NEG_15V_FIXED_OFFSET                  0


//----  TCPmodbus ----
#define DEFAULT_REMOTE_IP_ADDRESS                            0x0F46A8C0  // 192.168.70.15
#define DEFAULT_IP_ADDRESS                                   0x6346A8C0  // 192.168.70.99

#endif