################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
mcal/nvic/%.obj: ../mcal/nvic/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="F:/Sprints/workplace_ccs/Project1" --include_path="F:/Sprints/workplace_ccs/Project1/utils" --include_path="F:/Sprints/workplace_ccs/Project1/mcal" --include_path="F:/Sprints/workplace_ccs/Project1/config" --include_path="F:/Sprints/workplace_ccs/Project1/appl" --include_path="C:/ti/ccs930/ccs/tools/compiler/ti-cgt-arm_18.12.4.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="mcal/nvic/$(basename $(<F)).d_raw" --obj_directory="mcal/nvic" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

