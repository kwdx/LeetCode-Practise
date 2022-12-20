/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class UnionFind {
private:
    // 图的容量
    int capacity;
    // 存储若干棵树
    std::vector<int> parents;
    // 记录树的重量
    std::vector<int> size;
public:
    UnionFind(int n) {
        capacity = n;
        
        parents.resize(n);
        size.resize(n);
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    void unionn(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ) return;
        
        if (size[rootP] > size[rootQ]) {
            parents[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parents[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        capacity--;
    }

    bool isConnected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int x) {
        while (parents[x] != x) {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }
        return x;
    }

    int count() {
        return capacity;
    }
 };

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) {
            return true;
        }
        UnionFind uf(n);
        for (auto edge : edges) {
            uf.unionn(edge[0], edge[1]);
        }
        return uf.isConnected(source, destination);
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n;
    vector<vector<int>> edges;
    int source;
    int destination;
    bool res;
    
    /**
     输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
     输出：true
     解释：存在由顶点 0 到顶点 2 的路径:
     - 0 → 1 → 2
     - 0 → 2
     */
    n = 3;
    edges = {{0,1},{1,2},{2,0}};
    source = 0;
    destination = 2;
    res = true;
    assert(res == Solution().validPath(n, edges, source, destination));
    
    /**
     输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
     输出：false
     解释：不存在由顶点 0 到顶点 5 的路径.
     */
    n = 6;
    edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    source = 0;
    destination = 5;
    res = false;
    assert(res == Solution().validPath(n, edges, source, destination));

    cout << "OK~" << endl;
    
    return 0;
}
