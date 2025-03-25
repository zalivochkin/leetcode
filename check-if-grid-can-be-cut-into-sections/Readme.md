
<!-- problem:start -->

# [3394. Check if Grid can be Cut into Sections](https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections)

## Description

<!-- description:start -->

<p>You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:</p>

<p>(startx, starty): The bottom-left corner of the rectangle.</p>
<p>(endx, endy): The top-right corner of the rectangle.</p>
<p>Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:</p>

<p>Each of the three resulting sections formed by the cuts contains at least one rectangle.</p>
<p>Every rectangle belongs to exactly one section.</p>
<p>Return true if such cuts can be made; otherwise, return false.</p>

 

<p>Example 1:</p>

<p>Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]</p>

<p>Output: true</p>

<p>Explanation:</p>

<p><img alt="" src="images/tt1drawio.png" style="width: 200px; height: 200px;" /></p>

<p>The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.</p>

<p>Example 2:</p>

<p>Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]</p>

<p>Output: true</p>

<p>Explanation:</p>

<p><img alt="" src="images/tc2drawio.png" style="width: 200px; height: 200px;" /></p>

<p>We can make vertical cuts at x = 2 and x = 3. Hence, output is true.</p>

<p>Example 3:</p>

<p>Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]</p>

<p>Output: false</p>

<p>Explanation:</p>

<p>We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.</p>

 

<p>Constraints:</p>

<p>3 <= n <= 10^9</p>
<p>3 <= rectangles.length <= 10^5</p>
<p>0 <= rectangles[i][0] < rectangles[i][2] <= n</p>
<p>0 <= rectangles[i][1] < rectangles[i][3] <= n</p>
<p>No two rectangles overlap.</p>

<!-- description:end -->
