/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
private:
    int sz;
    unordered_map<int, int> mapping;
public:
    Solution(int n, vector<int>& blacklist) {
        sz = n - (int)blacklist.size();
        for (int b : blacklist) {
            mapping[b] = -1;
        }
        int last = n - 1;
        for (int b : blacklist) {
            if (b >= sz) continue;
            while (mapping.count(last)) {
                last--;
            }
            mapping[b] = last;
            last--;
        }

    }
    
    int pick() {
        int index = rand() % sz;
        if (mapping.count(index)) {
            return mapping[index];
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

bool except(int pick, vector<int>& blacklist) {
    for (int num : blacklist) {
        if (num == pick) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<int> blacklist;
    int n, pick;
    Solution* obj;

    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[1,[]],[],[],[]]
     输出：[null,0,0,0]
     */
    n = 1;
    blacklist = {};
    obj = new Solution(n, blacklist);
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    cout << endl;
    delete obj;

    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[2,[]],[],[],[]]
     输出：[null,1,1,1]
     */
    n = 2;
    blacklist = {};
    obj = new Solution(n, blacklist);
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    cout << endl;
    delete obj;

    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[3,[1]],[],[],[]]
     输出：[null,0,0,2]
     */
    n = 3;
    blacklist = {1};
    obj = new Solution(n, blacklist);
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    cout << endl;
    delete obj;

    /**
     输入：
     ["Solution","pick","pick","pick"]
     [[4,[2]],[],[],[]]
     输出：[null,1,3,1]
     */
    n = 4;
    blacklist = {2};
    obj = new Solution(n, blacklist);
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    pick = obj->pick();
    cout << pick << " ";
    assert(except(pick, blacklist));
    cout << endl;
    delete obj;

    cout << "OK~" << endl;

    return 0;
}
