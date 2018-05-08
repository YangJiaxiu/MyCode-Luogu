#include<iostream>

int main() {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (n / i);
    }
    std::cout << ans;
    return 0;
}