//
//  UnionFind.cpp
//  Cpp
//
//  Created by warden on 2021/8/19.
//

#include "UnionFind.h"

UnionFind::UnionFind(int n) {
    capacity = n;
    
    parents.resize(n);
    size.resize(n);
    
    for (int i = 0; i < n; i++) {
        parents[i] = i;
        size[i] = 1;
    }
}

void UnionFind::unionn(int p, int q) {
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

bool UnionFind::connected(int p, int q) {
    return find(p) == find(q);
}

int UnionFind::find(int x) {
    while (parents[x] != x) {
        parents[x] = parents[parents[x]];
        x = parents[x];
    }
    return x;
}

int UnionFind::count() {
    return capacity;
}
