/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = (int)secret.size();
        int A = 0, B = 0;
        
        vector<int> S(10), G(10);
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++A;
            } else {
                ++S[secret[i] - '0'];
                ++G[guess[i] - '0'];
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            B += min(S[i], G[i]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string secret, guess;
    string res;
    
    /**
     输入: secret = "1807", guess = "7810"
     输出: "1A3B"
     解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
     "1807"
       |
     "7810"
     */
    secret = "1807";
    guess = "7810";
    res = "1A3B";
    assert(res == Solution().getHint(secret, guess));
    
    /**
     输入: secret = "1123", guess = "0111"
     输出: "1A1B"
     解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
     "1123"        "1123"
       |      or     |
     "0111"        "0111"
     注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。
     */
    secret = "1123";
    guess = "0111";
    res = "1A1B";
    assert(res == Solution().getHint(secret, guess));
    
    /**
     输入：secret = "1", guess = "0"
     输出："0A0B"
     */
    secret = "1";
    guess = "0";
    res = "0A0B";
    assert(res == Solution().getHint(secret, guess));
    
    /**
     输入：secret = "1", guess = "1"
     输出："1A0B"
     */
    secret = "1";
    guess = "1";
    res = "1A0B";
    assert(res == Solution().getHint(secret, guess));
    
    /**
     输入：secret = "1122", guess = "1222"
     输出："3A0B"
     */
    secret = "1122";
    guess = "1222";
    res = "3A0B";
    assert(res == Solution().getHint(secret, guess));

    cout << "OK~" << endl;

    return 0;
}
