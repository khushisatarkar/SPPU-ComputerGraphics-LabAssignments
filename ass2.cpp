#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class scanline
{
    public:
    int n, x[5], y[5], i, xint[5];
    float dx, dy, slope[15];
    void accept();
    void drawpoly();
    void fill();
};

void scanline::accept()
{
    cout<<"Enter no of edges of polygon: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
   	 cout<<"Enter the x-coordinate for vertex ["<<i<<"] :";
   	 cin>>x[i];
   	 cout<<"Enter the y-coordinate  for vertex ["<<i<<"] :";
   	 cin>>y[i];
    }
    x[n]=x[0]; // initializing the first value of x to 0
    y[n]=y[0];
}

void scanline::drawpoly()
{
    for(i=0;i<n;i++)
    	line(x[i],y[i],x[i+1],y[i+1]);
}

void scanline::fill()
{
    // finding Slope
    for(i=0;i<n;i++)
    {
   	 dy=y[i+1]-y[i];
   	 dx=x[i+1]-x[i];
   	 if(dy==0)
   	 slope[i]=1;
   	 else if(dx==0)
   	 slope[i]=0;
   	 else
   	 slope[i]=dx/dy;
    }

    int temp;
    for(int scan=0;scan<600;scan++)
    {
   	 int k=0;
   	 for(i=0;i<n;i++)
   	 {
   		 if((y[i]<=scan && y[i+1]>scan)||(y[i]>scan && y[i+1]<=scan))
   		 {
   		 xint[k]=x[i]+slope[i]*(scan-y[i]);
   		 k++;
   		 }
   	 }

   	 // here we have done sorting - bubble sort
   	 for(i=0;i<k-1;i++)
   	 {
   		 if(xint[i]>xint[i+1])
   		 {
   			 temp=xint[i];
   			 xint[i]=xint[i+1];
   			 xint[i+1]=temp;
   		 }
   	 }

   	 // filling the polygon
   	 for(i=0;i<k;i=i+2)
   	 {
   		 setcolor(RED);
   		 line(xint[i],scan,xint[i+1],scan);
   		 delay(500);
   	 }
    }
}

int main()
{
    int gd, gm;
    scanline obj;
    obj.accept();
    gd=DETECT;
    initgraph(&gd, &gm, NULL);
    obj.drawpoly();
    obj.fill();
    getch();
    closegraph();
}
