/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) swap(s[left++], s[right--]);
    }
    void reverseString1(vector<char>& s) {
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<char> s, res;
    
    /**
     输入：["h","e","l","l","o"]
     输出：["o","l","l","e","h"]
     */
    s = {'h','e','l','l','o'};
    res = {'o','l','l','e','h'};
    Solution().reverseString(s);
    cout << (res == s) << endl;
    
    /**
     输入：["H","a","n","n","a","h"]
     输出：["h","a","n","n","a","H"]
     */
    s = {'H','a','n','n','a','h'};
    res = {'h','a','n','n','a','H'};
    Solution().reverseString(s);
    cout << (res == s) << endl;
    
    return 0;
}
