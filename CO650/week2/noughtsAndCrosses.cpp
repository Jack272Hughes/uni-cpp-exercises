#include <iostream>
#include <numeric>
#include <array>
using namespace std;

const char PLAYER_1 = 'O';
const char PLAYER_2 = 'X';

const int winLength = 3;
const int boardLength = 3;
const int boardHeight = 3;
const int boardSize = boardHeight * boardLength;
char board[boardSize];

void initialise() {
	srand(time(0));
	for (int index = 0; index < boardSize; index++) {
		board[index] = '-';
	}
}

int getBoardIndex(int x, int y) {
	return (y * boardLength) + x;
}

void display() {
	for (int y = 0; y < boardLength; y++) {
		for (int x = 0; x < boardHeight; x++) {
			const int boardIndex = getBoardIndex(x, y);
			cout << board[boardIndex] << "\t";
		}
		cout << "\n" << endl;
	}
	cout << "\n" << endl;
}

void setValue(int x, int y, char symbol) {
	board[getBoardIndex(x, y)] = symbol;
}

bool isFree(int x, int y) {
	return board[getBoardIndex(x, y)] == '-';
}

int getRandom(int range) {
	return rand() % range;
}

int calculateStep(int start, int end) {
	const int difference = end - start;
	if (difference < 0) return -1;
	if (difference > 0) return 1;
	return 0;
}

int countSquareForPlayer(const int count, int x, int y, char player) {
	const int boardIndex = getBoardIndex(x, y);
	return board[boardIndex] == player ? count + 1 : 0;
}

bool countLineOfSquaresForPlayer(int startX, int endX, int startY, int endY, char player) {
	int xStep = calculateStep(startX, endX);
	int yStep = calculateStep(startY, endY);

	int currentX = startX - xStep;
	int currentY = startY - yStep;
	
	int count = 0;
	while (currentX < endX || currentY < endY) {
		currentX += xStep;
		currentY += yStep;

		count = countSquareForPlayer(count, currentX, currentY, player);
		{
			if (count >= winLength) return true;
		}
	}

	return false;
}

// array<int, 2>
bool hasWon(char player, int x, int y) {
	const int maxSquares = winLength - 1;

	// Check the row
	const int rowStartX = max(x - maxSquares, 0);
	const int rowEndX = min(x + maxSquares, boardLength - 1);
	if (countLineOfSquaresForPlayer(rowStartX, rowEndX, y, y, player)) {
		return true;
	}

	// Check the column
	const int columnStartY = max(y - maxSquares, 0);
	const int columnEndY = min(y + maxSquares, boardHeight - 1);
	if (countLineOfSquaresForPlayer(x, x, columnStartY, columnEndY, player)) {
		return true;
	}

	// Check diagonal from top-left to bottom-right
	const int leftDiagonalStartLength = min(x - rowStartX, y - columnStartY);
	const int leftDiagonalEndLength = min(rowEndX - x, columnEndY - y);
	if (countLineOfSquaresForPlayer(x - leftDiagonalStartLength, x + leftDiagonalEndLength, y - leftDiagonalStartLength, y + leftDiagonalEndLength, player)) {
		return true;
	}

	// Check diagonal from top-right to bottom-left
	const int rightDiagonalStartLength = min(rowEndX - x, y - columnStartY);
	const int rightDiagonalEndLength = min(x - rowStartX, columnEndY - y);
	if (countLineOfSquaresForPlayer(x + rightDiagonalStartLength, x - rightDiagonalEndLength, y - rightDiagonalStartLength, y + rightDiagonalEndLength, player)) {
		return true;
	}

	return false;
}

int main() {
	bool gameOver = false;
	char currentPlayer = PLAYER_1;

	initialise();
	display();

	int turns = 0;
	while (!gameOver) {
		int selectedX = 0;
		int selectedY = 0;
		do {
			selectedX = getRandom(boardLength);
			selectedY = getRandom(boardHeight);
		} while (!isFree(selectedX, selectedY));
		setValue(selectedX, selectedY, currentPlayer);

		turns++;
		gameOver = turns == boardSize || hasWon(currentPlayer, selectedX, selectedY);

		currentPlayer = currentPlayer == PLAYER_1 ? PLAYER_2 : PLAYER_1;

		display();
	}
}
