#include<bits/stdc++.h>

inline bool isPrime(int x) {
    if (x == 1) return false;
    if (x == 2) return true;
    for (int i = 3; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n; 
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (isPrime(i) && (n % i == 0)) {
            std::cout << n / i;
            break;
        }
    }
    return 0;
}