#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,"");
float xrect1=0,yrect1=200,xrect2=350,yrect2=350,xc1=100,yc1=375,xc2=250,yc2=375;
line(0,400,700,400);
rectangle(0,200,350,350);
circle(100,375,25);
circle(250,375,25);
while(1)
{
xrect1+=5;
xrect2+=5;
xc1+=5;
xc2+=5;
delay(1);
clearviewport();
rectangle(xrect1,yrect1,xrect2,yrect2);
circle(xc2,yc2,25);
circle(xc1,yc1,25);
if(xrect1>700)
{
xrect1=0;
xrect2=350;
xc1=100;
xc2=250;
}
}
getch();
closegraph();
}
