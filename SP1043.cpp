#include<iostream>

const int MaxN = 50000 + 10;

int N, M;

struct FenwickTree {
    int a[MaxN], C[MaxN];
    void Init() {
        memset(a, 0, sizeof(a));
        memset(C, 0, sizeof(C));
    }

    int LowBit(const int &x) {
        return x & (-x);
    }

    void Add(int x, int d) {
        while (x <= N) {
            C[x] += d;
            x += LowBit(x);
        }
    }

    int Query(int x) {
        int ans = 0;
        while (x > 0) {
            ans += C[x];
            x -= LowBit(x);
        }
        return ans;
    }
} Tree;

void debug1() {
    for (int i = 0; i <= N; ++i) std::cerr << Tree.C[i] << "  ";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N;
    Tree.Init();
    for (int i = 1; i <= N; ++i) {
        std::cin >> Tree.a[i];
        Tree.Add(i, Tree.a[i]);
    }
    debug1();
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int x, y;
        std::cin >> x >> y;
        std::cout << Tree.Query(y)/* - Tree.Query(x - 1)*/ << "\n";
    }
    return 0;
}