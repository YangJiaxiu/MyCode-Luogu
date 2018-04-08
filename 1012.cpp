#include<bits/stdc++.h>

const int MaxN = 20 + 5;
int n;
std::string Num[MaxN];
/* 
inline bool cmp(const std::string &a, const std::string &b) {
    unsigned int len = std::min(a.size(), b.size());
    for (int i = 0; i < len; ++i) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    if (a.size() < b.size()) return true; else return false;
}
 */

inline bool cmp(const std::string &a, const std::string &b) {
    return (a + b) < (b + a);
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> Num[i];
    }
    sort(Num + 1, Num + n + 1, cmp);
    for (int i = n; i >= 1; --i) {
        std::cout << Num[i];
    }
    return 0;
}