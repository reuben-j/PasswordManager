#include <iostream> 
#include <fstream>
#include <ctime>
#include <vector>
#include <utility>
using namespace std;

pair<string, int>encrypt(string password) {
    time_t now = time(nullptr);
    int keyEnc = now % 10;
    if(keyEnc == 0) {
        keyEnc = 3;
    }
    for(int i = 0; i < password.length() + 1; i++) {
        if (password[i] >= 90) {
        password[i] = password[i] - keyEnc;
    } else {
        password[i] = password[i] + keyEnc;
    }
}
return make_pair(password, keyEnc);
}


string deEncrypt(string password) {
    for(int i = 0; i < password.length() + 1; i++) {
        password[i] = password[i] - 2;
    }
    return password;
}

 int main() {

time_t newNow = time(nullptr);






    cout << "What is the password you would like to encrypt? ";
    string password;
    cin >> password;
    
    
    

pair<string, int> result = encrypt(password);
string passwordEncrypted = result.first;

cout << endl << "Password before encryption: " << password << endl << "After encryption: " << passwordEncrypted << endl << "Using the key of: " << result.second;
}