# 3998. Transform Binary String Using Subsequence Sort

<p>You are given a binary string <code>s</code>. You are also given an array of strings <code>strs</code>, where each <code>strs[i]</code> has the same length as <code>s</code> and consists of characters <code>'0'</code>, <code>'1'</code>, and <code>'?'</code>. Each <code>'?'</code> can be replaced by either <code>'0'</code> or <code>'1'</code>.</p>

<p>You may perform the following operation any number of times (including zero):</p>

<ul>
	<li>Choose any subsequence <code>sub</code> of <code>s</code>.</li>
	<li>Sort <code>sub</code> in non-decreasing order.</li>
	<li>Replace the chosen subsequence in <code>s</code> with the sorted <code>sub</code>, keeping all other characters unchanged.</li>
</ul>

<p>Return a boolean array <code>ans</code>, where <code>ans[i]</code> is <code>true</code> if it's possible to replace all <code>'?'</code> in <code>strs[i]</code> with <code>'0'</code> or <code>'1'</code> and transform <code>s</code> into the resulting string using the allowed operation above, otherwise return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;101&quot;, strs = [&quot;1?1&quot;,&quot;0?1&quot;,&quot;0?0&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">[true,true,false]</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;1100&quot;, strs = [&quot;0011&quot;,&quot;11?1&quot;,&quot;1?1?&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">[true,false,true]</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;1010&quot;, strs = [&quot;0011&quot;]</span></p>

<p><strong>Output:</strong> <span class="example-io">[true]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == s.length &lt;= 2000</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= strs.length &lt;= 2000</code></li>
	<li><code>strs[i].length == n</code></li>
	<li><code>strs[i]</code> consists of <code>'0'</code>, <code>'1'</code>, and <code>'?'</code>.</li>
</ul>

---

**Difficulty:** Hard

**Topics:** String, Greedy, Prefix Sum
