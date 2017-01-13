#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define round(a) (int(a+0.5))
using namespace std;
void matrix_mul(float arr[1][3],float brr[3][3],int m,int n,int p,int &x,int &y)
{
float crr[1][3];
int i,j,k;
for(i=0;i<m;i++)
{
  for(j=0;j<n;j++)
  {
   crr[i][j]=0;
   for(k=0;k<p;k++)
   crr[i][j]=crr[i][j]+arr[i][k]*brr[k][j];
   }
}
x=round(crr[0][0]);
y=round(crr[0][1]);
}
int main()
{
   int a=0;
   int x1,x2,y1,y2,x3,y3,x_1,x_2,y_1,y_2,x_3,y_3,tx,ty,Sx,Sy;
   float x;
   float arr[1][3],brr[3][3];
   cout<<"Enter the coordinates of triangle\n";
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C://TC//BGI");
   line(x1,y1,x2,y2);
   line(x2,y2,x3,y3);
   line(x3,y3,x1,y1);
   while(a!=4)
   {
   cout<<"Enter your choice\n 1.Perform Translation\n 2.perform Scaling\n 3.Perform Rotation\n 4.Exit";
   cin>>a;
   switch(a)
   {
   case 1:
	cout<<"Enter the translation vector\n"        ;
	cin>>tx>>ty;
        brr[0][0]=brr[1][1]=brr[2][2]=1;
        brr[2][0]=tx;
        brr[2][1]=ty;
        brr[0][1]=brr[0][2]=brr[1][0]=brr[1][2]=0;
        arr[0][0]=x1;
        arr[0][1]=y1;
        arr[0][2]=1;
        matrix_mul(arr,brr,1,3,3,x_1,y_1);
        arr[0][0]=x2;
        arr[0][1]=y2;
        arr[0][2]=1;
        matrix_mul(arr,brr,1,3,3,x_2,y_2);
        arr[0][0]=x3;
        arr[0][1]=y3;
        arr[0][2]=1;
        matrix_mul(arr,brr,1,3,3,x_3,y_3);
        line(x_1,y_1,x_2,y_2);
        line(x_2,y_2,x_3,y_3);
        line(x_3,y_3,x_1,y_1);
        x1=x_1;
        y1=y_1;
        x2=x_2;
        y2=y_2;
        x3=x_3;
        y3=y_3;
        break;
    case 2:
    	 cout<<"Enter the scaling vector\n";
    	 cin>>Sx>>Sy;
    	 brr[0][0]=Sx;
         brr[1][1]=Sy;
         brr[2][2]=1;
         brr[0][1]=brr[0][2]=brr[1][0]=brr[1][2]=brr[2][0]=brr[2][1]=0;
         arr[0][0]=x1;
         arr[0][1]=y1;
         arr[0][2]=1;
         matrix_mul(arr,brr,1,3,3,x_1,y_1);
         arr[0][0]=x2;
         arr[0][1]=y2;
         arr[0][2]=1;
         matrix_mul(arr,brr,1,3,3,x_2,y_2);
         arr[0][0]=x3;
         arr[0][1]=y3;
         arr[0][2]=1;
         matrix_mul(arr,brr,1,3,3,x_3,y_3);
         line(x_1,y_1,x_2,y_2);
         line(x_2,y_2,x_3,y_3);
         line(x_3,y_3,x_1,y_1);
         x1=x_1;
         y1=y_1;
         x2=x_2;
         y2=y_2;
         x3=x_3;
         y3=y_3;
         break;
    case 3:
    	 cout<<"Enter rotation angle\n";
	 cin>>x;
	 x=x*(3.14/180);
    	 brr[0][0]=brr[1][1]=cos(x);
         brr[0][1]=sin(x);
         brr[1][0]=-brr[0][1];
         brr[2][2]=1;
         brr[0][2]=brr[1][2]=brr[2][0]=brr[2][1]=0;
         arr[0][0]=x1;
         arr[0][1]=y1;
         arr[0][2]=1;
         matrix_mul(arr,brr,1,3,3,x_1,y_1);
         arr[0][0]=x2;
         arr[0][1]=y2;
         arr[0][2]=1;
         matrix_mul(arr,brr,1,3,3,x_2,y_2);
         arr[0][0]=x3;
         arr[0][1]=y3;
         arr[0][2]=1;
         matrix_mul(arr,brr,1,3,3,x_3,y_3);
         line(x_1,y_1,x_2,y_2);
         line(x_2,y_2,x_3,y_3);
         line(x_3,y_3,x_1,y_1);
         x1=x_1;
         y1=y_1;
         x2=x_2;
         y2=y_2;
         x3=x_3;
         y3=y_3;
         break;
    }
}
getch();
closegraph();
}
