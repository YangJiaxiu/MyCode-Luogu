/* 
    主要思路：
    我们要明确：能确定排名的人 其实就相当于：入度 + 出度 = N - 1
    可以先琢磨一下这个式子，（其实也不算太难），（先想上几分钟再往下看）

    提示一下：我们的边是从胜利者指向失败者。。

    好了公布答案：入度 => 这头奶牛被打败了(注意“被”字)， 出度 => 这头奶牛打败了其它奶牛
                 N - 1 => 除了这只奶牛之外的其它奶牛；
    （其实这个思路我也是从楼下的题解中看(chao)的）

    程序流程：

    先跑Floyd，（跑Floyd可以明确所有点之间的关系（即使是间接到达的））

    然后再统计每个点的入、出度，查每个点，假设符合上面说的式子，ans++

    最后，cout << ans;

 */



#include<iostream>
#include<algorithm>


const int oo = 0x3f3f3f3f;
const int MaxN = 100 + 30;

/* dist：第一维：起点；第二维：终点
   haveGame[i]：奶牛i的入、出度的总和
    N:有N头奶牛 => （结）点
   M:有M轮比赛 => （有向）边
 */
 
int N, M, dist[MaxN][MaxN], haveGame[MaxN], ans = 0;

void Floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dist[i][j] =std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}/* 跑floyd */


void Init() {
    for (int i = 0; i <= N + 10; ++i) {
        for (int j = 0; j <= N + 10; ++j) {
            (i != j) ? dist[i][j] = oo : dist[i][j] = 0;
        }
    }
}/* 跑Floyd的初始工作 */

void debug1() {
    for (int i = 0; i <= N + 3; ++i) {
        for (int j = 0; j <= N + 3; ++j) {
            std::cerr << dist[i][j] << "   ";
        }
        std::cerr << "\n";
    }
    std::cerr << "\n\n\n\n";
}

void debug2() {
    for (int i = 0; i <= N + 3; ++i) std::cerr << haveGame[i] << "  ";
    std::cerr << "\n\n";
}

int main() {
    std::cin >> N >> M;

    Init();

    for (int i = 1; i <= M; ++i) {
        int x, y;
        std::cin >> x >> y;
        dist[x][y] = 1;
    }

    Floyd();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            /* 判断的时候一定要注意要大于0 */
            if ((dist[i][j] != oo) && (dist[i][j] > 0)) {
                haveGame[i]++;
                haveGame[j]++;
            }
        }
    }

    for (int i = 0; i <= N; ++i) {
        if (haveGame[i] == N - 1) ans++;
    }
    std::cout << ans;

    return 0;
}