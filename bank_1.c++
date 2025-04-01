#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<vector>
#include <cctype>

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
    cout << "                                CLIENT LIST : (" << hello.size() << ") client(s) " << endl ;
    cout << "_______________________________________________________________________________________________________________" << endl ;
    cout << "|" << setw(20) << left << " ACCOUNT NUMBER " << "|" << setw(15) << left << " PINE CODE " 
    << "|" << setw(30) << left <<" CLIENT NAME " << "|" << setw(20) << left << " CLIENT PHONE " << "|"
    << setw(20) << left << " ACCOUNT BALANCE " << "|" << endl ;
    cout << "---------------------------------------------------------------------------------------------------------------" << endl ;
    for (int i = 0; i < hello.size(); i++)
    {
        cout << "|" << setw(20) << left << hello[i].ac_number << "|" << setw(15) << left << hello[i].pin 
        << "|" << setw(30) << left <<
        hello[i].name << "|" << setw(20) << left << hello[i].phone << "|"
        << setw(17) << left << hello[i].balance <<"DA |" << endl ;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl ;
    }
}

Sclient fill_struct(){
    Sclient client ;

    cout << "-----------------------------------" << endl ;
    cout << "       ADD CLIENT SCREAN    " << endl ;
    cout << "-----------------------------------" << endl ;

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

void addC(Sclient client){

    ofstream file("bank_info/database.txt" , ios::app) ;
    bool more;
    char answer ;
    do{
    more = false ;
    if (file)
    {
        file << client.ac_number << "#//#" 
        << client.pin << "#//#" 
        << client.name << "#//#" 
        << client.phone << "#//#" 
        << client.balance << endl;
    }else{
        cout << "ERROR in reading the file " << endl ;
    }
    cout << "Do you whant to add more clients (y/n): " ;
    cin >> answer ;
    answer = tolower(answer);
    if (answer == 'y'){
        more = true ;
        client = fill_struct() ;
    }
    } while (more);
}

int whereExist(vector <Sclient> client , string ACN){
    for (int i = 0; i < client.size() ; i++)
    {
        if ( ACN == client[i].ac_number)
        {
            return i ;
        }
    }
    return -1 ;
} 

void deletAC(int number , vector <Sclient> client){
    char delett ;
    bool sure = false;
    ofstream file("bank_info/database.txt" , ios::app) ;
    cout << "-----------------------------------" << endl ;
    cout << "       DELETE CLIENT SCREAN    " << endl ;
    cout << "-----------------------------------" << endl ;
    if (number == -1 ){
        cout << "thi account number dosn't exist in the database !" << endl ;
        return;
    }
    cout << "the client detail : " << endl ;
    cout << "-----------------------------------" << endl ;
    cout << " client account number : " << client[number].ac_number << endl ;
    cout << " client pine number    : " << client[number].pin << endl ; 
    cout << " client name           : " << client[number].name << endl ; 
    cout << " client phone number   : " << client[number].phone << endl ; 
    cout << " client balance        : " << client[number].balance << endl;
    cout << "are you sure you whant to delet this client (y/n): " ;
    cin >> delett ;
    if (delett == 'y'){
        sure = true ;
    }
    if (sure)
    {
        ofstream file("bank_info/database.txt" , ios::out) ;
    }
    
    if (file.is_open() && sure){
    for (int i = 0; i < client.size(); i++)
    {
        if (i == number)
        {
            continue;
        }
        file << client[i].ac_number << "#//#" 
        << client[i].pin << "#//#" 
        << client[i].name << "#//#" 
        << client[i].phone << "#//#" 
        << client[i].balance << endl;
    }
    }else if(!file.is_open()){
        cout << "ERROR in reading the file " << endl ;
    }
}
void updateC(int number , vector <Sclient> client){
    cout << "-----------------------------------" << endl ;
    cout << "     UPDATE CLIENT INFO SCREAN    " << endl ;
    cout << "-----------------------------------" << endl ;
    ofstream file("bank_info/database.txt" , ios::app) ;
    Sclient updatt ;
    bool sure = false ;
    char updatte ;
    if (number == -1 ){
        cout << "thi account number dosn't exist in the database !" << endl ;
        return;
    }
    cout << "Enter the new acount pine: " ;
    updatt.ac_number = client[number].ac_number ;
    cin >> updatt.pin ;
    cin.ignore();
    cout << "Enter the new name: " ;
    getline(cin,updatt.name);
    cout << "Enter the new phone number: " ;
    cin >> updatt.phone ;
    cout << "Enter the new acount balance: " ;
    cin >> updatt.balance ;
    cout << endl << "are you sure you whant to update this client (y/n): " ;
    cin >> updatte ;
    if (updatte == 'y'){
        sure = true ;
    }
    if (sure)
    {
        ofstream file("bank_info/database.txt" , ios::out) ;
    }
    if (file.is_open() && sure){
    for (int i = 0; i < client.size(); i++)
    {
        if (i == number)
        {
            client[i] = updatt;
        }
        
        file << client[i].ac_number << "#//#" 
        << client[i].pin << "#//#" 
        << client[i].name << "#//#" 
        << client[i].phone << "#//#" 
        << client[i].balance << endl;
    }
    }else if(!file.is_open()){
        cout << "ERROR in reading the file " << endl ;
    }

}

void find_client(vector <Sclient> client){
    cout << "-----------------------------------" << endl ;
    cout << "       FIND CLIENT SCREAN    " << endl ;
    cout << "-----------------------------------" << endl ;
    string ac ;
    cout << "Enter the account number of the client ur looking for: " ;
    cin >> ac ;
    for (int i = 0; i < client.size() ; i++)
    {
        if (client[i].ac_number == ac )
        {
            cout << "the client detail : " << endl ;
            cout << "-----------------------------------" << endl ;
            cout << " client account number : " << client[i].ac_number << endl ;
            cout << " client pine number    : " << client[i].pin << endl ; 
            cout << " client name           : " << client[i].name << endl ; 
            cout << " client phone number   : " << client[i].phone << endl ; 
            cout << " client balance        : " << client[i].balance << endl;
        }
        
    }
    
}

void output(){
    vector <Sclient> vclient ;
    int number ;
    string ACN ;
    
    do
    {
    vclient = fileExtracter("bank_info/database.txt") ;
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
    cout << endl ;
    switch (number)
    {
    case 1 :
        showClient(vclient) ;
        break;
    case 2 : 
        addC(fill_struct());
        break;
    case 3 :
        cout << "enter the account number of the client you whant to delet: " ;
        cin >> ACN ;
        deletAC(whereExist(vclient,ACN),vclient);
    break;
    case 4 :
        cout << "enter the account number of the client you whant to update: " ;
        cin >> ACN ;
        updateC(whereExist(vclient,ACN),vclient);
        break;
    case 5 :
        find_client(vclient);
        break;
    case 6 : 
        cout << "-----------------------------------" << endl ;
        cout << "       GOOD BYE   " << endl ;
        cout << "-----------------------------------" << endl ;
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