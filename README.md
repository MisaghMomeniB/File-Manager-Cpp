# 🗂️ File Manager C++  

A simple yet powerful **cross-platform file manager** and library written in modern C++.  
Use it as a CLI tool to explore directory structures or embed it in your C++ projects.

---

## 📋 Table of Contents

1. [Overview](#overview)  
2. [Features](#features)  
3. [Installation & Build](#installation--build)  
4. [Usage](#usage)  
5. [Library Integration](#library-integration)  
6. [Supported Platforms](#supported-platforms)  
7. [Tech & Design](#tech--design)  
8. [License](#license)  
9. [Contributing](#contributing)

---

## 💡 Overview

This project lets you:

- Traverse and list files/directories with filters  
- Generate tree-like directory maps and save to output files  
- Integrate file-management utilities into your C++ programs

Built using **C++17** (leveraging `std::filesystem`) with clean, simple APIs. Ideal for learning and direct use! :contentReference[oaicite:1]{index=1}

---

## ✅ Features

- `list_files(...)` – returns file/directory entries, filtered by extensions  
- `writeToFile(...)` – outputs directory structure in tree format (`|--`)  
- CLI utility **`fmanager`** with options:
  - `-p`, `--path`: set traversal start directory  
  - `-l`, `--list_files`: print file listing  
  - `-t`, `--tree`: print tree output  
  - `-d`, `--ignore_dirs`: skip specified directories  
  - `-e`, `--ignore_extensions`: exclude specific extensions  
  - `-s`, `--separator`: customize tree marker (e.g. `-`, `*`) :contentReference[oaicite:2]{index=2}  

---

## ⚙️ Installation & Build

**Prerequisites**:

- A compiler supporting **C++17** (`g++`, `clang++`, MSVC)  
- CMake (optional, for building the library and CLI)

**Build steps**:

```bash
git clone https://github.com/MisaghMomeniB/File-Manager-Cpp.git
cd File-Manager-Cpp
mkdir build && cd build
cmake .. 
make          # or `cmake --build .`
````

This produces:

* `fmanager` CLI binary
* Static library (`libcpp-file-manager.a`) and headers in `include/`

---

## 🛠️ Usage

### CLI Examples

```bash
# List files in "samples" directory
./fmanager -p samples -l

# Generate a tree in current dir, ignoring .git and ".o" files
./fmanager -p . -t -d .git,build -e .o

# Use '-' as tree separator
./fmanager -p . -t -s '-'
```

### Library Integration

In your C++ code:

```cpp
#include "FileManager.hpp"

int main() {
    FileManager fm("/path/to/dir");
    auto list = fm.list_files({".tmp"}, true);
    for (auto &item : list) {
        std::cout << (item.is_dir ? "[DIR] " : "[FILE] ") << item.name << "\n";
    }
    fm.writeToFile({".git", "build"}, {".log", ".tmp"});
    return 0;
}
```

Compile with:

```bash
g++ main.cpp -Iinclude -Lbuild -lcpp-file-manager -o app
```

---

## 🌍 Supported Platforms

* **Linux**: fully supported
* **Windows / macOS**: experimental pending further testing, PRs welcome! ([github.com][1])

---

## 🧩 Tech & Design

* Leverages `std::filesystem` for portable traversal
* Encapsulated in `FileManager` class using RAII
* CLI built with lightweight argument parsing
* Filters use standard C++ containers and lambdas for clean code

---

## 📄 License

Licensed under the **MIT License** — see [LICENSE](LICENSE) file.

---

## 🤝 Contributing

Contributions and feedback are welcome!
Please:

1. Fork the repo
2. Create a branch (`feature/XXX`)
3. Submit a clean PR describing your changes
