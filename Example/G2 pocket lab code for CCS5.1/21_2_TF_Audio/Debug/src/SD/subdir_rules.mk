################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/SD/SD_HardWare.obj: ../src/SD/SD_HardWare.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/CCS5.5/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=coffabi -g --include_path="D:/CCS5.5/ccsv5/ccs_base/msp430/include" --include_path="C:/Users/shan/Desktop/G2 pocket lab code for CCS5.1/21_2_TF_Audio/src" --include_path="C:/Users/shan/Desktop/G2 pocket lab code for CCS5.1/21_2_TF_Audio/src/SD" --include_path="D:/CCS5.5/ccsv5/tools/compiler/msp430_4.2.1/include" --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="src/SD/SD_HardWare.pp" --obj_directory="src/SD" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SD/SD_SPI.obj: ../src/SD/SD_SPI.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/CCS5.5/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=coffabi -g --include_path="D:/CCS5.5/ccsv5/ccs_base/msp430/include" --include_path="C:/Users/shan/Desktop/G2 pocket lab code for CCS5.1/21_2_TF_Audio/src" --include_path="C:/Users/shan/Desktop/G2 pocket lab code for CCS5.1/21_2_TF_Audio/src/SD" --include_path="D:/CCS5.5/ccsv5/tools/compiler/msp430_4.2.1/include" --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="src/SD/SD_SPI.pp" --obj_directory="src/SD" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SD/SPI.obj: ../src/SD/SPI.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/CCS5.5/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmsp --abi=coffabi -g --include_path="D:/CCS5.5/ccsv5/ccs_base/msp430/include" --include_path="C:/Users/shan/Desktop/G2 pocket lab code for CCS5.1/21_2_TF_Audio/src" --include_path="C:/Users/shan/Desktop/G2 pocket lab code for CCS5.1/21_2_TF_Audio/src/SD" --include_path="D:/CCS5.5/ccsv5/tools/compiler/msp430_4.2.1/include" --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="src/SD/SPI.pp" --obj_directory="src/SD" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


