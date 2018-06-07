#include<iostream>

const int MaxN = 20 * 20;

struct UnionFindSet {
    int father[MaxN];
    inline void Init(const int &size) {
        for (int i = 1; i <= size; ++i) father[i] = i;
    }
    inline int Find(int x) {
        return (father[x] == x) ? x : father[x] = Find(father[x]);
    }
};

struct Edge {
    int u, v, weight;
} edge[MaxN * MaxN];

int numEdge = 0, n;

inline int Krushal() {

    return ans;
}

inline void AddEdge(const int &x, const int &y, const int &weight) {

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            std::cin >> x;
            if (i > j) {
                AddEdge(i, j, x);
            } 
        }
    }
    return 0;
}