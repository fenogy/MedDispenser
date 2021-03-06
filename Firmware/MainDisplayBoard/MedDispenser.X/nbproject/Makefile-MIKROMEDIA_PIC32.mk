#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-MIKROMEDIA_PIC32.mk)" "nbproject/Makefile-local-MIKROMEDIA_PIC32.mk"
include nbproject/Makefile-local-MIKROMEDIA_PIC32.mk
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=MIKROMEDIA_PIC32
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1687970324/Beep.o ${OBJECTDIR}/_ext/1687970324/drv_spi.o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o ${OBJECTDIR}/_ext/1687970324/M25P80.o ${OBJECTDIR}/_ext/1860783399/timer.o ${OBJECTDIR}/_ext/1919882987/HX8347.o ${OBJECTDIR}/_ext/803622919/Button.o ${OBJECTDIR}/_ext/803622919/Chart.o ${OBJECTDIR}/_ext/803622919/CheckBox.o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ${OBJECTDIR}/_ext/803622919/EditBox.o ${OBJECTDIR}/_ext/803622919/GOL.o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ${OBJECTDIR}/_ext/803622919/Grid.o ${OBJECTDIR}/_ext/803622919/GroupBox.o ${OBJECTDIR}/_ext/803622919/ListBox.o ${OBJECTDIR}/_ext/803622919/Meter.o ${OBJECTDIR}/_ext/803622919/Palette.o ${OBJECTDIR}/_ext/803622919/Picture.o ${OBJECTDIR}/_ext/803622919/Primitive.o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ${OBJECTDIR}/_ext/803622919/RadioButton.o ${OBJECTDIR}/_ext/803622919/RoundDial.o ${OBJECTDIR}/_ext/803622919/Slider.o ${OBJECTDIR}/_ext/803622919/StaticText.o ${OBJECTDIR}/_ext/803622919/TextEntry.o ${OBJECTDIR}/_ext/803622919/Window.o ${OBJECTDIR}/_ext/1472/CustomControlDemo.o ${OBJECTDIR}/_ext/1472/InternalResourceXC32.o ${OBJECTDIR}/_ext/1472/rtcc.o ${OBJECTDIR}/_ext/1472/SideButtons.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/StringConversion.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1687970324/Beep.o.d ${OBJECTDIR}/_ext/1687970324/drv_spi.o.d ${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d ${OBJECTDIR}/_ext/1687970324/M25P80.o.d ${OBJECTDIR}/_ext/1860783399/timer.o.d ${OBJECTDIR}/_ext/1919882987/HX8347.o.d ${OBJECTDIR}/_ext/803622919/Button.o.d ${OBJECTDIR}/_ext/803622919/Chart.o.d ${OBJECTDIR}/_ext/803622919/CheckBox.o.d ${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d ${OBJECTDIR}/_ext/803622919/EditBox.o.d ${OBJECTDIR}/_ext/803622919/GOL.o.d ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d ${OBJECTDIR}/_ext/803622919/Grid.o.d ${OBJECTDIR}/_ext/803622919/GroupBox.o.d ${OBJECTDIR}/_ext/803622919/ListBox.o.d ${OBJECTDIR}/_ext/803622919/Meter.o.d ${OBJECTDIR}/_ext/803622919/Palette.o.d ${OBJECTDIR}/_ext/803622919/Picture.o.d ${OBJECTDIR}/_ext/803622919/Primitive.o.d ${OBJECTDIR}/_ext/803622919/ProgressBar.o.d ${OBJECTDIR}/_ext/803622919/RadioButton.o.d ${OBJECTDIR}/_ext/803622919/RoundDial.o.d ${OBJECTDIR}/_ext/803622919/Slider.o.d ${OBJECTDIR}/_ext/803622919/StaticText.o.d ${OBJECTDIR}/_ext/803622919/TextEntry.o.d ${OBJECTDIR}/_ext/803622919/Window.o.d ${OBJECTDIR}/_ext/1472/CustomControlDemo.o.d ${OBJECTDIR}/_ext/1472/InternalResourceXC32.o.d ${OBJECTDIR}/_ext/1472/rtcc.o.d ${OBJECTDIR}/_ext/1472/SideButtons.o.d ${OBJECTDIR}/_ext/1472/Main.o.d ${OBJECTDIR}/_ext/1472/StringConversion.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1687970324/Beep.o ${OBJECTDIR}/_ext/1687970324/drv_spi.o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o ${OBJECTDIR}/_ext/1687970324/M25P80.o ${OBJECTDIR}/_ext/1860783399/timer.o ${OBJECTDIR}/_ext/1919882987/HX8347.o ${OBJECTDIR}/_ext/803622919/Button.o ${OBJECTDIR}/_ext/803622919/Chart.o ${OBJECTDIR}/_ext/803622919/CheckBox.o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ${OBJECTDIR}/_ext/803622919/EditBox.o ${OBJECTDIR}/_ext/803622919/GOL.o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ${OBJECTDIR}/_ext/803622919/Grid.o ${OBJECTDIR}/_ext/803622919/GroupBox.o ${OBJECTDIR}/_ext/803622919/ListBox.o ${OBJECTDIR}/_ext/803622919/Meter.o ${OBJECTDIR}/_ext/803622919/Palette.o ${OBJECTDIR}/_ext/803622919/Picture.o ${OBJECTDIR}/_ext/803622919/Primitive.o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ${OBJECTDIR}/_ext/803622919/RadioButton.o ${OBJECTDIR}/_ext/803622919/RoundDial.o ${OBJECTDIR}/_ext/803622919/Slider.o ${OBJECTDIR}/_ext/803622919/StaticText.o ${OBJECTDIR}/_ext/803622919/TextEntry.o ${OBJECTDIR}/_ext/803622919/Window.o ${OBJECTDIR}/_ext/1472/CustomControlDemo.o ${OBJECTDIR}/_ext/1472/InternalResourceXC32.o ${OBJECTDIR}/_ext/1472/rtcc.o ${OBJECTDIR}/_ext/1472/SideButtons.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/StringConversion.o


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-MIKROMEDIA_PIC32.mk dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX460F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1687970324/Beep.o: ../../../Board\ Support\ Package/Beep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/Beep.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/Beep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/Beep.o.d" -o ${OBJECTDIR}/_ext/1687970324/Beep.o "../../../Board Support Package/Beep.c"   
	
${OBJECTDIR}/_ext/1687970324/drv_spi.o: ../../../Board\ Support\ Package/drv_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/drv_spi.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" -o ${OBJECTDIR}/_ext/1687970324/drv_spi.o "../../../Board Support Package/drv_spi.c"   
	
${OBJECTDIR}/_ext/1687970324/TouchScreen.o: ../../../Board\ Support\ Package/TouchScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o "../../../Board Support Package/TouchScreen.c"   
	
${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o: ../../../Board\ Support\ Package/TouchScreenResistive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o "../../../Board Support Package/TouchScreenResistive.c"   
	
${OBJECTDIR}/_ext/1687970324/M25P80.o: ../../../Board\ Support\ Package/M25P80.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/M25P80.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/M25P80.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/M25P80.o.d" -o ${OBJECTDIR}/_ext/1687970324/M25P80.o "../../../Board Support Package/M25P80.c"   
	
${OBJECTDIR}/_ext/1860783399/timer.o: ../../../Microchip/Common/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1860783399 
	@${RM} ${OBJECTDIR}/_ext/1860783399/timer.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1860783399/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1860783399/timer.o.d" -o ${OBJECTDIR}/_ext/1860783399/timer.o ../../../Microchip/Common/timer.c   
	
${OBJECTDIR}/_ext/1919882987/HX8347.o: ../../../Microchip/Graphics/Drivers/HX8347.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1919882987 
	@${RM} ${OBJECTDIR}/_ext/1919882987/HX8347.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1919882987/HX8347.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1919882987/HX8347.o.d" -o ${OBJECTDIR}/_ext/1919882987/HX8347.o ../../../Microchip/Graphics/Drivers/HX8347.c   
	
${OBJECTDIR}/_ext/803622919/Button.o: ../../../Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Button.o.d" -o ${OBJECTDIR}/_ext/803622919/Button.o ../../../Microchip/Graphics/Button.c   
	
${OBJECTDIR}/_ext/803622919/Chart.o: ../../../Microchip/Graphics/Chart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Chart.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Chart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Chart.o.d" -o ${OBJECTDIR}/_ext/803622919/Chart.o ../../../Microchip/Graphics/Chart.c   
	
${OBJECTDIR}/_ext/803622919/CheckBox.o: ../../../Microchip/Graphics/CheckBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/CheckBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" -o ${OBJECTDIR}/_ext/803622919/CheckBox.o ../../../Microchip/Graphics/CheckBox.c   
	
${OBJECTDIR}/_ext/803622919/DigitalMeter.o: ../../../Microchip/Graphics/DigitalMeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" -o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ../../../Microchip/Graphics/DigitalMeter.c   
	
${OBJECTDIR}/_ext/803622919/EditBox.o: ../../../Microchip/Graphics/EditBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/EditBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/EditBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/EditBox.o.d" -o ${OBJECTDIR}/_ext/803622919/EditBox.o ../../../Microchip/Graphics/EditBox.c   
	
${OBJECTDIR}/_ext/803622919/GOL.o: ../../../Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/GOL.o.d" -o ${OBJECTDIR}/_ext/803622919/GOL.o ../../../Microchip/Graphics/GOL.c   
	
${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o: ../../../Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" -o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ../../../Microchip/Graphics/GOLSchemeDefault.c   
	
${OBJECTDIR}/_ext/803622919/Grid.o: ../../../Microchip/Graphics/Grid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Grid.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Grid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Grid.o.d" -o ${OBJECTDIR}/_ext/803622919/Grid.o ../../../Microchip/Graphics/Grid.c   
	
${OBJECTDIR}/_ext/803622919/GroupBox.o: ../../../Microchip/Graphics/GroupBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GroupBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" -o ${OBJECTDIR}/_ext/803622919/GroupBox.o ../../../Microchip/Graphics/GroupBox.c   
	
${OBJECTDIR}/_ext/803622919/ListBox.o: ../../../Microchip/Graphics/ListBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/ListBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ListBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/ListBox.o.d" -o ${OBJECTDIR}/_ext/803622919/ListBox.o ../../../Microchip/Graphics/ListBox.c   
	
${OBJECTDIR}/_ext/803622919/Meter.o: ../../../Microchip/Graphics/Meter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Meter.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Meter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Meter.o.d" -o ${OBJECTDIR}/_ext/803622919/Meter.o ../../../Microchip/Graphics/Meter.c   
	
${OBJECTDIR}/_ext/803622919/Palette.o: ../../../Microchip/Graphics/Palette.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Palette.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Palette.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Palette.o.d" -o ${OBJECTDIR}/_ext/803622919/Palette.o ../../../Microchip/Graphics/Palette.c   
	
${OBJECTDIR}/_ext/803622919/Picture.o: ../../../Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Picture.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Picture.o.d" -o ${OBJECTDIR}/_ext/803622919/Picture.o ../../../Microchip/Graphics/Picture.c   
	
${OBJECTDIR}/_ext/803622919/Primitive.o: ../../../Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Primitive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Primitive.o.d" -o ${OBJECTDIR}/_ext/803622919/Primitive.o ../../../Microchip/Graphics/Primitive.c   
	
${OBJECTDIR}/_ext/803622919/ProgressBar.o: ../../../Microchip/Graphics/ProgressBar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/ProgressBar.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" -o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ../../../Microchip/Graphics/ProgressBar.c   
	
${OBJECTDIR}/_ext/803622919/RadioButton.o: ../../../Microchip/Graphics/RadioButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/RadioButton.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" -o ${OBJECTDIR}/_ext/803622919/RadioButton.o ../../../Microchip/Graphics/RadioButton.c   
	
${OBJECTDIR}/_ext/803622919/RoundDial.o: ../../../Microchip/Graphics/RoundDial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/RoundDial.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" -o ${OBJECTDIR}/_ext/803622919/RoundDial.o ../../../Microchip/Graphics/RoundDial.c   
	
${OBJECTDIR}/_ext/803622919/Slider.o: ../../../Microchip/Graphics/Slider.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Slider.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Slider.o.d" -o ${OBJECTDIR}/_ext/803622919/Slider.o ../../../Microchip/Graphics/Slider.c   
	
${OBJECTDIR}/_ext/803622919/StaticText.o: ../../../Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/StaticText.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/StaticText.o.d" -o ${OBJECTDIR}/_ext/803622919/StaticText.o ../../../Microchip/Graphics/StaticText.c   
	
${OBJECTDIR}/_ext/803622919/TextEntry.o: ../../../Microchip/Graphics/TextEntry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/TextEntry.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/TextEntry.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/TextEntry.o.d" -o ${OBJECTDIR}/_ext/803622919/TextEntry.o ../../../Microchip/Graphics/TextEntry.c   
	
${OBJECTDIR}/_ext/803622919/Window.o: ../../../Microchip/Graphics/Window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Window.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Window.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Window.o.d" -o ${OBJECTDIR}/_ext/803622919/Window.o ../../../Microchip/Graphics/Window.c   
	
${OBJECTDIR}/_ext/1472/CustomControlDemo.o: ../CustomControlDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomControlDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomControlDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/CustomControlDemo.o.d" -o ${OBJECTDIR}/_ext/1472/CustomControlDemo.o ../CustomControlDemo.c   
	
${OBJECTDIR}/_ext/1472/InternalResourceXC32.o: ../InternalResourceXC32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/InternalResourceXC32.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/InternalResourceXC32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/InternalResourceXC32.o.d" -o ${OBJECTDIR}/_ext/1472/InternalResourceXC32.o ../InternalResourceXC32.c   
	
${OBJECTDIR}/_ext/1472/rtcc.o: ../rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/rtcc.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/rtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/rtcc.o.d" -o ${OBJECTDIR}/_ext/1472/rtcc.o ../rtcc.c   
	
${OBJECTDIR}/_ext/1472/SideButtons.o: ../SideButtons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SideButtons.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SideButtons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/SideButtons.o.d" -o ${OBJECTDIR}/_ext/1472/SideButtons.o ../SideButtons.c   
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d" -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c   
	
${OBJECTDIR}/_ext/1472/StringConversion.o: ../StringConversion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/StringConversion.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/StringConversion.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/StringConversion.o.d" -o ${OBJECTDIR}/_ext/1472/StringConversion.o ../StringConversion.c   
	
else
${OBJECTDIR}/_ext/1687970324/Beep.o: ../../../Board\ Support\ Package/Beep.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/Beep.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/Beep.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/Beep.o.d" -o ${OBJECTDIR}/_ext/1687970324/Beep.o "../../../Board Support Package/Beep.c"   
	
${OBJECTDIR}/_ext/1687970324/drv_spi.o: ../../../Board\ Support\ Package/drv_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/drv_spi.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/drv_spi.o.d" -o ${OBJECTDIR}/_ext/1687970324/drv_spi.o "../../../Board Support Package/drv_spi.c"   
	
${OBJECTDIR}/_ext/1687970324/TouchScreen.o: ../../../Board\ Support\ Package/TouchScreen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreen.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreen.o "../../../Board Support Package/TouchScreen.c"   
	
${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o: ../../../Board\ Support\ Package/TouchScreenResistive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o.d" -o ${OBJECTDIR}/_ext/1687970324/TouchScreenResistive.o "../../../Board Support Package/TouchScreenResistive.c"   
	
${OBJECTDIR}/_ext/1687970324/M25P80.o: ../../../Board\ Support\ Package/M25P80.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1687970324 
	@${RM} ${OBJECTDIR}/_ext/1687970324/M25P80.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1687970324/M25P80.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1687970324/M25P80.o.d" -o ${OBJECTDIR}/_ext/1687970324/M25P80.o "../../../Board Support Package/M25P80.c"   
	
${OBJECTDIR}/_ext/1860783399/timer.o: ../../../Microchip/Common/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1860783399 
	@${RM} ${OBJECTDIR}/_ext/1860783399/timer.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1860783399/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1860783399/timer.o.d" -o ${OBJECTDIR}/_ext/1860783399/timer.o ../../../Microchip/Common/timer.c   
	
${OBJECTDIR}/_ext/1919882987/HX8347.o: ../../../Microchip/Graphics/Drivers/HX8347.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1919882987 
	@${RM} ${OBJECTDIR}/_ext/1919882987/HX8347.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1919882987/HX8347.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1919882987/HX8347.o.d" -o ${OBJECTDIR}/_ext/1919882987/HX8347.o ../../../Microchip/Graphics/Drivers/HX8347.c   
	
${OBJECTDIR}/_ext/803622919/Button.o: ../../../Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Button.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Button.o.d" -o ${OBJECTDIR}/_ext/803622919/Button.o ../../../Microchip/Graphics/Button.c   
	
${OBJECTDIR}/_ext/803622919/Chart.o: ../../../Microchip/Graphics/Chart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Chart.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Chart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Chart.o.d" -o ${OBJECTDIR}/_ext/803622919/Chart.o ../../../Microchip/Graphics/Chart.c   
	
${OBJECTDIR}/_ext/803622919/CheckBox.o: ../../../Microchip/Graphics/CheckBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/CheckBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/CheckBox.o.d" -o ${OBJECTDIR}/_ext/803622919/CheckBox.o ../../../Microchip/Graphics/CheckBox.c   
	
${OBJECTDIR}/_ext/803622919/DigitalMeter.o: ../../../Microchip/Graphics/DigitalMeter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/DigitalMeter.o.d" -o ${OBJECTDIR}/_ext/803622919/DigitalMeter.o ../../../Microchip/Graphics/DigitalMeter.c   
	
${OBJECTDIR}/_ext/803622919/EditBox.o: ../../../Microchip/Graphics/EditBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/EditBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/EditBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/EditBox.o.d" -o ${OBJECTDIR}/_ext/803622919/EditBox.o ../../../Microchip/Graphics/EditBox.c   
	
${OBJECTDIR}/_ext/803622919/GOL.o: ../../../Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/GOL.o.d" -o ${OBJECTDIR}/_ext/803622919/GOL.o ../../../Microchip/Graphics/GOL.c   
	
${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o: ../../../Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" -o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ../../../Microchip/Graphics/GOLSchemeDefault.c   
	
${OBJECTDIR}/_ext/803622919/Grid.o: ../../../Microchip/Graphics/Grid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Grid.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Grid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Grid.o.d" -o ${OBJECTDIR}/_ext/803622919/Grid.o ../../../Microchip/Graphics/Grid.c   
	
${OBJECTDIR}/_ext/803622919/GroupBox.o: ../../../Microchip/Graphics/GroupBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GroupBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/GroupBox.o.d" -o ${OBJECTDIR}/_ext/803622919/GroupBox.o ../../../Microchip/Graphics/GroupBox.c   
	
${OBJECTDIR}/_ext/803622919/ListBox.o: ../../../Microchip/Graphics/ListBox.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/ListBox.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ListBox.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/ListBox.o.d" -o ${OBJECTDIR}/_ext/803622919/ListBox.o ../../../Microchip/Graphics/ListBox.c   
	
${OBJECTDIR}/_ext/803622919/Meter.o: ../../../Microchip/Graphics/Meter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Meter.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Meter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Meter.o.d" -o ${OBJECTDIR}/_ext/803622919/Meter.o ../../../Microchip/Graphics/Meter.c   
	
${OBJECTDIR}/_ext/803622919/Palette.o: ../../../Microchip/Graphics/Palette.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Palette.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Palette.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Palette.o.d" -o ${OBJECTDIR}/_ext/803622919/Palette.o ../../../Microchip/Graphics/Palette.c   
	
${OBJECTDIR}/_ext/803622919/Picture.o: ../../../Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Picture.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Picture.o.d" -o ${OBJECTDIR}/_ext/803622919/Picture.o ../../../Microchip/Graphics/Picture.c   
	
${OBJECTDIR}/_ext/803622919/Primitive.o: ../../../Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Primitive.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Primitive.o.d" -o ${OBJECTDIR}/_ext/803622919/Primitive.o ../../../Microchip/Graphics/Primitive.c   
	
${OBJECTDIR}/_ext/803622919/ProgressBar.o: ../../../Microchip/Graphics/ProgressBar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/ProgressBar.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/ProgressBar.o.d" -o ${OBJECTDIR}/_ext/803622919/ProgressBar.o ../../../Microchip/Graphics/ProgressBar.c   
	
${OBJECTDIR}/_ext/803622919/RadioButton.o: ../../../Microchip/Graphics/RadioButton.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/RadioButton.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/RadioButton.o.d" -o ${OBJECTDIR}/_ext/803622919/RadioButton.o ../../../Microchip/Graphics/RadioButton.c   
	
${OBJECTDIR}/_ext/803622919/RoundDial.o: ../../../Microchip/Graphics/RoundDial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/RoundDial.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/RoundDial.o.d" -o ${OBJECTDIR}/_ext/803622919/RoundDial.o ../../../Microchip/Graphics/RoundDial.c   
	
${OBJECTDIR}/_ext/803622919/Slider.o: ../../../Microchip/Graphics/Slider.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Slider.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Slider.o.d" -o ${OBJECTDIR}/_ext/803622919/Slider.o ../../../Microchip/Graphics/Slider.c   
	
${OBJECTDIR}/_ext/803622919/StaticText.o: ../../../Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/StaticText.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/StaticText.o.d" -o ${OBJECTDIR}/_ext/803622919/StaticText.o ../../../Microchip/Graphics/StaticText.c   
	
${OBJECTDIR}/_ext/803622919/TextEntry.o: ../../../Microchip/Graphics/TextEntry.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/TextEntry.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/TextEntry.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/TextEntry.o.d" -o ${OBJECTDIR}/_ext/803622919/TextEntry.o ../../../Microchip/Graphics/TextEntry.c   
	
${OBJECTDIR}/_ext/803622919/Window.o: ../../../Microchip/Graphics/Window.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Window.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Window.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/803622919/Window.o.d" -o ${OBJECTDIR}/_ext/803622919/Window.o ../../../Microchip/Graphics/Window.c   
	
${OBJECTDIR}/_ext/1472/CustomControlDemo.o: ../CustomControlDemo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/CustomControlDemo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/CustomControlDemo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/CustomControlDemo.o.d" -o ${OBJECTDIR}/_ext/1472/CustomControlDemo.o ../CustomControlDemo.c   
	
${OBJECTDIR}/_ext/1472/InternalResourceXC32.o: ../InternalResourceXC32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/InternalResourceXC32.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/InternalResourceXC32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/InternalResourceXC32.o.d" -o ${OBJECTDIR}/_ext/1472/InternalResourceXC32.o ../InternalResourceXC32.c   
	
${OBJECTDIR}/_ext/1472/rtcc.o: ../rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/rtcc.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/rtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/rtcc.o.d" -o ${OBJECTDIR}/_ext/1472/rtcc.o ../rtcc.c   
	
${OBJECTDIR}/_ext/1472/SideButtons.o: ../SideButtons.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/SideButtons.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/SideButtons.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/SideButtons.o.d" -o ${OBJECTDIR}/_ext/1472/SideButtons.o ../SideButtons.c   
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d" -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c   
	
${OBJECTDIR}/_ext/1472/StringConversion.o: ../StringConversion.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/StringConversion.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/StringConversion.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -DCFG_INCLUDE_MPLAB_X -DCFG_INCLUDE_MIKROMEDIA_PIC32 -I"../" -I"../../../Board Support Package" -I"../../../Microchip/Include" -MMD -MF "${OBJECTDIR}/_ext/1472/StringConversion.o.d" -o ${OBJECTDIR}/_ext/1472/StringConversion.o ../StringConversion.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,--defsym=_min_heap_size=3000
else
dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}         -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=3000
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MedDispenser.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/MIKROMEDIA_PIC32
	${RM} -r dist/MIKROMEDIA_PIC32

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
