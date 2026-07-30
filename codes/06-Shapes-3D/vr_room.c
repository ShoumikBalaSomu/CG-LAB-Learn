#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

float angle = 0.0;
float lx = 0.0, lz = -1.0;
float x = 0.0, z = 5.0;

void drawRoom()
{
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(-10, 0, -10); glVertex3f(-10, 0, 10);
    glVertex3f(10, 0, 10); glVertex3f(10, 0, -10);
    glEnd();

    glColor3f(0.8, 0.7, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(-10, 0, -10); glVertex3f(-10, 8, -10);
    glVertex3f(10, 8, -10); glVertex3f(10, 0, -10);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-10, 0, -10); glVertex3f(-10, 8, -10);
    glVertex3f(-10, 8, 10); glVertex3f(-10, 0, 10);
    glEnd();
}

void drawTable()
{
    glPushMatrix();
    glTranslatef(0, 1, -3);
    glColor3f(0.5, 0.2, 0.1);
    glPushMatrix(); glScalef(2, 0.2, 1); glutSolidCube(1); glPopMatrix();
    float leg[4][2] = {{0.8,0.4},{-0.8,0.4},{0.8,-0.4},{-0.8,-0.4}};
    for (int i = 0; i < 4; i++) {
        glPushMatrix();
        glTranslatef(leg[i][0], -0.6, leg[i][1]);
        glScalef(0.1, 1.2, 0.1);
        glutSolidCube(1);
        glPopMatrix();
    }
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(x, 2, z, x+lx, 2, z+lz, 0, 1, 0);
    drawRoom();
    drawTable();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    if (h == 0) h = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1.0*w/h, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int xx, int yy)
{
    float f = 0.3;
    switch (key) {
    case 'w': x += lx*f; z += lz*f; break;
    case 's': x -= lx*f; z -= lz*f; break;
    case 'a': angle -= 0.05; lx = sin(angle); lz = -cos(angle); break;
    case 'd': angle += 0.05; lx = sin(angle); lz = -cos(angle); break;
    case 27: exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Virtual Reality Room");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.8, 1.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
