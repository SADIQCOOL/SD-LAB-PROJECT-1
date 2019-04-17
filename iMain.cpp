#include "iGraphics.h"
#include "bitmap_loader.h"
#include "Header.h"
#include "Structure.h"
#include <iostream>




//images of logo

bool show[50],show1[50],show2[10];


                       //pacman BOOLEAN

                       //GHOST BOOLEAN
bool ghostright=false;
bool ghostleft=false;
bool ghostup=false;
bool ghostdown=false;




int ghostdhora=0;


char pacmanchange[27][27]={"images\\pacmancirclebmp.bmp","images\\pacmanopenbmp.bmp"};
//char pacmanopen[]={"images\\pacmanopenbmp.bmp"};
int pacmanIndex=0;


int x = 0, y = 0, r = 20;

int win_b = 400, win_l = 400;
float delay = 0;
int speed = 0;
int counter =0;

/*
 function iDraw() is called again and again by the system.

 */
void drawRoadLines(int offset)
{
	int len = 10;
	int width = 5;
	int gap = 10;
	int midx = 0, midy = win_l / 2;
	for (int i = 0; i < win_b / (len + gap); i++)
		iFilledRectangle((i * (len + gap) + offset) % win_b, midy, len, width);
}





int narutowidth=200;
int narutowheigth=166;
int narutoposX=53;
int narutoposY=53;
int swordy=290;
int ballx=500;
int bally=100;
int dx=10;
int dy=10;


//char sword1[]="images\\sword.bmp";
//char sword2[]="images\\sword.bmp";

char ghost1[]="images\\ghost1.bmp";
char ghost2[]="images\\ghost2.bmp";
char ghost3[]="images\\ghost3.bmp";
int red =255;
int green =255;
int blue =255;

//STRUCTURE FOR GHOST


struct ghost{
	//bool nahian=true;
	char imagelocation1[100],imagelocation2[100],imagelocation3[100];
	void setlocation(){
	strcpy(imagelocation1,"images\\ghost1.bmp");
	strcpy(imagelocation2,"images\\ghost2.bmp");
	strcpy(imagelocation3,"images\\ghost3.bmp");
	}
	bool show;

}strctghost1,strctghost2,strctghost3;


//Array for DOTS AND CODES

int cx[100],cy[100];

int cx1[50],cy1[50];

int cx2[10],cy2[10];





void iDraw()
{
	//place your drawing codes here
	iClear();




	if(menu==0){
iShowBMP(0,0,background);
iSetColor(255,255,0);
iText(150,110,"<CLICK TO START THE GAME>");
iFilledRectangle(150,250,200,50);
iSetColor(0,0,0);
iText(210,270,"START",GLUT_BITMAP_TIMES_ROMAN_24);



iSetColor(255,255,0);
iFilledRectangle(150,190,200,50);
iSetColor(0,0,0);
iText(210,210,"About",GLUT_BITMAP_TIMES_ROMAN_24);



}








	if(menu==1){


	iShowImage(0,0,screenwidth,screenheigth,maze);

	//iShowBMP2(ghost1posx,ghost1posy,strctghost1.imagelocation1,0);

	//iShowBMP2(ghost2posx,ghost2posy,strctghost2.imagelocation2,0);

	//iShowBMP2(ghost3posx,ghost3posy,strctghost3.imagelocation3,0);





	//GHOST 1 BLUE
	GHOST a(30,30,iLoadImage("images//ghost1.png"));
iShowImage(ghost1posx,ghost1posy,a.length,a.height,a.image);

GHOST b(30,30,iLoadImage("images//ghost2.png"));
iShowImage(ghost2posx,ghost2posy,b.length,b.height,b.image);


//RED GHOST 3
GHOST c(30,30,iLoadImage("images//ghost3.png"));
iShowImage(ghost3posx,ghost3posy,c.length,c.height,c.image);






iSetColor(255,255,255);


//Bottom 1st row


    	cx[0]=86; cy[0] = 78;
	    cx[1]=126; cy[1] = 78;
	    cx[2]=166; cy[2] = 78;
	    cx[3]=206; cy[3] = 78;
	    cx[4]=246; cy[4] = 78;
	    cx[5]=286; cy[5] = 78;
	    cx[6]=326; cy[6] = 78;
	    cx[7]=366; cy[7] = 78;

//Bottom 2nd row
	    cx[9]=86; cy[9] = 35;
	    cx[10]=126; cy[10] = 35;
	    cx[11]=166; cy[11] = 35;
	    cx[12]=206; cy[12] = 35;
	    cx[13]=246; cy[13] = 35;
        cx[14]=286; cy[14] = 35;
	    cx[15]=326; cy[15] = 35;
	    cx[16]=366; cy[16] = 35;


//Top row

	    cx[18]=106; cy[18] = 477;
	    cx[19]=146; cy[19] = 477;
	    cx[20]=186; cy[20] = 477;
	    cx[21]=226; cy[21] = 477;
	    cx[22]=266; cy[22] = 477;
	    cx[23]=306; cy[23] = 477;
	    cx[24]=346; cy[24] = 477;
	    cx[25]=386; cy[25] = 477;


//RIGHT SIDE
   	    cx[26]=406; cy[26] = 37;
	    cx[27]=406; cy[27] = 77;
	    cx[28]=406; cy[28] = 117;
	    cx[29]=406; cy[29] = 157;
	    cx[30]=406; cy[30] = 197;
	    cx[31]=406; cy[31] = 237;
	    cx[32]=406; cy[32] = 277;
	    cx[33]=406; cy[33] = 317;
	    cx[34]=406; cy[34] = 357;
	    cx[35]=406; cy[35] = 397;
	    cx[36]=406; cy[36] = 437;
	    cx[37]=406; cy[37] = 477;


//LEFT SIDE
	    cx[38]=66; cy[38] = 37;
	    cx[39]=66; cy[39] = 77;
	    cx[40]=66; cy[40] = 117;
		cx[41]=66; cy[41] = 157;
	    cx[42]=66; cy[42] = 197;
	    cx[43]=66; cy[43] = 237;
	    cx[44]=66; cy[44] = 277;
		cx[45]=66; cy[45] = 317;
	    cx[46]=66; cy[46] = 357;
		cx[47]=66; cy[47] = 397;
		cx[48]=66; cy[48] = 437;
		cx[49]=66; cy[49] = 477;


//LEFT SIDE SPECIAL DOT
		cx1[0]=115; cy1[0]=118;
		cx1[1]=115; cy1[1]=153;
		cx1[2]=115; cy1[2]=188;
		cx1[3]=115; cy1[3]=223;
		cx1[4]=115; cy1[4]=258;
		cx1[5]=115; cy1[5]=293;
		cx1[6]=115; cy1[6]=328;
		cx1[7]=115; cy1[7]=363;
		cx1[8]=115; cy1[8]=398;
		cx1[9]=115; cy1[9]=433;

//RIGHT SIDE SPECIAL DOT
		cx1[10]=351; cy1[10]=118;
		cx1[11]=351; cy1[11]=153;
		cx1[12]=351; cy1[12]=188;
		cx1[13]=351; cy1[13]=223;
		cx1[14]=351; cy1[14]=258;
		cx1[15]=351; cy1[15]=293;
		cx1[16]=351; cy1[16]=328;
		cx1[17]=351; cy1[17]=363;
		cx1[18]=351; cy1[18]=398;
		cx1[19]=351; cy1[19]=433;
//SUPER DOT
		cx2[1]=180; cy2[1]=318;
		cx2[2]=285; cy2[2]=318;

//ANOTHER METHOD


		for(int i=0;i<50;i++){
			if(show[i]){
				iSetColor(255,255,0);
				iFilledCircle(cx[i],cy[i],4,100);
		      }
		}

		for(int i=0;i<20;i++){
			if(show1[i]){
				iSetColor(255,28,28);
				iFilledCircle(cx1[i],cy1[i],4,100);
		      }
		}
		for(int i=0;i<3;i++){
			if(show2[i]){
				iSetColor(0,255,255);
				iFilledCircle(cx2[i],cy2[i],5,100);
		      }
		}




//for bottom 1st row
for(int i=77,j=0;i<=358&&j<9;i+=40,j++){
	if(packmanposx>=i&&packmanposx<=i+10&&packmanposy>=66&&packmanposy<=85){
		show[j]=false;
	 }
	}
//for bottom 2nd row
for(int i=77,j=9;i<=358&&j<=17;i+=40,j++){
	if(packmanposx>=i&&packmanposx<=i+10&&packmanposy>=20&&packmanposy<=40){
		show[j]=false;
	 }
	}
//for left column
for(int i=30,j=38;i<=500&&j<50;i+=40,j++){
	if(packmanposy>=i&&packmanposy<=i+10&&packmanposx>=50&&packmanposx<=75){
		show[j]=false;
	 }
	}


//for right column
for(int i=30,j=26;i<=500&&j<38;i+=40,j++){
	if(packmanposy>=i&&packmanposy<=i+10&&packmanposx>=385&&packmanposx<=415){
		show[j]=false;
	 }
	}


//for top row
for(int i=106,j=18;i<=400&&j<26;i+=40,j++){
	if(packmanposx>=i&&packmanposx<=i+5&&packmanposy>=465&&packmanposy<=490){
		show[j]=false;
	 }
	}
//for left side special dot
for(int i=110,j=0;i<=450&&j<=9;i+=35,j++){
	if(packmanposy>=i&&packmanposy<=i+10&&packmanposx>=95&&packmanposx<=120){
		show1[j]=false;
	 }
	}
//for right side special dot
for(int i=110,j=10;i<=450&&j<=19;i+=35,j++){
	if(packmanposy>=i&&packmanposy<=i+10&&packmanposx>=330&&packmanposx<=355){
		show1[j]=false;
	 }
	}
//for super dot
for(int i=170,j=1;i<=295&&j<=2;i+=105,j++){
	if(packmanposx>=i&&packmanposx<=i+10&&packmanposy>=300&&packmanposy<=330){
		show2[j]=false;
	 }
	}







	if(stop==1){


	}





//Collison by SADIQ & NAHIAN

if(right)
{
	//stop==1;


	
iShowImage(packmanposx,packmanposy,pacmanwidth,pacmanheight,pacman);

}
	if(left){
		iShowImage(packmanposx,packmanposy,pacmanwidth,pacmanheight,pacmanrotateleft);

	
	}

	if(up){

		iShowImage(packmanposx,packmanposy,pacmanwidth,pacmanheight,pacmanrotateup);

	}

	if(down){
		iShowImage(packmanposx,packmanposy,pacmanwidth,pacmanheight,pacmanrotatedown);
		
	}

	}




	//  GAMEOVER

	if(menu==2){
	
	  iShowImage(0,0,screenwidth,screenheigth,gameover);
	}




		if(menu==3){
			iShowImage(0,0,screenwidth,screenheigth,created);





}








}

void iPassiveMouse(int x, int y)
{
	;
}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
 */
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);

		if(mx>=150 && mx<=350 && my>=250 && my>=250 && my<=300)


			menu=1;


		if(mx>=150 && mx<=350  && my>=190 && my<=230)


			menu=3;



	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		//x -= 10;
		//y -= 10;

	}
}


/*
 function iKeyboard() is called whenever the user hits a key in keyboard.
 key- holds the ASCII value of the key pressed.
 */
void iKeyboard(unsigned char key)
{
	if(key == 'a')
	{
		packmanposx-=10;




	}

		if(key == 'd')
	{
		packmanposx+=10;

	}
			if(key == 'w')
	{
		packmanposy+=10;

	}
				if(key == 's')
	{
		packmanposy-=10;

	}

		if(key==' ')
		{


		}

	//place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{

	if(key==GLUT_KEY_RIGHT){
		//packmanposx+=7;


	right = true;
	left = false;
	up = false;
	down = false;

	//GHOST
    ghostright=true;
    ghostleft=true;
    ghostup=true;
    ghostdown=true;




	}

	if(key==GLUT_KEY_LEFT){


		//packmanposx-=7;
		right = false;
	left = true;
	up =false;
	down = false;

	}
	if(key==GLUT_KEY_UP){
		//packmanposy+=7;
		up = true;
	down = false;
	right = false;
	left = false;
	}

	if(key==GLUT_KEY_DOWN){
		//packmanposy-=7;
		up= false;
	down= true;
	right = false;
	left = false;



	}


	if (key == GLUT_KEY_END)
	{

		exit(0);
	}
	//place your codes for other keys here
}

//COLLISON BY SADIQ

//COLLISON BY SADIQ

void change(){
	//PACMAN MOVE BY TIMER




	if(right){
		packmanposx+=packmanspeed;




			 if (packmanposy>=83 && packmanposy<=160 && packmanposx>=340 && packmanposx<=380)
			packmanposx=340;

		else if (packmanposy>=83 && packmanposy<=160 && packmanposx>=65 && packmanposx<=97)
			packmanposx=65;



		else if (packmanposy>=188 && packmanposy<=257 && packmanposx>=110 && packmanposx<=148)
			packmanposx=110;

				else if (packmanposy>=188 && packmanposy<=257 && packmanposx>=295 && packmanposx<=335)
			packmanposx=295;

		else if (packmanposy>=282 && packmanposy<=390 && packmanposx>=295 && packmanposx<=335)
			packmanposx=295;


		else if (packmanposy>=282 && packmanposy<=390 && packmanposx>=110 && packmanposx<=149)
			packmanposx=110;




		else if( packmanposx>=70 && packmanposx<=96 && packmanposy>=190 && packmanposy<=447)
			packmanposx=70;

		else if( packmanposx>=355 && packmanposx<=380 && packmanposy>=190 && packmanposy<=447)
			packmanposx=355;


		else if (packmanposy>=234 && packmanposy<=300 && packmanposx>=150 && packmanposx<=287)
			packmanposx=150;


	}

		if(packmanposx>=390 ){

		packmanposx=390;
	}






	if(left){
		packmanposx-=packmanspeed;




		if (packmanposy>=83 && packmanposy<=160 && packmanposx>=340 && packmanposx<=380)
			packmanposx=380;

		else if (packmanposy>=83 && packmanposy<=160 && packmanposx>=65 && packmanposx<=97)
			packmanposx=97;



		else if (packmanposy>=188 && packmanposy<=257 && packmanposx>=110 && packmanposx<=148)
			packmanposx=148;

				else if (packmanposy>=188 && packmanposy<=257 && packmanposx>=295 && packmanposx<=335)
			packmanposx=335;

		else if (packmanposy>=282 && packmanposy<=390 && packmanposx>=295 && packmanposx<=335)
			packmanposx=335;


		else if (packmanposy>=282 && packmanposy<=390 && packmanposx>=110 && packmanposx<=149)
			packmanposx=149;




		else if( packmanposx>=70 && packmanposx<=96 && packmanposy>=190 && packmanposy<=447)
			packmanposx=96;

		else if( packmanposx>=355 && packmanposx<=380 && packmanposy>=190 && packmanposy<=447)
			packmanposx=380;




		else if (packmanposy>=234 && packmanposy<=300 && packmanposx>=166 && packmanposx<=287)
			packmanposx=287;




	}

	if(packmanposx<=54 ){

		packmanposx=54;
	}


	if(up){
		packmanposy+=packmanspeed;


		if( packmanposx>=160 && packmanposx<=285 && packmanposy>=170 && packmanposy<=200 )

		 packmanposy=170;

		else if( packmanposx>=160 && packmanposx<=285 && packmanposy>=370 && packmanposy<=393)
			packmanposy=370;


		else if(packmanposx>=163 && packmanposx<=293 && packmanposy>=88 && packmanposy<=118)
			packmanposy=88;



		else if( packmanposy>=35 && packmanposy<=68 && packmanposx>=260 && packmanposx<=380 )
			packmanposy=35;


		else if ( packmanposy>=35 && packmanposy<=68 && packmanposx>=74 && packmanposx<=194)
			packmanposy=35;


		else if (packmanposy>=128 && packmanposy<=156 && packmanposx>=115 && packmanposx<=190)
			packmanposy=128;

		else if (packmanposy>=128 && packmanposy<=156 && packmanposx>=267 && packmanposx<=330)
			packmanposy=128;




		else if( packmanposx>=160 && packmanposx<=280 && packmanposy>=220 && packmanposy<=300)
			packmanposy=220;



		//else if( packmanposx>=250 && packmanposx<=323 && packmanposy>=420 && packmanposy<=457)
			//packmanposy=420;

		else if( packmanposx>=110 && packmanposx<=177 && packmanposy>=420 && packmanposy<=457)
			packmanposy=420;

		else if( packmanposx>=66 && packmanposx<=100 && packmanposy>=420 && packmanposy<=457)
			packmanposy=420;









	}
		if(packmanposy>=473  )

		packmanposy=473;







	if(down){
		packmanposy-=packmanspeed;


		if( packmanposx>=160 && packmanposx<=285 && packmanposy>=170 && packmanposy<=200 )

		 packmanposy=200;

		else if( packmanposx>=160 && packmanposx<=285 && packmanposy>=370 && packmanposy<=393)
			packmanposy=393;



		else if(packmanposx>=163 && packmanposx<=293 && packmanposy>=88 && packmanposy<=118)
			packmanposy=118;



		else if( packmanposy>=35 && packmanposy<=68 && packmanposx>=260 && packmanposx<=380 )
			packmanposy=68;


		else if ( packmanposy>=35 && packmanposy<=68 && packmanposx>=74 && packmanposx<=194)
			packmanposy=68;




		else if (packmanposy>=128 && packmanposy<=156 && packmanposx>=115 && packmanposx<=190)
			packmanposy=156;

		else if (packmanposy>=128 && packmanposy<=156 && packmanposx>=267 && packmanposx<=330)
			packmanposy=156;



		else if( packmanposx>=250 && packmanposx<=323 && packmanposy>=420 && packmanposy<=457)
			packmanposy=457;

	else if( packmanposx>=110 && packmanposx<=177 && packmanposy>=420 && packmanposy<=457)
			packmanposy=457;

		else if( packmanposx>=66 && packmanposx<=100 && packmanposy>=420 && packmanposy<=457)
			packmanposy=457;


		else if (packmanposy>=234 && packmanposy<=300 && packmanposx>=150 && packmanposx<=287)
			packmanposy=300;




	}
		if(packmanposy<=25 )

		packmanposy=25;







		// PACMAN AND GHOST COLLISION


		
		if(ghost2posx>=packmanposx && ghost2posx<=packmanposx+pacmanwidth && ghost2posy>=packmanposy && ghost2posy<=packmanposy+pacmanheight)
			menu=2;
		else if(ghost1posx>=packmanposx && ghost1posx<=packmanposx+pacmanwidth && ghost1posy>=packmanposy && ghost1posy<=packmanposy+pacmanheight)
menu=2;

		else if(ghost3posx>=packmanposx && ghost3posx<=packmanposx+pacmanwidth && ghost3posy>=packmanposy && ghost3posy<=packmanposy+pacmanheight)
menu=2;









}


// GHOST MOVE BY TIMER





void changeghost1(){




//BLUE GHOST 1


	ghost1posy+=ghostspeed;


	if(ghost1posy>=465){
		ghost1posy=465;
	ghostspeed=4;
	//ghost1posy+=ghostspeed;
	ghost1posx+=ghostspeed;
	//printf("RIGHT\n");

	}



	if(ghost1posx>=390){
	ghost1posx=390;
	ghostspeed=-4;
	//ghost1posy+=ghostspeed;
	//printf("DOWN\n");

	}


	if(ghost1posy<=20)
	{

	ghost1posy=20;
	ghostspeed=-4;
	ghost1posx+=ghostspeed;
	//printf("LEFT\n");


	}



	if(ghost1posx<=50){

	ghost1posx=50;
	ghostspeed=4;
	//printf("AGAIN UP\n");

	}


//RED GHOST3

	ghost3posy+=ghost3speed;



	if(ghost3posy>=400){
		ghost3posy=400;
	ghost3speed=3;
	//ghost1posy+=ghostspeed;
	ghost3posx+=ghost3speed;
	//printf("RIGHT\n");

	}


	if(ghost3posx>=340){
	ghost3posx=340;
	ghost3speed=-3;
	//ghost1posy+=ghostspeed;
	//printf("DOWN\n");

	}



	if(ghost3posy<=70)
	{

	ghost3posy=70;
	ghost3speed=-3;
	ghost3posx+=ghost3speed;
	//printf("LEFT\n");


	}



	if(ghost3posx<=100){

	ghost3posx=100;
	ghost3speed=3;
	//printf("AGAIN UP\n");

	}



	//ORANGE GHOST 2

ghost2posy+=ghost2speed;



	if(ghost2posy>=345){
		ghost2posy=345;
	ghost2speed=2;
	//ghost1posy+=ghostspeed;
	ghost2posx+=ghost2speed;
	//printf("RIGHT\n");

	}


	if(ghost2posx>=290){
	ghost2posx=290;
	ghost2speed=-2;
	//ghost1posy+=ghostspeed;
	//printf("DOWN\n");

	}



	if(ghost2posy<=165)
	{

	ghost2posy=165;
	ghost2speed=-2;
	ghost2posx+=ghost2speed;
	//printf("LEFT\n");


	}



	if(ghost2posx<=145){

	ghost2posx=145;
	ghost2speed=2;
	//printf("AGAIN UP\n");

	}








		 }












int main()


    {
		memset(show,true,sizeof(show));
		memset(show1,true,sizeof(show1));
		memset(show2,true,sizeof(show2));
		strctghost1.setlocation();
		strctghost2.setlocation();
		strctghost3.setlocation();

	//place your own initialization codes here.

	iSetTimer(2 ,change);
	iSetTimer(6,changeghost1);

	iInitialize(screenwidth,screenheigth, "SADIQ");

	
	maze = iLoadImage("images\\maze96.png");
	pacman=iLoadImage("images\\newpacman.png");
	pacmanrotateleft=iLoadImage("images\\newpacmanrotateleft.png");
	pacmanrotateup=iLoadImage("images\\newpacmanrotateup.png");
	pacmanrotatedown=iLoadImage("images\\newpacmanrotatedown.png");
	
	gameover=iLoadImage("images\\gameOver3.png");
	created=iLoadImage("images\\created.png");
	
	iStart(); // it will start drawing

	return 0;

}

