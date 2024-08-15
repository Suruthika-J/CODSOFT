#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;

    Task(string desc) : description(desc) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << endl;
        }
    }

    void deleteTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        cout << "Task deleted: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + (index - 1));
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string description;
    int index;

    while (true) {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter task description: ";
            cin.ignore(); // To ignore the newline character left by cin
            getline(cin, description);
            todoList.addTask(description);
            break;
        case 2:
            todoList.viewTasks();
            break;
        case 3:
            cout << "Enter task number to delete: ";
            cin >> index;
            todoList.deleteTask(index);
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
