#include<bits/stdc++.h>

std::string Jam;
int s, t, w;

int main() {
    // freopen("c://YangJiaxiu/luogu/2.in", "r", stdin);
    std::cin >> s >> t >> w;
    std::cin >> Jam;
    for (int i = 0; i < 5; ++i) {
        for (int j = w - 1; j >= 0; --j) {
            /* j - w + t表示：表示位置j所能表示的最大数字，当前位置 - 数字的位数 + 最后的位置 */
            if ((Jam[j] - 'a' + 1) <= (j - w + t)) {
                Jam[j]++;

                for (int k = j + 1; k < w; ++k) 
                    Jam[k] = Jam[k - 1] + 1;
                
                std::cout << Jam << std::endl;
                break;
            }
        }
    }
    return 0;
}