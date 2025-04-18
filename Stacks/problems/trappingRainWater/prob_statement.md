# Trapping Rain Water (Leetcode 42)
- Given 'n' non-negative integers representing an elevation map where width of each bar is 1, compute how much water it can trap after raining.
```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```

## Naive Approach
- For each index, calculate largest left and right boundary. Find out the minimum out of them.
- For example: height = [4,2,0,3,2,5]
- In general for ith index, the water that can be stored will be min(lmax, rmax)-height[i]
- For '3', lmax = 4 and rmax = 5, then water = min(4,5) - 3 = 1

## Better Approach
- For lmax and rmax, just use one loop and use seperate arrays for them
- lmax: [4,4,4,4,4,5] and rmax: [5,5,5,5,5]
