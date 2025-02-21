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