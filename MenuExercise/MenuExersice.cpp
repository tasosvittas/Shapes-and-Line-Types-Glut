#define GLUT_DISABLE_ATEXIT_HACK
#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <math.h>
#define PI 3.14159
#define circlePoints 256

using namespace std;
//#include <windows.h>
int i;
void sampleDisplay()
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    //Set point size to 3 pixels
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2i(10,10);
        glVertex2i(20,10);
        glVertex2i(25,15);
        glVertex2i(20,20);
        glVertex2i(10,20);
    glEnd();
    glFlush();
}

void circleDisplay()
{
    GLfloat angleStep=2*PI/(float)circlePoints;
    GLuint pointsPerQuarter=circlePoints/4;
    GLfloat x[circlePoints];
    GLfloat y[circlePoints];
    GLfloat radius=10;
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glLineWidth(3);
    for(i=0;i<pointsPerQuarter/2;i++)
    {
        //Define points in first quadrant
        x[i]=radius*cos(i*angleStep);
        y[i]=radius*sin(i*angleStep);
        x[pointsPerQuarter-1-i]=y[i];
        y[pointsPerQuarter-1-i]=x[i];
        //Define points in second quadrant
        x[pointsPerQuarter+i]=-y[i];
        y[pointsPerQuarter+i]=x[i];
        x[2*pointsPerQuarter-1-i]=-x[i];
        y[2*pointsPerQuarter-1-i]=y[i];
        //Define points in third quadrant
        x[2*pointsPerQuarter+i]=-x[i];
        y[2*pointsPerQuarter+i]=-y[i];
        x[3*pointsPerQuarter-1-i]=-y[i];
        y[3*pointsPerQuarter-1-i]=-x[i];
        //Define points in fourth quadrant
        x[3*pointsPerQuarter+i]=y[i];
        y[3*pointsPerQuarter+i]=-x[i];
        x[4*pointsPerQuarter-1-i]=x[i];
        y[4*pointsPerQuarter-1-i]=-y[i];
    }
    glBegin(GL_LINE_LOOP);
    for (i=0;i<circlePoints;i++)
    {
        glVertex2f(x[i],y[i]);
    }
    glEnd();
    glFlush();
}

void shapesDisplay()
{
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    glLineWidth(2);
    glLineStipple(1,0x00FF);
    glBegin(GL_LINES);
        glVertex2i(0,0);
        glVertex2i(10,0);
        glVertex2i(0,10);
        glVertex2i(10,10);
    glEnd();
    glColor3f(0,1,0);
    glLineWidth(3);
    glLineStipple(2,0x00FF);
    glBegin(GL_LINE_STRIP);
        glVertex2i(15,10);
        glVertex2i(20,10);
        glVertex2i(25,5);
        glVertex2i(20,0);
        glVertex2i(15,0);
    glEnd();
    glColor3f(0,0,1);
    glLineWidth(2);
    glLineStipple(1,0x0A0A);
    glBegin(GL_LINE_LOOP);
        glVertex2i(0,15);
        glVertex2i(0,20);
        glVertex2i(5,25);
        glVertex2i(10,20);
        glVertex2i(10,15);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    int chooser;
    cout << "Give 1 for the Sample Display, 2 for Shapes and 3 for Cicle:" << endl;
    cout << "Give 0 (zero) for exit!" << endl;
    cin >> chooser;
    while (chooser != 0)
    {
        if (chooser != 1 || chooser != 2)
        {
            cout << "Give a number between 1, 2 or 3. Try again." << endl;
            cout << "Give 1 for the Sample Display, 2 for Shapes and 3 for Cicle:" << endl;
            cout << "Give 0 (zero) for exit!" << endl;
            cin >> chooser;
        }
        if (chooser == 1)
        {
            glutInit(&argc,argv);
            glutInitWindowPosition(50,50);
            glutInitWindowSize(640,480);
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
            glutCreateWindow("A sample OpenGL application");
            glMatrixMode(GL_PROJECTION);
            gluOrtho2D(5,30,5,25);
            glutDisplayFunc(sampleDisplay);
            glutMainLoop();
        }
        if (chooser == 2)
        {
            glutInit(&argc,argv);
            glutInitWindowPosition(50,50);
            glutInitWindowSize(640,480);
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
            glutCreateWindow("Drawing stippled lines");
            glMatrixMode(GL_PROJECTION);
            
            gluOrtho2D(-5,30,-5,30);
            glEnable(GL_LINE_STIPPLE);
            glutDisplayFunc(shapesDisplay);
            glutMainLoop();
        }
        if(chooser == 3)
        {
            glutInit(&argc,argv);
            glutInitWindowPosition(50,50);
            glutInitWindowSize(640,480);
            glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
            glutCreateWindow("Circle drawing");
            glMatrixMode(GL_PROJECTION);
            gluOrtho2D(-32,32,-24,24);
            glutDisplayFunc(circleDisplay);
            glutMainLoop();
            return 0;
        }

    }
    return 0;
}

