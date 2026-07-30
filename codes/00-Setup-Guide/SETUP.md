# OpenGL Setup Guide (Windows - MSYS2/MinGW)

## Step 1: Install MSYS2
Download and install from: https://www.msys2.org/

## Step 2: Install GCC and FreeGLUT
Open MSYS2 terminal and run:

    pacman -S mingw-w64-x86_64-gcc
    pacman -S mingw-w64-x86_64-freeglut

## Step 3: Add to PATH
Add this to your system PATH:

    C:\msys64\mingw64\bin

## Step 4: Verify Installation

    gcc --version
    ls /mingw64/lib | grep glut

## Step 5: Compile and Run

    gcc main.c -o app -lfreeglut -lopengl32 -lglu32
    ./app

## Troubleshooting
- If "glut.h not found": Make sure freeglut is installed
- If "cannot find -lfreeglut": Check PATH includes mingw64/bin
- If window doesn't open: Make sure you have a display/GPU driver
