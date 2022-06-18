//
//  114.外星文字典.cpp
//  cpp
//
//  Created by kingsoft on 2022/5/31.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 邻接矩阵
        unordered_map<char, unordered_set<char>> g;
        // 存每个字母的入度
        unordered_map<char, int> d;
        // 初始化每个字母的入度
        for (auto w: words)
            for (auto c: w)
                d[c] = 0;
        
        for (int i = 1; i < words.size(); ++i) {
            auto w1 = words[i - 1], w2 = words[i];
            int len = (int)min(w1.size(), w2.size());
            int j = 0;
            for (; j < len; ++j) {
                if (w1[j] == w2[j])
                    continue;
                if (!g.count(w1[j]) || !g[w1[j]].count(w2[j])) {
                    g[w1[j]].insert(w2[j]);
                    ++d[w2[j]];
                }
                // 找到第一个不同的字母（或没建边的点）后，直接退出
                break;    // 关键步
            }
            // 根据定义，此时w2的字典序小于w1的字典序，矛盾，说明无解
            if (j == len && w1.size() > w2.size())
                return "";
        }
        queue<char> q;
        for (auto [x, y] : d) {
            if (!y)
                q.push(x);
        }
        string res = "";
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res += t;
            for (auto c: g[t]) {
                if (--d[c] == 0)
                    q.push(c);
            }
        }
        return res.size() == g.size() ? res : "";
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<string> words;
    string res;
    
    /**
     输入：words = ["wrt","wrf","er","ett","rftt"]
     输出："wertf"
     */
    words = {"wrt","wrf","er","ett","rftt"};
    res = "wertf";
    assert(res == Solution().alienOrder(words));
    
    /**
     输入：words = ["z","x"]
     输出："zx"
     */
    words = {"z","x"};
    res = "zx";
    assert(res == Solution().alienOrder(words));
    
    /**
     输入：words = ["z","x","z"]
     输出：""
     解释：不存在合法字母顺序，因此返回 "" 。
     */
    words = {"z","x","z"};
    res = "";
    assert(res == Solution().alienOrder(words));

    cout << "OK~" << endl;
    
    return 0;
}
