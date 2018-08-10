#include "/Users/yjx/stdc++.h"

const int MaxN = 40 + 10;

inline int GetInt() {
    int x = 0, f = 1; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

int N, M, points[350 + 10], card[5 + 10], dp[MaxN][MaxN][MaxN][MaxN];

int dfs(int a, int b, int c, int d) {
    if (dp[a][b][c][d]) return dp[a][b][c][d];
    // dp[a][b][c][d] = points[a + b * 2 + c * 3 + d * 4];
    if (a > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dfs(a - 1, b, c, d) + points[(a) + b * 2 + c * 3 + d * 4 + 1]);
    if (b > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dfs(a, b - 1, c, d) + points[a + (b) * 2 + c * 3 + d * 4 + 1]);
    if (c > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dfs(a, b, c - 1, d) + points[a + b * 2 + (c) * 3 + d * 4 + 1]);
    if (d > 0) dp[a][b][c][d] = std::max(dp[a][b][c][d], dfs(a, b, c, d - 1) + points[a + b * 2 + c * 3 + (d) * 4 + 1]);
    return dp[a][b][c][d];
}

int main() {
    N = GetInt(); M = GetInt();
    for (int i = 1; i <= N; ++i) {
        points[i] = GetInt();
    }
    for (int i = 1; i <= M; ++i) {
        card[GetInt()]++;
    }
    // debug1();
    dp[0][0][0][0] = points[1];
    std::cout << dfs(card[1], card[2], card[3], card[4]) << "\n";;
    return 0;
}