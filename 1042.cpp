#include<bits/stdc++.h>

using std::string;

int Len, Win_11 = 0, Lose_11 = 0, Win_21 = 0, Lose_21 = 0;

string Result;

bool check_11(int win, int lose) {
    if (abs(lose - win) < 2) return false;
    if ((win < 11) && (lose < 11)) return false;
    return true;
}

bool check_21(int win, int lose) {
    if (abs(lose - win) < 2) return false;
    if ((win < 21) && (lose < 21)) return false;
    return true;
}

int main() {
    char c;
    while ((c = getchar()) != 'E') {
        if ((c != '\n') && (c != '\r')) Result += c;
    }
    Len = Result.size();

    if (Len == 0) {
        std::cout << "0:0\n\n0:0\n";
        return 0;
    }

    for (int i = 0; i < Len; ++i) {
        if (Result[i] == 'W') Win_11++;
        else Lose_11++;

        if (check_11(Win_11, Lose_11)) {
            std::cout << Win_11 << ":" << Lose_11 << "\n";
            Win_11 = Lose_11 = 0;
        }
    } 

    std::cout << Win_11 << ":" << Lose_11 << "\n";
    Win_11 = Lose_11 = 0;

    if (Len > 0) std::cout << "\n";

    for (int i = 0; i < Len; ++i) {
        if (Result[i] == 'W') Win_21++;
        else Lose_21++;

        if (check_21(Win_21, Lose_21) || (i == Len - 1)) {
            std::cerr << Win_21 << ":" << Lose_21 << "\n";
            Win_21 = Lose_21 = 0;
        }
    }
    return 0;
}