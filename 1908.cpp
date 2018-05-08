#include<iostream>

const int MaxN = 40000 + 10;

int a[MaxN], n, ans = 0, t[MaxN];

void MergeSort(int *a, int left, int right) {
    if (left == right) return;
    int mid = left + ((right - left) / 2);
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    int x = left, y = mid + 1, p = left;
    while (x <= mid && y <= right) {
        if (a[x] > a[y]) {
            t[p++] = a[y++];   
            ans += mid - x + 1;
        } else {
            t[p++] = a[x++];
            
        }
    }
    while (x <= mid) t[p++] = a[x++];
    while (y <= right) t[p++] = a[y++];
    for (int z = left; z <= right; ++z) a[z] = t[z];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = i + 1; j <= n; ++j) {
    //         if (a[i] > a[j]) ans++;
    //     }
    // }
    MergeSort(a, 1, n);
    std::cout << ans;
    return 0;
}