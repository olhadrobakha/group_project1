#include <iostream>
#include <string>
using namespace std;
struct User {
	string name;
	string forname;
	int id;
	string email;
};
struct Task{
	
};
struct Category {

};
Task* newTask(string title, string description, string deadline, int priority, bool done, enum type, User user) {
	Task* task = new Task;
	task->title = title;
	task->description = description;
	task->deadline = deadline;
	task->priority = priority;
	task->done = done;
	task->type = type;
	task->user = user;
	return task;
}

Task** createTaskArray(int size,int taskCount,enum type, User user) {
	Task** arr = new Task * [size];
	
	for (int i = 0; i < taskCount; ++i) {
		for (int i = 0; i < taskCount && i < size; ++i) {
			string title, description, deadline, type;
			int priority;
			bool done = false;

			cout << "Enter task title #" << i + 1 << ": ";
			cin.ignore();
			getline(cin, title);

			cout << "Enter description: ";
			getline(cin, description);

			cout << "Enter deadline: ";
			getline(cin, deadline);

			cout << "Do you want to add one more task?(1-yes,2-no):" << endl;
			int option;
			cin >> option;


			arr[i] = newTask(title, description, deadline, taskCount, done, type, user);
			if (option == 2) {
				break;
			}
		}
		return arr;
	}
void deleteTaskAt(Task * *arr, int& taskCount, int index) {
		if (index < 0 || index >= taskCount) {
			cout << "Invalid index to delete!"<<endl;
			return;
		}
		delete arr[index];

		for (int i = index; i < taskCount - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		arr[taskCount - 1] = nullptr; 
		taskCount--; 
	}
void searchByPriority(Task** arr, int taskCount, int priority) {
	cout << "Tasks with such priority: " << priority << ":\n";
	bool found = false;
	for (int i = 0; i < taskCount; ++i) {
		if (arr[i]->priority == priority) {
			cout << i + 1 << ". " << arr[i]->title << " | Deadline: " << arr[i]->deadline << endl;
			found = true;
		}
	}
	if (!found) cout << "Not found"<<endl;
}
void searchByDeadline(Task** arr, int taskCount, const string& deadline) {
	cout << "Tasks with such deadline: " << deadline << ":"<<endl;
	bool found = false;
	for (int i = 0; i < taskCount; ++i) {
		if (arr[i]->deadline == deadline) {
			cout << i + 1 << ". " << arr[i]->title << " | Priority: " << arr[i]->priority << endl;
			found = true;
		}
	}
	if (!found) cout << "Not found" << endl;
}
void searchByUser(Task** arr, int taskCount, int userId) {
	cout << "Tasks with such ID = " << userId << ":"<<endl;
	bool found = false;
	for (int i = 0; i < taskCount; ++i) {
		if (arr[i]->user.id == userId) {
			cout << i + 1 << ". " << arr[i]->title << " | Deadline: " << arr[i]->deadline << endl;
			found = true;
		}
	}
	if (!found) cout << "Not found" << endl;
}

void main()
{
	int id = 1;
	User user;
	user.id = id;
	id++;
	const int maxTasks = 100;
	int tasksCount = 0;
	

	cout << "Choice an option: 1-add task, 2-delete task, 3-mark done, 4-search by priority, 5-search by deadline, 6-search by ID" << endl;
	switch (option) {
	case 1:
		Task * *tasks = createTaskArray(maxTasks, tasksCount);
		tasksCount++;
		break;
	case 2:
		int index;
		cout << "Enter the index of the task to delete: ";
		cin >> index;
		deleteTaskAt(tasks, taskCount, index);
		break;
	}
	case 3:
		int num;
		cout << "Enter the index of the task to mark as done: ";
		cin >> num;
		if (num < 0 || num >= tasksCount) {
			cout << "Invalid task index!" << endl;
		}
		else {
			tasks[num]->done = true;
			cout << "Task #" << num << " marked as done." << endl;
		}
		break;
	case 4:
		int priority;
		cout << "Enter the priority to search for: ";
		cin >> priority;
		searchByPriority(tasks, tasksCount, priority);
		break;
	case 5:
		string deadline;
		cout << "Enter the deadline to search for: ";
		cin.ignore();
		getline(cin, deadline);
		searchByDeadline(tasks, tasksCount, deadline);
		break;
	case 6:
		int userId;
		cout << "Enter the user ID to search for: ";
		cin >> userId;
		searchByUser(tasks, tasksCount, userId);
		break;

}
