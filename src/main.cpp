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

// Function to delete a file
void deleteFile(const string &filename) {
    if (fs::remove(filename)) {  // Try to remove the file
        cout << "🗑️ File " << filename << " deleted successfully.\n";
    } else {
        cout << "❌ File not found!\n";  // If file is not found
    }
}

// Function to edit a specific line in a file
void editFile(const string &filename) {
    vector<string> lines;  // Vector to store file lines
    ifstream file(filename);  // Open file for reading
    if (!file) {  // If file not found
        cout << "❌ File not found!\n";
        return;
    }

    string line;
    while (getline(file, line)) {  // Read all lines from the file
        lines.push_back(line);
    }
    file.close();  // Close the file

    cout << "Enter line number to edit: ";
    int lineNumber;
    cin >> lineNumber;
    cin.ignore();  // Ignore the newline after the number input

    if (lineNumber < 1 || lineNumber > lines.size()) {  // Check if line number is valid
        cout << "❌ Invalid line number!\n";
        return;
    }

    cout << "Enter new text: ";
    string newText;
    getline(cin, newText);  // Read new text from user
    lines[lineNumber - 1] = newText;  // Replace the line with new text

    ofstream outFile(filename);  // Open file for writing again
    for (const auto &l : lines) {  // Write all lines back to the file
        outFile << l << endl;
    }

    cout << "✅ File updated successfully.\n";  // Success message
}

// Function to list all files in the current directory
void listFiles() {
    cout << "📂 Files in the current directory:\n";
    for (const auto &entry : fs::directory_iterator(fs::current_path())) {  // Iterate over the directory
        cout << entry.path().filename() << endl;  // Display file names
    }
}

// Function to search for a word in a file
void searchInFile(const string &filename) {
    ifstream file(filename);  // Open file for reading
    if (!file) {  // If file does not exist
        cout << "❌ File not found!\n";
        return;
    }

    cout << "Enter word to search: ";
    string word;
    cin >> word;  // Read the word to search

    string line;
    int lineNumber = 0;
    bool found = false;
    while (getline(file, line)) {  // Read each line from the file
        lineNumber++;
        if (line.find(word) != string::npos) {  // Check if the word exists in the line
            cout << "🔍 Found at line " << lineNumber << ": " << line << endl;
            found = true;
        }
    }
    if (!found) cout << "❌ Word not found in the file.\n";  // If word not found
}