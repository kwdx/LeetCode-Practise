/*
 * @lc app=leetcode.cn id=352 lang=cpp
 *
 * [352] 将数据流变为多个不相交区间
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// @lc code=start
class SummaryRanges {
private:
    map<int, int> interval;
public:
    SummaryRanges() {

    }
    
    void addNum(int val) {
        auto up = interval.upper_bound(val);
        auto down = (up == interval.begin() ? interval.end() : prev(up));

        if (down != interval.end() && (val >= down->first && val <= down->second)) {

        } else if ((up != interval.end() && up->first - 1 == val) && (down != interval.end() && down->second + 1 == val)) {
            int l = down->first, r = up->second;
            interval.erase(down->first);
            interval.erase(up->first);
            interval.emplace(l, r);
        } else if (down != interval.end() && down->second + 1 == val) {
            int l = down->first, r = val;
            interval.erase(l);
            interval.emplace(l, r);
        } else if (up != interval.end() && up->first - 1 == val) {
            int l = val, r = up->second;
            interval.erase(up->first);
            interval.emplace(l, r);
        } else {
            interval.emplace(val, val);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto& it : interval) {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> ans;
    /**
     输入：
     ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
     [[], [1], [], [3], [], [7], [], [2], [], [6], []]
     输出：
     [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

     解释：
     SummaryRanges summaryRanges = new SummaryRanges();
     summaryRanges.addNum(1);      // arr = [1]
     summaryRanges.getIntervals(); // 返回 [[1, 1]]
     summaryRanges.addNum(3);      // arr = [1, 3]
     summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3]]
     summaryRanges.addNum(7);      // arr = [1, 3, 7]
     summaryRanges.getIntervals(); // 返回 [[1, 1], [3, 3], [7, 7]]
     summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
     summaryRanges.getIntervals(); // 返回 [[1, 3], [7, 7]]
     summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
     summaryRanges.getIntervals(); // 返回 [[1, 3], [6, 7]]
     */
    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);
    ans = {{1,1}};
    assert(ans == summaryRanges.getIntervals());
    summaryRanges.addNum(3);
    ans = {{1,1},{3,3}};
    assert(ans == summaryRanges.getIntervals());
    summaryRanges.addNum(7);
    ans = {{1,1},{3,3},{7,7}};
    assert(ans == summaryRanges.getIntervals());
    summaryRanges.addNum(2);
    ans = {{1,3},{7,7}};
    assert(ans == summaryRanges.getIntervals());
    summaryRanges.addNum(6);
    ans = {{1,3},{6,7}};
    assert(ans == summaryRanges.getIntervals());

    cout << "OK~" << endl;

    return 0;
}
