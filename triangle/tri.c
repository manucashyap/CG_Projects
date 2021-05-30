#include<GL/glut.h>
#include<stdio.h>
#include<windows.h>
void myInit()
{

    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);

}

void triangle()
{

    glColor3f(1.0,1.01,.0);
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(250,400);
    glVertex2f(400,100);
    glEnd();
}

void Display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    triangle();
    glFlush();

}

int main(int argc, char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("triangle");
    myInit();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}

