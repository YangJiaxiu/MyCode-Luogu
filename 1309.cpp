#include<iostream>
#include<algorithm>

const int MaxN = 100000 + 10;

struct People {
    int s, w, num;
} people[2 * MaxN];

inline bool cmp(const People &a, const People &b) {
    if (a.s > b.s) {
        return true;
    } else {
        if (a.s == b.s) return a.num <= b.num;
    }
    return false;
}

int N, R, Q;

int main() {
    // freopen("/Users/yjx/Downloads/testdata-3.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    
    std::cin >> N >> R >> Q;
    for (int i = 1; i <= 2 * N; ++i) {
        std::cin >> people[i].s;
        people[i].num = i;
    }
    for (int i = 1; i <= 2 * N; ++i) std::cin >> people[i].w;

    std::stable_sort(people + 1, people + 1 + 2 * N, cmp);

    // for (int i = 1; i <= 2 * N; ++i) std::cerr << "s = " << people[i].s << " w = " << people[i].w << " num = " << people[i].num << "\n\n";

    while (R--) {
        for (int i = 1; i < 2 * N; i += 2) (people[i].w > people[i + 1].w) ? people[i].s++ : people[i + 1].s++;
        std::stable_sort(people + 1, people + 1 + 2 * N, cmp);
    }
    std::cout << people[Q].num;
    return 0;
}