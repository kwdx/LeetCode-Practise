/*
 * @lc app=leetcode.cn id=735 lang=swift
 *
 * [735] 行星碰撞
 */

// @lc code=start
class Solution {
    func asteroidCollision(_ asteroids: [Int]) -> [Int] {
        var st: [Int] = []
        for aster in asteroids {
            var alive = true    // 行星还存活
            while alive, aster < 0, let last = st.last, last > 0 {
                alive = last < -aster
                if last <= -aster { // 撞毁
                    st.removeLast()
                }
            }
            if alive {
                st.append(aster)
            }
        }
        return st
    }
}
// @lc code=end

func main() {
    var asteroids: [Int]
    var res: [Int]
    
    /**
     输入：asteroids = [5,10,-5]
     输出：[5,10]
     解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。
     */
    asteroids = [5,10,-5]
    res = [5,10]
    assert(res == Solution().asteroidCollision(asteroids))
    
    /**
     输入：asteroids = [8,-8]
     输出：[]
     解释：8 和 -8 碰撞后，两者都发生爆炸。
     */
    asteroids = [8,-8]
    res = []
    assert(res == Solution().asteroidCollision(asteroids))
    
    /**
     输入：asteroids = [10,2,-5]
     输出：[10]
     解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。
     */
    asteroids = [10,2,-5]
    res = [10]
    assert(res == Solution().asteroidCollision(asteroids))
}
