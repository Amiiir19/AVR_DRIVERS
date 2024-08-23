# Specify the minimum version of CMake required for this project
cmake_minimum_required(VERSION 3.28)
# Set the project name and the languages supported (C and ASM)
project(AVR_Project_Amir C ASM)

# Set the path to the AVR toolchain (update this to your specific toolchain location)
set(AVR_TOOLCHAIN_PATH /usr/lib ) 


# Specify the AVR cross compiler

#Set the that this is cross compiled to different values
#set(CMAKE_SYSTEM_NAME Generic)

#set the processor we cross compile for
set(CMAKE_SYSTEM_PROCESSOR avr)

# Specify the C and C++ compilers for the AVR architecture
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)

################################################################
# Define the MCU type and F_CPU
set(MCU atmega32)
set(F_CPU 16000000UL)

###############################################################

# Define the compiler and linker flags for building the project
set(CMAKE_C_FLAGS "-Os -DF_CPU=${F_CPU} -mmcu=${MCU}")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")


# Include directories to be searched during the build process
include_directories(
    ${AVR_TOOLCHAIN_PATH}/avr/include/avr

    ${PROJECT_SOURCE_DIR}/APP
    ${PROJECT_SOURCE_DIR}/LIB_DRIVERS

    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/ADC
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/GPIO
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/PWM
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/ICU
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/I2C
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/EXTI
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/SPI
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/UART
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/TIMER
    ${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/WDT

    ${PROJECT_SOURCE_DIR}/HAL_DRIVERS/DC_MOTOR
    ${PROJECT_SOURCE_DIR}/HAL_DRIVERS/LCD
    ${PROJECT_SOURCE_DIR}/HAL_DRIVERS/SENSOR
    ${PROJECT_SOURCE_DIR}/HAL_DRIVERS/ULTRASONIC
    ${PROJECT_SOURCE_DIR}/HAL_DRIVERS/KEYPAD
    ${PROJECT_SOURCE_DIR}/HAL_DRIVERS/EEPROM
    ${PROJECT_SOURCE_DIR}/HAL_DRIVERS/BUZZER

    
)
##########################################################################

# Define source files
# set(SOURCES)

# # Function to add source file if it exists
# function(add_source_file source_file)
#     if(EXISTS ${source_file})
#         list(APPEND SOURCES ${source_file})
#     else()
#         message(WARNING "Source file ${source_file} not found and will be skipped.")
#     endif()
# endfunction()

# # Add sources conditionally
# add_source_file(${PROJECT_SOURCE_DIR}/src/main.c)
# add_source_file(${PROJECT_SOURCE_DIR}/APP/app.c)

# add_source_file(${PROJECT_SOURCE_DIR}/HAL_DRIVERS/DC_MOTOR/dcmotor.c)
# add_source_file(${PROJECT_SOURCE_DIR}/HAL_DRIVERS/LCD/lcd.c)
# add_source_file(${PROJECT_SOURCE_DIR}/HAL_DRIVERS/SENSOR/sensor.c)
# add_source_file(${PROJECT_SOURCE_DIR}/HAL_DRIVERS/ULTRASONIC/ultrasonic.c)
# add_source_file(${PROJECT_SOURCE_DIR}/HAL_DRIVERS/KEYPAD/keypad.c)
# add_source_file(${PROJECT_SOURCE_DIR}/HAL_DRIVERS/EEPROM/eeprom.c)
# add_source_file(${PROJECT_SOURCE_DIR}/HAL_DRIVERS/BUZZER/buzzer.c)

# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/ADC/adc.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/EXIT/exti.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/GPIO/gpio.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/PWM/pwm.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/UART/uart.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/SPI/spi.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/I2C/i2c.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/TIMER/timer.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/WDT/wdt.c)
# add_source_file(${PROJECT_SOURCE_DIR}/MCAL_DRIVERS/ICU/icu.c)


# # Define source files to compile 
# set(SOURCES
#     src/main.c
#     APP/app.c
#     HAL_DRIVERS/DC_MOTOR/dcmotor.c
#     HAL_DRIVERS/LCD/lcd.c
#     HAL_DRIVERS/SENSOR/sensor.c
#     HAL_DRIVERS/BUZZER/buzzer.c
#     HAL_DRIVERS/EEPROM/eeprom.c
#     HAL_DRIVERS/KEYPAD/sensor.c
#     HAL_DRIVERS/ULTRASONIC/ultrasonic.c

#     MCAL_DRIVERS/ADC/adc.c
#     MCAL_DRIVERS/GPIO/gpio.c
#     MCAL_DRIVERS/PWM/pwm.c
#     MCAL_DRIVERS/EXTI/exti.c
#     MCAL_DRIVERS/I2C/i2c.c
#     MCAL_DRIVERS/ICU/icu.c
#     MCAL_DRIVERS/SPI/spi.c
#     MCAL_DRIVERS/TIMER/timer.c
#     MCAL_DRIVERS/UART/uart.c
#     MCAL_DRIVERS/WDT/wdt.c
# )
##################################################################################



#Moatasem Video

# Use GLOB_RECURSE to collect all source files (C and header files) in the project directory
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c *.h)

# Exclude any files in the 'build' directory from the SOURCES list
string(REGEX REPLACE "build/[^;]+;?" "" SOURCES "${SOURCES}")


# Create the main executable from the collected source files
# Check if SOURCES list is not empty before creating the executable

if(SOURCES)
        # Add executable target
	add_executable(${PROJECT_NAME}.elf ${SOURCES})

    
	#add_executable(${PROJECT_NAME}.elf ${SOURCES})

	################################################################################
	    # Add a custom target to generate a hex file from the executable using avr-objcopy
	add_custom_target(${PROJECT_NAME}.hex ALL	
   	 DEPENDS ${PROJECT_NAME}.elf
   	 COMMAND avr-objcopy -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
	)
	###################################################################################
	    # Add a custom target to flash the MCU using avrdude
	add_custom_target(flash
    	COMMAND avrdude -v -p m32 -c usbasp  -b 115200 -U flash:w:${PROJECT_NAME}.hex:i
	)
else()
    # Display an error message if no source files are found
    message(FATAL_ERROR "No source files found. Please check the paths and ensure the source files exist.")
endif()

