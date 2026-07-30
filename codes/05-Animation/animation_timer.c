#include <GL/gl.h>
#include <GL/glut.h>

float p = -8;
float speed = 0.1;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.25, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(p, 2);
    glVertex2f(p + 4, 2);
    glVertex2f(p + 4, -2);
    glVertex2f(p, -2);
    glEnd();
    glutSwapBuffers();
}

void update()
{
    p = p + speed;
    if (p >= 6 || p <= -10) speed = -speed;
    glutPostRedisplay();
}

void myTimer(int val)
{
    update();
    glutTimerFunc(100, myTimer, 0);
}

void init(void) { glClearColor(0,0,0,0); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-10,10,-10,10,-100,1); }

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Animation Timer");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(100, myTimer, 0);
    glutMainLoop();
    return 0;
}
