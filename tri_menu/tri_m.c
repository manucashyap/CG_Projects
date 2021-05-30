#include<GL/glu.h>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
float r=1.0,g=1.0,b=1.0;
void myInit()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
    glMatrixMode(GL_MODELVIEW);
}

void triangle()
{

    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(250,250);
    glVertex2f(400,100);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    triangle();
    glutPostRedisplay();
    glutSwapBuffers();
}

void subMenuHandler(int ch)
{
    switch(ch)
    {
        case 1: r = 1.0;
                g = 0.0;
                b = 0.0;
                break;
        case 2: r = 0.0;
                g = 1.0;
                b = 0.0;
                break;
        case 3: r = 0.0;
                g = 0.0;
                b = 1.0;
                break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("create triangle ");
    myInit();
    glutDisplayFunc(display);
    glutCreateMenu(subMenuHandler);
    glutAddMenuEntry("default", 0);
    glutAddMenuEntry("red", 1);
    glutAddMenuEntry("green", 2);
    glutAddMenuEntry("blue", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
