# 3994. Minimum Adjacent Swaps to Partition Array

<p>You are given a binary array <code>nums</code> of length <code>n</code>.</p>

<p>In one operation, you can swap two adjacent elements.</p>

<p>Return the minimum number of operations required to make all the <code>0</code>'s appear before all the <code>1</code>'s (a partitioned array).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,0,1,0,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>One optimal sequence: swap indices 1,2 -> [1,1,0,0,1]; swap indices 3,4 -> [1,1,0,1,0]; swap indices 2,3 -> [1,1,1,0,0].</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0,0,0,1,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The array is already partitioned.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

---

**Difficulty:** Medium

**Topics:** Array, Greedy, Two Pointers
