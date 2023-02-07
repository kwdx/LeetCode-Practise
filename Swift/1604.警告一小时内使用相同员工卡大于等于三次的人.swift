/*
 * @lc app=leetcode.cn id=1604 lang=swift
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */

// @lc code=start
class Solution {
    func alertNames(_ keyName: [String], _ keyTime: [String]) -> [String] {
        var timeMap = [String: [Int]]()
        for i in 0..<keyName.count {
            let name = keyName[i]
            let time = keyTime[i]
            let hour = Int(time.prefix(2)) ?? 0
            let minute = Int(time.suffix(2)) ?? 0
            timeMap[name] = timeMap[name] ?? []
            timeMap[name]?.append(hour * 60 + minute)
        }
        var ans = [String]()
        for (name, times) in timeMap {
            var j = 2
            let times = times.sorted()
            while j < times.count {
                let diff = times[j] - times[j - 2]
                if diff <= 60 {
                    ans.append(name)
                    break
                }
                j += 1
            }
        }
        return ans.sorted()
    }
}
// @lc code=end

func main() {
    var keyName: [String]
    var keyTime: [String]
    var res: [String]
    
    /**
     输入：keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
     输出：["daniel"]
     解释："daniel" 在一小时内使用了 3 次员工卡（"10:00"，"10:40"，"11:00"）。
     */
    keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"]
    keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
    res  = ["daniel"]
    assert(res == Solution().alertNames(keyName, keyTime))
    
    /**
     输入：keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
     输出：["bob"]
     解释："bob" 在一小时内使用了 3 次员工卡（"21:00"，"21:20"，"21:30"）。
     */
    keyName = ["alice","alice","alice","bob","bob","bob","bob"]
    keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
    res  = ["bob"]
    assert(res == Solution().alertNames(keyName, keyTime))
    
    /**
     输入：keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
     输出：[]
     */
    keyName = ["john","john","john"]
    keyTime = ["23:58","23:59","00:01"]
    res  = []
    assert(res == Solution().alertNames(keyName, keyTime))
    
    /**
     输入：keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"], keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
     输出：["clare","leslie"]
     */
    keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"]
    keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
    res  = ["clare","leslie"]
    assert(res == Solution().alertNames(keyName, keyTime))
}
