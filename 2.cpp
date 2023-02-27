#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
GLfloat d;
GLfloat rX=0,rY=0;
void Draw()
{
GLfloat P[3][2] = {{-0.5,0},{0.5,0},{0,0.6}};
GLfloat nP[3][2],r;
int i;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
glVertex2fv(P[0]);
glVertex2fv(P[1]);
glVertex2fv(P[2]);
glEnd();
r = d * 3.14/180;
for(i=0;i<3;i++)
{
nP[i][0] = P[i][0]*cos(r)-P[i][1]*sin(r)-rX*cos(r)+rY*sin(r)+rX;
nP[i][1] = P[i][0]*sin(r)+P[i][1]*cos(r)-rX*sin(r)-rY*cos(r)+rY;
}
glColor3f(0,1,0);
glBegin(GL_LINE_LOOP);
glVertex2fv(nP[0]);
glVertex2fv(nP[1]);
glVertex2fv(nP[2]);
glEnd();
glFlush();
}
int main(int argC,char *argV[])
{
printf("\nEnter the Pivot Point for Rotation : ");
scanf("%f%f",&rX,&rY);
printf("\nEnter the Degree of Rotation : ");
scanf("%f",&d); 
    glutInit(&argC,argV);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("Lab-2");
glutDisplayFunc(Draw);
glutIdleFunc(Spin);
glutMainLoop();
return 0;
}
