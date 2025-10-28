#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(5.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.3, 0.1);
    glVertex2f(0.6, 0.7);
    glVertex2f(0.9, 0.1);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(0.45, 0.35);
    glVertex2f(0.75, 0.35);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-0.8, -0.1);
    glVertex2f(-0.8, -0.7);
    glVertex2f(-0.8, -0.1);
    glVertex2f(-0.4, -0.1);
    glVertex2f(-0.8, -0.4);
    glVertex2f(-0.4, -0.4);
    glVertex2f(-0.8, -0.7);
    glVertex2f(-0.4, -0.7);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Line Plotting");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}