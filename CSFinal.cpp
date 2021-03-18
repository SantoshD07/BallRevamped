#include<fstream.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<math.h>
class GAME
{
   public:
   int life;
   char name[50];
   double score;
   GAME()
   {   life=3;
       score=0;
   }
}ob;
char CH;
int c=0,i=40,j=80,x=0,y=0,r=17,R=15;
int Y[3]={120,230,340};
int X[6]={10,500,150,600,10,450};
float p=0, q=0, t=0;
void lifedisp();
void line1(int, int, int);
void line2(int, int, int);
void main()
{

    int gd=DETECT,gm,colour=1,lcolour=28;
    int z;
    initgraph(&gd,&gm,"C:\\TurboC3\\BGI");


    settextstyle(1,0,5);
    setpalette(7,24);
    setpalette(11,15);
    int a,b;
    a=0;
    b=0;
	// getting maximum width
    int we=getmaxx();
	//getting maximum height
    z=getmaxy();
    setcolor(11);
    rectangle(a+80,b+80,we-100,z-80);
    setfillstyle(1,7);
    bar(a+81,b+81,we-101,z-81);
    setlinestyle(3,0,0);
    setcolor(14);
    rectangle(a+83,b+83,we-103,z-83);
    setlinestyle(0,0,0);
    setcolor(0);
    rectangle(a+86,b+86,we-106,z-86);
    // Finish drawingthe splash window
    putpixel(303,98,0);
    setfillstyle(5,2);

    setcolor(14);
    settextstyle(0,0,3);
    outtextxy(100,100,"Blue Ball Journey");
    setcolor(9);
    setfillstyle(1,9);
    circle(300,184,38);
      floodfill(300,184,9);
    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(120,250,"C.S Investigatory Project ");
    setcolor(19);
    settextstyle(0,0,2);
    outtextxy(95,300," By: Santosh, Kunal & Deep");
     setcolor(19);
    settextstyle(0,0,2);
     delay(4000);
    cleardevice();


    setcolor(15);
    settextstyle(0,0,2);
    outtextxy(100,200," Press 1 to Play the game ");
    setcolor(19);
    settextstyle(0,0,2);
    outtextxy(100,250," Press 2 to display Highscore");
     setcolor(14);
    settextstyle(0,0,2);
    cin>>CH;

    if(CH=='1')
  { clrscr();
    cleardevice();

    setcolor(14);
    settextstyle(0,0,3);
    outtextxy(100,100,"Enter Name");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                              ";
    gets(ob.name);
    cleardevice();

    settextstyle(0,0,2);
    outtextxy(260,16,"RULES");   delay(1000);
    setcolor(BLUE);
    setfillstyle(1,colour);
    circle(100,100,15);  floodfill(100,100,BLUE);    delay(1000);
    setcolor(GREEN);
    setfillstyle(1,colour+1);
    circle(100,170,15);     delay(1000);
    setcolor(RED);	 line(100,230,100,310);      delay(1000);
    setcolor(WHITE);
    outtextxy(150,95,"- Blue Ball");                      delay(1000);
    outtextxy(150,163,"- Destination");              delay(1000);
    outtextxy(150,270,"- Death line ");  delay(1500);
    settextstyle(0,0,0);
    outtextxy(170,390,"Use Arrow Keys to move the Blue Ball"); delay(2000);
    outtextxy(120,420,"Reach the Destination before you run out of time... "); delay(3000);
    cleardevice();
    settextstyle(0,0,2);
    setcolor(YELLOW);
    outtextxy(220,240,"Good Luck !!");   delay(1000);

    setcolor(WHITE);
    cleardevice();
    settextstyle(0,0,3);
    outtextxy(220,240,"Level 1");
     delay(2000);

    goto level1;
  }						//if CH==1

  if(CH=='2')
  {
    GAME ob;
    int maxrec=0;
    char high[80];
    ifstream in("score.txt",ios::in);
    cout<<"\n\n 			Highscores\n\n";
    while(!in.eof())
    {
       in.getline(high,80);
       cout<<"\n\t\t"<<high<<"\n";
       maxrec++;
       if(maxrec==9)
	break;

    }
    in.close();
    getch();
    exit(0);
  }				//if CH==2


  else
    exit(0);
 level1:while(ob.life>0)
 {
  setcolor(WHITE);
  settextstyle(0,0,0);
  rectangle(10,50,600,450); //main rectangle
  setcolor(colour);
  setfillstyle(1,colour);
  circle(i,j,R);
  floodfill(i,j,colour);
  setcolor(lcolour);
  line(X[0],Y[0],X[1],Y[0]); //line 1
  line(X[2],Y[1],X[3],Y[1]); //line 2
  line(X[4],Y[2],X[5],Y[2]); //line 3


  setcolor(GREEN);
  lifedisp();
  setfillstyle(1,colour+1);
  circle(100,400,15);
//  floodfill(100,400,GREEN);
  setcolor(WHITE);
  outtextxy(110,20,"Press Q to exit");

  if(kbhit())
  {
   c=getch();
   if(c==72)//up
   {  x=0; y=-1;
   //sound(432);delay(50);nosound();
   }
   if(c==75)//left
   {  x=-1; y=0;
   //sound(600);delay(50);nosound();
   }
   if(c==77)//right
   {  x=1; y=0;
    //sound(600);delay(50);nosound();
    }
   if(c==80)//down
   {  x=0; y=1;
   //sound(432);delay(50);nosound();
    }
   if(c==113 || c==81)
   { cleardevice();  exit(0);    }

   //circle restrict
   if(c==72&&j<70)//up
   {  x=0; y=0;    }
   if(c==75&&i<30)//left
   {  x=0; y=0;   }
   if(c==77&&i>580)//right
   {  x=0; y=0;   }
   if(c==80&&j>430)//down
   {  x=0; y=0;   }

   }//if
   line1(X[0],Y[0],X[1]); //line 1
   line1(X[2],Y[1],X[3]); //line 2
   line1(X[4],Y[2],X[5]); //line 3

    i=i+(4*x);
    j=j+(4*y);
    x=0;y=0;
    delay(20);
    cleardevice();

    if(pow(pow((100-i),2)+pow((400-j),2),0.5)<=35)    //exit hole
     { setcolor(WHITE); settextstyle(0,0,1); cleardevice(); outtextxy(178,240,"Congratulations ! Level 1 Clear"); delay(1500); goto level2;  }

    setcolor(colour+2);
  /*  outtextxy(626,50,"T");  outtextxy(625,65,"I");  outtextxy(625,80,"M");  outtextxy(625,95,"E");     outtextxy(625,110,"R");*/
    outtextxy(490,30,"             TIMER");
    setcolor(WHITE);
    rectangle(610,50,615,300);
    line(610,p+50,615,p+50);
    p=p+0.05;
    if(p>250)
    {  setcolor(GREEN); settextstyle(0,0,2); cleardevice(); outtextxy(130,220,"OMG! You ran out of time"); delay(2000); ob.life--; p=0;}


 }//while level 1

//----------------------------------------LEVEL 2 -----------------------------------------

 level2:
 setcolor(WHITE);
 i=40,j=80;
 cleardevice();
 settextstyle(0,0,3);
 outtextxy(220,240,"Level 2");
 delay(1500);
 cleardevice();
 int linetop[3]={130,200,280};
 int linever[3]={350,430,490};
 int linebot[3]={210,270,350};
 int linepos[3]={0,1,0};

 while(ob.life>0)
 {

  setcolor(WHITE);
  settextstyle(0,0,0);
  rectangle(10,50,600,450); //main rectangle
  setcolor(colour);
  setfillstyle(1,colour);
  circle(i,j,R);
  floodfill(i,j,colour);
  setcolor(lcolour);

	   {
	     line(295,49,295,380);      line2(295,50,380);

	     line(100,51,100,350);      line2(100,50,350);
	     line(200,120,200,449);     line2(200,120,449);
	    /* line(10,120,170,120);      line1(10,120,170);
	     line(240,120,295,120);     line1(240,120,295);
	     line(10,190,50,190);       line1(10,190,50);
	     line(120,190,295,190);     line1(120,190,295);
	     line(10,250,230,250);      line1(10,250,230);
	     line(100,310,295,310);     line1(100,310,295);
	     line(100,310,100,390);     line2(100,310,390);
	     line(190,370,190,449);     line2(190,370,449);*/
	     line(295,380,530,380);	line1(295,380,530);
	     line(360,290,599,290);	line1(360,290,599);
	     line(295,200,530,200);	line1(295,200,530);
	     line(360,120,599,120); 	line1(360,120,599);


	   }
  setcolor(GREEN);
  lifedisp(); 	                        // green circle
  setfillstyle(1,colour+1);
  circle(560,90,15);
//  floodfill(560,90,GREEN);
  setcolor(WHITE);
  outtextxy(110,20,"Press Q to exit");

  if(kbhit())
  {
   c=getch();
   if(c==72)//up
   {  x=0; y=-1;
 //  sound(432);delay(50);nosound();
   }
   if(c==75)//left
   {  x=-1; y=0;
 //  sound(600);delay(50);nosound();
   }
   if(c==77)//right
   {  x=1; y=0;
 //   sound(600);delay(50);nosound();
   }
   if(c==80)//down
   {  x=0; y=1;
 //  sound(432);delay(50);nosound();
   }
   if(c==113 || c==81)
   { cleardevice();  exit(0);    }

   //circle restrict
   if(c==72&&j<70)//up
   {  x=0; y=0;    }
   if(c==75&&i<30)//left
   {  x=0; y=0;   }
   if(c==77&&i>580)//right
   {  x=0; y=0;   }
   if(c==80&&j>430)//down
   {  x=0; y=0;   }
   }//if

   setcolor(RED);                  // moving red lines
   for(int I=0; I<3; I++)
   {
	if(linepos[I]==0)
	{   line(linever[I],linetop[I],linever[I],linebot[I]); line2(linever[I],linetop[I],linebot[I]); linetop[I]++; linebot[I]++;   }
	if(linepos[I]==1)
	{   line(linever[I],linetop[I],linever[I],linebot[I]); line2(linever[I],linetop[I],linebot[I]); linetop[I]--; linebot[I]--;   }


	   {
	   if(linetop[I]==52)
	     linepos[I]=0;
	    else if(linebot[I]==449)
	     linepos[I]=1;
	   }
   }
   setcolor(WHITE);


   i=i+(4*x);
   j=j+(4*y);
   x=0;y=0;
   delay(20);
   cleardevice();

   if(pow(pow((560-i),2)+pow((90-j),2),0.5)<=35)    //exit hole
     { setcolor(WHITE); settextstyle(0,0,1); cleardevice(); outtextxy(178,240,"Congratulations ! Level 2 Clear"); delay(1500); goto level3;}

   setcolor(colour+2);
  /*  outtextxy(626,50,"T");  outtextxy(625,65,"I");  outtextxy(625,80,"M");  outtextxy(625,95,"E");     outtextxy(625,110,"R");*/
    outtextxy(490,30,"             TIMER");
   setcolor(WHITE);
   rectangle(610,50,615,300);
   line(610,q+50,615,q+50);
   q=q+0.03;
   if(q>250)
   {  setcolor(GREEN); settextstyle(0,0,2); cleardevice(); outtextxy(130,220,"OMG! You ran out of time"); delay(2000); ob.life--; q=0;}



 }// while level2

 //-----------------------------------------LEVEL 3-------------------------------

 level3:

 int Linetop[5]={130,200,280,80,350};
 int Linever[5]={330,380,430,480,530};
 int Linebot[5]={210,270,350,150,430};
 int Linepos[5]={0,1,0,1,1};
 setcolor(WHITE);

 i=40,j=80;
 cleardevice();
 settextstyle(0,0,3);
 outtextxy(220,240,"Level 3");
 delay(1500);
 cleardevice();
 while(ob.life>0)
 {
  setcolor(WHITE);
  settextstyle(0,0,0);
  rectangle(10,50,600,450); //main rectangle
  setcolor(colour);
  setfillstyle(1,colour);
  circle(i,j,R);
  floodfill(i,j,colour);
  setcolor(lcolour);

	   {
	     line(295,49,295,380);      line2(295,49,380);

	     line(10,120,190,120);      line1(10,120,190);
	     line(250,120,295,120);     line1(250,120,295);
	     line(10,190,50,190);       line1(10,190,50);
	     line(110,190,295,190);     line1(110,190,295);
	     line(10,250,230,250);      line1(10,250,230);
	     line(100,310,295,310);     line1(100,310,295);
	     line(100,310,100,390);     line2(100,310,390);
	     line(190,370,190,449);     line2(190,370,449);
	     line(295,380,530,380);	line1(295,380,530);
	     line(360,290,599,290);	line1(360,290,599);
	     line(295,200,530,200);	line1(295,200,530);
	     line(360,120,599,120); 	line1(360,120,599);


	   }
  setcolor(GREEN);
  lifedisp(); 	                        // green circle
  setfillstyle(1,colour+1);
  circle(560,90,15);
//  floodfill(560,90,GREEN);
  setcolor(WHITE);
  outtextxy(110,20,"Press Q to exit");

  if(kbhit())
  {
   c=getch();
   if(c==72)//up
   {  x=0; y=-1;   }
   //sound(432);delay(50);nosound();      }
   if(c==75)//left
   {  x=-1; y=0;   }
   //sound(600);delay(50);nosound();      }
   if(c==77)//right
   {  x=1; y=0;    }
    //sound(600);delay(50);nosound();     }
   if(c==80)//down
   {  x=0; y=1;    }
   //sound(432);delay(50);nosound();      }
   if(c==113 || c==81)
   { cleardevice();  exit(0);    }

   //circle restrict
   if(c==72&&j<70)//up
   {  x=0; y=0;    }
   if(c==75&&i<30)//left
   {  x=0; y=0;   }
   if(c==77&&i>580)//right
   {  x=0; y=0;   }
   if(c==80&&j>430)//down
   {  x=0; y=0;   }
   }//if

   setcolor(RED);                  // moving red lines
   for(int I=0; I<5; I++)
   {
	if(Linepos[I]==0)
	{   line(Linever[I],Linetop[I],Linever[I],Linebot[I]); line2(Linever[I],Linetop[I],Linebot[I]); Linetop[I]++; Linebot[I]++;   }
	if(Linepos[I]==1)
	{   line(Linever[I],Linetop[I],Linever[I],Linebot[I]); line2(Linever[I],Linetop[I],Linebot[I]); Linetop[I]--; Linebot[I]--;   }


	   {
	   if(Linetop[I]==52)
	     Linepos[I]=0;
	    else if(Linebot[I]==449)
	     Linepos[I]=1;
	   }
   }
   setcolor(WHITE);


   i=i+(4*x);
   j=j+(4*y);
   x=0;y=0;
   delay(20);
   cleardevice();

   if(pow(pow((560-i),2)+pow((90-j),2),0.5)<=35)    //exit hole
     { setcolor(WHITE); settextstyle(0,0,1); cleardevice(); outtextxy(178,240,"Congratulations ! Level 3 Clear"); delay(1500); break;}

   setcolor(colour+2);
  /*  outtextxy(626,50,"T");  outtextxy(625,65,"I");  outtextxy(625,80,"M");  outtextxy(625,95,"E");     outtextxy(625,110,"R");*/
    outtextxy(490,30,"             TIMER");
   setcolor(WHITE);
   rectangle(610,50,615,300);
   line(610,t+50,615,t+50);
   t=t+0.03;
   if(t>250)
   {  setcolor(GREEN); settextstyle(0,0,2); cleardevice(); outtextxy(130,220,"OMG! You ran out of time"); delay(2000); ob.life--; t=0;}



 }// while level3

 if(ob.life<1)
 {
  cleardevice();
  setcolor(YELLOW);
  settextstyle(0,0,2);
  outtextxy(200,240,"Game Over ! ");
 }
 ofstream out("score.txt",ios::app);
 ob.score=((10*(p+q+t))+ob.life)+50; delay(1000);
 out<<ob.name<<" : "<<ob.score;
 out.close();

}//main


void line1(int xh1,int yh,int xh2)   //horizontal line
{
   if(c==72 && j<yh+r && j>yh-r && i>xh1-r && i<xh2+r) //up
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }
   if(c==75 && i<xh2+r && i>xh1-r && j<yh+r && j>yh-r) //left
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }
   if(c==77 && i>xh1-r && i<xh2+r && j<yh+r && j>yh-r) //right
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }
   if(c==80 && j<yh+r && j>yh-r && i>xh1-r && i<xh2+r) //down
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }
}

void line2(int vx, int vy1, int vy2)  // vertical line
{
   if(c==72 && i>vx-r && i<vx+r && j>vy1-r && j<vy2+r) //up
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }
   if(c==75 && i>vx-r && i<vx+r && j>vy1-r && j<vy2+r)//left
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }
   if(c==77 && i>vx-r && i<vx+r && j>vy1-r && j<vy2+r) //right
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }
   if(c==80 && i>vx-r && i<vx+r) //down
   {  x=0; y=0; setcolor(RED); settextstyle(0,0,2); cleardevice(); outtextxy(130,240,"Oops! You touched the line"); delay(2000); ob.life--; i=40; j=80;   }

}

void lifedisp()
{
 if(ob.life==3)
  outtextxy(400,20,"Lives left:      ");
 if(ob.life==2)
  outtextxy(400,20,"Lives left:    ");
 if(ob.life==1)
  outtextxy(400,20,"Lives left:  ");
}
