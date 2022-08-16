/*
 * @lc app=leetcode.cn id=1656 lang=swift
 *
 * [1656] 设计有序流
 */

// @lc code=start

class OrderedStream {

    private var elements: [String?]
    private var ptr = 1
    
    init(_ n: Int) {
        elements =  .init(repeating: nil, count: n + 1)
    }
    
    func insert(_ idKey: Int, _ value: String) -> [String] {
        var ans: [String] = []
        elements[idKey] = value
        while ptr < elements.count, let val = elements[ptr] {
            ptr += 1
            ans.append(val)
        }
        return ans
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * let obj = OrderedStream(n)
 * let ret_1: [String] = obj.insert(idKey, value)
 */
// @lc code=end

func main() {
    /**
     输入
     ["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
     [[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], [4, "ddddd"]]
     输出
     [null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]

     解释
     OrderedStream os= new OrderedStream(5);
     os.insert(3, "ccccc"); // 插入 (3, "ccccc")，返回 []
     os.insert(1, "aaaaa"); // 插入 (1, "aaaaa")，返回 ["aaaaa"]
     os.insert(2, "bbbbb"); // 插入 (2, "bbbbb")，返回 ["bbbbb", "ccccc"]
     os.insert(5, "eeeee"); // 插入 (5, "eeeee")，返回 []
     os.insert(4, "ddddd"); // 插入 (4, "ddddd")，返回 ["ddddd", "eeeee"]
     */
    let os = OrderedStream(5)
    assert([] == os.insert(3, "ccccc"))
    assert(["aaaaa"] == os.insert(1, "aaaaa"))
    assert(["bbbbb", "ccccc"] == os.insert(2, "bbbbb"))
    assert([] == os.insert(5, "eeeee"))
    assert(["ddddd", "eeeee"] == os.insert(4, "ddddd"))
}
