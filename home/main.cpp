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
    glBegin(GL_POLYGON);

    glVertex2i(20,30);
    glVertex2i(80,30);
    glVertex2i(80,80);
    glVertex2i(20,80);
    glEnd();

    glColor3f( 1 ,0, 1);
    glBegin(GL_POLYGON);

    glVertex2i(10,80);
    glVertex2i(50,80);
    glVertex2i(90,80);
    glVertex2i(80,95);
    glVertex2i(20,95);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);

    glVertex2i(40,30);
    glVertex2i(60,30);
    glVertex2i(60,50);
    glVertex2i(40,50);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);

    glVertex2i(60,60);
    glVertex2i(70,60);
    glVertex2i(70,70);
    glVertex2i(60,70);
    glEnd();

    glColor3f( 0 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(40,20);
    glVertex2i(40,0);
    glVertex2i(60,0);
    glVertex2i(60,20);
    glVertex2i(65,30);
    glVertex2i(35,30);
    glEnd();

    glColor3f( 1 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(48,10);
    glVertex2i(52,10);
    glVertex2i(52,20);
    glVertex2i(48,20);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(15,25);
    glVertex2i(85,25);
    glVertex2i(85,30);
    glVertex2i(15,30);
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
