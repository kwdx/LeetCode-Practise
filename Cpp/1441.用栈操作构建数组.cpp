/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] 用栈操作构建数组
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int prev = 0;
        for (int number : target) {
            for (int i = 0; i < number - prev - 1; ++i) {
                ans.emplace_back("Push");
                ans.emplace_back("Pop");
            }
            ans.emplace_back("Push");
            prev = number;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> target;
    int n;
    vector<string> res;
    
    /**
     输入：target = [1,3], n = 3
     输出：["Push","Push","Pop","Push"]
     解释：
     读取 1 并自动推入数组 -> [1]
     读取 2 并自动推入数组，然后删除它 -> [1]
     读取 3 并自动推入数组 -> [1,3]
     */
    target = {1,3};
    n = 3;
    res = {"Push","Push","Pop","Push"};
    assert(res == Solution().buildArray(target, n));
    
    /**
     输入：target = [1,2,3], n = 3
     输出：["Push","Push","Push"]
     */
    target = {1,2,3};
    n = 3;
    res = {"Push","Push","Push"};
    assert(res == Solution().buildArray(target, n));
    
    /**
     输入：target = [1,2], n = 4
     输出：["Push","Push"]
     解释：只需要读取前 2 个数字就可以停止。
     */
    target = {1,2};
    n = 4;
    res = {"Push","Push"};
    assert(res == Solution().buildArray(target, n));

    cout << "OK~" << endl;
    
    return 0;
}

