#include <iostream> 
#include <fstream>
#include <ctime>
#include <utility>
#include <tuple>
using namespace std;

// function that encrypts a password 
pair<string, int>encrypt(string password) { // function that returns pair from #include <utility>
    time_t now = time(nullptr); // depending on how many seconds have passed since time, will produce an int
    int keyEnc = now % 10;
    for(int i = 0; i < password.length(); i++) {
        password[i] = password[i] -15 + keyEnc - (i % keyEnc) +i;
    }
return make_pair(password, keyEnc); // return result in pair
}

string deEncrypt(string encryptedPassword, int key) { // reverse engineer encryption function
    for(int i = 0; i < encryptedPassword.length(); i++) {
        encryptedPassword[i] = encryptedPassword[i] + 15 - key + (i % key) - i;
    }
    return encryptedPassword; // return string of de-encrypted password
}

// function to retrieve identifier, username and password from user and return it as a tuple
tuple<string, string, string> getInfo() {
string passwordIdentifier, username, password;

cout << "What is the identifying name of the password? ";
cin >> passwordIdentifier; // take in user password identifier
cout << "What is the username? ";
cin >> username; // take in username
cout << "What is the password you would like to encrypt? "; // take in password to encrypt
cin >> password;

auto newTuple = make_tuple(passwordIdentifier, username, password); // create, allocate tuple
return newTuple; // return tuple
}

int main() {

tuple<string, string, string> newTuple = getInfo(); // retrieve user input and store in tuple

pair<string, int> result = encrypt(get<2>(newTuple)); // create new pair with string of encrypted password and int of key used
// pair is used because this is what can be done to pass two parameters to function

cout << endl << "Username: " << get<1>(newTuple) 
    << endl << "Password before encryption: " << get<2>(newTuple) 
    << endl << "After encryption: " << result.first 
    << endl << "Using the key of: " << result.second
    << endl << "Password decrypted: " << deEncrypt(result.first, result.second);

//write to new file
ofstream passwordFile;

 // to append to file, use the ios_base::app function which prevents overwriting of file
passwordFile.open("encryptedPasswordsNew.txt", ios_base::app);

// write to file
passwordFile << get<0>(newTuple) << " - " << get<1>(newTuple) << " - " << result.first << " - " << result.second << endl;

// close file
passwordFile.close();
} 
