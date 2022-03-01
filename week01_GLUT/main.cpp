#include <GL/glut.h>
/* GLUT callback Handlers */
static void display(void)

{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char *argv[])

{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("第02週的程式喔!");
    glutDisplayFunc(display);
    glutMainLoop();
}
