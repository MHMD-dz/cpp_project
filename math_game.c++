#include<iostream>
using namespace std ;

int points = 0;
enum operation { pl_us = 1 , subtract , multiply , division };
enum hardness { easy , medium , hard , so_hard } ;

struct math_game{
    int first_number ;
    int second_number ;
    operation op ;
    hardness level ;
    int answer ;
};

int get_number(string message){
    int number ;
    cout << message ;
    cin >> number ;
    return number ;
}

int random_number( int from , int to){
    int random ;
    random = (rand() % (to - from + 1) + from ) ;
    return random ;
}

void level_of_game ( math_game &math , int number ){
    if (number == 5 )
    {
        number = random_number(1,4) ;
    }
    

    switch (number) {
        case 1: math.level = easy; break;
        case 2: math.level = medium; break;
        case 3: math.level = hard; break;
        case 4: math.level = so_hard; break;
        default: math.level = easy;
    }
}

void game_op (math_game &math , int number ){
    if (number == 5 )
    {
     number = random_number(1,4) ;
    }
    switch (number) {
        case 1: math.op = pl_us; break;
        case 2: math.op = subtract; break;
        case 3: math.op = multiply; break;
        case 4: math.op = division; break;
        default: math.op = pl_us;
    }
}

void game_numb( math_game &math ){
    switch (math.level)
    {
        case easy :
        math.first_number = random_number(1,10) ;
        math.second_number = random_number(1,10) ;
        break;
        case medium :
        math.first_number = random_number(10,100) ;
        math.second_number = random_number(10,100) ;
        break;
        case hard :
        math.first_number = random_number(100,1000) ;
        math.second_number = random_number(100,1000) ;
        break;
        case so_hard :
        math.first_number = random_number(1000,10000) ;
        math.second_number = random_number(1000,10000) ;
        break;
    default:
        break;
    }

}

char op_char (math_game &math){

        switch (math.op)
        {
            case pl_us :
            return '+' ;
            case subtract :
            return '-';
            case multiply :
            return '*'  ;
            case division :
            return '/' ;
        
        default:
            return '+' ;
        }
}

bool checking (math_game &math){
    int number ;
    switch (math.op)
    {
        case pl_us :
        number = math.first_number + math.second_number ;
        break;
        case subtract :
        number = math.first_number - math.second_number ;
        break;
        case multiply :
        number = math.first_number * math.second_number ;
        break;
        case division :
        number = math.first_number / math.second_number ;
        break;
    
    default:
        number = math.first_number + math.second_number ;
    }
    if (number == math.answer)
    {
        return true ;
    }
    return false ;
}

void gamee(math_game &math){
    char op ;
    op = op_char(math) ;
    cout << "\t" <<  math.first_number << endl ;
    cout << " " << op << endl ;
    cout << "\t" <<  math.second_number<< endl ;
    cout << "_________________" << endl ;
    cin >> math.answer ;
    if (checking(math))
    {
        cout << "NICE YOU ARE RIGHT :-)" << endl ;
        system("color 2F");
        points ++ ;
    }
    else
    {
        cout << "NO YOU ARE WRONG :-(" << endl ;
        system("color 4E");
    }
    

}

void start_game(math_game &game){
    int question , i , lvl_number , op_number ;
    
    
    question = get_number("Enter the number of question you want: ");
    cout << "How hard you want the game to be : [1] Easy  , [2] mediom , [3] hard , [4] so hard , [5] mix : " ;
    cin >> lvl_number ;
    cout << "What operation you want  the question to by: [1] plus , [2] subtract , [3] multiply , [4] division , [5] random : " ;
    cin >> op_number ;
    level_of_game(game , lvl_number) ;
    game_op(game, op_number ) ;
    
    for ( i = 1 ; i <= question; i++)
    {
        if (lvl_number == 5 )
        {
            level_of_game(game , lvl_number) ;
        }
        if (op_number == 5)
        {
            game_op(game, op_number ) ;
        }
        
        
        game_numb(game) ;
        cout << "Question [" << i << "\\" << question << "] : " << endl ;
        gamee(game) ;
    }
    
    
} 


int main(){
    srand(time(0));
    math_game games ;
    start_game(games);
    return 0 ;
}