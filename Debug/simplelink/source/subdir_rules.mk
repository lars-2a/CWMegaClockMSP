################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
simplelink/source/device.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/device.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/device.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/driver.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/driver.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/driver.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/flowcont.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/flowcont.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/flowcont.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/fs.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/fs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/fs.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/netapp.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/netapp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/netapp.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/netcfg.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/netcfg.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/netcfg.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/nonos.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/nonos.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/nonos.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/socket.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/socket.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/socket.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/spawn.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/spawn.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/spawn.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

simplelink/source/wlan.obj: /home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source/wlan.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="/home/lars/ti/ccsv6/ccs_base/msp430/include" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/platform/msp430fr5969lp" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/source" --include_path="/home/lars/ti/workspace_v6_1/cc3100-sdk/simplelink/include" --include_path="/home/lars/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.5/include" --advice:power=all --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_USE_CLI_ --define=__CCS__ --define=_MPU_ENABLE --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="simplelink/source/wlan.pp" --obj_directory="simplelink/source" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


