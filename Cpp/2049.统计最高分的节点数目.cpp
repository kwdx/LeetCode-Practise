/*
 * @lc app=leetcode.cn id=2049 lang=cpp
 *
 * [2049] 统计最高分的节点数目
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int n;
    int cnt;
    long maxScore;
    vector<vector<int>> children;
    
    int dfs(int node) {
        long score = 1;
        int size = n - 1;
        for (int child : children[node]) {
            int val = dfs(child);
            score *= val;
            size -= val;
        }
        if (node != 0) { // 0为根节点，其余节点需要乘上父树
            score *= size;
        }
        if (score == maxScore) {
            cnt += 1;
        } else if (score > maxScore) {
            maxScore = score;
            cnt = 1;
        }
        return n - size;
    }
    
public:
    int countHighestScoreNodes(vector<int>& parents) {
        this->n = (int)parents.size();
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; ++i) {
            int parent = parents[i];
            if (parent != -1) {
                children[parent].emplace_back(i);
            }
        }
        dfs(0);
        return cnt;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> parents;
    int res;
    
    /**
     输入：parents = [-1,2,0,2,0]
     输出：3
     解释：
     - 节点 0 的分数为：3 * 1 = 3
     - 节点 1 的分数为：4 = 4
     - 节点 2 的分数为：1 * 1 * 2 = 2
     - 节点 3 的分数为：4 = 4
     - 节点 4 的分数为：4 = 4
     最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
     */
    parents = {-1,2,0,2,0};
    res = 3;
//    assert(res == Solution().countHighestScoreNodes(parents));
    
    /**
     输入：parents = [-1,2,0]
     输出：2
     解释：
     - 节点 0 的分数为：2 = 2
     - 节点 1 的分数为：2 = 2
     - 节点 2 的分数为：1 * 1 = 1
     最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
     */
    parents = {-1,2,0};
    res = 2;
    assert(res == Solution().countHighestScoreNodes(parents));

    cout << "OK~" << endl;

    return 0;
}
