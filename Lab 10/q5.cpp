#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void addTask(const string& task) {
    if (task.empty()) {
        cout << "Task cannot be empty!" << endl;
        return;
    }

    ofstream file("tasks.txt", ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    file << task << endl;
    file.close();
}

void viewTasks() {
    ifstream file("tasks.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string task;
    int taskNumber = 1;
    while (getline(file, task)) {
        cout << taskNumber++ << ". " << task << endl;
    }
    file.close();
}

void markTaskAsDone(int taskNumber) {
    ifstream file("tasks.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    vector<string> tasks;
    string task;
    while (getline(file, task)) {
        tasks.push_back(task);
    }
    file.close();

    if (tasks.empty()) {
        cout << "No tasks to mark as done." << endl;
        return;
    }

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1] += " [Done]";
        ofstream outFile("tasks.txt");
        if (!outFile) {
            cerr << "Error opening file!" << endl;
            return;
        }

        for (const auto& t : tasks) {
            outFile << t << endl;
        }
        outFile.close();
    } else {
        cout << "Invalid task number. Please try again." << endl;
    }
}

int main() {
    int choice;
    string task;
    do {
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                addTask(task);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                int taskNumber;
                cout << "Enter task number to mark as done: ";
                cin >> taskNumber;
                markTaskAsDone(taskNumber);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

