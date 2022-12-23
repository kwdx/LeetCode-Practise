/*
 * @lc app=leetcode.cn id=2011 lang=cpp
 *
 * [2011] 执行操作后的变量值
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string& operation : operations) {
            if (operation[1] == '-') {
                ans -= 1;
            } else {
                ans += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> operations;
    int res;
    
    /**
     输入：operations = ["--X","X++","X++"]
     输出：1
     解释：操作按下述步骤执行：
     最初，X = 0
     --X：X 减 1 ，X =  0 - 1 = -1
     X++：X 加 1 ，X = -1 + 1 =  0
     X++：X 加 1 ，X =  0 + 1 =  1
     */
    operations = {"--X","X++","X++"};
    res = 1;
    assert(res == Solution().finalValueAfterOperations(operations));
    
    /**
     输入：operations = ["++X","++X","X++"]
     输出：3
     解释：操作按下述步骤执行：
     最初，X = 0
     ++X：X 加 1 ，X = 0 + 1 = 1
     ++X：X 加 1 ，X = 1 + 1 = 2
     X++：X 加 1 ，X = 2 + 1 = 3
     */
    operations = {"++X","++X","X++"};
    res = 3;
    assert(res == Solution().finalValueAfterOperations(operations));
    
    /**
     输入：operations = ["X++","++X","--X","X--"]
     输出：0
     解释：操作按下述步骤执行：
     最初，X = 0
     X++：X 加 1 ，X = 0 + 1 = 1
     ++X：X 加 1 ，X = 1 + 1 = 2
     --X：X 减 1 ，X = 2 - 1 = 1
     X--：X 减 1 ，X = 1 - 1 = 0
     */
    operations = {"X++","++X","--X","X--"};
    res = 0;
    assert(res == Solution().finalValueAfterOperations(operations));

    cout << "OK~" << endl;
    
    return 0;
}
