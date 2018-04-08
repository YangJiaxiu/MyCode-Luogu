#include<bits/stdc++.h>

const int MaxN = 9 + 5;

int N, Matrix[MaxN][MaxN];
int f[MaxN][MaxN][MaxN][MaxN] = {0};

int Max_4(int a, int b, int c, int d) {
    if (b > a) a = b;
    if (c > a) a = c;
    if (d > a) a = d;
    return a;
}

int main() {
    std::cin >> N;
    int x, y, weight;
    while ((std::cin >> x >> y >> weight) && (x)) {
        Matrix[x][y] = weight;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                for (int l = 1; l <= N; ++l) {
                    f[i][j][k][l] = Max_4(f[i - 1][j][k - 1][l], f[i][j - 1][k][l - 1], f[i][j - 1][k - 1][l], f[i - 1][j][k][l - 1])
                                    + Matrix[i][j]
                                    + Matrix[k][l];
                    if ((i == k) && (j == l)) {
                        f[i][j][k][l] -= (Matrix[i][j]);
                    }
                }
            }
        }
    }
    std::cout << f[N][N][N][N];
    return 0;
}