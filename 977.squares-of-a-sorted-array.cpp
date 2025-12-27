/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (73.44%)
 * Likes:    10000
 * Dislikes: 266
 * Total Accepted:    2.5M
 * Total Submissions: 3.3M
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 * 
 * 
 * 
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */

// @lc code=start
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> sortedSquaresValues( nums.size() );
        int absNumLeftp = 0;
        int numsRightp = nums.size() - 1;
        int sortedRightp = sortedSquaresValues.size() - 1;
        int absNumRight = 0;
        int absNumLeft = 0;

        while( absNumLeftp <= numsRightp )
        {
            absNumLeft = abs( nums.at(absNumLeftp) );
            absNumRight = abs( nums.at(numsRightp) );

            if ( absNumRight > absNumLeft )
            {
                sortedSquaresValues[sortedRightp] =  (absNumRight*absNumRight);
                numsRightp--;
            }
            else
            {
                sortedSquaresValues[sortedRightp] =  (absNumLeft*absNumLeft);
                absNumLeftp++;
            }

            sortedRightp--;
        }

        return sortedSquaresValues;
    }
};
// @lc code=end

