#include <GL/glut.h>
#include <math.h>

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void plotCircle(int xc, int yc, int x, int y) {
    drawPixel(xc + x, yc + y);
    drawPixel(xc - x, yc + y);
    drawPixel(xc + x, yc - y);
    drawPixel(xc - x, yc - y);
    drawPixel(xc + y, yc + x);
    drawPixel(xc - y, yc + x);
    drawPixel(xc + y, yc - x);
    drawPixel(xc - y, yc - x);
}


void midpointCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1 - r;
    plotCircle(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 3;
        }
        else {
            y--;
            p += 2 * (x - y) + 5;
        }
        plotCircle(xc, yc, x, y);
    }
}


// Draw coordinate axes
void drawAxes() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(-250, 0); glVertex2i(250, 0);
    glVertex2i(0, -250); glVertex2i(0, 250);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxes();

    glColor3f(1.0, 0.0, 0.0);

    midpointCircle(0, 0, 100);



    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(2.0);
    gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Midpoint");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
