#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
 public:
  std::unordered_map<int, int> map;
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
      int find = target - nums.at(i);
      auto iter = map.find(find);
      if (iter == map.end()) {
        map[nums.at(i)] = i;
      } else {
        return {i, iter->second};
      }
    }
  }
};

int main(int argc, char* argv[]) {
  Solution sol;
  std::vector<int> data{1,2,3,4,5,6,7,8};
  std::vector<int> ret = sol.twoSum(data, 10);
  std::cout << ret.front() << " " << ret.back() << std::endl;
  return 0;
}