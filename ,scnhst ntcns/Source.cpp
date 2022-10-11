#include <algorithm>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <stdbool.h>
#include <vector>
#include <string>
using namespace std;
enum colors
{
    BlueDark, BlueGrey2, GreenGrey, BlueGrey, RedBlack, VioletLite, BrownLite, GreyLite, Grey, Blue, Green, GreenLite, Brown, Violet, Salat, White
};
const int Field = 10;
const char Wather = '0';
const char Ship = 'x';
const char meam = static_cast<char>(178);
const char Dam = static_cast<char>(176);
const int Fieldd = 10;
int x, y;
vector < string > histiory;
bool ship
(
    int size,
    bool is_horiz,
    int row_top,
    int col_left,
    const char field[][Field]
) {
    if (is_horiz) {
        for (int i = std::max(0, row_top - 1); i <= std::min(Field - 1, row_top + 1);
            ++i) {
            for (int j = std::max(0, col_left - 1); j <= std::min(Field - 1, col_left + size);
                ++j) {
                if (field[i][j] == Ship) return false;
            }
        }
        return true;
    }
    else {
        for (int i = std::max(0, row_top - 1); i <= std::min(Field - 1, row_top + size);
            ++i) {
            for (int j = std::max(0, col_left - 1); j <= std::min(Field - 1, col_left + 1);
                ++j) {
                if (field[i][j] == Ship) return false;
            }
        }
        return true;
    }
}

void SetShip(int size, char field[][Field]) {
    bool is_horiz = rand() % 2 == 0;
    int row_top = 0;
    int col_left = 0;

    do {
        do {
            row_top = rand() % Field;
        } while (!is_horiz && row_top > Field - size);

        do {
            col_left = rand() % Field;
        } while (is_horiz && col_left > Field - size);
    } while (!ship(size, is_horiz, row_top, col_left, field));

    if (is_horiz) {
        for (int j = col_left; j < col_left + size; ++j) {
            field[row_top][j] = Ship;
        }
    }
    else {
        for (int i = row_top; i < row_top + size; ++i) {
            field[i][col_left] = Ship;
        }
    }
}

void SetShips(char field[][Field]) {
    for (int i = 0; i < 1; ++i) {
        SetShip(4, field);
    }

    for (int i = 0; i < 2; ++i) {
        SetShip(3, field);
    }

    for (int i = 0; i < 3; ++i) {
        SetShip(2, field);
    }

    for (int i = 0; i < 4; ++i) {
        SetShip(1, field);
    }
}
void print_field(const char field[][Field]) {
    int r = 0;
    std::cout << " Y  0 1 2 3 4 5 6 7 8 9 \n";
    std::cout << "X   \n";
    for (int i = 0; i < Field; ++i) {
        std::cout << r << "   ";
        ++r;
        for (int j = 0; j < Field; ++j) {
            std::cout << field[i][j] <<
                " ";
            //static_cast<char>(176);
        }
        std::cout << std::endl;

    }
    std::cout << "\n";
}
void print_fieldd(const char fieldd[][Fieldd]) {
    int r = 0;
    std::cout << " Y  0 1 2 3 4 5 6 7 8 9 \n";
    std::cout << "X   \n";
    for (int i = 0; i < Fieldd; ++i) {
        std::cout << r << "   ";
        ++r;
        for (int j = 0; j < Fieldd; ++j) {
            std::cout << fieldd[i][j] <<
                " ";
            //static_cast<char>(176);
        }
        std::cout << std::endl;

    }
    std::cout << "\n";
}

void set_water(char field[][Field]) {
    for (int i = 0; i < Field; ++i) {
        for (int j = 0; j < Field; ++j) {
            field[i][j] = Wather;
        }
    }
}
void set_waterr(char fieldd[][Fieldd]) {
    for (int i = 0; i < Fieldd; ++i) {
        for (int j = 0; j < Fieldd; ++j) {
            fieldd[i][j] = Wather;
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "rus");
    srand(static_cast <unsigned> (time(0)));
    int x = 0;
    int y = 0;
    char field[Field][Field];
    char fieldd[Field][Field];
    set_water(field);
    SetShips(field);
    set_waterr(fieldd);
    SetShips(fieldd);
    std::cout << "Игрок 1 \n\n";
    print_field(field);
    std::cout << "Игрок 2 \n\n";
    print_fieldd(fieldd);
    int kto = 1;
    for (;;) {
        int buf;
        if (kto % 2 == 0) {
            buf = 2;
        }
        else if (kto % 2 != 0) {
            buf = 1;
        }

        std::cout << "       Xодит " << buf << " игрок";
        std::cout << "       x: y: ";

        if (kto % 2 != 0) {
            cin >> x >> y;
            if (field[x][y] == 'x') {
                std::cout << "попал";
                field[x][y] = Dam;
                histiory.push_back("попал");
            }
            else if (field[x][y] == '0') {
                std::cout << "Мимо";
                field[x][y] = meam;
                kto++;
                histiory.push_back("мимо");
            }

        }
        else if (kto % 2 == 0) {
            cin >> x >> y;
            if (fieldd[x][y] == 'x') {
                std::cout << "попал";
                fieldd[x][y] = Dam;
                histiory.push_back("попал");
            }
            else if (fieldd[x][y] == '0') {
                std::cout << "Мимо";
                fieldd[x][y] = meam;
                kto++;
                histiory.push_back("мимо");
            }

        }

        system("cls");
        print_field(field);
        std::cout << "\n\n";
        print_fieldd(fieldd);
        std::cout << "\n\n";
        for (auto item : histiory) {
            std::cout << item << "\n";
        }
    }
}