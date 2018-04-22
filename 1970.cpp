#include<iostream>
#include<cstdio>

const int MaxN = 100000 + 10;

int n, ans = 0, h[MaxN] = {0};

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> h[i];
    for (int i = 2; i < n; ++i) {
        if (((h[i] > h[i - 1]) && (h[i] > h[i + 1])) || ((h[i] < h[i - 1]) && (h[i] < h[i + 1]))) ans++;
    }
    std::cout << ans + 2;
    return 0;
}
