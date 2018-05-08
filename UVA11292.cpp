#include<iostream>
#include<algorithm>

const int MaxN = 20000 + 10;
const int MaxM = 20000 + 10;

int a[MaxN], b[MaxM];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    while ((std::cin >> n >> m) && n && m) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::sort(a, a + n);
        for (int i = 0; i < m; ++i) std::cin >> b[i];
        std::sort(b, b + m);
        for (int i = 0; i < m; ++i) {
            if (b[i] >= a[cnt]) {
                ans += b[i];
                if (++cnt == n) break;
            }
        }
        (cnt >= n) ? std::cout << ans << std::endl : std::cout << "Loowater is doomed!" << std::endl;
    }
    return 0;
}