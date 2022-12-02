/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = boxes[0] - '0', right = 0, operations = 0;
        int n = (int)boxes.size();
        for (int i = 1; i < n; ++i) {
            if (boxes[i] == '1') {
                right += 1;
                operations += i;
            }
        }
        vector<int> ans(n);
        ans[0] = operations;
        for (int i = 1; i < n; ++i) {
            operations += left - right;
            if (boxes[i] == '1') {
                ++left;
                --right;
            }
            ans[i] = operations;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string boxes;
    vector<int> res;
    
    /**
     输入：boxes = "110"
     输出：[1,1,3]
     解释：每个盒子对应的最小操作数如下：
     1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
     2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
     3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1 步操作。共计 3 步操作。
     */
    boxes = "110";
    res = {1,1,3};
    assert(res == Solution().minOperations(boxes));
    
    /**
     输入：boxes = "001011"
     输出：[11,8,5,4,3,4]
     */
    boxes = "001011";
    res = {11,8,5,4,3,4};
    assert(res == Solution().minOperations(boxes));
    
    cout << "OK~" << endl;
    
    return 0;
}
