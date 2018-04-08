#include<bits/stdc++.h>

int main() {
    int k;
    bool f = false;
    std::cin >> k;
    for (int i = 10000; i <= 30000; ++i) {
        int sub1 = (i/10000)*100 + (i/1000%10)*10 + (i/100%10), 
            sub2 = (i/1000%10)*100 + (i/100%10)*10 + (i%100/10),
            sub3 = (i/100%10)*100 + (i%100/10)*10 + (i%10);

        if ((sub1 % k == 0)
         && (sub2 % k == 0)
         && (sub3 % k == 0)) {
             f = true;
             std::cout << i << std::endl;
         }
    }
    if (f == false) std::cout << "No";
    return 0;
}