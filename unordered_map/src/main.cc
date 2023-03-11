#include <iostream>
#include <unordered_map>

using namespace std;

void test_unordered_map_emplace() {
  cout << "into " << __func__ << " ..." << endl;
  unordered_map<string, string> str_map{{"rcf", "1"}, {"wbk", "2"}};
  auto&& ret = str_map.emplace("sbc", "3");
  cout << boolalpha << ret.second << endl;
  cout << ret.first->first << " " << ret.first->second << endl;
  cout << "-------------------------------" << endl;
  auto&& it = str_map.emplace_hint(str_map.begin(), "sbc", "4");  // 插入失败
  cout << it->first << " " << it->second << endl;
  cout << "out " << __func__ << " ..." << endl;
}

int main() {
  test_unordered_map_emplace();
  return 0;
}