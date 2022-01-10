/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    string num;
    int n;
    vector<vector<int>> list;
public:
    bool isAdditiveNumber(string num) {
        this->num = num;
        this->n = (int)num.size();
        return dfs(0);
    }
    
    bool dfs(int idx) {
        // 现在已经确定的数字数量
        int m = (int)list.size();
        if (idx == n) return m >= 3;
        // 判断 '0' 的情况
        int max = num[idx] == '0' ? idx + 1 : n;
        vector<int> cur;
        for (int i = idx; i < max; i++){
            cur.insert(cur.begin(), num[i] - '0');
            if (m < 2 || check(list[m - 2], list[m - 1], cur)){
                // 回溯
                list.push_back(cur);
                if (dfs(i + 1)) return true;
                list.pop_back();
            }
        }
        return false;
    }
    
    /// 判断 a + b == c，倒序存储
    bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<int> sum;
        int m = (int)a.size();
        int n = (int)b.size();
        int x = (int)c.size();
        if (x < m || x < n) {
            return false;
        }
        int carry = 0;
        for (int i = 0; i < m || i < n || carry != 0; ++i) {
            if (i < m) carry += a[i];
            if (i < n) carry += b[i];
            sum.push_back(carry % 10);
            carry /= 10;
        }
        if (x != sum.size()) {
            return false;
        }
        for (int i = 0; i < x; i++){
            if(c[i] != sum[i]) return false;
        }
        return true;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string num;
    bool res;
    
    /**
     输入："112358"
     输出：true
     解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
     */
    num = "112358";
    res = true;
    assert(res == Solution().isAdditiveNumber(num));
    
    /**
     输入："199100199"
     输出：true
     解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
     */
    num = "199100199";
    res = true;
    assert(res == Solution().isAdditiveNumber(num));

    cout << "OK~" << endl;

    return 0;
}
