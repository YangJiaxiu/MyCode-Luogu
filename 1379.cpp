#include<iostream>
#include<deque> 
#include<string>
#include<set>

struct Status {
    std::string now;// 这个状态的“棋盘”
    int step;// 当前的步数
} start;

std::multiset< std::string > Board;

int FindZero(const std::string &s) {
    for (int i = 0; i < 9; ++i) if (s[i] == '0') return i;
    return -1;
}

std::string NextBoard(std::string board, const int &way) {
    int zero = FindZero(board);
    if ((way == 0 && zero == 0) || (way == 1 && zero == 9 - 1)) return "failed";
    (way == 0) ? std::swap(board[zero - 1], board[zero]) : std::swap(board[zero], board[zero + 1]);
    return board;
}

int BFS() {
    std::deque< Status > Q;
    Q.push_back(start);
    while (!Q.empty()) {
        Status root = Q.front();
        Q.pop_front();
        if (root.now == "123804765") return root.step;
        for (int i = 0; i < 2; ++i) {
            Status next;
            next.now = NextBoard(root.now, i);
            if (next.now == "failed" || Board.count(next.now)) continue;
            next.step = root.step + 1;
            Board.insert(next.now);
            Q.push_back(next);
            std::cerr << next.now + "\n";
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> start.now;
    Board.insert(start.now);
    std::cout << BFS();
    return 0;
}