/*
 * @lc app=leetcode.cn id=1705 lang=cpp
 *
 * [1705] 吃苹果的最大数目
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
typedef pair<int, int> P;
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<P,vector<P>,greater<P>> q;
        int n = (int)apples.size();
        int time = 0, ans = 0;
        while (time < n || !q.empty()) {
            if (time < n && apples[time] > 0)
                // 添加新的苹果
                q.push({time + days[time] - 1, apples[time]});
            while (!q.empty() && q.top().first < time)
                // 清除已过期的苹果
                q.pop();
            if (!q.empty()) {
                P apple = q.top();
                q.pop();
                if (--apple.second > 0 && apple.first > time)
                    // 还有苹果没过期
                    q.push(apple);
                ++ans;
            }
            ++time;
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> apples;
    vector<int> days;
    int res;
    
    /**
     输入：apples = [1,2,3,5,2], days = [3,2,1,4,2]
     输出：7
     解释：你可以吃掉 7 个苹果：
     - 第一天，你吃掉第一天长出来的苹果。
     - 第二天，你吃掉一个第二天长出来的苹果。
     - 第三天，你吃掉一个第二天长出来的苹果。过了这一天，第三天长出来的苹果就已经腐烂了。
     - 第四天到第七天，你吃的都是第四天长出来的苹果。
     */
    apples = {1,2,3,5,2};
    days = {3,2,1,4,2};
    res = 7;
    assert(res == Solution().eatenApples(apples, days));
    
    /**
     输入：apples = [3,0,0,0,0,2], days = [3,0,0,0,0,2]
     输出：5
     解释：你可以吃掉 5 个苹果：
     - 第一天到第三天，你吃的都是第一天长出来的苹果。
     - 第四天和第五天不吃苹果。
     - 第六天和第七天，你吃的都是第六天长出来的苹果。
     */
    apples = {3,0,0,0,0,2};
    days = {3,0,0,0,0,2};
    res = 5;
    assert(res == Solution().eatenApples(apples, days));

    cout << "OK~" << endl;

    return 0;
}
