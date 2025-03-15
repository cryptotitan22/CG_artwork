#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

float p = -100.0;

void init(void)
{
    glClearColor(0.4,1.0,0.04,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 0 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(-100,-10);
    glVertex2i(100,-10);
    glVertex2i(100,20);
    glVertex2i(-100,20);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-95,4);
    glVertex2i(-75,4);
    glVertex2i(-75,6);
    glVertex2i(-95,6);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-55,4);
    glVertex2i(-35,4);
    glVertex2i(-35,6);
    glVertex2i(-55,6);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-15,4);
    glVertex2i(5,4);
    glVertex2i(5,6);
    glVertex2i(-15,6);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(25,4);
    glVertex2i(45,4);
    glVertex2i(45,6);
    glVertex2i(25,6);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(65,4);
    glVertex2i(85,4);
    glVertex2i(85,6);
    glVertex2i(65,6);
    glEnd();
//Home
        glColor3f( 0 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(20,55);
    glVertex2i(30,55);
    glVertex2i(33,65);
    glVertex2i(23,65);
    glEnd();


    glColor3f(0.97, 0.74, 0.4);
    glBegin(GL_POLYGON);
    glVertex2i(10,65);
    glVertex2i(46,65);
    glVertex2i(46,85);
    glVertex2i(10,85);
    glEnd();

//Home Door
        glColor3f(0.72, 0.33, 0.48);
    glBegin(GL_POLYGON);
    glVertex2i(23,65);
    glVertex2i(33,65);
    glVertex2i(33,75);
    glVertex2i(23,75);
    glEnd();

    //Home Window
    glColor3f(0.97, 0.92, 0.85);
    glBegin(GL_POLYGON);
    glVertex2i(11,72);
    glVertex2i(21,72);
    glVertex2i(21,80);
    glVertex2i(11,80);
    glEnd();

    //Home Window
    glColor3f(0.97, 0.92, 0.85);
    glBegin(GL_POLYGON);
    glVertex2i(35,72);
    glVertex2i(45,72);
    glVertex2i(45,80);
    glVertex2i(35,80);
    glEnd();

    //Home Tin
        glColor3f( 1 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(7,85);
    glVertex2i(49,85);
    glVertex2i(28,95);
    glEnd();


//Car Movement
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
    glVertex2i(p,3);
    glVertex2i(p+15,3);
    glVertex2i(p+15,-3);
    glVertex2i(p,-3);
    glEnd();

// Write your Code


    glutSwapBuffers();
    if (p <= 100)
        p += 0.01;
    else
        p = -100;

    glutPostRedisplay();
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
