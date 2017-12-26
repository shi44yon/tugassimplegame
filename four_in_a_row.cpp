#include <iostream>

using namespace std;

void TPlay();
void TDraw();
void TFinalize();
int TRedturn();
int TBlueturn();

int main() {
	TPlay();
}

void TPlay() {
	char board[6][7];
	bool boardstatus[6][7];
	bool isRedPlay = false;
	bool isBluePlay = true;
	int i, j;
	for(i = 1; i <=7; i++) {
		cout<<i;
	}
	cout<<endl;
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 7; j++) {
			board[i][j] = 0;
			boardstatus[i][j] = false;
			cout<<board[i][j];
		}
		cout<<i+1<<endl;
	}
	
	for(i = 1; i <= 42; i++) {
		TFinalize;
		if(isRedPlay == false) {
			TRedturn;
			isRedPlay = true;
			isBluePlay = false;
		}else if(isBluePlay == false) {
			TBlueturn;
			isBluePlay = true;
			isRedPlay = false;
		}
		TDraw;
	}
}

int TRedturn(char board, bool boardstatus) {
	int n;
	char red = 'R';
	cin>>n;
	for(int i = 0; i < 7; i++) {
		if(boardstatus[n][i + 1] == true && i < 6) {
			board[n][i] = red;
			boardstatus[n][i] = true;
		}
	}
}

int TBlueturn(char board, bool boardstatus) {
	int n;
	char blue = 'B';
	cin>>n;
	for(int i = 0; i < 7; i++) {
		if(boardstatus[n][i + 1] == true && i < 6) {
			board[n][i] = blue;
			boardstatus[n][i] = true;
		}
	}
}

void TDraw(char board) {
	system("cls");
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 7; j++) {
			cout<<board[n][i];
		}
	}
}

void TFinalize(char board, bool boardstatus) {
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 4; j++) {
			if(board[i][j] == board[i][j + 1] == board[i][j + 2] == board[i][j + 3] || boardstatus[i][j] == true) {
				if(board[i][j] == 'R') {
					cout<<"Red is WIN!";
					
				}esle if(board[i][j] == 'B') {
					cout<<"Blue is WIN!";
					
				}
			}
		}
	}
}