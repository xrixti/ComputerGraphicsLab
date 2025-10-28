#include <GL/glut.h>  // OpenGL Utility Toolkit

// Draw coordinate axes
void drawAxes() {
    glColor3f(0, 0, 0); // Black axes
    glBegin(GL_LINES);
    glVertex2f(-250, 0); glVertex2f(250, 0); // X-axis
    glVertex2f(0, -250); glVertex2f(0, 250); // Y-axis
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();

    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(50, 50);
    glVertex2f(100, 50);
    glVertex2f(75, 100);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(50 * 2, 50 * 2);
    glVertex2f(100 * 2, 50 * 2);
    glVertex2f(75 * 2, 100 * 2);
    glEnd();


    glColor3f(0, 1, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(50 * 0.5, 50 * 0.9);
    glVertex2f(100 * 0.5, 50 * 0.9);
    glVertex2f(75 * 0.5, 100 * 0.9);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1); // White background
    gluOrtho2D(0, 500, 0, 500); // 2D coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scaling of Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
