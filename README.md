# CG LAB Learn - Computer Graphics Lab Practice

> Computer Graphics Lab er sob code shekho - Bangla o English byakhya shoho!

A comprehensive learning platform for CG lab students with bilingual explanations (Bangla + English), fully commented code, and step-by-step theory.

## Live Website

https://shoumikbalasomu.github.io/CG-LAB-Learn/

## Topics Covered

1. DDA Line Drawing - Digital Differential Analyzer
2. Bresenham's Algorithm - Integer-only fast line drawing (General)
3. Midpoint Circle - Circle with 8-way symmetry
4. 2D Transformation - Translation, Rotation, Scaling
5. Animation - Timer-based bouncing animation
6. Shapes and 3D VR - 3D room with perspective camera

## Setup (Windows)

Install MSYS2 from https://www.msys2.org/

    pacman -S mingw-w64-x86_64-gcc
    pacman -S mingw-w64-x86_64-freeglut

Add to PATH: C:\msys64\mingw64\bin

Compile and Run:

    gcc main.c -o app -lfreeglut -lopengl32 -lglu32
    ./app

## Contributors

- Shoumik Bala Somu - Project Lead and Developer
- Abdullah Al Amin - Code Contributor
- Afrin Maharin Shama - 3D VR Room Code
- Nusrat Jahan Nishi - Animation and Transform Code

## License

MIT License - see LICENSE file

Made with love by DIU Students | 2026