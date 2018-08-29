#include "/Users/yjx/stdc++.h"

const int MaxN = 1e5 + 10;

int n, m, q, u, v, t, a[MaxN];

double p;

struct cmp {
    inline bool operator ()(const int &a, const int &b) {
        return a < b;
    }
};

std::priority_queue<int, std::vector<int>, cmp> earthworm;// 听说这是蚯蚓的英文名, ~~很像“地球虫” 啊233~~

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> n >> m >> q >> u >> v >> t;
    p = (double)u / v;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        earthworm.push(a[i]);
    }
    int sigma = 0;
    for (int i = 1; i <= m; ++i) {
        if (i % t == 0) {
            std::cout << earthworm.top() + sigma << " ";
        }
        int sampleWorm = earthworm.top() + sigma; earthworm.pop();
        int U = floor(p * sampleWorm), V = sampleWorm - U;
        U -= sigma; V -= sigma;
        U -= q; V -= q;
        sigma += q;
        earthworm.push(U);
        earthworm.push(V);

    }
    std::cout << "\n";
    for (int i = 1; i <= n + m; ++i) {
        if (i % t == 0) {
            std::cout << earthworm.top() + sigma << " ";
        }
        earthworm.pop();
    }
    std::cout << std::endl;
    return 0;
}