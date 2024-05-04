#include<stdio.h>
#include<string>
#include<conio.h>
#include<thread>
#include<chrono>



char button;

//screens view [x] and [y]
char al[35] [80];


class snake{
    public:

    char body = '$';
    int x, y;
    char dir; //N north S south W west E east
    int bdycount;


};

snake Snake;


char directions()//adding values based on the direction facing
{ 
    switch(Snake.dir){
        case 'N':
            (Snake.x == 0)? Snake.x = 35 : --Snake.x;
        break;
        case 'S':
            (Snake.x == 35)? Snake.x = 0 : ++Snake.x;
        break;
        case 'E':
            ++Snake.y;
        break;
        case 'W':
            --Snake.y;
        break;

        default:
        break;
    }

    return 'O';

}

//setting the position
int placingSnake(int x, int y){

    al[x] [y] = Snake.body;
    return 0;
}


//printing the screen
int pr(){
    for(int i = 0; i < 35; ++i)
    {
        for(int t = 0; t < 80; ++t)
        {
            printf("%c", al[i] [t]);
        }
        printf("\n");
    }
    return 0;
}

//The Game Directions Control
void controls(){
    switch(button){
        case 'W':
            Snake.dir = 'N';
        break;
        case 'S':
            Snake.dir = 'S';
        break;
        case 'D':
            Snake.dir = 'E';
        break;
        case 'A':
            Snake.dir = 'W';
        break;

        default:
        break;
    }
}

//mere debugging line
void debug(){
    printf("Button : %c |", button);
    printf(" x = %d | y = %d", Snake.x, Snake.y);
}

int main(){

    //set the snake axis before starting the program loop
    Snake.x = 1;
    Snake.y = 1;

    while(1){
        if (kbhit()) {
            button = getch(); 
        }
        //checks whatever button you pressed to increase which one of the vectors position to increase
        controls();
        system("cls");

        //set marks on every sym of console like screen
        for(int i = 0; i < 35; ++i)
        {
            for(int t = 0; t < 80; ++t)
            {
                al[i] [t] = '0';
            }
        }

        //set our sym
        placingSnake(Snake.x, Snake.y);
        directions();

        //print results on screen
        pr();
        
        //debbug some values to see them
        debug();

        //some delay
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        //std::cout << button;
        button = ' ';
    
    }
    
    return 0;
}