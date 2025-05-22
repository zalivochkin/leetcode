
<!-- problem:start -->

# [3362. Zero Array Transformation III](https://leetcode.com/problems/zero-array-transformation-iii)

## Description

<!-- description:start -->
<p>Medium</p>

<p>You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].</p>
Each queries[i] represents the following action on nums:</p>
<p>Decrement the value at each index in the range [li, ri] in nums by at most 1.</p>
<p>The amount by which the value is decremented can be chosen independently for each index.</p>
<p>A Zero Array is an array with all its elements equal to 0.</p>
<p>Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.</p>

<p>Example 1:</p>
<p>Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]</p>
<p>Output: 1</p>
<p>Explanation:</p>
<p>After removing queries[2], nums can still be converted to a zero array.</p>
<p>Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.</p>
<p>Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.</p>

<p>Example 2:</p>
<p>Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]</p>
<p>Output: 2</p>
<p>Explanation:</p>
<p>We can remove queries[2] and queries[3].</p>

<p>Example 3:</p>
<p>Input: nums = [1,2,3,4], queries = [[0,3]]</p>
<p>Output: -1</p>
<p>Explanation:</p>
<p>nums cannot be converted to a zero array even after using all the queries.</p>

<p>Constraints:</p>
<p>1 <= nums.length <= 10^5</p>
<p>0 <= nums[i] <= 10^5</p>
<p>1 <= queries.length <= 10^5</p>
<p>queries[i].length == 2</p>
<p>0 <= li <= ri < nums.length</p>

<p>Hint 1</p>
<p>Sort the queries.</p>
<p>Hint 2</p>
<p>We need to greedily pick the queries with farthest ending point first.</p>

<!-- description:end -->
<!-- problem:end -->
