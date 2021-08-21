/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

// @lc code=start
class FreqStack {
private:
    int maxFreq;
    unordered_map<int, int> valToFreqs;
    unordered_map<int, stack<int>> freqToStacks;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = (int)valToFreqs[val] + 1;
        valToFreqs[val] = freq;
        if (!freqToStacks.count(freq))
            freqToStacks[freq] = stack<int>();
        freqToStacks[freq].push(val);
        maxFreq = max(maxFreq, freq);
    }
    
    int pop() {
        int val = freqToStacks[maxFreq].top();
        freqToStacks[maxFreq].pop();
        if (freqToStacks[maxFreq].empty()) maxFreq--;
        
        valToFreqs[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    /**
     输入：
     ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
     [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
     输出：[null,null,null,null,null,null,null,5,7,5,4]
     解释：
     执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

     pop() -> 返回 5，因为 5 是出现频率最高的。
     栈变成 [5,7,5,7,4]。

     pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
     栈变成 [5,7,5,4]。

     pop() -> 返回 5 。
     栈变成 [5,7,4]。

     pop() -> 返回 4 。
     栈变成 [5,7]。
     */
//    FreqStack freqSt;
//    freqSt.push(5);
//    freqSt.push(7);
//    freqSt.push(5);
//    freqSt.push(7);
//    freqSt.push(4);
//    freqSt.push(5);
//    // 5
//    cout << freqSt.pop() << endl;
//    // 7
//    cout << freqSt.pop() << endl;
//    // 5
//    cout << freqSt.pop() << endl;
//    // 4
//    cout << freqSt.pop() << endl;

    /*
     输入：
     ["FreqStack","push","push","push","push","push","push","push","push","push","push","pop","pop","pop","pop","pop","pop","pop","pop","pop","pop"]
     [[],[5],[1],[2],[5],[5],[5],[1],[6],[1],[5],[],[],[],[],[],[],[],[],[],[]]
     输出：[null,null,null,null,null,null,null,null,null,null,null,5,5,1,5,1,5,6,2,1,5]
     */
    FreqStack freqSt;
    freqSt.push(5);
    freqSt.push(1);
    freqSt.push(2);
    freqSt.push(5);
    freqSt.push(5);
    freqSt.push(5);
    freqSt.push(1);
    freqSt.push(6);
    freqSt.push(1);
    freqSt.push(5);
    // 5
    cout << freqSt.pop() << endl;
    // 5
    cout << freqSt.pop() << endl;
    // 1
    cout << freqSt.pop() << endl;
    // 5
    cout << freqSt.pop() << endl;
    // 1
    cout << freqSt.pop() << endl;
    // 5
    cout << freqSt.pop() << endl;
    // 6
    cout << freqSt.pop() << endl;
    // 2
    cout << freqSt.pop() << endl;
    // 1
    cout << freqSt.pop() << endl;
    // 5
    cout << freqSt.pop() << endl;
    
    return 0;
}
