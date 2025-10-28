#include <GL/glut.h>
#include <math.h>  // For sin, cos

void drawAxes() {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-250, 0); glVertex2f(250, 0);
    glVertex2f(0, -250); glVertex2f(0, 250);
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


    float theta = 45 * 3.1416 / 180.0;
    glColor3f(0, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(50 * cos(theta) - 50 * sin(theta), 50 * sin(theta) + 50 * cos(theta));
    glVertex2f(100 * cos(theta) - 50 * sin(theta), 100 * sin(theta) + 50 * cos(theta));
    glVertex2f(75 * cos(theta) - 100 * sin(theta), 75 * sin(theta) + 100 * cos(theta));
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotation of Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
