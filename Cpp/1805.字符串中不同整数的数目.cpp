/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> nums;
        int n = (int)word.size();
        for (int i = 0; i < n; ++i) {
            if (isdigit(word[i])) {
                while (i < n && word[i] == '0') {
                    i += 1;
                }
                int j = i;
                while (j < n && isdigit(word[j])) {
                    j += 1;
                }
                nums.insert(word.substr(i, j - i));
                i = j;
            }
        }
        return (int)nums.size();
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string word;
    int res;
    
    /**
     输入：word = "a123bc34d8ef34"
     输出：3
     解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
     */
    word = "a123bc34d8ef34";
    res = 3;
    assert(res == Solution().numDifferentIntegers(word));
    
    /**
     输入：word = "leet1234code234"
     输出：2
     */
    word = "leet1234code234";
    res = 2;
    assert(res == Solution().numDifferentIntegers(word));
    
    /**
     输入：word = "a1b01c001"
     输出：1
     解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
     */
    word = "a1b01c001";
    res = 1;
    assert(res == Solution().numDifferentIntegers(word));
    
    cout << "OK~" << endl;
    
    return 0;
}
