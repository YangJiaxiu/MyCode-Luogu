#include<bits/stdc++.h>

const int MaxN = 15000 + 10;

template<typename T> 
    inline T getInt(T &x) {
        int f = 1; x = 0; char ch;
        do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
        do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
        x = x*f;
    }

int n, m, X[MaxN], A[MaxN], B[MaxN], C[MaxN], D[MaxN],
    colorTime[4][MaxN];

int main() {
    std::ios::sync_with_stdio(false);
    getInt(n); getInt(m);
    for (int i = 1; i <= m; ++i) {
        getInt(X[i]);
    }


    for (int i = 1; i <= m; ++i) {
        std::cout << colorTime[1][i] << " "  
                  << colorTime[2][i] << " "
                  << colorTime[3][i] << " "
                  << colorTime[4][i] << " "                  
    }
    return 0;
}