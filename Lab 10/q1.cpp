#include <iostream>
#include <fstream>

using namespace std;

string encrypt(const string& input) {
    string encrypted;
    for (int i = 0; i < input.length(); i++) {
        encrypted += char(input[i] + (i + 1));
    }
    return encrypted;
}

string decrypt(const string& input) {
    string decrypted;
    for (int i = 0; i < input.length(); i++) {
        decrypted += char(input[i] - (i + 1));
    }
    return decrypted;
}

int main() {
    string userInput;
    cout << "Enter String = ";
    getline(cin, userInput);

    string encryptedText = encrypt(userInput);

    ofstream outFile("encrypted.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }
    outFile << encryptedText;
    outFile.close();

    cout << "Normal Text:= " << userInput << endl;
    cout << "Encrypted text inserted in file" << endl;
    cout << encryptedText << endl;
    string decryptedText;
    ifstream inFile("encrypted.txt");
    if (!inFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }
    getline(inFile, decryptedText);
    inFile.close();

    string decodedText = decrypt(decryptedText);
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decodedText << endl;

    return 0;
}

