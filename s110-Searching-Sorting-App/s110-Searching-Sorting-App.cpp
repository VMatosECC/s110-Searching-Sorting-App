// s110-Searching-Sorting-App.cpp 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Prototypes -------------------------------------------------
void experiment01(vector<string>& vcountry);
void experiment02(vector<string>& vcountry);
void experiment03();
int sequentialSearch(vector<string>& vcountry, string countryName);
int binarySearch(vector<string>& v, string key);

int main()
{
    vector<string> vcountry;

    experiment01(vcountry);
    experiment02(vcountry);

    cout << "\nAll done!\n";
}
//-----------------------------------------------------------
void experiment02(vector<string>& vcountry)
{
    //Binary search
    string countryName = "Argentina";

    int pos = binarySearch(vcountry, countryName);
    cout << "Pos " << pos << "\t" << countryName;
}
// ----------------------------------------------------------
int binarySearch(vector<string>& v, string key)
{
    return 8;
}



void experiment01(vector<string>& vcountry)
{
    //Sequential search
    ifstream xcountryFile("c:/temp/xcountry.txt");
    if (!xcountryFile) {
        cout << "ERROR - file not found\n";
        exit(1);
    }

    string countryName;
    //vector<string> vcountry;

    while (getline(xcountryFile, countryName))
    {
        vcountry.push_back(countryName);
    }
    xcountryFile.close();

    do {
        cout << "\nEnter country [xxx to end]: ";
        getline(cin, countryName);
        if (countryName == "xxx") break;
        int pos = sequentialSearch(vcountry, countryName);
        if (pos == -1) 
            cout << "Country not found " << endl;
        else
            cout << "Country found at location " << pos << endl;
    } while (true);
}

int sequentialSearch(vector<string>& vcountry, string countryName)
{
    for (int i = 0; i < vcountry.size(); i++) {
        if (vcountry[i] == countryName) 
            return i;   //success!
    }
    return -1;          //data item not found
}