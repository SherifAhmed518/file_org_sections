#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fruit;
    bool found = false;
    ifstream in("fruit.txt");
    while (getline(in, fruit))
    {
        cout << fruit << endl;
        if (fruit == "Fresh Fruits")
            found = true;
    }
    in.close();
    if (!found)
    {
        ofstream out("fruit.txt", ios::app);
        out << endl << "Fresh Fruits";
        out.close();
    }

    return 0;
}