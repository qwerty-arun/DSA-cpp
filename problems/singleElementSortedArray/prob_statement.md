# Single Element in a Sorted Array (Binary Search)
- Every element appears twice except for one element
- Target: O(logn) time and O(1) space which means we can use binary search
- There is an array arr = [1,1,2,3,3,4,4,8,8]
- 2 is our answer
- Perfect Duplicates: even
- Duplicates + Single : Odd
- We can have even no. of numbers on either side of 'mid' or odd number of numbers.
- Example: [1,1,2,3,'3',4,4,8,8] and [3,3,7,7,10,11,11]
- If L and R even then, if arr[mid-1] == arr[mid] then search in left else if arr[mid]==arr[mid+1], then search in right
- If L and R odd, then if arr[mid-1]==arr[mid] then search in right else if arr[mid]==arr[mid+1], then search in left

