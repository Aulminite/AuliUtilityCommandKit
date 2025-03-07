# AuliUtilityCommandKit
Small collection of CLI utilities that perform functions like testing terminal colorspace and periodic table lookups.

This repository contains a set of small command-line utilities that serve various purposes. Each utility is designed to be simple and easy to use. Below is a brief description of each command and instructions for adding them to your system's **PATH**.

## Commands Overview

### 1. **sipc** - SI Prefix Converter
The `sipc` command converts between different **SI (International System of Units) prefixes**. You can use it to easily convert values between prefixes like milli to base or kilo to centi.

#### Usage:
```bash
sipc <value> <prefix> <target prefix>
sipc 30mm m
```
This command will convert 30 millimeters to meters (0.03 meters).


### 2. colortest - Terminal Color Tester
The colortest command tests your terminal's color capabilities, including both ANSI 16 colors and 256 colors. It displays a range of colors to check which are supported by your terminal.
Usage:
```bash
colortest
```
This will print a grid of colors, showing both the basic 16 colors and the 256-color palette. This command will also check if your terminal supports full True Color (24-bit).

### 3. ptab - Periodic Table Lookup Tool
The ptab command allows you to quickly look up information about chemical elements in the periodic table by their atomic number or atomic symbol.
Usage:
```bash
ptab <element>
```
You can use either the atomic number or the atomic symbol as the argument:
    ptab 3 will return information about Lithium.
    ptab H will return information about Hydrogen.

### 4. ascii - ASCII Encode/Decode Program
The ascii command converts text to ASCII values and vice versa. This is useful for understanding how characters are represented in memory.
Usage:
    To convert text to ASCII values:
```bash
ascii <text>
```
Example:
```bash
ascii "Hello"
```
To convert ASCII values back to text, use the -r flag:
```bash
ascii -r <ascii values>
```
Example:
```bash
ascii -r 72 101 108 108 111
```
#### Note: The -r flag is only necessary when converting a single character's worth of ascii value into character format.

### 5. fold - display folder tree
The fold command displays the contents of your current directory and a summary of subdirectories. BE CAUTIOUS WITH THIS COMMAND. It does not stop after printing some number of lines, so if you use it in root, it will print every single directory on the machine. The purpose is to locate folders and files within projects.
Usage:
```bash
fold
```
Example Output:
```
C:\Users\REDACTED\Documents\GitHub\AuliUtilityCommandKit
├┬──.git
│├┬──hooks
││└─── ...
│├┬──info
││└─── ...
│├┬──logs
││├┬──refs
│││├┬──heads
││││└─── ...
│││├┬──remotes
││││├┬──origin
│││││└─── ...
││││└─── ...
│││└─── ...
││└─── ...
│├┬──objects
││├┬──info
│││└─── ...
││├┬──pack
│││└─── ...
││└─── ...
│├┬──refs
││├┬──heads
│││└─── ...
││├┬──remotes
│││├┬──origin
││││└─── ...
│││└─── ...
││├┬──tags
│││└─── ...
││└─── ...
│├───config
│├───description
│├───FETCH_HEAD
│├───HEAD
│├───index
│├───packed-refs
│└─── ...
├┬──Linux Executables
│└─── ...
├┬──Source Code
│├┬──linux
││└─── ...
│├┬──windows
││└─── ...
│└─── ...
├┬──Windows Executables
│├───ascii.exe
│├───colortest.exe
│├───fold.exe
│├───ptab.exe
│├───sipc.exe
│└─── ...
├───README.md
└─── ...
```
It is also color coded with the following scheme:
| File Extensions                                          | Category        | Color    |
| -------------------------------------------------------- | --------------- | -------- |
| `.jpg`, `.jpeg`, `.png`, `.gif`, `.bmp`, `.tiff`         | Image           | Red      |
| `.mp3`, `.wav`, `.flac`, `.aac`, `.ogg`                  | Audio           | Yellow   |
| `.mp4`, `.avi`, `.mkv`, `.mov`, `.wmv`, `.flv`           | Video           | Orange   |
| `.exe`, `.bat`, `.msi`, `.cmd`                           | Executable      | Blue     |
| `.c`, `.cpp`, `.h`, `.py`, `.java`, `.js`, `.html`, `.css` | Code            | Purple   |
| `.zip`, `.tar`, `.rar`, `.gz`, `.7z`                     | Compressed/Archive | White  |
| `.txt`, `.md`, `.rtf`, `.log`                            | Text            | Turquoise|

## Setting up the Programs (Adding to PATH)

### Windows
After compilation, you will have .exe files (e.g., `sipc.exe`, `colortest.exe`, `ptab.exe`, `ascii.exe`, `fold.exe`).
Move the executables to a directory of your choice (e.g., `C:\path\to\bin`).
Add that directory to your system's PATH environment variable:
    Right-click This PC and select Properties.
    Click Advanced system settings and then Environment Variables.
    In the System variables section, find the Path variable, and click Edit.
    Add the path to the directory where you placed the executables (e.g., `C:\path\to\bin`).
    Click OK to apply the changes.
Now you should be able to run the programs from any directory in Command Prompt or PowerShell.
    
### Linux
LINUX NOT YET SUPPORTED!

Step 1: Move the Executables to a Directory in PATH
First, choose or create a directory where you'd like to store the executables. A common directory for user binaries is `/usr/local/bin` or `~/bin` (the latter for a user-specific path).
If you want to use `/usr/local/bin`, it’s a standard directory already included in most Linux distributions' PATH, so you can use that.
Move the executables to the directory of your choice. Assuming you have the files in the current directory, run the following command to move them to /usr/local/bin:
```bash
sudo mv sipc colortest ptab ascii /usr/local/bin/
```
This moves the executables sipc, colortest, ptab, and ascii to /usr/local/bin.
