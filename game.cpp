#include <iostream>

using namespace std;

int initialize();

int main() {
	initialize();
}

int initialize() {
	int live = 3;
	int check = 0;
	int point = 0;
	string answer[6] = "M","A","R","T","Y","R";
	string display[6] = "_","_","R","T","_","R";
	string guess;
	
	if(live > 0) {
		if(point == 3){
			cout<<"Right Answer, Score: "<<live * 30 + 10;
		}else {
			cin>>guess;
			for(int i = 0; i < 6; i++) {
				if(guess == answer[i]) {
					if(guess == display[i]) {
						check = 2;
						break;
					}else {
						display[i] = guess;
						check = 1;
						point++;
					}
				}
			}
			for(int j = 0; j < 6; j++) {
				cout<<display[j];
			}
			if(check == 0) {
				live--;
				cout<<"Wrong Answer, Try Again!";
			}else if(check == 2) {
				cout<<"Already Answered, Try Again!";
			}
			check = 0;	
		}
	}else {
		cout<<"Wrong Answer, GAME OVER";
	}
}
