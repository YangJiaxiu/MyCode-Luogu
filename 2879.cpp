#include<bits/stdc++.h>

const int MaxN = 1e4 + 10;

int Ans[MaxN], N, I, H, R, f[MaxN];

std::map< std::pair<int, int>, bool> Map;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> I >> H >> R;
    for (int i = 1; i <= R; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (x > y) std::swap(x, y);
        int a = x + 1, b = y - 1;
        if (Map[std::make_pair(a, b)]) continue;
        Ans[a]--; Ans[b + 1]++;
        Map[std::make_pair(a, b)] = true;
    }
    for (int i = 1; i <= N; ++i) {
        f[i] = f[i - 1] + Ans[i];
        std::cout << (f[i]) + H << "\n";
    }    
    return 0;
}