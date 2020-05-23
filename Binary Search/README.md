<h1>Binary Search Variants</h1>
<h3>Template 1</h3>
<pre>
    <code>
int binarySearch(vector<int> &nums, int target)
{
    if(nums.size() == 0)
        return -1;
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    // End Condition: left > right
    return -1;
}   </code>
    </pre>
<p>Template one is the most basic and elementary form of Binary Search. It is the standard Binary Search Template that most high schools or universities use when they first teach students computer science. It is used to search for an element or condition which can be determined by accessing a single index in the array.</p>

<h4>Key Attributes:</h4>
<ol>
  <li>Most basic and elementary form of Binary Search</li>
  <li>Search Condition can be determined without comparing to the element's neighbors (or use specific elements around it)</li>
  <li>No post-processing required because at each step, you are checking to see if the element has been found. If you reach the end, then you know the element is not found</li>
</ol>
<h4>Distinguishing Syntax:</h4>
<ul>
  <li>Initial Condition: left = 0, right = length-1</li>
  <li>Termination: left > right</li>
  <li>Searching Left: right = mid-1</li>
  <li>Searching Right: left = mid+1</li>
</ul>
<h3>Template 2</h3>
<pre>
    <code>
int binarySearch(vector<int> &nums, int target)
{
    if(nums.size() == 0)
        return -1;
    int left = 0, right = nums.size();
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    // Post-processing:
    // End Condition: left == right
    if(left != nums.size() && nums[left] == target) return left;
    return -1;
}
   </code>
    </pre>
<p>Template two is an advanced form of Binary Search. It is used to search for an element or condition which requires accessing the current index and its immediate right neighbor's index in the array.</p>

<h4>Key Attributes:</h4>
<ol>
  <li>An advanced way to implement Binary Search.</li>
  <li>Search Condition needs to access element's immediate right neighbor</li>
  <li>Use element's right neighbor to determine if condition is met and decide whether to go left or right</li>
  <li>Gurantees Search Space is at least 2 in size at each step</li>
  <li>Post-processing required. Loop/Recursion ends when you have 1 element left. Need to assess if the remaining element meets the condition.</li>
</ol>

<h4>Distinguishing Syntax:</h4>
<ul>
  <li>Initial Condition: left = 0, right = length</li>
  <li>Termination: left == right</li>
  <li>Searching Left: right = mid</li>
  <li>Searching Right: left = mid+1</li>
</ul>
<h3>Template 3</h3>
<pre>
    <code>
int binarySearch(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return -1;
    int left = 0, right = nums.size() - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid;
        else
            right = mid;
    }
    // Post-processing:
    // End Condition: left + 1 == right
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}
   </code>
    </pre>
<p>Template three is another unique form of Binary Search. It is used to search for an element or condition which requires accessing the current index and its immediate left and right neighbor's index in the array.</p>

<h4>Key Attributes:</h4>
<ol>
<li>An alternative way to implement Binary Search</li>
<li>Search Condition needs to access element's immediate left and right neighbors</li>
<li>Use element's neighbors to determine if condition is met and decide whether to go left or right</li>
<li>Gurantees Search Space is at least 3 in size at each step</li>
<li>Post-processing required. Loop/Recursion ends when you have 2 elements left. Need to assess if the remaining elements meet the condition.</li>
</ol>

<h4>Distinguishing Syntax:</h4>
<ul>
  <li>Initial Condition: left = 0, right = length-1</li>
  <li>Termination: left+1 == right</li>
  <li>Searching Left: right = mid</li>
  <li>Searching Right: left = mid</li>
</ul>
<caption>Source: <a href="https://leetcode.com/explore/learn/card/binary-search" style="text-decoration:none;">Leetcode</a></caption>
