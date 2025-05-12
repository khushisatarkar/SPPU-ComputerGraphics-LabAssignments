#include<iostream>
#include<graphics.h>
using namespace std;

class transform
{
    public:
    int a[20][20],c[20][20];
    int i,j,k,m,s;
    float tx,ty,thetha,sx,sy,deg;
    float b[20][20];
    
    public:
    void accept();
    void object();
    void display();
    void translate();
    void rotate();
    void scale();
    void mul(float b[20][20]);
};
void transform::accept()
{
    cout<<"Enter the no of edges: "<<endl;
    cin>>m;
    cout<<"Enter coordinates: "<<endl;
    for(i=0;i<m;i++)
    {
   	 for(j=0;j<3;j++)
   	 {
   		 if(j>=2)
   		 {
   			 a[i][j]=1;
   		 }
   		 else
   		 {
   			 cin>>a[i][j];
   		 }
   	 }
    }
}
void transform::object()
{
    for(i=0;i<m-1;i++)
    {
   	 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }
    line(a[0][0],a[0][1],a[i][0],a[i][1]);
}
void transform::mul(float b [20][20])
{
    for(i=0;i<m;i++)
    {
   	 for(j=0;j<m;j++)
   	 {
   		 c[i][j]=0;
   		 for(int k=0;k<m;k++)
   		 {
   			 c[i][j]=c[i][j]+((a[i][k])*(b[k][i]));
   		 }
   	 }
    }
}
void transform::display()
{
    for(i=0;i<m-1;i++)
    {
   	 line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }
    line(a[0][0],a[0][1],a[i][0],a[i][1]);
}
void transform::translate()
{
    cout<<"Enter the value of tx and ty: "<<endl;
    cin>>tx>>ty;
    b[0][0]=b[1][1]=b[2][2]=1;
    b[0][1]=b[1][0]=b[1][2]=b[0][2]=0;
    b[2][0]=tx;
    b[2][1]=ty;
}
void transform::scale()
{
    cout<<"Enter the value of sx,sy: ";
    cin>>sx>>sy;
    b[2][2]=1;
    b[0][0]=sx;
    b[1][1]=sy;
    b[0][1]=b[1][0]=b[1][2]=b[0][2]=b[2][0]=b[2][1]=0;
    mul(b);
}
void transform::rotate()
{
    cout<<"\nEnter the value of degree: ";
    cin>>deg;
    thetha=deg*(3.14/100);
    b[0][1]=sin(thetha);
    b[1][0]=sin(thetha);
    b[0][0]=b[1][1]=cos(thetha);
    b[1][2]=b[0][2]=b[2][0]=b[2][1]=0;
    b[2][2]=1;
    mul(b);
}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    int ch;
    transform t;
    t.accept();
    t.object();
    cout<<"Enter the type of transformation: ";
    cout<<"\n 1 for Translation \n 2 for Scaling \n 3 for Rotation \n Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
   	 case 1:t.translate();
   	 t.display();
   	 break;
   	 case 2:t.scale();
   	 t.display();
   	 break;
   	 case 3:t.rotate();
   	 t.display();
   	 break;
   	 default:
   	 cout<<"INVALID CHOICE:"<<endl;
    }
    getch();
    closegraph();
    return 0;
}



