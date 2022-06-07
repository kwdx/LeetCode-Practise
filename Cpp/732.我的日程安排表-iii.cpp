/*
 * @lc app=leetcode.cn id=732 lang=cpp
 *
 * [732] 我的日程安排表 III
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// @lc code=start
class MyCalendarThree {
private:
    unordered_map<int, pair<int, int>> tree;
public:
    MyCalendarThree() {

    }
   
    void update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        }
        if (start <= l && r <= end) {
            tree[idx].first++;
            tree[idx].second++;
        } else {
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx);
            update(start, end, mid + 1, r, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }
    
    int book(int start, int end) {
        update(start, end - 1, 0, 1e9, 1);
        return tree[1].first;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
     [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
     输出：
     [null, 1, 1, 2, 3, 3, 3]

     解释：
     MyCalendarThree myCalendarThree = new MyCalendarThree();
     myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
     myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
     myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
     myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
     myCalendarThree.book(5, 10); // 返回 3
     myCalendarThree.book(25, 55); // 返回 3
     */
    MyCalendarThree myCalendarThree;
    assert(1 == myCalendarThree.book(10, 20));  // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
    assert(1 == myCalendarThree.book(50, 60));  // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
    assert(2 == myCalendarThree.book(10, 40));  // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
    assert(3 == myCalendarThree.book(5, 15));   // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
    assert(3 == myCalendarThree.book(5, 10));   // 返回 3
    assert(3 == myCalendarThree.book(25, 55));  // 返回 3;

    cout << "OK~" << endl;
    
    return 0;
}
