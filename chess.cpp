#include <iostream>
using namespace std;

int main() {

    string chess[8][8] = {"WE1", "WKn1", "WB1", "WQ", "WK", "WB2", "Wkn2", "WE2",
                          "WP1", "WP2", "WP3", "WP4", "WP5", "WP6", "WP7", "WP8",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8",
                          "BE1", "BKn1", "BB1", "BQ", "BK", "BB2", "Bkn2", "BE2"};
    for(int i = 1; i<=8; i++)
    {
        cout << i << "     ";
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[i][j] != "0") {
                cout << chess[i][j] + "   ";
            } else {
                cout << chess[i][j] + "     ";
            }
        }
        cout << endl;
    }
    while (1) {
        for (int i = 1; i > 0; i++) {
            cout << "Black's turn!\n";
            cout << "Enter which piece you want to move: \n";
            string choice;
            cin >> choice;
            int a, b;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chess[i][j] == choice) {
                        a = i;
                        b = j;
                    }
                }
            }
            cout << choice << endl;
            if (choice[0] == 'B' && choice[1] == 'P') {
                cout << "Enter the row you want to move to: \n";
                int p;
                cin >> p;
                cout << "Enter the column you want to move to: \n";
                int q;
                cin >> q;
                int x = p - 1;
                int y = q - 1;
                if ((x + 1 == a && y + 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y - 1 == b)){
                    if (chess[x][y][0] == 'W') {
                        cout << chess[x][y] << " is out!\n";
                        chess[x][y] = choice;
                        chess[a][b] = "0";
                    }
                    else  {
                        cout << "You can't move there!\n";
                        continue;
                    }
                }
                else if( ((x + 1 == a && y == b) || (x + 2 == a && y == b)))
                {
                    if (chess[x][y][0] == 'W') {
                        cout << "You can't remove the piece ahead of you!\n";
                        continue;
                    }
                    else if (chess[x][y][0] == 'B') {
                        cout << "You can't move there!\n";
                        continue;
                    } else {
                        chess[x][y] = choice;
                        chess[a][b] = "0";
                    }
                }
                else if ((x - 1 == a && y == b) || (x - 2 == a && y == b)) {

                    if (chess[x][y][0] == 'W') {
                        cout << "You can't remove the piece ahead of you!\n";
                    }
                    else if(chess[x][y][0] == 'B')
                    {
                        cout << "You can't move there!\n";
                        continue;
                    }
                    else {
                        chess[x][y] = choice;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice[0] == 'B' && choice[1] == 'E') {
                cout << "Enter whether you want to move in a row or a column(row|column)\n";
                string rc;
                cin >> rc;
                if (rc == "row") {
                    cout << "Enter the row you want to move to: \n";
                    int r;
                    cin >> r;
                    int qw = 0;
                    for (int o = a - 1; o > r - 1; o--) {
                        cout << chess[o][b] << endl;
                        if (chess[o][b][0] == 'B') {
                            qw++;
                        }
                    }
                    if (qw > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[r][b][0] == 'W') {
                        cout << chess[r][b] << " is out!\n";
                        chess[r - 1][b] = choice;
                        chess[a][b] = "0";
                    } else {
                        chess[r - 1][b] = choice;
                        chess[a][b] = "0";
                    }

                } else if (rc == "column") {
                    cout << "Enter the column you want to move to: \n";
                    int c;
                    cin >> c;
                    int qw1 = 0;
                    for (int o = b - 1; o > c - 1; o--) {
                        if (chess[a][o][0] == 'B') {
                            qw1++;
                        }
                    }
                    if (qw1 > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[a][c - 1][0] == 'W') {
                        cout << chess[a][c] << " is out!\n";
                        chess[a][c - 1] = choice;
                        chess[a][b] = "0";
                    } else {
                        chess[a][c - 1] = choice;
                        chess[a][b] = "0";
                    }

                }
            } else if (choice == "BKn1" || choice == "BKn2") {
                cout << "Enter the row you want to move to:\n";
                int rkn1, ckn1;
                cin >> rkn1;
                int rkn = rkn1 - 1;
                cout << "Enter the column you want to move to:\n";
                cin >> ckn1;
                int ckn = ckn1 - 1;
                int qw5 = 0;

                 if ((rkn + 2 == a && ckn - 1 == b) || (rkn - 2 == a && ckn + 1 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                    else if(chess[rkn][ckn][0] == 'B')
                    {
                        cout << "You can't move there!\n";
                    }else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                } else if ((rkn + 1 == a && ckn - 2 == b) || (rkn - 1 == a && ckn + 2 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                    else if(chess[rkn][ckn][0] == 'B')
                    {
                        cout << "You can't move there!\n";
                    }else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice == "BK") {
                cout << "Enter the row you want to move to: \n";
                int rk1, ck1;
                cin >> rk1;
                cout << "Enter the column you want to move to: \n";
                cin >> ck1;
                int rk = rk1 - 1;
                int ck = ck1 - 1;
                if (chess[rk][ck][0] == 'B') {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rk][ck][0] == 'W') {
                    cout << chess[rk][ck] << " is out!\n";
                    chess[rk][ck] = choice;
                    chess[a][b] = "0";
                } else {
                    if ((rk - 1 == a && ck == b) || (rk == a && ck - 1 == b) || (rk - 1 == a && ck - 1 == b) ||
                        (rk + 1 == a && ck == b) || (rk == a && ck + 1 == b) || (rk + 1 == a && ck + 1 == b)) {
                        chess[rk][ck] = choice;
                        chess[a][b] = "0";
                    }
                }
            } else if (choice == "BB1" || choice == "BB2") {
                int rb1, cb1;
                cout << "Enter the row you want to move to:\n";
                cin >> rb1;
                cout << "Enter the column you want to move to:\n";
                cin >> cb1;
                int rb = rb1 - 1;
                int cb = cb1 - 1;
                int cob = 0;
                int mb1 = cb;
                int mb2 = b;
                if (rb > a && cb > b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 1" << endl;
                            cob++;
                        }
                        mb1--;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else if (rb < a && cb > b) {
                    for (int i = a - 1; i > rb - 1; i--) {

                        if (chess[i][mb2+1][0] == 'B') {
                            cout << chess[i][mb2] << " 2" << endl;
                            cob++;
                        }
                        mb2++;
                        if (mb2 == cb - 1) {
                            break;
                        }
                    }
                } else if (rb > a && cb < b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 3" << endl;
                            cob++;
                        }
                        mb1++;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else {
                    for (int i = rb + 1; i < a - 1; i++) {
                        if (chess[i][mb2][0] == 'B') {
                            cout << chess[i][mb2] << " 4" << endl;
                            cob++;
                        }
                        mb2--;
                        if (mb2 == b - 1) {
                            break;
                        }
                    }
                }
                cout << cob << endl;
                if (cob > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if ((rb - a == cb - b) || (a - rb == b - cb) || (rb - a == b - cb) || (a - rb == cb - b)) {
                    if (chess[rb][cb][0] == 'W') {
                        cout << chess[rb][cb] << " is out!\n";
                        chess[rb][cb] = choice;
                        chess[a][b] = "0";
                    } else {
                        chess[rb][cb] = choice;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }

            } else if (choice == "BQ") {
                int rq1, cq1;
                cout << "Enter the row you want to move to:\n";
                cin >> rq1;
                cout << "Enter the column you want to move to:\n";
                cin >> cq1;
                int rq = rq1 - 1;
                int cq = cq1 - 1;
                int cot = 0;
                for (int mq = a; mq > rq; mq--) {
                    for (int nq = b; nq > cq; nq--) {
                        if (chess[mq][nq][0] == 'B') {
                            cot++;
                        }
                    }
                }
                if (cot > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rq][cq][0] == 'W') {
                    cout << chess[rq][cq] << " is out!";
                    chess[rq][cq] = choice;
                    chess[a][b] = "0";
                } else {
                    chess[rq][cq] = choice;
                    chess[a][b] = "0";
                }
            } else {
                cout << "Wrong Input!\n";
                continue;
            }
            for(int i = 1; i<=8; i++)
            {
                cout << i << "     ";
            }
            cout << endl;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chess[i][j] != "0") {
                        cout << chess[i][j] + "   ";
                    } else {
                        cout << chess[i][j] + "     ";
                    }
                }
                cout << endl;
            }
            break;
        }
        int cmb = 0;
        int cmw = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chess[i][j] == "BK") {
                    cmb++;
                } else if (chess[i][j] == "WK") {
                    cmw++;
                }
            }
        }
        if (cmb == 0) {
            cout << "Game Over! White Wins!\n";
            break;
        } else if (cmw == 0) {
            cout << "Game Over! Black Wins!\n";
            break;
        } else {
        }
        for (int i = 1; i >= 1; i++) {
            cout << "White's turn!\n";
            cout << "Enter which piece you want to move: \n";
            string choice1;
            cin >> choice1;
            int a, b;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chess[i][j] == choice1) {
                        a = i;
                        b = j;
                    }
                }
            }
            if (choice1[0] == 'W' && choice1[1] == 'P') {
                cout << "Enter the row you want to move to: \n";
                int p;
                cin >> p;
                cout << "Enter the column you want to move to: \n";
                int q;
                cin >> q;
                int x = p - 1;
                int y = q - 1;
                if ((x + 1 == a && y + 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y - 1 == b)){
                    if (chess[x][y][0] == 'B') {
                        cout << chess[x][y] << " is out!\n";
                        chess[x][y] = choice1;
                        chess[a][b] = "0";
                    }
                    else  {
                        cout << "You can't move there!\n";
                        continue;
                    }
                }
                else if( ((x + 1 == a && y == b) || (x + 2 == a && y == b)))
                {
                    if (chess[x][y][0] == 'B') {
                        cout << "You can't remove the piece ahead of you!\n";
                        continue;
                    }
                    else if (chess[x][y][0] == 'W') {
                        cout << "You can't move there!\n";
                        continue;
                    } else {
                        chess[x][y] = choice1;
                        chess[a][b] = "0";
                    }
                }
                else if ((x - 1 == a && y == b) || (x - 2 == a && y == b)) {

                    if (chess[x][y][0] == 'B') {
                        cout << "You can't remove the piece ahead of you!\n";
                    }
                    else if(chess[x][y][0] == 'W')
                    {
                        cout << "You can't move there!\n";
                        continue;
                    }
                    else {
                        chess[x][y] = choice1;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice1[0] == 'W' && choice1[1] == 'E') {
                cout << "Enter whether you want to move in a row or a column(row|column)\n";
                string rc;
                cin >> rc;
                if (rc == "row") {
                    cout << "Enter the row you want to move to: \n";
                    int r;
                    cin >> r;
                    int qw = 0;
                    for (int o = a - 1; o > r - 1; o--) {
                        cout << chess[o][b] << endl;
                        if (chess[o][b][0] == 'B') {
                            qw++;
                        }
                    }
                    if (qw > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[r][b][0] == 'W') {
                        cout << chess[r][b] << " is out!\n";
                        chess[r - 1][b] = choice1;
                        chess[a][b] = "0";
                    } else {
                        chess[r - 1][b] = choice1;
                        chess[a][b] = "0";
                    }

                } else if (rc == "column") {
                    cout << "Enter the column you want to move to: \n";
                    int c;
                    cin >> c;
                    int qw1 = 0;
                    for (int o = b - 1; o > c - 1; o--) {
                        if (chess[a][o][0] == 'B') {
                            qw1++;
                        }
                    }
                    if (qw1 > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[a][c - 1][0] == 'W') {
                        cout << chess[a][c] << " is out!\n";
                        chess[a][c - 1] = choice1;
                        chess[a][b] = "0";
                    } else {
                        chess[a][c - 1] = choice1;
                        chess[a][b] = "0";
                    }

                }
            } else if (choice1 == "WKn1" || choice1 == "WKn2") {
                cout << "Enter the row you want to move to:\n";
                int rkn1, ckn1;
                cin >> rkn1;
                int rkn = rkn1 - 1;
                cout << "Enter the column you want to move to:\n";
                cin >> ckn1;
                int ckn = ckn1 - 1;
                int qw5 = 0;
                for (int as = a - 1; as > rkn - 1; as--) {
                    for (int sa = b - 1; sa > ckn - 1; sa--) {
                        cout << chess[rkn][ckn] << endl;
                        if (chess[rkn][ckn][0] == 'B') {
                            qw5++;
                        }
                    }
                }
                if (qw5 > 0) {
                    cout << "There is a piece of yours in the way!\n";
                    continue;
                } else if ((rkn + 2 == a && ckn - 1 == b) || (rkn - 2 == a && ckn + 1 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    } else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    }
                } else if ((rkn + 1 == a && ckn - 2 == b) || (rkn - 1 == a && ckn + 2 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    } else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice1 == "WK") {
                cout << "Enter the row you want to move to: \n";
                int rk1, ck1;
                cin >> rk1;
                cout << "Enter the column you want to move to: \n";
                cin >> ck1;
                int rk = rk1 - 1;
                int ck = ck1 - 1;
                if (chess[rk][ck][0] == 'B') {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rk][ck][0] == 'W') {
                    cout << chess[rk][ck] << " is out!\n";
                    chess[rk][ck] = choice1;
                    chess[a][b] = "0";
                } else {
                    if ((rk - 1 == a && ck == b) || (rk == a && ck - 1 == b) || (rk - 1 == a && ck - 1 == b) ||
                        (rk + 1 == a && ck == b) || (rk == a && ck + 1 == b) || (rk + 1 == a && ck + 1 == b)) {
                        chess[rk][ck] = choice1;
                        chess[a][b] = "0";
                    }
                    else
                    {
                        cout << "You cannot move there!\n";
                        continue;
                    }
                }
            } else if (choice1 == "WB1" || choice1 == "WB2") {
                int rb1, cb1;
                cout << "Enter the row you want to move to:\n";
                cin >> rb1;
                cout << "Enter the column you want to move to:\n";
                cin >> cb1;
                int rb = rb1 - 1;
                int cb = cb1 - 1;
                int cob = 0;
                int mb1 = cb;
                int mb2 = b;
                if (rb > a && cb > b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 1" << endl;
                            cob++;
                        }
                        mb1--;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else if (rb < a && cb > b) {
                    for (int i = a - 1; i > rb - 1; i--) {
                        cout << i << endl;
                        cout << mb2 << endl;
                        if (chess[i][mb2][0] == 'B') {
                            cout << chess[i][mb2] << " 2" << endl;
                            cob++;
                        }
                        mb2++;
                        if (mb2 == cb - 1) {
                            break;
                        }
                    }
                } else if (rb > a && cb < b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 3" << endl;
                            cob++;
                        }
                        mb1++;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else {
                    for (int i = rb + 1; i < a - 1; i++) {
                        if (chess[i][mb2][0] == 'B') {
                            cout << chess[i][mb2] << " 4" << endl;
                            cob++;
                        }
                        mb2--;
                        if (mb2 == b - 1) {
                            break;
                        }
                    }
                }
                cout << cob << endl;
                if (cob > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if ((rb - a == cb - b) || (a - rb == b - cb) || (rb - a == b - cb) || (a - rb == cb - b)) {
                    if (chess[rb][cb][0] == 'W') {
                        cout << chess[rb][cb] << " is out!\n";
                        chess[rb][cb] = choice1;
                        chess[a][b] = "0";
                    } else {
                        chess[rb][cb] = choice1;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }

            } else if (choice1 == "WQ") {
                int rq1, cq1;
                cout << "Enter the row you want to move to:\n";
                cin >> rq1;
                cout << "Enter the column you want to move to:\n";
                cin >> cq1;
                int rq = rq1 - 1;
                int cq = cq1 - 1;
                int cot = 0;
                for (int mq = a; mq > rq; mq--) {
                    for (int nq = b; nq > cq; nq--) {
                        if (chess[mq][nq][0] == 'B') {
                            cot++;
                        }
                    }
                }
                if (cot > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rq][cq][0] == 'W') {
                    cout << chess[rq][cq] << " is out!";
                    chess[rq][cq] = choice1;
                    chess[a][b] = "0";
                } else {
                    chess[rq][cq] = choice1;
                    chess[a][b] = "0";
                }
            } else {
                cout << "Wrong Input!\n";
                continue;
            }
            break;
        }
        for(int i = 1; i<=8; i++)
        {
            cout << i << "     ";
        }
        cout << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chess[i][j] != "0") {
                    cout << chess[i][j] + "   ";
                } else {
                    cout << chess[i][j] + "     ";
                }
            }
            cout << endl;
        }
        int cmb1 = 0;
        int cmw1 = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chess[i][j] == "BK") {
                    cmb1++;
                } else if (chess[i][j] == "WK") {
                    cmw1++;
                }
            }
        }
        if (cmb1 == 0) {
            cout << "Game Over! White Wins!\n";
            break;
        } else if (cmw1 == 0) {
            cout << "Game Over! Black Wins!\n";
            break;
        } else {
            continue;
        }
    }
}
