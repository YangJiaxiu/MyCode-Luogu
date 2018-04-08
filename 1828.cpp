#include<bits/stdc++.h>

/* 
   奶牛数N，
   牧场数（2<=P<=800），
   牧场间道路数C(1<=C<=1450)
   cowFarm:下标指的是：牧场的号码；cowFarm[i]指的是：牛（在牧场[i]）的数量
   dist数组第一维是起点，第二维是终点；
 */

const int MaxN = 800 * 2;
const int MaxP = MaxN;
const int oo = 0x3f3f3f3f;

int N, P, C, cowFarm[MaxN] = {0}, dist[MaxP][MaxP];

void floyd() {
    for (int k = 1; k <= P; ++k) {
        for (int i = 1; i <= P; ++i) {
            for (int j = 1; j <= P; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][j];
                }
            }
        }
    }
}

long long count(int farm) {
    long long ans = 0;
    for (int i = 1; i <= P; ++i) {
        if (cowFarm[i]) {
            ans += dist[i][farm] * cowFarm[i];
        }
    }
    return ans;
}

void debug1() {
    for (int i = 0; i <= P + 3; ++i) {
        for (int j = 0; j <= P + 3; ++j) {
            std::cerr << dist[i][j] << "   ";
        }
        std::cerr << "\n";
    }
    std::cerr << "\n\n\n\n";
}

int main() {
    std::cin >> N >> P >> C;
    for (int i = 1; i <= N; ++i) {
        int x;
        std::cin >> x;
        cowFarm[x]++;
    }
    for (int i = 0; i <= P + 10; ++i) {
        for (int j = 0; j <= P + 10; ++j) {
           (i != j) ? (dist[i][j] = oo) :  (dist[i][j] = 0);
        }
    }

    for (int i = 1; i <= C; ++i) {
        int x, y;
        std::cin >> x >> y; 
        std::cin >> dist[x][y]; 
        dist[y][x] = dist[x][y];
    }
    debug1();
    floyd();
    debug1();
    long long ans = oo;
    for (int i = 1; i <= P; ++i) {
        /* count函数是统计：以i为终点所累积的路的长度 */
        long long x = count(i);
        if (x < ans) ans = x;
    }

    std::cout << ans;
    return 0;
}