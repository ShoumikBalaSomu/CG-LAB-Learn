#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void plotCirclePoints(int cx, int cy, int x, int y)
{
    glVertex2f(cx + x, cy + y);
    glVertex2f(cx - x, cy + y);
    glVertex2f(cx + x, cy - y);
    glVertex2f(cx - x, cy - y);
    glVertex2f(cx + y, cy + x);
    glVertex2f(cx - y, cy + x);
    glVertex2f(cx + y, cy - x);
    glVertex2f(cx - y, cy - x);
}

void MidPointCircle(int cx, int cy, int r)
{
    int x = 0, y = r;
    float p = 1 - r;
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POINTS);
    plotCirclePoints(cx, cy, x, y);
    while (x < y)
    {
        x++;
        if (p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
        plotCirclePoints(cx, cy, x, y);
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    MidPointCircle(150, 150, 80);
    MidPointCircle(150, 150, 40);
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
    glutCreateWindow("Mid Point Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
