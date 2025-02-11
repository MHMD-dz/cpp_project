#include<iostream>
using namespace std ;

int pc_points = 0 ;
int player_points = 0 ;

enum game { rock = 1 , paper = 2 , scisser = 3 } ;

game get_choise(string message){
    int number ;
    cout << message ;
    cin >> number ;
    if (number == 1 )
    {
        return game::rock ;}
    else if (number == 2)
    {
        return game::paper ;}
    else return game::scisser ;
    
}

int random_number(){
    int random ;
    random = (rand() % (3) + 1 ) ;
    return random ;
}

game pc_choise(){

    int number ;
    number = random_number() ;

    if (number == 1 )
    {
        return game::rock ;}
    else if (number == 2)
    {
        return game::paper ;}
    else return game::scisser ;
}

int who_win(game player , game pc ){
    if (player == pc){
        pc_points ++ ;
        player_points ++ ;
        return 0; 
    } 

    if ((player == rock && pc == scisser) || 
    (player == paper && pc == rock) || 
    (player == scisser && pc == paper)) 
{   player_points ++ ;
    return 1; 
}
    pc_points ++ ;
    return -1;
}

void show_winner(int number , int rounde ){
    cout << "               -------------------- THE ROUNDE " << rounde << " --------------------" << endl << endl;
    cout << "              player pointes : " << player_points << "   ********" << "  pc pointes " << pc_points << endl<< endl ;
    if (number > 0)
    {
        
        cout << "    the player win this rounde \a" << endl << endl ;
        system("color 2F");
        
    }
    else if (number < 0)
    {
        cout << "   the pc win this rounde \a" << endl<< endl ;
        system("color 4E");
        
    }
    else if (number == 0)
    {
        cout << "   this round wase a tie \a" << endl << endl;
        system("color 7C");
    }
    
}

int get_number(string message){
    int number ;
    cout << message ;
    cin >> number ;
    return number;
}

bool play_again(string message){
    int answer ;
    cout << message << endl ;
    cin >> answer ;
    if (answer == 1)
    {
        return true ;
    }
    return false ;
}

void start_the_game(){
    int round = 0 , i ;
    while  (round < 1 || round > 10)
    {
    round = get_number("Enter how mach rounde you want to play : ");}
    for ( i = 1; i <= round; i++)
    {
        show_winner(who_win(get_choise("what is yor choise \"(1) for rock , (2) for paper , (3) for scisser \": "),pc_choise()),i);
    }
    cout << endl << endl ;
    if ( pc_points == player_points)
        {
            cout<< " THIS GAME WAS A TIE  "  << player_points << " TO " << pc_points << endl ;
            system("color 7C");
        }
    if ( pc_points < player_points)
        {
            cout<< " THE PLAYER WON THIS GAME  " << player_points << " TO " << pc_points << endl ;
            system("color 2F");
        }
    if ( pc_points > player_points)
        {
            cout<< " THE PC WON THIS GAME  " << pc_points << " TO " << player_points << endl ;
            system("color 4E");
        }
    if (play_again("do yo want to play again  (1) for yes and (0) for no : "))
    {
        player_points = 0 ; pc_points = 0 ;
        start_the_game();
    }
    
    
}


int main(){
    srand(time(0));
    start_the_game();
}