/*
 * @lc app=leetcode.cn id=2034 lang=cpp
 *
 * [2034] 股票价格波动
 */

#include <iostream>
#include <map>
#include <set>

using namespace std;

// @lc code=start
class StockPrice {
private:
    int cur;
    map<int, int> timeToPrices;
    multiset<int> st;

public:
    StockPrice() {
        cur = 0;
    }
    
    void update(int timestamp, int price) {
        cur = max(cur, timestamp);
        if (timeToPrices.count(timestamp)) {
            int old = timeToPrices[timestamp];
            auto pos = st.find(old);
            st.erase(pos);
        }
        st.insert(price);
        timeToPrices[timestamp] = price;
    }
    
    int current() {
        return timeToPrices[cur];
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
     [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
     输出：
     [null, null, null, 5, 10, null, 5, null, 2]

     解释：
     StockPrice stockPrice = new StockPrice();
     stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
     stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
     stockPrice.current();     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
     stockPrice.maximum();     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
     stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。
                               // 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
     stockPrice.maximum();     // 返回 5 ，更正后最高价格为 5 。
     stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
     stockPrice.minimum();     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
     */
    StockPrice stockPrice;
    stockPrice.update(1, 10);
    stockPrice.update(2, 5);
    assert(5 == stockPrice.current());
    assert(10 == stockPrice.maximum());
    stockPrice.update(1, 3);
    assert(5 == stockPrice.maximum());
    stockPrice.update(4, 2);
    assert(2 == stockPrice.minimum());
    
    cout << "OK~" << endl;

    return 0;
}
