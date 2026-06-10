#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    const int w = 10;
    const int k = 20;

    char t[w][k];

    int x = k / 2;
    int pkt = 0;

    const int MAX = 5;

    int px[MAX];
    int py[MAX];
    char z[MAX];

    int licz = 0;

    for (int i = 0; i < MAX; i++) {
        px[i] = rand() % k;
        py[i] = rand() % 3;
        z[i] = (rand() % 2 == 0) ? '+' : '-';
    }
    while (pkt >= 0) {
        system("cls");
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < k; j++) {
                t[i][j] = ' ';
            }
        }
        t[w - 1][x] = 'O';
        int ile = 1 + pkt / 50;
        if (ile > MAX) {
            ile = MAX;
        }
        for (int i = 0; i < ile; i++) {
            t[py[i]][px[i]] = z[i];
        }
        cout << "SCORE: " << pkt << endl;
        cout << endl;

        cout << "+";
        for (int i = 0; i < k; i++) {
            cout << "-";
        }
        cout << "+" << endl;

        for (int i = 0; i < w; i++) {
            cout << "|";
            for (int j = 0; j < k; j++) {
                cout << t[i][j];
            }
            cout << "|" << endl;
        }

        cout << "+";
        for (int i = 0; i < k; i++) {
            cout << "-";
        }
        cout << "+" << endl;

        if (GetAsyncKeyState('A') & 0x8000 && x > 0) {
            x--;
        }

        if (GetAsyncKeyState('D') & 0x8000 && x < k - 1) {
            x++;
        }

        licz++;

        if (licz >= 6) {
            for (int i = 0; i < ile; i++) {
                py[i]++;

                if (py[i] == w - 1 && px[i] == x) {
                    if (z[i] == '+') {
                        pkt += 10;
                    } else {
                        pkt -= 10;
                    }

                    py[i] = 0;
                    px[i] = rand() % k;
                    z[i] = (rand() % 2 == 0) ? '+' : '-';
                }

                if (py[i] >= w) {
                    py[i] = 0;
                    px[i] = rand() % k;
                    z[i] = (rand() % 2 == 0) ? '+' : '-';
                }
            }

            licz = 0;
        }

        Sleep(50);
    }

    system("cls");
    cout << "GAME OVER" << endl;
    cout << "WYNIK: " << pkt << endl;

    return 0;
}
