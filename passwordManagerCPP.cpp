#include <iostream>

using namespace std;

int main() {
    cout << "1 to store new password.\n2 to retrieve saved password.\n";
    int answer;
    cin >> answer;
    if (answer != 1 || answer != 2){
        cin >> answer;
    } else if (answer ==2) {
        cout << "";
    } else {
        cout << "What is identifying name of the password you wish to store?"
    }
    
    
    cout << answer;
}