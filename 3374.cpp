#include<bits/stdc++.h>

const long long MaxN = 500000 + 100;

inline void getInt(long long &ans) {
    long long f = 1, x = 0; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    ans = f * x;
}

long long N, M, pre[MaxN], a[MaxN];

inline void debug1() {
    for (int i = 1; i <= N; ++i) {
        std::cout << pre[i] << " ";
    }
    std::cout << "\n\n";
}


int main() {
    getInt(N);
    getInt(M);
    for (int i = 1; i <= N; ++i) {
        getInt(a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    long long flag, x;
    for (int i = 1; i <= M; ++i) {
        getInt(flag); getInt(x);
        if (flag == 1) {
            long long k;
            getInt(k);
            pre[x] += k;
            pre[x + 1] -= k;
            for (long long j = 1; j <= N; ++j) pre[j] = pre[j - 1] + a[j];//注：此处应对整个数组再求一次前缀和
            // debug1();
        } else {
            long long y;
            getInt(y);
            // debug1();
            std::cout << pre[y] - pre[x - 1] << "\n";
        }
    }
    return 0;
}