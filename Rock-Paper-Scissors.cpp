#include <iostream>
#include <string>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;
void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
int askuser(string message) {
	int n;
	cout << message << endl;
	cin >> n;
	return n;
}
int randomchoicecomp(int from, int to) {
	int random = rand() % (to - from + 1) + from;
	return random;
}

void  check(int yourchoice, int compchoice, int c, int& howtimecomp, int& howtimesplayer, int& tied) {
	cout << "--------------------Round[" << c << "]------------------\n";
	string choice1[] = { "rock","scissors","paper" };
	cout << "your choice is:" << choice1[yourchoice - 1] << endl;
	cout << "computer choice is:" << choice1[compchoice - 1] << endl;
	if (compchoice == yourchoice) {
		system("color 6F");
		cout << "round winner:[no one]\n";
		cout << "----------------------------------------------\n";
		tied++;
	}
	else if ((compchoice == 2 && yourchoice == 3) || (compchoice == 1 && yourchoice == 2) || (compchoice == 3 && yourchoice == 1)) {
		system("color 4F");
		cout << "round winner:[computer]\n\a";
		cout << "----------------------------------------------\n";
		howtimecomp++;
	}
	else
	{
		system("color 2A");
		cout << "round winner:[player1]\n";
		cout << "----------------------------------------------\n";
		howtimesplayer++;
	}

}
void choose(int n) {
	int choice;
	int howtimecomp = 0, howtimesplayer = 0, tied = 0;
	for (int i = 1; i <= n; i++)
	{
		cout << "round[" << i << "] begain:\n";
		do {
			cout << "enter your choice (1)rock,(2)scissors,(3)paper:";
			cin >> choice;
		} while (choice > 3||choice<1);

		int compchoice = randomchoicecomp(1, 3);
		check(choice, compchoice, i, howtimecomp, howtimesplayer, tied);
	}
	cout << "---------------------------------\n";
	cout << "        +++Game over+++\n";
	cout << "---------------------------------\n";
	cout << " -----------------[Game result]---------\n";
	cout << "Game round:      " << n << endl;
	cout << "player won times: " << howtimesplayer << endl;
	cout << "computer won times:" << howtimecomp << endl;
	cout << "Draw times:      " << tied << endl;
	if (howtimesplayer > howtimecomp) {
		system("color 2A");
		cout << "the final winner is: player\n";
		
	}
	else if (howtimesplayer < howtimecomp) {
		system("color 4F");
		cout << "the final winner is: computer\n";
		
	}
	else {
		cout << "the final winner is: no one\n";
		system("color 6F");
	}
}
void conti(int n) {
	char m;
	do {
		clearScreen();
		choose(n);
		cout << "do you want to play again ?Y/N?\n";
		cin >> m;
		if (m == 'Y' || m == 'y') {
			clearScreen();
			system("color 0F");
			n = askuser("enter how many round you want to play from 1:10");


		}
	} while (m != 'n' && m != 'N');

}
int main() {
	srand((unsigned)time(NULL));
	int n;
	n = askuser("enter how many round you want to play from 1:10");
	while (n < 1 || n>10) {
		n = askuser("enter how many round you want to play from 1:10");
	}
	conti(n);
	return 0;
}