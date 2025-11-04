#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

struct Apple {
    float x, y;
    bool visible;
    bool staticApple; // true for decorative apples
    char key;
};

struct Tree {
    float trunkX, trunkY;
    float canopyLeft, canopyRight, canopyTop;
    std::vector<Apple> apples;
};

struct Cloud {
    float x, y;
};

#define NUM_TREES 3
#define CLOUDS_COUNT 3

Tree trees[NUM_TREES];
Cloud clouds[CLOUDS_COUNT];

void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1416f * i / segments;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}

void drawTree(Tree& tree) {
    // Trunk
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(tree.trunkX - 0.06f, tree.trunkY);
    glVertex2f(tree.trunkX + 0.06f, tree.trunkY);
    glVertex2f(tree.trunkX + 0.06f, tree.trunkY + 0.6f);
    glVertex2f(tree.trunkX - 0.06f, tree.trunkY + 0.6f);
    glEnd();

    // Canopy
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(tree.canopyLeft, tree.trunkY + 0.6f);
    glVertex2f(tree.canopyRight, tree.trunkY + 0.6f);
    glVertex2f((tree.canopyLeft + tree.canopyRight) / 2, tree.canopyTop);
    glEnd();
}

void drawApples(Tree& tree) {
    for (auto& a : tree.apples) {
        if (!a.visible) continue;

        glColor3f(1.0f, 0.0f, 0.0f);
        drawCircle(a.x, a.y, 0.035f, 20); // slightly bigger


        if (!a.staticApple) { // only falling apples show letters
            glColor3f(0, 0, 0);
            glRasterPos2f(a.x - 0.008f, a.y - 0.008f);
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, a.key);
        }
    }
}

void drawGround() {
    glColor3f(0.2f, 0.7f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glVertex2f(1, -0.5f);
    glVertex2f(-1, -0.5f);
    glEnd();
}

void drawSky() {
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    for (int i = 0; i < CLOUDS_COUNT; i++) {
        drawCircle(clouds[i].x, clouds[i].y, 0.07f, 20);
        drawCircle(clouds[i].x + 0.06f, clouds[i].y + 0.02f, 0.07f, 20);
        drawCircle(clouds[i].x - 0.06f, clouds[i].y + 0.02f, 0.07f, 20);
    }
}

void initTrees() {
    srand(time(0));
    for (int i = 0; i < NUM_TREES; i++) {
        trees[i].trunkX = -0.8f + i * 0.8f;
        trees[i].trunkY = -0.5f;
        trees[i].canopyLeft = trees[i].trunkX - 0.25f;
        trees[i].canopyRight = trees[i].trunkX + 0.25f;
        trees[i].canopyTop = trees[i].trunkY + 1.0f;

        // Add 3 static decorative apples
    // Spread 3 apples evenly within canopy
        for (int j = 0; j < 3; j++) {
            Apple a;
            a.staticApple = true;
            a.visible = true;
            a.key = ' ';
            a.x = trees[i].canopyLeft + (trees[i].canopyRight - trees[i].canopyLeft) * (0.25f + j * 0.25f);
            a.y = trees[i].trunkY + 0.8f - (j * 0.05f);
            trees[i].apples.push_back(a);
        }

    }
}


void initClouds() {
    for (int i = 0; i < CLOUDS_COUNT; i++) {
        clouds[i].x = -1.0f + i * 0.7f;
        clouds[i].y = 0.7f + static_cast<float>(rand() % 100) / 500.0f;
    }
}

void display() {
    drawSky();
    drawGround();
    for (int i = 0; i < NUM_TREES; i++) {
        drawTree(trees[i]);
        drawApples(trees[i]);
    }
    glFlush();
}

void idle() {
    // Clouds move slowly
    for (int i = 0; i < CLOUDS_COUNT; i++) {
        clouds[i].x += 0.00005f;
        if (clouds[i].x > 1.2f) {
            clouds[i].x = -1.2f;
            clouds[i].y = 0.6f + static_cast<float>(rand() % 100) / 500.0f;
        }
    }

    // Falling apples
    for (int i = 0; i < NUM_TREES; i++) {
        for (auto& a : trees[i].apples) {
            if (!a.staticApple && a.visible) {
                a.y -= 0.0001f;
                if (a.y < -0.5f) a.visible = false;
            }
        }

        // Spawn 1 apple roughly every 5 seconds
        if (rand() % 15000 < 2) {
            Apple a;
            a.x = trees[i].canopyLeft + static_cast<float>(rand() % 100) / 100.0f * 0.5f;
            a.y = trees[i].trunkY + 0.9f;
            a.visible = true;
            a.staticApple = false;
            a.key = 'A' + rand() % 26;
            trees[i].apples.push_back(a);
        }
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int, int) {
    for (int i = 0; i < NUM_TREES; i++) {
        for (auto& a : trees[i].apples) {
            if (!a.staticApple && a.visible && (key == a.key || key == a.key + 32))
                a.visible = false;
        }
    }
    glutPostRedisplay();
}

void init() {
    initTrees();
    initClouds();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Peaceful Apple Forest");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
