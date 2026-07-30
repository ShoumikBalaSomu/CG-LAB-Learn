#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void plotEllipsePoints(int cx, int cy, int x, int y)
{
    glVertex2f(cx + x, cy + y);
    glVertex2f(cx - x, cy + y);
    glVertex2f(cx + x, cy - y);
    glVertex2f(cx - x, cy - y);
}

void MidPointEllipse(int cx, int cy, int rx, int ry)
{
    int x = 0, y = ry;
    float rx2 = rx * rx, ry2 = ry * ry;
    float p1 = ry2 - rx2 * ry + 0.25 * rx2;
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);
    plotEllipsePoints(cx, cy, x, y);
    while (2 * ry2 * x < 2 * rx2 * y)
    {
        x++;
        if (p1 < 0) p1 += 2 * ry2 * x + ry2;
        else { y--; p1 += 2 * ry2 * x - 2 * rx2 * y + ry2; }
        plotEllipsePoints(cx, cy, x, y);
    }
    float p2 = ry2*(x+0.5)*(x+0.5) + rx2*(y-1)*(y-1) - rx2*ry2;
    while (y > 0)
    {
        y--;
        if (p2 > 0) p2 -= 2 * rx2 * y + rx2;
        else { x++; p2 += 2*ry2*x - 2*rx2*y + rx2; }
        plotEllipsePoints(cx, cy, x, y);
    }
    glEnd();
}

void display(void) { glClear(GL_COLOR_BUFFER_BIT); MidPointEllipse(150,150,100,60); glutSwapBuffers(); }
void init(void) { glClearColor(0,0,0,0); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0,300,0,300,-100,1); }
int main(int argc, char **argv) { glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB); glutInitWindowSize(500,500); glutCreateWindow("Mid Point Ellipse"); init(); glutDisplayFunc(display); glutMainLoop(); return 0; }
