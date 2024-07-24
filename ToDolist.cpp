#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(const string& description) : description(description), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    void markPending() {
        completed = false;
    }

    string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

private:
    string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
        } else {
            cerr << "Invalid task index" << endl;
        }
    }

    void markTaskPending(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markPending();
        } else {
            cerr << "Invalid task index" << endl;
        }
    }

    void viewTasks() const {
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getDescription()
                      << " [" << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]" << endl;
        }
    }

private:
    vector<Task> tasks;
};

void showMenu() {
    cout << "To-Do List Application" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Mark Task as Completed" << endl;
    cout << "3. Mark Task as Pending" << endl;
    cout << "4. View Tasks" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() {
    ToDoList todoList;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear the newline character from the buffer
                cout << "Enter the task description: ";
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2: {
                cout << "Enter the task number to mark as completed: ";
                int taskNumber;
                cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber - 1);
                break;
            }
            case 3: {
                cout << "Enter the task number to mark as pending: ";
                int taskNumber;
                cin >> taskNumber;
                todoList.markTaskPending(taskNumber - 1);
                break;
            }
            case 4:
                todoList.viewTasks();
                break;
            case 5:
                return 0;
            default:
                cerr << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
