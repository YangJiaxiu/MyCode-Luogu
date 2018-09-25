#include <bits/stdc++.h>

std::string word, sentence;

void Init() {
  std::cin >> word;
  for (int i = 0; i < word.size(); ++i)
    if (word[i] >= 'A' && word[i] <= 'Z') word[i] = word[i] - 'A' + 'a';
  char c = '\0';
  do {
    c = getchar();
  } while (c == '\n' || c == '\r');
  std::getline(std::cin, sentence);
  sentence = c + sentence;
  for (int i = 0; i < sentence.size(); ++i)
    if (sentence[i] >= 'A' && sentence[i] <= 'Z')
      sentence[i] = sentence[i] - 'A' + 'a';
}

void Work() {
  int first = 0, times = 0, isUsed = false, k = 0, isFirst = false, t = 0;
  for (int i = 0; i < sentence.size(); ++i) {
    if ((i - 1 < 0 || sentence[i - 1] == ' ')) {
      isUsed = true;
      t = i;
    }
    if ((sentence[i] != word[k] || k >= word.size())) {
      isUsed = false;
      k = 0;
    } else {
      k++;
    }
    if ((i + 1 >= sentence.size() || sentence[i + 1] == ' ') && isUsed) {
      times++;
      k = 0;
      if (!isFirst) {
        isFirst = true;
        first = t;
      }
    }
  }
  (times) ? std::cout << times << " " << first : std::cout << -1;
}

int main() {
  freopen("stat.in", "r", stdin);
  freopen("stat.out", "w", stdout);
  Init();
  Work();
  return 0;
}