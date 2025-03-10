/*
    *  BackupToolService.cpp
    *  SCRIPT WRITTEN BY: @zar.7.real (alchemy)
    *  This script is a simple backup tool that copies the Desktop, Downloads and Documents directories to a Backup directory.
    *  The script is written in C++ and uses the filesystem library.
    *  The script is designed to run on Windows OS.
    *  The script is open-source and can be used by anyone.
    *  The script is written for educational purposes only.
    *  The script is not intended for malicious purposes.
    *  The script is not intended to harm anyone.
    *  The script is not intended to steal any data.
    *  The script is not intended to be used for any dangerous purposes.
    *  The script is not intended to be used for any malicious purposes.
    *  The script is not intended to be used for any harmful purposes.
    *  The script is not intended to be used for any destructive purposes.
    *  The script is not intended to be used for any damaging purposes.
    *  The script is not intended to be used for any illegal purposes.
    *  The script is not intended to be used for any unethical purposes.
    *  The script is not intended to be used for any immoral purposes.
    *  you can update the script and modify it as you like.
    *  if u have any problem contact me on my github: https://github.com/zar7real
*/


#include <iostream>
#include <string>
#include <windows.h>
#include <Lmcons.h>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <filesystem>

namespace fs = std::filesystem;

const int red = 12;
const int green = 10;
const int blue = 9;
const int reset = 7;
const int yellow = 14;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void copy_file(const fs::path& src, const fs::path& dst) {
     try {
        fs::copy(src, dst, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        setColor(green);
        std::cout << "[+] " << "All directories was copied succesfully." << std::endl;
        std::cout << "[!] " << "BACKUP WAS FINISHED." << " copied at " << dst << std::endl;
    } catch (const fs::filesystem_error& e) {
        setColor(red);
        std::cerr << "[-] " << "Error copying " << src << " to " << dst << ": " << e.what() << std::endl;
    }
}

int main() {
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;

    if (GetUserNameA(username, &username_len)) {
        setColor(yellow);
        std::cout << "[!] " << "Username: " << username << std::endl;
    } else {
        setColor(red);
        std::cerr << "[-]" << "Username not found." << std::endl;
        return 1;
    }

    std::string home_path = "C:/Users/" + std::string(username);
    std::string backup_path = home_path + "/Backup";

    std::string desktop = home_path + "/Desktop";
    std::string downloads = home_path + "/Downloads";
    std::string documents = home_path + "/Documents";
    std::string final_path = home_path + "/Desktop";

    setColor(yellow);
    std::cout << "[!] " << "Backup processing was started." << std::endl;

    if (!fs::exists(backup_path)) {
        fs::create_directories(backup_path);
        std::cout << "[!] " <<"BackupPath created at: " << backup_path << std::endl;
    } else {
        if (fs::exists(backup_path) && fs::is_directory(backup_path)) {
            setColor(red);
            std::cout << "[-]" << "A backup file dir path was found" << std::endl;
            std::string user_choice_delete;
            std::cout << "do you want delete it(yes/no): ";
            std::getline(std::cin, user_choice_delete);

            if (user_choice_delete == "yes") {
                setColor(green);
                fs::remove_all(backup_path);
            } else if (user_choice_delete == "no") {
                setColor(red);
                std::cout << "Operation aborted by user." << std::endl;
                return 1;
            } else {
                setColor(red);
                std::cerr << "Error during the elimination of the path." << std::endl;
                return 1;
            }
            
        }
    }

    if (fs::exists(desktop) && fs::is_directory(desktop)) {
        setColor(green);
        copy_file(desktop, backup_path + "/Desktop");
    } else {
        setColor(red);
        std::cerr << "Desktop not exists." << std::endl;
        return 1;
    }

    if (fs::exists(downloads) && fs::is_directory(downloads)) {
        setColor(green);
        copy_file(downloads, backup_path + "/Downloads");
    } else {
        setColor(red);
        std::cerr << "Downloads not exists." << std::endl;
        return 1;
    }

    if (fs::exists(documents) && fs::is_directory(documents)) {
        setColor(green);
        copy_file(documents, backup_path + "/Documents");
    } else {
        setColor(red);
        std::cerr << "Documents not exists" << std::endl;
        return 1;
    }

    copy_file(backup_path, desktop);

    return 0;
}
