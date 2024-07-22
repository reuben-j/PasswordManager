#include <iostream> 
#include <fstream>
using namespace std;

string encrypt(string password) {
    
    for(int i = 0; i < password.length() + 1; i++) {
        password[i] = password[i] + 2;
    }
    return password;
}

string deEncrypt(string password) {
    for(int i = 0; i < password.length() + 1; i++) {
        password[i] = password[i] - 2;
    }
    return password;
}

int main() {
    cout << "What is the password you would like to encrypt? ";
    string password;
    cin >> password;
    cout << "Password encrypted: " << encrypt(password) << endl;
    string passWordEncrypted = encrypt(password);
    cout << "Password de-encrypted: " << deEncrypt(passWordEncrypted);
}