/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

#include <iostream>
#include <vector>
//#include "UnionFind.h"

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

    bool connected(int p, int q) {
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
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        
        for (string equation : equations)
            if (equation[1] == '=')
                uf.unionn(equation[0] - 'a', equation[3] - 'a');
        
        for (string equation : equations)
            if (equation[1] == '!' && uf.connected(equation[0] - 'a', equation[3] - 'a'))
                return false;
        
        return true;
    }
};
// @lc code=end


int main(int argc, const char * argv[]) {
    vector<string> equations;
    
    equations = {"a==b","b!=a"};
    // false
    cout << Solution().equationsPossible(equations) << endl;
    
    equations = {"b==a","a==b"};
    // true
    cout << Solution().equationsPossible(equations) << endl;
    
    equations = {"a==b","b==c","a==c"};
    // true
    cout << Solution().equationsPossible(equations) << endl;
    
    equations = {"a==b","b!=c","c==a"};
    // false
    cout << Solution().equationsPossible(equations) << endl;
    
    equations = {"c==c","b==d","x!=z"};
    // true
    cout << Solution().equationsPossible(equations) << endl;
    
    return 0;
}
