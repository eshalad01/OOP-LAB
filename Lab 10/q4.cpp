#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

class Logger {
private:
    ofstream logFile;
    const string baseFileName = "log";
    const string fileExtension = ".txt";
    const size_t maxFileSize = 1024 * 1024;
    size_t currentFileIndex = 1;

public:
    Logger() {
        openNewLogFile();
    }

    ~Logger() {
        logFile.close();
    }

    void log(const string& message) {
        if (logFile.tellp() >= maxFileSize) {
            rotateLogFile();
        }
        logFile << message << endl;
    }

private:
    void openNewLogFile() {
        string fileName = baseFileName + to_string(currentFileIndex) + fileExtension;
        logFile.open(fileName, ios::out | ios::app);
    }

    void rotateLogFile() {
        logFile.close();
        currentFileIndex++;
        openNewLogFile();
    }
};

int main() {
    Logger logger;
    for (int i = 0; i < 10000; ++i) {
        logger.log("This is log message number " + to_string(i));
    }
    return 0;
}

