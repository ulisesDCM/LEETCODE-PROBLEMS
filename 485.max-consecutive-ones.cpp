/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (64.05%)
 * Likes:    6610
 * Dislikes: 487
 * Total Accepted:    2M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,1,0,1,1,1]'
 *
 * Given a binary array nums, return the maximum number of consecutive 1's in
 * the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s. The maximum number of consecutive 1s is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1,0,1]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveOnes = 0;
        int consecutiveOnes = 0;

        for (const int& number : nums)
        {
            if (number == 1)
            {
                consecutiveOnes++;
            }
            else
            {
                if (consecutiveOnes > maxConsecutiveOnes)
                {
                    maxConsecutiveOnes = consecutiveOnes;
                }
                consecutiveOnes = 0;
            }
        }

        return (maxConsecutiveOnes > consecutiveOnes) ? maxConsecutiveOnes: consecutiveOnes;
    }
};

// @lc code=end

