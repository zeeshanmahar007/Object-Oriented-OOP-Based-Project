#include "graphics.h"
#include "winbgim.h" 
#include <iostream>
#include<string>
#include <math.h>
#include <stdlib.h>                
#include <ctype.h>                   
using namespace std;
int colour = 0;
class Shape
{
protected:
	int *coordinates=NULL;
	int size=0;
public:
	virtual void draw() = 0;
};
void layout()
{

	//1st row color
	setfillstyle(SOLID_FILL, BLUE);
	bar(70, 70, 20, 20);
	setfillstyle(SOLID_FILL, GREEN);
	bar(90, 70, 140, 20);
	//2nd row color
	setfillstyle(SOLID_FILL, RED);
	bar(70, 140, 20, 90);
	setfillstyle(SOLID_FILL, BROWN);
	bar(90, 140, 140, 90);
	//3rd row color
	setfillstyle(SOLID_FILL, MAGENTA);
	bar(70, 210, 20, 160);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(90, 210, 140, 160);
	//4th row color
	setfillstyle(SOLID_FILL, YELLOW);
	bar(70, 280, 20, 230);
	setfillstyle(SOLID_FILL, LIGHTGREEN);
	bar(90, 280, 140, 230);
	//5th row color
	setfillstyle(SOLID_FILL, WHITE);
	bar(70, 350, 20, 300);
	setfillstyle(SOLID_FILL, CYAN);
	bar(90, 350, 140, 300);
	//border line b/w color and shape
	line(0, 370, 170, 370);
	//////////////////////////shapes/////////////////////////////////////
	//circle
	circle(45, 420, 25);
	//rectangle
	rectangle(90, 445, 140, 395);
	//line
	line(35, 470, 50, 520);
	//tringle
	line(110, 470, 80, 520);
	line(110, 470, 140, 520);
	line(80, 520, 140, 520);
	//polygon
	line(25, 640, 55, 610);
	line(25, 640, 55, 670);
	line(55, 610, 100, 610);
	line(55, 670, 100, 670);
	line(100, 610, 130, 640);
	line(100, 670, 130, 640);
	//rectangle
	rectangle(30, 550, 140, 580);
	// write anything on convas
	settextstyle(4, 0, 4);
	outtextxy(360, 10, "Paint Here");
	readimagefile("save.jpg", 170, 0, 215, 40);
	readimagefile("load.jpg", 216, 0, 258, 40);
	readimagefile("delete.jpg",765, 0, 809, 40);
	readimagefile("undo.jpg", 810, 0, 855, 40);
	readimagefile("redo.jpg", 855, 0, 905, 40);
	readimagefile("pencil.jpg", 905, 0, 947, 40);
	readimagefile("bucket.jpg", 947, 0, 996, 40);
	readimagefile("text.jpg", 996, 0, 1047, 40);
	readimagefile("erasor.jpg", 1047, 0, 1099, 40);
	//border line b/w color and pad
	line(170, 0, 170, 700);
	//border line b/w pencil etc. and pad
	line(170,41,1100,41);
}
class Rec : public Shape
{
public:
	Rec()
	{
		size = 4;
		coordinates = new int[size];
	}
	void draw() 
	{
		clearmouseclick(WM_LBUTTONDOWN);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, coordinates[0], coordinates[1]);
		clearmouseclick(WM_LBUTTONDOWN);
		while (!ismouseclick(WM_LBUTTONDOWN)) 
		{
		}
		getmouseclick(WM_LBUTTONDOWN, coordinates[2], coordinates[3]);
		clearmouseclick(WM_LBUTTONDOWN);
		rectangle(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
		setfillstyle(SOLID_FILL, BLACK);
		bar(1, 1, 170, 700);
		setfillstyle(SOLID_FILL, BLACK);
		bar(170, 0, 1100, 40);
		layout();
	}
};

class Triangle : public Shape 
{
public:
	Triangle()
	{
		size = 6;
		coordinates = new int[size];
	}
	void draw()
	{ 
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, coordinates[0], coordinates[1]);
			clearmouseclick(WM_LBUTTONDOWN);
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, coordinates[2], coordinates[3]);
			clearmouseclick(WM_LBUTTONDOWN);
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, coordinates[4], coordinates[5]);
			clearmouseclick(WM_LBUTTONDOWN);
			line(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
			line(coordinates[2], coordinates[3], coordinates[4], coordinates[5]);
			line(coordinates[4], coordinates[5], coordinates[0], coordinates[1]);
			setfillstyle(SOLID_FILL, BLACK);
			bar(1, 1, 170, 700);
			setfillstyle(SOLID_FILL, BLACK);
			bar(171, 0, 1099, 40);
			layout();
		}
};
 
class Circle :public Shape
{
public:
	Circle() 
	{
		size = 4;
		coordinates = new int[size];
	}
	void draw()
	{
		int r;
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, coordinates[0], coordinates[1]);
			clearmouseclick(WM_LBUTTONDOWN);
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, coordinates[2], coordinates[3]); 
			r = sqrt(pow(coordinates[2] - coordinates[0], 2) + pow(coordinates[3] - coordinates[1], 2));
			clearmouseclick(WM_LBUTTONDOWN);
			circle(coordinates[0], coordinates[1], r);
			setfillstyle(SOLID_FILL, BLACK);
			bar(171, 0, 1099, 40);
			setfillstyle(SOLID_FILL, BLACK);
			bar(1, 1, 170, 700);
			layout();
		}

};
class square :public Shape
{
public:
	square() 
	{
		size = 4;
		coordinates = new int[size];
	}
	void draw()
	{
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, coordinates[0], coordinates[1]);
			clearmouseclick(WM_LBUTTONDOWN);
			while (!ismouseclick(WM_LBUTTONDOWN))
			{
			}
			getmouseclick(WM_LBUTTONDOWN, coordinates[2], coordinates[3]);
			clearmouseclick(WM_LBUTTONDOWN);
			/*line(coordinates[0], coordinates[1], coordinates[2], coordinates[1]);
			line(coordinates[2], coordinates[1], coordinates[2], coordinates[3]);
			line(coordinates[2], coordinates[3], coordinates[0], coordinates[3]);
			line(coordinates[0], coordinates[3], coordinates[0], coordinates[1]);*/
			if (coordinates[2] - coordinates[0] > coordinates[3] - coordinates[1])

				if (coordinates[0] > 120 && coordinates[2] > 120 && coordinates[1] > 105 && coordinates[3] > 105)
				{
					rectangle(coordinates[0], coordinates[1], coordinates[2], coordinates[2] - coordinates[0] + coordinates[1]);
				}
				else
				{
					if (coordinates[0] > 120 && coordinates[2] > 120 && coordinates[1] > 105 && coordinates[3] > 105)
						rectangle(coordinates[0], coordinates[1], coordinates[3] - coordinates[1] + coordinates[0], coordinates[3]);
				}
			setfillstyle(SOLID_FILL, BLACK);
			bar(1, 1, 170, 700);
			setfillstyle(SOLID_FILL, BLACK);
			bar(171, 0, 1099, 40);
			layout();
		}
};

	class Line :public Shape
	{
	public:
		Line()
		{
			size = 4;
			coordinates = new int[size];
		}
		void draw()
		{
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[0], coordinates[1]);
				clearmouseclick(WM_LBUTTONDOWN);
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[2], coordinates[3]);
				clearmouseclick(WM_LBUTTONDOWN);
				line(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
				setfillstyle(SOLID_FILL, BLACK);
				bar(1, 1, 170, 700);
				setfillstyle(SOLID_FILL, BLACK);
				bar(171, 0, 1099, 40);
				layout();
			}
	};
	class polygon :public Shape
	{
	public:
		polygon()
		{
			size = 12;
			coordinates = new int[size];
		}
		void draw()
		{
			while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[0], coordinates[1]);
				clearmouseclick(WM_LBUTTONDOWN);
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[2], coordinates[3]);
				clearmouseclick(WM_LBUTTONDOWN);
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[4], coordinates[5]);
				clearmouseclick(WM_LBUTTONDOWN);
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[6], coordinates[7]);
				clearmouseclick(WM_LBUTTONDOWN);
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[8], coordinates[9]);
				clearmouseclick(WM_LBUTTONDOWN);
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, coordinates[10], coordinates[11]);
				clearmouseclick(WM_LBUTTONDOWN);

				line(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
				line(coordinates[2], coordinates[3], coordinates[4], coordinates[5]);
				line(coordinates[4], coordinates[5], coordinates[6], coordinates[7]);
				line(coordinates[6], coordinates[7], coordinates[8], coordinates[9]);
				line(coordinates[8], coordinates[9], coordinates[10], coordinates[11]);
				line(coordinates[10], coordinates[11], coordinates[0], coordinates[1]);
				setfillstyle(SOLID_FILL, BLACK);
				bar(1, 1, 170, 700);
				setfillstyle(SOLID_FILL, BLACK);
				bar(171, 0, 1099, 40);
				layout();
		}
	};
	void pencil()
	{
		while (!ismouseclick(WM_RBUTTONDOWN))
		{
			POINT cursor;
				GetCursorPos(&cursor);
				if (cursor.x > 171 && cursor.y > 45)
				{
					setfillstyle(SOLID_FILL, 15);
					circle(cursor.x, cursor.y, 4);
					floodfill(cursor.x, cursor.y,WHITE);
					delay(0);
				}
		}
	}
	void erasor()
	{
		while (!ismouseclick(WM_RBUTTONDOWN))
		{
			POINT Eraser;
				GetCursorPos(&Eraser);
				if (Eraser.x > 175 && Eraser.y > 48)
				{
					setcolor(0);
					bar(Eraser.x, Eraser.y, Eraser.x + 25, Eraser.y + 25);
					setfillstyle(SOLID_FILL,BLACK);
				}
		}
	}
	void bucket()
	{
		int x, y,x1,y1;
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x1, y1);
		colour = getpixel(x1, y1);
		circle(x1, y1, 5);
		setfillstyle(SOLID_FILL, YELLOW);
		floodfill(x1 + 1, y1 + 1, WHITE);
		clearmouseclick(WM_RBUTTONDOWN);
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		setfillstyle(SOLID_FILL,colour);
		floodfill(x+1, y+1, WHITE);
		circle(x1, y1, 5);
		setfillstyle(SOLID_FILL, colour);
		floodfill(x1 + 1, y1 + 1, colour);
	}
	void save()
	{
		writeimagefile("save.bmp",171,41, 1100,700, (HWND)0);
	}
	void Text()
	{
		int x, y;
		char str[50];
		cout << "PLESAE ENTER YOUR TEXT:";
				cin.getline(str,50);
				clearmouseclick(WM_LBUTTONDOWN);
				cout << "Its working!";
				while (!ismouseclick(WM_LBUTTONDOWN))
				{
				}
				getmouseclick(WM_LBUTTONDOWN, x, y);
				settextstyle(1, 0, 1);
				outtextxy(x, y, str); 
				cout<< "DONE:";
	}
	void Delete()
	{
		setfillstyle(SOLID_FILL, BLACK);
		bar(171,42,1099,699);
	}
	void open()
	{
		readimagefile("save.bmp", 171, 41, 1100, 700);
	}
int main()
{
	initwindow(1100, 700,"Paint");
	layout();
	int X, Y;
	Shape *shape= nullptr;
	while (1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN,X,Y);
		cout << X << " : " << Y << " \n";
		if ((X>=30&&Y>=550)&& (X<=140&&Y<=580))
		{
				shape = new Rec;
				setfillstyle(SOLID_FILL, YELLOW);
				floodfill(31, 551, WHITE);
					shape->draw();
					setfillstyle(SOLID_FILL, BLACK);
					floodfill(31, 551, WHITE);
		
		}
		else if ((X>=17&&Y>=394)&&(X<=70&&Y<=444))
		{
				shape = new Circle;
				setfillstyle(SOLID_FILL, YELLOW);
				floodfill(44, 418, WHITE);
				shape->draw();
				setfillstyle(SOLID_FILL,BLACK);
				floodfill(44, 418, WHITE);
		}
		else if ((X >=90 && Y >= 395 ) && (X <= 140 && Y <= 445))
		{
			shape = new square;
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(95,397, WHITE);
			shape->draw();
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(95,397, WHITE);
		}
		else if ((X >=22 && Y >= 467) && (X <=60 && Y <=521))
		{

			shape = new Line;
			circle(34,462, 5);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(35,463, WHITE);
			shape->draw();
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(35,463,BLACK);
		}
		else if ((X >= 20 && Y >=606) && (X <= 132 && Y <=700))
		{
			shape = new polygon;
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(82,634, WHITE);
			shape->draw();
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(82, 634, WHITE);
		}
		else if ((X >= 905 && Y >=0) && (X <=947 && Y <= 40))
		{
			circle(924, 50, 4);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(925, 51, WHITE);
			pencil();
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(925, 51,BLACK);
		}
		else if ((X >= 1047 && Y >=0) && (X <= 1099 && Y <=40))
		{
			circle(1073, 50, 4);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(1074, 51, WHITE);
			erasor();
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(1074, 51, BLACK);
		}
		else if ((X >= 80 && Y >= 471) && (X <= 141 && Y <= 520))
		{
			shape = new Triangle;
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(109, 503, WHITE);
			shape->draw();
			setfillstyle(SOLID_FILL,BLACK);
			floodfill(109, 503, WHITE);
		}
		else if ((X >= 947 && Y >= 0) && (X <= 996 && Y <= 40))
		{
			circle(965, 50, 4);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(966, 51, WHITE);
			bucket();
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(966, 51, BLACK);
		}
		else if ((X >= 170 && Y >= 0) && (X <= 215 && Y <= 40))
		{
			circle(191, 50, 4);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(192, 51, WHITE);
			save();
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(192, 51, BLACK);
		}
		else if ((X >=996 && Y >= 0) && (X <= 1047 && Y <= 40))
		{
			circle(1024, 50, 4);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(1025, 51, WHITE);
			Text();
			setfillstyle(SOLID_FILL, BLACK);
			floodfill(1025, 51, BLACK);
		}
		else if ((X >= 765 && Y >= 0) && (X <= 809 && Y <= 40))
		{
		circle(786, 50, 4);
		setfillstyle(SOLID_FILL, YELLOW);
		floodfill(787, 51, WHITE);
		delay(100);
		Delete();
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(787, 51, BLACK);
		}
		else if ((X >=216 && Y >= 0) && (X <= 258 && Y <= 40))
		{
		circle(234,50, 4);
		setfillstyle(SOLID_FILL, YELLOW);
		floodfill(235,51 , WHITE);
		delay(100);
		open();
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(235, 51, BLACK);
		}
	}
	system("pause");
} 