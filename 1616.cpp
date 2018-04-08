#include<bits/stdc++.h>

const int MaxT = 100000 + 100;
const int MaxM = 10000 + 10;

inline int getInt() {
    int f = 1, x = 0; char ch;
    do{ch = getchar(); if (ch == '-')f = -1;} while (ch < '0' || ch > '9');
    do{x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');	
    return f*x;
}

int T, M, f[MaxT] = {0}, cost[MaxM], weight[MaxM];
//cost表示第[i]件的费用 
//weight表示第[i]件的价值 
int main() {
    T = getInt();
    M = getInt();
    
    for (int i = 1; i <= M; ++i) {
        cost[i] = getInt();
        weight[i] = getInt();
    }
    
    for (int i = 1; i <= M; ++i) {
        for (int j = cost[i]; j <= T; ++j) {
            f[j] = std::max(f[j], f[j - cost[i]] + weight[i]);
        }
    }
    
    std::cout << f[T];
    return 0;
}