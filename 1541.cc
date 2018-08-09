#include "/Users/yjx/stdc++.h"

const int MaxN = 350 + 10;
const int MaxM = 120 + 10;

inline int GetInt() {
    int x = 0, f = 1; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

int N, M, points[MaxN], card[5 + 10], dp[5 + 10][5 + 10][5 + 10][5 + 10];

int dfs(int a, int b, int c, int d) {

}

int main() {
    N = GetInt(); M = GetInt();
    for (int i = 1; i <= N; ++i) {
        points[i] = GetInt();
    }
    for (int i = 1; i <= M; ++i) {
        card[GetInt()]++;
    }
    dfs(card[1], card[2], card[3], card[4]);
    std::cerr << dp[card[1]][card[2]][card[3]][card[4]];
    return 0;
}