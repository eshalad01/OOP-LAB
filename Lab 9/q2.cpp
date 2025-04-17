#include <iostream>
#include <vector>
#include <string>

class Logger {
private:
    std::vector<std::string> logs;
    const size_t maxLogs = 1000;

    void storeLog(const std::string& message) {
        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin());
        }
        logs.push_back(message);
    }

    friend class Auditor;
    std::vector<std::string> getLogs() const {
        return logs;
    }

public:
    void logInfo(const std::string& message) {
        storeLog("INFO: " + message);
    }

    void logWarning(const std::string& message) {
        storeLog("WARN: " + message);
    }

    void logError(const std::string& message) {
        storeLog("ERROR: " + message);
    }
};

class Auditor {
private:
    std::string password;

    bool authenticate(const std::string& inputPwd) const {
        return inputPwd == password;
    }

public:
    Auditor(const std::string& pwd) : password(pwd) {}

    void retrieveLogs(const Logger& logger, const std::string& inputPwd) const {
        if (authenticate(inputPwd)) {
            std::vector<std::string> logs = logger.getLogs();
            std::cout << "--- Retrieved Logs ---" << std::endl;
            for (const auto& log : logs) {
                std::cout << log << std::endl;
            }
        } else {
            std::cout << "Access denied: Authentication failed." << std::endl;
        }
    }
};

int main() {
    Logger logger;

    logger.logInfo("Network module initialized.");
    logger.logWarning("Database connection slow.");
    logger.logError("Failed to retrieve user data.");
    Auditor auditor("admin123");
    auditor.retrieveLogs(logger, "wrongpass");
    auditor.retrieveLogs(logger, "admin123");

    return 0;
}

