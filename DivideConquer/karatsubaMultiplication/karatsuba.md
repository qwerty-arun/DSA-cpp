# Karatsuba Multiplication
- A faster algorithm to multiply large numbers which uses divide and conquer
- In general any number can be expressed as x = a * 10 ^ (n/2) + b where n is the length of the number
- example: x=146123, a = 146 and b = 123 and y=352120, c = 352 and d = 120
- Multiplying two numbers: x and y will give us ac * (10)^(n/2) + (ad+bc)*10^(n/2) + bd

## Algorithm
```python
def karatsuba(x,y)
    if x<10 or y<10
        return x*y
    else
        n = max(len(str(x)), len(str(y)))
        half = n // 2
        a = x // (10 ** half)
        b = x % (10 ** half)
        c = y // (10 ** half)
        d = y % (10 ** half)
        
        ac = karatsuba(a,c)
        bd = karatsuba(b,d)
        ad_plus_bc = karatsuba(a+b, c+d) - ac - bd

        return ac * 10 ** (2*half) + (ad_plus_bc) * 10 ** (half) + bd
```
