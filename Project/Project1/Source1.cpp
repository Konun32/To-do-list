#include <iostream>
#include <vector>
#include <string>
#include <ctime>

struct Task {
    std::string name;
    time_t deadline;
};

std::vector<Task> tasks;

void addTask(const std::string& name, time_t deadline) {
    Task newTask = { name, deadline };
    tasks.push_back(newTask);
}

void printTasks() {
    std::cout << "===== To-Do List =====" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].name << " - Deadline: " << asctime(localtime(&tasks[i].deadline));
    }
    std::cout << "======================" << std::endl;
}

void removeTask(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed successfully." << std::endl;
    }
    else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    char choice;
    do {
        std::cout << "Select an option:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Print Tasks\n";
        std::cout << "3. Remove Task\n";
        std::cout << "Q. Quit\n";
        std::cin >> choice;

        std::string name;
        time_t deadline;

        switch (choice) {
        case '1':
            std::cout << "Enter task name: ";
            std::cin >> name;
            std::cout << "Enter deadline (use timestamp): ";
            std::cin >> deadline;
            addTask(name, deadline);
            break;
        case '2':
            printTasks();
            break;
        case '3':
            int index;
            std::cout << "Enter the task number to remove: ";
            std::cin >> index;
            removeTask(index);
            break;
        case 'Q':
        case 'q':
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'q' && choice != 'Q');

    return 0;
}
