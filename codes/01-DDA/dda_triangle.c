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
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(round(x), round(y));
        x += x_inc;
        y += y_inc;
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    DDA(50.0f, 50.0f, 250.0f, 50.0f);
    DDA(250.0f, 50.0f, 150.0f, 250.0f);
    DDA(150.0f, 250.0f, 50.0f, 50.0f);
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
    glutCreateWindow("DDA Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
