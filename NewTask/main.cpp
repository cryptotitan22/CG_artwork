#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

float p = -10.0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0);
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    glBegin(GL_QUADS);
        glVertex2i(-3, p);
        glVertex2i(-3, p + 7);
        glVertex2i(3, p + 7);
        glVertex2i(3, p);
    glEnd();

    glutSwapBuffers();

    if (p <= 10)
        p += 0.0008;
    else
        p = -10;

    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutIdleFunc(Draw);
    glutMainLoop();
    return 0;
}
