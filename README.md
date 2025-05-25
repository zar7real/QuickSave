# 🔄 BackupTool

> **A simple and intuitive backup tool for Windows, written in C++**

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Version](https://img.shields.io/badge/version-1.0.0-orange.svg)](https://github.com/zar7real/BackupTool/releases)

## ✨ Features

- **🎯 Automatic backup** of main directories (Desktop, Downloads, Documents)
- **🌈 Colored console output** for better user experience
- **⚡ Optimized performance** using `std::filesystem` library
- **🛡️ Built-in safety checks** to prevent data loss
- **🔧 Smart directory management** with existing folder handling

## 🚀 How it works

The tool automatically backs up the following directories:
```
📁 C:/Users/{username}/
├── 📂 Desktop     → 📁 Backup/Desktop
├── 📂 Downloads   → 📁 Backup/Downloads
└── 📂 Documents   → 📁 Backup/Documents
```

Once the backup is complete, a copy of the Backup folder is created on the Desktop for quick access.

## 🔧 Compilation and Usage

### Prerequisites
- **💻 Windows Operating System**
- **⚙️ C++ compiler** with C++17 support (Visual Studio, MinGW, etc.)

### Compilation
```bash
g++ -std=c++17 BackupToolService.cpp -o BackupTool.exe
```

### Usage
1. **🔑 Run as administrator** (recommended)
2. **👤 Automatic user detection** - the tool will detect your username
3. **❓ Follow prompts** if an existing backup directory is found
4. **⏳ Wait for completion** - the backup process will run automatically

## 📁 Code Structure

```cpp
// Main components:
🔍 User detection and path resolution
📂 Directory validation and creation
📋 Recursive file copying with error handling
🎨 Colored console output for status updates
```

## 🛡️ Safety Features

- **🔄 Existing backup detection**: Prompts user before overwriting existing backups
- **✅ Directory validation**: Checks if source directories exist before copying
- **⚠️ Error handling**: Comprehensive error reporting for filesystem operations
- **🤝 User confirmation**: Interactive prompts for destructive operations

## 🔧 Technical Details

- **Language**: C++ (C++17 standard)
- **Platform**: Windows (uses Windows-specific APIs)
- **Dependencies**: Standard library only
- **Architecture**: Single-file executable

## 📊 Example Output

```
[!] Username: YourUsername
[!] Backup processing was started.
[!] BackupPath created at: C:/Users/YourUsername/Backup
[+] All directories was copied successfully.
[!] BACKUP WAS FINISHED. copied at C:/Users/YourUsername/Backup
```

## 🤝 Contributing

Feel free to fork this project and submit pull requests. All contributions are welcome!

## 📄 License

This project is open-source and available under the MIT License.

## 📞 Contact

- **GitHub**: [@zar7real](https://github.com/zar7real)
- **Issues**: [Report bugs or request features](https://github.com/zar7real/BackupTool/issues)

---

⭐ **Don't forget to star this repository if you found it useful!**
