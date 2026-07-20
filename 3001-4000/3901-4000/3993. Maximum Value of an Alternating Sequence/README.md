# 3993. Maximum Value of an Alternating Sequence

<p>You are given three integers <code>n</code>, <code>m</code>, and <code>k</code>.</p>

<p>Consider a sequence <code>seq</code> of length <code>n</code> that satisfies the following:</p>

<ul>
	<li>Each element is an integer between <code>0</code> and <code>m</code> inclusive.</li>
	<li>The sequence <strong>strictly alternates</strong> going up and down. That is, <code>seq[0] &lt; seq[1] &gt; seq[2] &lt; seq[3] &gt; ...</code> or <code>seq[0] &gt; seq[1] &lt; seq[2] &gt; seq[3] &lt; ...</code>.</li>
	<li>The absolute difference between adjacent elements is at most <code>k</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> possible value of any element in <code>seq</code>. If no such sequence exists, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 2, m = 5, k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>One possible sequence is <code>[2, 5]</code>. The maximum value is 5.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 3, m = 10, k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>One possible sequence is <code>[4, 6, 5]</code>. The maximum value is 6.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= m &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

---

**Difficulty:** Medium

**Topics:** Math, Greedy
