#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser() {
    string user, pass;
    cout << "Select a username: "; cin >> user;
    cout << "Select a password: "; cin >> pass;

    ofstream file;
    file.open(user + ".txt"); 
    file << user << endl << pass;
    file.close();
    cout << "Registration successful!\n";
}

bool loginUser() {
    string user, pass, u, p;
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;

    ifstream read(user + ".txt");
    getline(read, u);
    getline(read, p);

    if (u == user && p == pass) return true;
    else return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    }
    else if (choice == 2) {
        if (loginUser()) cout << "Login Successful!\n";
        else cout << "Invalid credentials!\n";
    }
    return 0;
}