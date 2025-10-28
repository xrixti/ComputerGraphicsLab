#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

// --------- DDA Algorithm ---------
void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    float X = x1;
    float Y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2i(round(X), round(Y));
        X += Xinc;
        Y += Yinc;
    }
    glEnd();
}

// --------- DLD / Bresenham Algorithm ---------
void DLD(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;

    int x, y, xEnd;

    if (x1 > x2) {
        x = x2;
        y = y2;
        xEnd = x1;
    } else {
        x = x1;
        y = y1;
        xEnd = x2;
    }

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    while (x < xEnd) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
        glVertex2i(x, y);
    }
    glEnd();
}

// --------- Display Function ---------
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Triangle coordinates
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    // ---- Draw Triangle using DDA ----
    glColor3f(1.0, 0.0, 0.0); // red
    DDA(x1, y1, x2, y2);
    DDA(x2, y2, x3, y3);
    DDA(x3, y3, x1, y1);

    // ---- Draw Triangle using DLD ----
    glColor3f(0.0, 0.0, 1.0); // blue
    DLD(x1 + 200, y1, x2 + 200, y2); // shifted right
    DLD(x2 + 200, y2, x3 + 200, y3);
    DLD(x3 + 200, y3, x1 + 200, y1);

    glFlush();
}

// --------- Init Function ---------
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glColor3f(0.0, 0.0, 0.0);         // black drawing
    glPointSize(2.0);                 // point size
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);       // 2D projection
}

// --------- Main Function ---------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA & DLD Algorithm - Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
