#include<bits/stdc++.h>

const int MaxLetter = 26 + 10;
const int MaxDeep = 100 + 10;

int t, va[MaxLetter], nowVar[MaxDeep], nowComplex[MaxDeep], ce[MaxDeep];

inline int GetComp(std::string &s) {
    if (s[2] == '1') {
        return 0;
    } else {
        int ans = 0, i = 4;
        while (isdigit(s[i])) ans = ans * 10 + s[i++] - '0';
        return ans;
    }
}

inline int ToNum(std::string &s) {
    std::stringstream ss(s);
    int ans;
    ss >> ans;
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> t;
    while (t--) {
        int L, maxComplex = 0; std::string s; bool ERR = false;
        memset(va, false, sizeof(va));
        memset(ce, false, sizeof(ce));
        memset(nowComplex, false, sizeof(nowComplex));
        memset(nowVar, false, sizeof(nowVar));
        std::cin >> L >> s;
        int complex = GetComp(s), now = 0;
        ce[0] = 1;
        for (int i = 1; i <= L; ++i) {
            char F; 
            std::cin >> F;
            if (F == 'F') {
                
                char vari;
                std::cin >> vari;
                if (va[vari - 'a']) {
                    ERR = true;
                }
                va[vari - 'a']++;
                nowVar[++now] = vari - 'a';
                std::string x, y; int isNum_x = 0, isNum_y = 0, x_1 = 0, y_1 = 0;
                std::cin >> x >> y;
                if (ERR) continue;
                if (x == "n") {
                    isNum_x = 1;
                } else {
                    isNum_x = 2;
                    x_1 = ToNum(x);
                }
                if (y == "n") {
                    isNum_y = 1;
                } else {
                    isNum_y = 2;
                    y_1 = ToNum(y);
                }

                if ((isNum_x == 2) && (isNum_y == 1)) nowComplex[now] = nowComplex[now - 1] + ce[now - 1];
                else nowComplex[now] = nowComplex[now - 1];
                if (((isNum_x == 2) && (isNum_y == 2) && (x_1 > y_1)) || ((isNum_x == 1) && (isNum_y == 2))) ce[now] = 0;
                else ce[now] = ce[now - 1];

                maxComplex = std::max(maxComplex, nowComplex[now]);
            } else {
                if (ERR) continue;
                if (now == 0) ERR = true;
                va[nowVar[now--]]--;
            }
        }

        if (now || ERR) {
            std::cout << "ERR\n";
        } else { 
            if (maxComplex == complex) {
                std::cout << "Yes\n";
            } else {
            std::cout << "No\n";
            }
        }
    }
    return 0;
}