#include<iostream>
#include<vector>
#include<queue>

std::priority_queue< int, std::vector< int >, std::greater< int > > q;

int N;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::cin >> N; 
    int flag;
    for (int i = 1; i <= N; ++i) {
        std::cin >> flag;
        switch (flag) {
            case 1: {
                int temp;
                std::cin >> temp;
                q.push(temp);
                break;
            }
            case 2: {
                std::cout << q.top() << "\n";
                break;
            }
            case 3: {
                q.pop();
                break;
            }
        
        } 
    }
    return 0;
}