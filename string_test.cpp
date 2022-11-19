#include <string>
#include <unordered_map>
#include <map>
#include <iostream>
// 将order转成unordered_map<char, int>
// unorder_map<int, std::vector<char>> data

class Solution {
public:
    std::string customSortString(std::string order, std::string s) {
      std::unordered_map<char, int> order_map;
      for (size_t i = 0; i < order.size(); ++i) {
          auto iter = order_map.find(order.at(i));
          if (iter == order_map.end()) {
              order_map[order.at(i)] = i;
          }
      }

      std::map<int, std::string> data;
      std::string other_data;
      for (size_t i = 0; i < s.size(); ++i) {
          if (order_map.count(s.at(i)) > 0) {
              data[order_map[s.at(i)]] += s.at(i);
          } else {
              other_data += s.at(i);
          }
      }
      std::string output;
      for (auto iter = data.begin(); iter != data.end(); ++iter) {
        output += iter->second;
      }
      output += other_data;
      return output;
    }
};

int main(int argc, char* argv[]) {
  Solution sol;
  std::string order = "abcdefg";
  std::string str = "ghbdcaefdhk";
  std::cout << sol.customSortString(order, str) << std::endl;
  return 0;
}
