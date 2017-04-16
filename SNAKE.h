#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<TIME.H>
#include<fstream.h>
#include<process.h>


//union REGS in,out;
int left=50;
int top=70;
int right=80;
int bottom=80;
char new_ch='\0';
char pre_ch='d';
char cur_dir='d';
int fillcolor=0;
int linecolor=MAGENTA;
int part_snack=3;
int point_flag=0;
int rand_x=0;
int rand_y=0;
int flag=4;
int k=3;
int delay_time=400;
int no_stage=10;
char char_stack[30];
int  int_stack[100];

int char_stack_count=0;
int int_stack_count=0;
      /*	int call_mouse()
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

	 //	if(click==0)
	//	{
	//		cout<<"Button not preesed\n";
	//	}
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
	}   */
  /*	int in_click(int l,int t,int r,int b)
	{
		int click;
		in.x.ax=3;
		int86(51,&in,&out);
		click=out.x.bx;
		x_pos=out.x.cx;
		y_pos=out.x.dx;

		{
			return 1;
		}
		else
		{
			return 0;
		}
	}      */

class user
{
	protected:

	int save_left;
	int save_top;
	int save_right;
	int save_bottom;
	int save_part_snack;
	char save_new_ch;
	char save_pre_ch;
	char save_cur_dir;
	int save_fillcolor;
	int save_linecolor;
	int save_copy_k;
	int save_flag;
	int save_delay_time;
	public:
    /*	user(int l,int t,int r,int b)
	{       cout<<"Enter Your Name:";
		cin>>ch;
		save_left=l;
		save_top=t;
		save_right=r;
		save_bottom=b;
		save_x_pos=x_pos;
		save_y_pos=y_pos;
	}        */
	void get_data(int l,int t,int r,int b)
	{

		save_left=l;
		save_top=t;
		save_right=r;
		save_bottom=b;
		save_part_snack=part_snack;
		save_new_ch=new_ch;
		save_pre_ch=pre_ch;
		save_cur_dir=cur_dir;
		save_fillcolor=fillcolor;
		save_linecolor=linecolor;
		save_copy_k=k;

		save_flag=flag;
		save_delay_time=delay_time;

	}
	void set_data()
	{
		left=save_left;
		top=save_top;
		right=save_right;
		bottom=save_bottom;
		point_flag=0;
		part_snack=save_part_snack;
		new_ch=save_new_ch;
		pre_ch=save_pre_ch;
		cur_dir=save_cur_dir;
		fillcolor=save_fillcolor;
		linecolor=save_linecolor;
		k=save_copy_k;

		flag=save_flag;
		delay_time=save_delay_time;

	}
};

class box
{

	int copy_left,copy_top,copy_right,copy_bottom;



	public:
	void set_box()
	{
		left=50;
		top=70;
		right=80;
		bottom=80;
		new_ch='\0';
		pre_ch='d';
		cur_dir='d';
		fillcolor=0;
		linecolor=MAGENTA;
		part_snack=3;
		point_flag=0;
		rand_x=0;
		rand_y=0;
		flag=4;
		k=3;
		delay_time-=37;
		no_stage=10;


		char_stack_count=0;
		int_stack_count=0;
	}


	void make_rectangle()
	{
		cleardevice();
	    //	setbkcolor(LIGHTGRAY);
		make_rectangle(10,30,629,460,WHITE,BLACK);
		make_rectangle(10,10,getmaxx()-10,30,WHITE,LIGHTBLUE);
		make_rectangle(getmaxx()-27,10,getmaxx()-10,30,WHITE,BLACK);
		moveto(getmaxx()-27,10);
		lineto(getmaxx()-10,30);
		moveto(getmaxx()-10,10);
		lineto(getmaxx()-27,30);

		setcolor(linecolor);

		rectangle(left,top,right,bottom);
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;
		if(cur_dir=='d')
		{
			for(int j=0;j<part_snack;j++)
			{
				moveto(copy_left+10,copy_top);
				lineto(copy_left+10,copy_top+10);
				copy_left+=10;
			}
		}
		else if(cur_dir=='a')
		{
			for(int j=0;j<part_snack;j++)
			{
				moveto(copy_left+10,copy_top);
				lineto(copy_left+10,copy_top+10);
				copy_left+=10;
			}
		}
		else if(cur_dir=='w')
		{
			for(int j=0;j<part_snack;j++)
			{
				moveto(copy_left,copy_top+10);
				lineto(copy_left+10,copy_top+10);
				copy_top+=10;
			}
		}
		else if(cur_dir=='s')
		{
			for(int j=0;j<part_snack;j++)
			{
				moveto(copy_left,copy_top+10);
				lineto(copy_left+10,copy_top+10);
				copy_top+=10;
			}
		}


	}
	void make_rectangle(int l1,int t1,int r1,int b1,int l_color,int f_color)
	{

		setcolor(l_color);
		rectangle(l1,t1,r1,b1);
		setfillstyle(SOLID_FILL,f_color);
		floodfill(l1+4,t1+4,l_color);
	}


	void check_path(int l,int t,int r,int b)
	{
		if(r>=getmaxx()-10 || t <= 36 || l <=16 || b>=getmaxy()-26)
		{
			hide_mouse();
			make_rectangle(180,125,430,275,BROWN,LIGHTGRAY);
			make_rectangle(180,125,430,140,BROWN,LIGHTBLUE);
			make_rectangle(415,125,430,140,WHITE,BLACK);
			setlinestyle(SOLID_LINE,0,1);
			moveto(415,125);
			lineto(430,140);
			moveto(415,140);
			lineto(430,125);

			setcolor(WHITE);
			settextjustify(CENTER_TEXT,CENTER_TEXT);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy(300,165,"Sorry !! You Lose The Game");
			make_rectangle(280,222,330,240,WHITE,DARKGRAY);
			outtextxy(305,232,"OK");
			call_mouse();
			while(1)
			{
				if(get_pos(415,125,430,140)==1 || get_pos(280,222,330,240)==1)
				{
					hide_mouse();
					make_rectangle(180,125,430,275,BLACK,BLACK);
					setcolor(BLACK);
					moveto(415,125);
					lineto(430,140);
					moveto(415,140);
					lineto(430,125);
					setcolor(BLACK);
					circle(rand_x,rand_y,2.5);
					left=50;
					top=70;
					right=80;
					bottom=80;
					new_ch='\0';
					pre_ch='w';
					cur_dir='w';
					part_snack=3;
					point_flag=0;
					flag=4;
					k=3;
					break;

				}
				if(get_pos(180,125,430,275)==0)
				{
					make_rectangle(180,125,415,140,WHITE,BLACK);
					delay(100);
					make_rectangle(180,125,415,140,WHITE,LIGHTBLUE);
					delay(100);
					make_rectangle(180,125,415,140,WHITE,BLACK);
					delay(100);
					make_rectangle(180,125,415,140,WHITE,LIGHTBLUE);
				}
			}
			cleardevice();
	    //		setbkcolor(LIGHTGRAY);
			make_rectangle(10,30,629,460,WHITE,BLACK);
			make_rectangle(10,10,getmaxx()-10,30,WHITE,LIGHTBLUE);
			make_rectangle(getmaxx()-27,10,getmaxx()-10,30,WHITE,BLACK);
			moveto(getmaxx()-27,10);
			lineto(getmaxx()-10,30);
			moveto(getmaxx()-10,10);
			lineto(getmaxx()-27,30);
			mov_box();
		}

	}

	void w_d()
	{
		int copy_k=k;
		cur_dir='w';
		flag=1;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=right-10;
		int copy_top1=top-10;
		int copy_right1=right;
		int copy_bottom1=bottom-10;
		while((copy_k)>1)
		{
			left+=10;
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left+10,copy_top);
				lineto(copy_left+10,copy_top+10);
				copy_left+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=right-10;
			copy_top1=top+-10;
			copy_right1=right;
			copy_bottom1=bottom-10;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_top1-=10;
				copy_bottom1-=10;
				copy_part_snack1++;
			}
			copy_top1=copy_top1+10;
			check_path(copy_left1,copy_top1,copy_right1,copy_bottom1+10);
		  /*	if(kbhit()!=0)
			{       char_stack c1;
				int_stack i1;

				c1.push(new_ch);
				c1.push(pre_ch);
				c1.push(cur_dir);
				i1.
				pre_ch=cur_dir;
				new_ch=getch();
				cur_ch=new_ch;
				if(new_ch=='d')
				{
				}
			}        */
			if(copy_left1==rand_x-5 && copy_top1==rand_y-5)
			{
				if(cur_dir=='w')
				{
					if(pre_ch=='a')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(right,top,right+10,bottom);
						copy_k++;
						copy_part_snack++;
						right=right+10;
						part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='d')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left-10,top,left,bottom);
						left=left-10;
						copy_k++;
						copy_part_snack++;
						part_snack++;
						point_flag=0;
					}
				}
				setcolor(BLACK);
				circle(rand_x,rand_y,2.5);
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(left,top,left+10,bottom);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}
		left=left;
		right=right;
		top=copy_top1;
		bottom=bottom;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;



	}
	void w_a()
	{
		int copy_k=k;
		cur_dir='w';
		flag=1;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=left;
		int copy_top1=top-10;
		int copy_right1=left+10;
		int copy_bottom1=bottom-10;
		while((copy_k)>1)
		{
			right-=10;
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left+10,copy_top);
				lineto(copy_left+10,copy_top+10);
				copy_left+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=left;
			copy_top1=top-10;
			copy_right1=left+10;
			copy_bottom1=bottom-10;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_top1-=10;
				copy_bottom1-=10;
				copy_part_snack1++;
			}
			copy_top1=copy_top1+10;
			check_path(copy_left1,copy_top1,copy_right1,copy_bottom1+10);
			if(copy_left1==rand_x-5 && copy_top1==rand_y-5)
			{
				if(cur_dir=='w')
				{
					if(pre_ch=='a')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(right,top,right+10,bottom);
						copy_k++;
						copy_part_snack++;
						right=right+10;
						part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='d')
					{
						k++;
						setcolor(MAGENTA);
						setfillstyle(SOLID_FILL,0);
						rectangle(left-10,top,left,bottom);
						left=left-10;
						copy_k++;
						copy_part_snack++;
						part_snack++;
						point_flag=0;
					}
				}
				setcolor(BLACK);
				circle(rand_x,rand_y,2.5);
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(right-10,top,right,bottom);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}
		left=left;
		right=right;
		top=copy_top1;
		bottom=bottom;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;

	}
	void s_a()
	{
		int copy_k=k;
		cur_dir='s';
		flag=2;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=left;
		int copy_top1=top+10;
		int copy_right1=left+10;
		int copy_bottom1=bottom+10;
		while((copy_k)>1)
		{
			right-=10;
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left+10,copy_top);
				lineto(copy_left+10,copy_top+10);
				copy_left+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=left;
			copy_top1=top+10;
			copy_right1=left+10;
			copy_bottom1=bottom+10;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_top1+=10;
				copy_bottom1+=10;
				copy_part_snack1++;
			}
			copy_bottom1=copy_bottom1-10;
			check_path(copy_left1,copy_top1-10,copy_right1,copy_bottom1);
			if(copy_right1==rand_x+5 && copy_bottom1==rand_y+5)
			 {
				if(cur_dir=='s')
				{
					if(pre_ch=='a')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(right,top,right+10,bottom);
						right=right+10;
						copy_k++;
						copy_part_snack++;
						part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='d')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left-10,top,left,bottom);
						left=left-10;
						copy_k++;
						copy_part_snack++;
						part_snack++;
						point_flag=0;
					}
				}
				setcolor(BLACK);
				circle(rand_x,rand_y,2.5);
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(right-10,top,right,bottom);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}

		left=left;
		right=right;
		top=top;
		bottom=copy_bottom1;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;

	}
	void s_d()
	{
		int copy_k=k;
		cur_dir='s';
		flag=2;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=right-10;
		int copy_top1=top+10;
		int copy_right1=right;
		int copy_bottom1=bottom+10;
		while((copy_k)>1)
		{
			left+=10;
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left+10,copy_top);
				lineto(copy_left+10,copy_top+10);
				copy_left+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=right-10;
			copy_top1=top+10;
			copy_right1=right;
			copy_bottom1=bottom+10;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_top1+=10;
				copy_bottom1+=10;
				copy_part_snack1++;
			}
			copy_bottom1=copy_bottom1-10;
			check_path(copy_left1,copy_top1-10,copy_right1,copy_bottom1);
			if(copy_right1==rand_x+5 && copy_bottom1==rand_y+5)
			{
				if(cur_dir=='s')
				{
					if(pre_ch=='a')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(right,top,right+10,bottom);
						right=right+10;
						copy_k++;
						copy_part_snack++;
						part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='d')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left-10,top,left,bottom);
						left=left-10;
						copy_k++;
						copy_part_snack++;
						part_snack++;
						point_flag=0;
					}
				}
				setcolor(BLACK);
				circle(rand_x,rand_y,2.5);
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(left,top,left+10,bottom);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}
		left=left;
		right=right;
		top=top;
		bottom=copy_bottom1;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;



	}
	void a_w()
	{
		int copy_k=k;
		cur_dir='a';
		flag=3;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=left-10;
		int copy_top1=top;
		int copy_right1=right-10;
		int copy_bottom1=top+10;
		while((copy_k)>1)
		{
			bottom-=10;
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left,copy_top+10);
				lineto(copy_left+10,copy_top+10);
				copy_top+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=left-10;
			copy_top1=top;
			copy_right1=right-10;
			copy_bottom1=top+10;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_left1-=10;
				copy_right1-=10;
				copy_part_snack1++;
			}
			copy_left1=copy_left1+10;
			check_path(copy_left1,copy_top1,copy_right1+10,copy_bottom1);
			if(copy_left1==rand_x-5 && copy_top1==rand_y-5)
			{
				 if(cur_dir=='a')
				 {
					if(pre_ch=='s')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,top-10,right,top);
						top=top-10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='w')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,bottom,right,bottom+10);
						bottom=bottom+10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
				}
				setcolor(BLACK);
				circle(rand_x,rand_y,2.5);
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(left,bottom-10,right,bottom);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}
		left=copy_left1;
		right=right;
		top=top;
		bottom=bottom;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;
	}

	void a_s()
	{
		int copy_k=k;
		cur_dir='a';
		flag=3;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=left-10;
		int copy_top1=bottom-10;
		int copy_right1=right-10;
		int copy_bottom1=bottom;
		while((copy_k)>1)
		{
			top+=10;
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left,copy_top+10);
				lineto(copy_left+10,copy_top+10);
				copy_top+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=left-10;
			copy_top1=bottom-10;
			copy_right1=right-10;
			copy_bottom1=bottom;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_left1-=10;
				copy_right1-=10;
				copy_part_snack1++;
			}
			copy_left1=copy_left1+10;
			check_path(copy_left1,copy_top1,copy_right1+10,copy_bottom1);
			if(copy_left1==rand_x-5 && copy_top1==rand_y-5)
			 {
				 if(cur_dir=='a')
				 {
					if(pre_ch=='s')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,top-10,right,top);
						top=top-10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='w')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,bottom,right,bottom+10);
						bottom=bottom+10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
				}
				setcolor(BLACK);
				circle(rand_x,rand_y,2.5);
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(left,top,right,top+10);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}
		left=copy_left1;
		right=right;
		top=bottom-10;
		bottom=bottom;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;
	}

	void d_w()
	{
		int copy_k=k;
		cur_dir='d';
		flag=4;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=left+10;
		int copy_top1=top;
		int copy_right1=right+10;
		int copy_bottom1=top+10;
		while((copy_k)>1)
		{
			bottom-=10;   //step by step delete the last box
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left,copy_top+10);
				lineto(copy_left+10,copy_top+10);
				copy_top+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=left+10;
			copy_top1=top;
			copy_right1=right+10;
			copy_bottom1=top+10;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_left1+=10;
				copy_right1+=10;
				copy_part_snack1++;
			}
			copy_right1=copy_right1-10;
			check_path(copy_left1-10,copy_top1,copy_right1,copy_bottom1);
			if(copy_right1==rand_x+5 && copy_top1==rand_y-5)
			 {
				if(cur_dir=='d')
				 {
					if(pre_ch=='s')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,top-10,right,top);
						top=top-10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='w')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,bottom,right,bottom+10);
						bottom=bottom+10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
				 }
				 setcolor(BLACK);
				 circle(rand_x,rand_y,2.5);
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(left,bottom-10,right,bottom);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}

		left=left;
		right=copy_right1;
		top=top;
		bottom=bottom;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;
	}


	void d_s()
	{
		int copy_k=k;
		cur_dir='d';
		flag=4;
		int copy_part_snack=part_snack;
		int copy_part_snack1;

		int copy_left1=left+10;
		int copy_top1=bottom-10;
		int copy_right1=right+10;
		int copy_bottom1=bottom;
		while((copy_k)>1)
		{
			top+=10;    //step by step delete the uper top box
			copy_part_snack--;
			setcolor(MAGENTA);
			rectangle(left,top,right,bottom);
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			for(int j=1;j<copy_part_snack;j++)
			{
				moveto(copy_left,copy_top+10);
				lineto(copy_left+10,copy_top+10);
				copy_top+=10;
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_part_snack1=copy_part_snack;
			setcolor(MAGENTA);
			copy_left1=left+10;
			copy_top1=bottom-10;
			copy_right1=right+10;
			copy_bottom1=bottom;
			while(copy_part_snack1<part_snack)
			{
				rectangle(copy_left1,copy_top1,copy_right1,copy_bottom1);
				copy_left1+=10;
				copy_right1+=10;
				copy_part_snack1++;
			}
			copy_right1=copy_right1-10;
			check_path(copy_left1-10,copy_top1,copy_right1,copy_bottom1);
			if(copy_right1==rand_x+5 && copy_top1==rand_y-5)
			 {
				if(cur_dir=='d')
				 {
					if(pre_ch=='s')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,top-10,right,top);
						top=top-10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
					else if(pre_ch=='w')
					{
						k++;
						setcolor(MAGENTA);
						rectangle(left,bottom,right,bottom+10);
						bottom=bottom+10;
						part_snack++;
						copy_k++;
						copy_part_snack++;
						point_flag=0;
					}
					setcolor(BLACK);
					circle(rand_x,rand_y,2.5);
				 }
			}
			if(copy_k>2)
			{
				delay(delay_time);
				setcolor(BLACK);
				rectangle(left,top,right,top+10);
			}
			copy_left=left;
			copy_right=right;
			copy_top=top;
			copy_bottom=bottom;
			copy_k--;
		}
		left=left;
		right=copy_right1;
		top=bottom-10;
		bottom=bottom;
		copy_left=left;
		copy_right=right;
		copy_top=top;
		copy_bottom=bottom;
	}



	class char_stack
	{
		char ch[100];
		int count;
		public:
		char_satck()
		{
			count=0;
		}
		void push(char c)
		{
			ch[count++]=c;
		}
		char pop()
		{
			return ch[count--];
		}
	};
	class int_stack
	{
		int val[100];
		int count;
		public:
		int_stack()
		{
			count=0;
		}
		void push(int v)
		{
			val[count++]=v;
		}
		int pop()
		{
			return val[count--];
		}
	};

	void mov_box()
	{


		call_mouse();

		while(1)
		{
			if(point_flag==0)
			{       next:

				randomize();
				rand_x=random(getmaxx()-16);
				rand_y=random(getmaxy()-31);

				if( (rand_x>=left && rand_x<=right && rand_y>=top && rand_y<=bottom) || rand_x<36 || rand_y<36 )
				{
					goto next;
				}
				else
				{


					if(rand_x % 5 !=0)
					{
						for(int l=0;l<630;l+=5)
						{
							if(rand_x<l)
							{
								rand_x=l;

								break;
							}
						}
					}

					if(rand_y % 5 !=0)
					{
						for(int m=0;m<470;m+=5)
						{
							if(rand_y<m)
							{
								rand_y=m;

								break;
							}
						}
					}
					if(rand_x % 10 ==0)
					{
						rand_x-=5;
					}
					if(rand_y % 10 ==0)
					{
						rand_y-=5;
					}

					point_flag=1;
					setcolor(MAGENTA);
					circle(rand_x,rand_y,2.5);
				}
			}



			copy_left=left;
			copy_right=right;
			copy_bottom=bottom;
			copy_top=top;
			if(flag==1)
			{
				cur_dir='w';
				setcolor(MAGENTA);

				rectangle(left,top,right,bottom);

				for(int j=0;j<part_snack;j++)
				{
					moveto(copy_left,copy_top+10);
					lineto(copy_left+10,copy_top+10);
					copy_top+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;

				delay(delay_time);
				setcolor(BLACK);

				rectangle(left,top,right,bottom);

				for(j=0;j<part_snack;j++)
				{
					moveto(copy_left,copy_top+10);
					lineto(copy_left+10,copy_top+10);
					copy_top+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;





				top-=10;
				bottom-=10;

			}
			if(flag==2)
			{
				cur_dir='s';
				setcolor(MAGENTA);

				rectangle(left,top,right,bottom);


				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;
				for(int j=0;j<part_snack;j++)
				{

					moveto(copy_left,copy_top+10);
					lineto(copy_left+10,copy_top+10);
					copy_top+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;

				delay(delay_time);
				setcolor(BLACK);

				rectangle(left,top,right,bottom);

				for(j=0;j<part_snack;j++)
				{
					moveto(copy_left,copy_top+10);
					lineto(copy_left+10,copy_top+10);
					copy_top+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;



				top+=10;
				bottom+=10;



			}

			if(flag==3)
			{       cur_dir='a';
				setcolor(MAGENTA);

				rectangle(left,top,right,bottom);

				for(int j=0;j<part_snack;j++)
				{
					moveto(copy_left+10,copy_top);
					lineto(copy_left+10,copy_top+10);
					copy_left+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;

				delay(delay_time);
				setcolor(BLACK);

				rectangle(left,top,right,bottom);

				for(j=0;j<part_snack;j++)
				{
					moveto(copy_left+10,copy_top);
					lineto(copy_left+10,copy_top+10);
					copy_left+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;




				left-=10;
				right-=10;

			}

			if(flag==4)
			{
				cur_dir='d';
				setcolor(MAGENTA);

				rectangle(left,top,right,bottom);

				for(int j=0;j<part_snack;j++)
				{
					moveto(copy_left+10,copy_top);
					lineto(copy_left+10,copy_top+10);
					copy_left+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;

				delay(delay_time);
				setcolor(BLACK);

				rectangle(left,top,right,bottom);

				for(j=0;j<part_snack;j++)
				{
					moveto(copy_left+10,copy_top);
					lineto(copy_left+10,copy_top+10);
					copy_left+=10;

				}

				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;




				left+=10;
				right+=10;

			}

			if(get_pos(getmaxx()-27,10,getmaxx()-10,30)==1)
			{
				exit(0);
			}


			if(kbhit()!=0)
			{
				int copy_k;
				pre_ch=cur_dir;
				new_ch=getch();
				int new_int;
				new_int=(int)new_ch;
				if(new_int==27)
				{
					hide_mouse();

					setlinestyle(SOLID_LINE,0,2);

					make_rectangle(180,125,430,275,WHITE,LIGHTGRAY);
					make_rectangle(180,125,430,140,WHITE,LIGHTBLUE);
					make_rectangle(415,125,430,140,WHITE,BLACK);
					setlinestyle(SOLID_LINE,0,1);
					moveto(415,125);
					lineto(430,140);
					moveto(415,140);
					lineto(430,125);
					setcolor(WHITE);
					settextjustify(CENTER_TEXT,CENTER_TEXT);
					settextstyle(SMALL_FONT,HORIZ_DIR,4);

					outtextxy(300,170,"Would you Like to Save The Game?");

					make_rectangle(230,222,270,240,WHITE,DARKGRAY);
					outtextxy(248,229,"Yes");
					make_rectangle(325,222,365,240,WHITE,DARKGRAY);
					outtextxy(343,229,"No");
					call_mouse();
					while(1)
					{
						if(get_pos(180,125,430,275)==0)
						{
							make_rectangle(180,125,415,140,WHITE,BLACK);

							delay(100);
							make_rectangle(180,125,415,140,WHITE,LIGHTBLUE);
							delay(100);
							make_rectangle(180,125,415,140,WHITE,BLACK);
							delay(100);
							make_rectangle(180,125,415,140,WHITE,LIGHTBLUE);

						}
						if(get_pos(415,125,430,140)==1)
						{       hide_mouse();
						   //	cout<<"X clicked";
							make_rectangle(180,125,430,275,BLACK,BLACK);
							setcolor(BLACK);
							moveto(415,125);
							lineto(430,140);
							moveto(415,140);
							lineto(430,125);
							call_mouse();
							break;
						}
						if(get_pos(230,222,270,240)==1)
						{
					   //		cout<<"Yes pressed";
							user u1;
							u1.get_data(left,top,right,bottom);
							ofstream file("Data.dat");


							file.write((char*)&u1,sizeof(u1));
							file.close();

						       exit(0);

						}
						if(get_pos(325,222,365,240)==1)
						{
					     //		cout<<"No Pressed";


							exit(0);
						}


					}


				}
				if(new_ch=='k')
			     //	if(left==rand_x-5 && right==rand_y-5)
				{
					if(cur_dir=='d')
					{
						k++;
						setcolor(MAGENTA);

						rectangle(left-10,top,left,bottom);


						left=left-10;
						part_snack++;

					}
					else if(cur_dir=='a')
					{
						k++;
						setcolor(MAGENTA);

						rectangle(right,top,right+10,bottom);


						right=right+10;
						part_snack++;
					}
					else if(cur_dir=='w')
					{
						k++;
						setcolor(MAGENTA);

						rectangle(left,bottom,right,bottom+10);


						bottom=bottom+10;
						part_snack++;
					}
					else if(cur_dir=='s')
					{
						k++;
						setcolor(MAGENTA);

						rectangle(left,top-10,right,top);


						top=top-10;
						part_snack++;
					}

				}
				if(new_ch=='w')
				{
					if(pre_ch=='d')
					{
						w_d();

					}
					else if(pre_ch=='a')
					{
						w_a();
					}

				}
				if(new_ch=='s')
				{
					if(pre_ch=='d')
					{
						s_d();

					}
					else if(pre_ch=='a')
					{
						s_a();

					}

				}
				if(new_ch=='a')
				{

					if(pre_ch=='w')
					{
						a_w();
					}
					else if(pre_ch=='s')
					{
						a_s();
					}

				}
				if(new_ch=='d')
				{

					if(pre_ch=='w')
					{
						d_w();
					}
					else if(pre_ch=='s')
					{
						d_s();
					}

				}



			 }



			 if(left==rand_x-5 && top==rand_y-5)
			 {

				 if(cur_dir=='a')
				 {
					k++;
					setcolor(MAGENTA);

					rectangle(right,top,right+10,bottom);


					right=right+10;
					part_snack++;
					point_flag=0;
				 }
				 else if(cur_dir=='w')
				 {
					k++;
					setcolor(MAGENTA);

					rectangle(left,bottom,right,bottom+10);
					point_flag=0;
					bottom=bottom+10;
					part_snack++;
				 }



				 setcolor(BLACK);
				 circle(rand_x,rand_y,2.5);
			 }
			 else if(right==rand_x+5 && bottom==rand_y+5)
			 {
				if(cur_dir=='d')
				{
					k++;
					setcolor(MAGENTA);

					rectangle(left-10,top,left,bottom);
					left=left-10;
					part_snack++;
					point_flag=0;
				 }
				 else if(cur_dir=='s')
				 {
					k++;
					setcolor(MAGENTA);

					rectangle(left,top-10,right,top);


					top=top-10;
					part_snack++;
					point_flag=0;

				 }
				 setcolor(BLACK);
				 circle(rand_x,rand_y,2.5);
			 }
			 check_path(left,top,right,bottom);

			 if(part_snack==8)
			 {
				make_rectangle(left,top,right,bottom,BLACK,BLACK);
				setcolor(BLACK);
				copy_left=left;
				copy_right=right;
				copy_top=top;
				copy_bottom=bottom;
				if(cur_dir=='d')
				{
					for(int j=0;j<part_snack;j++)
					{
						moveto(copy_left+10,copy_top);
						lineto(copy_left+10,copy_top+10);
						copy_left+=10;
					}
				}
				else if(cur_dir=='a')
				{
					for(int j=0;j<part_snack;j++)
					{
						moveto(copy_left+10,copy_top);
						lineto(copy_left+10,copy_top+10);
						copy_left+=10;
					}
				}
				else if(cur_dir=='w')
				{
					for(int j=0;j<part_snack;j++)
					{
						moveto(copy_left,copy_top+10);
						lineto(copy_left+10,copy_top+10);
						copy_top+=10;
					}
				}
				else if(cur_dir=='s')
				{
					for(int j=0;j<part_snack;j++)
					{
						moveto(copy_left,copy_top+10);
						lineto(copy_left+10,copy_top+10);
						copy_top+=10;
					}
				}
				circle(rand_x,rand_y,2.5);

				settextjustify(CENTER_TEXT,CENTER_TEXT);

				for(int i=3;i<10;i++)
				{
					setcolor(i);

					settextstyle(SMALL_FONT,HORIZ_DIR,i);
					outtextxy(300,180,"STAGE CLEARED");

				   /*	setcolor(LIGHTGRAY);
					settextstyle(SMALL_FONT,HORIZ_DIR,i-1);
					outtextxy(300,180,"STAGE CLEAREAD");     */
				 //	getch();
					delay(100);

					setcolor(BLACK);

					settextstyle(SMALL_FONT,HORIZ_DIR,i);
					outtextxy(300,180,"STAGE CLEARED");

				 /*	setcolor(BLACK);

					settextstyle(SMALL_FONT,HORIZ_DIR,i-1);
					outtextxy(300,180,"STAGE CLEARED");      */
				}

				for(i=10;i>=3;i--)
				{
					setcolor(i);
					settextstyle(SMALL_FONT,HORIZ_DIR,i);
					outtextxy(300,180,"STAGE CLEARED");

				   /*	setcolor(LIGHTGRAY);
					settextstyle(DEFAULT_FONT,HORIZ_DIR,i-1);
					outtextxy(300,180,"STAGE CLEARED");      */

				//	getch();
					delay(100);

					setcolor(BLACK);

					settextstyle(SMALL_FONT,HORIZ_DIR,i);
					outtextxy(300,180,"STAGE CLEARED");

				   /*	setcolor(BLACK);

					settextstyle(SMALL_FONT,HORIZ_DIR,i-1);
					outtextxy(300,180,"STAGE CLEARED");       */
				}


			     //	cout<<"You have cleared this stage";
				hide_mouse();

				delay(1000);
				call_mouse();
				break;

			 }




		}
	}
};



class main_win
{

	int mid_x,mid_y;
	int font,direction,size,color,horzjustify,vertjustify,multx,divx,multy,divy;
	char str[40];
	public:
	main_win()
	{
		font=GOTHIC_FONT;
		direction=HORIZ_DIR;
		size=16;
		color=WHITE;
		horzjustify=CENTER_TEXT;
		vertjustify=BOTTOM_TEXT;
		multx=1;
		divx=1;
		multy=1;
		divy=1;

		strcpy(str,"Welcome To The SNAKE Game");
		mid_x=getmaxx()/2;
		mid_y=getmaxy()/2;



	}

	void draw_text()
	{

		box b1;
	     //	b1.make_rectangle(10,10,getmaxx()-10,getmaxy()-10,WHITE,LIGHTBLUE);
		b1.make_rectangle(10,10,getmaxx()-10,30,WHITE,LIGHTBLUE);
		b1.make_rectangle(getmaxx()-27,10,getmaxx()-10,30,WHITE,BLACK);
		moveto(getmaxx()-27,10);
		lineto(getmaxx()-10,30);
		moveto(getmaxx()-10,10);
		lineto(getmaxx()-27,30);
		moveto(mid_x,mid_y);
		settextstyle(font,direction,size);
		setcolor(BROWN);
		settextjustify(horzjustify,vertjustify);
		setusercharsize(multx,divx,multy,divy);
		outtext(str);
		font=SMALL_FONT;
		size=4;
		settextstyle(font,direction,size);

		outtextxy(540,430,"PRESS KEY TO CONTINUE...");
	   //	settextjustify(CENTER_TEXT,CENTER_TEXT);
		b1.make_rectangle(540,390,580,408,WHITE,DARKGRAY);
		outtextxy(560,402,"Next");
		b1.make_rectangle(540,350,620,368,WHITE,DARKGRAY);
		outtextxy(580,362,"Load Game");

		call_mouse();
		restriction_mouse();
		while(1)
		{
			if(get_pos(getmaxx()-27,10,getmaxx()-10,30)==1)
			{
				exit(1);
			}
			if(get_pos(540,390,580,408)==1)
			{
				break;


			}
			if(get_pos(540,350,620,368)==1)
			{
		  //		make_rectangle(16,36,getmaxx()-10,getmaxy()-26,BLACK,BLACK)
				user u2;
				ifstream file1("Data.dat");
			      //	file1.open("DATA.dat",ios::in);
				file1.read((char*)&u2,sizeof(u2));

				u2.set_data();
			    //	file1.close();
				cleardevice();
			    //	setbkcolor(LIGHTGRAY);
				b1.make_rectangle(10,30,629,460,WHITE,BLACK);
				b1.make_rectangle(10,10,getmaxx()-10,30,WHITE,LIGHTBLUE);
				b1.make_rectangle(getmaxx()-27,10,getmaxx()-10,30,WHITE,BLACK);
				moveto(getmaxx()-27,10);
				lineto(getmaxx()-10,30);
				moveto(getmaxx()-10,10);
				lineto(getmaxx()-27,30);
				break;

			}

		}

	}

};

/*void main()
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

} */