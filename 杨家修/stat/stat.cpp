#include "/Users/yjx/stdc++.h"

std::string word, sentence;

void Init() {
  std::cin >> word;
  for (unsigned int i = 0; i < word.size(); ++i)
    if (word[i] >= 'A' && word[i] <= 'Z') word[i] = word[i] - 'A' + 'a';
  char c = '\0';
  do {
    c = getchar();
  } while (c == '\n' || c == '\r');
  std::getline(std::cin, sentence);
  sentence = c + sentence;
  for (unsigned int i = 0; i < sentence.size(); ++i)
    if (sentence[i] >= 'A' && sentence[i] <= 'Z')
      sentence[i] = sentence[i] - 'A' + 'a';
}

inline bool Begin(const unsigned int &x) {
  return (x < 1) ||
         ((sentence[x] >= 'a' && sentence[x] <= 'z') && sentence[x - 1] == ' ');
}

inline bool End(const unsigned int &x) {
  return (x + 1 > sentence.size()) ||
         ((sentence[x] >= 'a' && sentence[x] <= 'z') && sentence[x + 1] == ' ');
}

inline bool Middle(const unsigned int &x, const unsigned int &y) {
  return sentence[x] == word[y];
}

void Work() {
  unsigned int first = 0, times = 0, isUsed = false, k = 0, isFirst = false;
  for (unsigned int i = 0; i < sentence.size(); ++i) {
    // if (word.size() == 1) {
    //   if (Begin(i) && End(i)) {
    //     if (sentence[i] == word[0]) {
    //       isUsed = false;
    //       times++;
    //       std::cerr << "i == " << i << "\n";
    //       if (isFirst == false) {
    //         isFirst = true;
    //         first = i;
    //       }
    //       k = 0;
    //     }
    //   }
    // }
    if (End(i)) {
      if (sentence[i] == word[k]) {
        isUsed = false;
        times++;
        // std::cerr << "i == " << i << "\n";
        if (isFirst == false) {
          isFirst = true;
          first = i - word.size();
        }
        k = 0;
      }
    } else {
      isUsed = false;
    }

    if (Begin(i)) {
      if (sentence[i] == word[0]) {
        k = 1;
        isUsed = true;
      } else {
        isUsed = false;
      }
      continue;
    }

    if (Middle(i, k) && isUsed) {
      k++;
    } else {
      isUsed = false;
    }
  }
  (times) ? std::cout << times << " " << first : std::cout << -1;
}

int main() {
  // freopen("stat.in", "r", stdin);
  // freopen("stat.out", "w", stdout);
  Init();
  Work();
  return 0;
}