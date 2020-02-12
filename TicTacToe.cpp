#include <iostream>

using namespace std;

enum class TileFill {Empty, X, O};

struct Location {
	int col;
	int row;
};

void CreateBoard(TileFill board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = TileFill::Empty;
		}
	}
}

void DisplayBoard(TileFill board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch(board[i][j]) {
				case TileFill::Empty:
					cout << "| ";
					break;
				case TileFill::X:
					cout << "|X";
					break;
				case TileFill::O:
					cout << "|O";
					break;
			}
		}

		cout << "|" << endl;
	}
}

Location GetPlayerChoice() {
	int col, row;

	cout << "Where will you play?" << endl;
	cout << "Column: ";
	cin >> col;
	cout << "Row: ";
	cin >> row;

	return {col, row};
}

void PlaceMarker(TileFill board[3][3], Location place, TileFill value) {
	board[place.row - 1][place.col - 1] = value;
}

int main() {
	TileFill board[3][3];
	CreateBoard(board);

	for (int i = 0; i < 9; i++) {
		TileFill turn;

		if (i % 2) {
			turn = TileFill::X;
		} else {
			turn = TileFill::O;
		}

		DisplayBoard(board);
		PlaceMarker(board, GetPlayerChoice(), turn);
	}
}