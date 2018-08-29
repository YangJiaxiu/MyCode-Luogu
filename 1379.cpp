#include<iostream>
#include<deque>
#include<unordered_set>

const int MaxSize = 3 + 1;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int d[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

class Status {
    public:
        long long Board1;
        short Board2[MaxSize][MaxSize];
        int step = 0;
        void Board_1To2() {
            for (int i = 0; i < 9; ++i) {
                Board1 += Board2[i / 3][i % 3] * d[i];
            }
        }
        void Board_2To1() {
            for (int i = 0; i < 9; ++i) {
                Board2[i / 3][i % 3] = Board1 / d[i] % 10;
            }   
        }
};

std::unordered_set< Status > isAppear;

int Bfs(const Status &first) {
    std::deque< Status > Q;
    Q.push_back(first);
    while (!Q.empty()) {
        Status start = Q.front(); Q.pop_front();
        if (start.Board1 == 123804765LL) return start.step;
        if (isAppear.count(start)) continue;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (start.Board2[i][j] == 0) {
                    for (int way = 0; way < 4; ++way) {
                        int nextX = i + dx[way], nextY = j + dy[way];
                        if (nextX < 0 || nextY < 0 || nextX > 2 || nextY > 2) {
                            continue;
                        } else {
                            Status next = start;
                            next.step = start.step + 1;
                            std::swap(next.Board2[i][j], next.Board2[nextX][nextY]);
                            next.Board_2To1();
                            Q.push_back(next);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    Status first;
    std::cin >> first.Board1;
    first.Board_1To2();
    std::cout << Bfs(first);
    
    return 0;
}