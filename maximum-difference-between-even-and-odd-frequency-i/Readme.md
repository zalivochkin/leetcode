
<!-- problem:start -->

# [3442. Maximum Difference Between Even and Odd Frequency I](https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i)

## Description

<!-- description:start -->

<p>You are given a string s consisting of lowercase English letters.</p>
<p>Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:</p>
    <p>a1 has an odd frequency in the string.</p>
    <p>a2 has an even frequency in the string.</p>
<p>Return this maximum difference.</p>

<p>Example 1:</p>
<p>Input: s = "aaaaabbc"</p>
<p>Output: 3</p>
<p>Explanation:</p>
<p>    The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.</p>
<p>    The maximum difference is 5 - 2 = 3.</p>

<p>Example 2:</p>
<p>Input: s = "abcabcab"</p>
<p>Output: 1</p>
<p>Explanation:</p>
<p>    The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.</p>
<p>    The maximum difference is 3 - 2 = 1.</p>

<p>Constraints:</p>
<p>    3 <= s.length <= 100</p>
<p>    s consists only of lowercase English letters.</p>
<p>    s contains at least one character with an odd frequency and one with an even frequency.</p>

<p>Hint 1</p>
<p>Use a frequency map to identify the maximum odd and minimum even frequencies. Then, calculate their difference.</p>
<!-- description:end -->
