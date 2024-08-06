#include<iostream>
#include<fstream>
#include<nlohmann/json.hpp>

using namespace std;
using json=nlohmann::json;

int main(){
    ifstream file("teams.json");


    json j;
    file>>j;

    cout<<j.dump(4)<<endl;

    return 0;

}