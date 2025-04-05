#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

float p = -10.0;
float sunPos = 0.0;
bool isNight = false;
float cloudPos = 300.0;
float cloudSpeed = 0.05;
float planePos = -10.0;
float planeSpeed = 0.1;
float birdPos = -10.0;
float birdSpeed = 0.3;

// Star positions
float stars[10][2] = {
    {100, 900}, {200, 800}, {300, 950}, {450, 870}, {600, 920},
    {750, 860}, {850, 980}, {900, 750}, {650, 800}, {500, 950}
};

void init(void)
{
    glClearColor(0.23, 0.24, 0.24, 1.0); // Night time Background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1000.0, 0.0, 1000.0, -10.0, 10.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void drawStars()
{
    glColor3f(1.0, 1.0,0);
    for (int i = 0; i < 10; i++)
    {
        circle(5, 5, stars[i][0], stars[i][1]);
    }
}


void Draw()
{

    if (sunPos >= 1000)
        isNight = true;
    else if (sunPos <= -10)
        isNight = false;

    glClear(GL_COLOR_BUFFER_BIT);

    if (isNight)
    {
        glColor3f(0.0, 0.0, 0.2);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(1000, 0);
        glVertex2f(1000, 1000);
        glVertex2f(0, 1000);
        glEnd();

        drawStars();
    }
    else
    {

        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(0, 0);
        glVertex2f(1000, 0);

        glColor3f(0.18, 0.51, 0.95);
        glVertex2f(1000, 1000);
        glVertex2f(0, 1000);
        glEnd();
    }


    /////
    //Bird

    glColor3ub(150, 150, 150);

    // Bird Body
    glBegin(GL_POLYGON);
    glVertex2f(birdPos + 0, 975);
    glVertex2f(birdPos + 20, 975);
    glVertex2f(birdPos + 25, 980);
    glVertex2f(birdPos + 20, 985);
    glVertex2f(birdPos + 0, 985);
    glEnd();

    // Left Wing
    glColor3ub(130, 130, 130);
    glBegin(GL_POLYGON);
    glVertex2f(birdPos + 10, 980);
    glVertex2f(birdPos - 20, 1000);
    glVertex2f(birdPos + 15, 1000);
    glVertex2f(birdPos + 10, 975);
    glEnd();

    // Right Wing
    glBegin(GL_POLYGON);
    glVertex2f(birdPos + 15, 980);
    glVertex2f(birdPos + 40, 960);
    glVertex2f(birdPos + 10, 965);
    glVertex2f(birdPos + 13, 975);
    glEnd();

    // Bird Beak (triangle)
    glColor3ub(255, 165, 0);  // Orange color for the beak
    glBegin(GL_POLYGON);
    glVertex2f(birdPos + 20, 980);
    glVertex2f(birdPos + 25, 975);
    glVertex2f(birdPos + 25, 985);
    glEnd();

    // Update bird position for animation
    birdPos += birdSpeed;
    if (birdPos > 1000)
        birdPos = -100;





    glBegin(GL_QUADS);
    //Left side Road
    glColor3f(0.97, 0.95, 0.92);
    glBegin(GL_POLYGON);
    glVertex2i(0, 20);
    glVertex2i(190, 300);
    glVertex2i(130, 300);
    glVertex2i(0, 160);
    glEnd();

    //Left to Right side road
    glColor3f(0.97, 0.95, 0.92);
    glBegin(GL_POLYGON);
    glVertex2i(0, 275);
    glVertex2i(1000, 395);
    glVertex2i(1000, 410);
    glVertex2i(0, 300);
    glEnd();

    //Right Side road

    glColor3f(0.97, 0.95, 0.92);
    glBegin(GL_POLYGON);
    glVertex2i(1000, 20);
    glVertex2i(1000, 155);
    glVertex2i(810, 373);
    glVertex2i(760, 380);
    glEnd();

    ////////////IR lab
        glColor3f(0.97, 0.95, 0.92);
    glBegin(GL_POLYGON);
    glVertex2i(1000, 20);
    glVertex2i(1000, 155);
    glVertex2i(810, 373);
    glVertex2i(760, 380);
    glEnd();



    ///////////////////
    ///////AB3 right side to left side tree
    // Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(125, 313);
glVertex2f(129, 312);
glVertex2f(130, 322);
glVertex2f(122, 352);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(125, 313);
glVertex2f(129, 312);
glVertex2f(127, 321);
glVertex2f(118, 332);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(125, 313);
glVertex2f(127, 312);
glVertex2f(130, 322);
glVertex2f(130, 352);
glEnd();

// Leaves with Different Colors
glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 124, 353);
circle(5, 12, 119, 363);
circle(5, 12, 129, 363);
circle(5, 12, 134, 358);
circle(5, 12, 114, 373);

glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 118, 377);
glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 121, 377);
circle(5, 12, 123, 385);
circle(5, 10, 118, 380);
glColor3f(0.16, 0.86, 0.26);
circle(5, 10, 120, 378);

glColor3f(0.16, 0.86, 0.26);
circle(7, 10, 121, 373);
circle(8, 12, 133, 371);
circle(8, 12, 128, 371);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 127, 366);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 126, 365);
circle(8, 12, 138, 361);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 133, 356);
glColor3f(0.16, 0.86, 0.26);
circle(10, 14, 130, 353);
circle(10, 14, 121, 356);
circle(10, 14, 133, 376);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 128, 366);
circle(1, 2, 128, 380);
circle(1, 2, 138, 380);
circle(1, 2, 117, 366);
circle(1, 2.5, 123, 381);
circle(1, 1.5, 124, 367);
circle(1, 2.5, 138, 362);
circle(1, 3, 133, 359);
circle(1, 3, 123, 363);

/////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(100, 308);
glVertex2f(104, 307);
glVertex2f(105, 317);
glVertex2f(97, 347);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(100, 308);
glVertex2f(104, 307);
glVertex2f(102, 316);
glVertex2f(93, 327);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(100, 308);
glVertex2f(102, 307);
glVertex2f(105, 317);
glVertex2f(105, 347);
glEnd();

// Leaves with Different Colors
glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 99, 348);
circle(5, 12, 94, 358);
circle(5, 12, 104, 358);
circle(5, 12, 109, 353);
circle(5, 12, 89, 368);

glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 93, 372);
glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 96, 372);
circle(5, 12, 98, 380);
circle(5, 10, 93, 375);
glColor3f(0.16, 0.86, 0.26);
circle(5, 10, 95, 373);

glColor3f(0.16, 0.86, 0.26);
circle(7, 10, 96, 366);
circle(8, 12, 108, 364);
circle(8, 12, 103, 364);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 102, 359);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 101, 358);
circle(8, 12, 113, 354);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 108, 349);
glColor3f(0.16, 0.86, 0.26);
circle(10, 14, 105, 346);
circle(10, 14, 96, 349);
circle(10, 14, 108, 369);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 103, 359);
circle(1, 2, 103, 373);
circle(1, 2, 113, 373);
circle(1, 2, 92, 359);
circle(1, 2.5, 98, 374);
circle(1, 1.5, 99, 360);
circle(1, 2.5, 113, 355);
circle(1, 3, 108, 352);
circle(1, 3, 98, 356);

////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(75, 305);
glVertex2f(79, 304);
glVertex2f(80, 314);
glVertex2f(72, 344);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(75, 305);
glVertex2f(79, 304);
glVertex2f(77, 313);
glVertex2f(68, 324);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(75, 305);
glVertex2f(77, 304);
glVertex2f(80, 314);
glVertex2f(80, 344);
glEnd();

// Leaves with Different Colors
glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 74, 345);
circle(5, 12, 69, 355);
circle(5, 12, 79, 355);
circle(5, 12, 84, 350);
circle(5, 12, 64, 365);

glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 68, 369);
glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 71, 369);
circle(5, 12, 73, 377);
circle(5, 10, 68, 372);
glColor3f(0.16, 0.86, 0.26);
circle(5, 10, 70, 370);

glColor3f(0.16, 0.86, 0.26);
circle(7, 10, 71, 363);
circle(8, 12, 83, 361);
circle(8, 12, 78, 361);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 77, 356);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 76, 355);
circle(8, 12, 88, 351);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 83, 346);
glColor3f(0.16, 0.86, 0.26);
circle(10, 14, 80, 343);
circle(10, 14, 71, 346);
circle(10, 14, 83, 366);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 78, 356);
circle(1, 2, 78, 370);
circle(1, 2, 88, 370);
circle(1, 2, 67, 356);
circle(1, 2.5, 73, 371);
circle(1, 1.5, 74, 357);
circle(1, 2.5, 88, 352);
circle(1, 3, 83, 349);
circle(1, 3, 73, 353);

///////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(50, 301);
glVertex2f(54, 300);
glVertex2f(55, 310);
glVertex2f(47, 340);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(50, 301);
glVertex2f(54, 300);
glVertex2f(52, 309);
glVertex2f(43, 320);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(50, 301);
glVertex2f(52, 300);
glVertex2f(55, 310);
glVertex2f(55, 340);
glEnd();

// Leaves with Different Colors
glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 49, 341);
circle(5, 12, 44, 351);
circle(5, 12, 54, 351);
circle(5, 12, 59, 346);
circle(5, 12, 39, 361);

glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 43, 365);
glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 46, 365);
circle(5, 12, 48, 373);
circle(5, 10, 43, 368);
glColor3f(0.16, 0.86, 0.26);
circle(5, 10, 45, 366);

glColor3f(0.16, 0.86, 0.26);
circle(7, 10, 46, 360);
circle(8, 12, 58, 358);
circle(8, 12, 53, 358);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 52, 353);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 51, 352);
circle(8, 12, 63, 348);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 58, 343);
glColor3f(0.16, 0.86, 0.26);
circle(10, 14, 55, 340);
circle(10, 14, 46, 343);
circle(10, 14, 58, 363);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 53, 353);
circle(1, 2, 53, 367);
circle(1, 2, 63, 367);
circle(1, 2, 42, 353);
circle(1, 2.5, 48, 368);
circle(1, 1.5, 49, 354);
circle(1, 2.5, 63, 348);
circle(1, 3, 58, 345);
circle(1, 3, 48, 349);

////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(25, 298);
glVertex2f(29, 297);
glVertex2f(30, 307);
glVertex2f(22, 337);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(25, 298);
glVertex2f(29, 297);
glVertex2f(27, 306);
glVertex2f(18, 317);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(25, 298);
glVertex2f(27, 297);
glVertex2f(30, 307);
glVertex2f(30, 337);
glEnd();

// Leaves with Different Colors
glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 24, 338);
circle(5, 12, 19, 348);
circle(5, 12, 29, 348);
circle(5, 12, 34, 343);
circle(5, 12, 14, 358);

glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 18, 362);
glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 21, 362);
circle(5, 12, 23, 370);
circle(5, 10, 18, 365);
glColor3f(0.16, 0.86, 0.26);
circle(5, 10, 20, 363);

glColor3f(0.16, 0.86, 0.26);
circle(7, 10, 21, 356);
circle(8, 12, 33, 354);
circle(8, 12, 28, 354);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 27, 349);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 26, 348);
circle(8, 12, 38, 344);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 33, 339);
glColor3f(0.16, 0.86, 0.26);
circle(10, 14, 30, 336);
circle(10, 14, 21, 339);
circle(10, 14, 33, 359);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 28, 349);
circle(1, 2, 28, 363);
circle(1, 2, 38, 363);
circle(1, 2, 17, 349);
circle(1, 2.5, 23, 364);
circle(1, 1.5, 24, 350);
circle(1, 2.5, 38, 345);
circle(1, 3, 33, 342);
circle(1, 3, 23, 346);

/////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(0, 295);
glVertex2f(4, 294);
glVertex2f(5, 304);
glVertex2f(-3, 334);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(0, 295);
glVertex2f(4, 294);
glVertex2f(2, 303);
glVertex2f(-7, 314);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(0, 295);
glVertex2f(2, 294);
glVertex2f(5, 304);
glVertex2f(5, 334);
glEnd();

// Leaves with Different Colors
glColor3f(0.16, 0.86, 0.26);
circle(3, 6, -1, 335);
circle(5, 12, -6, 345);
circle(5, 12, 4, 345);
circle(5, 12, 9, 340);
circle(5, 12, -11, 353);

glColor3f(0.16, 0.86, 0.26);
circle(5, 12, -7, 357);
glColor3f(0.16, 0.86, 0.26);
circle(5, 12, -4, 357);
circle(5, 12, -2, 365);
circle(5, 10, -7, 360);
glColor3f(0.16, 0.86, 0.26);
circle(5, 10, -5, 358);

glColor3f(0.16, 0.86, 0.26);
circle(7, 10, -4, 353);
circle(8, 12, 8, 351);
circle(8, 12, 3, 351);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 2, 346);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 1, 345);
circle(8, 12, 13, 341);
glColor3f(0.16, 0.86, 0.26);
circle(8, 12, 8, 336);
glColor3f(0.16, 0.86, 0.26);
circle(10, 14, 5, 333);
circle(10, 14, -4, 336);
circle(10, 14, 8, 356);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 3, 346);
circle(1, 2, 3, 360);
circle(1, 2, 13, 360);
circle(1, 2, -6, 346);
circle(1, 2.5, 0, 361);
circle(1, 1.5, -1, 347);
circle(1, 2.5, 13, 342);
circle(1, 3, 8, 339);
circle(1, 3, -2, 343);

/////////////




    //AB3 Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(130, 314);
    glVertex2i(250, 327);
    glVertex2i(257, 617);
    glVertex2i(137, 608);
    glEnd();

// Top
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(137, 608);
    glVertex2i(257, 617);
    glVertex2i(258, 622);
    glVertex2i(138, 613);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(137,608);
    glVertex2i(300,617);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(300,622);
    glVertex2i(138,613);
    glEnd();

    //////////////////
    //Radio antena
        glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2i(200,618);
    glVertex2i(205,800);
    glEnd();

    circle(2, 4, 205, 800);

            glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2i(200,670);
    glVertex2i(204,672);
    glEnd();

            glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2i(200,670);
    glVertex2i(160,615);
    glEnd();

                glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2i(204,672);
    glVertex2i(240,615);
    glEnd();

    //Middle Wall

    glColor3f(0.38, 0.38, 0.38);
    glBegin(GL_POLYGON);
    glVertex2i(249, 327);
    glVertex2i(253, 330);
    glVertex2i(259, 625);
    glVertex2i(257, 623);
    glEnd();


    // Right Side Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(253, 326);
    glVertex2i(290, 332);
    glVertex2i(293, 625);
    glVertex2i(258, 622);
    glEnd();

    //6th floor of the right side building
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,566);
    glVertex2i(293,575);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,571);
    glVertex2i(293,580);
    glEnd();


    //Right Side Building Wall
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(290,332);
    glVertex2i(292,625);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(282,332);
    glVertex2i(284,625);
    glEnd();

//Right side Building top

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(293,626);
    glVertex2i(290,333);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(300,622);
    glVertex2i(138,613);
    glEnd();


    //Left Side Column


    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(130,314);
    glVertex2i(137,613);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(140,314);
    glVertex2i(146,613);
    glEnd();

    //Right Side Column


    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(240,327);
    glVertex2i(247,622);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(249,327);
    glVertex2i(257,623);
    glEnd();

    //AB3 Field
    glColor3f(0.78, 0.8, 0.68);
    glBegin(GL_POLYGON);
    glVertex2i(290, 330);
    glVertex2i(470, 350);
    glVertex2i(440, 400);
    glVertex2i(290, 380);
    glEnd();

    //AB3 Field 1st floor to 3rd Floor Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(291, 380);
    glVertex2i(440, 400);
    glVertex2i(440, 494);
    glVertex2i(292, 490);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(291,412);
    glVertex2i(440,432);
    glEnd();

    //AB3 Field 3rd floor to 1st floor column
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(440,399);
    glVertex2i(440,496);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(435,399);
    glVertex2i(435,496);
    glEnd();

    //AB3 1st floor all windows

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(294, 385);
    glVertex2i(327, 387);
    glVertex2i(327, 412);
    glVertex2i(294, 409);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(340, 391);
    glVertex2i(353, 393);
    glVertex2i(353, 415);
    glVertex2i(340, 412);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(364, 395);
    glVertex2i(392, 397);
    glVertex2i(392, 420);
    glVertex2i(364, 417);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(405, 398);
    glVertex2i(431, 400);
    glVertex2i(431, 425);
    glVertex2i(405, 422);
    glEnd();

    //AB3 2nd floor all windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(294, 420);
    glVertex2i(327, 422);
    glVertex2i(327, 443);
    glVertex2i(294, 440);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(340, 426);
    glVertex2i(353, 428);
    glVertex2i(353, 446);
    glVertex2i(340, 443);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(364, 430);
    glVertex2i(392, 432);
    glVertex2i(392, 451);
    glVertex2i(364, 448);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(405, 433);
    glVertex2i(431, 435);
    glVertex2i(431, 456);
    glVertex2i(405, 452);
    glEnd();

    //AB3 3rd floor all windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(294, 455);
    glVertex2i(327, 457);
    glVertex2i(327, 473);
    glVertex2i(294, 471);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(340, 461);
    glVertex2i(353, 463);
    glVertex2i(353, 476);
    glVertex2i(340, 474);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(364, 464);
    glVertex2i(390, 466);
    glVertex2i(390, 483);
    glVertex2i(364, 481);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(405, 467);
    glVertex2i(429, 469);
    glVertex2i(429, 488);
    glVertex2i(405, 486);
    glEnd();

    //AB3 4th floor all windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(294, 490);
    glVertex2i(327, 492);
    glVertex2i(327, 503);
    glVertex2i(294, 502);
    glEnd();

    //AB3 Field 4th Floor Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(292, 490);
    glVertex2i(400, 492);
    glVertex2i(400, 525);
    glVertex2i(292, 525);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(291,444);
    glVertex2i(440,464);
    glEnd();

    //AB3 Field 4th floor to 1st floor column
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(400,394);
    glVertex2i(400,525);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(395,394);
    glVertex2i(395,525);
    glEnd();



    //AB3 Field 5th Floor Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(292, 525);
    glVertex2i(360, 525);
    glVertex2i(360, 557);
    glVertex2i(292, 557);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(291,482);
    glVertex2i(440,496);
    glEnd();

    //AB3 Field 6th Floor Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(292, 557);
    glVertex2i(335, 557);
    glVertex2i(335, 589);
    glVertex2i(292, 589);
    glEnd();

//4th floor of field building
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(293,520);
    glVertex2i(400,526);
    glEnd();

    //AB3 Field 7th Floor Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(292, 589);
    glVertex2i(335, 589);
    glVertex2i(335, 623);
    glVertex2i(292, 623);
    glEnd();

        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(292,623);
    glVertex2i(335,623);
    glEnd();



    //AB3 Field 7th floor to 1st floor column
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(335,385);
    glVertex2i(335,625);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(330,385);
    glVertex2i(330,625);
    glEnd();



// 5th floor of fieldd building
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(293,556);
    glVertex2i(360,558);
    glEnd();

    //AB3 Field 5th floor to 1st floor column
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(360,388);
    glVertex2i(360,558);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(357,388);
    glVertex2i(357,558);
    glEnd();

    // 6th flooor of field building
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(293,588);
    glVertex2i(335,590);
    glEnd();

//1st floor
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(131,351);
    glVertex2i(290,364);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(131,356);
    glVertex2i(290,369);
    glEnd();

    //1st floor right side building Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(253, 326);
    glVertex2i(282, 329);
    glVertex2i(283, 364);
    glVertex2i(253, 360);
    glEnd();

    //Red Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(140, 314);
    glVertex2i(160, 316);
    glVertex2i(160, 353);
    glVertex2i(141, 351);
    glEnd();

    // Black Window
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(209, 322);
    glVertex2i(240, 324);
    glVertex2i(240, 358);
    glVertex2i(210, 356);
    glEnd();


    //2nd floor
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(132,397);
    glVertex2i(290,410);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(132,403);
    glVertex2i(290,415);
    glEnd();

    //2nd floor right side building Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(254, 367);
    glVertex2i(282, 369);
    glVertex2i(283, 409);
    glVertex2i(254, 406);
    glEnd();

    //Red Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(141, 356);
    glVertex2i(161, 358);
    glVertex2i(162, 400);
    glVertex2i(142, 398);
    glEnd();

    // Black Window
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(210, 363);
    glVertex2i(240, 363);
    glVertex2i(242, 405);
    glVertex2i(212, 403);
    glEnd();


    //3rd floor
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(133,440);
    glVertex2i(291,452);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(133,445);
    glVertex2i(291,456);
    glEnd();

    //3rd floor right side building Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(254, 413);
    glVertex2i(282, 415);
    glVertex2i(283, 450);
    glVertex2i(255, 449);
    glEnd();

    //Red Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(141, 403);
    glVertex2i(161, 406);
    glVertex2i(163, 443);
    glVertex2i(142, 441);
    glEnd();

    // Black Window
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(211, 411);
    glVertex2i(241, 413);
    glVertex2i(242, 448);
    glVertex2i(212, 446);
    glEnd();




    //4th floor
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,482);
    glVertex2i(292,493);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,487);
    glVertex2i(292,498);
    glEnd();
    //4th floor right side building Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(255, 454);
    glVertex2i(283, 455);
    glVertex2i(283, 491);
    glVertex2i(256, 490);
    glEnd();


    //Red Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(142, 445);
    glVertex2i(162, 448);
    glVertex2i(164, 485);
    glVertex2i(143, 483);
    glEnd();

    // Black Window
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(213, 451);
    glVertex2i(243, 453);
    glVertex2i(244, 490);
    glVertex2i(214, 488);
    glEnd();

    //5th floor
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,524);
    glVertex2i(294,533);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,529);
    glVertex2i(294,538);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(256, 497);
    glVertex2i(283, 495);
    glVertex2i(283, 532);
    glVertex2i(257, 531);
    glEnd();



    //5th floor right side building Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(256, 497);
    glVertex2i(283, 495);
    glVertex2i(283, 532);
    glVertex2i(257, 531);
    glEnd();

    //Red Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(143, 487);
    glVertex2i(164, 490);
    glVertex2i(165, 527);
    glVertex2i(144, 525);
    glEnd();

    // Black Window
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(214, 494);
    glVertex2i(244, 496);
    glVertex2i(245, 532);
    glVertex2i(215, 530);
    glEnd();



    //6th floor
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,566);
    glVertex2i(255,575);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(134,571);
    glVertex2i(255,580);
    glEnd();

    //Red Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(144, 529);
    glVertex2i(165, 532);
    glVertex2i(166, 569);
    glVertex2i(145, 567);
    glEnd();

    // Black Window
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(215, 536);
    glVertex2i(245, 537);
    glVertex2i(246, 574);
    glVertex2i(216, 572);
    glEnd();

//  7 Floor
    //Red Wall
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(145, 571);
    glVertex2i(166, 574);
    glVertex2i(167, 610);
    glVertex2i(146, 609);
    glEnd();

    // Black Window
    glColor3ub(177,124,119);
    glBegin(GL_POLYGON);
    glVertex2i(216, 577);
    glVertex2i(246, 580);
    glVertex2i(247, 617);
    glVertex2i(217, 614);
    glEnd();



    // DIU Mosque
    glColor3f(0.88, 0.91, 0.91);
    glBegin(GL_POLYGON);
    glVertex2i(500, 355);
    glVertex2i(620, 368);
    glVertex2i(640, 492);
    glVertex2i(470, 480);
    glEnd();

    //DIU Mosque Line
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(500,355);
    glVertex2i(620,368);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(640,492);
    glVertex2i(470,480);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(500,355);
    glVertex2i(470,480);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(620,368);
    glVertex2i(640,492);
    glEnd();





    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(510,355);
    glVertex2i(510,490);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(610,368);
    glVertex2i(610,492);
    glEnd();

    // DIU Mosque Square Shape
    glColor3f(0.96, 0.62, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(510, 355);
    glVertex2i(610, 366);
    glVertex2i(610, 456);
    glVertex2i(510, 450);
    glEnd();

    // DIU Mosque top Shape rectangle shape
    glColor3f(0.96, 0.62, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(510, 470);
    glVertex2i(610, 477);
    glVertex2i(610, 492);
    glVertex2i(510, 483);
    glEnd();

// Diu mosque First side
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(550, 358);
    glVertex2i(570, 360);
    glVertex2i(570, 410);
    glVertex2i(550, 410);
    glEnd();
// Blue color for first side
    glColor3f(0.24, 0.24, 0.98);
    glBegin(GL_POLYGON);
    glVertex2i(552, 358);
    glVertex2i(568, 360);
    glVertex2i(568, 390);
    glVertex2i(552, 390);
    glEnd();
    glColor3f(0.24, 0.24, 0.98);
    circle(8, 8, 560, 392);

    // DIU Mosque TOP
    glColor3f(0.87, 0.88, 0.84);
    glBegin(GL_POLYGON);
    glVertex2i(468, 480);
    glVertex2i(643, 492);
    glVertex2i(643, 498);
    glVertex2i(468, 488);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(468,480);
    glVertex2i(643,492);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(643,498);
    glVertex2i(468,488);
    glEnd();

    //YKSG 2 hall
        glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(550, 491);
    glVertex2i(550, 618);
    glVertex2i(643, 620);
    glVertex2i(643, 498);
    glEnd();

    //YKSG 2 Hall LIne
        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(550,491);
    glVertex2i(550,618);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(643,620);
    glVertex2i(643,498);
    glEnd();

        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(550,618);
    glVertex2i(643,620);
    glEnd();



    //YKSG 2 hall Windows

            glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(555, 496);
    glVertex2i(555, 510);
    glVertex2i(638, 510);
    glVertex2i(638, 496);
    glEnd();

            glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(555, 515);
    glVertex2i(555, 529);
    glVertex2i(638, 529);
    glVertex2i(638, 515);
    glEnd();

            glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(555, 534);
    glVertex2i(555, 548);
    glVertex2i(638, 548);
    glVertex2i(638, 534);
    glEnd();

                glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(555, 553);
    glVertex2i(555, 567);
    glVertex2i(638, 567);
    glVertex2i(638, 553);
    glEnd();

                glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(555, 572);
    glVertex2i(555, 586);
    glVertex2i(638, 586);
    glVertex2i(638, 572);
    glEnd();

    //YKSG 1 Building Column

                glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(555, 591);
    glVertex2i(555, 605);
    glVertex2i(638, 605);
    glVertex2i(638, 591);
    glEnd();


                glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(580, 491);
    glVertex2i(580, 618);
    glVertex2i(585, 620);
    glVertex2i(585, 498);
    glEnd();

                glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(620, 491);
    glVertex2i(620, 618);
    glVertex2i(625, 620);
    glVertex2i(625, 498);
    glEnd();

// Mosque beside building
    glColor3f(0.88, 0.11, 0.11);
    glBegin(GL_POLYGON);
    glVertex2i(468, 489);
    glVertex2i(550, 493);
    glVertex2i(550, 520);
    glVertex2i(468, 522);
    glEnd();

    // Mosque beside building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(510, 489);
    glVertex2i(514, 493);
    glVertex2i(514, 520);
    glVertex2i(510, 522);
    glEnd();

    //Mosque beside building line
        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(510,489);
    glVertex2i(510,522);
    glEnd();

        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(514,492);
    glVertex2i(514,520);
    glEnd();

        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(514,520);
    glVertex2i(510,522);
    glEnd();


    // Mosque beside building Window 1
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(473, 493);
    glVertex2i(505, 497);
    glVertex2i(505, 516);
    glVertex2i(473, 516);
    glEnd();

    // Mosque beside building Windows 2
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(520, 497);
    glVertex2i(545, 498);
    glVertex2i(545, 516);
    glVertex2i(520, 514);
    glEnd();


    //AB2 1st floor to 3rd Floor Building
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(668, 414);
    glVertex2i(1000, 449);
    glVertex2i(1000, 545);
    glVertex2i(668, 514);
    glEnd();

        //AB2 1st floor to 3rd floor building line
        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(668,414);
    glVertex2i(1000,449);
    glEnd();

        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(1000,449);
    glVertex2i(1000,545);
    glEnd();

        glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(1000,545);
    glVertex2i(668,514);
    glEnd();

            glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(668,514);
    glVertex2i(668,414);
    glEnd();

    //AB2 1st Floor Windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(672, 418);
    glVertex2i(996, 453);
    glVertex2i(996, 475);
    glVertex2i(672, 443);
    glEnd();

    //AB2 2nd Floor Windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(672, 450);
    glVertex2i(996, 482);
    glVertex2i(996, 505);
    glVertex2i(672, 475);
    glEnd();

    //AB2 3rd Floor Windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(672, 482);
    glVertex2i(996, 511);
    glVertex2i(996, 535);
    glVertex2i(672, 507);
    glEnd();

    //AB2 1st column
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(718, 419);
    glVertex2i(723, 419);
    glVertex2i(723, 520);
    glVertex2i(718, 520);
    glEnd();

    //AB2 2nd column
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(768, 424);
    glVertex2i(773, 424);
    glVertex2i(773, 520);
    glVertex2i(768, 520);
    glEnd();

    //AB2 3rd column
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(818, 430);
    glVertex2i(823, 430);
    glVertex2i(823, 528);
    glVertex2i(818, 528);
    glEnd();

    //AB2 4th column
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(878, 440);
    glVertex2i(883, 440);
    glVertex2i(883, 528);
    glVertex2i(878, 528);
    glEnd();

    //AB2 5th column
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(938, 445);
    glVertex2i(943, 445);
    glVertex2i(943, 531);
    glVertex2i(938, 531);
    glEnd();


    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(291,412);
    glVertex2i(440,432);
    glEnd();


    //AB3 Field 3rd floor to 1st floor column
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(440,399);
    glVertex2i(440,496);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(435,399);
    glVertex2i(435,496);
    glEnd();

    //AB3 1st floor all windows

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(294, 385);
    glVertex2i(327, 387);
    glVertex2i(327, 412);
    glVertex2i(294, 409);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(340, 391);
    glVertex2i(353, 393);
    glVertex2i(353, 415);
    glVertex2i(340, 412);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(364, 395);
    glVertex2i(392, 397);
    glVertex2i(392, 420);
    glVertex2i(364, 417);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(405, 398);
    glVertex2i(431, 400);
    glVertex2i(431, 425);
    glVertex2i(405, 422);
    glEnd();

    //AB3 2nd floor all windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(294, 420);
    glVertex2i(327, 422);
    glVertex2i(327, 443);
    glVertex2i(294, 440);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(340, 426);
    glVertex2i(353, 428);
    glVertex2i(353, 446);
    glVertex2i(340, 443);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(364, 430);
    glVertex2i(392, 432);
    glVertex2i(392, 451);
    glVertex2i(364, 448);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(405, 433);
    glVertex2i(431, 435);
    glVertex2i(431, 456);
    glVertex2i(405, 452);
    glEnd();

    //AB3 3rd floor all windows
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(294, 455);
    glVertex2i(327, 457);
    glVertex2i(327, 473);
    glVertex2i(294, 471);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(340, 461);
    glVertex2i(353, 463);
    glVertex2i(353, 476);
    glVertex2i(340, 474);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(364, 464);
    glVertex2i(390, 466);
    glVertex2i(390, 483);
    glVertex2i(364, 481);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(405, 467);
    glVertex2i(429, 469);
    glVertex2i(429, 488);
    glVertex2i(405, 486);
    glEnd();


    // DIU Green garden
    glColor3f(0.36, 0.14, 0.73);
    glBegin(GL_POLYGON);
    glVertex2i(800, 385);
    glVertex2i(920, 398);
    glVertex2i(940, 522);
    glVertex2i(775, 510);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(810,385);
    glVertex2i(810,513);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(910,398);
    glVertex2i(910,520);
    glEnd();

    // DIU green garden Line
            glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(429, 469);
    glVertex2i(429, 488);
    glEnd();

                glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(800,385);
    glVertex2i(775,510);
    glEnd();

    // DIU Green garden square shape
    glColor3f(0.79, 0.7, 0.96);
    glBegin(GL_POLYGON);
    glVertex2i(810, 385);
    glVertex2i(910, 398);
    glVertex2i(910, 486);
    glVertex2i(810, 480);
    glEnd();

    // DIU Mosque top Shape rectangle shape
    glColor3f(0.96, 0.62, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(510, 470);
    glVertex2i(610, 477);
    glVertex2i(610, 492);
    glVertex2i(510, 483);
    glEnd();

// Diu Grenn garden First side gate
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(850, 388);
    glVertex2i(875, 390);
    glVertex2i(875, 440);
    glVertex2i(850, 440);
    glEnd();

    // Diu green graden First side
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(850, 388);
    glVertex2i(875, 390);
    glVertex2i(890, 460);
    glVertex2i(835, 457);
    glEnd();


    // DIU Mosque TOP
    glColor3f(0.87, 0.88, 0.84);
    glBegin(GL_POLYGON);
    glVertex2i(768, 510);
    glVertex2i(943, 522);
    glVertex2i(943, 528);
    glVertex2i(768, 518);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(768,510);
    glVertex2i(943,522);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(943,528);
    glVertex2i(768,518);
    glEnd();



    // Basketball field
    glColor3f(0.77, 0.58, 0.03);
    glBegin(GL_POLYGON);
    glVertex2i(910, 260);
    glVertex2i(1000, 290);
    glVertex2i(1000, 395);
    glVertex2i(810, 373);
    glEnd();

// Basketball field line
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(910,260);
    glVertex2i(1000,290);
    glEnd();
    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(1000,395);
    glVertex2i(810,373);
    glEnd();

    glColor3f(0.76, 0.76, 0.76);
    glBegin(GL_LINES);
    glVertex2i(910,260);
    glVertex2i(810,373);
    glEnd();

        glColor3f(1, 1, 1);
    circle(25,25, 1000, 355);

    // Basketball Basket
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(859, 316);
    glVertex2i(861, 290);
    glVertex2i(861, 395);
    glVertex2i(859, 373);
    glEnd();

    // Basketball Basket
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(858, 373);
    glVertex2i(865, 373);
    glVertex2i(865, 375);
    glVertex2i(858, 375);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(1100,300);
    glVertex2i(955,388);
    glEnd();

    glColor3f(0, 0, 0);
    circle(3, 3, 868, 374);

    // Basketball Basket
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex2i(847, 290);
    glVertex2i(876, 298);
    glVertex2i(861, 315);
    glVertex2i(830, 311);
    glEnd();

    //Main Footbal and Cricket Field
    glColor3f(0.31, 0.82, 0.33);
    glBegin(GL_POLYGON);
    glVertex2i(-30, -20);
    glVertex2i(1040, 0);
    glVertex2i(768, 367);
    glVertex2i(191, 300);
    glEnd();

//Main Cricket Field
    glColor3f(0, 0.67, 0.11);
    circle(340, 170, 500, 140);

    // Cricket Pitch
    glColor3f(0.31, 0.82, 0.33);
    glBegin(GL_POLYGON);
    glVertex2i(400, 125);
    glVertex2i(600, 135);
    glVertex2i(610, 175);
    glVertex2i(410, 165);
    glEnd();

    //Cricket Pitch Line
        glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(400,125);
    glVertex2i(600,135);
    glEnd();

        glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(610,175);
    glVertex2i(410,165);
    glEnd();

        glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(400,125);
    glVertex2i(410,165);
    glEnd();

        glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(600,135);
    glVertex2i(610,175);
    glEnd();

    // Left Side Goalpost
glColor3f(1,1,1); // Black color for the goalpost

// Left vertical line of the goalpost
glBegin(GL_LINES);
glVertex2i(170, 230);
glVertex2i(170, 260);
glEnd();

// Right vertical line of the goalpost
glBegin(GL_LINES);
glVertex2i(140, 180);
glVertex2i(140, 220);
glEnd();

// Top horizontal line of the goalpost
glBegin(GL_LINES);
glVertex2i(170, 260);
glVertex2i(140, 220);
glEnd();


//Right Side Golpost
// Left vertical line of the goalpost
glBegin(GL_LINES);
glVertex2i(800, 290);
glVertex2i(800, 320);
glEnd();

// Right vertical line of the goalpost
glBegin(GL_LINES);
glVertex2i(836, 240);
glVertex2i(836, 270);
glEnd();

// Top horizontal line of the goalpost
glBegin(GL_LINES);
glVertex2i(800, 320);
glVertex2i(836, 270);
glEnd();


// Bottom Left side to right side road

    glColor3f(0.97, 0.95, 0.92);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(1000,5);
    glVertex2i(1000, 35);
    glVertex2i(0, 35);
    glEnd();






















    // House (Lights on in night mode)
    if (isNight)
        glColor3f(1.0, 1.0, 0.6); // Warm glowing yellow
    else
        glColor3f(0.97, 0.74, 0.4); //
            // Car
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(p + 5, 21);
    glVertex2i(p + 11, 21);
    glVertex2i(p + 14, 28);
    glVertex2i(p + 28, 28);
    glVertex2i(p + 34, 21);
    glVertex2i(p + 39, 21);
    glVertex2i(p + 39, 14);
    glVertex2i(p + 5, 14);
    glEnd();

//Car windows
    glColor3f(0.5, 0.8, 1.0);
glBegin(GL_POLYGON);
glVertex2i(p + 15, 22);
glVertex2i(p + 27, 22);
glVertex2i(p + 26, 26);
glVertex2i(p + 16, 26);
glEnd();


    glColor3f(0, 0, 1);
    circle(4, 4, p + 12, 14);
    circle(4, 4, p + 32, 14);

    // Right to left 1st tree bottom
        int z = 100;
    glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(680 + z, 0, 0);
glVertex3f(685 + z, 0, 0);
glVertex3f(685 + z, 20, 0);
glVertex3f(680 + z, 20, 0);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(675 + z, 10, 0);
glVertex3f(690 + z, 10, 0);
glVertex3f(682.5 + z, 40, 0);
glVertex3f(682.5 + z, 40, 0);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(676 + z, 15, 0);
glVertex3f(689 + z, 15, 0);
glVertex3f(682.5 + z, 45, 0);
glVertex3f(682.5 + z, 45, 0);
glEnd();


//Right to left 2nd tree bottom
    int a = 200;
    glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(680 + a, 0, 0);
glVertex3f(685 + a, 0, 0);
glVertex3f(685 + a, 20, 0);
glVertex3f(680 + a, 20, 0);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(675 + a, 10, 0);
glVertex3f(690 + a, 10, 0);
glVertex3f(682.5 + a, 40, 0);
glVertex3f(682.5 + a, 40, 0);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(676 + a, 15, 0);
glVertex3f(689 + a, 15, 0);
glVertex3f(682.5 + a, 45, 0);
glVertex3f(682.5 + a, 45, 0);
glEnd();

// Right to left 3rd tree bottom
        glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex3f(680,0,0);
    glVertex3f(685,0,0);
    glVertex3f(685,20,0);
    glVertex3f(680,20,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(675,10,0);
    glVertex3f(690,10,0);
    glVertex3f(682.5,40,0);
    glVertex3f(682.5,40,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(676,15,0);
    glVertex3f(689,15,0);
    glVertex3f(682.5,45,0);
    glVertex3f(682.5,45,0);
    glEnd();

// Right to left 4th tree bottom
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex3f(580,0,0);
    glVertex3f(585,0,0);
    glVertex3f(585,20,0);
    glVertex3f(580,20,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(575,10,0);
    glVertex3f(590,10,0);
    glVertex3f(582.5,40,0);
    glVertex3f(582.5,40,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(576,15,0);
    glVertex3f(589,15,0);
    glVertex3f(582.5,45,0);
    glVertex3f(582.5,45,0);
    glEnd();

//Right to left 5th tree bottom
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex3f(480,0,0);
    glVertex3f(485,0,0);
    glVertex3f(485,20,0);
    glVertex3f(480,20,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(475,10,0);
    glVertex3f(490,10,0);
    glVertex3f(482.5,40,0);
    glVertex3f(482.5,40,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(476,15,0);
    glVertex3f(489,15,0);
    glVertex3f(482.5,45,0);
    glVertex3f(482.5,45,0);
    glEnd();

//Right to left 6th tree bottom
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex3f(380,0,0);
    glVertex3f(385,0,0);
    glVertex3f(385,20,0);
    glVertex3f(380,20,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(375,10,0);
    glVertex3f(390,10,0);
    glVertex3f(382.5,40,0);
    glVertex3f(382.5,40,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(376,15,0);
    glVertex3f(389,15,0);
    glVertex3f(382.5,45,0);
    glVertex3f(382.5,45,0);
    glEnd();

//Right to left 7th tree bottom
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex3f(280,0,0);
    glVertex3f(285,0,0);
    glVertex3f(285,20,0);
    glVertex3f(280,20,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(275,10,0);
    glVertex3f(290,10,0);
    glVertex3f(282.5,40,0);
    glVertex3f(282.5,40,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(276,15,0);
    glVertex3f(289,15,0);
    glVertex3f(282.5,45,0);
    glVertex3f(282.5,45,0);
    glEnd();

//Right to left 8th tree bottom
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex3f(180,0,0);
    glVertex3f(185,0,0);
    glVertex3f(185,20,0);
    glVertex3f(180,20,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(175,10,0);
    glVertex3f(190,10,0);
    glVertex3f(182.5,40,0);
    glVertex3f(182.5,40,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(176,15,0);
    glVertex3f(189,15,0);
    glVertex3f(182.5,45,0);
    glVertex3f(182.5,45,0);
    glEnd();

//Right to left 9th tree bottom
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75,35,5);
    glVertex3f(80,0,0);
    glVertex3f(85,0,0);
    glVertex3f(85,20,0);
    glVertex3f(80,20,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(75,10,0);
    glVertex3f(90,10,0);
    glVertex3f(82.5,40,0);
    glVertex3f(82.5,40,0);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex3f(76,15,0);
    glVertex3f(89,15,0);
    glVertex3f(82.5,45,0);
    glVertex3f(82.5,45,0);
    glEnd();



// Field Top 1st TREE Trunk right side
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(765,364);
    glVertex2f(769,363);
    glVertex2f(770,373);
    glVertex2f(762,403);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(765,364);
    glVertex2f(769,363);
    glVertex2f(767,372);
    glVertex2f(758,383);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(765,364);
    glVertex2f(767,363);
    glVertex2f(770,373);
    glVertex2f(770,403);
    glEnd();


// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(765, 364);
glVertex2f(769, 363);
glVertex2f(770, 373);
glVertex2f(762, 403);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 764, 404);
circle(5, 12, 759, 414);
circle(5, 12, 769, 414);
circle(5, 12, 774, 409);
circle(5, 12, 754, 424);

// Light Brown Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 758, 428);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 761, 428);
circle(5, 12, 763, 436);
circle(5, 10, 758, 431);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 760, 429);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 761, 424);
circle(8, 12, 773, 422);
circle(8, 12, 768, 422);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 767, 417);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 766, 416);
circle(8, 12, 778, 412);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 773, 407);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 770, 405);
circle(10, 14, 761, 408);
circle(10, 14, 773, 430);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 768, 418);
circle(1, 2, 768, 432);
circle(1, 2, 778, 432);
circle(1, 2, 757, 418);
circle(1, 2.5, 763, 433);
circle(1, 1.5, 764, 419);
circle(1, 2.5, 778, 415);
circle(1, 3, 773, 412);


///////////////////// Left side tree
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(191, 300);
glVertex2f(195, 299);
glVertex2f(197, 310);
glVertex2f(187, 340);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(191, 300);
glVertex2f(195, 299);
glVertex2f(193, 308);
glVertex2f(184, 320);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(191, 300);
glVertex2f(193, 299);
glVertex2f(197, 310);
glVertex2f(197, 340);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 190, 345);
circle(5, 12, 185, 355);
circle(5, 12, 195, 355);
circle(5, 12, 200, 350);
circle(5, 12, 180, 360);

// Light Brown Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 184, 364);
circle(5, 12, 186, 364);
circle(5, 12, 188, 372);
circle(5, 10, 184, 367);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 186, 365);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 187, 360);
circle(8, 12, 199, 358);
circle(8, 12, 194, 358);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 193, 353);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 192, 352);
circle(8, 12, 204, 348);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 199, 343);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 197, 340);
circle(10, 14, 187, 343);
circle(10, 14, 199, 365);

// Pinkish Flowers (Adjusted with Leaves)
glColor3ub(227, 91, 137);
circle(1, 2, 194, 355);
circle(1, 2, 194, 370);
circle(1, 2, 204, 370);
circle(1, 2, 183, 356);
circle(1, 2.5, 189, 368);
circle(1, 1.5, 190, 354);
circle(1, 2.5, 204, 350);
circle(1, 3, 199, 345);

////////////AB3 Field Tree
// Field Top 1st TREE Trunk right side
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(290, 330);
glVertex2f(294, 329);
glVertex2f(295, 339);
glVertex2f(287, 369);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(290, 330);
glVertex2f(292, 329);
glVertex2f(295, 339);
glVertex2f(295, 369);
glEnd();

// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(290, 330);
glVertex2f(294, 329);
glVertex2f(295, 339);
glVertex2f(287, 369);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 289, 370);
circle(5, 12, 284, 380);
circle(5, 12, 294, 380);
circle(5, 12, 299, 375);
circle(5, 12, 279, 390);

// Light Brown Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 283, 394);
circle(5, 12, 286, 394);
circle(5, 12, 288, 402);
circle(5, 10, 283, 397);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 285, 395);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 286, 390);
circle(8, 12, 298, 388);
circle(8, 12, 293, 388);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 292, 383);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 291, 382);
circle(8, 12, 303, 378);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 298, 373);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 295, 371);
circle(10, 14, 286, 374);
circle(10, 14, 298, 396);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 293, 384);
circle(1, 2, 293, 398);
circle(1, 2, 303, 398);
circle(1, 2, 282, 384);
circle(1, 2.5, 288, 399);
circle(1, 1.5, 289, 385);
circle(1, 2.5, 303, 381);
circle(1, 3, 298, 378);

//////////
// Field Top 1st TREE Trunk right side
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(320, 330);
glVertex2f(324, 329);
glVertex2f(325, 339);
glVertex2f(317, 369);
glEnd();



glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(320, 330);
glVertex2f(322, 329);
glVertex2f(325, 339);
glVertex2f(325, 369);
glEnd();

// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(320, 330);
glVertex2f(324, 329);
glVertex2f(325, 339);
glVertex2f(317, 369);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 319, 370);
circle(5, 12, 314, 380);
circle(5, 12, 324, 380);
circle(5, 12, 329, 375);
circle(5, 12, 309, 390);

// Light Brown Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 313, 394);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 316, 394);
circle(5, 12, 318, 402);
circle(5, 10, 313, 397);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 315, 395);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 316, 390);
circle(8, 12, 328, 388);
circle(8, 12, 323, 388);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 322, 383);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 321, 382);
circle(8, 12, 333, 378);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 328, 373);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 325, 371);
circle(10, 14, 316, 374);
circle(10, 14, 328, 396);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 323, 384);
circle(1, 2, 323, 398);
circle(1, 2, 333, 398);
circle(1, 2, 312, 384);
circle(1, 2.5, 318, 399);
circle(1, 1.5, 319, 385);
circle(1, 2.5, 333, 381);
circle(1, 3, 328, 378);

///////////////
// Field Top 1st TREE Trunk Right Side
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(355, 335);
glVertex2f(359, 334);
glVertex2f(360, 344);
glVertex2f(352, 374);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(355, 335);
glVertex2f(357, 334);
glVertex2f(360, 344);
glVertex2f(360, 374);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 354, 375);
circle(5, 12, 349, 385);
circle(5, 12, 359, 385);
circle(5, 12, 364, 380);
circle(5, 12, 344, 395);

// Light Brown Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 348, 399);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 351, 399);
circle(5, 12, 353, 407);
circle(5, 10, 348, 402);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 350, 400);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 351, 395);
circle(8, 12, 363, 393);
circle(8, 12, 358, 393);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 357, 388);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 356, 387);
circle(8, 12, 368, 383);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 363, 378);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 360, 376);
circle(10, 14, 351, 379);
circle(10, 14, 363, 401);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 358, 389);
circle(1, 2, 358, 403);
circle(1, 2, 368, 403);
circle(1, 2, 347, 389);
circle(1, 2.5, 353, 404);
circle(1, 1.5, 354, 390);
circle(1, 2.5, 368, 386);
circle(1, 3, 363, 383);

    // House Base
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(365, 336);
    glVertex2i(380, 338);
    glVertex2i(380, 357);
    glVertex2i(365, 357);
    glEnd();

    // Roof
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(364, 357);
    glVertex2i(382, 357);
    glVertex2i(372.5, 367);
    glEnd();

    /////////////
    // Field Top 1st TREE Trunk right side
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(417, 341);
glVertex2f(421, 340);
glVertex2f(423, 350);
glVertex2f(415, 375);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(417, 340);
glVertex2f(419, 339);
glVertex2f(423, 349);
glVertex2f(423, 375);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 416, 380);
circle(5, 12, 411, 390);
circle(5, 12, 421, 390);
circle(5, 12, 426, 385);
circle(5, 12, 406, 400);

// Light Brown Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 408, 404);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 411, 404);
circle(5, 12, 413, 412);
circle(5, 10, 408, 407);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 410, 405);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 411, 400);
circle(8, 12, 423, 398);
circle(8, 12, 418, 398);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 417, 393);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 416, 392);
circle(8, 12, 428, 388);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 423, 383);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 420, 381);
circle(10, 14, 411, 384);
circle(10, 14, 423, 406);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 418, 394);
circle(1, 2, 418, 408);
circle(1, 2, 428, 408);
circle(1, 2, 407, 394);
circle(1, 2.5, 413, 409);
circle(1, 1.5, 414, 395);
circle(1, 2.5, 428, 391);
circle(1, 3, 423, 388);


///////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(440, 345);
glVertex2f(444, 344);
glVertex2f(445, 354);
glVertex2f(437, 384);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(440, 345);
glVertex2f(444, 344);
glVertex2f(442, 353);
glVertex2f(433, 364);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(440, 345);
glVertex2f(442, 344);
glVertex2f(445, 354);
glVertex2f(445, 384);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 441, 385);
circle(5, 12, 436, 395);
circle(5, 12, 446, 395);
circle(5, 12, 451, 390);
circle(5, 12, 431, 405);

// Light Brown Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 431, 409);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 434, 409);
circle(5, 12, 436, 417);
circle(5, 10, 431, 412);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 433, 410);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 434, 405);
circle(8, 12, 446, 403);
circle(8, 12, 441, 403);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 440, 398);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 439, 397);
circle(8, 12, 451, 393);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 446, 388);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 443, 385);
circle(10, 14, 434, 388);
circle(10, 14, 446, 410);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 441, 393);
circle(1, 2, 441, 407);
circle(1, 2, 451, 407);
circle(1, 2, 430, 393);
circle(1, 2.5, 436, 408);
circle(1, 1.5, 437, 394);
circle(1, 2.5, 451, 390);
circle(1, 3, 446, 387);
circle(1, 3, 436, 391);

//////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(465, 380);
glVertex2f(469, 379);
glVertex2f(470, 389);
glVertex2f(462, 409);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(465, 380);
glVertex2f(469, 379);
glVertex2f(467, 388);
glVertex2f(458, 399);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(465, 380);
glVertex2f(467, 379);
glVertex2f(470, 389);
glVertex2f(470, 409);
glEnd();

// Leaves with Different Colors
glColor3f(0.15, 0.86, 0.18);
circle(3, 6, 464, 410);
circle(5, 12, 459, 420);
circle(5, 12, 469, 420);
circle(5, 12, 474, 415);
circle(5, 12, 454, 430);

glColor3f(0.15, 0.86, 0.18);
circle(5, 12, 458, 434);
glColor3f(0.15, 0.86, 0.18);
circle(5, 12, 461, 434);
circle(5, 12, 463, 442);
circle(5, 10, 458, 437);
glColor3f(0.23, 0.97, 0.27);
circle(5, 10, 460, 435);

glColor3f(0.15, 0.86, 0.18);
circle(7, 10, 461, 430);
circle(8, 12, 473, 428);
circle(8, 12, 468, 428);
glColor3f(0.15, 0.86, 0.18);
circle(8, 12, 467, 423);
glColor3f(0.15, 0.86, 0.18);
circle(8, 12, 466, 422);
circle(8, 12, 478, 418);
glColor3f(0.15, 0.86, 0.18);
circle(8, 12, 473, 413);
glColor3f(0.15, 0.86, 0.18);
circle(10, 14, 470, 411);
circle(10, 14, 461, 414);
circle(10, 14, 473, 433);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 468, 423);
circle(1, 2, 468, 437);
circle(1, 2, 478, 437);
circle(1, 2, 457, 423);
circle(1, 2.5, 463, 438);
circle(1, 1.5, 464, 414);
circle(1, 2.5, 478, 409);
circle(1, 3, 473, 406);
circle(1, 3, 463, 420);

/////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(470, 350);
glVertex2f(474, 349);
glVertex2f(475, 359);
glVertex2f(467, 389);
glEnd();


glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(470, 350);
glVertex2f(472, 349);
glVertex2f(475, 359);
glVertex2f(475, 389);
glEnd();

// Leaves with Different Colors
glColor3f(0.15, 0.86, 0.18);
circle(3, 6, 462, 390);
circle(5, 12, 457, 400);
circle(5, 12, 467, 400);
circle(5, 12, 472, 395);
circle(5, 12, 452, 410);

// Light Brown Leaves
glColor3f(0.15, 0.86, 0.18);
circle(5, 12, 456, 414);
glColor3f(0.15, 0.86, 0.18);
circle(5, 12, 459, 414);
circle(5, 12, 461, 422);
circle(5, 10, 456, 417);
glColor3f(0.15, 0.86, 0.18);
circle(5, 10, 458, 415);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 459, 410);
circle(8, 12, 471, 408);
circle(8, 12, 466, 408);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 465, 403);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 464, 402);
circle(8, 12, 476, 398);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 471, 393);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 468, 390);
circle(10, 14, 459, 393);
circle(10, 14, 471, 415);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 466, 403);
circle(1, 2, 466, 417);
circle(1, 2, 476, 417);
circle(1, 2, 455, 403);
circle(1, 2.5, 461, 418);
circle(1, 1.5, 462, 404);
circle(1, 2.5, 476, 399);
circle(1, 3, 471, 396);
circle(1, 3, 461, 410);

////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(640, 380);
glVertex2f(644, 379);
glVertex2f(645, 389);
glVertex2f(637, 409);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(640, 380);
glVertex2f(644, 379);
glVertex2f(642, 388);
glVertex2f(633, 399);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(640, 380);
glVertex2f(642, 379);
glVertex2f(645, 389);
glVertex2f(645, 409);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 639, 410);
circle(5, 12, 634, 420);
circle(5, 12, 644, 420);
circle(5, 12, 649, 415);
circle(5, 12, 629, 430);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 633, 434);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 636, 434);
circle(5, 12, 638, 442);
circle(5, 10, 633, 437);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 635, 435);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 636, 429);
circle(8, 12, 648, 427);
circle(8, 12, 643, 427);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 642, 422);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 641, 421);
circle(8, 12, 653, 417);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 648, 412);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 645, 411);
circle(10, 14, 636, 414);
circle(10, 14, 648, 436);

// Pinkish Flowers (Adjusted)
glColor3ub(227, 91, 137);
circle(1, 2, 643, 418);
circle(1, 2, 643, 432);
circle(1, 2, 653, 432);
circle(1, 2, 632, 418);
circle(1, 2.5, 638, 433);
circle(1, 1.5, 639, 419);
circle(1, 2.5, 653, 414);
circle(1, 3, 648, 411);


////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(630, 370);
glVertex2f(634, 369);
glVertex2f(635, 379);
glVertex2f(627, 409);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(630, 370);
glVertex2f(634, 369);
glVertex2f(632, 378);
glVertex2f(623, 389);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(630, 370);
glVertex2f(632, 369);
glVertex2f(635, 379);
glVertex2f(635, 409);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 629, 410);
circle(5, 12, 624, 420);
circle(5, 12, 634, 420);
circle(5, 12, 639, 415);
circle(5, 12, 619, 430);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 623, 434);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 626, 434);
circle(5, 12, 628, 442);
circle(5, 10, 623, 437);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 625, 435);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 626, 430);
circle(8, 12, 638, 428);
circle(8, 12, 633, 428);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 632, 423);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 631, 422);
circle(8, 12, 643, 418);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 638, 413);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 635, 410);
circle(10, 14, 626, 413);
circle(10, 14, 638, 433);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 633, 423);
circle(1, 2, 633, 437);
circle(1, 2, 643, 437);
circle(1, 2, 622, 423);
circle(1, 2.5, 628, 438);
circle(1, 1.5, 629, 424);
circle(1, 2.5, 643, 419);
circle(1, 3, 638, 416);
circle(1, 3, 628, 420);

/////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(670, 375);
glVertex2f(674, 374);
glVertex2f(675, 384);
glVertex2f(667, 414);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(670, 375);
glVertex2f(674, 374);
glVertex2f(672, 383);
glVertex2f(663, 394);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(670, 375);
glVertex2f(672, 374);
glVertex2f(675, 384);
glVertex2f(675, 414);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 669, 415);
circle(5, 12, 664, 425);
circle(5, 12, 674, 425);
circle(5, 12, 679, 420);
circle(5, 12, 659, 435);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 663, 439);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 666, 439);
circle(5, 12, 668, 447);
circle(5, 10, 663, 442);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 665, 440);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 666, 435);
circle(8, 12, 678, 433);
circle(8, 12, 673, 433);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 672, 428);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 671, 427);
circle(8, 12, 683, 423);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 678, 418);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 675, 415);
circle(10, 14, 666, 418);
circle(10, 14, 678, 438);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 673, 428);
circle(1, 2, 673, 442);
circle(1, 2, 683, 442);
circle(1, 2, 662, 428);
circle(1, 2.5, 668, 443);
circle(1, 1.5, 669, 429);
circle(1, 2.5, 683, 424);
circle(1, 3, 678, 421);
circle(1, 3, 668, 425);

///////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(700, 380);
glVertex2f(704, 379);
glVertex2f(705, 389);
glVertex2f(697, 419);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(700, 380);
glVertex2f(704, 379);
glVertex2f(702, 388);
glVertex2f(693, 399);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(700, 380);
glVertex2f(702, 379);
glVertex2f(705, 389);
glVertex2f(705, 419);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 699, 420);
circle(5, 12, 694, 430);
circle(5, 12, 704, 430);
circle(5, 12, 709, 425);
circle(5, 12, 689, 440);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 693, 444);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 696, 444);
circle(5, 12, 698, 452);
circle(5, 10, 693, 447);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 695, 445);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 696, 440);
circle(8, 12, 708, 438);
circle(8, 12, 703, 438);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 702, 433);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 701, 432);
circle(8, 12, 713, 428);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 708, 423);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 705, 420);
circle(10, 14, 696, 423);
circle(10, 14, 708, 443);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 703, 433);
circle(1, 2, 703, 447);
circle(1, 2, 713, 447);
circle(1, 2, 692, 433);
circle(1, 2.5, 698, 448);
circle(1, 1.5, 699, 434);
circle(1, 2.5, 713, 429);
circle(1, 3, 708, 426);
circle(1, 3, 698, 430);

//////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(730, 385);
glVertex2f(734, 384);
glVertex2f(735, 394);
glVertex2f(727, 424);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(730, 385);
glVertex2f(734, 384);
glVertex2f(732, 393);
glVertex2f(723, 404);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(730, 385);
glVertex2f(732, 384);
glVertex2f(735, 394);
glVertex2f(735, 424);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 729, 425);
circle(5, 12, 724, 435);
circle(5, 12, 734, 435);
circle(5, 12, 739, 430);
circle(5, 12, 719, 445);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 723, 449);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 726, 449);
circle(5, 12, 728, 457);
circle(5, 10, 723, 452);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 725, 450);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 726, 445);
circle(8, 12, 738, 443);
circle(8, 12, 733, 443);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 732, 438);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 731, 437);
circle(8, 12, 743, 433);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 738, 428);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 735, 425);
circle(10, 14, 726, 428);
circle(10, 14, 738, 448);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 733, 438);
circle(1, 2, 733, 452);
circle(1, 2, 743, 452);
circle(1, 2, 722, 438);
circle(1, 2.5, 728, 453);
circle(1, 1.5, 729, 439);
circle(1, 2.5, 743, 434);
circle(1, 3, 738, 431);
circle(1, 3, 728, 435);


////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(930, 398);
glVertex2f(934, 397);
glVertex2f(935, 407);
glVertex2f(927, 437);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(930, 398);
glVertex2f(934, 397);
glVertex2f(932, 406);
glVertex2f(923, 417);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(930, 398);
glVertex2f(932, 397);
glVertex2f(935, 407);
glVertex2f(935, 437);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 929, 438);
circle(5, 12, 924, 448);
circle(5, 12, 934, 448);
circle(5, 12, 939, 443);
circle(5, 12, 919, 458);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 923, 462);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 926, 462);
circle(5, 12, 928, 470);
circle(5, 10, 923, 465);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 925, 463);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 926, 458);
circle(8, 12, 938, 456);
circle(8, 12, 933, 456);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 932, 451);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 931, 450);
circle(8, 12, 943, 446);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 938, 441);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 935, 438);
circle(10, 14, 926, 441);
circle(10, 14, 938, 461);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 933, 451);
circle(1, 2, 933, 465);
circle(1, 2, 943, 465);
circle(1, 2, 922, 451);
circle(1, 2.5, 928, 466);
circle(1, 1.5, 929, 452);
circle(1, 2.5, 943, 447);
circle(1, 3, 938, 444);
circle(1, 3, 928, 448);

/////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(960, 403);
glVertex2f(964, 402);
glVertex2f(965, 412);
glVertex2f(957, 442);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(960, 403);
glVertex2f(964, 402);
glVertex2f(962, 411);
glVertex2f(953, 422);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(960, 403);
glVertex2f(962, 402);
glVertex2f(965, 412);
glVertex2f(965, 442);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 959, 443);
circle(5, 12, 954, 453);
circle(5, 12, 964, 453);
circle(5, 12, 969, 448);
circle(5, 12, 949, 463);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 953, 467);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 956, 467);
circle(5, 12, 958, 475);
circle(5, 10, 953, 470);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 955, 468);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 956, 463);
circle(8, 12, 968, 461);
circle(8, 12, 963, 461);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 962, 456);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 961, 455);
circle(8, 12, 973, 451);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 968, 446);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 965, 443);
circle(10, 14, 956, 446);
circle(10, 14, 968, 466);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 963, 456);
circle(1, 2, 963, 470);
circle(1, 2, 973, 470);
circle(1, 2, 952, 456);
circle(1, 2.5, 958, 471);
circle(1, 1.5, 959, 457);
circle(1, 2.5, 973, 452);
circle(1, 3, 968, 449);
circle(1, 3, 958, 453);

///////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(985, 407);
glVertex2f(989, 406);
glVertex2f(990, 416);
glVertex2f(982, 446);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(985, 407);
glVertex2f(989, 406);
glVertex2f(987, 415);
glVertex2f(978, 426);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(985, 407);
glVertex2f(987, 406);
glVertex2f(990, 416);
glVertex2f(990, 446);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 984, 447);
circle(5, 12, 979, 457);
circle(5, 12, 989, 457);
circle(5, 12, 994, 452);
circle(5, 12, 974, 467);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 978, 471);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 981, 471);
circle(5, 12, 983, 479);
circle(5, 10, 978, 474);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 980, 472);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 981, 467);
circle(8, 12, 993, 465);
circle(8, 12, 988, 465);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 987, 460);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 986, 459);
circle(8, 12, 998, 455);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 993, 450);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 990, 447);
circle(10, 14, 981, 450);
circle(10, 14, 993, 470);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 988, 460);
circle(1, 2, 988, 474);
circle(1, 2, 998, 474);
circle(1, 2, 977, 460);
circle(1, 2.5, 983, 475);
circle(1, 1.5, 984, 461);
circle(1, 2.5, 998, 456);
circle(1, 3, 993, 453);
circle(1, 3, 983, 457);

///////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(718, 357, 0);
glVertex3f(723, 357, 0);
glVertex3f(723, 377, 0);
glVertex3f(718, 377, 0);
glEnd();

// Bottom Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(713, 367, 0);
glVertex3f(728, 367, 0);
glVertex3f(720.5, 397, 0);
glVertex3f(720.5, 397, 0);
glEnd();

// Middle Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(714, 372, 0);
glVertex3f(727, 372, 0);
glVertex3f(720.5, 402, 0);
glVertex3f(720.5, 402, 0);
glEnd();

///////

// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(658, 352, 0);
glVertex3f(663, 352, 0);
glVertex3f(663, 372, 0);
glVertex3f(658, 372, 0);
glEnd();

// Bottom Leaf Section
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(653, 362, 0);
glVertex3f(668, 362, 0);
glVertex3f(660.5, 392, 0);
glVertex3f(660.5, 392, 0);
glEnd();

// Top Leaf Section
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(654, 367, 0);
glVertex3f(667, 367, 0);
glVertex3f(660.5, 397, 0);
glVertex3f(660.5, 397, 0);
glEnd();

////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(598, 347, 0);
glVertex3f(603, 347, 0);
glVertex3f(603, 367, 0);
glVertex3f(598, 367, 0);
glEnd();

// Tree Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(593, 357, 0);
glVertex3f(608, 357, 0);
glVertex3f(600, 387, 0);
glVertex3f(600, 387, 0);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(594, 362, 0);
glVertex3f(607, 362, 0);
glVertex3f(600, 397, 0);
glVertex3f(600, 397, 0);
glEnd();

/////////
// Tree Trunk at
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(538, 337, 0);
glVertex3f(543, 337, 0);
glVertex3f(543, 357, 0);
glVertex3f(538, 357, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(533, 347, 0);
glVertex3f(548, 347, 0);
glVertex3f(540.5, 377, 0);
glVertex3f(540.5, 377, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(534, 352, 0);
glVertex3f(547, 352, 0);
glVertex3f(540.5, 382, 0);
glVertex3f(540.5, 382, 0);
glEnd();

///////////////
// Bottom Tree
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(478, 330, 0);
glVertex3f(483, 330, 0);
glVertex3f(483, 350, 0);
glVertex3f(478, 350, 0);
glEnd();

// Bottom Tree 1
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(473, 340, 0);
glVertex3f(488, 340, 0);
glVertex3f(480.5, 370, 0);
glEnd();

// Bottom Tree 1
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(474, 345, 0);
glVertex3f(487, 345, 0);
glVertex3f(480.5, 375, 0);
glEnd();


////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(418, 323, 0);
glVertex3f(423, 323, 0);
glVertex3f(423, 343, 0);
glVertex3f(418, 343, 0);
glEnd();

// Bottom Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(413, 333, 0);
glVertex3f(428, 333, 0);
glVertex3f(420.5, 363, 0);
glVertex3f(420.5, 363, 0);
glEnd();

// Middle Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(414, 338, 0);
glVertex3f(427, 338, 0);
glVertex3f(420.5, 368, 0);
glVertex3f(420.5, 368, 0);
glEnd();

///////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(358, 316, 0);
glVertex3f(363, 316, 0);
glVertex3f(363, 336, 0);
glVertex3f(358, 336, 0);
glEnd();

// Bottom Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(353, 326, 0);
glVertex3f(368, 326, 0);
glVertex3f(360.5, 356, 0);
glVertex3f(360.5, 356, 0);
glEnd();

// Middle Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(354, 331, 0);
glVertex3f(367, 331, 0);
glVertex3f(360.5, 361, 0);
glVertex3f(360.5, 361, 0);
glEnd();

/////////
// Bottom tree trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(298, 309, 0);
glVertex3f(303, 309, 0);
glVertex3f(303, 329, 0);
glVertex3f(298, 329, 0);
glEnd();

// Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(293, 319, 0);
glVertex3f(308, 319, 0);
glVertex3f(300.5, 349, 0);
glVertex3f(300.5, 349, 0);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(294, 324, 0);
glVertex3f(307, 324, 0);
glVertex3f(300.5, 354, 0);
glVertex3f(300.5, 354, 0);
glEnd();

///////////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75,35,5);
glVertex3f(248,303,0);
glVertex3f(253,303,0);
glVertex3f(253,323,0);
glVertex3f(248,323,0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(243,313,0);
glVertex3f(258,313,0);
glVertex3f(250.5,343,0);
glVertex3f(250.5,343,0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(244,318,0);
glVertex3f(257,318,0);
glVertex3f(250.5,348,0);
glVertex3f(250.5,348,0);
glEnd();

///////////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(145, 230, 0);
glVertex3f(150, 230, 0);
glVertex3f(150, 250, 0);
glVertex3f(145, 250, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(140, 240, 0);
glVertex3f(155, 240, 0);
glVertex3f(150, 270, 0);
glVertex3f(150, 270, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(141, 245, 0);
glVertex3f(154, 245, 0);
glVertex3f(150, 275, 0);
glVertex3f(150, 275, 0);
glEnd();

////////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75,35,5);
glVertex3f(167.5,265,0);
glVertex3f(172.5,265,0);
glVertex3f(172.5,285,0);
glVertex3f(167.5,285,0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(162.5,275,0);
glVertex3f(177.5,275,0);
glVertex3f(170,305,0);
glVertex3f(170,305,0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(163,280,0);
glVertex3f(176,280,0);
glVertex3f(170,310,0);
glVertex3f(170,310,0);
glEnd();

//////////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(122.5, 195, 0);
glVertex3f(127.5, 195, 0);
glVertex3f(127.5, 215, 0);
glVertex3f(122.5, 215, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(117.5, 205, 0);
glVertex3f(132.5, 205, 0);
glVertex3f(125, 235, 0);
glVertex3f(125, 235, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(118, 210, 0);
glVertex3f(131, 210, 0);
glVertex3f(125, 240, 0);
glVertex3f(125, 240, 0);
glEnd();

//////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(100, 160, 0);
glVertex3f(105, 160, 0);
glVertex3f(105, 180, 0);
glVertex3f(100, 180, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(95, 170, 0);
glVertex3f(110, 170, 0);
glVertex3f(102.5, 200, 0);
glVertex3f(102.5, 200, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(96, 175, 0);
glVertex3f(109, 175, 0);
glVertex3f(102.5, 205, 0);
glVertex3f(102.5, 205, 0);
glEnd();

//////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(77.5, 125, 0);
glVertex3f(82.5, 125, 0);
glVertex3f(82.5, 145, 0);
glVertex3f(77.5, 145, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(72.5, 135, 0);
glVertex3f(87.5, 135, 0);
glVertex3f(80, 165, 0);
glVertex3f(80, 165, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(73, 140, 0);
glVertex3f(86, 140, 0);
glVertex3f(80, 170, 0);
glVertex3f(80, 170, 0);
glEnd();

//////////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(52, 90, 0);
glVertex3f(57, 90, 0);
glVertex3f(57, 110, 0);
glVertex3f(52, 110, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(47, 100, 0);
glVertex3f(62, 100, 0);
glVertex3f(54.5, 130, 0);
glVertex3f(54.5, 130, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(48, 105, 0);
glVertex3f(61, 105, 0);
glVertex3f(54.5, 135, 0);
glVertex3f(54.5, 135, 0);
glEnd();

///////////////////
// Bottom Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(26.5, 55, 0);
glVertex3f(31.5, 55, 0);
glVertex3f(31.5, 75, 0);
glVertex3f(26.5, 75, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(21.5, 65, 0);
glVertex3f(36.5, 65, 0);
glVertex3f(26.5, 95, 0);
glVertex3f(26.5, 95, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(22, 70, 0);
glVertex3f(36, 70, 0);
glVertex3f(26.5, 100, 0);
glVertex3f(26.5, 100, 0);
glEnd();

//////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex3f(15, 40, 0);
glVertex3f(20, 40, 0);
glVertex3f(20, 60, 0);
glVertex3f(15, 60, 0);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(10, 50, 0);
glVertex3f(25, 50, 0);
glVertex3f(17.5, 80, 0);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(11, 55, 0);
glVertex3f(24, 55, 0);
glVertex3f(17.5, 85, 0);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0, 102, 0);
glVertex3f(12, 60, 0);
glVertex3f(23, 60, 0);
glVertex3f(17.5, 90, 0);
glEnd();

/////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(808, 370);
    glVertex2f(812, 370);
    glVertex2f(812, 400);
    glVertex2f(808, 400);
    glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(795, 400);
    glVertex2f(825, 400);
    glVertex2f(810, 440);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(798, 420);
    glVertex2f(822, 420);
    glVertex2f(810, 460);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(800, 440);
    glVertex2f(820, 440);
    glVertex2f(810, 480);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 810, 435);
circle(1.5, 2, 815, 450);
circle(1.5, 2, 805, 450);
circle(1.5, 2, 810, 470);

//////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(818, 350);
glVertex2f(822, 350);
glVertex2f(822, 380);
glVertex2f(818, 380);
glEnd();

// FirstLayer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(805, 380);
glVertex2f(835, 380);
glVertex2f(820, 440);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(810, 410);
glVertex2f(830, 410);
glVertex2f(820, 470);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLE_FAN);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(815, 440);
glVertex2f(825, 440);
glVertex2f(820, 500);
glEnd();

////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);  // Brown trunk
    glVertex2f(838, 330);
    glVertex2f(842, 330);
    glVertex2f(842, 360);
    glVertex2f(838, 360);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12); // Green Leaves
    glVertex2f(825, 360);
    glVertex2f(855, 360);
    glVertex2f(840, 400);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(828, 380);
    glVertex2f(852, 380);
    glVertex2f(840, 420);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(830, 400);
    glVertex2f(850, 400);
    glVertex2f(840, 440);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 840, 395);
circle(1.5, 2, 845, 410);
circle(1.5, 2, 835, 410);
circle(1.5, 2, 840, 430);

////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(869, 290);
    glVertex2f(873, 290);
    glVertex2f(873, 320);
    glVertex2f(869, 320);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(860, 320);
    glVertex2f(880, 320);
    glVertex2f(869, 360);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(863, 340);
    glVertex2f(877, 340);
    glVertex2f(869, 380);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(865, 360);
    glVertex2f(875, 360);
    glVertex2f(869, 400);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 869, 350);
circle(1.5, 2, 874, 365);
circle(1.5, 2, 864, 365);
circle(1.5, 2, 869, 385);

//////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(887, 270);
    glVertex2f(891, 270);
    glVertex2f(891, 300);
    glVertex2f(887, 300);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(875, 300);
    glVertex2f(905, 300);
    glVertex2f(890, 340);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(878, 320);
    glVertex2f(902, 320);
    glVertex2f(890, 360);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(880, 340);
    glVertex2f(900, 340);
    glVertex2f(890, 380);
glEnd();

// Pinkish Flowers on the Leaves
glColor3ub(227, 91, 137);
circle(1.5, 2, 890, 325);
circle(1.5, 2, 895, 335);
circle(1.5, 2, 885, 335);
circle(1.5, 2, 890, 355);
circle(1.5, 2, 895, 345);
circle(1.5, 2, 880, 345);

///////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(905, 250);
    glVertex2f(909, 250);
    glVertex2f(909, 280);
    glVertex2f(905, 280);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(890, 280);
    glVertex2f(920, 280);
    glVertex2f(905, 320);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(893, 300);
    glVertex2f(917, 300);
    glVertex2f(905, 340);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(895, 320);
    glVertex2f(915, 320);
    glVertex2f(905, 360);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 905, 325);
circle(1.5, 2, 910, 340);
circle(1.5, 2, 900, 340);
circle(1.5, 2, 905, 355);

/////////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(922, 230);
    glVertex2f(926, 230);
    glVertex2f(926, 260);
    glVertex2f(922, 260);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(907, 260);
    glVertex2f(947, 260);
    glVertex2f(922, 300);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(910, 280);
    glVertex2f(944, 280);
    glVertex2f(922, 320);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(912, 300);
    glVertex2f(942, 300);
    glVertex2f(922, 340);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 922, 315);
circle(1.5, 2, 927, 330);
circle(1.5, 2, 917, 330);
circle(1.5, 2, 922, 350);
circle(1.5, 2, 917, 310);
circle(1.5, 2, 927, 310);
circle(1.5, 2, 912, 335);
circle(1.5, 2, 932, 335);
circle(1.5, 2, 918, 340);
circle(1.5, 2, 928, 340);

//////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(938, 210);
    glVertex2f(942, 210);
    glVertex2f(942, 240);
    glVertex2f(938, 240);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(929, 240);
    glVertex2f(949, 240);
    glVertex2f(938, 280);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(932, 260);
    glVertex2f(946, 260);
    glVertex2f(938, 300);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(934, 280);
    glVertex2f(944, 280);
    glVertex2f(938, 320);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 938, 270);
circle(1.5, 2, 943, 285);
circle(1.5, 2, 933, 285);
circle(1.5, 2, 938, 305);

///////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(954, 190);
    glVertex2f(958, 190);
    glVertex2f(958, 220);
    glVertex2f(954, 220);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(945, 220);
    glVertex2f(965, 220);
    glVertex2f(954, 260);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(948, 240);
    glVertex2f(962, 240);
    glVertex2f(954, 280);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(950, 260);
    glVertex2f(960, 260);
    glVertex2f(954, 300);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 954, 250);
circle(1.5, 2, 959, 265);
circle(1.5, 2, 949, 265);
circle(1.5, 2, 954, 285);

////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(976, 165);
    glVertex2f(980, 165);
    glVertex2f(980, 195);
    glVertex2f(976, 195);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(967, 195);
    glVertex2f(987, 195);
    glVertex2f(976, 235);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(970, 215);
    glVertex2f(983, 215);
    glVertex2f(976, 255);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(972, 235);
    glVertex2f(980, 235);
    glVertex2f(976, 265);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 976, 225);
circle(1.5, 2, 981, 240);
circle(1.5, 2, 971, 240);
circle(1.5, 2, 976, 260);

////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(994, 145);
    glVertex2f(998, 145);
    glVertex2f(998, 175);
    glVertex2f(994, 175);
glEnd();

// First Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(985, 175);
    glVertex2f(1005, 175);
    glVertex2f(994, 215);
glEnd();

// Second Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(988, 195);
    glVertex2f(1002, 195);
    glVertex2f(994, 235);
glEnd();

// Third Layer of Leaves
glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(990, 215);
    glVertex2f(1000, 215);
    glVertex2f(994, 245);
glEnd();

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 994, 210);
circle(1.5, 2, 999, 225);
circle(1.5, 2, 989, 225);
circle(1.5, 2, 994, 240);

/////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(990, 260);
glVertex2f(994, 259);
glVertex2f(995, 269);
glVertex2f(987, 299);
glEnd();

// Layer 1 Leaves
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 988, 300);
circle(5, 12, 983, 310);
circle(5, 12, 993, 310);
circle(5, 12, 998, 305);
circle(5, 12, 978, 320);

// Layer 2 Leaves
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 982, 324);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 985, 324);
circle(5, 12, 987, 332);
circle(5, 10, 982, 327);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 984, 325);

// Layer 3 Leaves
glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 985, 320);
circle(8, 12, 997, 318);
circle(8, 12, 992, 318);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 991, 313);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 990, 312);
circle(8, 12, 1002, 308);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 997, 303);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 994, 300);
circle(10, 14, 985, 303);
circle(10, 14, 997, 325);

// Pinkish Flowers
glColor3ub(227, 91, 137);
circle(1, 2, 992, 313);
circle(1, 2, 992, 327);
circle(1, 2, 1002, 327);
circle(1, 2, 981, 313);
circle(1, 2.5, 987, 328);
circle(1, 1.5, 988, 314);
circle(1, 2.5, 1002, 309);
circle(1, 3, 997, 306);

////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(112, 283);
glVertex2f(116, 282);
glVertex2f(117, 292);
glVertex2f(109, 322);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(112, 283);
glVertex2f(116, 282);
glVertex2f(114, 291);
glVertex2f(105, 302);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(112, 283);
glVertex2f(114, 282);
glVertex2f(117, 292);
glVertex2f(117, 322);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 111, 323);
circle(5, 12, 106, 333);
circle(5, 12, 116, 333);
circle(5, 12, 121, 328);
circle(5, 12, 101, 343);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 105, 347);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 108, 347);
circle(5, 12, 110, 355);
circle(5, 10, 105, 350);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 107, 348);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 108, 343);
circle(8, 12, 120, 341);
circle(8, 12, 115, 341);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 114, 336);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 113, 335);
circle(8, 12, 125, 331);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 120, 326);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 117, 323);
circle(10, 14, 108, 326);
circle(10, 14, 120, 346);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 115, 336);
circle(1, 2, 115, 350);
circle(1, 2, 125, 350);
circle(1, 2, 104, 336);
circle(1, 2.5, 110, 351);
circle(1, 1.5, 111, 337);
circle(1, 2.5, 125, 332);
circle(1, 3, 120, 329);
circle(1, 3, 110, 333);

//////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(87, 280);
glVertex2f(91, 279);
glVertex2f(92, 289);
glVertex2f(84, 319);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(87, 280);
glVertex2f(91, 279);
glVertex2f(89, 288);
glVertex2f(80, 299);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(87, 280);
glVertex2f(89, 279);
glVertex2f(92, 289);
glVertex2f(92, 319);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 86, 320);
circle(5, 12, 81, 330);
circle(5, 12, 91, 330);
circle(5, 12, 96, 325);
circle(5, 12, 76, 340);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 80, 344);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 83, 344);
circle(5, 12, 85, 352);
circle(5, 10, 80, 347);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 82, 345);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 83, 340);
circle(8, 12, 95, 338);
circle(8, 12, 90, 338);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 89, 333);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 88, 332);
circle(8, 12, 100, 328);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 95, 323);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 92, 320);
circle(10, 14, 83, 323);
circle(10, 14, 95, 343);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 90, 333);
circle(1, 2, 90, 347);
circle(1, 2, 100, 347);
circle(1, 2, 79, 333);
circle(1, 2.5, 85, 348);
circle(1, 1.5, 86, 334);
circle(1, 2.5, 100, 329);
circle(1, 3, 95, 326);
circle(1, 3, 85, 330);

//////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(62, 275);
glVertex2f(66, 274);
glVertex2f(67, 284);
glVertex2f(59, 314);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(62, 275);
glVertex2f(66, 274);
glVertex2f(64, 283);
glVertex2f(55, 294);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(62, 275);
glVertex2f(64, 274);
glVertex2f(67, 284);
glVertex2f(67, 314);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 61, 315);
circle(5, 12, 56, 325);
circle(5, 12, 66, 325);
circle(5, 12, 71, 320);
circle(5, 12, 51, 335);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 55, 339);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 58, 339);
circle(5, 12, 60, 347);
circle(5, 10, 55, 342);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 57, 340);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 58, 335);
circle(8, 12, 70, 333);
circle(8, 12, 65, 333);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 64, 328);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 63, 327);
circle(8, 12, 75, 323);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 70, 318);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 67, 315);
circle(10, 14, 58, 318);
circle(10, 14, 70, 338);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 65, 328);
circle(1, 2, 65, 342);
circle(1, 2, 75, 342);
circle(1, 2, 54, 328);
circle(1, 2.5, 60, 343);
circle(1, 1.5, 61, 329);
circle(1, 2.5, 75, 324);
circle(1, 3, 70, 321);
circle(1, 3, 60, 325);

///////////////////

// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(37, 275);
glVertex2f(41, 274);
glVertex2f(42, 284);
glVertex2f(34, 314);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(37, 275);
glVertex2f(41, 274);
glVertex2f(39, 283);
glVertex2f(30, 294);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(37, 275);
glVertex2f(39, 274);
glVertex2f(42, 284);
glVertex2f(42, 314);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 36, 315);
circle(5, 12, 31, 325);
circle(5, 12, 41, 325);
circle(5, 12, 46, 320);
circle(5, 12, 26, 335);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 30, 339);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 33, 339);
circle(5, 12, 35, 347);
circle(5, 10, 30, 342);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 32, 340);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 33, 335);
circle(8, 12, 45, 333);
circle(8, 12, 40, 333);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 39, 328);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 38, 327);
circle(8, 12, 50, 323);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 45, 318);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 42, 315);
circle(10, 14, 33, 318);
circle(10, 14, 45, 338);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 40, 328);
circle(1, 2, 40, 342);
circle(1, 2, 50, 342);
circle(1, 2, 29, 328);
circle(1, 2.5, 35, 343);
circle(1, 1.5, 36, 329);
circle(1, 2.5, 50, 324);
circle(1, 3, 45, 321);
circle(1, 3, 35, 325);

////////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(12, 272);
glVertex2f(16, 271);
glVertex2f(17, 281);
glVertex2f(9, 311);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(12, 272);
glVertex2f(16, 271);
glVertex2f(14, 280);
glVertex2f(5, 291);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(12, 272);
glVertex2f(14, 271);
glVertex2f(17, 281);
glVertex2f(17, 311);
glEnd();

// Leaves with Different Colors
glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 11, 312);
circle(5, 12, 6, 322);
circle(5, 12, 16, 322);
circle(5, 12, 21, 317);
circle(5, 12, 1, 327);

glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 5, 331);
glColor3f(0.18, 0.71, 0.12);
circle(5, 12, 8, 331);
circle(5, 12, 10, 339);
circle(5, 10, 5, 334);
glColor3f(0.18, 0.71, 0.12);
circle(5, 10, 7, 332);

glColor3f(0.18, 0.71, 0.12);
circle(7, 10, 8, 327);
circle(8, 12, 20, 325);
circle(8, 12, 15, 325);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 14, 320);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 13, 319);
circle(8, 12, 25, 315);
glColor3f(0.18, 0.71, 0.12);
circle(8, 12, 20, 310);
glColor3f(0.18, 0.71, 0.12);
circle(10, 14, 17, 307);
circle(10, 14, 8, 310);
circle(10, 14, 20, 330);

// Pinkish Flower
glColor3ub(227, 91, 137);
circle(1, 2, 15, 318);
circle(1, 2, 15, 332);
circle(1, 2, 25, 332);
circle(1, 2, 4, 318);
circle(1, 2.5, 10, 333);
circle(1, 1.5, 11, 319);
circle(1, 2.5, 25, 312);
circle(1, 3, 20, 309);
circle(1, 3, 10, 313);

/////////////////
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(10, 242);
glVertex2f(14, 241);
glVertex2f(15, 251);
glVertex2f(7, 281);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(10, 242);
glVertex2f(14, 241);
glVertex2f(12, 250);
glVertex2f(3, 261);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(10, 242);
glVertex2f(12, 241);
glVertex2f(15, 251);
glVertex2f(15, 281);
glEnd();

glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 9, 282);
circle(5, 12, 4, 292);
circle(5, 12, 14, 292);
circle(5, 12, 19, 287);
circle(5, 12, -1, 302);

glColor3f(0.16, 0.86, 0.26);
circle(5, 12, 3, 306);
circle(5, 12, 6, 306);
circle(5, 12, 8, 314);
circle(5, 10, 3, 309);
circle(5, 10, 5, 307);

glColor3f(0.16, 0.86, 0.26);
circle(7, 10, 6, 302);
circle(8, 12, 18, 300);
circle(8, 12, 13, 300);
circle(8, 12, 12, 295);
circle(8, 12, 11, 294);
circle(8, 12, 23, 290);
circle(8, 12, 18, 285);
circle(10, 14, 15, 282);
circle(10, 14, 6, 285);
circle(10, 14, 18, 305);

glColor3ub(227, 91, 137);
circle(1, 2, 13, 295);
circle(1, 2, 13, 309);
circle(1, 2, 23, 309);
circle(1, 2, 2, 295);
circle(1, 2.5, 8, 310);
circle(1, 1.5, 9, 296);
circle(1, 2.5, 23, 291);
circle(1, 3, 18, 288);
circle(1, 3, 8, 292);

////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(30, 242);
glVertex2f(34, 241);
glVertex2f(35, 251);
glVertex2f(27, 281);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(30, 242);
glVertex2f(34, 241);
glVertex2f(32, 250);
glVertex2f(23, 261);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(30, 242);
glVertex2f(32, 241);
glVertex2f(35, 251);
glVertex2f(35, 281);
glEnd();

glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 29, 282);
circle(5, 12, 24, 292);
circle(5, 12, 34, 292);
circle(5, 12, 39, 287);
circle(5, 12, 19, 302);
circle(5, 12, 23, 306);
circle(5, 12, 26, 306);
circle(5, 12, 28, 314);
circle(5, 10, 23, 309);
circle(5, 10, 25, 307);
circle(7, 10, 26, 302);
circle(8, 12, 38, 300);
circle(8, 12, 33, 300);
circle(8, 12, 32, 295);
circle(8, 12, 31, 294);
circle(8, 12, 43, 290);
circle(8, 12, 38, 285);
circle(10, 14, 35, 282);
circle(10, 14, 26, 285);
circle(10, 14, 38, 305);

glColor3ub(227, 91, 137);
circle(1, 2, 33, 295);
circle(1, 2, 33, 309);
circle(1, 2, 43, 309);
circle(1, 2, 22, 295);
circle(1, 2.5, 28, 310);
circle(1, 1.5, 29, 296);
circle(1, 2.5, 43, 292);
circle(1, 3, 38, 289);
circle(1, 3, 28, 293);

////////////////
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(50, 242);
glVertex2f(54, 241);
glVertex2f(55, 251);
glVertex2f(47, 281);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(50, 242);
glVertex2f(54, 241);
glVertex2f(52, 250);
glVertex2f(43, 261);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(50, 242);
glVertex2f(52, 241);
glVertex2f(55, 251);
glVertex2f(55, 281);
glEnd();

glColor3f(0.16, 0.86, 0.26);
circle(3, 6, 49, 282);
circle(5, 12, 44, 292);
circle(5, 12, 54, 292);
circle(5, 12, 59, 287);
circle(5, 12, 39, 302);
circle(5, 12, 43, 306);
circle(5, 12, 46, 306);
circle(5, 12, 48, 314);
circle(5, 10, 43, 309);
circle(5, 10, 45, 307);
circle(7, 10, 46, 302);
circle(8, 12, 58, 300);
circle(8, 12, 53, 300);
circle(8, 12, 52, 295);
circle(8, 12, 51, 294);
circle(8, 12, 63, 290);
circle(8, 12, 58, 285);
circle(10, 14, 55, 282);
circle(10, 14, 46, 285);
circle(10, 14, 58, 305);

glColor3ub(227, 91, 137);
circle(1, 2, 53, 295);
circle(1, 2, 53, 309);
circle(1, 2, 63, 309);
circle(1, 2, 42, 295);
circle(1, 2.5, 48, 310);
circle(1, 1.5, 49, 296);
circle(1, 2.5, 63, 291);
circle(1, 3, 58, 288);
circle(1, 3, 48, 292);

//////////////////
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(10, 212);
glVertex2f(14, 211);
glVertex2f(16, 230);
glVertex2f(8, 250);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(10, 212);
glVertex2f(14, 211);
glVertex2f(12, 225);
glVertex2f(5, 235);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(10, 212);
glVertex2f(12, 211);
glVertex2f(16, 230);
glVertex2f(16, 260);
glEnd();

glColor3f(0.18, 0.71, 0.12);
circle(3, 6, 10, 255);
circle(5, 12, 5, 265);
circle(5, 12, 15, 265);
circle(5, 12, 20, 260);
circle(5, 12, 0, 275);
circle(5, 12, 4, 279);
circle(5, 12, 7, 279);
circle(5, 12, 9, 287);
circle(5, 10, 4, 282);
circle(5, 10, 6, 280);
circle(7, 10, 8, 275);
circle(8, 12, 20, 273);
circle(8, 12, 15, 273);
circle(8, 12, 14, 268);
circle(8, 12, 13, 267);
circle(8, 12, 25, 263);
circle(8, 12, 20, 258);
circle(10, 14, 17, 255);
circle(10, 14, 8, 258);
circle(10, 14, 20, 278);

glColor3ub(227, 91, 137);
circle(1, 2, 15, 268);
circle(1, 2, 15, 282);
circle(1, 2, 25, 282);
circle(1, 2, 4, 268);
circle(1, 2.5, 10, 283);
circle(1, 1.5, 11, 269);
circle(1, 2.5, 25, 265);
circle(1, 3, 20, 262);
circle(1, 3, 10, 266);

////////////////////

    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(75, 35, 5);
        glVertex2f(0, 165);
        glVertex2f(4, 165);
        glVertex2f(4, 195);
        glVertex2f(0, 195);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.18, 0.71, 0.12);
        glVertex2f(-9, 195);
        glVertex2f(13, 195);
        glVertex2f(2, 235);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.18, 0.71, 0.12);
        glVertex2f(-6, 215);
        glVertex2f(10, 215);
        glVertex2f(2, 255);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.18, 0.71, 0.12);
        glVertex2f(-4, 235);
        glVertex2f(8, 235);
        glVertex2f(2, 275);
    glEnd();

    glColor3ub(227, 91, 137);
    circle(1.5, 2, 2, 225);
    circle(1.5, 2, 7, 240);
    circle(1.5, 2, -3, 240);
    circle(1.5, 2, 2, 260);

///////////////////
glBegin(GL_TRIANGLE_FAN);
    glColor3ub(75, 35, 5);
    glVertex2f(27, 195);
    glVertex2f(31, 195);
    glVertex2f(31, 225);
    glVertex2f(27, 225);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(18, 225);
    glVertex2f(40, 225);
    glVertex2f(29, 265);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(21, 245);
    glVertex2f(37, 245);
    glVertex2f(29, 285);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.71, 0.12);
    glVertex2f(23, 265);
    glVertex2f(35, 265);
    glVertex2f(29, 305);
glEnd();

glColor3ub(227, 91, 137);
circle(1.5, 2, 29, 255);
circle(1.5, 2, 34, 270);
circle(1.5, 2, 24, 270);
circle(1.5, 2, 29, 290);

////////////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(54, 225);
glVertex2f(58, 225);
glVertex2f(58, 255);
glVertex2f(54, 255);
glEnd();

// Tree Leaves
glBegin(GL_TRIANGLES);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(49, 255);
glVertex2f(71, 255);
glVertex2f(59, 295);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(52, 275);
glVertex2f(66, 275);
glVertex2f(59, 315);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(54, 295);
glVertex2f(64, 295);
glVertex2f(59, 335);
glEnd();

// Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 59, 275);
circle(1.5, 2, 64, 290);
circle(1.5, 2, 54, 290);
circle(1.5, 2, 59, 310);

//////////////////////
// Tree Trunk
glBegin(GL_TRIANGLE_FAN);
glColor3ub(75, 35, 5);
glVertex2f(85, 255);
glVertex2f(89, 255);
glVertex2f(89, 285);
glVertex2f(85, 285);
glEnd();

// Tree Leaves
glBegin(GL_TRIANGLES);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(76, 285);
glVertex2f(98, 285);
glVertex2f(87, 325);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(79, 305);
glVertex2f(94, 305);
glVertex2f(87, 345);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.18, 0.71, 0.12);
glVertex2f(81, 325);
glVertex2f(92, 325);
glVertex2f(87, 355);
glEnd();

// Tree Flowers
glColor3ub(227, 91, 137);
circle(1.5, 2, 87, 325);
circle(1.5, 2, 92, 340);
circle(1.5, 2, 82, 340);
circle(1.5, 2, 87, 360);

/////////////////
/////Cloud
    glColor3ub(173,197,224);
    circle(9,15,p+20,685);
    glColor3ub(252,254,255);
    circle(6,14,p+21,685);

    glColor3ub(232,241,255);
    circle(7,16,p+30,695);
    glColor3ub(252,254,255);
    circle(7,14,p+32,692);

    glColor3ub(252,254,255);
    circle(12,16,p+28,680);

    glColor3ub(221,229,247);
    circle(10,15,p+45,690);
    glColor3ub(252,254,255);
    circle(9,13,p+43,685);
    glColor3ub(252,254,255);
    circle(15,18,p+48,670);

    glColor3ub(173,197,224);
    circle(6,14,p+30,680);
    glColor3ub(252,254,255);
    circle(6,13,p+30,677);

    glColor3ub(173,197,224);
    circle(6,14,p+38,668);
    glColor3ub(252,254,255);
    circle(6,13,p+36,667);


    glColor3ub(252,254,255);
    circle(11,15,p+29,668);

////////////Another Cloud
// Cloud in the Sky
glColor3ub(173, 197, 224);
circle(9, 15, 550, 680);
glColor3ub(252, 254, 255);
circle(6, 14, 555, 680);

glColor3ub(232, 241, 255);
circle(7, 16, 565, 690);
glColor3ub(252, 254, 255);
circle(7, 14, 567, 692);

glColor3ub(252, 254, 255);
circle(12, 16, 575, 680);

glColor3ub(221, 229, 247);
circle(10, 15, 585, 690);
glColor3ub(252, 254, 255);
circle(9, 13, 583, 685);
glColor3ub(252, 254, 255);
circle(15, 18, 590, 670);

glColor3ub(173, 197, 224);
circle(6, 14, 575, 680);
glColor3ub(252, 254, 255);
circle(6, 13, 575, 677);

glColor3ub(173, 197, 224);
circle(6, 14, 585, 668);
glColor3ub(252, 254, 255);
circle(6, 13, 583, 667);

glColor3ub(252, 254, 255);
circle(11, 15, 570, 668);

////////
    glColor3ub(232,241,255);
    circle(13,20,400,665);
    glColor3ub(252,254,255);
    circle(11,18,400,665);

    glColor3ub(232,241,255);
    circle(10,20,410,675);
    glColor3ub(252,254,255);
    circle(10,20,412,672);

    glColor3ub(232,241,255);
    circle(13,20,410,655);

    glColor3ub(221,229,247);
    circle(9,20,420,680);
    glColor3ub(252,254,255);
    circle(8,18,420,679);

    glColor3ub(232,241,255);
    circle(9,20,420,650);
    glColor3ub(252,254,255);
    circle(8,18,420,652);

    glColor3ub(221,229,247);
    circle(9,20,430,685);
    glColor3ub(252,254,255);
    circle(8,18,430,683);

    glColor3ub(232,241,255);
    circle(9,20,425,655);
    glColor3ub(252,254,255);
    circle(8,18,435,657);

    glColor3ub(232,241,255);
    circle(9,20,440,675);

    glColor3ub(221,229,247);
    circle(8,18,445,665);
    glColor3ub(252,254,255);
    circle(8,18,443,663);
    glColor3ub(252,254,255);
    circle(18,18,420,664);
    glColor3ub(252,254,255);
    circle(18,25,417,665);


    glColor3ub(232,241,255);
    circle(13,20,p+200,745);
    glColor3ub(252,254,255);
    circle(11,18,p+200,745);

    glColor3ub(232,241,255);
    circle(10,20,p+210,755);
    glColor3ub(252,254,255);
    circle(10,20,p+212,762);

    glColor3ub(232,241,255);
    circle(13,20,p+210,735);

    glColor3ub(221,229,247);
    circle(9,20,p+220,750);
    glColor3ub(252,254,255);
    circle(8,18,p+220,759);

    glColor3ub(232,241,255);
    circle(9,20,p+220,756);
    glColor3ub(252,254,255);
    circle(8,18,p+220,752);

    glColor3ub(232,241,255);
    circle(9,20,p+230,765);
    glColor3ub(252,254,255);
    circle(8,18,p+230,761);

    glColor3ub(232,241,255);
    circle(9,20,p+225,745);
    glColor3ub(252,254,255);
    circle(8,18,p+235,747);

    glColor3ub(232,241,255);
    circle(9,20,p+240,755);

    glColor3ub(221,229,247);
    circle(8,18,p+243,745);
    glColor3ub(252,254,255);
    circle(8,18,p+240,743);
    glColor3ub(173,197,224);
    circle(8,18,p+230,733);
    glColor3ub(252,254,255);
    circle(8,18,p+230,738);
    glColor3ub(173,197,224);
    circle(8,18,p+220,723);
    glColor3ub(252,254,255);
    circle(8,18,p+220,728);



    glColor3ub(252,254,255);
    circle(23,9,p+245,744);
    glColor3ub(173,197,224);
    circle(21,10,p+240,720);
    glColor3ub(252,254,255);
    circle(21,11,p+238,723);


    glColor3ub(252,254,255);
    circle(18,18,p+210,744);
    glColor3ub(252,254,255);
    circle(18,25,p+220,745);

    glColor3ub(173,197,224);
    circle(10,20,p+235,715);
    glColor3ub(252,254,255);
    circle(10,20,p+235,719);

/////////////////////
    glColor3ub(173, 197, 224);
    circle(9, 15, p + 20, 785);
    glColor3ub(252, 254, 255);
    circle(6, 14, p + 21, 785);

    glColor3ub(232, 241, 255);
    circle(7, 16, p + 30, 795);
    glColor3ub(252, 254, 255);
    circle(7, 14, p + 32, 792);

    glColor3ub(252, 254, 255);
    circle(12, 16, p + 28, 780);

    glColor3ub(221, 229, 247);
    circle(10, 15, p + 45, 790);
    glColor3ub(252, 254, 255);
    circle(9, 13, p + 43, 785);
    glColor3ub(252, 254, 255);
    circle(15, 18, p + 48, 770);

    glColor3ub(173, 197, 224);
    circle(6, 14, p + 30, 770);
    glColor3ub(252, 254, 255);
    circle(6, 13, p + 30, 767);

    glColor3ub(173, 197, 224);
    circle(6, 14, p + 38, 758);
    glColor3ub(252, 254, 255);
    circle(6, 13, p + 36, 757);

    glColor3ub(252, 254, 255);
    circle(11, 15, p + 29, 758);

/////////////////////
// Cloud Drawing Function with Speed Controller
    glColor3ub(173, 197, 224);
    circle(9, 15, cloudPos + 20, 880);
    glColor3ub(252, 254, 255);
    circle(6, 14, cloudPos + 21, 880);

    glColor3ub(232, 241, 255);
    circle(7, 16, cloudPos + 30, 890);
    glColor3ub(252, 254, 255);
    circle(7, 14, cloudPos + 32, 887);

    glColor3ub(252, 254, 255);
    circle(12, 16, cloudPos + 28, 880);

    glColor3ub(221, 229, 247);
    circle(10, 15, cloudPos + 45, 890);
    glColor3ub(252, 254, 255);
    circle(9, 13, cloudPos + 43, 885);
    glColor3ub(252, 254, 255);
    circle(15, 18, cloudPos + 48, 870);

    glColor3ub(173, 197, 224);
    circle(6, 14, cloudPos + 30, 880);
    glColor3ub(252, 254, 255);
    circle(6, 13, cloudPos + 30, 877);

    glColor3ub(173, 197, 224);
    circle(6, 14, cloudPos + 38, 868);
    glColor3ub(252, 254, 255);
    circle(6, 13, cloudPos + 36, 867);

    glColor3ub(252, 254, 255);
    circle(11, 15, cloudPos + 29, 868);

    cloudPos += cloudSpeed;
    if (cloudPos > 1000) cloudPos = -200;
/////////
//Plaine
    glColor3ub(255, 255, 255);

    // Plane Body
    glBegin(GL_POLYGON);
    glVertex2f(planePos + 0, 900);
    glVertex2f(planePos + 20, 900);
    glVertex2f(planePos + 20, 905);
    glVertex2f(planePos + 0, 905);
    glEnd();

    // Plane Wings
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(planePos + 5, 900);
    glVertex2f(planePos + 10, 890);
    glVertex2f(planePos + 15, 890);
    glVertex2f(planePos + 20, 900);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(planePos + 5, 905);
    glVertex2f(planePos + 10, 915);
    glVertex2f(planePos + 15, 915);
    glVertex2f(planePos + 20, 905);
    glEnd();

    // Plane Windows
    glColor3ub(0, 0, 0);
    circle(1, 1, planePos + 6, 902);
    circle(1, 1, planePos + 8, 902);
    circle(1, 1, planePos + 10, 902);
    circle(1, 1, planePos + 12, 902);

    planePos += planeSpeed;
    if (planePos > 1000) planePos = -200;

////////////////////









    // Car Headlights (Only at Night)
    if (isNight)
    {
        glColor3f(1, 1, 0.5); // Soft Yellow
        glBegin(GL_TRIANGLES);
        glVertex2f(p + 39, 20);
        glVertex2f(p + 60, 30);
        glVertex2f(p + 60, 10);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex2f(p + 39, 15);
        glVertex2f(p + 55, 25);
        glVertex2f(p + 55, 5);
        glEnd();
    }



    // Sun (Day Mode)
    if (!isNight)
    {
        glColor3f(1, 1, 0);
        circle(20, 20, sunPos, 900);
    }

    // Moon (Night Mode)
    if (isNight)
    {
        glColor3f(1, 1, 0.8);
        circle(20, 20, 500, 900);

        glColor3f(0.23, 0.24, 0.10);
        circle(18, 18, 506, 904);
    }

    glutSwapBuffers();

    // Move the car
    if (p <= 1000)
        p += 0.1;
    else
        p = -100;

    // Move the sun slowly
    if (!isNight)
        sunPos += 0.5;
    else
        sunPos -= 0.5;

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Day-Night Transition with Car & House Lights");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
