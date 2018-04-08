#include<bits/stdc++.h>

const int MaxN = 1e5 + 10;

using Int64 = long long;

Int64 segmentTree[MaxN << 2], a[MaxN], tag[MaxN << 2];

inline Int64 lson(Int64 o) {
    return o << 1;
}

inline Int64 rson(Int64 o) {
    return o << 1 | 1;
}

inline void push_up(Int64 o) {
    segmentTree[o] = segmentTree[lson(o)] + segmentTree[rson(o)];
}

inline void mark(Int64 o, 
                 Int64 left, 
                 Int64 right, 
                 Int64 k) {
    tag[o] = tag[o] + k;    
    segmentTree[o] = segmentTree[o] + k * (right - left + 1);
}

inline void push_down(Int64 o, Int64 left, Int64 right) {
    Int64 mid = (left + right) >> 1;
    mark(lson(o), left, mid, tag[o]);
    mark(rson(o), mid + 1, right, tag[o]);
    tag[o] = 0;
}

inline void Build(int left,
                  int right,
                  int o) {
    tag[o] = 0;
    if (left == right) {
        segmentTree[o] = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    Build(left, mid, lson(o));
    Build(mid + 1, right, rson(o));
    push_up(o);
}

inline void Updata(Int64 o, 
                   Int64 updataLeft, 
                   Int64 updataRight, 
                   Int64 left, 
                   Int64 right, 
                   Int64 k) {
    if (updataLeft <= left && right <= updataRight) {
        tag[o] += k;
        segmentTree[o] += k*(right - left + 1); 
        return;
    }
    push_down(o, left, right);
    Int64 mid = (left + right) >> 1;    
    if (updataLeft <= mid) Updata(lson(o), updataLeft, updataRight, left, mid, k);
    if (updataRight > mid) Updata(rson(o), updataLeft, updataRight, mid + 1, right, k);
    push_up(o);
}

inline Int64 Query(Int64 queryLeft, 
                   Int64 queryRight,
                   Int64 left,
                   Int64 right,
                   Int64 o) {
    if (queryLeft <= left && right <= queryRight) return segmentTree[o];
    Int64 mid = (left + right) >> 1;
    Int64 ans = 0;
    push_down(o, left, right);
    if (queryLeft <= mid) ans += Query(queryLeft, queryRight, left, mid, lson(o));
    if (queryRight > mid) ans += Query(queryLeft, queryRight, mid + 1, right, rson(o));
    return ans;
}

int N, M;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i) std::cin >> a[i];
    Build(1, N, 1);
    while (M--) {
        int flag;
        std::cin >> flag;
        if (flag == 1) {
            int x, y, k;
            std::cin >> x >> y >> k; 
            Updata(1, x, y, 1, N, k);
        } else {
            int x, y;
            std::cin >> x >> y;
            std::cout << Query(x, y, 1, N, 1) << std::endl;
        } 
    }
    return 0;
}