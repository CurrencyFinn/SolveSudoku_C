#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() 
{

    
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
    int eight;
    int nine;

    vector<int> One;
    vector<int> Two;
    vector<int> Three;
    vector<int> Four;
    vector<int> Five;
    vector<int> Six;
    vector<int> Seven;
    vector<int> Eight;
    vector<int> Nine;
     
    ifstream inputFile;
    inputFile.open("test.csv");
    string line;
    while (getline(inputFile, line)) {

        string tempString = ""; 

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        one = atoi(tempString.c_str());
        One.insert(One.end(), one);
        tempString = "";
        getline(inputString, tempString, ',');
        two = atoi(tempString.c_str());
        Two.insert(Two.end(), two);
        tempString = "";
        getline(inputString, tempString, ',');
        three = atoi(tempString.c_str());
        Three.insert(Three.end(), three);
        tempString = "";
        getline(inputString, tempString, ',');
        four = atoi(tempString.c_str());
        Four.insert(Four.end(), four);
        tempString = "";
        getline(inputString, tempString, ',');
        five = atoi(tempString.c_str());
        tempString = "";
        getline(inputString, tempString, ',');
        six = atoi(tempString.c_str());
        tempString = "";
        getline(inputString, tempString, ',');
        seven = atoi(tempString.c_str());
        tempString = "";
        getline(inputString, tempString, ',');
        eight = atoi(tempString.c_str());
        tempString = "";
        getline(inputString, tempString, ',');
        nine = atoi(tempString.c_str());

        line ="";
    }

    int value;
    while (value != 10) {
        cin>> value;
        cout << One[value] << endl;
    }


}