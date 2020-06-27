#include <iostream>
#include <conio.h>
//sleep function
#include <Windows.h>
using namespace std;

bool gameover;
const int width = 30, height = 30;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int ntail = 0;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup(){

    gameover = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw(){
    system("cls");  //system("clear") for linux

    cout<<"\t\tScore = "<<score<<"\n\n\n";

    for(int i=0; i<width+2;i++){
        cout<<"=";
    }
    cout<<endl;

    for(int i=0; i<height;i++){
        for(int j=0; j<=width;j++){
            if(j==0 || j== (width))
                cout<<"#";
            
            if(i==y && j==x)
                cout<<"O";
            else if (i == fruitY && j == fruitX)
                cout<<"F";
            else{
                bool print = false;
                for(int k=0; k<ntail; k++){
                    if(tailX[k] == j && tailY[k] == i){
                        cout<<"o";
                        print= true;
                    }
                }
                if(!print)
                    cout<<" ";
            }
        }
        cout<<endl;
    }

    for(int i=0; i<width+2;i++){
        cout<<"=";
    }
    cout<<endl;
}

void input(){
    if(_kbhit()){
        switch (_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'w':
                dir = UP;
                break;
            case 'd':
                dir = RIGHT;
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

    int prevX = tailX[0], prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i=1; i<ntail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir){

        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
        case UP:
            y--;
            break;
        default:
            break;
    }
    
    //not go through walls
    if(x > width || x < 0 || y > height || y<0){
        //gameover = true;
    }
    
    //go through walls
    if(x>width) 
        x=0;
    else if(x < 0)
        x= width-1;

    if(y>height) 
        y=0;
    else if(y < 0)
        y= height-1;


    for(int i=0; i<ntail; i++){
        if(tailX[i]==x && tailY[i]==y)
            gameover=true;
    }
    if(x == fruitX && y == fruitY){
        score += 10;
        //fruit on a new position    
        fruitX = rand() % width;
        fruitY = rand() % height;
        ntail++;
    }
}

int main(){
    setup();
    while(!gameover){
        draw();
        input();
        logic();
        //Sleep(10);  //can be used to adjust difficulty level
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t GAME OVER\n\n\t\t\tScore = "<<score<<"\n\n\n\t\t\t>>Press Enter to Exit";
    cin.get();
        
    return 0;
}
