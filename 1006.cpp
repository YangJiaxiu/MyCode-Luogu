#include<bits/stdc++.h>

const int MaxM = 50 + 10;
const int MaxN = 50 + 10;

int m, n, a[MaxM][MaxN], f[MaxM][MaxN][MaxM][MaxN];

int Max_4(int a, int b, int c, int d) {
    if (b > a) a = b;
    if (c > a) a = c;
    if (d > a) a = d;
    return a;
}

void debug1() {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= m; ++k) {
                for (int l = 1; l <= n; ++l) {
                    std::cerr << f[i][j][k][l] << "   ";
                }
            }
        }
    }
}

int main() {
    std::cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> a[i][j];
        }
    }


    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = m; k >= 1; --k) {
                for (int l = n; l >= 1; --l) {
                    f[i][j][k][l] = Max_4(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1], f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])
                                    + a[i][j]
                                    + a[k][l];
                    if ((i == k) && (j == l)) {
                        f[i][j][k][l] -= (a[i][j]);
                    }
                }
            }
        }
    }
   /*  debug1();
    std::cerr << "\n\n"; */
    std::cout << f[m][n][m][n];
    return 0;
}