/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int aster : asteroids) {
            bool alive = true;
            while (alive && aster < 0 && !st.empty() && st.top() > 0) {
                alive = st.top() < -aster;
                if (st.top() <= -aster) {
                    st.pop();
                }
            }
            if (alive) {
                st.push(aster);
            }
        }
        int n = (int)st.size();
        vector<int> ans(n);
        for (int i = n - 1 ; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> asteroids;
    vector<int> res;
    
    /**
     输入：asteroids = [5,10,-5]
     输出：[5,10]
     解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
     */
    asteroids = {5,10,-5};
    res = {5,10};
    assert(res == Solution().asteroidCollision(asteroids));
    
    /**
     输入：asteroids = [8,-8]
     输出：[]
     解释：8 和 -8 碰撞后，两者都发生爆炸。
     */
    asteroids = {8,-8};
    res = {};
    assert(res == Solution().asteroidCollision(asteroids));
    
    /**
     输入：asteroids = [10,2,-5]
     输出：[10]
     解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。
     */
    asteroids = {10,2,-5};
    res = {10};
    assert(res == Solution().asteroidCollision(asteroids));
    
    cout << "OK~" << endl;
    
    return 0;
}
