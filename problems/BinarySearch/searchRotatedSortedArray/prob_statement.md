# Search in Rotated Sorted Array (LT 33)

- We have an array which is sorted and then rotated like: [3,4,5,6,7,0,1,2]
- Constraint: O(logn)
- whenever we have Sorted array, we should definitely think of using the binary search algorithm
- We can observe that either L or R part will be sorted, in this case it is Left part
- Then apply BS on which is sorted
- For left sorted array if, A[st] <= tar <=A[mid] satisfies, then target is here, if not then it is in right array
- For right sorted array if, A[mid]<=tar <=A[end] satisfies, then target is in right array, else search in left
