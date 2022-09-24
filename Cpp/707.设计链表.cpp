/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// @lc code=start
struct ListNode {
    int val;
    ListNode *prev, *next;
    ListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
};

class MyLinkedList {
private:
    int size;
    ListNode *head;
    ListNode *tail;
public:
    MyLinkedList() {
        this->size = 0;
        this->head = new ListNode(0);
        this->tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        ListNode *cur;
        if (index + 1 < size - index) {
            cur = head;
            for (int i = 0; i <= index; ++i) {
                cur = cur->next;
            }
        } else {
            cur = tail;
            for (int i = 0; i < size - index; ++i) {
                cur = cur->prev;
            }
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        index = max(0, index);
        ListNode *pred, *succ;
        if (index < size - index) {
            pred = head;
            for (int i = 0; i < index; ++i) {
                pred = pred->next;
            }
            succ = pred->next;
        } else {
            succ = tail;
            for (int i = 0; i < size - index; ++i) {
                succ = succ->prev;
            }
            pred = succ->prev;
        }
        ++size;
        ListNode *node = new ListNode(val);
        node->prev = pred;
        node->next = succ;
        pred->next = node;
        succ->prev = node;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        ListNode *pred, *succ;
        if (index < size - index) {
            pred = head;
            for (int i = 0; i < index; ++i) {
                pred = pred->next;
            }
            succ = pred->next->next;
        } else {
            succ = tail;
            for (int i = 0; i < size - index - 1; i++) {
                succ = succ->prev;
            }
            pred = succ->prev->prev;
        }
        --size;
        ListNode *node = pred->next;
        pred->next = succ;
        succ->prev = pred;
        delete node;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
        
    /**
     MyLinkedList linkedList = new MyLinkedList();
     linkedList.addAtHead(1);
     linkedList.addAtTail(3);
     linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
     linkedList.get(1);            //返回2
     linkedList.deleteAtIndex(1);  //现在链表是1-> 3
     linkedList.get(1);            //返回3
     */
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1, 2);
    assert(2 == linkedList->get(1));
    linkedList->deleteAtIndex(1);
    assert(3 == linkedList->get(1));

    cout << "OK~" << endl;
    
    return 0;
}

