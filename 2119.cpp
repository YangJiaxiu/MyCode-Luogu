#include<iostream>

const int MaxN = 15000 + 10;
const int MaxM = 40000 + 10;

int N, M, num[MaxM], value[MaxM];
int a[MaxN], b[MaxN], c[MaxN], d[MaxN];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        std::cin >> value[i];
        num[value[i]]++;
    }

    for (int t = 1; 9 * t + 1 <= N; ++t) {
        int sum = 0;
        int va, vb, vc, vd;
        for (vd = 9 * t + 2; vd <= N; ++vd) {
            vc = vd - t;
            vb = vd - 7 * t - 1;
            va = vd - 9 * t - 1;
            sum += num[vb] * num[va];
            c[vc] += sum * num[vd];
            d[vd] += sum * num[vc];
        }
        sum = 0;
        for (va = N - 9 * t - 1; va >= 1; --va) {
            vb = va + 2 * t;
            vc = va + t * 8 + 1;
            vd = va + t * 9 + 1;
            sum += num[vc] * num[vd];
            a[va] += sum * num[vb];
            b[vb] += sum * num[va];
        }
    }

    for (int i = 1; i <= M; ++i) std::cout << a[value[i]] << " " << b[value[i]] << " " << c[value[i]] << " " << d[value[i]] << "\n";
    return 0;
}