/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (61.64%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    58.1K
 * Total Submissions: 94.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> vis;
    int target;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int _target) {
        sort(candidates.begin(),candidates.end());
        target = _target;
        vis = vector<bool>(candidates.size(), false);
        dfs(candidates, 0, 0, path);
        return ans;
    }
    void dfs(vector<int>& candidates, int deep, int sum, vector<int>& path){
        if(sum >= target){
            if(sum == target) ans.push_back(path);
            return;
        }
        for(int i = deep; i < candidates.size(); i++){
            if(i && candidates[i] == candidates[i - 1] && !vis[i - 1])
                continue;
            vis[i] = true, path.push_back(candidates[i]);
            dfs(candidates, i + 1, sum + candidates[i], path);
            vis[i] = false, path.pop_back();
        }
    }
};
// @lc code=end

