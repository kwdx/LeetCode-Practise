//
//  UnionFind.hpp
//  Cpp
//
//  Created by warden on 2021/8/19.
//

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <iostream>
#include <vector>

class UnionFind {
private:
    // 图的容量
    int capacity;
    // 存储若干棵树
    std::vector<int> parents;
    // 记录树的重量
    std::vector<int> size;
public:
    /* 构建连通图 */
    UnionFind(int n);
    
    /* 将 p 和 q 连通 */
    void unionn(int p, int q);
    
    /* 判断 p 和 q 是否互相连通 */
    bool connected(int p, int q);
    
    /* 返回节点 x 的根节点 */
    int find(int x);
    
    /* 返回连通分量 */
    int count();
};

#endif /* UnionFind_hpp */
