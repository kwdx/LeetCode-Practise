/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
constexpr int MAX_LEVEL = 32;
struct SkiplistNode {
    int val;
    vector<SkiplistNode*> forward;
    SkiplistNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {}
};

class Skiplist {
private:
    SkiplistNode* head;
    int level;
    uniform_int_distribution<int> dis;
    
public:
    Skiplist(): head(new SkiplistNode(-1)), level(0), dis(0, 4) {
        
    }
    
    bool search(int target) {
        SkiplistNode* cur = this->head;
        for (int i = level - 1; i >= 0; --i) {
            /* 找到第 i 层小于且最接近 target 的元素 */
            while (cur->forward[i] && cur->forward[i] -> val < target) {
                cur = cur->forward[i];
            }
        }
        cur = cur->forward[0];
        /* 检测当前元素的值是否等于 target */
        if (cur && cur->val == target) {
            return true;
        }
        return false;
    }
    
    void add(int num) {
        vector<SkiplistNode*> update(MAX_LEVEL, head);
        SkiplistNode* cur  = this->head;
        for (int i = level - 1; i >= 0; --i) {
            /* 找到第 i 层小于且最接近 num 的元素 */
            while (cur->forward[i] && cur->forward[i]->val < num) {
                cur = cur->forward[i];
            }
            update[i] = cur;
        }
        int lv = randomLevel();
        level = max(level, lv);
        SkiplistNode* newNode = new SkiplistNode(num, lv);
        for (int i = 0; i < lv; ++i) {
            /* 对第 i 层的状态进行更新，将当前元素的forward指向新的节点 */
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<SkiplistNode*> update(MAX_LEVEL, nullptr);
        SkiplistNode* cur = this->head;
        for (int i = level - 1; i >= 0; --i) {
            /* 找到第 i 层小于且最接近 num 的元素 */
            while (cur->forward[i] && cur->forward[i]->val < num) {
                cur = cur->forward[i];
            }
            update[i] = cur;
        }
        cur = cur->forward[0];
        /* 如果值不存在则返回 false */
        if (!cur || cur->val != num) {
            return false;
        }
        for (int i = 0; i < level; ++i) {
            if (update[i]->forward[i] != cur) {
                break;
            }
            /* 对第 i 层的状态进行更新，将 forward 指向被删除节点的下一跳 */
            update[i]->forward[i] = cur->forward[i];
        }
        delete cur;
        /* 更新当前的 level */
        while (level > 1 && head->forward[level - 1] == nullptr) {
            --level;
        }
        return true;
    }
    
    int randomLevel() {
        int lv = 1;
        /* 随机生成 lv */
        while ((rand() & 0x3) < 1 && lv < MAX_LEVEL) {
            lv++;
        }
        return lv;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
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
    Skiplist skiplist;
    skiplist.add(1);
    skiplist.add(2);
    skiplist.add(3);
    assert(false == skiplist.search(0));
    skiplist.add(4);
    assert(true == skiplist.search(1));
    assert(false == skiplist.erase(0));
    assert(true == skiplist.erase(1));
    assert(false == skiplist.search(1));
    
    cout << "OK~" << endl;
    
    return 0;
}
