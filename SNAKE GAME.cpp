#include<iostream>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;
enum dir{top=1,down,Right,Left};
struct map
{
	int widht, height, snakex, snakey;
};
struct snake
{
	int headx, heady,len_n,len_x[50],len_y[50];
	dir d1;
};
struct player 
{
	int score;
	bool lose;
};
map m1;
snake s1;
player p1;
void loction_snake()
{
	srand(time(NULL));
	m1.snakex=rand() % (m1.widht-2)+1;
	m1.snakey=rand() % (m1.height-2)+1;
}
void setting()
{
	m1.widht=40;
	m1.height=20;
	loction_snake();
	s1.headx=m1.widht/2;
	s1.heady=m1.height/2;
	s1.len_n=0;
	p1.score=0;
	p1.lose=false;
}
void shift_right(int arr[],int s);
void draw()
{
	bool printed;	
	system("cls");
	for(int i=0;i<m1.height;i++)
	{
		for(int j=0;j<m1.widht;j++)
		{
			if(i==0 || i==m1.height-1)cout<<"#";
			else if(j==0 || j==m1.widht-1)cout<<"#";
			else if(i==s1.heady && j==s1.headx)cout<<"SH";
			else if(i==m1.snakey && j==m1.snakex)cout<<"*";
			else {
			bool printed=false;
			for(int a=0;a<s1.len_n;a++){
			if(s1.len_x[a]==j && s1.len_y[a]==i){
			cout<<"*";
			printed=true;
			break;
		}
	}
		if(!printed)
		cout<<" ";
			}
		}
		cout<<"\n";
	}
	cout<<"Player score is :"<<p1.score<<endl;
}
void in_put()
{
	if(_kbhit())
	{
		char c=_getch();
		switch (c)
		{
			case 't': s1.d1=top;
			break;
			case 'd': s1.d1=down;
			break;
			case 'r': s1.d1= Right;
			break;
			case 'l': s1.d1= Left;
			break;
			case 'x': exit(0);
			break;
		}
	}
}
void shift_right(int arr[],int s);
void move()
{
	shift_right(s1.len_x,50);
	shift_right(s1.len_y,50);
	s1.len_x[0]=s1.headx;
	s1.len_y[0]=s1.heady;
	switch (s1.d1)
	{
		case top: s1.heady--;
		break;
		case down: s1.heady++;
		break;
		case Right: s1.headx++;
		break;
		case Left: s1.headx--;
		break;	
	}
	if(s1.heady>=m1.height || s1.heady<=0 || s1.headx>=m1.widht || s1.headx<=0){
	p1.lose=true;
	cout<<"Game Over..... *_* ";
	}
	if(s1.headx==m1.snakex && s1.heady==m1.snakey)
	{
		loction_snake();
		p1.score +=1;
		s1.len_n ++;	
	}
}
void shift_right(int arr[],int s)
{
	for(int i= s-2 ; i>=0 ; i--)
	arr[i+1]=arr[i];
}
int main()
{
	setting();
	cout<<"WLECOME TO MY GAME\n \n SNAKE GAME...\n\n ";
	cout<<"Use The char 'T' To Move TO TOP\n Use The char 'D' To Move TO DOWN\n Use The char 'R' To Move TO RIGHT\n Use The char 'L' To Move TO LEFT \n Use The char 'X' To EXIT \n ";
	cout<<" \n Enter anything to start play :  \n ";
			getche();
	while (!p1.lose)
	{
		draw();
		in_put();
		move();
		Sleep(10);
	//	getche();	
	};
		cout<<"\nThanks for using my game ... Eng:Shaima Riyadh ... :) \n";
		
			getche();
	return 0;
}
