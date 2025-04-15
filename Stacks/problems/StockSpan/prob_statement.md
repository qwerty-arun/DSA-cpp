# Stock Span
- price = [100,80,60,70,60,75,85]
- days =  [0  , 1, 2, 3, 4, 5, 6]
- span = max no. of consecutive days from today where price <= today's price
- For 70, the stack span will be 2
- i = 0: span = 1
- i = 1: span = 1
- i = 2: span = 1
- i = 3: span = 2
- i = 4: span = 1
- i = 5: span = 4
- i = 6: span = 6

- prevHigh: immediate greater value for any day. For 70, it is 80, for 60, its 80, for 75, its 80
- span - i-prevhigh
- We will make a stack for prevHigh, one for each element
- If prev values stack is empty, it means that the stock prices are increasing day by day, and also span = i+1 for any element
