# 📂 **Advanced File Manager** 🖥️

A powerful command-line tool to manage your files with ease. This program allows you to create, read, write, delete, edit, search, compress, backup, and even encrypt files. All in a user-friendly interface with clear prompts and intuitive navigation! 🚀

## Features ✨

- **Create, Write, Read, and Delete Files** ✍️
- **Edit Specific Lines in Files** ✂️
- **Search for Words in Files** 🔍
- **Rename Files** 🔄
- **Compress Files using zlib** 📦
- **Backup Files** 🗂️
- **Encrypt and Decrypt Files using AES** 🔒🔓 *(Future feature)*
- **View All Files in the Current Directory** 📂

## Requirements ⚙️

- **C++ Compiler** (Supports C++17 or later)
- **zlib** for file compression
- **OpenSSL** for encryption (AES)

## Compilation Instructions 🛠️

To compile the program, make sure you have both `zlib` and `OpenSSL` installed.

1. **Install zlib**: 
   ```bash
   sudo apt-get install zlib1g-dev
   ```

2. **Install OpenSSL**:
   ```bash
   sudo apt-get install libssl-dev
   ```

3. **Compile the Program**:
   ```bash
   g++ -o file_manager file_manager.cpp -lz -lssl -lcrypto
   ```

4. **Run the Program**:
   ```bash
   ./file_manager
   ```

## Install and run with makefile

1. **Install the program**
   For compile and you can run program **filemanager** in linux commandline
   ```bash
   make clean
   sudo make install
   ```

2. **For run with makefile**
   ```bash
   make run
   ```
3. **Clean project files**
   ```bash
   make clean
   ```

## How to Use 🔧

Once you run the program, you will be presented with a menu of operations to choose from. The interface is intuitive and will prompt you for additional information when needed. Here are the available actions:

### 1️⃣ **Create a New File**
   - Simply specify the name of the file you want to create.
   
### 2️⃣ **Write to a File**
   - Add text to an existing file. (The program opens the file in append mode.)

### 3️⃣ **Read from a File**
   - View the contents of any existing file.

### 4️⃣ **Delete a File**
   - Delete a file from the current directory.

### 5️⃣ **Edit a File**
   - Modify specific lines in a file by choosing the line number and entering new content.

### 6️⃣ **List Files**
   - Displays all files in the current directory.

### 7️⃣ **Search in a File**
   - Search for a specific word or phrase within a file.

### 8️⃣ **Rename a File**
   - Rename any file in the current directory.

### 9️⃣ **Compress a File**
   - Compress a file using the `zlib` library. (Output will be a `.gz` file.)

### 🔟 **Backup a File**
   - Create a backup of any file by simply copying it to a new `.bak` file.

### 1️⃣1️⃣ **Encrypt a File** *(Coming soon!)*
   - (AES encryption will be implemented soon!)

### 1️⃣2️⃣ **Decrypt a File** *(Coming soon!)*
   - (AES decryption will be implemented soon!)

### 1️⃣3️⃣ **Exit**
   - Exit the program safely.

## Sample Interaction 💬

Here’s an example of what a user might experience while interacting with the program:

```
📂 **Advanced File Manager**
1️⃣ Create a new file
2️⃣ Write to a file
3️⃣ Read from a file
4️⃣ Delete a file
5️⃣ Edit a file
6️⃣ List files
7️⃣ Search in a file
8️⃣ Rename a file
9️⃣ Compress a file
🔟 Backup a file
1️⃣1️⃣ Encrypt a file
1️⃣2️⃣ Decrypt a file
1️⃣3️⃣ Exit
🔸 Your choice: 1
📌 Enter file name: test.txt
✅ File test.txt created successfully.

📂 **Advanced File Manager**
1️⃣ Create a new file
...
```

## Future Improvements 🌱

- AES Encryption and Decryption 🚀
- More advanced file operations and enhancements ⚡
- Enhanced error handling and validation 💡

## Contribute 🤝

We welcome contributions! Feel free to fork this repository, open an issue, or submit a pull request with improvements or bug fixes.

---

Thanks for checking out the **Advanced File Manager**! Happy coding! 🖥️✨

---
