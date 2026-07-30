#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void Bresenham(float x1, float y1, float x2, float y2)
{
    float dx = fabs(x2 - x1);
    float dy = fabs(y2 - y1);
    float p = 2 * dy - dx;
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    glVertex2f(x1, y1);
    while (x1 < x2)
    {
        x1++;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            y1++;
            p = p + 2 * dy - 2 * dx;
        }
        glVertex2f(x1, y1);
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Bresenham(120, 100, 260, 200);
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
    glutCreateWindow("Bresenham Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
