#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void DDA(float x1, float y1, float x2, float y2)
{
    float dx = fabs(x2 - x1);
    float dy = fabs(y2 - y1);
    float steps = fmax(dx, dy);
    float x_inc = (x2 - x1) / steps;
    float y_inc = (y2 - y1) / steps;
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(round(x1), round(y1));
        x1 += x_inc; y1 += y_inc;
    }
    glEnd();
}

void Bresenham(float x1, float y1, float x2, float y2)
{
    float dx = fabs(x2 - x1);
    float dy = fabs(y2 - y1);
    float p = 2 * dy - dx;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    while (x1 <= x2)
    {
        x1++;
        if (p < 0) p = p + 2 * dy;
        else { p = p + 2 * dy - 2 * dx; y1++; }
        glVertex2f(x1, y1);
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    DDA(100, 100, 200, 200);
    Bresenham(140, 140, 260, 240);
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 300.0, 0.0, 300.0, -100.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA + Bresenham");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
