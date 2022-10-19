/*
 * @lc app=leetcode.cn id=1700 lang=swift
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
    func countStudents(_ students: [Int], _ sandwiches: [Int]) -> Int {
        var s1 = students.reduce(0, +)
        var s0 = students.count - s1
        for sandwich in sandwiches {
            if sandwich == 0 && s0 > 0 {
                s0 -= 1
            } else if sandwich == 1 && s1 > 0 {
                s1 -= 1
            } else {
                break
            }
        }
        return s1 + s0
    }
}
// @lc code=end

func main() {
    var students: [Int]
    var sandwiches: [Int]
    var res: Int
    
    /**
     输入：students = [1,1,0,0], sandwiches = [0,1,0,1]
     输出：0
     解释：
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,0,0,1]。
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,0,1,1]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [0,1,1]，三明治栈为 sandwiches = [1,0,1]。
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [1,1,0]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1,0]，三明治栈为 sandwiches = [0,1]。
     - 最前面的学生放弃最顶上的三明治，并回到队列的末尾，学生队列变为 students = [0,1]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = [1]，三明治栈为 sandwiches = [1]。
     - 最前面的学生拿走最顶上的三明治，剩余学生队列为 students = []，三明治栈为 sandwiches = []。
     所以所有学生都有三明治吃。
     */
    students = [1,1,0,0]
    sandwiches = [0,1,0,1]
    res = 0
    assert(res == Solution().countStudents(students, sandwiches))
    
    /**
     输入：students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
     输出：3
     */
    students = [1,1,1,0,0,1]
    sandwiches = [1,0,0,0,1,1]
    res = 3
    assert(res == Solution().countStudents(students, sandwiches))
}
