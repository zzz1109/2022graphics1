///week16_interpolation
///改編自week15_angles_TRT_again
#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;
int angleID=0;
FILE * fout=NULL, * fin = NULL;
void myWrite()
{///每呼叫一次myWrite
    if(fout == NULL)fout=fopen("file.txt","w+");

    for(int i = 0;i<20;i++)
    {
        printf("%.1f ",angle[i]);///小黑印出來
        fprintf(fout,"%.1f ",angle[i]);///檔案印出來
    }///這裡老師沒有fclose
    printf("\n");///小黑印出跳行
    fprintf(fout,"\n");///檔案跳行
}
float NewAngle[20],OldAngle[20];
void myRead()
{
    if(fout!=NULL){fclose(fout); fout=NULL;}
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        OldAngle[i] = NewAngle[i];
        fscanf(fin, "%f", &NewAngle[i] );
        ///fscanf(fin,"%f",&angle[i]);
    }
    glutPostRedisplay();///重劃畫面
}
void myInterpolate(float alpha){
    for(int i=0;i<20;i++){
        angle[i]= alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
    }
}
///int t=0;
void timer(int t){
    if(t%50==0) myRead();
    myInterpolate((t%50)/50.0);
    glutPostRedisplay();
    glutTimerFunc(20,timer,t+1);
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='p'){
        myRead();
        glutTimerFunc(0,timer,0);
        ///if(t%30==0) myRead();
        ///myInterpolate( (t%30)/30.0 );///介於0.0~1.0
        ///glutPostRedisplay();
        ///t++;
    }
    if(key=='s') myWrite();///調好動作才save存檔
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
    ///myWrite();
    oldX=x;
    glutPostRedisplay();
}
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);

    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);
        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);
        glPopMatrix();
    glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.3,0.4,0);
            glRotatef(angle[2],0,0,1);
            glTranslatef(0.3,-0.4,0);
            glColor3f(1,0,0);
            glRectf(-0.3,0.5,-0.7,0.3);

            glPushMatrix();
                glTranslatef(-0.7,0.4,0);
                glRotatef(angle[3],0,0,1);
                glTranslatef(0.7,-0.4,0);
                glColor3f(0,1,0);
                glRectf(-0.7,0.5,-1.0,0.3);
            glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
 }
 int main(int argc, char *argv[])
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15_angles_TRT_again");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();
 }
