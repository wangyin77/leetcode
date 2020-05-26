/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.06%)
 * Likes:    717
 * Dislikes: 0
 * Total Accepted:    131.2K
 * Total Submissions: 172.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vis = vector<bool>(nums.size(), false);
        dfs(nums, 0, path);
        return ans;    
    }

    void dfs(vector<int>& nums, int deep, vector<int>& path){
        if(deep == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!vis[i]){
                vis[i] = true, path.push_back(nums[i]);
                dfs(nums, deep + 1, path);
                vis[i] = false, path.pop_back();
            }
        }        
    }
};
// @lc code=end

