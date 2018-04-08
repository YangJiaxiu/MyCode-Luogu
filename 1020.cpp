#include<bits/stdc++.h>

const int MaxN = 100000 + 50;
const int oo = 0x3f3f3f3f;

int a[MaxN], n, f[MaxN];

inline void debug1(int x) {
    std::cerr << x << "  ";
}

inline void debug2() {
    for (int i = 1; i <= n; ++i) {
        std::cerr << f[i] << "  ";
    }
    std::cerr << "\n";
}

int main() {
    int temp, ans1 = 1;
    while (std::cin >> temp) a[++n] = temp;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] >= a[i]) {
                f[i] = std::max(f[j] + 1, f[i]);
            }
        }
        ans1 = std::max(ans1, f[i]);
    }
    // debug2();
    std::cout << ans1 << std::endl;/* 未理解 */
    /* 上面求的是最长不上升子序列 */
    memset(f, 0, sizeof(f));
    int ans2 = 0;
    
    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                f[i] = std::max(f[i], f[j] + 1);
            }
        }
        ans2 = std::max(f[i], ans2);
    }
    //  上面求的是最长上升子序列 
    std::cout << ans2 << std::endl;
    return 0;
}