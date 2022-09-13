/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string chars = to_string(num);
        int n = (int)chars.size();
        int maxIdx = n - 1;
        int idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (chars[i] > chars[maxIdx]) {
                maxIdx = i;
            } else if (chars[i] < chars[maxIdx]) {
                idx1 = i;
                idx2 = maxIdx;
            }
        }
        if (idx1 >= 0) {
            swap(chars[idx1], chars[idx2]);
            return  stoi(chars);
        }
        return num;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int num;
    int res;
    
    /**
     输入: 2736
     输出: 7236
     解释: 交换数字2和数字7。
     */
    num = 2736;
    res = 7236;
    assert(res == Solution().maximumSwap(num));
    
    /**
     输入: 9973
     输出: 9973
     解释: 不需要交换。
     */
    num = 9973;
    res = 9973;
    assert(res == Solution().maximumSwap(num));

    cout << "OK~" << endl;
    
    return 0;
}
