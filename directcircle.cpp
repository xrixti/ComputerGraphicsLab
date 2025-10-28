#include <GL/glut.h>
#include <math.h>

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// 4-way symmetric points
void plotCircle(int xc, int yc, int x, int y) {
    drawPixel(xc + x, yc + y);
    drawPixel(xc - x, yc + y);
    drawPixel(xc + x, yc - y);
    drawPixel(xc - x, yc - y);
}

// Direct Circle 
void directCircle(int xc, int yc, int r) {
    float x, y;
    for (x = 0; x <= r; x++) {
        y = sqrt(r * r - x * x);
        plotCircle(xc, yc, (int)x, (int)y);
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
    directCircle(0, 0, 100);

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
    glutCreateWindow("Direct Circle Drawing (4-Way Symmetry)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
