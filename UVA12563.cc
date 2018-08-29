#include "/Users/yjx/stdc++.h"

const int MaxN = 50 + 10;
const int MaxTime = 100000 + 10;

int ans1[MaxTime], ti[MaxN];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    int cnt = 0;
    while (T--) {
        cnt++;
        memset(ans1, 0x8f, sizeof ans1);
        int N, t;
        std::cin >> N >> t;
        for (int i = 1; i <= N; ++i) std::cin >> ti[i];
        ans1[0] = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = t - 1; j >= ti[i]; --j) {
                if (ans1[j - ti[i]] + 1 > ans1[j]) {
                    ans1[j] = ans1[j - ti[i]] + 1;
                }
                // std::cerr << j << "  " << ans1[j] << "\n";
            }
            // std::cerr << "  \n\n";
        }
        int ans2 = t - 1;
        for (int i = t - 1; i >= 0; --i) {
            if (ans1[i] > ans1[ans2] || (ans1[i] == ans1[ans2] && i > ans2)) {
                ans2 = i;
            }
            // std::cerr << "ans2 = " << ans2 << " i = " << i << "\n";
            // std::cerr << i << "  " << ans1[i] << "\n";
        }
        std::cout << "Case " << cnt << ": " << ans1[ans2] + 1 << " " << ans2 + 678 << "\n";
    }
    return 0;
}