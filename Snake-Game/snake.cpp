#include <iostream>
#include <conio.h>
using namespace std;

bool gameover;
const int width = 50, height = 20;
int x, y, fruitX, fruitY, score;
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

    for(int i=0; i<width;i++){
        cout<<"#";
    }
    cout<<endl;

    for(int i=0; i<height;i++){
        for(int j=0; j<width;j++){
            if(j==0 || j== (width-1))
                cout<<"#";
            
            if(i==y && j==x)
                cout<<"O";
            else if (i == fruitY && j == fruitX)
                cout<<"F";
            else
            {
                    cout<<" ";
            }
        }
        cout<<endl;
    }

    for(int i=0; i<width;i++){
        cout<<"#";
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
    if(x > width-1 || x < 0 || y > height || y<0){
        gameover = true;
    }
    if(x == fruitX && y == fruitY){
        score += 10;
        //fruit on a new position    
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main(){
    setup();
    while(!gameover){
        draw();
        input();
        logic();
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t GAME OVER";
    cin.get();
    
    return 0;
}
