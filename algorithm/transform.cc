#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
  vector<double> deg_C{21.0, 30.5, 0.0, 3.2, 100.0};
  vector<double> deg_F(deg_C.size());
  vector<double> deg_F2;
  transform(std::begin(deg_C), std::end(deg_C), std::rbegin(deg_F),
            [](double temp) { return 32.0 + 9.0 * temp / 5.0; });
  transform(std::begin(deg_C), std::end(deg_C), std::back_inserter(deg_F2),
            [](double temp) { return 32.0 + 9.0 * temp / 5.0; });
  cout << "deg_F: " << endl;
  copy(deg_F.begin(), deg_F.end(), ostream_iterator<double>(cout, ","));
  cout << endl;
  cout << "deg_F2: " << endl;
  copy(deg_F2.begin(), deg_F2.end(), ostream_iterator<double>(cout, ","));
  cout << endl;
  vector<string> words{"one", "two", "three", "four", "five"};
  vector<size_t> hash_values(words.size());
  auto end_iter = transform(words.begin(), words.end(), hash_values.begin(),
                            hash<string>());
  copy(begin(hash_values), end(hash_values),
       ostream_iterator<size_t>(cout, " "));
  return 0;
}
