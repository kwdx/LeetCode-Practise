/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

#include <iostream>
#include <stack>

using namespace std;

// @lc code=start
class StockSpanner {
private:
    stack<pair<int, int>> st;
    int idx;
public:
    StockSpanner() {
        st.emplace(-1, INT_MAX);
        idx = -1;
    }
    
    int next(int price) {
        ++idx;
        while (st.top().second <= price) {
            st.pop();
        }
        int ans = idx - st.top().first;
        st.emplace(idx, price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
     输出：[null,1,1,1,2,1,4,6]
     解释：
     首先，初始化 S = StockSpanner()，然后：
     S.next(100) 被调用并返回 1，
     S.next(80) 被调用并返回 1，
     S.next(60) 被调用并返回 1，
     S.next(70) 被调用并返回 2，
     S.next(60) 被调用并返回 1，
     S.next(75) 被调用并返回 4，
     S.next(85) 被调用并返回 6。

     注意 (例如) S.next(75) 返回 4，因为截至今天的最后 4 个价格
     (包括今天的价格 75) 小于或等于今天的价格。
     */
    StockSpanner S;
    assert(1 == S.next(100));
    assert(1 == S.next(80));
    assert(1 == S.next(60));
    assert(2 == S.next(70));
    assert(1 == S.next(60));
    assert(4 == S.next(75));
    assert(6 == S.next(85));
    
    cout << "OK~" << endl;
    
    return 0;
}
