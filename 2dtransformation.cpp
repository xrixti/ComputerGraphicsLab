#include <GL/glut.h>
#include <math.h>

#define PI 3.1416
int choice = 0; // Tracks which transformation to show

void drawAxes() {
    glColor3f(1, 0, 0); // Red axes
    glBegin(GL_LINES);
    glVertex2f(-250, 0); glVertex2f(250, 0); // X-axis
    glVertex2f(0, -250); glVertex2f(0, 250); // Y-axis
    glEnd();
}

void drawOriginalTriangle() {
    glColor3f(1, 0, 0); // Red
    glBegin(GL_LINE_LOOP);
    glVertex2f(50, 50);
    glVertex2f(100, 50);
    glVertex2f(75, 100);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    drawOriginalTriangle();

    // Draw transformation based on choice
    if (choice == 1) { // Translation
        float tx = 50, ty = 75;
        glColor3f(0, 0, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(50 + tx, 50 + ty);
        glVertex2f(100 + tx, 50 + ty);
        glVertex2f(75 + tx, 100 + ty);
        glEnd();
    }
    else if (choice == 2) { // Scaling
        glColor3f(0, 0, 1); // Scale up
        glBegin(GL_LINE_LOOP);
        glVertex2f(50 * 2, 50 * 2);
        glVertex2f(100 * 2, 50 * 2);
        glVertex2f(75 * 2, 100 * 2);
        glEnd();

        glColor3f(0, 1, 0); // Scale down
        glBegin(GL_LINE_LOOP);
        glVertex2f(50 * 0.5, 50 * 0.9);
        glVertex2f(100 * 0.5, 50 * 0.9);
        glVertex2f(75 * 0.5, 100 * 0.9);
        glEnd();
    }
    else if (choice == 3) { // Rotation 45°
        float theta = 45 * PI / 180;
        glColor3f(0, 0, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(50 * cos(theta) - 50 * sin(theta), 50 * sin(theta) + 50 * cos(theta));
        glVertex2f(100 * cos(theta) - 50 * sin(theta), 100 * sin(theta) + 50 * cos(theta));
        glVertex2f(75 * cos(theta) - 100 * sin(theta), 75 * sin(theta) + 100 * cos(theta));
        glEnd();
    }
    else if (choice == 4) { // Reflection
        glColor3f(0, 0, 1); // Reflect X-axis
        glBegin(GL_LINE_LOOP);
        glVertex2f(50, -50);
        glVertex2f(100, -50);
        glVertex2f(75, -100);
        glEnd();

        glColor3f(0, 1, 0); // Reflect Y-axis
        glBegin(GL_LINE_LOOP);
        glVertex2f(-50, 50);
        glVertex2f(-100, 50);
        glVertex2f(-75, 100);
        glEnd();
    }
    else if (choice == 5) { // Shearing X
        float shx = 1.5;
        glColor3f(0, 0, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(50 + shx * 50, 50);
        glVertex2f(100 + shx * 50, 50);
        glVertex2f(75 + shx * 100, 100);
        glEnd();
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '1') choice = 1;
    else if (key == '2') choice = 2;
    else if (key == '3') choice = 3;
    else if (key == '4') choice = 4;
    else if (key == '5') choice = 5;

    glutPostRedisplay();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-250, 250, -250, 250); // include negative coordinates for reflections
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Transformations Switch");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
