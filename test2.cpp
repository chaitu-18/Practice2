#include<iostream>
#include<fstream>
#include <nlohmann/json.hpp>

using namespace std;

using json=nlohmann::json;

int main(){
    ifstream jsonFile("file1.json");

    json jsonData;
    jsonFile >> jsonData;

    string Name=jsonData["Name"];
    int Age=jsonData["Age"];
    vector<string>Numbers=jsonData["Numbers"];

    cout<<"Name: "<<Name<<endl;
    cout<<"Age: "<<Age<<endl;
    cout<<"Numbers: ";
    for(const auto& i:Numbers){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}

