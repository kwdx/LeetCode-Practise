/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
private:
    vector<NestedInteger> list;
    int value;
public:
    NestedInteger(int value) {
        this->value = value;
        this->list = {};
    }
    NestedInteger(vector<NestedInteger> list) {
        
        this->value = 0;
        this->list = list;
    }
    
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return this->list.empty(); }
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return this->value; }
    
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const { return this->list; }
};

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> st; // 记录当前遍历的序列
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.emplace(nestedList.begin(), nestedList.end());
    }
    
    int next() {
        return st.top().first++->getInteger();
    }
    
    bool hasNext() {
        while (!st.empty()) {
            auto &top = st.top();
            if (top.first == top.second) {
                st.pop();
                continue;
            }
            if (top.first->isInteger()) return true;
            
            auto &list = top.first++->getList();
            st.emplace(list.begin(), list.end());
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    vector<NestedInteger> nestedList = {
        NestedInteger({1, 1}),
        NestedInteger(2),
        NestedInteger({1, 1})
    };
    NestedIterator* iterator = new NestedIterator(nestedList);
    
    while (iterator->hasNext()) {
        cout << iterator->next() << " ";
    }
    cout << endl;
    
    return 0;
}
