
<!-- problem:start -->

# [3403. Find the Lexicographically Largest String From the Box I](https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i)

## Description

<!-- description:start -->
<p>You are given a string word, and an integer numFriends.</p>
<p>Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:</p>
    <p>word is split into numFriends non-empty strings, such that no previous round has had the exact same split.</p>
    <p>All the split words are put into a box.</p>
<p>Find the string from the box after all the rounds are finished.</p>

<p>Example 1:</p>
<p>Input: word = "dbca", numFriends = 2</p>
<p>Output: "dbc"</p>
<p>Explanation:</p>
<p>All possible splits are:</p>
    <p>"d" and "bca".</p>
    <p>"db" and "ca".</p>
    <p>"dbc" and "a".</p>

<p>Example 2:</p>
<p>Input: word = "gggg", numFriends = 4</p>
<p>Output: "g"</p>
<p>Explanation:</p>
<p>The only possible split is: "g", "g", "g", and "g".</p>

Con<p>straints:</p>
    <p>1 <= word.length <= 5 * 10^3</p>
    <p>word consists only of lowercase English letters.</p>
    <p>1 <= numFriends <= word.length</p>

<p>Hint 1</p>
<p>Find lexicographically largest substring of size n - numFriends + 1 or less starting at every index.</p>
<!-- description:end -->
