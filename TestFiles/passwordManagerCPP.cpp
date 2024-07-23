#include <iostream>
#include <ctype.h>
#include <fstream>
#include <map>

using namespace std;

int main() {
    cout << "1 to store new password.\n2 to retrieve saved password.\nAnswer: ";
    int answer;
    string nameToStore, passwordToStore;
    cin >> answer;

    
    if (answer != 1 && answer != 2) {
    cout << "Invalid answer";
    return 0;
    }
    
    cout << "What is the name of the password you would like to store?\n:";
    cin >> nameToStore;
    cout << "What is the password for " << nameToStore << endl << ":";
    cin >> passwordToStore;
    
    ofstream passwordFile;
    
    // to append to file, use the ios_base::app function which prevents overwriting of file
    passwordFile.open("passwordFile.txt", ios_base::app);
    passwordFile.open("passwordFile.txt");
    passwordFile << nameToStore << " - " << passwordToStore << endl;
    passwordFile.close();


    
}