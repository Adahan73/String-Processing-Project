#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to encrypt the message using Caesar cipher
string encryptCaesar(string message, int shift) {
    string encryptedMessage = "";
    for (char character : message) {
        if (isalpha(character)) {
            char base = isupper(character) ? 'A' : 'a';
            char shiftedCharacter = char((character - base + shift) % 26 + base);
            encryptedMessage += shiftedCharacter;
        } else {
            // Non-alphabetic characters remain unchanged
            encryptedMessage += character;
        }
    }
    return encryptedMessage;
}

// Function to decrypt the message using Caesar cipher
string decryptCaesar(string encryptedMessage, int shift) {
    return encryptCaesar(encryptedMessage, 26 - shift);
}

// Function to encrypt the message using Vigenère cipher
string encryptVigenere(string message, string key) {
    string encryptedMessage = "";
    int keyIndex = 0;
    for (char character : message) {
        if (isalpha(character)) {
            char base = isupper(character) ? 'A' : 'a';
            char keyChar = key[keyIndex % key.length()];
            char shiftedCharacter = char((character - base + keyChar - 'A') % 26 + base);
            encryptedMessage += shiftedCharacter;
            keyIndex++;
        } else {
            // Non-alphabetic characters remain unchanged
            encryptedMessage += character;
        }
    }
    return encryptedMessage;
}

// Function to decrypt the message using Vigenère cipher
string decryptVigenere(string encryptedMessage, string key) {
    string decryptedMessage = "";
    int keyIndex = 0;
    for (char character : encryptedMessage) {
        if (isalpha(character)) {
            char base = isupper(character) ? 'A' : 'a';
            char keyChar = key[keyIndex % key.length()];
            char shiftedCharacter = char((character - base - (keyChar - 'A') + 26) % 26 + base);
            decryptedMessage += shiftedCharacter;
            keyIndex++;
        } else {
            // Non-alphabetic characters remain unchanged
            decryptedMessage += character;
        }
    }
    return decryptedMessage;
}

int main() {
    string message, key;
    int shift;

    // Input the message
    cout << "Enter the message: ";
    getline(cin, message);

    // Input the Caesar cipher shift value
    cout << "Enter the Caesar cipher shift value: ";
    cin >> shift;

    // Encrypt and decrypt using the Caesar cipher
    string encryptedCaesar = encryptCaesar(message, shift);
    cout << "Encrypted message (Caesar): " << encryptedCaesar << endl;
    cout << "Decrypted message (Caesar): " << decryptCaesar(encryptedCaesar, shift) << endl;

    // Input the Vigenere cipher key
    cout << "Enter the Vigenere cipher key: ";
    cin >> key;

    // Encrypt and decrypt using the Vigenere cipher
    string encryptedVigenere = encryptVigenere(message, key);
    cout << "Encrypted message (Vigenere): " << encryptedVigenere << endl;
    cout << "Decrypted message (Vigenere): " << decryptVigenere(encryptedVigenere, key) << endl;

    return 0;
}
