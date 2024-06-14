
#Cmake Minumum Version
cmake_minimum_required(VERSION 3.28)
#Set Project Name and the Language supported 
project(AVR_Project_Amir C ASM)


set(AVR_TOOLCHAIN_PATH /usr/lib ) # Update this path to the location of your AVR toolchain


# Specify the AVR cross compiler
#Set the that this is cross compiled to different values
#set(CMAKE_SYSTEM_NAME Generic)
#set the processor we cross compile for
set(CMAKE_SYSTEM_PROCESSOR avr)

#Set the compiler used For C & C++
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
################################################################
# Define the MCU type and F_CPU
set(MCU atmega32)
set(F_CPU 16000000UL)
###############################################################
# Define compiler and linker flags
set(CMAKE_C_FLAGS "-Os -DF_CPU=${F_CPU} -mmcu=${MCU}")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

# Include directories to include during the build.

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
##########################################################################3
# Define source files to compile 
set(SOURCES
    src/main.c
    APP/app.c
    HAL_DRIVERS/DC_MOTOR/dcmotor.c
    HAL_DRIVERS/LCD/lcd.c
    HAL_DRIVERS/SENSOR/sensor.c
    MCAL_DRIVERS/ADC/adc.c
    
    MCAL_DRIVERS/GPIO/gpio.c
    MCAL_DRIVERS/PWM/pwm.c
)
##################################################################################
# creates the main executable
add_executable(${PROJECT_NAME}.elf ${SOURCES})

################################################################################

# Add custom target to generate hex file using avr-objcopy command to generate the project
add_custom_target(${PROJECT_NAME}.hex ALL
    DEPENDS ${PROJECT_NAME}.elf
    COMMAND avr-objcopy -O ihex -R .eeprom ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
)
###################################################################################
# Add custom target to flash the MCU
add_custom_target(flash
    COMMAND avrdude -v -p m32 -c usbasp  -b 115200 -U flash:w:${PROJECT_NAME}.hex:i
)

