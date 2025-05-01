#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>  // For atoi()

using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int yearsOfService;
};

// Writes dummy employee data to the file
void writeDummyData() {
    ofstream outFile("employees.txt");
    if (!outFile) {
        cerr << "Error writing to file.\n";
        return;
    }

    outFile << "1,John Doe,Manager,3\n";
    outFile << "2,Jane Smith,Developer,1\n";
    outFile << "3,Bob Johnson,Manager,2\n";
    outFile << "4,Alice Brown,Designer,5\n";
    outFile.close();
}

// Reads data from file into vector of Employee
vector<Employee> readData() {
    ifstream inFile("employees.txt");
    vector<Employee> employees;
    string line;

    while (getline(inFile, line)) {
        char buffer[200];
        strcpy(buffer, line.c_str());

        char* token = strtok(buffer, ",");
        if (!token) continue;

        Employee emp;
        emp.id = atoi(token);

        token = strtok(nullptr, ",");
        emp.name = token;

        token = strtok(nullptr, ",");
        emp.designation = token;

        token = strtok(nullptr, ",");
        emp.yearsOfService = atoi(token);

        employees.push_back(emp);
    }

    inFile.close();
    return employees;
}

// Filters only managers with 2+ years of service
vector<Employee> findManagersWithService(const vector<Employee>& employees) {
    vector<Employee> result;
    for (const Employee& emp : employees) {
        if (emp.designation == "Manager" && emp.yearsOfService >= 2) {
            result.push_back(emp);
        }
    }
    return result;
}

// Overwrites file with filtered data, incrementing ID and years
void writeUpdatedData(const vector<Employee>& managers) {
    ofstream outFile("employees.txt");
    if (!outFile) {
        cerr << "Error writing to file.\n";
        return;
    }

    for (const Employee& emp : managers) {
        outFile << (emp.id + 1) << "," 
                << emp.name << "," 
                << emp.designation << "," 
                << (emp.yearsOfService + 1) << "\n";
    }

    outFile.close();
}

int main() {
    // a) Write initial dummy data
    writeDummyData();

    // b) Read all data into vector
    vector<Employee> employees = readData();

    // c) Filter: Manager with >=2 years
    vector<Employee> managers = findManagersWithService(employees);

    // d) Overwrite file with updated filtered data
    writeUpdatedData(managers);

    cout << "Filtered and updated data written to file.\n";
    return 0;
}

