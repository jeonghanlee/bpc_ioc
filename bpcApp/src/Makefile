TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = BPC
# BPC.dbd will be created and installed
DBD += BPC.dbd

# BPC.dbd will be made up from these files:
BPC_DBD += base.dbd

# Include dbd files from all support applications:
#BPC_DBD += xxx.dbd
BPC_DBD += BPCsubs.dbd

# Add all the support libraries needed by this IOC
#BPC_LIBS += xxx

# BPC_registerRecordDeviceDriver.cpp derives from BPC.dbd
BPC_SRCS += BPC_registerRecordDeviceDriver.cpp
BPC_SRCS += StatSub.c
BPC_SRCS += DecodeSub1.c
BPC_SRCS += DecodeSub2.c
BPC_SRCS += Tester.c
BPC_SRCS += Tester2.c

# Build the main IOC entry point on workstation OSs.
BPC_SRCS_DEFAULT += BPCMain.cpp
BPC_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#BPC_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
BPC_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

