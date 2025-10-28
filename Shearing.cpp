#include <GL/glut.h>

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


    glColor3f(0, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(50 + shx * 50, 50);
    glVertex2f(100 + shx * 50, 50);
    glVertex2f(75 + shx * 100, 100);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Shearing of Triangle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
