/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> index;
        
        for (int i = 0; i < pieces.size(); ++i) {
            index[pieces[i][0]] = i;
        }
        for (int i = 0; i< arr.size(); ) {
            auto it = index.find(arr[i]);
            if (it == index.end()) {
                return false;
            }
            for (int x : pieces[it->second]) {
                if (arr[i++] != x) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> arr;
    vector<vector<int>> pieces;
    bool res;
    
    /**
     输入：arr = [15,88], pieces = [[88],[15]]
     输出：true
     解释：依次连接 [15] 和 [88]
     */
    arr = {15,88};
    pieces = {{88},{15}};
    res = true;
    assert(res == Solution().canFormArray(arr, pieces));
    
    /**
     输入：arr = [49,18,16], pieces = [[16,18,49]]
     输出：false
     解释：即便数字相符，也不能重新排列 pieces[0]
     */
    arr = {49,18,16};
    pieces = {{16,18,49}};
    res = false;
    assert(res == Solution().canFormArray(arr, pieces));
    
    /**
     输入：arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
     输出：true
     解释：依次连接 [91]、[4,64] 和 [78]
     */
    arr = {91,4,64,78};
    pieces = {{78},{4,64},{91}};
    res = true;
    assert(res == Solution().canFormArray(arr, pieces));

    cout << "OK~" << endl;
    
    return 0;
}
