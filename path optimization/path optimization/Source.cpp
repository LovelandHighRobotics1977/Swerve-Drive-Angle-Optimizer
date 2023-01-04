#include<iostream>

using namespace std;

int main() {
	int desired;
	int current;
	int direction = 1;



	cout << "Enter current angle: ";
	cin >> current;
	cout << endl;
	cout << "Enter desired angle: ";
	cin >> desired;
	cout << endl;



	int angle1 = (desired - (current % 4096));
	int angle2 = ((2048 - abs(desired % 4096)) + (2048 - abs(current % 4096)));
	int shortest;
	int check1;
	

	if (abs(angle1) <= abs(angle2)) {
		shortest = angle1;
		check1 = false;
	}
	else {
		shortest = angle2;
		check1 = true;
	}

	angle1 = ((desired - 2048) - (current % 4096));
	angle2 = ((2048 - (abs(desired % 4096)-2048)) + (2048 - (abs(current % 4096))));
	

	int shortest2;
	bool check2;
	if (abs(angle2) < abs(angle1)) {
		shortest2 = angle2;
		check2 = true;
	}
	else {
		shortest2 = angle1;
		check2 = false;
	}

	//cout << "1: " << shortest << " 2: " << shortest2 << endl;
	if (abs(shortest) <= abs(shortest2)) {
		if (check1 == true) {
			if (current < 0) {
				current -= shortest;
			}
			else {
				current += shortest;
			}
		}
		else {
			current += shortest;
		}
	}
	else {
		direction = -1;
		if (check2 == true) {
			if (current < 0) {
				current -= shortest2;
			}
			else {
				current += shortest2;
			}
		}
		else {
			current += shortest2;
		}
	}

	cout << "Final angle: " << current << " Direction: " << direction << endl;
	system("pause");
	system("CLS");
	main();
}