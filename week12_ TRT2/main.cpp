#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);///��������

     glPushMatrix();///�k�䪺���u��y
        glTranslatef(0.2,0,0);///(3)����k��(��ө���)
        glRotatef(angle, 0,0,1);///(2)����
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///�p�����A��@�p���u
        glPushMatrix();
            glTranslatef(0.2,0,0);///(3)����k��(��ө���)
            glRotatef(angle, 0,0,1);///(2)����
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);///�p�����A��@�p��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���䪺���u��y
        glTranslatef(-0.2,0,0);///(3)���쥪��(��ө���)
        glRotatef(-angle, 0,0,1);///(2)����
        glTranslatef(-0.2,0,0);
        glColor3f(1,0,0);
        glutSolidTeapot(0.2);///�p�����A��@�p���u
        glPushMatrix();
            glTranslatef(-0.2,0,0);///(3)���쥪��(��ө���)
            glRotatef(-angle, 0,0,1);///(2)����
            glTranslatef(-0.2,0,0);
            glColor3f(1,0,0);
            glutSolidTeapot(0.2);///�p�����A��@�p��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.01; ///�C������ display() �[1��
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
