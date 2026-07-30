#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void Bresenham_General(float x1, float y1, float x2, float y2)
{
    float dx = fabs(x2 - x1);
    float dy = fabs(y2 - y1);
    float p;
    float x_change = (x1 > x2) ? -1 : 1;
    float y_change = (y1 > y2) ? -1 : 1;
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    if (dx > dy)
    {
        p = 2 * dy - dx;
        while (1)
        {
            x1 = x1 + x_change;
            if (p < 0) p = p + 2 * dy;
            else { y1 = y1 + y_change; p = p + 2 * dy - 2 * dx; }
            glVertex2f(x1, y1);
            if (x1 == x2) break;
        }
    }
    else
    {
        p = 2 * dx - dy;
        while (1)
        {
            y1 = y1 + y_change;
            if (p < 0) p = p + 2 * dx;
            else { x1 = x1 + x_change; p = p + 2 * dx - 2 * dy; }
            glVertex2f(x1, y1);
            if (y1 == y2) break;
        }
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Bresenham_General(50, 50, 250, 150);
    Bresenham_General(250, 50, 50, 150);
    Bresenham_General(150, 50, 100, 250);
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
    glutCreateWindow("Bresenham General");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
