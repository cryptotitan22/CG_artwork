#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(0.0, 150.0, 0.0, 150.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 0 ,0, 0);
    glBegin(GL_POLYGON);

    glVertex2i(20,0);
    glVertex2i(130,0);
    glVertex2i(140,20);
    glVertex2i(10,20);
    glEnd();

    glColor3f( 0 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(30,20);
    glVertex2i(40,20);
    glVertex2i(40,68);
    glVertex2i(20,68);
    glVertex2i(20,20);
    glEnd();

    glColor3f( 0.64 ,0.09, 0.81);
    glBegin(GL_POLYGON);
    glVertex2i(40,20);
    glVertex2i(60,20);
    glVertex2i(60,80);
    glVertex2i(40,80);
    glEnd();

    glColor3f( 1 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(60,20);
    glVertex2i(80,20);
    glVertex2i(80,65);
    glVertex2i(60,65);
    glEnd();

    glColor3f( 0.62 ,0.09, 0.56);
    glBegin(GL_POLYGON);
    glVertex2i(80,20);
    glVertex2i(130,20);
    glVertex2i(130,58);
    glVertex2i(80,58);
    glEnd();

    glColor3f( 1 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(83,43);
    glVertex2i(95,43);
    glVertex2i(95,55);
    glVertex2i(83,55);
    glEnd();

    glColor3f( 1 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(98,43);
    glVertex2i(110,43);
    glVertex2i(110,55);
    glVertex2i(98,55);

    glEnd();

    glColor3f( 1 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(113,43);
    glVertex2i(125,43);
    glVertex2i(125,55);
    glVertex2i(113,55);

    glEnd();

    glColor3f( 1 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(50,90);
    glVertex2i(70,80);
    glVertex2i(60,100);
    glVertex2i(80,110);
        glVertex2i(57,110);
            glVertex2i(50,130);
                glVertex2i(42,110);
                glVertex2i(20,110);
                glVertex2i(40,100);
                                glVertex2i(30,80);


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
