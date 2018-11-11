// CubeTimer.cpp : Defines the entry point for the console application.
//

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
	string name;
	TimeList times;

	User() {
		name = "Default";
	}

	User(string name) {
		this->name = name;
	}

	void setName(string name) {
		this->name = name;
	}
};

void startTimer() {
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
}



int main()
{
	int chvar;
	User user;

	while (1) {
		cout << "Simple Cube Timer Made By Deivis Dervinis" << endl;
		cout << "Choose one of the following options:" << endl;
		cout << "1. Start a timer" << endl;
		cout << "2. Times" << endl;
		cout << "3. User Settings" << endl;
		cout << "4. Create a user" << endl;
		cout << "5. Exit" << endl;

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
			int isTimer = 0;
			startTimer();
			break;
		}

		case 2: {
			// Do Code
			break;
		}

		case 3: {
			// Do Code
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
			// Exit
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

