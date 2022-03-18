/*
 * @lc app=leetcode.cn id=2043 lang=swift
 *
 * [2043] 简易银行系统
 */

// @lc code=start

class Bank {
    
    private var balance: [Int]
    
    init(_ balance: [Int]) {
        self.balance = balance
    }
    
    func transfer(_ account1: Int, _ account2: Int, _ money: Int) -> Bool {
        let range = 1...(balance.count)
        guard
            range.contains(account1),
            range.contains(account2),
            balance[account1 - 1] >= money
        else { return false }
        balance[account1 - 1] -= money
        balance[account2 - 1] += money
        return true
    }
    
    func deposit(_ account: Int, _ money: Int) -> Bool {
        guard (1...(balance.count)).contains(account) else { return false }
        
        balance[account - 1] += money
        return true
    }
    
    func withdraw(_ account: Int, _ money: Int) -> Bool {
        guard
            (1...(balance.count)).contains(account),
            balance[account - 1] >= money
        else { return false }
        
        balance[account - 1] -= money
        return true
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * let obj = Bank(balance)
 * let ret_1: Bool = obj.transfer(account1, account2, money)
 * let ret_2: Bool = obj.deposit(account, money)
 * let ret_3: Bool = obj.withdraw(account, money)
 */
// @lc code=end

func main() {
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
    let bank = Bank([10, 100, 20, 50, 30])
    assert(bank.withdraw(3, 10))
    assert(bank.transfer(5, 1, 20))
    assert(bank.deposit(5, 20))
    assert(!bank.transfer(3, 4, 15))
    assert(!bank.withdraw(10, 50))
}
