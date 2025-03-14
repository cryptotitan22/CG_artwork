#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

float p = -50.0;

void init(void)
{
    glClearColor(0.4,1.0,0.04,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 0 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,40);
    glVertex2i(100,40);
    glVertex2i(100,60);
    glVertex2i(0,60);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(5,49);
    glVertex2i(15,49);
    glVertex2i(15,51);
    glVertex2i(5,51);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(25,49);
    glVertex2i(35,49);
    glVertex2i(35,51);
    glVertex2i(25,51);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(45,49);
    glVertex2i(55,49);
    glVertex2i(55,51);
    glVertex2i(45,51);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(65,49);
    glVertex2i(75,49);
    glVertex2i(75,51);
    glVertex2i(65,51);
    glEnd();

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(85,49);
    glVertex2i(95,49);
    glVertex2i(95,51);
    glVertex2i(85,51);
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
    glVertex2i(p+3,3);
    glVertex2i(p+3,-3);
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
