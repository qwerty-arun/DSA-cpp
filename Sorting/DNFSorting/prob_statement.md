# DNF Sorting Algorithm
- Sort an array of 0s, 1s and 2s
- Example: [2,0,2,1,1,0,1,2,0,0] -> [0,0,0,0,1,1,1,2,2,2]

## Brute Force
- sort(v.begin(),v.end()) -> O(logn*n)

## Optimized 
- Count the no. of 0s, 1s and 2s.
- Overwrite the elements

## Optimal -> Dutch National Flag Algorithm -> O(n)
- 3 pointers: low, mid, high
-   0   0   0   0       1   1   1       2   2   2
-   0           l-1     l       m-1     h+1     n-1
- Between the m and h is where the unsorted elements lie, (shrinks and we are left with sorted elements)

