#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace std;

/********************************************************************/
//Ukuran papan permainan
const int COLS = 8;//Kolom
const int ROWS = 8;//Baris

//Bidak
const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';
char disc = PLAYER_1;//Set pemain yang bermain di giliran pertama
char opposing_disc = PLAYER_2;//Set pemain yang bermain di giliran berikutnya
int endgame = 0;
/********************************************************************/
//Memunculkan koordinat papan permainan
void DrawBoard(const char board[ROWS][COLS]) {
	cout<<" ";
	for(int c = 0; c < COLS; c++) {
		cout<<c;
	}
	cout<<endl;
	
	for(int r = 0; r < ROWS; r++) {
		cout<<r;
		for(int c = 0; c < COLS; c++) {
			cout<<board[r][c];
		}
		cout<<endl;
	}
}
/********************************************************************/
//Meletakkan bidak
int PlaceDisc(char board[ROWS][COLS], int row, int col, char *player) {
	int num_flipped = 0;
	
	if(board[row][col] != ' ') {
		return 0;
	}
	board[row][col] = *player;
	
	if(*player == PLAYER_1) {
		opposing_disc = PLAYER_2;
	}else if(*player == PLAYER_2) {
		opposing_disc = PLAYER_1;
	}
	
	//Cek bidak di sebelah kiri
	int disc_pos = -1;
	for(int c = col - 1; c >= 0 && board[row][c] != ' ' && disc_pos == -1; c--)	{
		if(board[row][c] == *player) {
			disc_pos = c;
		}
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos < col - 1) {
		//Balik bidak di sebelah kiri
		for(int c = col - 1; c > disc_pos; c--) {
			board[row][c] = *player;
			num_flipped++;
		}
	}
	//Cek bidak di sebelah kanan
	disc_pos = -1;
	for(int c = col + 1; c < COLS && board[row][c] != ' ' && disc_pos == -1; c++) {
		if(board[row][c] == *player) {
			disc_pos = c;
		}
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos > col + 1) {
		//Balik bidak di sebelah kanan
		for(int c = col + 1; c < disc_pos; c++) {
			board[row][c] = *player;
			num_flipped++;
		}
	}
	//Cek bidak di atas
	disc_pos = -1;
	for(int r = row - 1; r >= 0 && board[r][col] != ' ' && disc_pos == -1; r--) {
		if(board[r][col] == *player) {
			disc_pos = r;
		}
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos < row - 1) {
		//Balik bidak di atas
		for(int r = row - 1; r > disc_pos; r--) {
			board[r][col] = *player;
			num_flipped++;
		}
	}
	//Cek bidak di bawah
	disc_pos = -1;
	for(int r = row + 1; r < ROWS && board[r][col] != ' ' && disc_pos == -1; r++) {
		if(board[r][col] == *player) {
			disc_pos = r;
		}
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos > row + 1) {
		//Balik bidak di bawah
		for(int r = row + 1; r < disc_pos; r++) {
			board[r][col] = *player;
			num_flipped++;
		}
	}
	//Cek bidak di sebelah kiri atas
	disc_pos = -1;
	int c = col - 1;
	for (int r = row - 1; c >= 0 && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--) {
		if (board[r][c] == *player) {
			disc_pos = r;
		}
		c--;
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos < row - 1) {
		c = col - 1;
		for(int r = row - 1; r > disc_pos; r--) {
			board[r][c] = *player;
			num_flipped++;
			c--;
		}
	}
	//Cek bidak di sebelah kanan atas
	disc_pos = -1;
	c = col + 1;
	for(int r = row - 1; c < COLS && r >= 0 && board[r][c] != ' ' && disc_pos == -1; r--) {
		if(board[r][c] == *player) {
			disc_pos = r;
		}
		c++;
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos < row - 1) {
		c = col + 1;
		for(int r = row - 1; r > disc_pos; r--) {
			board[r][c] = *player;
			num_flipped++;
			c++;
		}
	}
	//Cek bidak di sebelah kiri bawah
	disc_pos = -1;
	c = col - 1;
	for(int r = row + 1; c >= 0 && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++) {
		if(board[r][c] == *player) {
			disc_pos = r;
		}
		c--;
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos > row + 1) {
		c = col - 1;
		for(int r = row + 1; r < disc_pos; r++) {
			board[r][c] = *player;
			num_flipped++;
			c--;
		}
	}
	//Cek bidak di sebelah kanan bawah
	disc_pos = -1;
	c = col + 1;
	for(int r = row + 1; c < COLS && r < ROWS && board[r][c] != ' ' && disc_pos == -1; r++) {
		if(board[r][c] == *player) {
			disc_pos = r;
		}
		c++;
	}
	//Pastikan ada bidak yang sama dengan jarak setidaknya 2 petak jauhnya
	if(disc_pos != -1 && disc_pos > row + 1) {
		c = col + 1;
		for(int r = row + 1; r < disc_pos; r++) {
			board[r][c] = *player;
			num_flipped++;
			c++;
		}
	}
	//Reset papan jika tidak ada yang bidak dibalik... illegal move
	if(num_flipped == 0) {
		board[row][col] = ' ';
	}
	return num_flipped;
}
/********************************************************************/
//Ganti giliran pemain
void ChangePlayerMove(char *player, char *opposing_player) {
	if(*opposing_player == PLAYER_1) {
		*player = PLAYER_1;
	}else if(*opposing_player == PLAYER_2) {
		*player = PLAYER_2;
	}
}
/********************************************************************/
//Cek apakah pemain bisa memainkan gillirannya
int MoveIsPossible(const char board[ROWS][COLS], char *player) {return 1;}

//Dapatkan giliran pemain(jika illegal move bisa dilakukan)
void GetPlayerMove(char board[ROWS][COLS], char *player) {
	int row, col;
	bool illegal_move;
	//Cek apakah illegal move bisa dilakukan
	if(MoveIsPossible(board, &disc)) {
		cout<<"Giliran Pemain "<<*player<<".\n";
		do{
			illegal_move = false;
			cout<<"Masukan Baris = ";
			cin>>row;
			while(row < 0 || row >= ROWS) {
				cout<<"Masukan Baris antara 0 sampai "<<(ROWS - 1)<<".\n";
				cout<<"Maskuan Baris = ";
				cin>>row;
			}
			cout<<"Masukan Kolom = ";
			cin>>col;
			while(col < 0 || col >= COLS) {
				cout<<"Masukan Kolom antara 0 sampai "<<(COLS - 1)<< ".\n";
				cout<<"Masukan Kolom = ";
				cin>>col;
			}
			if(board[row][col] != ' ') {
				cout<<"Masukan Baris dan Kolom yang kosong.\n";
				illegal_move = true;
			}else {
				int discs_flipped = PlaceDisc(board, row, col, &disc);	
				if(discs_flipped == 0) {
					cout<<"Illegal Move.\n";
					illegal_move = true;
				}else {
					cout<<"Pemain "<<*player<<" membalik "<<discs_flipped<<" bidak.\n\n";
				}
			}
			endgame = 0;
		}while(illegal_move);
	}else {
		cout<<"Pemain "<<*player<<" tidak bisa memainkan gilirannya.\n";
		endgame++;
	}
}
/********************************************************************/
int GetScore(char board[ROWS][COLS], char player) {
	int player_score = 0;
	for(int r = 0; r< ROWS; r++) {
		for(int c = 0; c < COLS; c++) {
			if(board[r][c] = player) {
				player_score++;
			}
		}
	}
	return player_score;
}
/********************************************************************/
int main() {
	char board[ROWS][COLS];
	//Memunculkan papan awal permainan
	strncpy(board[0],"        ", COLS);
	strncpy(board[1],"        ", COLS);
	strncpy(board[2],"        ", COLS);
	strncpy(board[3],"   OX   ", COLS);
	strncpy(board[4],"   XO   ", COLS);
	strncpy(board[5],"        ", COLS);
	strncpy(board[6],"        ", COLS);
	strncpy(board[7],"        ", COLS);
	DrawBoard(board);
	
	//Ulangi terus selama kedua pemain bisa bermain
	do{
		GetPlayerMove(board, &disc);
		system("cls");//Reset layar sebelum menampilkan papan lagi
		DrawBoard(board);
		ChangePlayerMove(&disc, &opposing_disc);
	}while(endgame != 2);
	
	//Munculkan skor dan akhiri permainan
	cout<<"Permainan berakhir"<<endl;
	cout<<"Skor Pemain X = "<<GetScore(board, PLAYER_1)<<endl;
	cout<<"Skor Pemain O = "<<GetScore(board, PLAYER_2)<<endl;
}
