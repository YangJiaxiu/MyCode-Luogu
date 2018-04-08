#include<bits/stdc++.h>

const int MaxN = 20 + 5;
const int MaxM = 20 + 5;
const int oo = 0x3f3f3f3f;
const int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2, 0};
const int dy[] = {2, 2, 1, -1, -2, -2, -1, 1, 0};

/* N和M可理解为：B点坐标，不要想成边界 */
int N, M, HorseX, HorseY;
bool a[MaxN][MaxM] = {false};
long long f[MaxN][MaxM] = {0};

inline bool Check(int x, int y) {
    return ((x >= 0) && (x <= N) && (y >= 0) && (y <= M));
}

void debug1() {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            std::cerr << f[i][j] << "  ";
        }
        std::cerr << "\n";
    }
    std::cerr << "\n\n";
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            std::cerr << a[i][j] << "  ";
        }
        std::cerr << "\n";
    }
    std::cerr << "\n\n";
}

int MinX = oo, MinY = oo;

int main() {
    std::cin >> N >> M >> HorseX >> HorseY;
    for (int i = 0; i < 9; ++i) {
        int x = HorseX + dx[i], y = HorseY + dy[i];
        bool flag = Check(x, y);
        if (flag) a[x][y] = true;
        if ((x == 0) && (flag)) MinY = std::min(MinY, y);
        if ((y == 0) && (flag)) MinX = std::min(MinX, x);
    }
    // std::cerr << MinX << "  " << MinY << "\n\n\n";
    f[0][0] = 1;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            // if (f[0][4] != 0) std::cerr << i << " " << j;
            if (a[i][j] == false) {
                if (Check(i - 1, j) && (Check(i, j - 1))) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                } else {
                    if (((i == 0) && (j > MinY)) || ((j == 0) && (i > MinX))) {
                        f[i][j] = 0;
                    } else {
                        f[i][j] = 1;
                    }
                }
            }
        }
    }
    // std::cerr << "\n\n";
    // debug1();
    std::cout << f[N][M];

    return 0;
}