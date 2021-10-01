/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mo;
        for (vector<string> & path : paths) {
            mo[path[0]] += 1;
            mo[path[1]] += 0;
        }
        for (auto & p : mo) {
            if (p.second == 0) return p.first;
        }
        return "";
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<vector<string>> paths;
    string res;
    
    /**
     输入：paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
     输出："Sao Paulo"
     解释：从 "London" 出发，最后抵达终点站 "Sao Paulo" 。本次旅行的路线是 "London" -> "New York" -> "Lima" -> "Sao Paulo" 。
     */
    paths = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    res = "Sao Paulo";
    assert(res == Solution().destCity(paths));
    
    /**
     输入：paths = [["B","C"],["D","B"],["C","A"]]
     输出："A"
     解释：所有可能的线路是：
     "D" -> "B" -> "C" -> "A".
     "B" -> "C" -> "A".
     "C" -> "A".
     "A".
     显然，旅行终点站是 "A" 。
     */
    paths = {{"B","C"},{"D","B"},{"C","A"}};
    res = "A";
    assert(res == Solution().destCity(paths));
    
    /**
     输入：paths = [["A","Z"]]
     输出："Z"
     */
    paths = {{"B","C"},{"D","B"},{"C","A"}};
    res = "A";
    assert(res == Solution().destCity(paths));
    
    cout << "OK~" << endl;
    
    return 0;
}
