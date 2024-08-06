#include <iostream>
#include <fstream> 
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main() {
    json data1;
    string name;
    int age;
    string street, city;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter street: ";
    cin >> street;
    cout << "Enter city: ";
    cin >> city;

    json address;
    address["street"] = street;
    address["city"] = city;


    data1["name"] = name;
    data1["age"] = age;
    data1["address"] = address;

    ofstream jsonFile("file4.json");

    jsonFile << data1.dump(4);
    return 0;
}
