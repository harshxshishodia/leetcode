# 3992. Rearrange String to Avoid Character Pair

<p>You are given a string <code>s</code> and two distinct lowercase English letters <code>x</code> and <code>y</code>.</p>

<p>Rearrange the characters of <code>s</code> to construct a new string <code>t</code> such that:</p>

<ul>
	<li><code>t</code> is a permutation of <code>s</code>.</li>
	<li>Every occurrence of <code>y</code> appears before every occurrence of <code>x</code> in <code>t</code>.</li>
</ul>

<p>Return <em>any</em> valid string <code>t</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;aabc&quot;, x = &quot;a&quot;, y = &quot;b&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;bcaa&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>All <code>b</code>'s appear before all <code>a</code>'s.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;abcd&quot;, x = &quot;a&quot;, y = &quot;d&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;dbca&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>All <code>d</code>'s appear before all <code>a</code>'s.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
	<li><code>x</code> and <code>y</code> are distinct lowercase English letters.</li>
</ul>

---

**Difficulty:** Easy

**Topics:** String, Counting Sort
