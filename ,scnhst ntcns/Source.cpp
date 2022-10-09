#include <iostream>
#include <ctime>
#include <stdbool.h>
#include <vector>
using namespace std;
int mask2[4][2]{
	{1, 0},
	{0, 1},
	{0, -1},
	{-1, 0} };
int field[10][10];
int fieldd[10][10];
int scan = 0;
int i, j, k, h, g, ok, nook;
vector<string> histiory;
class Rastan
{
public:
	int id;
	int x, y;
	void Ship(int id)
	{
		this->id = id;
		for (int i = 0; i <= 9; i++)
			for (int j = 0; j <= 9; j++)
			{
				field[i][j] = 0;
			}

	}
	int damage(int kto)
	{
		if (field[x][y] == 1) {
			cout << "попал"; field[x][y] = 2;   kto++; histiory.push_back("попал");
		}                                       //изменить рисунок на x
		else if (field[x][y] == 0) {
			cout << "Мимо"; field[x][y] = 3;   histiory.push_back("мимо");// изменить рисунок на ^
		}
		return kto;
	}
	void scanr()
	{
		h = i;
		g = j;
		scan = 0;
		i += 1;
		if (field[i][j] != 1 && i != 10)
		{
			j += 1;
			if (field[i][j] != 1 && j != 10)
			{
				i -= 1;
				if (field[i][j] != 1 && i != -1)
				{
					i -= 1;
					if (field[i][j] != 1 && i != -1)
					{
						j -= 1;
						if (field[i][j] != 1 && j != -1)
						{
							j -= 1;
							if (field[i][j] != 1 && j != -1)
							{
								i += 1;
								if (field[i][j] != 1 && i != 10)
								{
									i += 1;
									if (field[i][j] != 1 && i != 10)
									{

										scan = 1;
										i = h;
										j = g;
									}
								}
							}
						}
					}
				}
			}
		}
		else if (scan == 0) {
			h = i;
			g = j;
		}

	}
	void randk()
	{
		srand(time(0)); // автоматическая рандомизация"
		k = rand() % 4;
	}
	/*void gto()
	{
		if (k == 1)
		{
			k = 4;
			i -= 1;
			if (field[i][j] == 1)
			{
				i += mask2[k][0];
				j += mask2[k][1];
				if (field[i][j] == 1)
				{
					i += mask2[k][0];
					j += mask2[k][1];
					if (field[i][j] == 1)
					{
						i += mask2[k][0];
						j += mask2[k][1];
					}
				}
			}
		}
	}*/

	void pereme()
	{
		if (mask2[k][0] == -1) {
			i = i + mask2[k][0];
		}
		if (mask2[k][1] == -1) {
			j = j + mask2[k][1];
		}
		if (mask2[k][0] == 1) {
			i += mask2[k][0];
		}
		if (mask2[k][1] == 1) {
			j += mask2[k][1];
		}
		if (mask2[k][0] == 0) {
			i += mask2[k][0];
		}
		if (mask2[k][1] == 0) {
			j += mask2[k][1];
		}


		/*if (i > 9)
		{
			Rastan bar;
			bar.gt1();
		}*/

	}
	void rando()
	{
		srand(time(0)); // автоматическая рандомизация
		i = rand() % 9;
		j = rand() % 9;
	}
	void proricovka()
	{
		cout << "Игрок" << id << ":\n";
		cout << " Y  0  1  2  3  4  5  6  7  8  9  \n";
		cout << "X  _____________________________\n";
		int n = 0, m = 0;
		for (int i = 0; i <= 9; i++)
		{
			n = i;
			cout << i << " ";

			for (int j = 0; j <= 9; j++)
			{
				m = j;
				cout << "|";
				if (field[i][j] == 0 || field[i][j] == 1)cout << " " << field[i][j];
				else cout << " x";
				if (m == 9) cout << "|";
			}

			if (n < 9)cout << endl;
			else cout << "\n  ```````````````````````````````";
		}

	}
	void toch() {
		field[i][j] = 1;
		while (nook > 1) {
			if (mask2[k][0] == -1) {
				i = i - mask2[k][0];
			}
			if (mask2[k][1] == -1) {
				j = j - mask2[k][1];
			}
			if (mask2[k][0] == 1) {
				i -= mask2[k][0];
			}
			if (mask2[k][1] == 1) {
				j -= mask2[k][1];
			}
			if (mask2[k][0] == 0) {
				i -= mask2[k][0];
			}
			if (mask2[k][1] == 0) {
				j -= mask2[k][1];
			}
			field[i][j] = 1;
			nook -= 1;
		}

	}
};
class Start {
public:
	int id;
	void maino() {
		Rastan random;
		Rastan randomk;
		Rastan scaner;
		Rastan per;
		Rastan oks;
		this->id = id;
		std::cout << " Генерация кораблей это может занять до 4 минут \n";


		while (ok < 1) {
			random.rando();
			randomk.randk();
			nook = 0;
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					if (scan == 1)
					{
						nook = 2;
						per.pereme();
						scaner.scanr();
						if (scan == 1)
						{
							nook = 3;
							per.pereme();
							scaner.scanr();
							if (scan == 1)
							{
								nook = 4;
								per.pereme();
								scaner.scanr();
								oks.toch();
								ok = 1;
								nook = 0;
								std::cout << i << " - I  " << j << " - J  Первый кораблик \n";
							}
						}
					}

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();

			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					if (scan == 1)
					{
						nook = 2;
						per.pereme();
						scaner.scanr();
						if (scan == 1)
						{
							nook = 3;
							per.pereme();
							scaner.scanr();
							oks.toch();
							ok = 1;
							std::cout << i << " - I  " << j << " - J  второй кораблик \n";
						}
					}

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();
			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					if (scan == 1)
					{
						nook = 2;
						per.pereme();
						scaner.scanr();
						if (scan == 1)
						{
							nook = 3;
							per.pereme();
							scaner.scanr();
							oks.toch();
							ok = 1;
							std::cout << i << " - I  " << j << " - J  третий кораблик \n";
						}
					}

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();
			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					if (scan == 1)
					{
						nook = 2;
						per.pereme();
						scaner.scanr();
						oks.toch();
						ok = 1;
						std::cout << i << " - I  " << j << " - J  четвёртый кораблик \n";
					}

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();
			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					if (scan == 1)
					{
						nook = 2;
						per.pereme();
						scaner.scanr();
						oks.toch();
						ok = 1;
						std::cout << i << " - I  " << j << " - J  пятый кораблик \n";
					}

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();
			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					if (scan == 1)
					{
						nook = 2;
						per.pereme();
						scaner.scanr();
						oks.toch();
						ok = 1;
						std::cout << i << " - I  " << j << " - J  шестой кораблик \n";
					}

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();

			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					oks.toch();
					ok = 1;
					std::cout << i << " - I  " << j << " - J  седьмой кораблик \n";

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();

			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					oks.toch();
					ok = 1;
					std::cout << i << " - I  " << j << " - J  восьмой кораблик \n";

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();

			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					oks.toch();
					ok = 1;
					std::cout << i << " - I  " << j << " - J  девятый кораблик \n";

				}
			}
		}
		ok = 0;
		srand(55);
		while (ok < 1) {
			random.rando();

			randomk.randk();
			if (field[i][j] != 1)
			{
				scaner.scanr();
				if (scan == 1)
				{
					nook = 1;
					per.pereme();
					scaner.scanr();
					oks.toch();
					ok = 1;
					std::cout << i << " - I  " << j << " - J  десятый кораблик \n";

				}
			}
		}
		ok = 0;

	}
};
/*class ships {
public:
void kor4() {
		if (field[i][j] != 1)
		{
			scaner.scanr();
			if (scan == 0)
			{
				field[i][j] = 1;
				per.pereme();
				scaner.scanr();
				if (scan == 0)
				{
					field[i][j] = 1;
					per.pereme();
					scaner.scanr();
					if (scan == 0)
					{
						field[i][j] = 1;
						per.pereme();
						scaner.scanr();
						if (scan == 0)
						{
							field[i][j] = 1;
							per.pereme();
							scaner.scanr();

						}
					}
				}

			}
		}
	}
};
*/
//int argc, char *argv[]
int main()
{
	setlocale(LC_CTYPE, "rus");

	Rastan one;
	Rastan two;
	Start tresh;



	tresh.maino();
	one.id = 1;
	one.proricovka();  cout << "\n\n";
	


	tresh.maino();
	two.id = 2;
	two.proricovka();



	int kto = 1;
	for (;;)
	{
		int buf;
		if (kto % 2 == 0) { buf = 2; }
		else if (kto % 2 != 0) { buf = 1; }

		cout << "       Xодит " << buf << " игрок";
		cout << "       x: y: ";


		if (kto % 2 != 0)
		{
			cin >> two.x >> two.y;

			kto = two.damage(kto);

			kto++;

		}

		else if (kto % 2 == 0) {

			cin >> one.x >> one.y;
			kto = one.damage(kto);
			kto++;

		}


		system("cls");
		one.proricovka();  cout << "\n\n";
		two.proricovka();  cout << "\n\n";
		for (auto item : histiory) {
			cout << item << "\n";
		}
	}
	system("pause");
	return 0;
}