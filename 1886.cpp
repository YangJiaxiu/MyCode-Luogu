#include<bits/stdc++.h>

using namespace std;

inline int read() {
    int f=1,x=0;char ch;
    do {ch=getchar();if(ch=='-')f=-1;} while(ch<'0'||ch>'9');
    do {x=x*10+ch-'0';ch=getchar();} while(ch>='0'&&ch<='9');
    return f*x;
}

const int MaxN = 1e6 + 100;

struct Data {
    int number, pos;
};

int n, k;
int data[MaxN];
deque< Data > ans;

int main() {
    n = read();
    k = read();
    for (int i = 1; i <= n; ++i) data[i] = read();
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        Data m = {data[i], i};
        while (!(ans.empty()) && (ans.back().number > data[i])) ans.pop_back();
        ans.push_back(m);
        if (i >= k) { 
            if (ans.front().pos <= (i - k)) ans.pop_front();
            std::cout << ans.front().number << " ";
        }
    }
    std::cout << "\n";
    ans.clear();    
    for (int i = 1; i <= n; ++i) {
        Data m = {data[i], i};
        while (!(ans.empty()) && (ans.back().number < data[i])) ans.pop_back();
        ans.push_back(m);
        if (i >= k) { 
            if (ans.front().pos <= (i - k)) ans.pop_front();
            std::cout << ans.front().number << " ";
        }
    }

    return 0;
}