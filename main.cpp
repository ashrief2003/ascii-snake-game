#include<cstdio.h>
#include<conio.h>
#include<thread>
#include<chrono>

//randomness limits
int xRg = 15 - 1 + 1;
int yRg = 40 - 1 + 1;

//game score
int score;

char button;

//screens view [x] and [y]
char al[15] [40];
class apple{
    public:
    int x, y;
    const char Shape = 'C';



};

class snake{
    public:

    const char body = '$';
    int x, y;
    char dir; //N north S south W west E east
    int bdycount;


};

apple Apple;
snake Snake;


//check if snake passed on the apple
bool eaten(){

    return (Snake.x == Apple.x) && (Snake.y == Apple.y);
}

//adding values based on the direction facing
char directions()
{ 
    switch(Snake.dir){
        case 'N':
            (Snake.x == 0)? Snake.x = 15 : --Snake.x;
        break;
        case 'S':
            (Snake.x == 15)? Snake.x = 0 : ++Snake.x;
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

int placingApple(int x, int y){

    al[x] [y] = Apple.Shape;
    return 0;
}


//printing the screen
int pr(){
    for(int i = 0; i < 15; ++i)
    {
        for(int t = 0; t < 40; ++t)
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
            if(Snake.dir != 'S') Snake.dir = 'N';
        break;
        case 'S':
            if(Snake.dir != 'N') Snake.dir = 'S';
        break;
        case 'D':
            if(Snake.dir != 'W') Snake.dir = 'E';
        break;
        case 'A':
            if(Snake.dir != 'E') Snake.dir = 'W';
        break;

        default:
        break;
    }
}

//mere debugging line
void debug(){
    printf("Button : %c |", button);
    printf(" x = %d | y = %d", Snake.x, Snake.y);
    printf(" | SCORE : %d", score);
}

void AppleRandomPosition(){

    ++score;
    Apple.x = rand() % xRg;
    Apple.y = rand() % yRg;
}

int main(){

    //set the snake axis before starting the program loop
    Snake.x = 1;
    Snake.y = 1;

    Apple.x = 6;
    Apple.y = 6;

    while(1){


        if (kbhit()) {
            button = getch(); 
        }

        //checks whatever button you pressed to increase which one of the vectors position to increase
        controls();
        system("cls");

        //set marks on every sym of console like screen
        for(int i = 0; i < 15; ++i)
        {
            for(int t = 0; t < 40; ++t)
            {
                al[i] [t] = '0';
            }
        }

        //set our sym
        placingSnake(Snake.x, Snake.y);
        placingApple(Apple.x, Apple.y);
        directions();
    

        //print results on screen
        
        pr();

        
        //debbug some values to see them
        debug();

        (eaten() == true)? AppleRandomPosition():

        //some delay
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        //std::cout << button;
        button = ' ';
  
    }

    
    
    return 0;
}
