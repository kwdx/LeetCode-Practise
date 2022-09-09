/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (int i = 0;i<logs.size();i++) {
            if (logs[i] == "./") {
                
            } else if (logs[i] == "../") {
                if (level > 0) {
                    level -= 1;
                }
            } else {
                level += 1;
            }
        }
        return level;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> logs;
    int res;
    
    /**
     输入：logs = ["d1/","d2/","../","d21/","./"]
     输出：2
     解释：执行 "../" 操作变更文件夹 2 次，即可回到主文件夹
     */
    logs = {"d1/","d2/","../","d21/","./"};
    res = 2;
    assert(res == Solution().minOperations(logs));
    
    /**
     输入：logs = ["d1/","d2/","./","d3/","../","d31/"]
     输出：3
     */
    logs = {"d1/","d2/","./","d3/","../","d31/"};
    res = 3;
    assert(res == Solution().minOperations(logs));
    
    /**
     输入：logs = ["d1/","../","../","../"]
     输出：0
     */
    logs = {"d1/","../","../","../"};
    res = 0;
    assert(res == Solution().minOperations(logs));

    cout << "OK~" << endl;
    
    return 0;
}
