#include<bits/stdc++.h>

const int MaxN = 1e5 + 10;

int a[MaxN], n;

inline bool judge(bool isUp) {
    int count = 0;
    for (int i = 2; i <= n; ++i, isUp = !isUp) {
        if ((a[i] != a[i - 1]) && (a[i] > a[i - 1]) != isUp) {
            if (++count > 1) {
                return false;
            } else {
                ++i;
                isUp = !isUp;
            }
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    while (std::cin >> n) {
        memset(a, sizeof(a), 0);
        if (n <= 3) std::cout << "Yes" << std::endl;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        if (judge(0) || judge(1)) std::cout << "Yes" << std::endl; else std::cout << "No" << std::endl;
    }
    return 0;
}