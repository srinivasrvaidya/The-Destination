/*************************************************************************/
//*************************************************************************//
//       -*-     Program of Game "The Destination"     -*-                //
//-------------------------------------------------------------------------//
//       -*-       Language  :-  C-Graphics & C.     -*-                //
//-------------------------------------------------------------------------//
//       -*-       Compilier :-  Turbo C & C++.        -*-                //
//-------------------------------------------------------------------------//
//       -*-         By- Srinivas R. Vaidya            -*-                //
//*************************************************************************//
//*************************************************************************//



#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
#include<process.h>

/****** Global Variables ********/
int s1,s2,s3,s4,s5,s6,s7,s8;


void initialAnimation()
{

	int i;
	int xm,gmode,gd=DETECT;
	initgraph(&gd,&gmode,"c:\\tc\\bgi");
	xm=getmaxx();
	setbkcolor(CYAN);
	setcolor(YELLOW);
	outtextxy(10,10," GAME: ");

/***** Block Animation ********/

	int x1=0,y1=0,area11;char *m11;	
	setfillstyle(LINE_FILL,RED);
	area11=imagesize(x1,y1,80,20);
	m11=(char *)malloc(area11);
	getimage(x1,y1,80,20,m11);
	putimage(x1,y1,m11,XOR_PUT);

	int x12=xm-100,y12=220,a12;char *m2;
	rectangle(x12,y12,xm,240);
	setfillstyle(LINE_FILL,RED);
	a12=imagesize(x12,y12,xm,240);
	m2=(char *)malloc(a12);
	getimage(x12,y12,xm,240,m2);
	putimage(x12,y12,m2,XOR_PUT);


	x1=0;y1=0;
	for(i=0;i<190;i++)
	{
		y1+=1;
		x1+=1;
		putimage(x1,y1,m11,XOR_PUT);
		delay(20);
		putimage(x1,y1,m11,XOR_PUT);

	}
	putimage(x1,y1,m11,XOR_PUT);

	int x11=0,y11=160,a11;char *m1;
	rectangle(x11,y11,100,180);
	setfillstyle(LINE_FILL,RED);
	a11=imagesize(x11,y11,100,180);
	m1=(char *)malloc(a11);
	getimage(x11,y11,100,180,m1);
	putimage(x11,y11,m1,XOR_PUT);


/****** Block Cross-over code **********/
	for(i=0;i<600;i++)
	{
		x11+=1;
		putimage(x11,y11,m1,XOR_PUT);
		delay(2);
		if(x11>=xm)
		{ 
			break;
		}


		x12-=1;
		putimage(x12,y12,m2,XOR_PUT);
		delay(2);
		if(x12<=0)
		{ 
			break;
		}

	}
	putimage(x11,y11,m1,XOR_PUT);
	putimage(x12,y12,m2,XOR_PUT);

	
	outtextxy(270,200,"THE DESTINATION ");
	delay(1000);
	getch();
	
/********   Introduction   **************/	
	
	clearviewport();
	delay(1000);

	setbkcolor(WHITE);
	setcolor(RED);
	outtextxy(250,20," Introduction ");
	outtextxy(10,50," The User block has to be taken to its DESTINATION form START ");
	outtextxy(10,65," facing obstrucles in its path.  ");
	outtextxy(10,130,"  How To Play: ");
	outtextxy(20,145," * Use array keys for movement of user Block ");
	outtextxy(20,160," * The user block should not touch, intersect other blocks in the game. ");
	outtextxy(20,175," * However in the last Track you have a DOOR, and you need to reach");
	outtextxy(20,190,"   the DESTINATION passing through this DOOR");
	delay(2000);
	getch();

	clearviewport();
	setbkcolor(RED);
	setcolor(BLUE);
	sound(3);

	H:

/***********   Player Level Selection **************/ 

	outtextxy(20,50," Player Level's ");
	outtextxy(20,70," 1. Easy ");
	outtextxy(20,90," 2. Hard ");
	char p=getch();

/***** Easy ***********/

	if(p==49)
	{
		s1=2;
		s2=3;
		s3=5;
		s4=10;
		s5=5;
		s6=4;
		s7=6;
		s8=8;
	}
/***** Hard **********/
	else
	if(p==50)
	{
		s1=5;
		s2=7;
		s3=9;
		s4=16;
		s5=9;
		s6=8;
		s7=8;
		s8=12;
	}
	else
	{
		goto H;
	}
	closegraph();
	getch();
}


void main()
{

	int l=3,once=1;
	START:
	if(once==1)
	{
		once++;
		initialAnimation();
	}
	char ee;
	int xm,ym,gmode,gd=DETECT;
	initgraph(&gd,&gmode,"c:\\tc\\bgi");
	setcolor(WHITE);
	setbkcolor(CYAN);

/**** Fetching max x-cordinate and max y-cordinate ******/

	xm=getmaxx();
	ym=getmaxy();

	printf("\n\n      %d",l);
	outtextxy(5,35,"LIFE:");
	if(s1==2)
	{
		outtextxy(7,48," EASY");
	}
	else
	{
		outtextxy(7,48," HARD");
	}
	
/********* Display Banner ***********/	
	
	outtextxy(5,35,"");
	outtextxy(10,200,"S");
	outtextxy(10,212,"T");
	outtextxy(10,224,"A");
	outtextxy(10,236,"R");
	outtextxy(10,248,"T");
	outtextxy(625,170,"D");
	outtextxy(625,180,"E");
	outtextxy(625,192,"S");
	outtextxy(625,205,"T");
	outtextxy(625,220,"I");
	outtextxy(625,235,"N");
	outtextxy(625,245,"A");
	outtextxy(625,260,"T");
	outtextxy(625,275,"I");
	outtextxy(625,290,"O");
	outtextxy(625,305,"N");

	int area,xuser=25,yuser=220;
/********** 'f':x-axes movement increment factor. ***************/
	int f=10;
	char *m;
	rectangle(0,0,xm,ym);
	rectangle(25,220,65,260);
	setfillstyle(CLOSE_DOT_FILL,RED);
	floodfill(27,240,WHITE);
	
/************      horizontal lines          *************/

	for(int i=75;i<600;i=i+60)
	{
		line(i,0,i,ym);
	}
	area=imagesize(25,220,65,260);
	m=(char *)malloc(area);
	getimage(25,220,65,260,m);
/********* blocks creation: Track 1 block 1   ***********/
	int y11=0,y12=40,area11;char *m11;
	rectangle(85,y11,125,y12);
	setfillstyle(LINE_FILL,RED);
	floodfill(100,30,WHITE);
	area11=imagesize(85,y11,125,y12);
	m11=(char *)malloc(area11);
	getimage(85,y11,125,y12,m11);
	
/***************   Track1: block 2    ********************/
	int y13=120,y14=160;
	rectangle(85,y13,125,y14);
	setfillstyle(LINE_FILL,RED);
	floodfill(100,140,WHITE);
	getimage(85,y13,125,y14,m11);
	
/**************** Track1: block 3      *******************/   
 	int y15=240,y16=280;
	rectangle(85,y15,125,y16);
	setfillstyle(LINE_FILL,RED);
	floodfill(100,260,WHITE);
	getimage(85,y15,125,y16,m11);
	
/***************    Track1: block 4      ******************/
	int y17=360,y18=400;
	rectangle(85,y17,125,y18);
	setfillstyle(LINE_FILL,RED);
	floodfill(100,380,WHITE);
	getimage(85,y17,125,y18,m11);

/*********** blocks creation: Track 2 block 1  ***********/
	int y21=0,y22=40,area21;char *m21;
	rectangle(145,y21,185,y22);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(170,20,WHITE);
	area21=imagesize(145,y21,185,y22);
	m21=(char *)malloc(area21);
	getimage(145,y21,185,y22,m21);

/*********** blocks creation: Track 2 block 2     **********/
	int y23=120,y24=160;
	rectangle(145,y23,185,y24);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(170,140,WHITE);
	getimage(145,y23,185,y24,m21);

/************** blocks creation: Track 2 block 3   *********/
	int y25=240,y26=280;
	rectangle(145,y25,185,y26);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(170,260,WHITE);
	getimage(145,y25,185,y26,m21);

/*********   blocks creation: Track 2 block 4       *********/
 	int y27=360,y28=400;
	rectangle(145,y27,185,y28);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(170,380,WHITE);
	getimage(145,y27,185,y28,m21);

/************ blocks creation: Track 3 block 1   ***********/
	int y31=0,y32=60,area31;char *m31;int f3=1;
	rectangle(205,y31,245,y32);
	setfillstyle(HATCH_FILL,YELLOW);
	floodfill(215,5,WHITE);
	area31=imagesize(205,y31,245,y32);
	m31=(char *)malloc(area31);
	getimage(205,y31,245,y32,m31);

/********** blocks creation: Track 3 block 2     ************/
	int y33=419,y34=478,area32;char *m32;int f4=-1;
	rectangle(205,y33,245,y34);
	setfillstyle(HATCH_FILL,YELLOW);
	floodfill(215,450,WHITE);
	area32=imagesize(205,y33,245,y34);
	m32=(char *)malloc(area32);
	getimage(205,y33,245,y34,m32);

/************ blocks creation: Track 4 block 1  ***************/
	int y41=0,y42=10,area41;char *m41;
	rectangle(265,y41,305,y42);
	setfillstyle(SOLID_FILL,RED);
	floodfill(275,5,WHITE);
	area41=imagesize(265,y41,305,y42);
	m41=(char *)malloc(area41);
	getimage(265,y41,305,y42,m41);

/************ blocks creation: Track 4 block 2  ***************/
	int y43=160,y44=170,area42;char *m42;
	rectangle(265,y43,305,y44);
	setfillstyle(SOLID_FILL,RED);
	floodfill(275,165,WHITE);
	area42=imagesize(265,y43,305,y44);
	m42=(char *)malloc(area42);
	getimage(265,y43,305,y44,m42);

/************ blocks creation: Track 4 block 3  ***************/
	int y45=320,y46=330,area43;char *m43;
	rectangle(265,y45,305,y46);
	setfillstyle(SOLID_FILL,RED);
	floodfill(275,325,WHITE);
	area43=imagesize(265,y45,305,y46);
	m43=(char *)malloc(area43);
	getimage(265,y45,305,y46,m43);

/************ blocks creation: Track 5 block 1  ***************/
	int y51=(ym/2-59),y52=ym/2-1,area51;char *m51;int f5=1;
	rectangle(325,y51,365,y52);
	setfillstyle(HATCH_FILL,YELLOW);
	floodfill(345,ym/2-30,WHITE);
	area51=imagesize(325,y51,365,y52);
	m51=(char *)malloc(area51);
	getimage(325,y51,365,y52,m51);

/************ blocks creation: Track 5 block 2  ***************/
	int y53=ym/2,y54=(ym/2+59),area52;char *m52;int f6=-1;
	rectangle(325,y53,365,y54);
	setfillstyle(HATCH_FILL,YELLOW);
	floodfill(345,ym/2+30,WHITE);
	area52=imagesize(325,y53,365,y54);
	m52=(char *)malloc(area52);
	getimage(325,y53,365,y54,m52);

/************ blocks creation: Track 6 block 1  ***************/
	int y61=0,y62=40,area61;char *m611;
	rectangle(385,y61,425,y62);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(400,20,WHITE);
	area61=imagesize(385,y61,425,y62);
	m611=(char *)malloc(area61);
	getimage(385,y61,425,y62,m611);


/************ blocks creation: Track 6 block 2  ***************/
	int y63=120,y64=160;
	rectangle(385,y63,425,y64);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(390,140,WHITE);
	getimage(385,y63,425,y64,m611);

/************ blocks creation: Track 6 block 3  ***************/
	int y65=240,y66=280;
	rectangle(385,y65,425,y66);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(390,260,WHITE);
	getimage(385,y65,425,y66,m611);

/************ blocks creation: Track 6 block 4  ***************/
	int y67=360,y68=400;
	rectangle(385,y67,425,y68);
	setfillstyle(LINE_FILL,BLUE);
	floodfill(390,380,WHITE);
	getimage(385,y67,425,y68,m611);

/************ blocks creation: Track 7 block 1  ***************/
	int y71=0,y72=40,area71;char *m71;
	rectangle(445,y71,485,y72);
	setfillstyle(LINE_FILL,RED);
	floodfill(460,10,WHITE);
	area71=imagesize(445,y71,485,y72);
	m71=(char *)malloc(area71);
	getimage(445,y71,485,y72,m71);
	
/************ blocks creation: Track 7 block 2  ***************/
	int y73=120,y74=160;
	rectangle(445,y73,485,y74);
	setfillstyle(LINE_FILL,RED);
	floodfill(460,140,WHITE);
	getimage(445,y73,485,y74,m71);
	
/************ blocks creation: Track 7 block 3  ***************/
	int y75=240,y76=280;
	rectangle(445,y75,485,y76);
	setfillstyle(LINE_FILL,RED);
	floodfill(460,260,WHITE);
	getimage(445,y75,485,y76,m71);
	
/************ blocks creation: Track 7 block 4  ***************/
	int y77=360,y78=400;
	rectangle(445,y77,485,y78);
	setfillstyle(LINE_FILL,RED);
	floodfill(460,380,WHITE);
	getimage(445,y77,485,y78,m71);


/************ blocks creation: Track 8 : Window  ***************/
	int y81=0,y82=50,area81;char *m81;
	rectangle(565,y81,623,y82);
	setfillstyle(EMPTY_FILL,YELLOW);
	floodfill(585,20,WHITE);
	outtextxy(578,25,"DOOR");
	setfillstyle(WIDE_DOT_FILL,RED);
	floodfill(530,100,WHITE);
	area81=imagesize(565,y81,623,y82);
	m81=(char *)malloc(area81);
	getimage(565,y81,623,y82,m81);
	putimage(565,y81,m81,XOR_PUT);
	putimage(496,y81,m81,XOR_PUT);

	if(once==2){
		getch();
	}


	while(1)
	{
		 /******** condition((y1-1)>=y)&&((y1-1)<=(y+80 for 1st n 2nd Track     *************/
		if(((xuser==85)&&(yuser<=y11+40)&&(yuser+40>=y11)||(xuser==85)&&(yuser<=y13+40)&&(yuser+40>=y13)||(xuser==85)&&(yuser<=y15+40)&&(yuser+40>=y15)||(xuser==85)&&(yuser<=y17+40)&&(yuser+40>=y17))||((xuser==145)&&(yuser<=y21+40)&&(yuser+40>=y21)||(xuser==145)&&(yuser<=y23+40)&&(yuser+40>=y23)||(xuser==145)&&(yuser<=y25+40)&&(yuser+40>=y25))||((xuser==145)&&(yuser<=y27+40)&&(yuser+40>=y27))||((xuser==205)&&(yuser<=y31+60)&&(yuser+40>=y31))||((xuser==205)&&(yuser<=y33+60)&&(yuser+40>=y33))||((xuser==265)&&(yuser<=y41+10)&&(yuser+40>=y41)||(xuser==265)&&(yuser<=y43+10)&&(yuser+40>=y43)||(xuser==265)&&(yuser<=y45+10)&&(yuser+40>=y45))||((xuser==325)&&(yuser<=y51+60)&&(yuser+40>=y51)||(xuser==325)&&(yuser<=y53+60)&&(yuser+40>=y53)))
		{
			CON:
			
			getch();
			l--;
		
		
		    /********* Exit-CODE ************/
			if(l==0)
			{
				getch();
				outtextxy(xm/2-100,ym/2,"Oops!! You Lost All Your Lifes");
				outtextxy(xm/2-70,ym/2+30,"Better luck next time");
				getch();
				closegraph();
				printf("\n\n Programmer: Srinivas R Vaidya");
				getch();
				exit(0);
			     
			}
			/*********** Player wants to play again **********/
			else
			{
				getch();
				goto START;
			}
	   }

	   if((xuser==445)&&(yuser<=y71+40)&&(yuser+40>=y71)||(xuser==445)&&(yuser<=y73+40)&&(yuser+40>=y73)||(xuser==445)&&(yuser<=y75+40)&&(yuser+40>=y75)||(xuser==445)&&(yuser<=y77+40)&&(yuser+40>=y77)||(xuser==385)&&(yuser<=y61+40)&&(yuser+40>=y61)||(xuser==385)&&(yuser<=y63+40)&&(yuser+40>=y63)||(xuser==385)&&(yuser<=y65+40)&&(yuser+40>=y65)||(xuser==385)&&(yuser<=y67+40)&&(yuser+40>=y67)||((xuser==505)&&((yuser>=y81+50)||(yuser+40<=y81))))
	   {
			goto CON;
	   }

	   /********* Player reaches final track **************/
			
	   if(xuser==565)
	   {
		
			getch();
			outtextxy(xm/2-70,ym/2,"Yeah, You Win!! ");
			getch();
			closegraph();

			printf("\n\n Programmer: Srinivas R. Vaidya ");
			getch();
			exit(0);
	   }

/**** when user hits a button on the keyboard. ******/
		if(kbhit())   
		{
		
		/**   fetching and storing which key is pressed into 'ch'  **/ 
			char ch=getch();   
			
			if(ch==27)
			{
				break;
			}
			else
			if(ch==80)
			/************** User clicks Right arrow key **************/
			{
				if((yuser==440)||(yuser>=440)){}
				else
				{
					putimage(xuser,yuser,m,XOR_PUT);
					yuser+=f;
					putimage(xuser,yuser,m,XOR_PUT);
				}
			}
			else
			if(ch==72)
			/************** User clicks Left arrow key **************/
			{
				if((yuser==0)||(yuser<=0)){}
				else
				{
					putimage(xuser,yuser,m,XOR_PUT);
					yuser-=f;
					putimage(xuser,yuser,m,XOR_PUT);
				}
			}
			else
			if(ch==75)
			/************** User clicks Bottom arrow key **************/
			{
				if(xuser==25){}
				else
				{
					putimage(xuser,yuser,m,XOR_PUT);
					xuser-=60;
					putimage(xuser,yuser,m,XOR_PUT);
				}
			}
			else
			if(ch==77)
			/************** User clicks Up arrow key **************/
			{
				if(xuser==565){}
				else
				{
				putimage(xuser,yuser,m,XOR_PUT);
				xuser+=60;
				putimage(xuser,yuser,m,XOR_PUT);
				}
			}
			else
			{
				// blank;
			}

		}
		
/********   1st Track 1st block     ***********/
		putimage(85,y11,m11,XOR_PUT);
		delay(0);
		y11+=s1;
		putimage(85,y11,m11,XOR_PUT);
		if(y11>ym)
		{
			putimage(85,y11,m11,XOR_PUT);
			y11=0;
			putimage(85,y11,m11,XOR_PUT);
		}


/********   1st Track 2nd block     ***********/
		putimage(85,y13,m11,XOR_PUT);
		delay(0);
		y13+=s1;
		putimage(85,y13,m11,XOR_PUT);
		if(y13>ym)
		{
			putimage(85,y13,m11,XOR_PUT);
			y13=0;
			putimage(85,y13,m11,XOR_PUT);
		}

/********   1st Track 3rd block     ***********/
		putimage(85,y15,m11,XOR_PUT);
		delay(0);
		y15+=s1;
		putimage(85,y15,m11,XOR_PUT);
		if(y15>ym)
		{
			putimage(85,y15,m11,XOR_PUT);
			y15=0;
			putimage(85,y15,m11,XOR_PUT);
		}
	
/********   1st Track 4th block     ***********/
		putimage(85,y17,m11,XOR_PUT);
		delay(0);
		y17+=s1;
		putimage(85,y17,m11,XOR_PUT);
		if(y17>ym)
		{
			putimage(85,y17,m11,XOR_PUT);
			y17=0;
			putimage(85,y17,m11,XOR_PUT);
		}

/********   2st Track 1st block     ***********/
		putimage(145,y21,m21,XOR_PUT);
		delay(0);
		y21-=s2;
		putimage(145,y21,m21,XOR_PUT);
		if(y21<0)
		{
			putimage(145,y21,m21,XOR_PUT);
			y21=ym;
			putimage(145,y21,m21,XOR_PUT);
		}

/********   2nd Track 2nd block     ***********/
		putimage(145,y23,m21,XOR_PUT);
		delay(0);
		y23-=s2;
		putimage(145,y23,m21,XOR_PUT);
		if(y23<0)
		{
			putimage(145,y23,m21,XOR_PUT);
			y23=ym;
			putimage(145,y23,m21,XOR_PUT);
		}

/********   2nd Track 3rd block     ***********/
		putimage(145,y25,m21,XOR_PUT);
		delay(0);
		y25-=s2;
		putimage(145,y25,m21,XOR_PUT);
		if(y25<0)
		{
			putimage(145,y25,m21,XOR_PUT);
			y25=ym;
			putimage(145,y25,m21,XOR_PUT);
		}

/********   2nd Track 4th block     ***********/
		putimage(145,y27,m21,XOR_PUT);
		delay(0);
		y27-=s2;
		putimage(145,y27,m21,XOR_PUT);
		if(y27<0)
		{
			putimage(145,y27,m21,XOR_PUT);
			y27=ym;
			putimage(145,y27,m21,XOR_PUT);
		}

/********   3rd Track 1st block     ***********/
		if(y31==(ym/2-59)||(y31<0))
		{
			f3*=-1;
		}
		putimage(205,y31,m31,XOR_PUT);
		y31=y31+(f3*s3);
		putimage(205,y31,m31,XOR_PUT);
		if(y33==239||(y33>ym-60))
		{
			f4*=-1;
		}
		putimage(205,y33,m32,XOR_PUT);
		y33=y33+(f4*s3);
		putimage(205,y33,m32,XOR_PUT);

/********   4th Track 1st block     ***********/
		putimage(265,y41,m41,XOR_PUT);
		delay(0);
		y41-=s4;
		putimage(265,y41,m41,XOR_PUT);
		if(y41<0)
		{
			putimage(265,y41,m41,XOR_PUT);
			y41=ym;
			putimage(265,y41,m41,XOR_PUT);
		}

/********   4th Track 2nd block     ***********/
		putimage(265,y43,m42,XOR_PUT);
		delay(0);
		y43-=s4;
		putimage(265,y43,m42,XOR_PUT);
		if(y43<0)
		{
			putimage(265,y43,m42,XOR_PUT);
			y43=ym;
			putimage(265,y43,m42,XOR_PUT);
		}

/********   4th Track 3rd block     ***********/
		putimage(265,y45,m43,XOR_PUT);
		delay(0);
		y45-=s4;
		putimage(265,y45,m43,XOR_PUT);
		if(y45<0)
		{
			putimage(265,y45,m43,XOR_PUT);
			y45=ym;
			putimage(265,y45,m43,XOR_PUT);
		}

/********   5th Track 1st block     ***********/
		if(y51==(ym/2-59)||(y51<0))
		{
			f5*=-1;
		}
		putimage(325,y51,m51,XOR_PUT);
		y51=y51+(f5*s5);
		putimage(325,y51,m51,XOR_PUT);
		if(y53==239||(y53>ym-60))
		{
			f6*=-1;
		}
		putimage(325,y53,m52,XOR_PUT);
		y53=y53+(f6*s5);
		putimage(325,y53,m52,XOR_PUT);



/********   7th Track 1st block     ***********/
		putimage(445,y71,m71,XOR_PUT);
		delay(0);
		y71+=s7;
		putimage(445,y71,m71,XOR_PUT);
		if(y71>ym)
		{
			putimage(445,y71,m71,XOR_PUT);
			y71=0;
			putimage(445,y71,m71,XOR_PUT);
		}

/********   7th Track 2nd block     ***********/
		putimage(445,y73,m71,XOR_PUT);
		delay(0);
		y73+=s7;
		putimage(445,y73,m71,XOR_PUT);
		if(y73>ym)
		{
			putimage(445,y73,m71,XOR_PUT);
			y73=0;
			putimage(445,y73,m71,XOR_PUT);
		}
		
/********   7th Track 3rd block     ***********/
		putimage(445,y75,m71,XOR_PUT);
		delay(0);
		y75+=s7;
		putimage(445,y75,m71,XOR_PUT);
		if(y75>ym)
		{
			putimage(445,y75,m71,XOR_PUT);
			y75=0;
			putimage(445,y75,m71,XOR_PUT);
		}
		
/********   7th Track 4st block     ***********/
		putimage(445,y77,m71,XOR_PUT);
		delay(0);
		y77+=s7;
		putimage(445,y77,m71,XOR_PUT);
		if(y77>ym)
		{
			putimage(445,y77,m71,XOR_PUT);
			y77=0;
			putimage(445,y77,m71,XOR_PUT);
		}


/********   6th Track 1st block     ***********/
		putimage(385,y61,m611,XOR_PUT);
		delay(0);
		y61-=s6;
		putimage(385,y61,m611,XOR_PUT);
		if(y61<0)
		{
			putimage(385,y61,m611,XOR_PUT);
			y61=ym;
			putimage(385,y61,m611,XOR_PUT);
		}

/********   6th Track 2nd block     ***********/
		putimage(385,y63,m611,XOR_PUT);
		delay(0);
		y63-=s6;
		putimage(385,y63,m611,XOR_PUT);
		if(y63<0)
		{
			putimage(385,y63,m611,XOR_PUT);
			y63=ym;
			putimage(385,y63,m611,XOR_PUT);
		}

/********   6th Track 3rd block     ***********/
		putimage(385,y65,m611,XOR_PUT);
		delay(0);
		y65-=s6;
		putimage(385,y65,m611,XOR_PUT);
		if(y65<0)
		{
			putimage(385,y65,m611,XOR_PUT);
			y65=ym;
			putimage(385,y65,m611,XOR_PUT);
		}

/********   6th Track 4th block     ***********/
		putimage(385,y67,m611,XOR_PUT);
		delay(0);
		y67-=s6;
		putimage(385,y67,m611,XOR_PUT);
		if(y67<0)
		{
			putimage(385,y67,m611,XOR_PUT);
			y67=ym;
			putimage(385,y67,m611,XOR_PUT);
		}

/**********     8th Track      *****************/
		putimage(496,y81,m81,XOR_PUT);
		delay(0);
		y81-=s8;
		putimage(496,y81,m81,XOR_PUT);
		if(y81<0)
		{
			putimage(496,y81,m81,XOR_PUT);
			y81=ym;
			putimage(496,y81,m81,XOR_PUT);
		}

	}


	getch();
	closegraph();

}



