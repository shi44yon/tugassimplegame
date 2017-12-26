#include<iostream>

using namespace std;

void mapping();
int player();
int point();

int main() {
	mapping();
}

void mapping() {
	char map[9][9] = {
		"#########",
		"#       #",
		"# ## ## #",
		"# #   # #",
		"#       #",
		"# #   # #",
		"# ## ## #",
		"#       #",
		"#########",
	};
	for(int x = 0; x < 10; x++) {
	    for(int y = 0; y < 10; y++) {
	        cout<<mapping[x][y];
	    }
	    cout<<endl;
	}
}

int player() {
	char objplayer = '@';
}
