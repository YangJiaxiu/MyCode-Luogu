#include<bits/stdc++.h>
using namespace std;

set< int, vector<int>, greater<int> > ran;
int N;

int main() {
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        int x;
        std::cin >> x;
        ran.insert(x);
    }
    std::cout << ran.size() << "\n";
    while (!ran.empty()) {
        std::cout << *(ran.begin()) << " ";
        ran.erase(ran.begin());
    }
    return 0;
}