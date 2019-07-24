#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
using namespace std;
const int width=20,height=20;
bool gameover;
int score;
int x,y,fruitX,fruitY;
enum dect{STOP=0,LEFT,RIGHT,TOP,DOWN};
dect dir;
void setup(){
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand() % width;
    fruitY=rand() % height;
    score=0;
}
void draw(){
    system("cls");
    for(int i=0 ; i <= width+1 ; i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0 ; i < height ; i++){
        for(int j=0 ; j < width ; j++){
            if(j==0){
                cout<<"#";
            }
            if(i== y && j== x){
                cout<<">";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"@";
            }
            else{
             cout<<" ";
            }
            if(j==width-1)
                cout<<"#";
        }
        cout<<endl;
    }
    for(int i=0 ; i <= width+1 ; i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"Score:"<<score<<endl;
}


void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = TOP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}

void logic(){
   switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case TOP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
   if(x > width || x<0 && y > height || y < 0)
     gameover=true;
   if(x==fruitX && y==fruitY){
    score+=5;
    fruitX=rand() % width;
    fruitY=rand() % height;
   }
}

int main(){
    setup();
    while(!gameover){
        draw();
        input();
        logic();
    }

return 0;
}
