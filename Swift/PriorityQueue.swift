//
//  PriorityQueue.swift
//  Swift_
//
//  Created by warden on 2021/12/14.
//

import Foundation

/// 优先级队列
struct PriorityQueue<Element> {
    private var pq: [Element] = []
    private let cmp: (Element, Element) -> Bool
    
    init(_ cmp: @escaping (Element, Element) -> Bool) {
        self.cmp = cmp
    }
    
    init() where Element: Comparable {
        self.cmp = { $0 < $1 }
    }
    
    /// 堆顶元素
    var top: Element? { pq.first }
    
    /// 堆元素个数
    var count: Int { pq.count }
    
    /// 堆是否为空
    var isEmpty: Bool { pq.isEmpty }
    
    /// 添加元素
    mutating func push(_ element: Element) {
        pq.append(element)
        swim(pq.count - 1)
    }
    
    /// 移除堆顶元素
    @discardableResult
    mutating func pop() -> Element? {
        guard !pq.isEmpty else {
            return nil
        }
        let top = pq[0]
        pq.swapAt(0, pq.count - 1)
        pq.removeLast()
        sink(0)
        return top
    }
    
    /// 父节点的索引
    private func parent(_ index: Int) -> Int {
        (index + 1) / 2 - 1
    }
    
    /// 左子树的索引
    private func left(_ index: Int) -> Int {
        (index + 1) * 2 - 1
    }
    
    /// 右子树的索引
    private func right(_ index: Int) -> Int {
        (index + 1) * 2
    }
    
    /// 上浮以维持优先级队列
    private mutating func swim(_ index: Int) {
        // 上浮到堆顶，就不再上浮
        var k = index
        while k > 0 && compare(parent(k), k) {
            pq.swapAt(parent(k), k)
            k = parent(k)
        }
    }
    
    /// 下沉以维持优先级队列
    private mutating func sink(_ index: Int) {
        // 如果沉到堆底，就沉不下去了
        var k = index
        while left(k) < pq.count {
            
            var child = left(k)
            if right(k) < pq.count && compare(child, right(k)) {
                child = right(k)
            }
            
            if compare(child, k) {
                break
            } else {
                pq.swapAt(child, k)
                k = child
            }
        }
    }
    
    private func compare(_ left: Int, _ right: Int) -> Bool {
        return cmp(pq[left], pq[right])
    }
}
