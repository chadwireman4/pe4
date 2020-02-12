#include <iostream>

using namespace std;

enum class TileFill {Empty, X, O};

void CreateBoard(TileFill board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = TileFill::Empty;
		}
	}
}

int main() {
	TileFill board[3][3];
	CreateBoard(board);
}