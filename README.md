# CG-LAB-Learn

> Computer Graphics Laboratory - Complete Practice Guide for Students

A comprehensive learning resource for Computer Graphics lab practice using **OpenGL** and **C Programming**.

## Topics Covered

| # | Topic | Description |
|---|-------|-------------|
| 1 | **DDA Algorithm** | Digital Differential Analyzer line drawing |
| 2 | **Bresenham Algorithm** | Integer-based line drawing (all quadrants) |
| 3 | **Mid Point Algorithm** | Circle and ellipse drawing |
| 4 | **2D Transformation** | Translation, Rotation, Scaling |
| 5 | **Animation** | Timer-based and keyboard-controlled |
| 6 | **Shapes & 3D** | Polygons, 3D room, first-person navigation |

## Quick Start

### Prerequisites (Windows)

    pacman -S mingw-w64-x86_64-gcc
    pacman -S mingw-w64-x86_64-freeglut

### Add to PATH

    C:\\msys64\\mingw64\\bin

### Compile & Run

    gcc main.c -o app -lfreeglut -lopengl32 -lglu32
    ./app

## Project Structure

    CG-LAB-Learn/
    |-- index.html
    |-- LICENSE
    |-- README.md
    |-- codes/
        |-- 00-Setup-Guide/
        |-- 01-DDA/
        |-- 02-Bresenham/
        |-- 03-MidPoint/
        |-- 04-2D-Transformation/
        |-- 05-Animation/
        |-- 06-Shapes-3D/

## GitHub Pages

Visit: **https://shoumikbalasomu.github.io/CG-LAB-Learn/**

## Author

**Shoumik Bala Somu** - [GitHub](https://github.com/ShoumikBalaSomu)

## License

MIT License - see [LICENSE](LICENSE)

## Institution

Daffodil International University (DIU)
