# 3999. Minimum Number of String Groups Through Transformations

<p>You are given an array of strings <code>words</code>.</p>

<p>Define a transformation on a string <code>s</code> as follows:</p>

<ul>
	<li>Let <code>E</code> be the subsequence of characters at even indices of <code>s</code>.</li>
	<li>Let <code>O</code> be the subsequence of characters at odd indices of <code>s</code>.</li>
	<li>Independently cyclically shift <code>E</code> and <code>O</code> by any number of positions to the right, possibly zero.</li>
	<li>Reconstruct the string by placing the shifted <code>E</code> characters back into even indices and the shifted <code>O</code> characters back into odd indices.</li>
</ul>

<p>Two strings are <strong>equivalent</strong> if one can be transformed into the other by a single transformation.</p>

<p>Partition <code>words</code> into the minimum number of groups such that:</p>

<ul>
	<li>Every string belongs to exactly one group.</li>
	<li>Every pair of strings in the same group are equivalent.</li>
</ul>

<p>Return an integer denoting the minimum number of groups.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = [&quot;ntgwz&quot;,&quot;zwntg&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = [&quot;abc&quot;,&quot;cab&quot;,&quot;bac&quot;,&quot;acb&quot;,&quot;bca&quot;,&quot;cba&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">words = [&quot;leet&quot;,&quot;abb&quot;,&quot;bab&quot;,&quot;deed&quot;,&quot;edde&quot;,&quot;code&quot;,&quot;bba&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 5 * 10<sup>5</sup></code></li>
	<li>The sum of <code>words[i].length</code> does not exceed <code>5 * 10<sup>5</sup></code>.</li>
	<li><code>words[i]</code> consist of lowercase English letters.</li>
</ul>

---

**Difficulty:** Medium

**Topics:** Hash Table, String, Grouping
