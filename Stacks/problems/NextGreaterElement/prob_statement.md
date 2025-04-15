# Next Greater Element
- For a given array, find out the next greater element for each element in the array
- For arr[i], which element is immediately greater towards the right?
- For example: arr = [6,8,0,1,3] -> [8, -1, 1, 3, -1]
- -1 indicates that there is no greater element

# LeetCode 496. Next greater element
- You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is the subset of nums2
- For each 0<=i<=nums1.length, find that index j that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
- If there is no greater element, then the answer is -1
- Return an array ans of length nums1.len such that ans[i] is the nest greater element as described above

- Example: nums1 = [4,1,2] and nums2 = [1,3,4,2]
- Output: [-1,3,-1]

# Leetcode 503. Next Greater Element II
- Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

- The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number.
- If it doesn't exist, return -1 for this number.
```
Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
```
