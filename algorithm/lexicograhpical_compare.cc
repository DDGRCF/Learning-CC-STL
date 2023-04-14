#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> a{"a", "b", "cd"};
  vector<string> b{"a", "b", "cc"};

  cout << boolalpha
       << lexicographical_compare(a.begin(), a.end(), b.begin(), b.end())
       << endl;
  ;
  return 0;
}
