################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/DAC8411.obj: ../src/DAC8411.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=coffabi --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS5.5/21_2_TF_Audio/src" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS5.5/21_2_TF_Audio/src/SD" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.2.1/include" -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="src/DAC8411.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/softFIFO.obj: ../src/softFIFO.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=coffabi --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS5.5/21_2_TF_Audio/src" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS5.5/21_2_TF_Audio/src/SD" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.2.1/include" -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="src/softFIFO.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


