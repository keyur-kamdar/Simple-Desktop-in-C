#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include"snake.h"
#include"tic.h"



int x_pos,y_pos;
union REGS in,out;
int call_mouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
	return 1;
}
void restriction_mouse()
{
	      //	639
	      //	479
	in.x.ax=7;
	in.x.cx=2;
	in.x.dx=635;
	int86(51,&in,&out);
	in.x.ax=8;
	in.x.cx=2;
	in.x.dx=475;
	int86(51,&in,&out);
}
void set_pos()
{
	in.x.ax=4;
	in.x.cx=10;
	in.x.dx=10;
	int86(51,&in,&out);
}
int get_pos(int l,int t,int r,int b)
{
	int click;
	in.x.ax=3;
	int86(51,&in,&out);
	click=out.x.bx;
	x_pos=out.x.cx;
	y_pos=out.x.dx;
 /*	if(click==0)
	{
		cout<<"Button not preesed\n";
	}       */
	if(click==1)
	{

		if(x_pos>l && y_pos>t && x_pos<r && y_pos<b)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(click==2)
	{
		cout<<"Right button is preesed\n";
	}
	return 3;
}
void hide_mouse()
{
	in.x.ax=2;
	int86(51,&in,&out);
}
void make_rectangle(int l1,int t1,int r1,int b1,int l_color,int f_color)
{
	setcolor(l_color);
	rectangle(l1,t1,r1,b1);
	setfillstyle(SOLID_FILL,f_color);
	floodfill(l1+4,t1+4,l_color);
}

class desktop
{
	public:
	void set_desktop()
	{
		cleardevice();
		setbkcolor(BLACK);
		make_rectangle(2,2,638,475,BLUE,LIGHTBLUE);
		make_rectangle(2,453,638,475,WHITE,DARKGRAY);
		settextjustify(LEFT_TEXT,BOTTOM_TEXT);
		make_rectangle(2,453,50,475,WHITE,LIGHTGRAY);
		setcolor(GREEN);
		outtextxy(12,470,"MENU");
		call_mouse();
		restriction_mouse();

	}

	void check_button_click()
	{
		while(1)
		{
			return_menu:

			if(get_pos(2,453,50,475)==1)
			{       hide_mouse();
				int i=450;
				int j=50;
				while(i>=300)
				{
					make_rectangle(2,i,j,451,WHITE,LIGHTBLUE);
					delay(10);
					make_rectangle(2,i,j,451,LIGHTBLUE,LIGHTBLUE);
					i-=15;
					j+=8;
				}

				make_rectangle(2,300,127,453,BLACK,LIGHTBLUE);

				settextjustify(LEFT_TEXT,BOTTOM_TEXT);
				make_rectangle(2,453,50,475,WHITE,LIGHTGRAY);
				setcolor(GREEN);
				outtextxy(12,470,"MENU");
				call_mouse();

				make_rectangle(2,415,127,453,BLACK,LIGHTBLUE);
				make_rectangle(2,377,127,415,BLACK,LIGHTBLUE);
				make_rectangle(2,339,127,377,BLACK,LIGHTBLUE);
				make_rectangle(2,300,127,339,BLACK,LIGHTBLUE);
				outtextxy(43,443,"EXIT");
				outtextxy(3,405,"TIC-TAC-TOI GAME");
				outtextxy(13,367,"Telephone Book");
				outtextxy(23,329,"SNACK GAME");
				while(1)
				{
					if(get_pos(2,453,50,475)==1)
					{

						hide_mouse();
						setcolor(LIGHTBLUE);
						outtextxy(43,443,"EXIT");
						outtextxy(3,405,"TIC-TAC-TOI GAME");
						outtextxy(13,367,"Telephone Book");
						outtextxy(23,329,"SNACK GAME");
						make_rectangle(2,415,127,453,LIGHTBLUE,LIGHTBLUE);
						make_rectangle(2,377,127,415,LIGHTBLUE,LIGHTBLUE);
						make_rectangle(2,339,127,377,LIGHTBLUE,LIGHTBLUE);
						make_rectangle(2,300,127,339,LIGHTBLUE,LIGHTBLUE);
						int i=300;
						int j=127;
						while(i<=450)
						{
							make_rectangle(2,i,j,451,WHITE,LIGHTBLUE);
							delay(10);
							make_rectangle(2,i,j,451,LIGHTBLUE,LIGHTBLUE);
							i+=15;
							j-=8;
						}

					   //	make_rectangle(2,300,128,453,BLACK,LIGHTBLUE);
						make_rectangle(2,453,638,475,WHITE,DARKGRAY);
						settextjustify(LEFT_TEXT,BOTTOM_TEXT);
						make_rectangle(2,453,50,475,WHITE,LIGHTGRAY);
						setcolor(GREEN);
						outtextxy(12,470,"MENU");


				       /*		setcolor(LIGHTBLUE);
						outtextxy(43,443,"EXIT");
						outtextxy(3,405,"TIC-TAC-TOI GAME");
						outtextxy(13,367,"Telephone Book");
						outtextxy(23,329,"SNACK GAME"); */


						call_mouse();
						goto return_menu;

					}
					if(kbhit()!=0)
					{
						char ch=getch();
						if(ch=='k')
						{
							exit(0);
						}
					}

					if(get_pos(2,415,127,453)==1)
					{

						exit(0);
					}
					if(get_pos(2,377,127,415)==1)
					{
						hide_mouse();
						cleardevice();

						clrscr();
						play p;
						p.start();
					     //	cout<<"tic-toi pressed";


					}
					if(get_pos(2,339,127,377)==1)
					{
						cout<<"Telephone book";
						getch();
						exit(0);
					}
					if(get_pos(2,300,127,339)==1)
					{
						int driver=DETECT,mode;


						initgraph(&driver,&mode,"c:\\tc\\bgi");


						cleardevice();


						main_win w1;
						w1.draw_text();


						hide_mouse();



						box b1;

						b1.make_rectangle();

						call_mouse();
						for(int i=0;i<no_stage;i++)
						{

							b1.mov_box();
							b1.set_box();
						     //	delay_time-=30;
						}



						getch();


						cout<<"Snack ";
						getch();
						exit(0);
					}
				}
				getch();
				exit(0);

			}
		}
	}


};
void main()
{
	desktop desk;
	int driver=DETECT,mode;
	initgraph(&driver,&mode,"c:\\tc\\bgi");
	desk.set_desktop();
	desk.check_button_click();
	getch();
}