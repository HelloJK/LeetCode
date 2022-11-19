#include <iostream>
#include <math.h>
#include <vector>

class Solution {
public:
    double myPow(double x, int n) {
      if (n == 0) return 1;
      int ori_n = n;
      n = std::abs(n);

      if (n == 1) return ori_n > 0 ? x : 1 / x ;
      
      std::vector<std::pair<int, double>> vec_;
      vec_.push_back({1, x});
      long long count = 2; // count = count * 2;
      double tmp = x; // tmp = tmp * tmp
      while (count <= n) {
        tmp *= tmp;
        vec_.push_back({count, tmp});

        count *= 2;
      }

      count /= 2;
      if (count == n) {
        return ori_n > 0 ? tmp : 1 / tmp;
      }

      for (auto iter = vec_.rbegin(); iter != vec_.rend(); ++iter) {
        if ((count + iter->first) < n) {
          tmp *= iter->second;
          count += iter->first;
        } else if ((count + iter->first) == n) {
          tmp *= iter->second;
          return ori_n > 0 ? tmp : 1 / tmp;
        }
      }
      return -1;
    }
};

int main(int argc, char* argv[]) {
    Solution Sol;
    double x = 0.00001;
    int d = 2147483647;
    std::cout << d << std::endl;
    std::cout << Sol.myPow(x, d) << " : " << std::pow(x, d) << std::endl;
    return 0;
}
