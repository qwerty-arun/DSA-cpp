# Book Allocation Problem

- N books, each 'i'th book has A[i] no. of pages.
- You have to allocate books to M number of students so that the max. no of pages allocated to a student is min.
## Conditions
- Each book should be allocated to a student
- Each student has to be allocated at least one book
- Allotment should be in contiguous order.
- Calculate and return that min possible number
- Return -1 if a valid assignment is not possible

Example: arr= [2,1,3,4], N=4, M=2

Case 1: S1 = 2, S2 = 8
Case 2: S1 = 3, S2 = 7
Case 1: S1 = 6, S2 = 4 -> This is the min of all the max no. of pages allocated to a student

- M<=N always
