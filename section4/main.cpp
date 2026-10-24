#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {

    int n;
    cout << "How many persons? ";
    cin >> n;
    cin.ignore();

    ofstream outFile("persons.txt");
    for (int i = 0; i < n; i++) {
        Person p;
        cout << "Enter name: ";
        getline(cin, p.name);
        cout << "Enter age: ";
        cin >> p.age;
        cin.ignore();

        outFile << p.name << endl;
        outFile << p.age << endl;
    }
    outFile.close();


    vector<Person> people;
    ifstream inFile("persons.txt");
    Person p;
    while (getline(inFile, p.name)) {
        inFile >> p.age;
        inFile.ignore();
        people.push_back(p);
    }
    inFile.close();

    if (people.empty()) {
        cout << "No data found in file." << endl;
        return 0;
    }

    int youngest = 0, oldest = 0;
    for (int i = 1; i < people.size(); i++) {
        if (people[i].age < people[youngest].age) youngest = i;
        if (people[i].age > people[oldest].age) oldest = i;
    }

    ofstream resFile("results.txt");
    resFile << "Youngest: " << people[youngest].name << " - " << people[youngest].age << endl;
    resFile << "Oldest: " << people[oldest].name << " - " << people[oldest].age << endl;
    resFile.close();

    cout << "Results saved in results.txt" << endl;
    return 0;
}