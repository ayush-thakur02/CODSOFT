// Task 4 (TO-DO LIST)
// Build a simple console-based to-do list manager that allows users to add, view, and delete tasks -
// Task Input: Allow users to input tasks they want to add to the list.
// Add Task: Implement a function to add tasks to the list.
// View Tasks: Display the list of tasks with their status (completed or pending).
// Mark Task as Completed: Allow users to mark tasks as completed.
// Remove Task: Provide an option to remove tasks from the list.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void AddTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view the list of tasks
void ViewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void MarkTaskAsCompleted(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void RemoveTask(vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    string description; // Move the declaration outside the switch statement

    while (true) {
        cout << "===== To-Do List Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // Clear newline character from previous input
                getline(cin, description);
                AddTask(tasks, description);
                break;
            case 2:
                ViewTasks(tasks);
                break;
            case 3:
                ViewTasks(tasks);
                cout << "Enter the task index to mark as completed: ";
                int markIndex;
                cin >> markIndex;
                MarkTaskAsCompleted(tasks, markIndex);
                break;
            case 4:
                ViewTasks(tasks);
                cout << "Enter the task index to remove: ";
                int removeIndex;
                cin >> removeIndex;
                RemoveTask(tasks, removeIndex);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
