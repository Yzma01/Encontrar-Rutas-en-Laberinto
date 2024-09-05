#include <iostream>
#include "stack.h"
using namespace std;

bool oneIsUp(int, int, int[7][7]);
bool oneIsRight(int, int, int[7][7]);
bool oneIsDown(int, int, int[7][7]);
bool oneIsLeft(int, int, int[7][7]);
bool validate(int, int, int, int, int[7][7]);
bool recursive(int, int, int, int, int[7][7]);
void iterative(int, int, int, int, int[7][7], Stack*);
bool newRoute(int, int, int[7][7], Stack*);
void returnToIntersecction(int, int, int[7][7], Stack*);

int main() {
	int board[7][7] = {
		{1,1,0,0,0,0,1},
		{0,1,0,0,0,1,0},
		{1,1,1,1,1,1,1},
		{1,0,1,0,1,0,0},
		{1,0,1,0,1,0,0},
		{1,0,1,0,1,1,0},
		{1,0,1,0,0,0,1}
	};
	int boardCopy[7][7] = {
		{1,1,0,0,0,0,1},
		{0,1,0,0,0,1,0},
		{1,1,1,1,1,1,1},
		{1,0,1,0,1,0,0},
		{1,0,1,0,1,0,0},
		{1,0,1,0,1,1,0},
		{1,0,1,0,0,0,1}
	};
	int startRow, startCol = 0;
	cout << "INSERTE LA POSICION X DE ENTRADA: ";
	cin >> startRow;
	cout << "INSERTE LA POSICION Y DE ENTRADA: ";
	cin >> startCol;



	int endRow, endCol = 0;
	cout << "INSERTE LA POSICION X DE ENTRADA: ";
	cin >> endRow;
	cout << "INSERTE LA POSICION Y DE ENTRADA: ";
	cin >> endCol;
	if (validate(startRow, startCol, endRow, endCol, board)) {
		return 0;
	}

	Stack* list = new Stack();
	cout << "Ruta recursiva: " << endl;
	recursive(startRow, startCol, endRow, endCol, boardCopy);
	cout << "Ruta iterativa: " << endl;
	iterative(startRow, startCol, endRow, endCol, board, list);

	return 0;
}

bool oneIsUp(int row, int col, int board[7][7]) {
	row = row - 1;
	if (col >= 0 && board[row][col] == 1) {
		return true;
	}
	return false;
}

bool oneIsRight(int row, int col, int board[7][7]) {
	col = col + 1;
	if (row < 7 && board[row][col] == 1) {
		return true;
	}
	return false;
}

bool oneIsDown(int row, int col, int board[7][7]) {
	row = row + 1;
	if (col < 7 && board[row][col] == 1) {
		return true;
	}
	return false;
}

bool oneIsLeft(int row, int col, int board[7][7]) {
	col = col - 1;
	if (row >= 0 && board[row][col] == 1) {
		return true;

	}
	return false;
}

bool validate(int startRow, int startCol, int endRow, int endCol, int board[7][7]) {
	if (startRow > 6 || startCol > 6 || endRow > 6 || endCol > 6) {
		return true;
	}
	if (board[startRow][startCol] == 0) {
		return true;
	}
	if (board[endRow][endCol] == 0) {
		return true;
	}
	if (startRow == endRow && startCol == endCol) {
		return true;
	}
	if (startRow < 0 || endRow < 0 || startCol < 0 || endCol < 0) {
		return true;
	}
	return false;
}

bool recursive(int startRow, int startCol, int endRow, int endCol, int board[7][7]) {
	if (startRow == endRow && startCol == endCol) {
		cout << '{' << startRow << ',' << startCol << '}' << endl;
		return true;
	}
	bool path = false;
	board[startRow][startCol] = 0;

	if (oneIsUp(startRow, startCol, board)) {
		path = recursive(startRow - 1, startCol, endRow, endCol, board);
		if (path) {
			cout << '{' << startRow << ',' << startCol << '}' << endl;
			return true;
		}
	}
	if (oneIsDown(startRow, startCol, board)) {
		path = recursive(startRow + 1, startCol, endRow, endCol, board);
		if (path) {
			cout << '{' << startRow << ',' << startCol << '}' << endl;
			return true;
		}

	}
	if (oneIsLeft(startRow, startCol, board)) {
		path = recursive(startRow, startCol - 1, endRow, endCol, board);
		if (path) {
			cout << '{' << startRow << ',' << startCol << '}' << endl;
			return true;
		}
	}
	if (oneIsRight(startRow, startCol, board)) {
		path = recursive(startRow, startCol + 1, endRow, endCol, board);
		if (path) {
			cout << '{' << startRow << ',' << startCol << '}' << endl;
			return true;
		}
	}
	board[startRow][startCol] = 1;
	return false;
}

void iterative(int startRow, int startCol, int endRow, int endCol, int board[7][7], Stack* list) {
	list->push(new StackNode(startRow, startCol, true, false));

	while (!list->isEmpty()) {
		StackNode* currentNode = list->peek();
		int currentRow = currentNode->getX();
		int currentCol = currentNode->getY();

		if (currentRow == endRow && currentCol == endCol) {
			list->print();
			return;
		}
		board[currentRow][currentCol] = 0;

		bool moved = false;

		if (oneIsUp(currentRow, currentCol, board)) {
			list->push(new StackNode(currentRow - 1, currentCol, true, false));
			moved = true;
		}
		else if (oneIsDown(currentRow, currentCol, board)) {
			list->push(new StackNode(currentRow + 1, currentCol, true, false));
			moved = true;
		}
		else if (oneIsRight(currentRow, currentCol, board)) {
			list->push(new StackNode(currentRow, currentCol + 1, true, false));
			moved = true;
		}
		else if (oneIsLeft(currentRow, currentCol, board)) {
			list->push(new StackNode(currentRow, currentCol - 1, true, false));
			moved = true;
		}

		if (!moved) {
			list->pop();
		}
	}

	cout << "No se encontró un camino." << endl;
}


void returnToIntersecction(int startRow, int startCol, int board[7][7], Stack* list) {
	while (newRoute(startRow, startCol, board, list)) {
		StackNode* popNode = list->pop();
		startCol = popNode->getY();
		startRow = popNode->getX();
		popNode->setRoute(false);
	}
}

bool newRoute(int row, int col, int board[7][7], Stack* list) {
	//encontrar una casisilla que tenga un 1 cerca col que no hacola sido visitada
	if (oneIsUp(row, col, board) && list->searchNode(row, col - 1) == nullptr) {
		return false;
	}
	if (oneIsRight(row, col, board) && list->searchNode(row + 1, col) == nullptr) {
		return false;
	}
	if (oneIsDown(row, col, board) && list->searchNode(row, col + 1) == nullptr) {
		return false;
	}
	if (oneIsLeft(row, col, board) && list->searchNode(row - 1, col) == nullptr) {
		return false;
	}
	return true;
}
