#******************************************************************************
#
# Makefile - Rules for building the SimpliciTI End Device for AP As Data Hub example.
#
# Copyright (c) 2010-2012 Texas Instruments Incorporated.  All rights reserved.
# Software License Agreement
# 
# Texas Instruments (TI) is supplying this software for use solely and
# exclusively on TI's microcontroller products. The software is owned by
# TI and/or its suppliers, and is protected under applicable copyright
# laws. You may not combine this software with "viral" open-source
# software in order to form a larger program.
# 
# THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
# NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
# NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
# CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
# DAMAGES, FOR ANY REASON WHATSOEVER.
# 
# This is part of revision 9107 of the DK-LM3S9D96-EM2-CC2500-SIMPLICITI Firmware Package.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=LM4F120H5QR
CC=arm-none-eabi-gcc
#
# Set the processor variant.
#
VARIANT=cm4f

#
# The base directory for StellarisWare.
#
ROOT=${HOME}/arm/stellarisware

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=../../SimpliciTI-1.1.1
VPATH+=${ROOT}/boards/ek-lm4f120xl/drivers
VPATH+=${ROOT}/utils

#
# Where to find header files that do not live in the source directory.
#
IPATH=.
IPATH+=${ROOT}
IPATH+=../../SimpliciTI-1.1.1
IPATH+=../../SimpliciTI-1.1.1/Components/bsp
IPATH+=../../SimpliciTI-1.1.1/Components/bsp/boards/stellaris_launchpad
#IPATH+=../../dk-lm3s9d96
IPATH+=../../SimpliciTI-1.1.1/Components/bsp/drivers
IPATH+=../../SimpliciTI-1.1.1/Components/mrfi
IPATH+=../../SimpliciTI-1.1.1/Components/simpliciti/nwk
IPATH+=../../SimpliciTI-1.1.1/Components/simpliciti/nwk_applications

#
# The default rule, which causes the SimpliciTI End Device for AP As Data Hub example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/simpliciti_hub_dev.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER} ${wildcard *~}

#
# The rule to create the target directory.
#
${COMPILER}:
	@mkdir -p ${COMPILER}

#
# Rules for building the SimpliciTI End Device for AP As Data Hub example.
#
${COMPILER}/simpliciti_hub_dev.axf: ${COMPILER}/simpliciti_hub_dev.o
${COMPILER}/simpliciti_hub_dev.axf: ${COMPILER}/simplicitilib.o
${COMPILER}/simpliciti_hub_dev.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/simpliciti_hub_dev.axf: ${COMPILER}/uartstdio.o
${COMPILER}/simpliciti_hub_dev.axf: ${COMPILER}/ustdlib.o
${COMPILER}/simpliciti_hub_dev.axf: ${ROOT}/driverlib/${COMPILER}-cm4f/libdriver-cm4f.a
${COMPILER}/simpliciti_hub_dev.axf: simpliciti_hub_dev.ld
SCATTERgcc_simpliciti_hub_dev=simpliciti_hub_dev.ld
ENTRY_simpliciti_hub_dev=ResetISR
CFLAGSgcc=-DTARGET_IS_FIRESTORM_RA2 -DSIMPLICITI_CONFIG_HEADER

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
