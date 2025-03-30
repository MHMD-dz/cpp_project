#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>

using namespace std ; 

struct Sclient{
    string name ;
    string pin ;
    string ac_number ;
    string phone ;
    string balance ;
};




void showClient(vector <Sclient> hello){   
    cout << "_______________________________________________________________________________________________________________" << endl ;
    cout << "|" << setw(20) << left << " ACCOUNT NUMBER " << "|" << setw(15) << left << " PINE CODE " << "|" << setw(30) << left <<
    " CLIENT NAME " << "|" << setw(20) << left << " CLIENT PHONE " << "|"
    << setw(20) << left << " ACCOUNT BALANCE " << "|" << endl ;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl ;
    for (int i = 0; i < hello.size(); i++)
    {
        cout << "|" << setw(20) << left << hello[i].ac_number << "|" << setw(15) << left << hello[i].pin << "|" << setw(30) << left <<
        hello[i].name << "|" << setw(20) << left << hello[i].phone << "|"
        << setw(17) << left << hello[i].balance <<"DA |" << endl ;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl ;
    }
    
}

void output(){
    vector <Sclient> vclient ;
    int number ;
    cout << "=============================================" << endl ;
    cout << "               MAIN MENUE SCREEN    " << endl ;
    cout << "=============================================" << endl ;
    cout << "[1] show client list " << endl ;
    cout << "[2] add client" << endl ;
    cout << "[3] delet client" << endl ;
    cout << "[4] update client info " << endl ;
    cout << "[5] find client" << endl ;
    cout << "[6] exit " << endl ;
    cout << "=============================================" << endl ;
    cout << "enter the number of the operation you whant to do: [1 to 6]: " ;
    cin >> number ;
    switch (number)
    {
    case 1 :
        showClient(vclient) ;
        break;
    
    default:
        break;
    }


}

int main (){
    output();
}