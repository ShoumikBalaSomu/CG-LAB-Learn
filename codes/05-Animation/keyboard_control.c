#include <GL/gl.h>
#include <GL/glut.h>

float px = -8, py = 2, speed = 1.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.25, 0.25, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(px, py);
    glVertex2f(px + 4, py);
    glVertex2f(px + 4, py - 4);
    glVertex2f(px, py - 4);
    glEnd();
    glutSwapBuffers();
}

void myKeyboardControl(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_RIGHT: px += speed; glutPostRedisplay(); break;
    case GLUT_KEY_LEFT: px -= speed; glutPostRedisplay(); break;
    case GLUT_KEY_UP: py += speed; glutPostRedisplay(); break;
    case GLUT_KEY_DOWN: py -= speed; glutPostRedisplay(); break;
    }
}

void init(void) { glClearColor(0,0,0,0); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-10,10,-10,10,-100,1); }

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Keyboard Control");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(myKeyboardControl);
    glutMainLoop();
    return 0;
}
