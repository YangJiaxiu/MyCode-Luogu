/* 本题已保证每个参赛者都能在一个时段内完成 */

#include<bits/stdc++.h>

const int MaxN = 500 + 50;

int m, n;

struct Game {
    int time;/*  表示这个游戏所在的时间段 */
    int money;/* 表示完不成这个游戏的扣款数 */
}a[MaxN];


inline bool operator < (const Game &a, const Game &b) {
    return (a.money > b.money);
    if (a.money == b.money) return (a.time < b.time);
}


inline void debug1() {
    for (int i = 1; i <= n; ++i) {
        printf("time = %d money = %d\n", a[i].time, a[i].money);
    }
}

int ans = 0;
bool Time[MaxN] = {false};

int main() {
    std::cin >> m >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i].time;
    for (int i = 1; i <= n; ++i) std::cin >> a[i].money;

    std::sort(a + 1, a + n + 1);
    // debug1();

    for (int i = 1; i <= n; ++i) {
        bool f = false;/* f表示判定这个游戏能不能玩，
                         true表示能，false表示不能 */
        for (int j = a[i].time; j >= 1; --j) {
            if (Time[j] == false) {
                Time[j] = true;
                f = true;
                break;
            }
        }
        if (f == false) ans += a[i].money;        
    }

    std::cout << m - ans << std::endl;
    return 0;
}