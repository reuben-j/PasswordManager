#include <iostream> 
#include <fstream>
#include <ctime>
#include <vector>
#include <utility>
using namespace std;

// function that encrypts a password 
pair<string, int>encrypt(string password) { // function that returns pair from #include <utility>
    time_t now = time(nullptr); // depending on how many seconds have passed since time, will produce an int
    int keyEnc = now % 10; // gives a single digit encoding key
    if(keyEnc == 0) { // if key were to equal 0, there would be no encryption or at least very basic encryption
        keyEnc = 3; // allocate key to 3 in case it equals 0
    }
    for(int i = 0; i < password.length() + 1; i++) { // loop through each letter of original password
        if (password[i] >= 90) { // to ensure all ascii chars are within bounds (less than 127 and above 31)
        password[i] = password[i] - (keyEnc + i + 2); // ascii char above 90 gets a char lower than 90
    } else {
        password[i] = password[i] + (keyEnc + i + 2); // ascii char below 90 gets a char above 90
    }
}
return make_pair(password, keyEnc); // return result in pair
}


string deEncrypt(string encryptedPassword, int key) { // reverse engineer encryption function
    
    for(int i = 0; i < encryptedPassword.length(); i++) { // loop through each letter again
        if(encryptedPassword[i] + (key + i) > 90) { // find out whether original char was above or below 90 to allocate original char accurately
            encryptedPassword[i] = encryptedPassword[i] + (key + i + 2);
        } else {
            encryptedPassword[i] = encryptedPassword[i] - (key + i + 2);
        }
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

cout << "Password de-encrypted: " << deEncrypt(result.first, result.second);

//write to new file

}