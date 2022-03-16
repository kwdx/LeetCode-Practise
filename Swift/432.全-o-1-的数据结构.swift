/*
 * @lc app=leetcode.cn id=432 lang=swift
 *
 * [432] 全 O(1) 的数据结构
 */

// @lc code=start

class AllOne {

    private class Node {
        var cnt = 0
        var sets: Set<String> = []
        var left: Node?
        var right: Node?
        
        init(_ cnt: Int) {
            self.cnt = cnt
        }
    }

    private var head = Node(-1000)
    private var tail = Node(-1000)
    private var map: [String: Node] = [:]
    
    init() {
        head.right = tail
        tail.left = head
    }
    
    func inc(_ key: String) {
        if let node = map[key] {
            node.sets.remove(key)
            let next: Node
            if node.right?.cnt == node.cnt + 1 {
                next = node.right!
            } else {
                next = Node(node.cnt + 1)
                next.right = node.right
                next.left = node
                node.right?.left = next
                node.right = next
            }
            next.sets.insert(key)
            map[key] = next
            clear(node)
        } else {
            let node: Node
            if head.right?.cnt == 1 {
                node = head.right!
            } else {
                node = Node(1)
                node.right = head.right
                node.left = head
                head.right?.left = node
                head.right = node
            }
            node.sets.insert(key)
            map[key] = node
        }
    }
    
    func dec(_ key: String) {
        guard let node = map[key] else { return }
        node.sets.remove(key)

        if node.cnt == 1 {
            map.removeValue(forKey: key)
        } else {
            let prev: Node
            if (node.left?.cnt == node.cnt - 1) {
                prev = node.left!
            } else {
                prev = Node(node.cnt - 1)
                prev.right = node
                prev.left = node.left
                node.left?.right = prev
                node.left = prev
            }
            prev.sets.insert(key)
            map[key] = prev
        }
        clear(node)
    }
    
    func getMaxKey() -> String {
        tail.left?.sets.first ?? ""
    }
    
    func getMinKey() -> String {
        head.right?.sets.first ?? ""
    }
    
    private func clear(_ node: Node) {
        if node.sets.isEmpty {
            node.left?.right = node.right
            node.right?.left = node.left
        }
    }
}

/**
 * Your AllOne object will be instantiated and called as such:
 * let obj = AllOne()
 * obj.inc(key)
 * obj.dec(key)
 * let ret_3: String = obj.getMaxKey()
 * let ret_4: String = obj.getMinKey()
 */
// @lc code=end

func main() {
    /**
     输入
     ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
     [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
     输出
     [null, null, null, "hello", "hello", null, "hello", "leet"]

     解释
     AllOne allOne = new AllOne();
     allOne.inc("hello");
     allOne.inc("hello");
     allOne.getMaxKey(); // 返回 "hello"
     allOne.getMinKey(); // 返回 "hello"
     allOne.inc("leet");
     allOne.getMaxKey(); // 返回 "hello"
     allOne.getMinKey(); // 返回 "leet"
     */
    let allOne = AllOne()
    allOne.inc("hello")
    allOne.inc("hello")
    assert("hello" == allOne.getMaxKey())
    assert("hello" == allOne.getMinKey())
    allOne.inc("leet")
    assert("hello" == allOne.getMaxKey())
    assert("leet" == allOne.getMinKey())
}
