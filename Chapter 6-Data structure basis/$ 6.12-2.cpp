#include<iostream>
#include<cmath>
#include<cstring>
#include<Windows.h>
using namespace std;

//r = a + b * sin(θ + π)
//a = 3; b = 3

char pic[1000][1000];
int centerX = 500;
int centerY = 200;

void gotoxy(int x, int y) {
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void dfs(int r, int c) {

	if (pic[r][c] == '*' || pic[r][c] == '#') return;
	pic[r][c] = '#';
	dfs(r + 1, c);
	dfs(r - 1, c);
	dfs(r, c + 1);
	dfs(r, c - 1);
	Sleep(1);
	gotoxy(c + 1, r );
	cout << "#";
}

int main() {
	system("mode con cols=200 lines=151");
	Sleep(1000);
	memset(pic, ' ', sizeof(pic));
	const int a = 50;
	const int b = 50;

	for (double i = 0; i < 2 * acos(-1); i += 0.01) {
		double r = a + b * cos(i);
		int x = r * cos(i)/ 2 + 100;
		int y = r * sin(i) + 100;
		pic[x][y] = '*';
	}
	
	
	//pic[94][73] = '$';
	for (int i = 0; i < 151; i++) {
		for (int j = 0; j < 200; j++) {
			//Sleep(1);
			cout << pic[i][j];
		}
		cout << endl;
	}
	dfs(94, 73);
	// 94 73


	system("pause");
}