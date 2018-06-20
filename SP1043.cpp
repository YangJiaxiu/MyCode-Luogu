#include<iostream>

const int MaxN = 500000 + 10;

struct SegmentTree {
    long long a[MaxN], tree[MaxN << 2], lazyTag[MaxN << 2];
    inline int lson(const int &o) {
        return o << 1;
    }
    inline int rson (const int &o) {
        return o << 1 | 1;
    }
    inline void PushUp(const int &o) {
        tree[o] = tree[lson(o)] + tree[rson(o)];
    }
    inline void Build(int o, int left, int right) {
        lazyTag[o] = 0;
        if (left == right) {
            tree[o] = a[left];
            return;
        }
        int mid = (left + right) >> 1;
        Build(lson(o), left, mid);
        Build(rson(o), mid + 1, right);
        PushUp(o);
    }
    inline void Mark(const int &o, int left, int right, long long k) {
        lazyTag[o] += k;
        tree[o] += k * (right - left + 1);
    }
    inline void PushDown(const int &o, int left, int right) {
        int mid = (left + right) >> 1;
        Mark(lson(o), left, mid, lazyTag[o]);
        Mark(rson(o), mid + 1, right, lazyTag[o]);
        lazyTag[o] = 0;
    }
    inline void Updata(const int &o, 
                       const int &updataLeft, 
                       const int &updataRight, 
                       int left, 
                       int right, 
                       long long k) {
        if (updataLeft <= left && updataRight >= right) {
            lazyTag[o] += k;
            tree[o] += k * (right - left + 1);
            return;
        }
        int mid = (left + right) >> 1;
        PushDown(o, left, right);
        if (updataLeft <= mid) Updata(lson(o), updataLeft, updataRight, left, mid, k);
        if (updataRight > mid) Updata(rson(o), updataLeft, updataRight, mid + 1, right, k);
        PushUp(o);
    }

    inline long long Query(const int &o, 
                           const int &queryLeft,
                           const int &queryRight,
                           int left,
                           int right) {
        
        if (queryLeft <= left && queryRight >= right) return tree[o];
        int mid = (left + right) >> 1;
        long long ans = 0;
        PushDown(o, left, right);
        if (queryLeft <= mid) ans += Query(lson(o), queryLeft, queryRight, left, mid);
        if (queryRight > mid) ans += Query(rson(o), queryLeft, queryRight, mid + 1, right);
        return ans;
    }
} Tree;

int main() {
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i) std::cin >> Tree.a[i];
    Tree.Build(1, 1, N);
    
    while (M--) {
        int flag;
        std::cin >> flag;
        if (flag == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;
            Tree.Updata(1, x, y, 1, N, k);
        } else {
            int x, y;
            std::cin >> x >> y;
            std::cout << Tree.Query(1, x, y, 1, N) << "\n";
        }
    }
    return 0;
}