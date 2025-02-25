#pragma once
#include "program.h"
#include "Graph.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void prog() {
	cout << "Welcome to our social network!" << endl;

	int n;
	int f = 0;
	do {
		cout << "Choose what you want to do: " << endl;
		cout << "1 - enter dating pairs." << endl;
		if (f != 0)
			cout << "2 - output all dating pairs through 3 handshakes" << endl;

		cout << "0 - complete the program." << endl;
		cout << "Your chose: ";
		cin >> n;
		if (n == 0) {
			break;
		}
		switch (n)
		{
		case 1:
		{
			cout << "Enter the name of the person (who knows) and the name of the person (whom he knows), separated by a space." << endl;
			string names;
			cin.ignore();
			getline(cin, names);
			string st1;
			string st2;
			int flag = 0;
			for (int i = 0; i < names.size(); i++) {
				if (names[i] == ' ') continue;
				if (flag == 0) st1 += names[i];
				else st2 += names[i];
			}

		}
		default:
			break;
		}

	} while (n != 0);

}