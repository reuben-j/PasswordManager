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
        password[i] = password[i] - (keyEnc + i);
    } else {
        password[i] = password[i] + (keyEnc + i);
    }
}
return make_pair(password, keyEnc);
}


string deEncrypt(string encryptedPassword, int key) {
    
    for(int i = 0; i < encryptedPassword.length(); i++) {
        if(encryptedPassword[i] + (key + i) > 90) {
            encryptedPassword[i] = encryptedPassword[i] + (key + i);
        } else {
            encryptedPassword[i] = encryptedPassword[i] - (key + i);
        }
    }
    return encryptedPassword;
}

 int main() {

time_t newNow = time(nullptr);

    cout << "What is the password you would like to encrypt? ";
    string password;
    cin >> password;

pair<string, int> result = encrypt(password);
string passwordEncrypted = result.first;
int key = result.second;

cout << endl << "Password before encryption: " << password << endl << "After encryption: " << passwordEncrypted << endl << "Using the key of: " << result.second << endl;

cout << "Attempting to de-encrypt: " << deEncrypt(passwordEncrypted, key);
}