#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(30,10);
    glVertex2i(60,10);
    glEnd();

    glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(30,10);
    glVertex2i(45,30);
    glEnd();

            glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(60,10);
    glVertex2i(45,30);
    glEnd();

        glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(30,10);
    glVertex2i(60,10);
    glEnd();

            glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(45,30);
    glVertex2i(10,60);
    glEnd();

            glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(10,60);
    glVertex2i(45,100);
    glEnd();

            glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(45,100);
    glVertex2i(80,60);
    glEnd();

            glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(80,60);
    glVertex2i(45,30);
    glEnd();

        glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(45,30);
    glVertex2i(45,100);
    glEnd();

            glColor3f( 1 ,0, 0);
    glBegin(GL_LINES);
    glVertex2i(10,60);
    glVertex2i(80,60);
    glEnd();


// Write your Code


    glutSwapBuffers();
}

int main(int argc,char **argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
