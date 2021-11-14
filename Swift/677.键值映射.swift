/*
 * @lc app=leetcode.cn id=677 lang=swift
 *
 * [677] 键值映射
 */

// @lc code=start

class TrieNode {
    var val = 0
    var children: [TrieNode?] = .init(repeating: nil, count: 26)
}

class MapSum {
    
    private let root = TrieNode()
    private var cnt = [String: Int]()

    init() {

    }
    
    func insert(_ key: String, _ val: Int) {
        var delta = val
        if let val_ = cnt[key] {
            delta -= val_
        }
        cnt[key] = val
        var node = root
        for c in key.unicodeScalars {
            let node_ = node.children[Int(c.value) - 97] ?? TrieNode()
            node.children[Int(c.value) - 97] = node_
            node = node_
            node.val += delta
        }
    }
    
    func sum(_ prefix: String) -> Int {
        var node = root
        for c in prefix.unicodeScalars {
            if let node_ = node.children[Int(c.value) - 97] {
                node = node_
            } else {
                return 0
            }
        }
        return node.val;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * let obj = MapSum()
 * obj.insert(key, val)
 * let ret_2: Int = obj.sum(prefix)
 */
// @lc code=end

func main() {
    /**
     输入：
     ["MapSum", "insert", "sum", "insert", "sum"]
     [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
     输出：
     [null, null, 3, null, 5]

     解释：
     MapSum mapSum = new MapSum();
     mapSum.insert("apple", 3);
     mapSum.sum("ap");           // return 3 (apple = 3)
     mapSum.insert("app", 2);
     mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
     */
    let obj = MapSum()
    obj.insert("apple", 3)
    assert(3 == obj.sum("ap"))
    obj.insert("app", 2)
    assert(5 == obj.sum("ap"))
}
