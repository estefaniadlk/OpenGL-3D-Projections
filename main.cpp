#include <glut.h> //an parousiazei provlima se compile - build tote #include <GL/glut.h>

GLfloat rotationAngleX = 0.0f; 
GLfloat rotationAngleY = 0.0f;
GLfloat rotationAngleZ = 0.0f;

void drawCube(GLfloat r, GLfloat g, GLfloat b) {
    glBegin(GL_QUADS);

    //sxediash pleurwn cube - Front
    glColor3f(r, g, b);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    //Back
    glColor3f(r, g, b);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    //Left
    glColor3f(r, g, b);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    //Right
    glColor3f(r, g, b);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    //Top 
    glColor3f(r, g, b);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    //Bottom
    glColor3f(r, g, b);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glEnd();

    // sxediasi grammwn anamesa se kathe pleura gia pio diakrita apotelesmata
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    /*float left = -2.0f; // gia tin provoli xwris ti xrisi tis gluPerspective xrisi glOrtho
    float right = 2.0f;
    float bottom = -2.0f;
    float top = 2.0f;
    float near = 0.1f; // gia ta oria vathous apostasis
    float far = 100.0f;

    glOrtho(left, right, bottom, top, near, far);*/
    
    //perspective projection with angle 45degrees
    gluPerspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Perspective Projection
    glPushMatrix(); //mhtrwa
    glTranslatef(-2.5f, 0.0f, -7.0f);
    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationAngleZ, 0.0f, 0.0f, 1.0f);
    drawCube(0.7f, 0.7f, 0.7f);
    glPopMatrix();

    // Cavalier Projection
    glPushMatrix(); //metra cavalier 1-1-1
    glTranslatef(0.0f, 0.0f, -7.0f);
    glRotatef(45.0f, 0.25f, -0.25f, 0.0f); //rotation x,y gia na einai pio emfanes to cavalier effect
    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f); //rotate gia to keyboard, hdh exei efarmostei rotation stin progioumeni me 45.0f
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationAngleZ, 0.0f, 0.0f, 1.0f);
    glScalef(1.0f, 1.0f, 1.5f); //times gia to vathos tis cavalier gia pio kontina apotelesmata sto epithimito enanti 1-1-1
    drawCube(0.0f, 1.0f, 0.0f);
    glPopMatrix();

    // Cabinet Projection
    glPushMatrix(); //metra cabinet gia 60moires 1-1-0.5
    glTranslatef(2.5f, 0.0f, -7.0f);
    glRotatef(63.4f, 0.25f, -0.25f, 0.0f); //cabinet me xaraktiristiki gwnia 63,4 moires k rotation x,y, gia cabinet effect
    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotationAngleZ, 0.0f, 0.0f, 1.0f); 
    glScalef(1.0f, 1.0f, 0.75f); // oi kathetes menoun statheres to z meiwnetai sto 1/2 gia cabinet
    drawCube(0.0f, 0.0f, 1.0f);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r': //reset stin arxiki thesi me r/R, rotate se antistoixous aksones me x,y,z h X,Y,Z gia antitheti katefthinsi
        case 'R':
            rotationAngleX = 0.0f;
            rotationAngleY = 0.0f;
            rotationAngleZ = 0.0f;
            break;
        case 'x':
            rotationAngleX += 3.0f; //to 1.0f eixe argo result 
            break;
        case 'X':
            rotationAngleX -= 3.0f;
            break;
        case 'y':
            rotationAngleY += 3.0f;
            break;
        case 'Y':
            rotationAngleY -= 3.0f;
            break;
        case 'z':
            rotationAngleZ += 3.0f;
            break;
        case 'Z':
            rotationAngleZ -= 3.0f;
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Projection Forms");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

    return 0;
}
