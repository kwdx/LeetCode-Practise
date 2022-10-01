/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string reformatNumber(string number) {
        string num;
        for (char c : number) {
            if (isdigit(c)) {
                num.push_back(c);
            }
        }
        int n = (int)num.size();
        int idx = 0;
        string ans;
        while (n > 0) {
            if (n > 4) {
                ans += num.substr(idx, 3) + "-";
                idx += 3;
                n -= 3;
            } else {
                if (n == 4) {
                    ans += num.substr(idx, 2) + "-" + num.substr(idx + 2, 2);
                } else {
                    ans += num.substr(idx, n);
                }
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string number;
    string res;
    
    /**
     输入：number = "1-23-45 6"
     输出："123-456"
     解释：数字是 "123456"
     步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
     步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
     连接这些块后得到 "123-456" 。
     */
    number = "1-23-45 6";
    res = "123-456";
    assert(res == Solution().reformatNumber(number));
    
    /**
     输入：number = "123 4-567"
     输出："123-45-67"
     解释：数字是 "1234567".
     步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
     步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
     连接这些块后得到 "123-45-67" 。
     */
    number = "123 4-567";
    res = "123-45-67";
    assert(res == Solution().reformatNumber(number));
    
    /**
     输入：number = "123 4-5678"
     输出："123-456-78"
     解释：数字是 "12345678" 。
     步骤 1：第 1 个块 "123" 。
     步骤 2：第 2 个块 "456" 。
     步骤 3：剩下 2 个数字，将它们放入单个含 2 个数字的块。第 3 个块是 "78" 。
     连接这些块后得到 "123-456-78" 。
     */
    number = "123 4-5678";
    res = "123-456-78";
    assert(res == Solution().reformatNumber(number));
    
    /**
     输入：number = "12"
     输出："12"
     */
    number = "12";
    res = "12";
    assert(res == Solution().reformatNumber(number));
    
    /**
     输入：number = "--17-5 229 35-39475 "
     输出："175-229-353-94-75"
     */
    number =  "--17-5 229 35-39475 ";
    res = "175-229-353-94-75";
    assert(res == Solution().reformatNumber(number));

    cout << "OK~" << endl;
    
    return 0;
}
