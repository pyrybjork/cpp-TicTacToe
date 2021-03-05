#include <iostream>
using namespace std;

short x = 0, y = 0;
char matrix[3][3] = {'1', '4', '7', '2', '5', '8', '3', '6', '9'};
char in = '0';
char player = 'X';
bool game = true;
bool cround = true;
bool isValid = false;
short nplayer = 0;
short rounds = 1;
short xwins =  0;
short owins = 0;


void draw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void reset() {
    x = 0;
    y = 0;
    matrix[0][0] = '1';
    matrix[1][0] = '2';
    matrix[2][0] = '3';
    matrix[0][1] = '4';
    matrix[1][1] = '5';
    matrix[2][1] = '6';
    matrix[0][2] = '7';
    matrix[1][2] = '8';
    matrix[2][2] = '9';

    in = '0';
    player = 'X';
    game = true;
    cround = true;
    isValid = false;
    nplayer = 0;
    rounds++;
}

bool wcheck() {
    if ((matrix[0][0] == player && matrix[0][1] == player && matrix[0][2] == player) ||
        (matrix[1][0] == player && matrix[1][1] == player && matrix[1][2] == player) ||
        (matrix[2][0] == player && matrix[2][1] == player && matrix[2][2] == player) ||
        (matrix[0][0] == player && matrix[1][0] == player && matrix[2][0] == player) ||
        (matrix[0][1] == player && matrix[1][1] == player && matrix[2][1] == player) ||
        (matrix[0][2] == player && matrix[1][2] == player && matrix[2][2] == player) ||
        (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player) ||
        (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)) {
            cout << player <<" Won the game \n\n";
            if (nplayer == 0) {
                xwins++;
            }
            if (nplayer == 1) {
                owins++;
            }
            return true;
    }
    return false;
}

bool check(char b, int c) {
    switch (c) {
        case 0: 
            cout << player <<" : ";
            cin >> in;
            cout << "\n";
            break;
        case 1: 
            cout << player <<" : ";
            cin >> in;
            cout << "\n";
            break;
    }
    switch (in) {
        case '1':
            x = 0; y = 0;
            break;
        case '2':
            x = 1; y = 0;
            break;
        case '3':
            x = 2; y = 0;
            break;
        case '4':
            x = 0; y = 1;
            break;
        case '5':
            x = 1; y = 1;
            break;
        case '6':
            x = 2; y = 1;
            break;
        case '7':
            x = 0; y = 2;
            break;
        case '8':
            x = 1; y = 2;
            break;
        case '9':
            x = 2; y = 2;
            break;
    }
    if (matrix[x][y] == 'X' || matrix[x][y] == 'O') {
        cout << "This place is already occupied\n" << endl;
        return true;
    } else {
        matrix[x][y] = b;
        return false;
    }
}

int main() {
    while (game == true) {

        cout << "Round " << rounds << " | X: " << xwins << ", O: " << owins << "\n\n";

        for (int i = 0; i < 9; i++) {
            if (wcheck() == false) {
                nplayer = i % 2;
                cround = true;
                player = (nplayer == 0) ? 'X' : 'O';
                draw();
                while (cround == true) {
                    isValid = check(player, nplayer);
                    if (isValid == true) {
                        draw();
                    } else {
                        cround = false;
                    }
                }    
            } else {
                break;
            } 
        }
        reset();

    }
    system("pause");

    return 0;
}
