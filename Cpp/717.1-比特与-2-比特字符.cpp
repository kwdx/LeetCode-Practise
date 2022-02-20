/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = (int)bits.size(), idx = 0;
        while (idx < n - 1) {
            if (bits[idx] == 0) idx += 1;
            else idx += 2;
        }
        return idx == n - 1;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> bits;
    bool res;
    
    /**
     输入: bits = [1, 0, 0]
     输出: true
     解释: 唯一的编码方式是一个两比特字符和一个一比特字符。
     所以最后一个字符是一比特字符。
     */
    bits = {1, 0, 0};
    res = true;
    assert(res == Solution().isOneBitCharacter(bits));
    
    /**
     输入: bits = [1, 1, 1, 0]
     输出: false
     解释: 唯一的编码方式是两比特字符和两比特字符。
     所以最后一个字符不是一比特字符。
     */
    bits = {1, 1, 1, 0};
    res = true;
    assert(res == Solution().isOneBitCharacter(bits));

    cout << "OK~" << endl;
    
    return 0;
}

