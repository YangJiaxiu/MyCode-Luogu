#include<bits/stdc++.h>

const int MaxN = 200000 + 100;

long long N, f[MaxN] = {0};
long long ans, sum;
int main() {
    std::cin >> N;
    std::cin >> ans;
    for (int i = 2; i <= N; ++i) {
        long long x;
        std::cin >> x;
        sum += x;
        ans = std::max(sum, ans);
        if (sum < 0) sum = 0;         
    }

    std::cout << ans;
    return 0;
}