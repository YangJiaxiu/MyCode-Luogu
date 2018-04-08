/* #include<bits/stdc++.h>

typedef long long Int64;

const int MaxN = 1e5 + 10;
const Int64 INF = 0x3f3f3f3fLL;
int n;
Int64 a[MaxN] = {0}, 
      test1[MaxN] = {0},
      test2[MaxN] = {0};


inline bool judge_1() {
    int Time = 0;    
    for (int i = 2; i < n; i += 2) {
        if (!((test1[i - 1] <= test1[i]) && (test1[i] >= test1[i + 1]))) {
            test1[i] = INF;
            Time++;
        }
        if (Time > 1) return false;
    }
    return true;
}

inline bool judge_2() {
    int Time = 0;
    for (int i = 2; i < n; i += 2) {
        if (!((test2[i - 1] >= test2[i]) && (test2[i] <= test2[i + 1]))) {
            test2[i] = -INF;
            Time++;
        }
        if (Time > 1) return false;
    }
    return true;
}

inline void debug1() {
    for (int i = 1; i <= n; ++i) {
        std::cerr << test1[i] << "  ";
    }
    std::cerr << "\n";
    for (int i = 1; i <= n; ++i) std::cerr << test2[i] << "   ";
    std::cerr << "\n\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    while (std::cin >> n) {
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            test2[i] = test1[i] = a[i];
        }
        
        (judge_1() || judge_2()) ? std::cout << "Yes\n" : std::cout << "No\n";
        debug1();
    }
    return 0;
} */
#include<bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    
    return 0;
}