#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
const LEFT=1;
const TOP=1;
const RIGHT=81;
const BOTTOM=25;
const COLOR=WHITE;



class dos_box
{
	private:
	int left,top,right,bottom;
	int hight,width;
	int color;
	public:
	dos_box()
	{
		left=LEFT;
		top=TOP;
		right=RIGHT;
		bottom=BOTTOM;
		color=COLOR;
		hight=bottom-top;
		width=right-left;
	}
	dos_box(int l,int t,int r,int b,int c)
	{
		left=l;
		top=t;
		right=r;
		bottom=b;
		color=c;

		hight=bottom-top;
		width=right-left;
	}
	void make_win()
	{

		window(left,top,right,bottom);
	}
	void make_board()
	{       textcolor(color);
		for(int i=left;i<=width;i++)
		{
			gotoxy(i,left);
			putch(char(205));
			gotoxy(i,hight);
			putch(char(205));
		}
		for(i=top;i<=hight;i++)
		{
			gotoxy(top,i);
			putch(char(186));
			gotoxy(width,i);
			putch(char(186));
		}
		gotoxy(width,top);
		putch(char(187));
		gotoxy(left,top);
		putch(char(201));
		gotoxy(left,hight);
		putch(char(200));
		gotoxy(width,hight);
		putch(char(188));


	}
	void text()
	{       window(left+1,top+1,right,bottom);
		cputs("1. PLAY WITH COMPUTER\n\r2. PLAY WITH HUMAN\n\r3. EXIT");
	}



	int get_left()
	{
		return left;
	}
	int get_top()
	{
		return top;
	}
	int get_right()
	{
		return right;
	}
	int get_bottom()
	{
		return bottom;
	}

};


class play
{

	int choise,chance;
	int a[3][3],pos,pos1[5],pos2[5];
	public:
	play()
	{
		chance=2;
	}
	void start()
	{

		a:
	setbkcolor(BLACK);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			a[i][j]=0;
		}
	}

	textmode(BW80);

	dos_box win1(1,1,30,6,WHITE);
	win1.text();
	win1.make_win();
	win1.make_board();
	gotoxy(1,7);
	cout<<"\n";
	cout<<"ENTER YOUR CHOISE: ";
	cin>>choise;
	clrscr();
	if(choise==1)
	{       b:
		clrscr();

		dos_box win2(1,1,80,25,WHITE);
		win2.make_win();
		win2.make_board();
		for(int i=2,j=1;i<10,j<8;i=i+4,j=j+3)
		{
			gotoxy(3,i);
			cout<<j;
		}
		for(i=2,j=2;i<10,j<9;i=i+4,j=j+3)
		{
			gotoxy(11,i);
			cout<<j;
		}
		for(i=2,j=3;i<10,j<10;i=i+4,j=j+3)
		{
			gotoxy(20,i);
			cout<<j;
		}


		for( i=2;i<=12;i++)
		{
			gotoxy(10,i);
			putch(char(186));
			gotoxy(19,i);
			putch(char(186));

		}
		for(i=3;i<=26;i++)
		{
			gotoxy(i,5);
			putch(char(205));
			gotoxy(i,9);
			putch(char(205));
		}


		for(i=3;i<12;i=i+2)
		{

			gotoxy(29,i);
			cout<<"ENTER YOUR POSITION:";
			cin>>pos;
			if(pos==1)
			{
				a[0][0]=1;
				gotoxy(7,4);
				cout<<"X";
				if((a[0][1]==1&&a[0][2]==1)||(a[1][1]==1&&a[2][2]==1)||(a[1][0]==1&&a[2][0]==1))
				{
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}

				if(a[0][1]==1 && a[0][2]==0)
				{       a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
				}
				else if(a[0][2]==1 && a[0][1]==0)
				{       a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
				}
				else if(a[1][1]==1 && a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
				}
				else if(a[2][2]==1 && a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else if(a[1][0]==1 && a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
				}
				else if(a[2][0]==1 && a[1][0]==0)
				{       a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
				}
				else
				{       if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}

					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
				}
			}
			else if(pos==2)
			{	a[0][1]=1;
				gotoxy(16,4);
				cout<<"X";
				if((a[0][0]==1 && a[0][2]==1)||(a[1][1]==1 && a[2][1]==1))
				{	gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}

				if(a[0][0]==1 && a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
				}
				else if(a[0][2]==1 && a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
				}
				else if(a[1][1]==1 && a[2][1]==0)
				{
					a[2][2]=2;
					gotoxy(16,11);
					cout<<"O";
				}
				else if(a[1][1]==0 && a[2][1]==1)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else
				{       if(a[2][2]==0)
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
				}
			}
			else if(pos==3)
			{
				a[0][2]=1;
				gotoxy(23,4);
				cout<<"X";
				if((a[0][0]==1 && a[0][1]==1)||(a[1][2]==1 && a[2][2]==1)||(a[1][1]==1 && a[2][0]==1))
				{	gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}

				if(a[0][0]==1&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
				}
				else if(a[0][0]==0&&a[0][1]==1)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
				}
				else if(a[1][1]==1&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
				}
				else if(a[1][1]==0&&a[2][0]==1)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else if(a[1][2]==1&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
				}
				else if(a[1][2]==0&&a[2][2]==1)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
				}
				else
				{
					if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
				}
			}
			else if(pos==4)
			{
				a[1][0]=1;
				gotoxy(7,7);
				cout<<"X";
				if((a[0][0]==1&&a[2][0]==1)||(a[1][1]==1&&a[1][2]==1))
				{
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}


				if(a[0][0]==1&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
				}
				else if(a[2][0]==1&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
				}
				else if(a[1][1]==0&&a[1][2]==1)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else if(a[1][1]==1&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
				}
				else
				{       if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}

					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}

				}
			}
			else if(pos==5)
			{	a[1][1]=1;
				gotoxy(16,7);
				cout<<"X";
				if((a[0][0]==1&&a[2][2]==1)||(a[0][2]==1&&a[2][0]==1)||(a[1][0]==1&&a[1][2]==1))
				{	gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}


				if(a[0][0]==0&&a[2][2]==1)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
				}
				else if(a[0][0]==1&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
				}
				else if(a[0][2]==0&&a[2][0]==1)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
				}
				else if(a[0][2]==1&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
				}
				else if(a[1][0]==0&&a[1][2]==1)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
				}
				else if(a[1][0]==1&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
				}
				else if(a[0][1]==1&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
				}
				else if(a[0][1]==0&&a[2][1]==1)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
				}
				else
				{       if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}

					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
				}
			}
			else if(pos==6)
			{
				a[1][2]=1;
				gotoxy(23,7);
				cout<<"X";
				if((a[0][2]==1&&a[2][2]==1)||(a[1][0]==1&&a[1][1]==1))
				{	gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}


				if(a[1][0]==1&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else if(a[1][0]==0&&a[1][1]==1)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
				}
				else if(a[0][2]==0&&a[2][2]==1)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
				}
				else if(a[0][2]==1&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
				}
				else
				{       if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}

					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
				}


			}
			else if(pos==7)
			{
				a[2][0]=1;
				gotoxy(7,11);
				cout<<"X";
				if((a[0][0]==1&&a[1][0]==1)||(a[1][1]==1&&a[0][2]==1)||(a[2][1]==1&&a[2][2]==1))
				{	gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}


				if(a[0][0]==1&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
				}
				else if(a[0][0]==0&&a[1][0]==1)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
				}
				else if(a[1][1]==1&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
				}
				else if(a[1][1]==0&&a[0][2]==1)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else if(a[2][1]==1&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
				}
				else if(a[2][1]==0&&a[2][2]==1)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
				}
				else
				{       if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}

					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
				}
			}
			else if(pos==8)
			{
				a[2][1]=1;
				gotoxy(16,11);
				cout<<"X";
				if((a[2][0]==1&&a[2][2]==1)||(a[0][1]==1&&a[1][1]==1))
				{	gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}

				if(a[2][0]==1&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
				}
				else if(a[2][0]==0&&a[2][2]==1)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
				}
				else if(a[0][1]==1&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else if(a[0][1]==0&&a[1][1]==1)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
				}
				else
				{       if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}

					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}
					else if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(16,11);
						cout<<"O";
					}
					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
				}
			}
			else if(pos==9)
			{	a[2][2]=1;
				gotoxy(23,11);
				cout<<"X";
				if((a[0][0]==1&&a[1][1]==1)||(a[2][0]==1&&a[2][1]==1)||(a[0][2]==1&&a[1][2]==1))
				{	gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"YOU WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][0]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[2][0]==2&&a[0][0]==2)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][1]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[2][1]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][2]==2&&a[2][2]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][2]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][1]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][1]==2&&a[0][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[0][2]==2&&a[0][1]==0)
				{
					a[0][1]=2;
					gotoxy(16,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[1][2]==2&&a[1][0]==0)
				{
					a[1][0]=2;
					gotoxy(7,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][0]==2&&a[1][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][1]==2&&a[2][2]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[2][0]==2&&a[2][2]==2&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==0)
				{
					a[2][2]=2;
					gotoxy(23,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][2]==2&&a[0][0]==0)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][0]==2&&a[2][2]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}

				else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==0)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[1][1]==2&&a[2][0]==2&&a[0][2]==0)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else if(a[0][2]==2&&a[2][0]==2&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
					gotoxy(win2.get_left()+5,win2.get_bottom());
					cout<<"COMPUTER WON THE MATCH";
					getch();
					clrscr();
					goto a;
				}
				else
				{
				}


				if(a[0][0]==1&&a[1][1]==0)
				{
					a[1][1]=2;
					gotoxy(16,7);
					cout<<"O";
				}
				else if(a[0][0]==0&&a[1][1]==1)
				{
					a[0][0]=2;
					gotoxy(7,4);
					cout<<"O";
				}
				else if(a[2][0]==0&&a[2][1]==1)
				{
					a[2][0]=2;
					gotoxy(7,11);
					cout<<"O";
				}
				else if(a[2][0]==1&&a[2][1]==0)
				{
					a[2][1]=2;
					gotoxy(16,11);
					cout<<"O";
				}
				else if(a[0][2]==1&&a[1][2]==0)
				{
					a[1][2]=2;
					gotoxy(23,7);
					cout<<"O";
				}
				else if(a[0][2]==0&&a[1][2]==1)
				{
					a[0][2]=2;
					gotoxy(23,4);
					cout<<"O";
				}
				else
				{       if(a[2][0]==0)
					{
						a[2][0]=2;
						gotoxy(7,11);
						cout<<"O";
					}
					else if(a[1][1]==0)
					{       a[1][1]=2;
						gotoxy(16,7);
						cout<<"O";
					}
					else if(a[0][1]==0)
					{
						a[0][1]=2;
						gotoxy(16,4);
						cout<<"O";
					}
					else if(a[0][2]==0)
					{
						a[0][2]=2;
						gotoxy(23,4);
						cout<<"O";
					}
					else if(a[1][0]==0)
					{
						a[1][0]=2;
						gotoxy(7,7);
						cout<<"O";
					}
					else if(a[0][0]==0)
					{
						a[0][0]=2;
						gotoxy(7,4);
						cout<<"O";
					}
					else if(a[1][2]==0)
					{
						a[1][2]=2;
						gotoxy(23,7);
						cout<<"O";
					}

					else if(a[2][1]==0)
					{
						a[2][1]=2;
						gotoxy(17,11);
						cout<<"O";
					}
					else
					{
						a[2][2]=2;
						gotoxy(23,11);
						cout<<"O";
					}
				}
			}
			textcolor(COLOR);

		}
		gotoxy(win2.get_left()+5,win2.get_bottom());
		cout<<"MATCH DRAW";
		getch();
		clrscr();
		goto a;
		textcolor(COLOR);
	}
	else if(choise==2)
	{
		clrscr();
		dos_box win2(1,1,80,25,WHITE);
		win2.make_win();
		win2.make_board();

		for( i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				a[i][j]=0;
			}
		}
		for(int i=2,j=1;i<10,j<8;i=i+4,j=j+3)
		{
			gotoxy(3,i);
			cout<<j;
		}
		for(i=2,j=2;i<10,j<9;i=i+4,j=j+3)
		{
			gotoxy(11,i);
			cout<<j;
		}
		for(i=2,j=3;i<10,j<10;i=i+4,j=j+3)
		{
			gotoxy(20,i);
			cout<<j;
		}

		for(i=2;i<=12;i++)
		{
			gotoxy(10,i);
			putch(char(186));
			gotoxy(19,i);
			putch(char(186));

		}
		for(i=3;i<=26;i++)
		{
			gotoxy(i,5);
			putch(char(205));
			gotoxy(i,9);
			putch(char(205));
		}
		textcolor(WHITE);

		gotoxy(29,3);
		cout<<"PLAYER 1:";
		gotoxy(55,3);
		cout<<"PLAYER 2:";
		gotoxy(29,4);
		cout<<"ENTER YOUR POSSITION:";
		cin>>pos1[0];
		if(pos1[0]==1)
		{
			a[0][0]=1;
			gotoxy(7,4);
			cout<<"X";
		}
		else if(pos1[0]==2)
		{       a[0][1]=1;
			gotoxy(16,4);
			cout<<"X";
		}
		else if(pos1[0]==3)
		{	a[0][2]=1;
			gotoxy(23,4);
			cout<<"X";
		}
		else if(pos1[0]==4)
		{	a[1][0]=1;
			gotoxy(7,7);
			cout<<"X";
		}
		else if(pos1[0]==5)
		{
			a[1][1]=1;
			gotoxy(16,7);
			cout<<"X";
		}
		else if(pos1[0]==6)
		{
			a[1][2]=1;
			gotoxy(23,7);
			cout<<"X";
		}
		else if(pos1[0]==7)
		{
			a[2][0]=1;
			gotoxy(7,11);
			cout<<"X";
		}
		else if(pos1[0]==8)
		{	a[2][1]=1;
			gotoxy(16,11);
			cout<<"X";
		}
		else if(pos1[0]==9)
		{
			a[2][2]=1;
			gotoxy(23,11);
			cout<<"X";
		}
		else
		{
		}
		for(i=0;i<4;i++)
		{
			gotoxy(55,i+4);
			cout<<"ENTER YOUR POSSITION:";
			cin>>pos2[i];
			if(pos2[i]==1)
			{       a[0][0]=2;
				gotoxy(7,4);
				cout<<"O";
			}
			else if(pos2[i]==2)
			{       a[0][1]=2;
				gotoxy(16,4);
				cout<<"O";
			}
			else if(pos2[i]==3)
			{	a[0][2]=2;
				gotoxy(23,4);
				cout<<"O";
			}
			else if(pos2[i]==4)
			{	a[1][0]=2;
				gotoxy(7,7);
				cout<<"O";
			}
			else if(pos2[i]==5)
			{
				a[1][1]=2;
				gotoxy(16,7);
				cout<<"O";
			}
			else if(pos2[i]==6)
			{
				a[1][2]=2;
				gotoxy(23,7);
				cout<<"O";
			}
			else if(pos2[i]==7)
			{
				a[2][0]=2;
				gotoxy(7,11);
				cout<<"O";
			}
			else if(pos2[i]==8)
			{	a[2][1]=2;
				gotoxy(16,11);
				cout<<"O";
			}
			else if(pos2[i]==9)
			{
				a[2][2]=2;
				gotoxy(23,11);
				cout<<"O";
			}
			else
			{
			}

			if(a[0][0]==2&&a[0][1]==2&&a[0][2]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[1][0]==2&&a[1][1]==2&&a[1][2]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[2][0]==2&&a[2][1]==2&&a[2][2]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][0]==2&&a[1][0]==2&&a[2][0]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][1]==2&&a[1][1]==2&&a[2][1]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][2]==2&&a[1][2]==2&&a[2][2]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][0]==2&&a[1][1]==2&&a[2][2]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][2]==2&&a[1][1]==2&&a[2][0]==2)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 2 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else
			{
			}
			gotoxy(29,i+5);
			cout<<"ENTER YOUR POSSOTION:";
			cin>>pos1[i+1];
			if(pos1[i+1]==1)
			{       a[0][0]=1;
				gotoxy(7,4);
				cout<<"X";
			}
			else if(pos1[i+1]==2)
			{       a[0][1]=1;
				gotoxy(16,4);
				cout<<"X";
			}
			else if(pos1[i+1]==3)
			{	a[0][2]=1;
				gotoxy(23,4);
				cout<<"X";
			}
			else if(pos1[i+1]==4)
			{	a[1][0]=1;
				gotoxy(7,7);
				cout<<"X";
			}
			else if(pos1[i+1]==5)
			{
				a[1][1]=1;
				gotoxy(16,7);
				cout<<"X";
			}
			else if(pos1[i+1]==6)
			{
				a[1][2]=1;
				gotoxy(23,7);
				cout<<"X";
			}
			else if(pos1[i+1]==7)
			{
				a[2][0]=1;
				gotoxy(7,11);
				cout<<"X";
			}
			else if(pos1[i+1]==8)
			{	a[2][1]=1;
				gotoxy(16,11);
				cout<<"X";
			}
			else if(pos1[i+1]==9)
			{
				a[2][2]=1;
				gotoxy(23,11);
				cout<<"X";
			}
			else
			{
			}
			if(a[0][0]==1&&a[0][1]==1&&a[0][2]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[1][0]==1&&a[1][1]==1&&a[1][2]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[2][0]==1&&a[2][1]==1&&a[2][2]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][0]==1&&a[1][0]==1&&a[2][0]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][1]==1&&a[1][1]==1&&a[2][1]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][2]==1&&a[1][2]==1&&a[2][2]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][0]==1&&a[1][1]==1&&a[2][2]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else if(a[0][2]==1&&a[1][1]==1&&a[2][0]==1)
			{       gotoxy(win2.get_left()+5,win2.get_bottom());
				cout<<"PLAYER 1 WON THE MATCH";
				getch();
				clrscr();
				goto a;
			}
			else
			{
			}
		}
		gotoxy(win2.get_left()+5,win2.get_bottom());
		cout<<"MATCH DRAW";
		getch();
		clrscr();
		goto a;



	}
	else if(choise==3)
	{
		exit(1);
	}
	else
	{
		clrscr();
		cout<<"PLEASE ENTER CORECT CHOISE \n";
		getch();
		goto a;
	}


	}

};
