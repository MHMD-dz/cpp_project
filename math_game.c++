#include<iostream>
using namespace std ;

enum operation { pluus = 1 , subtract , multiplay , division };
enum hardness { easy , midiom , hard , so_hard , mix } ;

struct math_game{
    int first_number ;
    int second_number ;
    operation op ;
    hardness level ;
    int answer ;
};

int get_number(string masseg){
    int number ;
    cout << masseg ;
    cin >> number ;
    return number ;
}

int random_number( int from , int to){
    int random ;
    random = (rand() % (to - from + 1) + from ) ;
    return random ;
}

hardness level_of_game ( math_game &math ){
    int number ;
    cout << "How hard you want the game to be : [1] Easy , [2] mediom , [3] hard , [4] so hard , [5] mix : " ;
    cin >> number ;
    switch (number)
    {
        case 1 :
        return math.level = easy ;
        case 2 :
        return math.level = midiom ;
        case 3 :
        return math.level = hard ;
        case 4 :
        return math.level = so_hard;
        case 5 :
        return math.level = mix ;
    default:
        break;
    }
    return math.level = easy ;
}

operation game_op (math_game &math ){
    int number ;
    number = random_number(1,4) ;
    switch (number)
    {
        case 1 :
        return math.op = pluus ;
        case 2 :
        return math.op = subtract ;
        case 3 :
        return math.op = multiplay ;
        case 4 :
        return math.op = division ;
    
    default:
        return math.op = pluus ;
    }
}

void game_numb( math_game &math ){
    math.level = level_of_game(math);
    switch (math.level)
    {
        case easy :
        math.first_number = random_number(1,10) ;
        math.second_number = random_number(1,10) ;
        case midiom :
        math.first_number = random_number(10,100) ;
        math.second_number = random_number(10,100) ;
        case hard :
        math.first_number = random_number(100,1000) ;
        math.second_number = random_number(100,1000) ;
        case so_hard :
        math.first_number = random_number(1000,00010000) ;
        math.second_number = random_number(1000,10000) ;
    default:
        break;
    }

}

char op_char (math_game &math){

        switch (math.op)
        {
            case pluus :
            return '+' ;
            case subtract :
            return '-';
            case multiplay :
            return '*'  ;
            case division :
            return '/' ;
        
        default:
            return '+' ;
        }
}

bool chacking (math_game &math){
    int number ;
    switch (math.op)
    {
        case pluus :
        number = math.first_number + math.second_number ;
        case subtract :
        number = math.first_number - math.second_number ;
        case multiplay :
        number = math.first_number * math.second_number ;
        case division :
        number = math.first_number / math.second_number ;
    
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
    if (chacking(math))
    {
        cout << "NICE YOU ARE RIGHT" << endl ;
        system("color 2F");}
    else
    {
        cout << "NO YOU ARE WRONG" << endl ;
        system("color 4E");
    }
    

}

void start_game(math_game &game){
    int quastion ;
    quastion = get_number("Enter the number of quastion you want: ");
    level_of_game(game) ;
    game_op(game) ;
    game_numb(game) ;
    op_char(game) ;
    gamee(game) ;
}


int main(){
    srand(time(0));
    math_game games ;
    start_game(games);
}