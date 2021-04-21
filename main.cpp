

#include<fstream>
#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<string>
#include <time.h>
#include <sys/timeb.h>

#define WIDTH 900
#define HEIGHT 600

GLfloat x = 0.20, z = 0.25, x2 = -0.20, z2 = -0.25, txp = 0.100, tzp = 0.110, txm = -0.100, tzm = -0.110, ty = -0.015, dx = 0.030, PI = 3.14;
void table();
void face();
void chairs();
void room();
void clock_draw();
void plant();
double second_angle = 0, minute_angle = 0, hour_angle = 0;
GLuint text_2d;
GLfloat texBoard[8][8][4];

void drawLine(GLfloat x, GLfloat y, GLfloat angle) {
	glVertex3f(x, x, -0.39f);
	glVertex3f(y * cos(angle), y * sin(angle), -0.39f);
}
GLfloat T[8][3] = {
    {0.020, -0.015, 0.025},
    {-0.020, -0.015, 0.025},
    {-0.020, -0.015, -0.025},
    {0.020, -0.015, -0.025},

    {-0.020, 0.015, 0.025},
    {-0.020, 0.015, -0.025},
    {0.020, 0.015, 0.025},
    {0.020, 0.015, -0.025}
};

void display_clock(void) {

    GLfloat x, y, angle;
    GLfloat clo[] = { 1,0,0,1 };
    glPointSize(1.5);
    glPushMatrix();

    glTranslatef(0.0, 0.2, 0.0);
    glBegin(GL_POINTS);
    for (angle = 0.0f; angle <= (2.0f * 3.14); angle += 0.01f)
    {
        x = 0.0500f * sin(angle);
        y = 0.050f * cos(angle);
        glVertex3f(x, y, -0.39f);
    }
    angle = 0.0f;
    glEnd();
    glPopMatrix();
}
void clock_draw() {
    GLfloat clo[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, clo);
    glPushMatrix();
    glTranslatef(0, 0.2, -0.4);
    glutSolidCylinder(0.06, 0.01, 10, 10);
    glPopMatrix();
    display_clock();
    plant();
}

void laptop() {
    GLfloat cam[] = { 0.15,0.15,0.15 ,1 };
    GLfloat cam1[] = { 1,1,1 ,1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cam);
    
    glPushMatrix();
    glTranslatef(0, 0, -0.06);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.03);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0, 0.03, 0.03);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.03);
    glPopMatrix();    

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0, -0.3, 0.15);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.1);
    glPopMatrix();


    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cam1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0, -0.299, 0.15);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.09);
    glPopMatrix();   

}
void plant() {
    GLfloat lam[] = { 0.36, 0.25, 0.20,1 };
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, lam);
    glPushMatrix();
    glTranslatef(-0.28, -0.125, -0.350);
    glScalef(0.05, 0.05, 0.05);
    glutSolidRhombicDodecahedron();
    glPopMatrix();

    GLfloat lam1[] = { 0, 1, 0.5,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, lam1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.25, 0.32, -0.03);
    glutSolidCone(0.1, 0.05, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.25, 0.32, 0.02);
    glutSolidCone(0.08, 0.05, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.25, 0.32, 0.07);
    glutSolidCone(0.07, 0.05, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.25, 0.32, 0.11);
    glutSolidCone(0.05, 0.05, 10, 10);
    glPopMatrix();



    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.25, 0.32, 0.15);
    glutSolidCone(0.02, 0.05, 10, 10);
    glPopMatrix();
    laptop();
}
void lamps() {

    GLfloat lam[] = { 1,1,0,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, lam);
    glPushMatrix();
   
    glRotatef(-90, 1, 0, 0);
    glTranslatef(0.35, 0.355, 0.1);
    glColor3f(1, 1, 1);
    glutSolidCone(0.050, 0.1, 10, 10);
    glColor3f(0.36, 0.25, 0.2);
    glutSolidCylinder(0.005, -0.2, 10, 10);
    glPopMatrix();

    GLfloat lam1[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lam1);
    glPushMatrix();

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -0.29);
    glColor3f(0, 0, 0);
    glutSolidCylinder(0.015, 0.05, 10, 10);
    glColor3f(0.36, 0.25, 0.2);
    glutSolidCylinder(0.0025, -0.1, 10, 10);
    glPopMatrix();

    GLfloat lam2[] = { 1,0,0,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, lam2);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(-0.3, 0.35, -0.28);
    glutSolidCylinder(0.015, 0.05, 10, 10);
    glPopMatrix();
    chairs();

}

void chairs() {

    GLfloat cha[] = { 0.62352, 0.372549, 0.623529,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, cha);
    glPushMatrix();
    glTranslatef(0.0, -0.05, 0.15);
    glScalef(2, 0.1, 2);
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.20);
    glRotatef(90, 1, 0, 0);
    glScalef(2, 0.1, 2); 
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.05, -0.15);
    glScalef(2, 0.1, 2);
    glutSolidCube(0.05);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.20);
    glRotatef(90, 1, 0, 0);
    glScalef(2, 0.1, 2);
    glutSolidCube(0.05);
    glPopMatrix();


    //LEGS
    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(0.50, -0.07, -1.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(0.50, -0.075, 1.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(0.45, -0.075, 1.95);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(0.45, -0.075, -1.95);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(-0.50, -0.075, 1.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(-0.45, -0.075, 1.95);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(-0.50, -0.075, -1.1);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 2, 0.1);
    glTranslatef(-0.45, -0.075, -1.95);
    glutSolidCube(0.1);
    glPopMatrix();

    clock_draw();
}
void face() {

    GLfloat mat[] = { 0,1,1,1 };
  
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
    glScalef(2, 2, 2);
    glTranslatef(0, 0.01, 0.028);
    glBegin(GL_QUADS);

    glColor3f(0, 1, 0);         //BOTTOM
    glVertex3f(T[0][0], T[0][1], T[0][2]);
    glVertex3f(T[1][0], T[1][1], T[1][2]);
    glVertex3f(T[2][0], T[2][1], T[2][2]);
    glVertex3f(T[3][0], T[3][1], T[3][2]);


    glColor3f(1, 1, 0);         //BACK
    glNormal3f(T[1][0]- 0.002, 0, 0);
    glVertex3f(T[4][0] - 0.002, T[4][1], T[4][2]);
    glVertex3f(T[1][0] - 0.002, T[1][1], T[1][2]);
    glVertex3f(T[2][0] - 0.002, T[2][1], T[2][2]);
    glVertex3f(T[5][0] - 0.002, T[5][1], T[5][2]);

    glColor3f(1, 1, 0);         //BACK
    glNormal3f(T[1][0], 0, 0);
    glVertex3f(T[4][0], T[4][1], T[4][2]);
    glVertex3f(T[1][0], T[1][1], T[1][2]);
    glVertex3f(T[2][0], T[2][1], T[2][2]);
    glVertex3f(T[5][0], T[5][1], T[5][2]);
    glEnd();



    glBegin(GL_QUADS);


    glColor3f(.5, 0, 1);        //LEFT
    glNormal3f(0, 0, T[0][2]+0.002);
    glVertex3f(T[4][0], T[4][1], T[4][2] + 0.002);
    glVertex3f(T[6][0], T[6][1], T[6][2] + 0.002);
    glVertex3f(T[0][0], T[0][1], T[0][2] + 0.002);
    glVertex3f(T[1][0], T[1][1], T[1][2] + 0.002);
    glColor3f(.5, 0, 1);        //LEFT
    glNormal3f(0, 0, T[0][2]);
    glVertex3f(T[4][0], T[4][1], T[4][2]);
    glVertex3f(T[6][0], T[6][1], T[6][2]);
    glVertex3f(T[0][0], T[0][1], T[0][2]);
    glVertex3f(T[1][0], T[1][1], T[1][2]);

    glColor3f(1, 0, 0);           //RIGHT
    glNormal3f(0, 0, T[5][2] - 0.002);
    glVertex3f(T[5][0], T[5][1], T[5][2] - 0.002);
    glVertex3f(T[7][0], T[7][1], T[7][2] - 0.002);
    glVertex3f(T[3][0], T[3][1], T[3][2] - 0.002);
    glVertex3f(T[2][0], T[2][1], T[2][2] - 0.002);
    glColor3f(1, 0, 0);           //RIGHT
    glNormal3f(0, 0, T[5][2]);
    glVertex3f(T[5][0], T[5][1], T[5][2]);
    glVertex3f(T[7][0], T[7][1], T[7][2]);
    glVertex3f(T[3][0], T[3][1], T[3][2]);
    glVertex3f(T[2][0], T[2][1], T[2][2]);

    glColor3f(0, 1, 1);
    glNormal3f(T[1][0]+0.002, 0, 0);
    glVertex3f(T[6][0] + 0.002, T[6][1], T[6][2]);
    glVertex3f(T[0][0] + 0.002, T[0][1], T[0][2]);
    glVertex3f(T[3][0] + 0.002, T[3][1], T[3][2]);
    glVertex3f(T[7][0] + 0.002, T[7][1], T[7][2]);
    glColor3f(0, 1, 1);         //FRONT
    glNormal3f(T[6][0], 0, 0);
    glVertex3f(T[6][0], T[6][1], T[6][2]);
    glVertex3f(T[0][0], T[0][1], T[0][2]);
    glVertex3f(T[3][0], T[3][1], T[3][2]);
    glVertex3f(T[7][0], T[7][1], T[7][2]);


    glEnd();

    glPopMatrix();
    lamps();
}

void table() {

    GLfloat pot[] = { 1,0,0,1 };
    glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, pot);
    glTranslatef(0, 0.02, 0.05);
    glutSolidTeapot(0.025);
    glPopMatrix();


    GLfloat tab[] = { 0.36, 0.25, 0.20,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, tab);
    glBegin(GL_QUADS);

    //LEGS
    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(txp, -0.1, -0.01);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txp, ty, tzp - 0.010);
    glVertex3f(txp, ty - 0.100, tzp - 0.010);
    glVertex3f(txp, ty - 0.100, tzp);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(-0.01, -0.1, tzp);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txp - 0.010, ty, tzp);
    glVertex3f(txp - 0.010, ty - 0.100, tzp);
    glVertex3f(txp, ty - 0.100, tzp);


    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(txm, -0.1, -0.01);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txm, ty, tzp - 0.010);
    glVertex3f(txm, ty - 0.100, tzp - 0.010);
    glVertex3f(txm, ty - 0.100, tzp);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(0.01, -0.1, tzp);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txm + 0.010, ty, tzp);
    glVertex3f(txm + 0.010, ty - 0.100, tzp);
    glVertex3f(txm, ty - 0.100, tzp);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(txp, -0.1, 0.01);
    glVertex3f(txp, ty, tzm);
    glVertex3f(txp, ty, tzm + 0.010);
    glVertex3f(txp, ty - 0.100, tzm + 0.010);
    glVertex3f(txp, ty - 0.100, tzm);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(-0.01, -0.1, tzm);
    glVertex3f(txp, ty, tzm);
    glVertex3f(txp - 0.010, ty, tzm);
    glVertex3f(txp - 0.010, ty - 0.100, tzm);
    glVertex3f(txp, ty - 0.100, tzm);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(txm, -0.1, 0.01);
    glVertex3f(txm, ty, tzm);
    glVertex3f(txm, ty, tzm + 0.010);
    glVertex3f(txm, ty - 0.100, tzm + 0.010);
    glVertex3f(txm, ty - 0.100, tzm);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3f(0.01, -0.1, tzm);
    glVertex3f(txm, ty, tzm);
    glVertex3f(txm + 0.010, ty, tzm);
    glVertex3f(txm + 0.010, ty - 0.100, tzm);
    glVertex3f(txm, ty - 0.100, tzm);

    //TABLE TOP
    glColor3f(0.36, 0.25, 0.20);
    glNormal3b(0, ty, 0);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txm, ty, tzm);
    glVertex3f(txp, ty, tzm);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3b(0, ty-0.010, 0);
    glVertex3f(txp, ty-0.010, tzp);
    glVertex3f(txm, ty-0.010, tzp);
    glVertex3f(txm, ty-0.010, tzm);
    glVertex3f(txp, ty-0.010, tzm);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3b(0, 0, tzp);
    glVertex3f(txm, ty, tzp);
    glVertex3f(txp, ty, tzp);
    glVertex3f(txp, ty - 0.010, tzp);
    glVertex3f(txm, ty - 0.010, tzp);

    glColor3f(0.36, 0.25, 0.20);
    glNormal3b(txp, 0, 0);
    glVertex3f(txp, ty - 0.010, tzp);
    glVertex3f(txp, ty - 0.010, tzm);
    glVertex3f(txp, ty, tzm);
    glVertex3f(txp, ty, tzp);
    glEnd();

    face();


    glutSwapBuffers();
}

GLfloat room_vertices[7][3] = {
    {-0.350, -0.115, 0.400},
    {-0.350, -0.115, -0.400},
    {0.400, -0.115, -0.400},
    {0.400, -0.115, 0.400},

    {-0.350, 0.300, -0.400},
    {-0.350, 0.300, 0.400},
     {0.400, 0.300, -0.400}

};

GLfloat room_normal[3][3] = {
    {0.050, -0.115, 0},
    {-0.350, 0.115,0},
    {0.050, 0.115, -0.400}
};
void room() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat wall[3][4] = { { 1,1,1,1 },
                            {1,0,0,1},
                            {1,0,1,1} };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, wall[0]);

    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0);
    glNormal3fv(room_normal[0]);
    glVertex3fv(room_vertices[0]);
    glVertex3fv(room_vertices[1]);
    glVertex3fv(room_vertices[2]);
    glVertex3fv(room_vertices[3]);

    glColor3f(0.0, 0.0, 1.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wall[1]);
    glNormal3fv(room_normal[1]);
    glVertex3fv(room_vertices[0]);
    glVertex3fv(room_vertices[1]);
    glVertex3fv(room_vertices[4]);
    glVertex3fv(room_vertices[5]);

    glColor3f(0.0, 1.0, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wall[2]);
    glNormal3fv(room_normal[2]);
    glVertex3fv(room_vertices[4]);
    glVertex3fv(room_vertices[6]);
    glVertex3fv(room_vertices[2]);
    glVertex3fv(room_vertices[1]);
    glEnd();


    display_clock();

    glLineWidth(5);
    GLfloat clock_hands[3][3] = { {1,0.5, 0},
                                {1,1,1},
                                {1,0,0} };
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_LINES);
    drawLine(0.0, 0.035, -second_angle + PI / 2);
    glEnd();

    glColor3f(1, 0.5, 0);
    glBegin(GL_LINES);
    drawLine(0.0, 0.040, -minute_angle + PI / 2);
    glEnd();

    glBegin(GL_LINES);
    drawLine(0.0, 0.025, -hour_angle + PI / 2);
    glEnd();
    glPopMatrix();
    table();
}

void lights() {

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);

    //GLfloat light2_pos[] = { 0.0f, 1.0f, 0.0f, 0.0f };
    GLfloat light2_pos[] = { 0, 0.2, 0, 0.0f };
    
    GLfloat light1_pos[] = { -0.400, -0.115, 0.400 , 0.0f };
    GLfloat diffuse0[] = { 1, 1, 1, 1.0 };
    GLfloat diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat diffuse2[] = { 0.5, 0.5, 0.0, 1.0 };
    GLfloat ambient0[] = { 0.2, 0.2, 0.2, 1.0 };

    GLfloat specular0[] = { 2.0, 6.0, 4.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION,  room_vertices[0]); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0); 
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);

    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular0);

    glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular0);
    

}
void init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Final Project");
    lights();
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    gluPerspective(30.0, (float)WIDTH / (float)HEIGHT, 1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();   
    gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    GLuint text_2d; 
    GLfloat texBoard[8][8][4]; 
    glEnable(GL_TEXTURE_2D); 
    glGenTextures(1, &text_2d); 
    glBindTexture(GL_TEXTURE_1D, text_2d);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 8, 0, GL_RGBA, GL_FLOAT, texBoard);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glEnable(GL_DEPTH_TEST);

}
int count = 0;
void Perspec_change(int key, int x, int y) {

  
    switch (key) {

    case GLUT_KEY_UP:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(2.5, 1, 1.5, 0, 0, 0, 0, 1, 0);
               break;
    case GLUT_KEY_LEFT:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
                break;
    case GLUT_KEY_RIGHT:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(0.8, 0.8, -0.5, 0, 0, 0, 0, 1, 0);
                break;
    case GLUT_KEY_DOWN:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(0.5, 3, -0.3, 0, 0, 0, 0, 1, 0);
                break;
        }
    glutPostRedisplay();
   
}
void lightoff(unsigned char key, int x, int y) {

    key = tolower(key);
    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }
    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}

void time_change(int i) {
    struct timeb tb;
    time_t tim = time(0);
    struct tm* local_time;
    local_time = localtime(&tim);
    ftime(&tb);

    second_angle = (double)(local_time->tm_sec + (double)tb.millitm / 1000.0) / 30.0 * PI;
    minute_angle = (double)(local_time->tm_min) / 30.0 * PI + second_angle / 60.0;
    hour_angle = (double)(local_time->tm_hour > 12 ? local_time->tm_hour - 12 : local_time->tm_hour) / 6.0 * PI + minute_angle / 12.0;

    glutPostRedisplay();
    glutTimerFunc(15, time_change, 1);
}

int main(int argc, char** argv)
{

    init(argc, argv);
    glutDisplayFunc(room);
    glutSpecialFunc(Perspec_change);
    glutKeyboardFunc(lightoff);
    glutTimerFunc(15, time_change, 1);
    glutMainLoop();
    return 0;
}