/*
 * @lc app=leetcode.cn id=1678 lang=cpp
 *
 * [1678] 设计 Goal 解析器
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string interpret(string command) {
        string ans;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                ans += "G";
            } else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ans += "o";
                } else {
                    ans += "al";
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string command;
    string res;
    
    /**
     输入：command = "G()(al)"
     输出："Goal"
     解释：Goal 解析器解释命令的步骤如下所示：
     G -> G
     () -> o
     (al) -> al
     最后连接得到的结果是 "Goal"
     */
    command = "G()(al)";
    res = "Goal";
    assert(res == Solution().interpret(command));
    
    /**
     输入：command = "G()()()()(al)"
     输出："Gooooal"
     */
    command = "G()()()()(al)";
    res = "Gooooal";
    assert(res == Solution().interpret(command));
    
    /**
     输入：command = "(al)G(al)()()G"
     输出："alGalooG"
     */
    command = "(al)G(al)()()G";
    res = "alGalooG";
    assert(res == Solution().interpret(command));
    
    cout << "OK~" << endl;
    
    return 0;
}
