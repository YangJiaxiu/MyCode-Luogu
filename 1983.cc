#include "/Users/yjx/stdc++.h"

const int MaxM = 1000 + 10;
const int MaxN = 1000 + 10;

inline int GetInt() {
    int x = 0, f = 1; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

int n, m, trainStop[MaxM], nextNode[MaxN][MaxN]; // trainStop[0]表示此班列车停靠站的个数

int isEdge[MaxN][MaxN], f[MaxN];

int dfs(const int &x) {
    if (f[x]) return f[x];
    for (int i = 1; i <= nextNode[x][0]; ++i) {
        f[x] = std::max(f[x], dfs(nextNode[x][i]));
    }
    return ++f[x];
}

int main() {
    n = GetInt(); m = GetInt();
    for (int i = 1; i <= m; ++i) {
        trainStop[0] = GetInt();
        for (int j = 1; j <= trainStop[0]; ++j) {
            trainStop[j] = GetInt();
        }
        int stop = 1;
        for (int j = trainStop[1]; j < trainStop[trainStop[0]]; ++j) {
            if (trainStop[stop] == j) {
                stop++;
            } else {
                for (int k = 1; k <= trainStop[0]; ++k) {
                    if (!isEdge[trainStop[k]][j]) {
                        nextNode[trainStop[k]][0]++;
                        nextNode[trainStop[k]][nextNode[trainStop[k]][0]] = j;
                        isEdge[trainStop[k]][j] = true;
                    }
                }
            }
        }
    }
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, dfs(i));
    }
    std::cout << ans;
    return 0;
}