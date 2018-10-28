#include<iostream>
using namespace std;

bool endGame = false;
bool endLevel = false;
int a = 1;  // the player's x location
int b = 0;  // the player's y location
int x = 0;  // the player's previous x location
int y = 0;  // the player's previous y location
int level = 0; // the level of the game 
int mlx; 
int mly;

int map0[10][10] = 
{
	{1,1,1,1,1,1,1,1,1,1},
    {2,0,1,1,0,0,0,0,1,1},
    {1,0,1,1,0,1,1,0,0,1},
	{1,0,0,1,0,1,0,1,0,1},
	{1,1,0,1,1,0,1,1,0,1},
	{1,0,0,1,0,1,0,0,0,1},
	{1,1,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,1,0,1,1,1},
	{1,1,0,0,0,1,0,0,0,3},
	{1,1,1,1,1,1,1,1,1,1}
};

int map1[10][15] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{2,0,0,0,0,1,0,0,0,1,1,0,1,1,1},
	{1,0,1,1,0,1,0,1,0,0,0,0,0,1,1},
	{1,0,1,0,0,1,0,0,1,1,0,1,0,0,1},
	{1,0,1,0,0,1,1,0,1,1,0,1,1,0,1},
	{1,0,0,1,0,1,1,0,0,0,1,1,0,0,1},
	{1,0,1,0,0,1,1,0,1,1,1,0,0,0,1},
	{1,1,1,1,0,0,0,0,1,0,1,0,0,0,3},
	{1,1,0,0,0,1,1,1,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int map2[15][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{2,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,1,1,1},
	{1,1,0,1,1,0,1,1,0,0,0,1,1,1,1,0,1,1,1,1},
	{1,1,0,1,1,0,1,1,1,0,1,0,0,1,1,0,0,0,0,1},
	{1,0,0,1,0,0,1,0,0,0,1,1,0,1,0,1,1,1,0,1},
	{1,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1},
	{1,1,0,1,0,0,0,1,1,0,1,0,0,1,0,1,1,1,0,1},
	{1,1,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,0,1,1,1,1,0,1,0,1,1,0,0,0,1},
	{1,0,1,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,0,1},
	{1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,1,1},
	{1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,0,0,0,3},
	{1,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1},
	{1,0,0,0,1,1,1,1,0,1,1,0,1,0,0,1,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void printMap();
void up();
void down();
void left();
void right();
void move();


int main() {
	char ch;
	while (!endGame) {
		printMap();
		a = 1; 
		b = 0; 
		x = 0;  
		y = 0; 
		while (!endLevel) {
			ch = getchar();
			switch (ch) {
			case 'w':
				up();
				move();
				system("cls");
				printMap();
				break;
			case 's':
				down();
				move();
				system("cls");
				printMap();
				break;
			case 'a':
				left();
				move();
				system("cls");
				printMap();
				break;
			case 'd':
				right();
				move();
				system("cls");
				printMap();
				break;
			}

			if (level == 3) {
				cout << "Congratulation! You passed all levels!";
				endGame = true;
				break;
			}

			if (endLevel) {
				cout << "Congratulation! You passed level ";
				cout<< level << endl;
				level++;
				cout << "Starting level ";
				cout << level << endl;
			}
		}
		endLevel = false;
	}

	cin.get();
	cin.get();
	return 0;
}

void printMap() {
	cout << "Press w to move up" << endl;
	cout << "Press d to move down" << endl;
	cout << "Press a to move left" << endl;
	cout << "Press d to move right" << endl;
	cout << "The char X is your current position" << endl << endl;
	switch (level) {
	case 0:
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map0[i][j] == 1) {
					cout << "#";
				}
				else if (map0[i][j] == 0) {
					cout << " ";
				}
				else if (map0[i][j] == 2) {
					cout << 'X';
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 1:
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				if (map1[i][j] == 1) {
					cout << "#";
				}
				else if (map1[i][j] == 0) {
					cout << " ";
				}
				else if (map1[i][j] == 2) {
					cout << 'X';
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	case 2:
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 20; j++) {
				if (map2[i][j] == 1) {
					cout << "#";
				}
				else if (map2[i][j] == 0) {
					cout << " ";
				}
				else if (map2[i][j] == 2) {
					cout << 'X';
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		break;
	}
}

void up() {
	switch (level) {
	case 0:
		if (map0[a - 1][b] != 1) {
			x = a;
			y = b;
			a = a - 1;
		}
		break;
	case 1:
		if (map1[a - 1][b] != 1) {
			x = a;
			y = b;
			a = a - 1;
		}
		break;
	case 2:
		if (map2[a - 1][b] != 1) {
			x = a;
			y = b;
			a = a - 1;
		}
		break;
	}
}

void down() {
	switch (level) {
	case 0:
		if (map0[a + 1][b] != 1) {
			x = a;
			y = b;
			a = a + 1;
		}
		break;
	case 1:
		if (map1[a + 1][b] != 1) {
			x = a;
			y = b;
			a = a + 1;
		}
		break;
	case 2:
		if (map1[a + 1][b] != 1) {
			x = a;
			y = b;
			a = a + 1;
		}
		break;
	}
}

void left() {
	switch (level) {
	case 0:
		if (map0[a][b - 1] != 1) {
			x = a;
			y = b;
			b = b -1;
		}
		break;
	case 1:
		if (map1[a][b - 1] != 1) {
				x = a;
				y = b;
				b = b - 1;
			}
		break;
	case 2:
		if (map1[a][b - 1] != 1) {
			x = a;
			y = b;
			b = b - 1;
		}
		break;
	}
	
}

void right() {
	switch (level) {
	case 0:
		if (map0[a][b + 1] != 1) {
			x = a;
			y = b;
			b = b + 1;
		}
		break;
	case 1:
		if (map1[a][b + 1] != 1) {
			x = a;
			y = b;
			b = b + 1;
		}
		break;
	case 2:
		if (map1[a][b + 1] != 1) {
			x = a;
			y = b;
			b = b + 1;
		}
		break;
	}
}

void move() {
	switch (level) {
	case 0:
		if (map0[a][b] == 3) {
			endLevel = true;
		}
		map0[a][b] = 2;
		map0[x][y] = 0;
		break;
	case 1:
		if (map1[a][b] == 3) {
			endLevel = true;
		}
		map1[a][b] = 2;
		map1[x][y] = 0;
		break;
	case 2:
		if (map1[a][b] == 3) {
			endLevel = true;
		}
		map1[a][b] = 2;
		map1[x][y] = 0;
		break;
	}
}