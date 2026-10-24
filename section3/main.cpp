#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream file;
    file.open("welcome.txt",ios::out);
    file<<"Hello Everybody" ;
    file.close();
    fstream f ;
    f.open("welcome.txt",ios::in|ios::out) ;
    f.seekp(11);
    f<<"one ";
    f.close();
return 0;
}