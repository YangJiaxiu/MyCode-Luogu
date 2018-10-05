#include <iostream>
#include <cstdio>
#include <map>
#include <string>

const long long MaxK = 15 + 10;

std::map<std::string, long long> m;

long long k, a[MaxK], b[MaxK], ans;
std::string n;

void dfs(std::string s) {
    if (!m[s]) {
        ans++;
        m[s]++;
    }
    for (long long i = 1; i <= k; ++i) {

        for (long long j = 0; j < s.size(); ++j) {
            if (s[j] == a[i] + '0') {
                s[j] = b[i] + '0';
                dfs(s);
                s[j] = a[i] + '0';
            }
        }
    }
}

int main() {
    freopen("P3.in", "r", stdin);
    // freopen("P3.ans", "w", stdout);
    std::cin >> n >> k;
    for (long long i = 1; i <= k; ++i) std::cin >> a[i] >> b[i];
    dfs(n);
    std::cout << ans;
    return 0;
}

/*
 * 这题的规则可以只改变其中一部分.
 * hack:
 * 222 2
 * 2 3
*/
