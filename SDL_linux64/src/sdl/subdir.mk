################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sdl/cfg_file.c \
../src/sdl/gfx.c \
../src/sdl/opengl.c \
../src/sdl/snd.c \
../src/sdl/text.c 

OBJS += \
./src/sdl/cfg_file.o \
./src/sdl/gfx.o \
./src/sdl/opengl.o \
./src/sdl/snd.o \
./src/sdl/text.o 

C_DEPS += \
./src/sdl/cfg_file.d \
./src/sdl/gfx.d \
./src/sdl/opengl.d \
./src/sdl/snd.d \
./src/sdl/text.d 


# Each subdirectory must supply rules for building sources it contributes
src/sdl/%.o: ../src/sdl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	x86_64-glibc2.12.2-linux-gnu-gcc -DGTK -DSDL -DGLEW_STATIC -I../src -I../src/sdl -I/usr/x86_64-glibc2.12.2-linux-gnu/usr/include/SDL -O3 -Wall -ffast-math -msse2 -mfpmath=sse -c -fmessage-length=0 -finline-functions -Winline `x86_64-glibc2.12.2-linux-gnu-pkg-config --cflags gtk+-2.0` -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


