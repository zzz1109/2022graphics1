#include <GL/glut.h>
float angle=45,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///��GLUT�����e��
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ�
    glRectf(0.3,0.5,-0.3,-0.5);///����
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///����u���b���W
        glRotatef(angle,0,0,1);///��z�b����
        glTranslatef(-0.3,-0.4,0);///�D����u�����त��
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()�D�禡 �i����
 {
    glutInit(&argc,argv);//��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//���w�İ�+3D�`�ץ\��
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");//�}GLUT����
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);//��ܥΪ��禡

    glutMainLoop();
 }
