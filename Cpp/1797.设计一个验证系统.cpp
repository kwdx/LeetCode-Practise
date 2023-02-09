/*
 * @lc app=leetcode.cn id=1797 lang=cpp
 *
 * [1797] 设计一个验证系统
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> codes;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        codes[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (!codes.count(tokenId)) {
            return;
        }
        int time = codes[tokenId];
        if (time <= currentTime) {
            codes.erase(tokenId);
            return;
        }
        generate(tokenId, currentTime);
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto &[token, time] : codes) {
            if (time > currentTime) {
                ans += 1;
            }
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
// @lc code=end

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     输入：
     ["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", "generate", "renew", "renew", "countUnexpiredTokens"]
     [[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], ["bbb", 10], [15]]
     输出：
     [null, null, null, 1, null, null, null, 0]

     解释：
     AuthenticationManager authenticationManager = new AuthenticationManager(5); // 构造 AuthenticationManager ，设置 timeToLive = 5 秒。
     authenticationManager.renew("aaa", 1); // 时刻 1 时，没有验证码的 tokenId 为 "aaa" ，没有验证码被更新。
     authenticationManager.generate("aaa", 2); // 时刻 2 时，生成一个 tokenId 为 "aaa" 的新验证码。
     authenticationManager.countUnexpiredTokens(6); // 时刻 6 时，只有 tokenId 为 "aaa" 的验证码未过期，所以返回 1 。
     authenticationManager.generate("bbb", 7); // 时刻 7 时，生成一个 tokenId 为 "bbb" 的新验证码。
     authenticationManager.renew("aaa", 8); // tokenId 为 "aaa" 的验证码在时刻 7 过期，且 8 >= 7 ，所以时刻 8 的renew 操作被忽略，没有验证码被更新。
     authenticationManager.renew("bbb", 10); // tokenId 为 "bbb" 的验证码在时刻 10 没有过期，所以 renew 操作会执行，该 token 将在时刻 15 过期。
     authenticationManager.countUnexpiredTokens(15); // tokenId 为 "bbb" 的验证码在时刻 15 过期，tokenId 为 "aaa" 的验证码在时刻 7 过期，所有验证码均已过期，所以返回 0 。
     */
    AuthenticationManager obj(5);
    obj.renew("aaa", 1);
    obj.generate("aaa", 2);
    assert(1 == obj.countUnexpiredTokens(6));
    obj.generate("bbb", 7);
    obj.renew("aaa", 8);
    obj.renew("bbb", 10);
    assert(0 == obj.countUnexpiredTokens(15));

    cout << "OK~" << endl;
    
    return 0;
}
