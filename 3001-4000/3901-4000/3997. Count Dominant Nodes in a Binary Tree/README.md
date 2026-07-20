# 3997. Count Dominant Nodes in a Binary Tree

<p>You are given the <code>root</code> of a <strong>complete binary tree</strong>.</p>

<p>A node <code>x</code> is called <strong>dominant</strong> if its value is equal to the maximum value among all nodes in the subtree rooted at <code>x</code>.</p>

<p>Return the number of <strong>dominant</strong> nodes in the tree.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [5,3,8,2,4,7,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>The leaf nodes with values 2, 4, 7, and 1 are dominant. The node with value 8 is dominant because its value is the maximum value in its subtree <code>[8, 7, 1]</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The leaf nodes with values 1, 2, and 3 are dominant. The node with value 2 whose subtree is <code>[2, 1, 2]</code> is dominant.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li>The tree is guaranteed to be a <strong>complete binary tree</strong>.</li>
</ul>

---

**Difficulty:** Medium

**Topics:** Tree, Depth-First Search, Binary Tree
