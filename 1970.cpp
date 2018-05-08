#include<iostream>
#include<cstdio>

const int MaxN = 100000 + 10;

int n, ans = 0, h[MaxN] = {0};
bool isMono = false;//true表示现在在单调上升中，false表示现在单调下降中

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> h[i];
    // for (int i = 2; i < n; ++i) {
    //     if (((h[i] > h[i - 1]) && (h[i] > h[i + 1])) || ((h[i] < h[i - 1]) && (h[i] < h[i + 1]))) ans++;
    // }

    if (h[2] > h[1]) isMono = true;
    for (int i = 1; i <= n; ++i) {
        if (i == n && isMono == false) {
            ans++;
            continue;
        }
        if ((isMono == true) && (h[i] < h[i - 1])) {
            isMono = false;
            ans++;
            continue;
        }
        if ((isMono == false) && (h[i] > h[i - 1])) {
            isMono = true;
            ans++;
            continue;            
        }
    }
    std::cout << ans;    
    return 0;
}
