#include <iostream> 
#include <fstream>
#include <ctime>
#include <vector>
#include <utility>
using namespace std;

// function that encrypts a password 
pair<string, int>encrypt(string password) { // function that returns pair from #include <utility>
    time_t now = time(nullptr); // depending on how many seconds have passed since time, will produce an int
    int keyEnc = now % 10;
    for(int i = 0; i < password.length(); i++) {
        password[i] = password[i] -15 + keyEnc + (i % keyEnc) -i;
    }
return make_pair(password, keyEnc); // return result in pair
}


string deEncrypt(string encryptedPassword, int key) { // reverse engineer encryption function
    for(int i = 0; i < encryptedPassword.length(); i++) {
        encryptedPassword[i] = encryptedPassword[i] + 15 - key - (i % key) + i;
    }
    return encryptedPassword; // return string of de-encrypted password
}
 int main() {

cout << "What is the password you would like to encrypt? ";
string password;
cin >> password;

pair<string, int> result = encrypt(password); // create new pair with string of encrypted password and int of key used

cout << endl << "Password before encryption: " << password 
    << endl << "After encryption: " << result.first 
    << endl << "Using the key of: " << result.second << endl;

cout << deEncrypt(result.first, result.second);

//write to new file
ofstream passwordFile;
 // to append to file, use the ios_base::app function which prevents overwriting of file
passwordFile.open("encryptedPasswordsNew.txt", ios_base::app);

passwordFile << result.first << " - " << result.second << endl;

// cout << "Woud you like to encrypt any other passwords? Yes or no?" << endl;
}