///week14_angles_fprintf_fscanf
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;///0號關節,1號關節...
FILE * fout = NULL , *fin=NULL;
void myWrite(){
    if(fout==NULL) fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.1f ",angle[i]);///小黑印出來
        fprintf(fout , "%.1f ", angle[i]);///檔案印出來
    }
    printf("\n");///每呼叫一次小黑跳行
    fprintf(fout,"\n");///每呼叫一次檔案也跳行
}
void myRead(){
    if(fout!=NULL) {fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key,int x ,int y){
    if(key=='r') myRead();
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    myWrite();
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
        glRotatef(angle[0],0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///把手肘掛回去
            glRotatef(angle[1],0,0,1);///旋轉
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);///綠色的
            glRectf(0.7,0.5,1.0,0.3);///下手肘
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///把手臂掛在身上
        glRotatef(angle[2],0,0,1);///對z軸旋轉
        glTranslatef(0.3,-0.4,0);///挑整手臂的旋轉中心
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///把手肘掛回去
            glRotatef(angle[3],0,0,1);///旋轉
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,0);///綠色的
            glRectf(-0.7,0.5,-1.0,0.3);///下手肘
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    ///glutInitWindowSize(600,600);
    glutCreateWindow("week13_rect_TRT");//開GLUT視窗
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);//顯示用的函式

    glutMainLoop();
 }
