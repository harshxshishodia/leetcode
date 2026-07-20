# 3995. Minimum Cost to Convert String III

<p>You are given two strings <code>source</code> and <code>target</code> of equal length <code>n</code>, consisting of lowercase English letters.</p>

<p>You are also given two arrays <code>original</code> and <code>changed</code> of length <code>m</code>, and an integer array <code>cost</code> of length <code>m</code>, where <code>cost[i]</code> is the cost to change the character <code>original[i]</code> to <code>changed[i]</code>.</p>

<p>Additionally, you are given an array <code>allowed</code> of length <code>n</code>, where <code>allowed[i]</code> is a set of characters that the character at position <code>i</code> can be changed to directly (without using the transformation graph).</p>

<p>In one operation, you can:</p>

<ul>
	<li>Change a character at position <code>i</code> to any character in <code>allowed[i]</code> with cost 0.</li>
	<li>Or use the transformation graph: change a character <code>a</code> to <code>b</code> with cost equal to the shortest path from <code>a</code> to <code>b</code> in the directed graph defined by <code>original</code>, <code>changed</code>, <code>cost</code>.</li>
</ul>

<p>Return the minimum total cost to convert <code>source</code> into <code>target</code>. If it is impossible, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">source = &quot;abcd&quot;, target = &quot;acbe&quot;, original = [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;,&quot;c&quot;], changed = [&quot;b&quot;,&quot;c&quot;,&quot;b&quot;,&quot;e&quot;], cost = [2,3,1,4], allowed = [[&quot;a&quot;,&quot;b&quot;],[&quot;b&quot;],[&quot;c&quot;,&quot;e&quot;],[&quot;d&quot;]]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>0 &lt;= m &lt;= 2000</code></li>
	<li><code>source.length == target.length == n</code></li>
	<li><code>source[i]</code>, <code>target[i]</code>, <code>original[i]</code>, <code>changed[i]</code> are lowercase English letters.</li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>allowed[i]</code> consists of distinct lowercase English letters.</li>
</ul>

---

**Difficulty:** Hard

**Topics:** Graph, Shortest Path, Dynamic Programming
