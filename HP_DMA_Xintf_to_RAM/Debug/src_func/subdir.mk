################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src_func/DMA_Xintf_to_RAM.c 

OBJS += \
./src_func/DMA_Xintf_to_RAM.obj 

C_DEPS += \
./src_func/DMA_Xintf_to_RAM.pp 

OBJS__QTD += \
".\src_func\DMA_Xintf_to_RAM.obj" 

C_DEPS__QTD += \
".\src_func\DMA_Xintf_to_RAM.pp" 

C_SRCS_QUOTED += \
"../src_func/DMA_Xintf_to_RAM.c" 


# Each subdirectory must supply rules for building sources it contributes
src_func/DMA_Xintf_to_RAM.obj: ../src_func/DMA_Xintf_to_RAM.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/bin/cl2000" --silicon_version=28 -g --include_path="D:/CCS4.2/ccsv4/tools/compiler/C2000 Code Generation Tools 5.2.15/include" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_device" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_driver" --include_path="E:/CCSproj/Example_F28335_II/HP_DMA_Xintf_to_RAM/inc_func" --diag_warning=225 --large_memory_model --unified_memory --preproc_with_compile --preproc_dependency="src_func/DMA_Xintf_to_RAM.pp" --obj_directory="src_func" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


