#include <iostream>
#include <cstdio>

const int MaxN = 2000 + 10;

inline int GetInt() {
    int f = 1, x = 0; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

int n, a[MaxN];

int gcd(const int &a, const int &b) {return (b == 0) ? a : gcd(b, a % b);} 

inline void Read() {
    n = GetInt();
    for (int i = 1; i <= n; ++i) {
        a[i] = GetInt();
    }
}

inline void Work() {
    int x = 1, y = 1, last = a[x], ans = -0x3f3f3f3f;
    while (x <= n) {
        if (y > n) {
            x++; y = x + 1;// 此处 如果x + 1 则[x + 1, y]区间的gcd 就会不知道是谁...
        }
        if (gcd(last, a[y]) == last) {
            y++;
            ans = std::max(y - x + 1, ans);
            continue;
        } 
        if (gcd(last, a[y]) == a[y]) {
            last = a[y];
            y++;
            ans = std::max(y - x + 1, ans);
            continue;
        } 
        x++;
    }
    std::cout << ans;
}

int main() {
    // freopen("save.in", "r", stdin);
    // freopen("save.out", "w", stdout);
    Read();
    Work();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
5
4 6 9 3 6
*/