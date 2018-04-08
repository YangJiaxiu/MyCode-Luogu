#include<bits/stdc++.h>

const int hehe = 10000000;

long double sum = 0, x;

int main() {
    while ((std::cin >> x) && (x != 0)) sum += x * hehe;
    std::cout << std::fixed << std::setprecision(5) << sum / hehe;
    return 0;
}
/* 
#include<bits/stdc++.h>

const int hehe = 1000000; 

long double sum, x;

int main() {
    if (scanf("%lf", &x) != EOF) {
        sum += x * hehe;
        main();
    } else {
        printf("%.5Lf", sum / hehe);
    }
    return 0;
} */