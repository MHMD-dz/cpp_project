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

vector <string> lineTOvect(string line){
    short pos = 0 ;
    string sWord = "" ;
    string Delim = "#//#" ; 
    vector <string> vString ;
    while ((pos = line.find(Delim)) != string::npos){
        sWord = line.substr(0, pos); 
            if (sWord != ""){
                vString.push_back(sWord);
            }
        line.erase(0, pos + Delim.length());
    }
    if (line != ""){
        vString.push_back(line); 
    }
    return vString ;
}

Sclient lineTOstruct( string line ){
    vector <string> str ;
    Sclient client ;
    str = lineTOvect(line);
    client.ac_number = str[0] ;
    client.pin = str[1] ;
    client.name = str[2] ;
    client.phone = str[3] ;
    client.balance = str[4] ;
    return client ;
}

vector <Sclient> fileExtracter( string filename){
    ifstream file(filename) ;
    string line ;
    vector <Sclient> bank_info ;
    while (getline(file,line)){
        bank_info.push_back(lineTOstruct(line));
    }
    return bank_info ;
}


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

Sclient fill_struct(){
    Sclient client ;
    cout << "Enter the acount number: " ;
    cin >> client.ac_number ;
    cout << "Enter the acount pine: " ;
    cin >> client.pin ;
    cin.ignore();
    cout << "Enter the name: " ;
    getline(cin,client.name);
    cout << "Enter the phone number: " ;
    cin >> client.phone ;
    cout << "Enter the acount balance: " ;
    cin >> client.balance ;
    return client ;
}

void writ_info_toFile(Sclient client){
    ofstream file("bank_info/database.txt" , ios::app) ;
    if (file)
    {
        file << client.ac_number << "#//#" << client.pin << "#//#" << client.name << "#//#" << client.phone << "#//#" << client.balance << endl;
    }else{
        cout << "ERROR in reading the file " << endl ;
    }
    
}

void output(){
    vector <Sclient> vclient ;
    int number ;
    do
    {
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
        showClient(fileExtracter("bank_info/database.txt")) ;
        break;
    case 2 : 
        writ_info_toFile(fill_struct());
        break;
    case 6 : 
        return;
        break;
    
    default:
    cout << "ERROR enter a valide number !" << endl ;
        break;
    }
    cin.ignore();
    cout << "press ENTER to continue .... " ;
    cin.get();
    }  while (number != 6);
    
}

int main (){
    output();
}