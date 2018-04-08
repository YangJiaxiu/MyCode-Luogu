#include<bits/stdc++.h>

typedef long long Int64;

const int MaxN = 2e5 + 10;
const int MaxM = 2e5 + 10;
const Int64 oo = 999999999999LL;

struct Range {
    int left, right;
}range[MaxM];

Int64 v[MaxN], w[MaxN], num[MaxN], sumValue[MaxN],
      n, m, S, minWeight = oo, maxWeight = -oo;

template<typename _T> 
    inline _T MyAbs(_T a) {
        return (a >= 0) ? a : -a;
    }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> S;
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i] >> v[i];
        minWeight = std::min(minWeight, w[i]);
        maxWeight = std::max(maxWeight, w[i]);
    }
    for (int i = 1; i <= m; ++i) {
        std::cin >> range[i].left >> range[i].right;
    }

    Int64 left = minWeight - 1, right = maxWeight + 1;
    Int64 ans = oo;
    while (left <= right) {
        Int64 mid = (left + right) >> 1;
        memset(num, 0, sizeof(num)); memset(sumValue, 0, sizeof(sumValue));
        for (int i = 1; i <= n; ++i) {
            if (w[i] >= mid) {
                num[i] = num[i - 1] + 1;
                sumValue[i] = sumValue[i - 1] + v[i];
            } else {
                num[i] = num[i - 1];
                sumValue[i] = sumValue[i - 1];
            }
        }
        Int64 sum = 0;
        for (int i = 1; i <= m; ++i) {
            sum += (sumValue[range[i].right] - sumValue[range[i].left - 1]) * 
                   (num[range[i].right] - num[range[i].left - 1]);
        }

        ans = std::min(ans, MyAbs(S - sum));

        if (sum > S) {
            left = mid + 1;            
        } else {
            right = mid - 1;            
        }
    }
    std::cout << ans << std::endl;
    return 0;
}