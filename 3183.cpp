#include<bits/stdc++.h>

const int MaxM = 200000 + 100;
const int MaxN = 100000 + 100;

int N, M, num, ans = 0;
int Last[MaxM] = {0}, In[MaxM], Out[MaxM], f[MaxN];
/* In和Out可形象地理解为：点i接收或发出的边*/
struct edge {
    int to, last;
}Edge[MaxM];
/* to：边i的终点;last：与这条边同起点的 上一条边的序号; */
void addEdge(int u, int v) {
    Edge[++num].to = v, Edge[num].last = Last[u], Last[u] = num;
}
/* point字面意思上是点，在这里则表示：搜到了哪个点 */
int dfs(int point) {
    if (f[point]) return f[point];
    int ans = 0;
    if ((!Out[point]) && (In[point])) {
        ans++;
    }
    for (int i = Last[point]; i; i = Edge[i].last) {
        int v = Edge[i].to;
        ans += dfs(v);
    }
    return f[point] = ans;
}

int main() {
    std::cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        int u, v;
        std::cin >> u >> v;
        In[v]++ , Out[u]++;
        addEdge(u, v);
    }

    for (int i = 1; i <= M; ++i) {
        if ((Out[i]) && (!In[i])) ans += dfs(i);
    }

    std::cout << ans;

    return 0;
}