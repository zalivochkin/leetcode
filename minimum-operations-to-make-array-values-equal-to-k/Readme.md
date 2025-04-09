
<!-- problem:start -->

# [3375. Minimum Operations to Make Array Values Equal to K](https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k)

## Description

<!-- description:start -->

<p>You are given an integer array nums and an integer k.</p>

<p>An integer h is called valid if all values in the array that are strictly greater than h are identical.</p>

<p>For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.</p>

<p>You are allowed to perform the following operation on nums:</p>

<p>Select an integer h that is valid for the current values in nums.</p>
<p>For each index i where nums[i] > h, set nums[i] to h.</p>
<p>Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.</p>

<p>Constraints:</p>
<p>1 <= nums.length <= 100</p>
<p>1 <= nums[i] <= 100</p>
<p>1 <= k <= 100</p>

<!-- description:end -->
