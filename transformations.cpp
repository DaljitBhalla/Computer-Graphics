#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
class point;
void translate(point& );
void scale(point);
void line(point,point );
class point{
    float x;
    float y;
public:    point(float  x,float  y)
    {
        this->x=x;
        this->y=y;
    }
    void print(){cout<<"x="<<x<<"y="<<y;}
    friend void translate(point &p)
{     float x1,y1;
       cout<<"enter the point with which the point is to be translated \n";
         cin>>x1>>y1;
            p.x+=x1;
            p.y+=y1;
    cout<<p.x<<p.y;
            }
            friend void scale(point p)
            {
            float x1,y1;
            cout<<"enter the scaling factors Sx,Sy\n";
            cin>>x1>>y1;
            p.x=(p.x)*x1;
            p.y=(p.y)*y1;
                }
            friend void line(point p,point r)
            {
                        line(p.x,p.y,r.x,r.y);
            }
                friend void rotation(point p)
                {
                    cout<<"enter the angle at which the object is to be rotated ";
                    float q,r;
                    cin>>q;
                    r=atan(p.y/p.x);
                    p.x=sqrt(p.x*p.x+p.y*p.y)*cos(q+r);
                    p.y=sqrt(p.x*p.x+p.y*p.y)*sin(q+r);
                cout<<p.x<<p.y;
                }
};
main()
{

    int gd=0,gm=DETECT;
    initgraph(&gd,&gm,"");

  point p1(10,10);
  point p2(10,20);
  point p3(20,10 );
translate(p2);
 translate(p1);
 translate(p3);
// clrscr();
  line(p1,p2);
  line(p2,p3);
  line(p3,p1);
p2.print();
    getch();
  closegraph();

    }
