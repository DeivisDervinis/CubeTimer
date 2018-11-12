// Cube Timer By Deivis Dervinis

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

struct node {
	string time;
	node *next;
};

class TimeList {
private:
	node * head, *tail;

public:
	TimeList() {
		head = NULL;
		tail = NULL;
	}

	// Creates nodes
	void createNode(string val) {
		node *temp = new node;
		temp->time = val;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	// Display all nodes
	void display()
	{
		node *temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->time << "\t";
			temp = temp->next;
		}
	}

	// Inserts at the start
	void insert_start(string value)
	{
		node *temp = new node;
		temp->time = value;
		temp->next = head;
		head = temp;
	}
};

class User {
public:
	// Field variables
	string name;
	string lname;
	int ID;

	TimeList times;

	// Default constructor
	User() {
		name = "Default";
		lname = "Default";
		ID = 0;
	}

	User(string name) {
		this->name = name;
	}


	// Accessors and mutators for variables
	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setLName(string lname) {
		this->lname = lname;
	}

	string getLName() {
		return lname;
	}

	void setID(int ID) {
		this->ID = ID;
	}

	int getID() {
		return ID;
	}
};

// Method that starts the timer
string startTimer() {
	cout << "Hit 'SPACE' to stop timer" << endl;
	cin.get();

	unsigned short miliseconds = 0;
	unsigned short seconds = 0;
	unsigned short minutes = 0;

	while (!GetAsyncKeyState(0x20)) {
		miliseconds++;
		//system("CLS");
		cout << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << ":" << setfill('0') << setw(2) << miliseconds << std::endl;
		Sleep(8);
		if (miliseconds == 100) {
			miliseconds = 0;
			seconds++;
		}

		if (seconds == 60) {
			seconds = 0;
			minutes++;
		}
		//cout << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << ":" << setfill('0') << setw(2) << miliseconds << std::endl;
	}
	system("CLS");
	cout << "Your time: " << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << ":" << setfill('0') << setw(2) << miliseconds << std::endl;
	cout << "Press ENTER to continue" << endl;
	string s = to_string(minutes) + ":" + to_string(seconds) + ":" + to_string(miliseconds);
	return s;
}

string createUser(string name, string lname, int ID, User user) {
	user.setName(name);
	user.setLName(lname);
	user.setID(ID);
}

string displayUser(User user) {
	cout << user.getID() << endl;
	cout << user.getName() << endl;
	cout << user.getName()<< endl;
}

int main()
{
	int chvar;
	bool usrFlag = false;
	int usrID = 0;
	User user;

	while (1) {
		cout << "Simple Cube Timer Made By Deivis Dervinis" << endl;
		cout << "Choose one of the following options:" << endl;
		cout << "# 1. Start a timer" << endl;
		cout << "# 2. Times" << endl;
		cout << "# 3. User Settings" << endl;
		cout << "# 4. Create a user" << endl;
		cout << "# 5. Exit" << endl;

		cout << "Enter your option:" << endl;
		cin >> chvar;

		switch (chvar) {
		case 1: {
			// When user clicks here
			// option 1 start a timer with a button click
			// option 2 start a timer when selection is chosen

			// When selection is chosen
			/* Starts a timer
			When user presses any button again, the timer stops
			creates the new node, gives the data
			saves it to the start of the list*/
			cout << "Push any button to start " << endl;
			cout << startTimer() << endl;
			break;
		}

		case 2: {
			// Do Code
			break;
		}

		case 3: {
			// Code for user settings
			if (usrFlag) {
				// User already exists
			}
			else {
				// User doesn't exist
				cout << "Enter your first name: " << endl;
				string name;
				cin >> name;

				cout << "Enter your last name: " << endl;
				string lname;
				cin >> lname;

				usrID++;



				createUser(name, lname, usrID, user);
				displayUser(user);
			}
			break;
		}

		case 4: {
			// Creates a user
			string username;
			cout << "Enter your name: " << endl;
			cin >> username;
			user.setName(username);
			cout << user.name << " successfully created!" << endl;
			break;
		}

		case 5: {
			// Exits the program
			exit(0);
			break;
		}

		default: {
			// Wrong choice
			break;
		}
		}

		cin.get();
	}

	return 0;
}

