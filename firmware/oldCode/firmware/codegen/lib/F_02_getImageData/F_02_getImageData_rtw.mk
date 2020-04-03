###########################################################################
## Makefile generated for MATLAB file/project 'F_02_getImageData'. 
## 
## Makefile     : F_02_getImageData_rtw.mk
## Generated on : Tue Feb 04 11:06:51 2020
## MATLAB Coder version: 4.3 (R2019b)
## 
## Build Info:
## 
## Final product: ./F_02_getImageData.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = F_02_getImageData
MAKEFILE                  = F_02_getImageData_rtw.mk
MATLAB_ROOT               = /usr/local/MATLAB/R2019b
MATLAB_BIN                = /usr/local/MATLAB/R2019b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/glnxa64
MASTER_ANCHOR_DIR         = 
START_DIR                 = /media/teamlary/Team_Lary_1/gitGubRepos/Lakitha/stereoVisionMatlab/firmware/codegen/lib/F_02_getImageData
TGT_FCN_LIB               = ISO_C++
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
C_STANDARD_OPTS           = -fwrapv -ansi -pedantic -Wno-long-long
CPP_STANDARD_OPTS         = -fwrapv -std=c++03 -pedantic -Wno-long-long
MODELLIB                  = F_02_getImageData.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          GNU gcc/g++ | gmake (64-bit Linux)
# Supported Version(s):    
# ToolchainInfo Version:   2019b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS         = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX     = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS     = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC = gcc

# Linker: GNU Linker
LD = g++

# C++ Compiler: GNU C++ Compiler
CPP = g++

# C++ Linker: GNU C++ Linker
CPP_LD = g++

# Archiver: GNU Archiver
AR = ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/glnxa64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(C_STANDARD_OPTS) -fPIC \
                       -O0
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -fPIC \
                       -O0
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./F_02_getImageData.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I/media/teamlary/Team_Lary_1/gitGubRepos/Lakitha/stereoVisionMatlab/firmware -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=F_02_getImageData -DHAVESTDIO -DUSE_RTMODEL -DUNIX

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/rt_nonfinite.cpp $(START_DIR)/rtGetNaN.cpp $(START_DIR)/rtGetInf.cpp $(START_DIR)/F_02_getImageData_rtwutil.cpp $(START_DIR)/F_02_getImageData_data.cpp $(START_DIR)/F_02_getImageData_initialize.cpp $(START_DIR)/F_02_getImageData_terminate.cpp $(START_DIR)/F_02_getImageData.cpp $(START_DIR)/StereoParametersImpl.cpp $(START_DIR)/colon.cpp $(START_DIR)/xswap.cpp $(START_DIR)/ImageTransformer.cpp $(START_DIR)/CameraParametersImpl.cpp $(START_DIR)/imread.cpp $(START_DIR)/undistortImage.cpp $(START_DIR)/meshgrid.cpp $(START_DIR)/distortPoints.cpp $(START_DIR)/interp2d.cpp $(START_DIR)/rectifyStereoImages.cpp $(START_DIR)/svd.cpp $(START_DIR)/xnrm2.cpp $(START_DIR)/xdotc.cpp $(START_DIR)/xaxpy.cpp $(START_DIR)/xrotg.cpp $(START_DIR)/xrot.cpp $(START_DIR)/rodriguesVectorToMatrix.cpp $(START_DIR)/bwtraceboundary.cpp $(START_DIR)/sort.cpp $(START_DIR)/sortIdx.cpp $(START_DIR)/regionprops.cpp $(START_DIR)/bwconncomp.cpp $(START_DIR)/inv.cpp $(START_DIR)/rgb2gray.cpp $(START_DIR)/disparitySGM.cpp $(START_DIR)/reconstructScene.cpp $(START_DIR)/imwarp.cpp $(START_DIR)/F_02_getImageData_emxutil.cpp $(START_DIR)/F_02_getImageData_emxAPI.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rt_nonfinite.o rtGetNaN.o rtGetInf.o F_02_getImageData_rtwutil.o F_02_getImageData_data.o F_02_getImageData_initialize.o F_02_getImageData_terminate.o F_02_getImageData.o StereoParametersImpl.o colon.o xswap.o ImageTransformer.o CameraParametersImpl.o imread.o undistortImage.o meshgrid.o distortPoints.o interp2d.o rectifyStereoImages.o svd.o xnrm2.o xdotc.o xaxpy.o xrotg.o xrot.o rodriguesVectorToMatrix.o bwtraceboundary.o sort.o sortIdx.o regionprops.o bwconncomp.o inv.o rgb2gray.o disparitySGM.o reconstructScene.o imwarp.o F_02_getImageData_emxutil.o F_02_getImageData_emxAPI.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(MATLAB_ROOT)/bin/glnxa64/libmwjpegreader.so $(MATLAB_ROOT)/bin/glnxa64/libmwdisparitySGM.so

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -L"$(MATLAB_ROOT)/bin/glnxa64" -lmwimterp2d -lmwippreconstruct -lmwipp -lmwbwlookup_tbb -lmwrgb2gray_tbb -lm -lstdc++

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : /media/teamlary/Team_Lary_1/gitGubRepos/Lakitha/stereoVisionMatlab/firmware/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /media/teamlary/Team_Lary_1/gitGubRepos/Lakitha/stereoVisionMatlab/firmware/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


F_02_getImageData_rtwutil.o : $(START_DIR)/F_02_getImageData_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


F_02_getImageData_data.o : $(START_DIR)/F_02_getImageData_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


F_02_getImageData_initialize.o : $(START_DIR)/F_02_getImageData_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


F_02_getImageData_terminate.o : $(START_DIR)/F_02_getImageData_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


F_02_getImageData.o : $(START_DIR)/F_02_getImageData.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


StereoParametersImpl.o : $(START_DIR)/StereoParametersImpl.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


colon.o : $(START_DIR)/colon.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xswap.o : $(START_DIR)/xswap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ImageTransformer.o : $(START_DIR)/ImageTransformer.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


CameraParametersImpl.o : $(START_DIR)/CameraParametersImpl.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imread.o : $(START_DIR)/imread.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


undistortImage.o : $(START_DIR)/undistortImage.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


meshgrid.o : $(START_DIR)/meshgrid.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


distortPoints.o : $(START_DIR)/distortPoints.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


interp2d.o : $(START_DIR)/interp2d.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rectifyStereoImages.o : $(START_DIR)/rectifyStereoImages.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


svd.o : $(START_DIR)/svd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.o : $(START_DIR)/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xdotc.o : $(START_DIR)/xdotc.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xaxpy.o : $(START_DIR)/xaxpy.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.o : $(START_DIR)/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrot.o : $(START_DIR)/xrot.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rodriguesVectorToMatrix.o : $(START_DIR)/rodriguesVectorToMatrix.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bwtraceboundary.o : $(START_DIR)/bwtraceboundary.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sort.o : $(START_DIR)/sort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


sortIdx.o : $(START_DIR)/sortIdx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


regionprops.o : $(START_DIR)/regionprops.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


bwconncomp.o : $(START_DIR)/bwconncomp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


inv.o : $(START_DIR)/inv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rgb2gray.o : $(START_DIR)/rgb2gray.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


disparitySGM.o : $(START_DIR)/disparitySGM.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


reconstructScene.o : $(START_DIR)/reconstructScene.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


imwarp.o : $(START_DIR)/imwarp.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


F_02_getImageData_emxutil.o : $(START_DIR)/F_02_getImageData_emxutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


F_02_getImageData_emxAPI.o : $(START_DIR)/F_02_getImageData_emxAPI.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


