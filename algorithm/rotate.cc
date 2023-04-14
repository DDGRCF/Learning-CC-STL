#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> words{"one",  "two", "three", "four",
                       "five", "six", "seven", "eight"};
  auto iter =
      std::rotate(std::begin(words), std::begin(words) + 3, std::end(words));

  std::copy(std::begin(words), std::end(words),
            std::ostream_iterator<string>{std::cout, " "});

  std::cout << std::endl
            << "First element before rotation: " << *iter << std::endl;

  iter = rotate(words.begin(), words.begin() + 1, words.begin());
  std::copy(std::begin(words), std::end(words),
            std::ostream_iterator<string>{std::cout, " "});

  std::cout << std::endl
            << "First element before rotation: " << *iter << std::endl;
  vector<string> new_words;
  rotate_copy(words.begin(), words.begin() + 3, words.end(),
              back_inserter(new_words));
  copy(new_words.begin(), new_words.end(), ostream_iterator<string>(cout, ","));
  cout << endl;

  return 0;
}
