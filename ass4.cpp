#include <iostream>
#include <graphics.h>
using namespace std;

class dda_line
{
	public:
	void line(int x1, int y1, int x2, int y2)
	{
  	  int len;
  	  float dx, dy, xi, yi, x, y;
  	  dx=x2-x1;
  	  dy=y2-y1;
  	  if(abs(dx)>=abs(dy))
  	  {
  		  len=abs(dx);
  	  }
  	  else
  	  {
  		  len=abs(dy);
  	  }
  	  xi=dx/len;
  	  yi=dy/len;
  	  x=x1+0.5;
  	  y=y1+0.5;
  	  putpixel(x,y,WHITE);
  		 
  	  int i=0;
  	  while(i<=len)
  	  {
  		  x=x+xi;
  		  y=y+yi;
  		  putpixel(x,y,RED);
  		  //delay(10);
  		  i=i+1;
  	  }
	}
    
	void circle(int x,int y,int r)
	{
  	  int x1=0,y1=r;
  	  int d;
  	  d=3-(2*r);
  	  do
  	  {
  		  putpixel(x+x1,y+y1,RED);
  		  putpixel(x-x1,y-y1,RED);
  		  putpixel(x+x1,y-y1,RED);
  		  putpixel(x-x1,y+y1,RED);
  		  putpixel(x+y1,y+x1,RED);
  		  putpixel(x-y1,y-x1,RED);
  		  putpixel(x+y1,y-x1,RED);
  		  putpixel(x-y1,y+x1,RED);
  		  if (d<0)
  		  {
  			  d=d+4*x1+6;
  		  }
  		  else
  		  {
  			  d=d+4*(x1-y1)+10;
  			  y1--;
  		  }
  		  x1++;
  		  delay(20);
  	  }while(x1<y1);     
	} 
};

int main()
{
	dda_line obj;
	int gd, gm;
	gd=DETECT;
	initgraph(&gd,&gm,NULL);
	obj.circle(300, 200, 100);
	// rectangle
	obj.line(100, 80, 500, 80);
	obj.line(500, 80, 500, 320);
	obj.line(500, 320, 100, 320);
	obj.line(100, 320, 100, 82);
	// diamond
	obj.line(300, 80, 100, 200);
	obj.line(100, 200, 300, 320);
	obj.line(300, 320, 500, 200);
	obj.line(500, 200, 300, 80);
	getch();
	closegraph();
}

