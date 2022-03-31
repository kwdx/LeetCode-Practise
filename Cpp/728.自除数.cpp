/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; ++i) {
            if (isSelfDividingNumber(i)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
    
    bool isSelfDividingNumber(int num) {
        int n = num;
        while (num > 0) {
            int a = num % 10;
            if (a == 0 || n % a != 0) return false;
            num /= 10;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int left;
    int right;
    vector<int> res;
    
    /**
     输入：left = 1, right = 22
     输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
     */
    left = 1;
    right = 22;
    res = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    assert(res == Solution().selfDividingNumbers(left, right));
    
    /**
     输入：left = 47, right = 85
     输出：[48,55,66,77]
     */
    left = 47;
    right = 85;
    res = {48,55,66,77};
    assert(res == Solution().selfDividingNumbers(left, right));
    
    cout << "OK~" << endl;
    
    return 0;
}
