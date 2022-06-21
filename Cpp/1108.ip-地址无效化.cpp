/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (char c : address) {
            if (c == '.') {
                ans.append("[.]");
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    string address;
    string res;
    
    /**
     输入：address = "1.1.1.1"
     输出："1[.]1[.]1[.]1"
     */
    address = "1.1.1.1";
    res = "1[.]1[.]1[.]1";
    assert(res == Solution().defangIPaddr(address));
    
    /**
     输入：address = "255.100.50.0"
     输出："255[.]100[.]50[.]0"
     */
    address = "255.100.50.0";
    res = "255[.]100[.]50[.]0";
    assert(res == Solution().defangIPaddr(address));
    
    cout << "OK~" << endl;
    
    return 0;
}
