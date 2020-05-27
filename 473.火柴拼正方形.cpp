/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode-cn.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (38.83%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 21.1K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 
 * 还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。
 * 
 * 输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,2,2,2]
 * 输出: true
 * 
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,3,3,3,4]
 * 输出: false
 * 
 * 解释: 不能用所有火柴拼成一个正方形。
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的火柴长度和在 0 到 10^9之间。
 * 火柴数组的长度不超过15。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<bool> vis;
    int side;
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        vis = vector<bool>(nums.size(), false);
        int sum = 0;
        for(int &i : nums) sum += i;
        if(sum % 4) return false;
        side = sum / 4;
        sort(nums.begin(), nums.end());//剪枝1从大到小遍历
        reverse(nums.begin(), nums.end());
        return dfs(nums, 0, 0, side);
    }

    bool dfs(vector<int>& nums, int start, int cnt, int tot){
        if(!tot){
            if(++cnt == 4) return true;
            return dfs(nums, 0, cnt, side);
        }
        for(int i = start; i < nums.size(); i++){//剪枝1：sort后，从start开始枚举
            if(!vis[i] && tot >= nums[i] ){
                if(i && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
                //剪枝2：相同长度的木棍只枚举第一个没用到的，强力
                vis[i] = true;
                if(dfs(nums, i + 1, cnt, tot - nums[i])) return true;
                vis[i] = false;
                if(tot == nums[i] || tot == side) return false;
                //剪枝3：若当前木棍处在某条边的开头或结尾并返回失败
                //则这条边没有地方放，直接false
            }
        }
        return false;
    }

};
// @lc code=end

