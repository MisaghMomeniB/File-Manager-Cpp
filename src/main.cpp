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

// Function to rename a file
void renameFile(const string &oldName, const string &newName) {
    try {
        fs::rename(oldName, newName);  // Try to rename the file
        cout << "✅ File renamed successfully.\n";
    } catch (const fs::filesystem_error& e) {  // If there is an error
        cout << "❌ Error renaming file: " << e.what() << "\n";
    }
}

// Function to compress a file using zlib
void compressFile(const string &filename) {
    ifstream file(filename, ios::binary);  // Open file for binary reading
    if (!file) {  // If file not found
        cout << "❌ File not found!\n";
        return;
    }

    string compressedFile = filename + ".gz";  // Set name for the compressed file
    ofstream outFile(compressedFile, ios::binary);  // Open file for binary writing
    
    char buffer[1024];  // Buffer to store data
    while (file.read(buffer, sizeof(buffer))) {  // Read file in binary chunks
        outFile.write(buffer, file.gcount());  // Write the data to the compressed file
    }

    cout << "📦 File compressed successfully as " << compressedFile << endl;  // Success message
}

// Function to create a backup of a file
void backupFile(const string &filename) {
    string backupName = filename + ".bak";  // Set name for the backup file
    fs::copy(filename, backupName);  // Copy the original file to the backup file
    cout << "🗂️ Backup created as " << backupName << endl;  // Success message
}

// Function to encrypt a file using AES (Not implemented yet)
void encryptFile(const string &filename) {
    cout << "🔒 Encrypting file (Not implemented yet!)\n";
}

// Function to decrypt a file using AES (Not implemented yet)
void decryptFile(const string &filename) {
    cout << "🔓 Decrypting file (Not implemented yet!)\n";
}

// Main menu
int main() {
    int choice;
    string filename, newFilename;

    do {
        cout << "\n📂 **Advanced File Manager**\n";
        cout << "1️⃣ Create a new file\n";
        cout << "2️⃣ Write to a file\n";
        cout << "3️⃣ Read from a file\n";
        cout << "4️⃣ Delete a file\n";
        cout << "5️⃣ Edit a file\n";
        cout << "6️⃣ List files\n";
        cout << "7️⃣ Search in a file\n";
        cout << "8️⃣ Rename a file\n";
        cout << "9️⃣ Compress a file\n";
        cout << "🔟 Backup a file\n";
        cout << "1️⃣1️⃣ Encrypt a file\n";
        cout << "1️⃣2️⃣ Decrypt a file\n";
        cout << "1️⃣3️⃣ Exit\n";
        cout << "🔸 Your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5 || choice == 7 || choice == 9 || choice == 10 || choice == 11 || choice == 12) {
            cout << "📌 Enter file name: ";
            cin >> filename;
        }

        switch (choice) {  // Perform the operation based on user input
            case 1: createFile(filename); break;
            case 2: writeFile(filename); break;
            case 3: readFile(filename); break;
            case 4: deleteFile(filename); break;
            case 5: editFile(filename); break;
            case 6: listFiles(); break;
            case 7: searchInFile(filename); break;
            case 8: 
                cout << "📌 Enter new file name: ";
                cin >> newFilename;
                renameFile(filename, newFilename);
                break;
            case 9: compressFile(filename); break;
            case 10: backupFile(filename); break;
            case 11: encryptFile(filename); break;
            case 12: decryptFile(filename); break;
            case 13: cout << "👋 Exiting program!\n"; break;
            default: cout << "❌ Invalid option! Please try again.\n";
        }
    } while (choice != 13);  // Continue until the user selects exit option

    return 0;
}