// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// C++ программа to do list
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Определение класса задач
class Task {
private:
    string name; // Название задачи
    string description; // Описание задачи
    string dueDate; // Дата задачи
    bool completed; // Статус выполнения

public:
    // Конструктор для инициализации задачи
    Task(const string& name, const string& description,
        const string& dueDate)
        : name(name)
        , description(description)
        , dueDate(dueDate)
        , completed(false)
    {
    }

    // Средство получения имени задачи
    string getName() const { return name; }

    // Средство получения описания задачи
    string getDescription() const { return description; }

    // Средство получения даты задачи
    string getDueDate() const { return dueDate; }

    // Средство получения статуса выполнения задачи
    bool isCompleted() const { return completed; }

    // Средство настройки имени задачи
    void setName(const string& name) { this->name = name; }

    // Средство настройки описания задачи
    void setDescription(const string& description)
    {
        this->description = description;
    }

    // Средство настройки даты задачи
    void setDueDate(const string& dueDate)
    {
        this->dueDate = dueDate;
    }

    // Отметьте задачу как выполненную
    void markCompleted() { completed = true; }

    // Отображение сведений о задаче
    void displayTask() const
    {
        cout << name << " ("
            << (completed ? "Completed" : "Pending")
            << ") - Due: " << dueDate << endl
            << "   Description: " << description << endl;
    }
};

// Определить класс ToDoList
class ToDoList {
private:
    vector<Task> tasks; // Список задач

public:
    // Отобразить меню
    void displayMenu()
    {
        cout
            << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Edit Task\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------"
            "\n";
    }

    // Добавление новой задачи
    void addTask()
    {
        string name, description, dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, dueDate);

        tasks.emplace_back(name, description, dueDate);
        cout << "Task added successfully!" << endl;
    }

    // Удаление задачи
    void deleteTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                << endl;
        }
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    // Отобразить все задачи
    void displayTasks()
    {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    // Отметьте задачу как выполненную
    void markTaskCompleted()
    {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!"
                << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                << endl;
        }
        cout << "Enter the task number to mark as "
            "completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    // Редактировать задачу
    void editTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                << endl;
        }
        cout << "Enter the task number to edit: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            Task& task = tasks[taskNumber - 1];
            string name, description, dueDate;
            cout << "Enter new task name (current: "
                << task.getName() << "): ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new task description (current: "
                << task.getDescription() << "): ";
            getline(cin, description);
            cout << "Enter new task due date (current: "
                << task.getDueDate() << "): ";
            getline(cin, dueDate);

            task.setName(name);
            task.setDescription(description);
            task.setDueDate(dueDate);
            cout << "Task updated successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    // Запустите приложение "список дел"
    void run()
    {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                markTaskCompleted();
                break;
            case 5:
                editTask();
                break;
            case 6:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!"
                    << endl;
            }
        } while (choice != 6);
    }
};

// Главная функция
int main()
{
    // Создайте объект списка дел и запустите приложение
    ToDoList toDoList;
    toDoList.run();
    return 0;
}





// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
