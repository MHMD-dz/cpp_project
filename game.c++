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
    if ( player == rock && pc == scisser || player == paper && pc == rock || player == scisser && pc == paper)
    {
        return 1 ;}
    else if ( pc == rock && player == scisser || pc == paper && player == rock || pc == scisser && player == paper)
    {
        return -1 ;}
    else  if ( pc == rock && player == rock || pc == paper && player == paper || pc == scisser && player == scisser)
    {
        return 0 ;}
}

void show_winner(int number){
    if (number > 0)
    {
        cout << "the player win this rounde \a" << endl ;
        system("color 2F");
    }
    else if (number < 0)
    {
        cout << "the pc win this rounde \a" << endl ;
        system("color 4E");
    }
    else if (number == 0)
    {
        cout << "this round wase a tie \a" << endl ;
        system("color 6C");
    }
    
}

int get_number(string message){
    int number ;
    cout << message ;
    cin >> number ;
    return number;
}



int main(){
    srand(time(0));
    show_winner(who_win(get_choise("what is yor choise \"(1) for rock , (2) for paper , (3) for scisser \": "),pc_choise()));
    show_winner(who_win(get_choise("what is yor choise \"(1) for rock , (2) for paper , (3) for scisser \": "),pc_choise()));
    show_winner(who_win(get_choise("what is yor choise \"(1) for rock , (2) for paper , (3) for scisser \": "),pc_choise()));
    show_winner(who_win(get_choise("what is yor choise \"(1) for rock , (2) for paper , (3) for scisser \": "),pc_choise()));
}