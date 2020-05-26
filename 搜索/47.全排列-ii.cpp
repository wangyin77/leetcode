/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (58.70%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    60K
 * Total Submissions: 102.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis = vector<bool>(nums.size(), false);
        sort(nums.begin(),nums.end());//排序
        vector<int> path;
        dfs(nums, 0, 0, path);
        return ans;
    }

    void dfs(vector<int>& nums, int deep, int start, vector<int> & path){
        if(deep == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!vis[i]){
                //剪枝条件
                if(i && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
                //与前一个数相同，并且前一个数没被用到，则continue；
                //即重复的数只用没vis到的最前面的那个
                vis[i] = true, path.push_back(nums[i]);    
                dfs(nums, deep + 1, 0, path);
                vis[i] = false, path.pop_back();
            }
        }
    }
};
// @lc code=end

