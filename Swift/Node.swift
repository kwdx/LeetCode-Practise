//
//  Node.swift
//  Swift_
//
//  Created by warden on 2021/11/21.
//

import Foundation

public class Node {
    public var val: Int
    public var children: [Node]
    public init(_ val: Int, _ childrend: [Node] = []) {
        self.val = val
        self.children = childrend
    }
}
