################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src_device/28335_II_DMA.c \
../src_device/28335_II_DefaultIsr.c \
../src_device/28335_II_GlobalVariableDefs.c \
../src_device/28335_II_Gpio.c \
../src_device/28335_II_PieCtrl.c \
../src_device/28335_II_PieVect.c \
../src_device/28335_II_SysCtrl.c \
../src_device/28335_II_Xintf.c 

ASM_SRCS += \
../src_device/28335_II_usDelay.asm 

ASM_DEPS += \
./src_device/28335_II_usDelay.pp 

OBJS += \
./src_device/28335_II_DMA.obj \
./src_device/28335_II_DefaultIsr.obj \
./src_device/28335_II_GlobalVariableDefs.obj \
./src_device/28335_II_Gpio.obj \
./src_device/28335_II_PieCtrl.obj \
./src_device/28335_II_PieVect.obj \
./src_device/28335_II_SysCtrl.obj \
./src_device/28335_II_Xintf.obj \
./src_device/28335_II_usDelay.obj 

C_DEPS += \
./src_device/28335_II_DMA.pp \
./src_device/28335_II_DefaultIsr.pp \
./src_device/28335_II_GlobalVariableDefs.pp \
./src_device/28335_II_Gpio.pp \
./src_device/28335_II_PieCtrl.pp \
./src_device/28335_II_PieVect.pp \
./src_device/28335_II_SysCtrl.pp \
./src_device/28335_II_Xintf.pp 

OBJS__QTD += \
".\src_device\28335_II_DMA.obj" \
".\src_device\28335_II_DefaultIsr.obj" \
".\src_device\28335_II_GlobalVariableDefs.obj" \
".\src_device\28335_II_Gpio.obj" \
".\src_device\28335_II_PieCtrl.obj" \
".\src_device\28335_II_PieVect.obj" \
".\src_device\28335_II_SysCtrl.obj" \
".\src_device\28335_II_Xintf.obj" \
".\src_device\28335_II_usDelay.obj" 

ASM_DEPS__QTD += \
".\src_device\28335_II_usDelay.pp" 

C_DEPS__QTD += \
".\src_device\28335_II_DMA.pp" \
".\src_device\28335_II_DefaultIsr.pp" \
".\src_device\28335_II_GlobalVariableDefs.pp" \
".\src_device\28335_II_Gpio.pp" \
".\src_device\28335_II_PieCtrl.pp" \
".\src_device\28335_II_PieVect.pp" \
".\src_device\28335_II_SysCtrl.pp" \
".\src_device\28335_II_Xintf.pp" 

C_SRCS_QUOTED += \
"../src_device/28335_II_DMA.c" \
"../src_device/28335_II_DefaultIsr.c" \
"../src_device/28335_II_GlobalVariableDefs.c" \
"../src_device/28335_II_Gpio.c" \
"../src_device/28335_II_PieCtrl.c" \
"../src_device/28335_II_PieVect.c" \
"../src_device/28335_II_SysCtrl.c" \
"../src_device/28335_II_Xintf.c" 

ASM_SRCS_QUOTED += \
"../src_device/28335_II_usDelay.asm" 


# Each subdirectory must supply rules for building sources it contributes
src_device/28335_II_DMA.obj: ../src_device/28335_II_DMA.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_DMA.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_DefaultIsr.obj: ../src_device/28335_II_DefaultIsr.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_DefaultIsr.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_GlobalVariableDefs.obj: ../src_device/28335_II_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_GlobalVariableDefs.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_Gpio.obj: ../src_device/28335_II_Gpio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_Gpio.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_PieCtrl.obj: ../src_device/28335_II_PieCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_PieCtrl.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_PieVect.obj: ../src_device/28335_II_PieVect.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_PieVect.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_SysCtrl.obj: ../src_device/28335_II_SysCtrl.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_SysCtrl.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_Xintf.obj: ../src_device/28335_II_Xintf.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_Xintf.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src_device/28335_II_usDelay.obj: ../src_device/28335_II_usDelay.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_device/28335_II_usDelay.pp" --obj_directory="src_device" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


