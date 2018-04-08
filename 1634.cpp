#include<bits/stdc++.h>

long long ans = 1;

int main() {
    int x, n;
    std::cin >> x >> n;
    while (n--) {
        ans += (ans * x);
    }
    std::cout << ans;
    return 0;
}