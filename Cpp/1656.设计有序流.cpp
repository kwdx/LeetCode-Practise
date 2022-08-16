/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class OrderedStream {
private:
    vector<string> elements;
    int ptr = 1;
public:
    OrderedStream(int n) {
        elements.resize(n + 1);
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        elements[idKey] = value;
        while (ptr < elements.size() && !elements[ptr].empty()) {
            ans.emplace_back(elements[ptr++]);
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入
     ["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
     [[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
     输出
     [null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

     解释
     OrderedStream os= new OrderedStream(5);
     os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
     os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
     os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
     os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
     os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
     */
    OrderedStream os(5);
    vector<string> res;
    res = {};
    assert(res == os.insert(3, "ccccc"));
    res = {"aaaaa"};
    assert(res == os.insert(1, "aaaaa"));
    res = {"bbbbb", "ccccc"};
    assert(res == os.insert(2, "bbbbb"));
    res = {};
    assert(res == os.insert(5, "eeeee"));
    res = {"ddddd", "eeeee"};
    assert(res == os.insert(4, "ddddd"));

    cout << "OK~" << endl;
    
    return 0;
}
