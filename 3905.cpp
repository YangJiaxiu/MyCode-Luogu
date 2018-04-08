#include<bits/stdc++.h>

const int MaxN = 100 + 10;
const int oo = 0x3f3f3f3f;

int n, m, Start, End;
int Dist[MaxN][MaxN], Weight[MaxN][MaxN];

void Init() {
    for (int i = 0; i <= n + 3; ++i) {
        for (int j = 0; j <= n + 3; ++j) {
            (i != j) ? Dist[i][j] = oo : Dist[i][j] = 0;
        }
    }
}

void Floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            }
        }
    }
}

void debug1() {
    for (int i = 0; i <= n + 3; ++i) {
        for (int j = 0; j <= n + 3; ++j) {
            std::cerr << Dist[i][j] << "   ";
        }
        std::cerr << "\n";
    }
    std::cerr << "\n\n";
}

int main() {
    std::cin >> n >> m;

    Init();

    for (int i = 1; i <= m; ++i) {
        int x, y, k;/* x：起点，y：终点，k：权值 */
        std::cin >> x >> y >> k;
        Weight[x][y] = Weight[y][x] = k;
        Dist[x][y] = Dist[y][x] = 0;
    }
    // debug1();

    
    int D;
    std::cin >> D;
    for (int i = 1; i <= D; ++i) {
        int x, y;
        std::cin >> x >> y;
        Dist[x][y] = Dist[y][x] = Weight[x][y];
    }
    // debug1();

    std::cin >> Start >> End;

    Floyd();

    std::cout << Dist[Start][End];
    return 0;
}