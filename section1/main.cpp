#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream file ;
    file.open("Student.txt");
    cout<< "insert name : " ;
    string name ;
    getline(cin,name);
    int id ,grade ;
    cout<<"insert id and grade " ;
    cin>>id>>grade ;
    file <<"name : " << name << " \n id : " << id << "\n grade : " <<grade ;
    file.close() ;
return 0;
}