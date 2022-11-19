#include <vector>
#include <iostream>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
      int largest_altitude = 0;
      int altitude = 0;
      for (auto &_gain : gain) {
        altitude += _gain;
        largest_altitude = largest_altitude < altitude ? altitude : largest_altitude;
      } 
      return largest_altitude;
    }
};

int main(int argc, char* argv[]) {
  Solution sol;
  std::vector<int> gain{-4,-3,-2,-1,4,3,2};
  std::cout << sol.largestAltitude(gain) << std::endl;
}