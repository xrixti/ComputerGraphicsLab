#include <GL/glut.h>

// Triangle position
float xPos = 0, yPos = 0;
float speed = 10; // Movement step
float boundary = 200; // Window boundary

void drawAxes() {
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-250, 0); glVertex2f(250, 0);
    glVertex2f(0, -250); glVertex2f(0, 250);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();

    // Draw triangle at current position
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(xPos, yPos + 25);   // top
    glVertex2f(xPos - 25, yPos - 25); // bottom left
    glVertex2f(xPos + 25, yPos - 25); // bottom right
    glEnd();

    glFlush();
}

// Keyboard input for arrow keys
void specialKeys(int key, int xx, int yy) {
    switch (key) {
    case GLUT_KEY_UP:
        if (yPos + 25 + speed <= boundary) yPos += speed;
        break;
    case GLUT_KEY_DOWN:
        if (yPos - 25 - speed >= -boundary) yPos -= speed;
        break;
    case GLUT_KEY_LEFT:
        if (xPos - 25 - speed >= -boundary) xPos -= speed;
        break;
    case GLUT_KEY_RIGHT:
        if (xPos + 25 + speed <= boundary) xPos += speed;
        break;
    }
    glutPostRedisplay(); // Redraw
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-250, 250, -250, 250); // Centered coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Move Triangle with Arrow Keys");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys); // Capture arrow keys
    glutMainLoop();
    return 0;
}
