/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valToIndex.count(val)) return false;

        valToIndex[val] = (int)nums.size();
        nums.push_back(val);

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!valToIndex.count(val)) return false;

        int index = valToIndex[val];
        valToIndex[nums.back()] = index;
        swap(nums[index], nums.back());
        nums.pop_back();
        valToIndex.erase(val);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    /**
     // 初始化一个空的集合。
     RandomizedSet randomSet = new RandomizedSet();

     // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
     randomSet.insert(1);

     // 返回 false ，表示集合中不存在 2 。
     randomSet.remove(2);

     // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
     randomSet.insert(2);

     // getRandom 应随机返回 1 或 2 。
     randomSet.getRandom();

     // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
     randomSet.remove(1);

     // 2 已在集合中，所以返回 false 。
     randomSet.insert(2);

     // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
     randomSet.getRandom();
     */
    RandomizedSet* obj = new RandomizedSet();
    // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
    assert(obj->insert(1));
    // 返回 false ，表示集合中不存在 2 。
    assert(!obj->remove(2));
    // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
    assert(obj->insert(2));
    // getRandom 应随机返回 1 或 2 。
    int num = obj->getRandom();
    assert(num == 1 || num == 2);
    // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
    assert(obj->remove(1));
    // 2 已在集合中，所以返回 false 。
    assert(!obj->insert(2));
    // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
    assert(obj->getRandom() == 2);

    cout << "OK~" << endl;

    return 0;
}
