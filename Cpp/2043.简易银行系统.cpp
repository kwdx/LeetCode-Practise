/*
 * @lc app=leetcode.cn id=2043 lang=cpp
 *
 * [2043] 简易银行系统
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Bank {
private:
    vector<long long> balance;
public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 < 1 ||account1 > balance.size()) return false;
        if (account2 < 1 ||account2 > balance.size()) return false;
        
        if (balance[account1 - 1] < money) {
            return false;
        }
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account < 1 ||account > balance.size()) return false;
        
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account < 1 ||account > balance.size()) return false;
        
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end


int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
     [[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], [10, 50]]
     输出：
     [null, true, true, true, false, false]

     解释：
     Bank bank = new Bank([10, 100, 20, 50, 30]);
     bank.withdraw(3, 10);    // 返回 true ，账户 3 的余额是 $20 ，所以可以取款 $10 。
                              // 账户 3 余额为 $20 - $10 = $10 。
     bank.transfer(5, 1, 20); // 返回 true ，账户 5 的余额是 $30 ，所以可以转账 $20 。
                              // 账户 5 的余额为 $30 - $20 = $10 ，账户 1 的余额为 $10 + $20 = $30 。
     bank.deposit(5, 20);     // 返回 true ，可以向账户 5 存款 $20 。
                              // 账户 5 的余额为 $10 + $20 = $30 。
     bank.transfer(3, 4, 15); // 返回 false ，账户 3 的当前余额是 $10 。
                              // 所以无法转账 $15 。
     bank.withdraw(10, 50);   // 返回 false ，交易无效，因为账户 10 并不存在。
     */
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank bank(balance);
    assert(bank.withdraw(3, 10));
    assert(bank.transfer(5, 1, 20));
    assert(bank.deposit(5, 20));
    assert(!bank.transfer(3, 4, 15));
    assert(!bank.withdraw(10, 50));

    cout << "OK~" << endl;
    
    return 0;
}
