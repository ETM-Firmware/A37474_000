#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=TCPmodbus/TCPIPStack/ARP.c TCPmodbus/TCPIPStack/Delay.c TCPmodbus/TCPIPStack/ENC28J60.c TCPmodbus/TCPIPStack/Helpers.c TCPmodbus/TCPIPStack/ICMP.c TCPmodbus/TCPIPStack/IP.c TCPmodbus/TCPIPStack/StackTsk.c TCPmodbus/TCPIPStack/TCP.c TCPmodbus/TCPIPStack/Tick.c TCPmodbus/TCPmodbus.c TCPmodbus/TcpServerCanFormat.c A37474.c MCP23008.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o ${OBJECTDIR}/TCPmodbus/TCPmodbus.o ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o ${OBJECTDIR}/A37474.o ${OBJECTDIR}/MCP23008.o
POSSIBLE_DEPFILES=${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o.d ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o.d ${OBJECTDIR}/TCPmodbus/TCPmodbus.o.d ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o.d ${OBJECTDIR}/A37474.o.d ${OBJECTDIR}/MCP23008.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o ${OBJECTDIR}/TCPmodbus/TCPmodbus.o ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o ${OBJECTDIR}/A37474.o ${OBJECTDIR}/MCP23008.o

# Source Files
SOURCEFILES=TCPmodbus/TCPIPStack/ARP.c TCPmodbus/TCPIPStack/Delay.c TCPmodbus/TCPIPStack/ENC28J60.c TCPmodbus/TCPIPStack/Helpers.c TCPmodbus/TCPIPStack/ICMP.c TCPmodbus/TCPIPStack/IP.c TCPmodbus/TCPIPStack/StackTsk.c TCPmodbus/TCPIPStack/TCP.c TCPmodbus/TCPIPStack/Tick.c TCPmodbus/TCPmodbus.c TCPmodbus/TcpServerCanFormat.c A37474.c MCP23008.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=30F6014A
MP_LINKER_FILE_OPTION=,--script=p30F6014A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o: TCPmodbus/TCPIPStack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/ARP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o: TCPmodbus/TCPIPStack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/Delay.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o: TCPmodbus/TCPIPStack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/ENC28J60.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o: TCPmodbus/TCPIPStack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/Helpers.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o: TCPmodbus/TCPIPStack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/ICMP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o: TCPmodbus/TCPIPStack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/IP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o: TCPmodbus/TCPIPStack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/StackTsk.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o: TCPmodbus/TCPIPStack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/TCP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o: TCPmodbus/TCPIPStack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/Tick.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPmodbus.o: TCPmodbus/TCPmodbus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPmodbus.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPmodbus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPmodbus.c  -o ${OBJECTDIR}/TCPmodbus/TCPmodbus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPmodbus.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPmodbus.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o: TCPmodbus/TcpServerCanFormat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus 
	@${RM} ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TcpServerCanFormat.c  -o ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/A37474.o: A37474.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/A37474.o.d 
	@${RM} ${OBJECTDIR}/A37474.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  A37474.c  -o ${OBJECTDIR}/A37474.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/A37474.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/A37474.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MCP23008.o: MCP23008.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MCP23008.o.d 
	@${RM} ${OBJECTDIR}/MCP23008.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCP23008.c  -o ${OBJECTDIR}/MCP23008.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MCP23008.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/MCP23008.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o: TCPmodbus/TCPIPStack/ARP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/ARP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/ARP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o: TCPmodbus/TCPIPStack/Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/Delay.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/Delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o: TCPmodbus/TCPIPStack/ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/ENC28J60.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/ENC28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o: TCPmodbus/TCPIPStack/Helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/Helpers.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/Helpers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o: TCPmodbus/TCPIPStack/ICMP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/ICMP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/ICMP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o: TCPmodbus/TCPIPStack/IP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/IP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/IP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o: TCPmodbus/TCPIPStack/StackTsk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/StackTsk.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/StackTsk.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o: TCPmodbus/TCPIPStack/TCP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/TCP.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/TCP.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o: TCPmodbus/TCPIPStack/Tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus/TCPIPStack 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPIPStack/Tick.c  -o ${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPIPStack/Tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TCPmodbus.o: TCPmodbus/TCPmodbus.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPmodbus.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TCPmodbus.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TCPmodbus.c  -o ${OBJECTDIR}/TCPmodbus/TCPmodbus.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TCPmodbus.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TCPmodbus.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o: TCPmodbus/TcpServerCanFormat.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/TCPmodbus 
	@${RM} ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o.d 
	@${RM} ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TCPmodbus/TcpServerCanFormat.c  -o ${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/TCPmodbus/TcpServerCanFormat.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/A37474.o: A37474.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/A37474.o.d 
	@${RM} ${OBJECTDIR}/A37474.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  A37474.c  -o ${OBJECTDIR}/A37474.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/A37474.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/A37474.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MCP23008.o: MCP23008.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/MCP23008.o.d 
	@${RM} ${OBJECTDIR}/MCP23008.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCP23008.c  -o ${OBJECTDIR}/MCP23008.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MCP23008.o.d"        -g -omf=elf -I"../../ETM_LIBRARY/Version_03/inc" -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/MCP23008.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../ETM_LIBRARY/Version_03/lib/ETM_LINAC_CAN_30F6014A.a ../../ETM_LIBRARY/Version_03/lib/ETM_CORE_30F6014A.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\ETM_LIBRARY\Version_03\lib\ETM_LINAC_CAN_30F6014A.a ..\..\ETM_LIBRARY\Version_03\lib\ETM_CORE_30F6014A.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf  -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../ETM_LIBRARY/Version_03/lib/ETM_LINAC_CAN_30F6014A.a ../../ETM_LIBRARY/Version_03/lib/ETM_CORE_30F6014A.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\ETM_LIBRARY\Version_03\lib\ETM_LINAC_CAN_30F6014A.a ..\..\ETM_LIBRARY\Version_03\lib\ETM_CORE_30F6014A.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/A37474.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
