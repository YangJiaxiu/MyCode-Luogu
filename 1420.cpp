#include<bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    long long last, temp = 1, ans = 0;
    std::cin >> last;
    for (int i = 1; i < n; ++i) {
        int x;
        std::cin >> x;
        if (x == last + 1) {
            temp++;
        } else {
            if (temp > ans) ans = temp;
            temp = 1;
        }
/*         std::cerr << "last = " << last
                  << "temp = " << temp
                  << "ans = " << ans << "\n";  */       
        last = x;
    }
    std::cout << ans;
    return 0;
}