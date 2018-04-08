#include<bits/stdc++.h>

const int MAXN = 30 + 20;
int N,V;//N：有N件事可以做；V:亲密程度。。
int A[MAXN] = {0},B[MAXN] = {0};//A：小明做第i件事时，对小红增加的好感度。B:反之；
int ans = 0;//ans表示所求得的“好感度之差的最小绝对值”
bool flag(false);//flag表示有无在一起的情况；

inline void getInt(int &ans) {
    int f = 1, x = 0; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch < '0' || ch > '9');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    (f == 1) ? ans = x : ans = -x;
}

void dfs(int dep,int m_h,int h_m) {//dep：枚举第i件事；m_h：小明对小红的感情；h_m:反之。
    if (dep > N) {
        if (m_h + h_m >= V) {//记录有无答案及最优答案；p.s.2：上下两个if要注意条件。
            flag = true;
            if (abs(m_h - h_m) < ans) {
                ans = abs(m_h - h_m);
            }
        }
        return;
    } else {
        //for (int i = dep; i <= N; ++i) {//枚举从i + 1到n的每一件事情。p.s：这里的i的初值要小心，一开始我错了,i的初值为dep + 1;然后我将i的初值改成现在这样，下面再dep + 1，间接改变i的初值。
            dfs(dep + 1, m_h + A[dep] , h_m + B[dep]);//做这件事所能得到的感情
            dfs(dep + 1, m_h , h_m);//不做。。
        //}
    }
}

void init() {//读入。。
    scanf("%d %d",&N,&V);
    for (int i = 1;i <= N;++i) {
        getInt(A[i]);
        getInt(B[i]);
    }
}

void work() {//开始搜索
    ans = (1 << 30) - 1;//答案一开始总是要设得很大的嘛。。
    
    dfs(1,0,0);//预计用深搜，枚举每一件事造成的“亲密程度”，dep = 1，从第一件事开始，反正后面的i从这件事开始枚举。。后两个0，0表明互相之间没有感情。
}

void print() {
    if (flag == false) {//感情不能达到V（还做什么cp啊。。（逃
        ans = -1;//依题意，输出-1；
    }
    printf("%d",ans);
}

int main() {
    init();
    work();
    print();
    return 0;
}