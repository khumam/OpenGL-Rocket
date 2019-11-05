#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <stdarg.h>

char title[] = "Roket";

double rotate_y = 0;
double rotate_x = 0;
double move_x = 0;
double move_y = 0;
double rand1, rand2, rand3, rand4 = 0;

// void display();
// void specialKeys();

void initGL()
{
    glClearColor(0.135f, 0.206f, 0.535f, 1.0f);
    // glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    // glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Lighting set up
    // glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    // glEnable(GL_LIGHTING);
    // glEnable(GL_LIGHT0);

    // Set lighting intensity and color
    // GLfloat qaAmbientLight[] = {0.2, 0.2, 0.2, 1.0};
    // GLfloat qaDiffuseLight[] = {0.8, 0.8, 0.8, 1.0};
    // GLfloat qaSpecularLight[] = {0.1, 0.1, 0.1, 0.1};
    // glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    // glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    // glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

    // Set the light position
    // GLfloat qaLightPosition[] = {1.0, .5, 0.0, 1.0};
    // glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    // glLoadIdentity();
    // glTranslatef(1.0f, 1.0f, 1.0f);
    // glTranslatef(-1.5f, 0.0f, -6.0f);

    // Set material properties
    // GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
    // GLfloat qaGreen[] = {1.0, 1.0, 0.0, 1.0};
    // GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
    // glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
    // glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
    // glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
    // glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

    // Badan belakang
    glBegin(GL_POLYGON);
    glColor3f(0.03, 0.01, 0.3);
    glVertex3f(0, -1, 1);
    glVertex3f(0.5, -1, 1);
    glVertex3f(0.5, 1.5, 1);
    glVertex3f(0, 1.5, 1);
    glEnd();

    // Badan samping kanan
    glBegin(GL_POLYGON);
    glColor3f(0.03, 0.03, 0.3);
    glVertex3f(0.5, -1, 0.5);
    glVertex3f(0.5, -1, 1);
    glVertex3f(0.5, 1.5, 1);
    glVertex3f(0.5, 1.5, 0.5);
    glEnd();

    // Badan depan
    glBegin(GL_POLYGON);
    glColor3f(0.03, 0.01, 0.3);
    glVertex3f(0, -1, 0.5);
    glVertex3f(0.5, -1, 0.5);
    glVertex3f(0.5, 1.5, 0.5);
    glVertex3f(0, 1.5, 0.5);
    glEnd();

    // Badan samping kiri
    glBegin(GL_POLYGON);
    glColor3f(0.03, 0.03, 0.3);
    glVertex3f(0, -1, 0.5);
    glVertex3f(0, -1, 1);
    glVertex3f(0, 1.5, 1);
    glVertex3f(0, 1.5, 0.5);
    glEnd();

    // Badan bawah
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.03, 0.3);
    glVertex3f(0, -1, 1);
    glVertex3f(0.5, -1, 1);
    glVertex3f(0.5, -1, 0.5);
    glVertex3f(0, -1, 0.5);
    glEnd();

    // sayap    glVertex3f(0, -1, 0.5);
    glVertex3f(0, -1, 0.5);
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.5, -1, 0.85);
    glVertex3f(0.5, 0, 0.85);
    glVertex3f(1, -1, 0.85);
    glEnd();

    // sayap kanan atas
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.5, 0, 0.65);
    glVertex3f(0.5, 0, 0.85);
    glVertex3f(1, -1, 0.85);
    glVertex3f(1, -1, 0.65);
    glEnd();

    // sayap kanan 2
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.5, -1, 0.65);
    glVertex3f(0.5, 0, 0.65);
    glVertex3f(1, -1, 0.65);
    glEnd();

    // sayap kanan bawah
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.01, 0.1);
    glVertex3f(0.5, -1, 0.65);
    glVertex3f(0.5, -1, 0.85);
    glVertex3f(1, -1, 0.85);
    glVertex3f(1, -1, 0.65);
    glEnd();

    // sayap kiri 1
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0, -1, 0.85);
    glVertex3f(0, 0, 0.85);
    glVertex3f(-0.5, -1, 0.85);
    glEnd();

    // sayap kiri atas
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0, 0, 0.65);
    glVertex3f(0, 0, 0.85);
    glVertex3f(-0.5, -1, 0.85);
    glVertex3f(-0.5, -1, 0.65);
    glEnd();

    // sayap kiri bawah
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.01, 0.1);
    glVertex3f(0, -1, 0.65);
    glVertex3f(0, -1, 0.85);
    glVertex3f(-0.5, -1, 0.85);
    glVertex3f(-0.5, -1, 0.65);
    glEnd();

    // sayap kiri 2
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0, -1, 0.65);
    glVertex3f(0, 0, 0.65);
    glVertex3f(-0.5, -1, 0.65);
    glEnd();

    // sayap depan 1
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.35, 0, 0.5);
    glVertex3f(0.35, -1, 0.5);
    glVertex3f(0.35, -1, -0.15);
    glEnd();

    // sayap depan atas
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.15, -1, -0.15);
    glVertex3f(0.35, -1, -0.15);
    glVertex3f(0.35, 0, 0.5);
    glVertex3f(0.15, 0, 0.5);
    glEnd();

    // sayap depan bawah
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.01, 0.1);
    glVertex3f(0.15, -1, -0.15);
    glVertex3f(0.35, -1, -0.15);
    glVertex3f(0.35, -1, 0.5);
    glVertex3f(0.15, -1, 0.5);
    glEnd();

    // sayap depan 2
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.15, 0, 0.5);
    glVertex3f(0.15, -1, 0.5);
    glVertex3f(0.15, -1, -0.15);
    glEnd();

    // sayap belakang 1
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.15, 0, 1);
    glVertex3f(0.15, -1, 1);
    glVertex3f(0.15, -1, 1.65);
    glEnd();

    // sayap belakang atas
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.15, -1, 1.65);
    glVertex3f(0.35, -1, 1.65);
    glVertex3f(0.35, 0, 1);
    glVertex3f(0.15, 0, 1);
    glEnd();

    // sayap belakang bawah
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.01, 0.1);
    glVertex3f(0.15, -1, 1.65);
    glVertex3f(0.35, -1, 1.65);
    glVertex3f(0.35, -1, 1);
    glVertex3f(0.15, -1, 1);
    glEnd();

    // sayap belakang 2
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.35, 0, 1);
    glVertex3f(0.35, -1, 1);
    glVertex3f(0.35, -1, 1.65);
    glEnd();

    //moncong roket belakang
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.5, 1.5, 1);
    glVertex3f(0, 1.5, 1);
    glVertex3f(0.25, 2.2, 0.75);
    glEnd();

    //moncong roket depan
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.5, 1.5, 0.5);
    glVertex3f(0, 1.5, 0.5);
    glVertex3f(0.25, 2.2, 0.75);
    glEnd();

    //moncong roket kiri
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0, 1.5, 1);
    glVertex3f(0, 1.5, 0.5);
    glVertex3f(0.25, 2.2, 0.75);
    glEnd();

    //moncong roket kanan
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.01, 0.1);
    glVertex3f(0.5, 1.5, 1);
    glVertex3f(0.5, 1.5, 0.5);
    glVertex3f(0.25, 2.2, 0.75);
    glEnd();

    // awan nihhhh

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0.8, 1.5 - move_y, 1);
    glVertex3f(1.0, 1.7 - move_y, 1);
    glVertex3f(1.2, 3.0 - move_y, 1);
    glVertex3f(1.5, 2.3 - move_y, 1);
    glVertex3f(1.7, 2.8 - move_y, 1);
    glVertex3f(2.0, 2.0 - move_y, 1);
    glVertex3f(2.2, 2.2 - move_y, 1);
    glVertex3f(2.4, 1.7 - move_y, 1);
    glVertex3f(2.8, 1.5 - move_y, 1);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(0.8, 1.5 - move_y, 0.5);
    glVertex3f(1.0, 1.7 - move_y, 0.5);
    glVertex3f(1.2, 3.0 - move_y, 0.5);
    glVertex3f(1.5, 2.3 - move_y, 0.5);
    glVertex3f(1.7, 2.8 - move_y, 0.5);
    glVertex3f(2.0, 2.0 - move_y, 0.5);
    glVertex3f(2.2, 2.2 - move_y, 0.5);
    glVertex3f(2.4, 1.7 - move_y, 0.5);
    glVertex3f(2.8, 1.5 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(0.8, 1.5 - move_y, 1);
    glVertex3f(1.0, 1.7 - move_y, 1);
    glVertex3f(1.0, 1.7 - move_y, 0.5);
    glVertex3f(0.8, 1.5 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(1.0, 1.7 - move_y, 1);
    glVertex3f(1.2, 3.0 - move_y, 1);
    glVertex3f(1.2, 3.0 - move_y, 0.5);
    glVertex3f(1.0, 1.7 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(1.2, 3.0 - move_y, 1);
    glVertex3f(1.5, 2.3 - move_y, 1);
    glVertex3f(1.5, 2.3 - move_y, 0.5);
    glVertex3f(1.2, 3.0 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(1.5, 2.3 - move_y, 1);
    glVertex3f(1.7, 2.8 - move_y, 1);
    glVertex3f(1.7, 2.8 - move_y, 0.5);
    glVertex3f(1.5, 2.3 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(1.7, 2.8 - move_y, 1);
    glVertex3f(2.0, 2.0 - move_y, 1);
    glVertex3f(2.0, 2.0 - move_y, 0.5);
    glVertex3f(1.7, 2.8 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(2.0, 2.0 - move_y, 1);
    glVertex3f(2.2, 2.2 - move_y, 1);
    glVertex3f(2.2, 2.2 - move_y, 0.5);
    glVertex3f(2.0, 2.0 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(2.2, 2.2 - move_y, 1);
    glVertex3f(2.4, 1.7 - move_y, 1);
    glVertex3f(2.4, 1.7 - move_y, 0.5);
    glVertex3f(2.2, 2.2 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(2.4, 1.7 - move_y, 1);
    glVertex3f(2.8, 1.5 - move_y, 1);
    glVertex3f(2.8, 1.5 - move_y, 0.5);
    glVertex3f(2.4, 1.7 - move_y, 0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(2.8, 1.5 - move_y, 1);
    glVertex3f(0.8, 1.5 - move_y, 1);
    glVertex3f(0.8, 1.5 - move_y, 0.5);
    glVertex3f(2.8, 1.5 - move_y, 0.5);
    glEnd();

    // awan sampe sini

    // api
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.5, 0.3);

    glVertex3f(0, -1, 1);
    glVertex3f(0.2, -rand1, 1);
    glVertex3f(0.3, -rand2, 1);
    glVertex3f(0.4, -rand3, 1);
    glVertex3f(0.5, -1, 1);

    glVertex3f(0.5, -1, 1);
    glVertex3f(0.2, -rand3, 1);
    glVertex3f(0.3, -rand2, 1);
    glVertex3f(0.4, -rand1, 1);
    glVertex3f(0.5, -1, 0.5);

    glVertex3f(0.5, -1, 0.5);
    glVertex3f(0.2, -rand1, 0.5);
    glVertex3f(0.3, -rand2, 0.5);
    glVertex3f(0.2, -rand3, 0.5);
    glVertex3f(0, -1, 0.5);

    glVertex3f(0, -1, 0.5);
    glVertex3f(0.1, -rand3, 0.5);
    glVertex3f(0.2, -rand2, 0.5);
    glVertex3f(0.1, -rand1, 0.5);
    glVertex3f(0, -1, 1);

    glEnd();

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{

    //  Right arrow - increase rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;

    //  Left arrow - decrease rotation by 5 degree
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    else if (key == GLUT_KEY_PAGE_UP)
    {
        move_y += 0.2;

        double randomnum = rand() % 5 + 1;
        if (randomnum > 1)
        {
            rand1 = randomnum;

            // randomnum = 3.4;
            rand2 = randomnum;

            // randomnum = 4;
            rand3 = randomnum;
        }
        else
        {
            rand1 = 3;
            rand2 = 2.2;
            rand3 = 1.5;
        }
    }
    else if (key == GLUT_KEY_PAGE_DOWN)
    {
        move_y -= 0.2;

        double randomnum = rand() % 5 + 1;
        if (randomnum > 1)
        {
            rand1 = randomnum;

            // randomnum = 3.4;
            rand2 = randomnum;

            // randomnum = 4;
            rand3 = randomnum;
        }
        else
        {
            rand1 = 3;
            rand2 = 2.2;
            rand3 = 1.5;
        }
    }

    rand1 = 0;
    rand2 = 0;
    rand2 = 0;

    //  Request display update
    glutPostRedisplay();
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glScalef(0.2, 0.2, 0.2);
    // gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();

    return 0;
}