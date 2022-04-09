#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


float x = 0.0;
void init(){
    glClearColor(0.5,0.8,1.0,0.0);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void Elipse(GLfloat x, GLfloat y, GLfloat rx, GLfloat ry){
    glBegin(GL_POLYGON);
    for(int i=0; i<360; i++){
        glVertex2f(x+rx*cos(i*3.14/180), y+ry*sin(i*3.14/180));
    }
    glEnd();
}

void DrawSea(){
    glColor3f(0, 115/255.0, 161/255.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(640.0, 0.0);
    glVertex2f(640.0, 120.0);
    glVertex2f(0.0, 120.0);
    glEnd();
}

void DrawSun(){
    glColor3f(1.0,1.0,0.0);
    Elipse(320,400,30,30);
}

void DrawClouds(){
    glPushMatrix();
    glTranslatef(-x,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    for(int i = 0; i<640; i+=300){
        Elipse(50+i,420,30,20);
        Elipse(80+i,420,20,20);
        Elipse(110+i,420,30,20);

        Elipse(200+i,320,30,20);
        Elipse(230+i,320,20,20);
        Elipse(260+i,320,30,20);
    }

    glPopMatrix();
}


void DrawMountain(){
    glColor3f(0.0, 100/255.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(360.0, 120.0);
    glVertex2f(600.0, 320.0);
    glVertex2f(800.0, 120.0);
    glEnd();

    glColor3f(0.0, 128/255.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-100.0, 120.0);
    glVertex2f(240.0, 360.0);
    glVertex2f(480.0, 120.0);
    glEnd();
}

void DrawBoat(){
    glPushMatrix();
    glTranslatef(x,0.0,0.0);
    glColor3f(160/255.0,82/255.0,45/255.0);
    glBegin(GL_POLYGON);
    glVertex2f(100.0, 40.0);
    glVertex2f(160.0, 40.0);
    glVertex2f(200.0, 80.0);
    glVertex2f(60.0, 80.0);
    glEnd();

    glColor3f(0.5f, 0.1f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(130.0, 80.0);
    glVertex2f(140.0, 80.0);
    glVertex2f(140.0, 120.0);
    glVertex2f(130.0, 120.0);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(140.0, 120.0);
    glVertex2f(160.0, 110.0);
    glVertex2f(140.0, 100.0);
    glEnd();
    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    DrawSea();
    DrawSun();
    DrawClouds();
    DrawMountain();
    DrawBoat();
    glFlush();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/30, timer, 0);
    if (x<640.0)
        x+=1.0;
    else
        x=0.0;
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Hierarchical Modeling");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();
    return 0;
}

