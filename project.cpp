#include <iostream>  // Include the necessary header files
#include <string>
#include <cctype>

using namespace std;

// Function to encrypt the message using Caesar cipher
string encryptCaesar(string message, int shift) {
    string encryptedMessage = "";  // Initialize an empty string to store the encrypted message
    for (char character : message) {  // Iterate over each character in the message
        if (isalpha(character)) {  // Check if the character is alphabetic
            char base = isupper(character) ? 'A' : 'a';  // Determine the base character based on case
            char shiftedCharacter = char((character - base + shift) % 26 + base);  // Apply the Caesar cipher shift
            encryptedMessage += shiftedCharacter;  // Append the encrypted character to the encrypted message
        } else {
            // Non-alphabetic characters remain unchanged
            encryptedMessage += character;  // Append the character to the encrypted message as is
        }
    }
    return encryptedMessage;  // Return the encrypted message
}

// Function to decrypt the message using Caesar cipher
string decryptCaesar(string encryptedMessage, int shift) {
    // Decryption is essentially encryption with the inverse shift
    return encryptCaesar(encryptedMessage, 26 - shift);  // Call the encryption function with the inverse shift
}

// Function to encrypt the message using Vigenère cipher
string encryptVigenere(string message, string key) {
    string encryptedMessage = "";  // Initialize an empty string to store the encrypted message
    int keyIndex = 0;  // Initialize an index variable to keep track of the current key character
    for (char character : message) {  // Iterate over each character in the message
        if (isalpha(character)) {  // Check if the character is alphabetic
            char base = isupper(character) ? 'A' : 'a';  // Determine the base character based on case
            char keyChar = key[keyIndex % key.length()];  // Retrieve the current key character cyclically
            char shiftedCharacter = char((character - base + keyChar - 'A') % 26 + base);  // Apply the Vigenère cipher shift
            encryptedMessage += shiftedCharacter;  // Append the encrypted character to the encrypted message
            keyIndex++;  // Increment the key index for the next character
        } else {
            // Non-alphabetic characters remain unchanged
            encryptedMessage += character;  // Append the character to the encrypted message as is
        }
    }
    return encryptedMessage;  // Return the encrypted message
}

// Function to decrypt the message using Vigenère cipher
string decryptVigenere(string encryptedMessage, string key) {
    string decryptedMessage = "";  // Initialize an empty string to store the decrypted message
    int keyIndex = 0;  // Initialize an index variable to keep track of the current key character
    for (char character : encryptedMessage) {  // Iterate over each character in the encrypted message
        if (isalpha(character)) {  // Check if the character is alphabetic
            char base = isupper(character) ? 'A' : 'a';  // Determine the base character based on case
            char keyChar = key[keyIndex % key.length()];  // Retrieve the current key character cyclically
            char shiftedCharacter = char((character - base - (keyChar - 'A') + 26) % 26 + base);  // Apply the Vigenère cipher shift
            decryptedMessage += shiftedCharacter;  // Append the decrypted character to the decrypted message
            keyIndex++;  // Increment the key index for the next character
        } else {
            // Non-alphabetic characters remain unchanged
            decryptedMessage += character;  // Append the character to the decrypted message as is
        }
    }
    return decryptedMessage;  // Return the decrypted message
}

int main() {
    string message, key;  // Declare variables to store the message and key for encryption
    int shift;  // Declare a variable to store the Caesar cipher shift value

    // Input the message
    cout << "Enter the message: ";
    getline(cin, message);

    // Input the Caesar cipher shift value
    cout << "Enter the Caesar cipher shift value: ";
    cin >> shift;

    // Encrypt and decrypt using the Caesar cipher
    string encryptedCaesar = encryptCaesar(message, shift);  // Encrypt the message using Caesar cipher
    cout << "Encrypted message (Caesar): " << encryptedCaesar << endl;
    cout << "Decrypted message (Caesar): " << decryptCaesar(encryptedCaesar, shift) << endl;

    // Input the Vigenere cipher key
    cout << "Enter the Vigenere cipher key: ";
    cin >> key;

    // Encrypt and decrypt using the Vigenere cipher
    string encryptedVigenere = encryptVigenere(message, key);  // Encrypt the message using Vigenere cipher
    cout << "Encrypted message (Vigenere): " << encryptedVigenere << endl;
    cout << "Decrypted message (Vigenere): " << decryptVigenere(encryptedVigenere, key) << endl;

    return 0;
}