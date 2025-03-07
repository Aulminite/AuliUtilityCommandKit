#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <direct.h>
#include <io.h>
#include <shlwapi.h>

#define MAX_PATH_LENGTH 1024

// @author  Aulminite
// @date    March 7, 2025
// @brief   This program is designed to display the current directory in a tree form while in the terminal.

// ASCII CODES
#define SOURCE_SPACER       "\xB3"
#define BRANCH_LEFT_ROOT    "\xC3\xC4\xC4\xC4"
#define BRANCH_LEFT_DIR     "\xC3\xC2\xC4\xC4"
#define BRANCH_LEFT_END     "\xB3\xC0\xC4\xC4\xC4\xC4\xC4\xC4"
#define SOURCE_END          "\xC0\xC4\xC4\xC4 ..."
#define SUBDIR_END          "\xB3\xC0\xC4\xC4\xC4 ..."

// ANSI Color codes for file types
#define RESET_COLOR "\033[0m"
#define COLOR_FOLDERS "\033[38;5;82m"
#define COLOR_PICTURES "\033[38;5;196m"
#define COLOR_AUDIO "\033[38;5;226m"
#define COLOR_VIDEO "\033[38;5;214m"
#define COLOR_EXECUTABLE "\033[38;5;21m"
#define COLOR_CODE "\033[38;5;13m"
#define COLOR_COMPRESSED "\033[38;5;255m"
#define COLOR_TEXT "\033[38;5;51m"
#define COLOR_OTHER "\033[38;5;242m"

// File categories - these are expandable!
const char *imageExtensions[] = {".jpg", ".jpeg", ".png", ".gif", ".bmp", ".tiff", NULL};
const char *audioExtensions[] = {".mp3", ".wav", ".flac", ".aac", ".ogg", NULL};
const char *videoExtensions[] = {".mp4", ".avi", ".mkv", ".mov", ".wmv", ".flv", NULL};
const char *executableExtensions[] = {".exe", ".bat", ".msi", ".cmd", NULL};
const char *codeExtensions[] = {".c", ".cpp", ".h", ".py", ".java", ".js", ".html", ".css", NULL};
const char *compressedExtensions[] = {".zip", ".tar", ".rar", ".gz", ".7z", NULL};
const char *textExtensions[] = {".txt", ".md", ".rtf", ".log", NULL};

// Function to check if a file extension matches a category
int hasExtension(const char *filename, const char **extensions) {
    const char *ext = strrchr(filename, '.');
    if (ext != NULL) {
        for (int i = 0; extensions[i] != NULL; i++) {
            if (strcmp(ext, extensions[i]) == 0) {
                return 1;  // Match found
            }
        }
    }
    return 0;  // No match
}

// Function to set color based on file extension
void setColorByExtension(const char *filename) {
    if (hasExtension(filename, imageExtensions)) {
        printf("%s", COLOR_PICTURES);  // Red for pictures
    } else if (hasExtension(filename, audioExtensions)) {
        printf("%s", COLOR_AUDIO);     // Yellow for audio
    } else if (hasExtension(filename, videoExtensions)) {
        printf("%s", COLOR_VIDEO);     // Orange for video
    } else if (hasExtension(filename, executableExtensions)) {
        printf("%s", COLOR_EXECUTABLE);  // Blue for executables
    } else if (hasExtension(filename, codeExtensions)) {
        printf("%s", COLOR_CODE);     // Purple for code files
    } else if (hasExtension(filename, compressedExtensions)) {
        printf("%s", COLOR_COMPRESSED);  // White for compressed files
    } else if (hasExtension(filename, textExtensions)) {
        printf("%s", COLOR_TEXT);     // Turquoise for text files
    } else if (strrchr(filename, '.') != NULL) {
        printf("%s", COLOR_OTHER);     // Gray for other file types
    } else {
        printf("%s", COLOR_FOLDERS);    // Bright Green for folders
    }
}

// Function to print the directory tree in the stylized format
void printDirectoryTree(const char *path, int depth, int pageLimit) {
    struct _finddata_t findFileData;
    intptr_t hFile;

    // Build the search pattern for files and directories
    char searchPath[MAX_PATH];
    snprintf(searchPath, MAX_PATH, "%s\\*", path);

    // Open the directory
    hFile = _findfirst(searchPath, &findFileData);

    if (hFile == -1) {
        printf("Unable to open directory: %s\n", path);
        return;
    }

    int fileCount = 0;
    int subdirCount = 0;
    int printedFiles = 0;

    // Print current directory
    if (depth == 0) {
        system("cd");
    }

    // First, print all subdirectories
    do {
        const char *fileName = findFileData.name;

        if (strcmp(fileName, ".") != 0 && strcmp(fileName, "..") != 0) {
            if (findFileData.attrib & _A_SUBDIR) {
                subdirCount++;
            }
        }
    } while (_findnext(hFile, &findFileData) == 0);

    // Go back to beginning of directory search
    _findclose(hFile);
    hFile = _findfirst(searchPath, &findFileData);

    // Print subdirectories
    do {
        const char *fileName = findFileData.name;

        if (strcmp(fileName, ".") != 0 && strcmp(fileName, "..") != 0) {
            // Print subdirectories first
            if (findFileData.attrib & _A_SUBDIR) {
                for (int i = 0; i < depth; i++) {
                    printf(SOURCE_SPACER);
                }

                if (subdirCount > 1 && fileCount == 0) {
                    printf("%s", BRANCH_LEFT_DIR);  // Branch line for first subdir
                } else {
                    printf("%s", BRANCH_LEFT_DIR);  // Last branch for subdir
                }

                setColorByExtension(fileName);
                printf("%s\n", fileName);  // Print directory name
                printf(RESET_COLOR);

                // Recursively print subdirectories (no page peek yet)
                char newPath[MAX_PATH];
                snprintf(newPath, MAX_PATH, "%s\\%s", path, fileName);
                printDirectoryTree(newPath, depth + 1, pageLimit);
                fileCount++;
            }
        }
    } while (_findnext(hFile, &findFileData) == 0);

    // Print the other files (after subdirs)
    _findclose(hFile);
    hFile = _findfirst(searchPath, &findFileData);

    do {
        const char *fileName = findFileData.name;

        if (strcmp(fileName, ".") != 0 && strcmp(fileName, "..") != 0) {
            if (!(findFileData.attrib & _A_SUBDIR)) {  // Only files, not directories
                if (printedFiles < pageLimit) {
                    for (int i = 0; i < depth; i++) {
                        printf(SOURCE_SPACER);
                    }

                    if (printedFiles == 0) {
                        printf("%s", BRANCH_LEFT_ROOT);  // Branch line for files
                    } else if (printedFiles == pageLimit - 1) {
                        printf("%s", BRANCH_LEFT_END);  // Last file
                    } else {
                        printf("%s", BRANCH_LEFT_ROOT);  // Branch line for files
                    }

                    setColorByExtension(fileName);
                    printf("%s\n", fileName);  // Print the file name
                    printf(RESET_COLOR);
                }
                printedFiles++;
            }
        }
        if(depth > 1){break;}
    } while (_findnext(hFile, &findFileData) == 0);

    if(depth == 0){
        printf("%s\n", SOURCE_END);
    } else {
        for (int i = 0; i < depth-1; i++) {
            printf(SOURCE_SPACER);
        }
        printf("%s\n", SUBDIR_END);
    }
    
    _findclose(hFile);
}

int main() {
    // Test the printDirectoryTree function with a page limit
    printDirectoryTree(".", 0, 10);  // Adjust pageLimit to the number of files to list
    return 0;
}
