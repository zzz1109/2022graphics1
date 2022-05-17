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
    glutPostRedisplay();///請GLUT重劃畫面
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glRectf(0.3,0.5,-0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///把手臂掛在身上
        glRotatef(angle,0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");//開GLUT視窗
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }
