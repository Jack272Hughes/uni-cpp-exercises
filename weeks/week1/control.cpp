#define TEST true

#include <iostream>
#include <cstdlib>
#include <string>
#include <numeric>

using namespace std;

int main() {
	// Exercise 1
	int scores[100];

	srand(time(0));
	for (int i = 0; i < 100; i++) {
		scores[i] = (rand() % 99) + 1;
	}

	int rangeLimits[4] = { 40, 60, 80, 100 };
	int ranges[4] = { 0, 0, 0, 0 };

	for (int score : scores) {
		for (int rangeIndex = 0; rangeIndex < 4; rangeIndex++) {
			if (score <= rangeLimits[rangeIndex]) {
				ranges[rangeIndex] += 1;
				break;
			}
		}
	}

	for (int index = 0; index < 4; index++) {
		int previousLimit = index == 0 ? 0 : rangeLimits[index - 1];
		cout << "There were " << ranges[index] << " scores of value " << previousLimit << " to " << rangeLimits[index] << endl;
	}

	// Exercise 2
#if TEST == true
	int sum = accumulate(ranges, ranges + 4, 0);
	string testOutcome = sum == 100 ? "successful" : "unsuccessful";
	cout << "Test for if sum of ranges is 100 was " << testOutcome << ". Total ranges was " << sum << endl;
#endif

	// Exercise 3
	enum MovementState {
		STAND,
		WALK,
		RUN,
		CRAWL
	};

	string stateNames[4] = { "stand", "walk", "run", "crawl" };

	MovementState currentState = (MovementState)(rand() % 4);
	cout << "Your current state is " << stateNames[currentState] << " (" << currentState << ")" << endl;

	switch (currentState) {
		case STAND:
			cout << "You can either walk or crawl" << endl;
			break;
		case WALK:
			cout << "You can either stand or run" << endl;
			break;
		case RUN:
			cout << "You can only walk" << endl;
			break;
		case CRAWL:
			cout << "You can only stand" << endl;
			break;
	}



	// Exercise 4
	for (int move = 0; move < 10; move++) {
		switch (currentState) {
		case STAND:
			currentState = rand() % 2 == 0 ? WALK : CRAWL;
			break;
		case WALK:
			currentState = rand() % 2 == 0 ? STAND : RUN;
			break;
		case RUN:
			currentState = WALK;
			break;
		case CRAWL:
			currentState = STAND;
			break;
		}

		cout << "Your current state is now " << stateNames[currentState] << " (" << currentState << ")" << endl;
	}
}
