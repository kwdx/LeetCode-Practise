/*
 * @lc app=leetcode.cn id=284 lang=cpp
 *
 * [284] 顶端迭代器
 */

#include <iostream>
#include <queue>

using namespace std;

class Iterator {
    const vector<int>* nums;
    int index;
public:
    Iterator(const vector<int>& nums) {
        this->nums = &nums;
        this->index = 0;
    }
    Iterator(const Iterator& iter);
    
    // Returns the next element in the iteration.
    int next() {
        return (*nums)[index++];
    }
    
    // Returns true if the iteration has more elements.
    bool hasNext() const {
        return index < (*nums).size();
    }
};

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool flag;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextElement;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
        return ret;
	}
	
	bool hasNext() const {
        return flag;
	}
};
// @lc code=end

int main(int argc, const char * argv[]) {
    
    /**
     输入：
     ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
     [[[1, 2, 3]], [], [], [], [], []]
     输出：
     [null, 1, 2, 2, 3, false]

     解释：
     PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
     peekingIterator.next();    // 返回 1 ，指针移动到下一个元素 [1,2,3]
     peekingIterator.peek();    // 返回 2 ，指针未发生移动 [1,2,3]
     peekingIterator.next();    // 返回 2 ，指针移动到下一个元素 [1,2,3]
     peekingIterator.next();    // 返回 3 ，指针移动到下一个元素 [1,2,3]
     peekingIterator.hasNext(); // 返回 False
     */
    vector<int> nums = {1,2,3};
    PeekingIterator peekingIterator(nums);
    assert(1 == peekingIterator.next());
    assert(2 == peekingIterator.peek());
    assert(2 == peekingIterator.next());
    assert(3 == peekingIterator.next());
    assert(!peekingIterator.hasNext());
    
    cout << "OK~" << endl;
    
    return 0;
}
