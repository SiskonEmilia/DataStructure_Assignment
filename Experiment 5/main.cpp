#include "tree.hpp"
#include <string>
using namespace std;

BTree myTree;

void Append() {
	int temp;
	cout << "Type in a number you want to append to the tree:" << endl;
	cin >> temp;
	getchar();
	myTree.append(temp);
	cout << "Succeed!" << endl
		<< "Press enter to return to menu." << endl;
	getchar();
}

void Interchange() {
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 4ebc7e3266e4ab183be55ea476de384f0d3f1bcb
=======
>>>>>>> 4ebc7e3266e4ab183be55ea476de384f0d3f1bcb
	myTree.interChange();
	cout << "Succeed!" << endl
		<< "Press enter to return to menu." << endl;
	getchar();
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 4ebc7e3266e4ab183be55ea476de384f0d3f1bcb
=======
  myTree.interChange();
  cout << "Succeed!" << endl
    << "Press enter to return to menu." << endl;
  getchar();
>>>>>>> 935c65811446b7edfdc2fbc6613233f501e05660
<<<<<<< HEAD
>>>>>>> 4ebc7e3266e4ab183be55ea476de384f0d3f1bcb
=======
>>>>>>> 4ebc7e3266e4ab183be55ea476de384f0d3f1bcb
}

void Print(unsigned position = 0) {
	if (position != 1) {
		int temp;
		while (1) {
			cout << "Please type in the id of the subtree's root node." << endl;
			cin >> temp;
			getchar();
			position = temp;
			if (temp <= 0) {
				cout << "We need a positive number to find your subtree." << endl
					<< "Press enter to try again." << endl;
				getchar();
			}
			else
				break;
		}
	}
	myTree.print(position);
	cout << "Press enter to return to menu." << endl;
	getchar();
}

void Get() {
	int temp;
	while (1) {
		cout << "Please type in the id of the node." << endl;
		cin >> temp;
		getchar();
		if (temp <= 0) {
			cout << "We need a positive number to find your data." << endl
				<< "Press enter to try again." << endl;
			getchar();
		}
		else
			break;
	}

	if (temp > myTree.size())
		cout << "This number is larger than the size of the tree, we will print nothing for you." << endl;
	else
		cout << myTree[temp] << endl;
	cout << "Press enter to return to menu." << endl;
	getchar();
}

int main() {
	string input;
	while (1) {
		cout
			<< "                Menu                " << endl // 26 words per line
			<< "------------------------------------" << endl
			<< "a. Append an element to the tree." << endl
			<< "b. Interchange subtrees." << endl
			<< "c. Print the tree." << endl
			<< "d. Print a subtree with id." << endl
			<< "e. Get an element through the id of node." << endl
			<< "q. Quit." << endl
			<< "Please type in the mark of function you want to use: " << endl;

		cin >> input;
		getchar();
		if (input.length() != 1) {
			cout << "Invalid input!"
				<< "Press enter to try again!" << endl;
			getchar();
		}
		switch (input[0]) {
		case 'a': case 'A':
			Append();
			break;

		case 'b': case 'B':
			Interchange();
			break;

		case 'c': case 'C':
			Print(1);
			break;

		case 'd': case 'D':
			Print();
			break;

		case 'e': case 'E':
			Get();
			break;

		case 'q': case 'Q':
			cout << "Thanks for your using!" << endl;
			return 0;
			break;

<<<<<<< HEAD
=======

		cin >> input;
		getchar();
		if (input.length() != 1) {
			cout << "Invalid input!"
				<< "Press enter to try again!" << endl;
			getchar();
		}
		switch (input[0]) {
		case 'a': case 'A':
			Append();
			break;

		case 'b': case 'B':
			Interchange();
			break;

		case 'c': case 'C':
			Print(1);
			break;

		case 'd': case 'D':
			Print();
			break;

		case 'e': case 'E':
			Get();
			break;

		case 'q': case 'Q':
			cout << "Thanks for your using!" << endl;
			return 0;
			break;

>>>>>>> 4ebc7e3266e4ab183be55ea476de384f0d3f1bcb
=======
>>>>>>> 4ebc7e3266e4ab183be55ea476de384f0d3f1bcb
		default:
			cout << "Invalid input!"
				<< "Press enter to try again!" << endl;
			getchar();
			break;
		}
	}
}
