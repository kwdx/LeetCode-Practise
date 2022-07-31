/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class UnionFind {
public:
    UnionFind(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    void uni(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
private:
    
public:
    int largestComponentSize(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        UnionFind uf(m + 1);
        for (int num : nums) {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    uf.uni(num, i);
                    uf.uni(num, num / i);
                }
            }
        }
        vector<int> counts(m + 1);
        int ans = 0;
        for (int num : nums) {
            int root = uf.find(num);
            counts[root]++;
            ans = max(ans, counts[root]);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> nums;
    int res;
    
    /**
     输入：nums = [4,6,15,35]
     输出：4
     */
    nums = {4,6,15,35};
    res = 4;
    assert(res == Solution().largestComponentSize(nums));
    
    /**
     输入：nums = [20,50,9,63]
     输出：2
     */
    nums = {20,50,9,63};
    res = 2;
    assert(res == Solution().largestComponentSize(nums));
    
    /**
     输入：nums = [2,3,6,7,4,12,21,39]
     输出：8
     */
    nums = {2,3,6,7,4,12,21,39};
    res = 8;
    assert(res == Solution().largestComponentSize(nums));
    
    cout << "OK~" << endl;
    
    return 0;
}
