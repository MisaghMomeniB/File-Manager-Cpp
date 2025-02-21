#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <zlib.h>  // For compression (requires linking with -lz)
#include <openssl/aes.h>  // For encryption (requires OpenSSL)

using namespace std;
namespace fs = filesystem;

// Function to create a new file
void createFile(const string &filename) {
    ofstream file(filename);  // Open file for writing
    if (file) {  // If file opened successfully
        cout << "✅ File " << filename << " created successfully.\n";
    } else {
        cout << "❌ Error creating file!\n";  // If there is an error creating the file
    }
    file.close();  // Close the file
}

// Function to write to a file
void writeFile(const string &filename) {
    ofstream file(filename, ios::app);  // Open file in append mode
    if (!file) {  // If file not found
        cout << "❌ File not found!\n";
        return;
    }
    string content;
    cout << "✍️ Enter text to write:\n";
    cin.ignore();
    getline(cin, content);  // Read the input text from the user
    file << content << endl;  // Write the content to the file
    cout << "✅ Data saved successfully.\n";  // Success message
    file.close();  // Close the file
}

// Function to read from a file
void readFile(const string &filename) {
    ifstream file(filename);  // Open file for reading
    if (!file) {  // If file does not exist
        cout << "❌ File does not exist!\n";
        return;
    }
    string line;
    cout << "📖 File content:\n";
    while (getline(file, line)) {  // Read file line by line
        cout << line << endl;
    }
    file.close();  // Close the file
}