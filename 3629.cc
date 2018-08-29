#include "/Users/yjx/stdc++.h"

const int MaxN = 100000 + 10;
const int MaxM = MaxN * 2;

int n, k, v[MaxM], next[MaxM], last[MaxN], edgeNum = 1, p = 0, q = 0, maxLen = 0, weight[MaxM], dis[MaxN];

inline int GetInt() {
    int x = 0, f = 1; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

inline void AddEdge(const int &x, const int &y, const int &w) {
    v[++edgeNum] = y;
    next[edgeNum] = last[x];
    weight[edgeNum] = w;
    last[x] = edgeNum;
}

bool visit[MaxN];

void DFS1(int now, int len) {
    visit[now] = true;
    if (len > maxLen) {
        p = now;
        maxLen = len;
    }
    dis[now] = len;

    for (int i = last[now]; i; i = next[i]) {
        int end = v[i];
        if (!visit[end]) {
            DFS1(end, len + weight[i]);
        }
    }
    visit[now] = false;
}


int MarkEdgeDfs(const int &now) {

    if (!dis[now]) return 1;
    for (int i = last[now]; i; i = next[i]) {
        int end = v[i];
        // std::cerr << "QAQ" << v[i] << "\n";
        if (dis[end] == dis[now] - 1) {
            if (MarkEdgeDfs(end)) {
                weight[i] = weight[i ^ 1] = -1;
                // std::cerr << "QAQQAQ\n";
                return 1;
            }
        }
    }
    return 0;
}

void DP(const int &now) {
    visit[now] = 1;
    for (int i = last[now]; i; i = next[i]) {
        int end = v[i];
        if (visit[end]) continue;
        DP(end);
        maxLen = std::max(maxLen, dis[now] + dis[end] + weight[i]);
        // std::cerr << "mx == " << maxLen << "\n";
        dis[now] = std::max(dis[now], dis[end] + weight[i]);
    }
}

inline void debug1() {
    for (int i = 1; i <= edgeNum + 5; ++i) {
        // std::cerr << "weight[" << i << "] == " << weight[i] << "\n";
    }
}

int main() {
    n = GetInt(); k = GetInt();
    int ans = 2 * (n - 1);
    for (int i = 1; i <= n - 1; ++i) {
        int x = GetInt(), y = GetInt();
        AddEdge(x, y, 1); AddEdge(y, x, 1);
    }
    memset(visit, false, sizeof visit);
    DFS1(1, 0);
    maxLen = -1e9;
    memset(dis, 0, sizeof dis);
    DFS1(p, 0);
    ans = ans - maxLen + 1;
    if (k == 1) {
        std::cout << ans << std::endl;
        return 0;
    }
    // std::cerr << "p == " << p << "dist == " << dis[p] << "\n";
    MarkEdgeDfs(p);
    debug1();
    maxLen = 0;
    memset(visit, false, sizeof visit);
    memset(dis, 0, sizeof dis);
    DP(1);
    std::cout << ans - maxLen + 1;
    return 0;
}

/*本做法只寻找树的直径, 预计得分30分*/