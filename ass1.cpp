#include <iostream>
#include <graphics.h>
using namespace std;


int main(){
int gd, gm, j, i,mx,my;
gd = DETECT;
initgraph(&gd,&gm,NULL);
mx = getmaxx();
my = getmaxy();

for (i = 0; i < (mx-200); i = i + 5)
{

	line(0,350,1000,350); // Ground
	line(100+i,300, 100+i, 250); // Body
	circle(100+i, 225,25); // Head
	line(100+i, 275, 150+i,250); // Right Hand
	line(100+i,275,50+i,250); // Left Hand
	line(150+i,250,150+i,175); // Umbrella handle
	line(100+i,175,200+i,175); // Umbrella base
	ellipse(150+i,175,180,360, 50,50); // Umbrella Handle
	delay(1);
	
	if(i%2 == 0)
	{
		line(50+i,350,100+i,300); //Left Leg
		line(100+i,300, 150+i,350); //Right Leg
	} 
	else
	{
		line(65+i,350,100+i,300); //Left Leg
		line(100+i,300, 165+i,350); //Right Leg
	}

	for (j = 0; j < 400; j = j + 10)
	{
		outtextxy(rand()%mx,rand()%(my-150), "/");
		delay(10);
	}
	cleardevice();
}


	getch();
	closegraph();
}

