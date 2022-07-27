/*
 * @lc app=leetcode.cn id=1206 lang=swift
 *
 * [1206] 设计跳表
 */

// @lc code=start

class Skiplist {
    
    private var routes: [Int: Int] = [:]

    init() {

    }
    
    func search(_ target: Int) -> Bool {
        routes[target] != nil
    }
    
    func add(_ num: Int) {
        routes[num] = 1 + (routes[num] ?? 0)
    }
    
    func erase(_ num: Int) -> Bool {
        if let val = routes[num] {
            if val == 1 {
                routes.removeValue(forKey: num)
            } else {
                routes[num] = val - 1
            }
            return true
        }
        return false
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * let obj = Skiplist()
 * let ret_1: Bool = obj.search(target)
 * obj.add(num)
 * let ret_3: Bool = obj.erase(num)
 */
// @lc code=end

func main() {
    /**
     输入
     ["Skiplist", "add", "add", "add", "search", "add", "search", "erase", "erase", "search"]
     [[], [1], [2], [3], [0], [4], [1], [0], [1], [1]]
     输出
     [null, null, null, null, false, null, true, false, true, false]

     解释
     Skiplist skiplist = new Skiplist();
     skiplist.add(1);
     skiplist.add(2);
     skiplist.add(3);
     skiplist.search(0);   // 返回 false
     skiplist.add(4);
     skiplist.search(1);   // 返回 true
     skiplist.erase(0);    // 返回 false，0 不在跳表中
     skiplist.erase(1);    // 返回 true
     skiplist.search(1);   // 返回 false，1 已被擦除
     */
    let skiplist = Skiplist()
    skiplist.add(1)
    skiplist.add(2)
    skiplist.add(3)
    assert(false == skiplist.search(0))
    skiplist.add(4)
    assert(true == skiplist.search(1))
    assert(false == skiplist.erase(0))
    assert(true == skiplist.erase(1))
    assert(false == skiplist.search(1))
}
