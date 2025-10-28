#include <GL/glut.h>
#include <stdlib.h> 
const int WIDTH = 800;
const int HEIGHT = 600;

void putPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putPixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int originX = WIDTH / 2;
    int originY = HEIGHT / 2;


    glColor3f(0.0f, 1.0f, 0.0f);
    drawLine(originX, 0, originX, HEIGHT);
    drawLine(0, originY, WIDTH, originY);


    glColor3f(1.0f, 1.0f, 1.0f);
    drawLine(originX - 150, originY + 50, originX - 100, originY + 150);
    drawLine(originX - 50, originY + 50, originX - 100, originY + 150);
    drawLine(originX - 120, originY + 100, originX - 80, originY + 100);

    //for L
    drawLine(originX + 50, originY + 50, originX + 50, originY + 150);
    drawLine(originX + 50, originY + 50, originX + 150, originY + 50);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
