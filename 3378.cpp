#include<bits/stdc++.h>

using std::priority_queue;
using std::vector;

priority_queue< int, vector< int >, std::greater< int > > q;

inline void getInt(int &ans) {
    int f = 1, x = 0; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while(ch >= '0' && ch <= '9');
    ans = f * x;
}

int N;

int main() {
    getInt(N);
    int flag;
    for (int i = 1; i <= N; ++i) {
        getInt(flag);
        switch (flag) {
            case 1: {
                int temp;
                getInt(temp);
                q.push(temp);
                break;
            }
            case 2: {
                std::cout << q.top() << "\n";
                break;
            }
            case 3: {
                q.pop();
                break;
            }
        
        } 
    }
    return 0;
}