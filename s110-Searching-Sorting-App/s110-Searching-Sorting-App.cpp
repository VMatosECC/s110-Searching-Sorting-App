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
void showVector(vector<int>& v, string caption = "This is a vector");
void bubbleSort(vector<int>& v);


//----------------------------------------------------------------
int main()
{
    vector<string> vcountry;

    //experiment01(vcountry);

    //experiment02(vcountry);

    experiment03();

    cout << "\nAll done!\n";
}
// ----------------------------------------------------------
void experiment03()
{

    vector<int> a { 33, 22, 44, 11, 77, 66, 55 };
    showVector(a, "Before sorting");
    bubbleSort(a);
    showVector(a, "After sorting");
}


//------------------------------------------------------------
void bubbleSort(vector<int>& v)
{
    int counter = 0;
    for (int last = v.size()-1; last > 0; last--)
    {
        for (int first = 0; first < last; first++)
        {
            if (v[first] > v[first + 1]) {
                //swap data cells
                int temp = v[first];
                v[first] = v[first + 1];
                v[first + 1] = temp;

            }
            ++counter;
            cout << " Count of statements " << 4 * counter << endl;
        }
    }
}



void showVector(vector<int>& v, string caption)
{
    cout << caption << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
}




//-----------------------------------------------------------
void experiment02(vector<string>& vcountry)
{
    //Binary search
    string countryName = "Vatican"; //Hardcoding a value

    do {
        cout << "\nBIN. Enter a country [xxx]: ";
        getline(cin, countryName);
        if (countryName == "xxx") break;

        int pos = binarySearch(vcountry, countryName);
        if (pos >= 0)
            cout << "Country found at location " << pos << endl;
        else
            cout << "Country not found\n";
      

    } while (true);

}
// ----------------------------------------------------------
int binarySearch(vector<string>& v, string key)
{
    int first = 0;
    int last = v.size() - 1;
    int mid;
    int counter = 0;
    while (first <= last)
    {
        //Bisection
        int mid = (first + last) / 2;
        cout << "Bisection count " << ++counter << endl;

        //check for a match
        if (v[mid] == key) return mid;

        //should we search left or right sub-array?
        if (v[mid] > key)
            //left
            last = mid - 1;
        else
            //right
            first = mid + 1;
    }
    //data not found
    return -1;
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
        cout << "\nSEQ. Enter country [xxx to end]: ";
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