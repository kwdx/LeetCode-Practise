/*
 * @lc app=leetcode.cn id=2013 lang=swift
 *
 * [2013] 检测正方形
 */

// @lc code=start

class DetectSquares {
    
    private var x2y: [Int: [Int: Int]] = [:]

    init() {

    }
    
    func add(_ point: [Int]) {
        var yCnts = x2y[point[0]] ?? [:]
        yCnts[point[1]] = 1 + (yCnts[point[1]] ?? 0)
        x2y[point[0]] = yCnts
    }
    
    func count(_ point: [Int]) -> Int {
        let x = point[0], y = point[1]
        var ans = 0
        guard let yCnts = x2y[x] else { return 0 }
        for (y1, cnt) in yCnts {
            if y == y1 {
                continue
            }
            let side = y - y1
            for x1 in [x + side, x - side] {
                ans += cnt * (x2y[x1]?[y] ?? 0) * (x2y[x1]?[y1] ?? 0);
            }
        }
        return ans
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * let obj = DetectSquares()
 * obj.add(point)
 * let ret_2: Int = obj.count(point)
 */
// @lc code=end

func main() {
    /**
     输入：
     ["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
     [[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
     输出：
     [null, null, null, null, 1, 0, null, 2]

     解释：
     DetectSquares detectSquares = new DetectSquares();
     detectSquares.add([3, 10]);
     detectSquares.add([11, 2]);
     detectSquares.add([3, 2]);
     detectSquares.count([11, 10]); // 返回 1 。你可以选择：
                                    //   - 第一个，第二个，和第三个点
     detectSquares.count([14, 8]);  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
     detectSquares.add([11, 2]);    // 允许添加重复的点。
     detectSquares.count([11, 10]); // 返回 2 。你可以选择：
                                    //   - 第一个，第二个，和第三个点
                                    //   - 第一个，第三个，和第四个点
     */
    let detectSquares = DetectSquares()
    detectSquares.add([3, 10])
    detectSquares.add([11, 2])
    detectSquares.add([3, 2])
    assert(1 == detectSquares.count([11, 10]))
    assert(0 == detectSquares.count([14, 8]))
    detectSquares.add([11, 2])
    assert(2 == detectSquares.count([11, 10]))
}
