# Celebrity Problem
- Given a 2D array (nxn), such that arr[i][j] = 1 means ith person knows jth person, the task is to find the celebrity
- A celebrity is a person who is known to all but doesn't know anyone
- Return the index of celebrity, if there is no celebrity, return -1;
- arr = [[0,1,0], [0,0,0], [0,1,0]]

## Logic
- arr[i][celeb] = 1 for all i
- arr[celeb][i] = 0 for all i
