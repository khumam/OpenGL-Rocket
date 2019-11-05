/* 
*/

#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <malloc.h>
// #include <freeglut.h>
// #include <FreeImage.h>
#include <math.h>
// #include <windows.h>

//The particle structure
typedef struct
{
    double px, py, pz;
    double dx, dy, dz;
    double speed, scale, state;
    double rx, ry, rz, ra;
    double r, g, b;
    int age;
    struct particle *next;

} particle;

//The global Structure
typedef struct
{
    particle *head;
    particle *tail;
    int fire;
    double sprayfactor;
    double colourmode;
    int explosions;
    int rotate;

} glob;
glob global;
int e[][4] = {{0, 3, 2, 1}, {3, 7, 6, 2}, {7, 4, 5, 6}, {4, 0, 1, 5}, {0, 4, 7, 3}, {1, 2, 6, 5}};
float c[][3] = {{1.0, 0, 0}, {0, 1.0, 0}, {1.0, 1.0, 1.0}, {0, 0, 1.0}, {.6, 0, .6}, {0, .6, .6}};

//This method creates a new particle
particle *createParticle(double x, double y, double z)
{
    particle *p;
    p = (particle *)malloc(sizeof(particle));
    p->age = 0;
    p->px = x; //position variables
    p->py = y;
    p->pz = z;
    p->dx = (((double)rand() / RAND_MAX) - 0.5) * global.sprayfactor; //direction values
    p->dy = (double)rand() / RAND_MAX;
    p->dz = (((double)rand() / RAND_MAX) - 0.5) * global.sprayfactor;
    p->rx = ((double)rand() / RAND_MAX) * 180; //rotation values
    p->ry = ((double)rand() / RAND_MAX) * 180;
    p->rz = ((double)rand() / RAND_MAX) * 180;
    p->ra = ((double)rand() / RAND_MAX) * 36; //rotation speed
    p->speed = 1;                             //particle speed
    if (!global.colourmode)
        p->scale = 0.5; //change size if applicable
    else
        p->scale = (double)rand() / RAND_MAX;
    p->state = 0;                                         //state for camera or not
    p->r = (double)rand() / RAND_MAX * global.colourmode; //colour variables
    p->g = (double)rand() / RAND_MAX * global.colourmode;
    p->b = (double)rand() / RAND_MAX * global.colourmode;
    p->next = 0;

    return p;
}
//manually throw a new particle
void throwParticle(double px, double py, double pz)
{
    particle *newP;
    newP = (particle *)malloc(sizeof(particle));
    newP = createParticle(px, py, pz);
    if (global.head)
    {
        global.tail->next = newP;
        global.tail = newP;
    }
    else
    {
        global.head = newP;
        global.tail = newP;
    }
}
//Make a particle explode
void blowUp(particle *current)
{
    int i;
    for (i = 0; i < 6; i++)
        throwParticle(current->px, current->py, current->pz);
    if (current->state == 1)
    {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(20, 30, 70, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    }
}
//Draw the particle at the new location
void updateParticles(particle *current)
{
    int i;
    float p[][3] = {
        {current->px + current->scale, current->py + current->scale, current->pz + current->scale},
        {current->px + current->scale, current->py - current->scale, current->pz + current->scale},
        {current->px - current->scale, current->py - current->scale, current->pz + current->scale},
        {current->px - current->scale, current->py + current->scale, current->pz + current->scale},
        {current->px + current->scale, current->py + current->scale, current->pz - current->scale},
        {current->px + current->scale, current->py - current->scale, current->pz - current->scale},
        {current->px - current->scale, current->py - current->scale, current->pz - current->scale},
        {current->px - current->scale, current->py + current->scale, current->pz - current->scale}};
    glColor3f(current->r, current->g, current->b);
    for (i = 0; i < 6; ++i)
    {

        glBegin(GL_QUADS);
        glVertex3fv(p[e[i][0]]);
        glVertex3fv(p[e[i][1]]);
        glVertex3fv(p[e[i][2]]);
        glVertex3fv(p[e[i][3]]);
        glEnd();
    }
    if (global.rotate)
        glPopMatrix();
    current->age++;
}
//Rotate a particle
void rotateParticle(particle *current)
{
    current->rx += current->ra;
    if (current->rx > 360)
        current->rx -= 360;
    current->ry += current->ra;
    if (current->ry > 360)
        current->ry -= 360;
    current->rz += current->ra;
    if (current->rz > 360)
        current->rz -= 360;
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(current->px, current->py, current->pz);
    glRotatef(current->rx, 1.0, 0.0, 0.0);
    glRotatef(current->ry, 0.0, 1.0, 0.0);
    glRotatef(current->rz, 0.0, 0.0, 1.0);
    glTranslatef(-current->px, -current->py, -current->pz);
}
//Update particle position
void updatePositions()
{
    particle *current;
    current = global.head;
    do
    {
        if (current->py > 0 && current->py < current->scale && current->pz < 30 && current->pz > -30 && current->px > -30 && current->px < 30)
        {
            if (!((current->px > -20 && current->px < -10) && (current->pz > 5 && current->pz < 15)))
            {
                current->dy = -0.95 * current->dy;
                current->dx = 0.95 * current->dx;
                current->dz = 0.95 * current->dz;
                if (current->dy < 0.0005 && current->dx < 0.0005 && current->dz < 0.0005)
                {
                    current->speed = 0;
                }
            }
        }
        if (abs(current->py) > current->scale)
            current->dy -= 0.01;
        current->px += current->speed * current->dx;
        current->py += current->speed * current->dy;
        current->pz += current->speed * current->dz;
        if (current->state == 1)
        {
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(current->px, current->py, current->pz, current->speed * current->dx, current->speed * current->dy, current->speed * current->dz, 0.0, 1.0, 0.0);
        }
        current = current->next;
    } while (current != 0);
}
//Change particle speeds
void changeSpeeds()
{
    particle *current;
    current = global.head;
    while (current != 0)
    {
        current->speed = (double)rand() / RAND_MAX;
        current = current->next;
    }
}
//Remove stationary particles, old particles and particles below screen
void cleanParticles()
{
    particle *current, *temp;
    current = global.head;

    while (current != 0)
    {

        temp = current->next;
        if (temp != 0 && (temp->py < -60 || temp->speed == 0 || temp->age > 3000))
        {
            current->next = temp->next;
            if (temp->state == 1)
            {
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(20, 30, 70, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
            }
            if (temp == global.tail)
                global.tail == current;
            free(temp);
        }
        current = current->next;
    }
}
//reset to original setup
void reset()
{
    particle *current;
    current = global.head;
    while (current != 0)
    {
        current->age = 4000;

        current = current->next;
    }
    global.explosions = 0;
    global.fire = 1;
    global.sprayfactor = 1;
    global.colourmode = 0;
    global.rotate = 0;
    global.tail = global.head;
}

//Main draw frame loop
void drawStage(void)
{
    int p[][3] = {{1, 2, 1}, {1, 0, 1}, {-1, 0, 1}, {-1, 2, 1}, {1, 2, -1}, {1, 0, -1}, {-1, 0, -1}, {-1, 2, -1}};
    particle *current = global.head;
    int i;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Clear Color and Depth Buffers
    // Draw ground
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex3f(-30.0f, 0.0f, -30.0f);
    glVertex3f(-30.0f, 0.0f, 5.0f);
    glVertex3f(30.0f, 0.0f, 5.0f);
    glVertex3f(30.0f, 0.0f, -30.0f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-30.0f, 0.0f, 5.0f);
    glVertex3f(-20.0f, 0.0f, 5.0f);
    glVertex3f(-20.0f, 0.0f, 15.0f);
    glVertex3f(-30.0f, 0.0f, 15.0f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(30.0f, 0.0f, 15.0f);
    glVertex3f(-10.0f, 0.0f, 15.0f);
    glVertex3f(-10.0f, 0.0f, 5.0f);
    glVertex3f(30.0f, 0.0f, 5.0f);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-30.0f, 0.0f, 30.0f);
    glVertex3f(30.0f, 0.0f, 30.0f);
    glVertex3f(30.0f, 0.0f, 15.0f);
    glVertex3f(-30.0f, 0.0f, 15.0f);
    glEnd();
    //draw origin point
    for (i = 0; i < 6; ++i)
    {
        glColor3fv(c[i]);
        glBegin(GL_QUADS);
        glVertex3iv(p[e[i][0]]);
        glVertex3iv(p[e[i][1]]);
        glVertex3iv(p[e[i][2]]);
        glVertex3iv(p[e[i][3]]);
        glEnd();
    }
    if (rand() > RAND_MAX * 0.7 && global.fire)
        throwParticle(0, 1, 0);
    if (current != NULL)
        updatePositions();
    while (current != 0)
    {
        if (rand() < 20 && global.explosions && current != global.head)
            blowUp(current);
        if (current->state != 1 && current != global.head)
        {
            if (global.rotate)
                rotateParticle(current);
            updateParticles(current);
        }
        current = current->next;
    }
    cleanParticles();
    glutPostRedisplay();
    glutSwapBuffers();
}
/*glut keyboard function*/
void keyboard(unsigned char key, int x, int y)
{
    particle *newP;
    switch (key)
    {
    case 0x1B:
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 'p':
    case 'P':
        throwParticle(0, 1, 0);
        break;
    case 's':
    case 'S':
        changeSpeeds();
        break;
    case 'f':
    case 'F':
        if (global.fire)
            global.fire = 0;
        else
            global.fire = 1;
        break;
    case 'R':
    case 'r':
        reset();
        break;
    case 'e':
    case 'E':
        global.tail->state = 1;
        break;
    case 't':
    case 'T':
        if (global.sprayfactor == 0.2)
            global.sprayfactor = 1;
        else
            global.sprayfactor = 0.2;
        break;
    case 'c':
    case 'C':
        if (!global.colourmode)
            global.colourmode = 1;
        else
            global.colourmode = 0;
        break;
    case 'B':
    case 'b':
        if (global.explosions)
            global.explosions = 0;
        else
            global.explosions = 1;
        break;
    case 'x':
    case 'X':
        if (global.rotate)
            global.rotate = 0;
        else
            global.rotate = 1;
        break;
    }
} //keyboard
int main(int argc, char **argv)
{
    printf("Q:Quit\nP:Throw particle\nS:Change speed\nF:Start/stop Stream\nR:Reset\nE:Throw camera\nT:Change spread\nC:Change Colours and sizes\nB:Particles will explode\nX:Particles will rotate\n");
    global.sprayfactor = 1;
    global.fire = 1;
    global.colourmode = 0;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Volcano");
    glutDisplayFunc(drawStage);
    glutKeyboardFunc(keyboard);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, glutGet(GLUT_WINDOW_WIDTH) / glutGet(GLUT_WINDOW_HEIGHT), 1, 200.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(20, 30, 70, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glClearColor(0.2, 0.6, 0.6, 0.9);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}