#include<iostream>
#include<fstream>
#include<nlohmann/json.hpp>

using namespace std;

using json=nlohmann::json;

int main(){
    json jsonData;

    string Name;
    int age;
    bool present;
    vector<string>courses;
    int count;

    cout<<"Enter Name ";
    cin>>Name;
    cout<<"Enter Age ";
    cin>>age;
    cout<<"Is present  ";
    cin>>present;
    
    cout<<"Enter the courses";
    for(int i=0;i<4;i++){
        string temp;
        cin>>temp;
        courses.push_back(temp);
    }

    jsonData["Name"]=Name;
    jsonData["Age"]=age;
    jsonData["present"]=present;
    jsonData["courses"]=courses;

    ofstream jsonFile("file2.json");

    jsonFile << jsonData.dump(4);

    return 0;



}
