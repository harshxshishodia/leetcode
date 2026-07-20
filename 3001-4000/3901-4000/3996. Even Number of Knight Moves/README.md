# 3996. Even Number of Knight Moves

<p>You are given two integer arrays <code>start</code> and <code>target</code>, where each array is of the form <code>[x, y]</code> representing a cell on a standard <code>8 x 8</code> chessboard.</p>

<p>Return <code>true</code> if a knight can move from <code>start</code> to <code>target</code> in an <strong>even</strong> number of moves. Otherwise, return <code>false</code>.</p>

<p><strong>Note:</strong> A valid knight move consists of moving two squares in one direction and one square perpendicular to it.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">start = [1,1], target = [2,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>One possible sequence of moves is <code>(1, 1) -> (3, 2) -> (2, 4) -> (4, 3) -> (2, 2)</code>. The knight reaches the target in 4 moves, which is even.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">start = [4,5], target = [6,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>It is impossible to reach target in an even number of moves.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>start.length == target.length == 2</code></li>
	<li><code>0 &lt;= start[i], target[i] &lt;= 7</code></li>
</ul>

---

**Difficulty:** Easy

**Topics:** Math, Parity
