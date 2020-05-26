/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.28%)
 * Likes:    572
 * Dislikes: 0
 * Total Accepted:    90.5K
 * Total Submissions: 117K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < 1 << n; i++){//2^n种组合
            vector<int> path;
            for(int j = 0; j < n; j++){
                if(i & 1 << j){//比较第j位
                    path.push_back(nums[j]);
                }
            }
            ans.push_back(path);
        }
        return ans;
    }
};
// @lc code=end

