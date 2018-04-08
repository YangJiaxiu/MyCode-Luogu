#include<bits/stdc++.h>

#define dbg(x) std::cerr << "x = " << x << "   "

const int MaxN = 2e5 + 100;

struct city {
    int south;
    int north;

    friend inline bool operator < (const city &a, const city &b) {return a.south < b.south;}
    /* 上面保持了南岸有序 */
}x[MaxN];

inline int getInt() {
    int f=1,x=0;
    char ch;
    do {ch=getchar();if(ch=='-')f=-1;} while(ch<'0'||ch>'9');
    do {x=x*10+ch-'0';ch=getchar();} while(ch>='0'&&ch<='9');
    return f*x;
}

int f[MaxN] = {0}, ans, N;
/* 设f[i]为到第i位为止的最长不下降子序列 */
int main() {
    N = getInt();
    for (int i = 1; i <= N; ++i) {
        x[i].south = getInt(); x[i].north = getInt();
    }

    std::sort(x + 1, x + N + 1);
    for (int i = 1; i <= N; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (x[i].north > x[j].north){
                f[i] = std::max(f[i], f[j] + 1);
            }
        }
        ans = std::max(ans, f[i]);
    }
    std::cout << ans;
    return 0;
}