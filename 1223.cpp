#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cstdio>

const int MaxN = 1000 + 10;

struct Peo {
    int timePeo, num;//timePeo：此人用的时间； num：此人的序号
}a[MaxN];

inline bool compare (const Peo &a, const Peo &b) {
    return a.timePeo < b.timePeo;
}

int n;
double sum = 0;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i].num = i;
        std::cin >> a[i].timePeo;
    }

    std::sort(a + 1, a + n + 1, compare);

    for (int i = 1;  i <= n; ++i) {
        std::cout << a[i].num << " ";
        sum += a[i].timePeo * (n - i);
    }
    std::cout << "\n";
    sum /= n;
    printf("%0.2f\n", sum);
    // std::cout << std::ios::fixed << std::setprecision(2) << (double)sum << std::endl;
    return 0;
}