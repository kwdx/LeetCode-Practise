/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) return false;
        unordered_map<int, int> cnt;
        for (int num : target) {
            ++cnt[num];
        }
        for (int num : arr) {
            if (cnt.count(num)) {
                --cnt[num];
                if (cnt[num] == 0) {
                    cnt.erase(num);
                }
            } else {
                return false;
            }
        }
        return cnt.empty();
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> target;
    vector<int> arr;
    bool res;
    
    /**
     输入：target = [1,2,3,4], arr = [2,4,1,3]
     输出：true
     解释：你可以按照如下步骤使 arr 变成 target：
     1- 翻转子数组 [2,4,1] ，arr 变成 [1,4,2,3]
     2- 翻转子数组 [4,2] ，arr 变成 [1,2,4,3]
     3- 翻转子数组 [4,3] ，arr 变成 [1,2,3,4]
     上述方法并不是唯一的，还存在多种将 arr 变成 target 的方法。
     */
    target = {1,2,3,4};
    arr = {2,4,1,3};
    res = true;
    assert(res == Solution().canBeEqual(target, arr));
    
    /**
     输入：target = [7], arr = [7]
     输出：true
     解释：arr 不需要做任何翻转已经与 target 相等。
     */
    target = {7};
    arr = {7};
    res = true;
    assert(res == Solution().canBeEqual(target, arr));
    
    /**
     输入：target = [3,7,9], arr = [3,7,11]
     输出：false
     解释：arr 没有数字 9 ，所以无论如何也无法变成 target 。
     */
    target = {3,7,9};
    arr = {3,7,11};
    res = false;
    assert(res == Solution().canBeEqual(target, arr));

    cout << "OK~" << endl;
    
    return 0;
}
