/* 坑点1：不能预先计算两块石头间的差值，因为：假设撤掉石头之后，两块石头间的差会发生变动
 */



#include<bits/stdc++.h>

const int MaxN = 50000 + 100;
/* L：总的路程的距离，
   N：石头的个数， 
   M：组委会能移动的石头的个数
   Dist：Dist[i]表示石头[i]和石头[i - 1]的距离
    */
long long L;
long long N, M, ans = 0, D[MaxN];
/* 子程序中的dist表示二分枚举到的距离 */
inline bool check(int dist) {
    long long stone = 0, now = 0;

    for (int i = 1; i <= N + 1; ++i) 
        (D[i] - D[now] < dist) ? stone++ : now = i;
        
    return (stone <= M);/* 移动的石头数 <= 组委会能移动的石头数 */
}

int main() {
    std::cin >> L >> N >> M;
    for (int i = 1; i <= N; ++i) {
        std::cin >> D[i];
    }
    D[N + 1] = L;/*这一句是为了在上面子程序处理的时候
                   不用专门再写一句最后一个石头的距离
                   和终点比较的语句*/
    /* 根据题解大佬的说法这是二分模板（看起来还可以） */
    int mid, left = 1, right = L;
    while (left <= right) {
        mid = left + ((right - left) >> 1);
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << ans;
    return 0;
}