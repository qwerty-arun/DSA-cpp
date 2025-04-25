# What is Hash Table?
- A Hash Table is a data structure that provides a mapping from keys to values using a technique called hashing.
- Provides a mapping from keys to values. Key-Value Pair

# What is a Hash Function H(x)
- Is a function that maps a key 'x' to a whole number in a fixed range.
- Example: H(x) = x^2 - 6x +9 
- We can also define hash functions for arbitrary objects such as strings, lists, tuples, multi data objects, etc.

# Properties of Hash Functions
- If H(x) = H(y), then objects x and y might be equal, but if H(x) != H(y), then x and y are certainly not equal.
- Q) How can we use this to our advantage to speedup object comparison?
- A) Instead of comparing x and y directly a smarter approach is to first compare their hash values, and only if the hash values match do we need to explicitly compare x and y.
- Must be deterministic. This means that if H(x)=y, then H(x) must always produce y and never other value.
- Make uniform has functions to minimize the number of has collisions. H(x) = H(y)
- Keys used in hash table are immutable (fixed/constant, not like lists or sets where we can add/remove elements from)
- O(1) for all for a uniform hash function

# Hash Collision Resolution Techniques
- Separate Chaining: Deals with collisions by maintaining a data structure like LL to hold all the different values which hashed to a particular value.
- Open Addressing: Deals with collisions by finding another place within the hash table for the object to go by offsetting it from the position to which it hashed to.

# Open Addressing
- Key-value pairs are stored in the table (array) itself as opposed to a data structure like in separate chaining.
- Load factor = (items in table) / (size of table). This must be below a certain threshold. This means once alpha > threshold, table grows exponentially in size.
- When H(k) has some a collision, we try another position in the hash table by offsetting the current position subject to a probing sequence P(x).
- There are many probing sequences
- Linear Probing: P(x) = ax + b
- Quadratic Probing: P(x) = ax^2 + b*x +c
- Double Hashing: P(k, x) = x * H2(k), where H2 is a secondary hash function
- Pseudo Random Number Generator: P(k, x) = x*RNG(H(k), x)
```python
x=1;
keyhash = H(k)
indes = keyhash

while table[index]!=null:
    index = (keyhash+P(k,x)) mod N
    x = x+1
insert(k,v) at table[index]
```
- Problem: Infinite Loop due to modulo N produces a cycle shorted than the table size.
- Solution: Choosing a probing function producing cycles of exactly length 'N'

# Chaos with cycles
## Linear Probing
- Q) Which values(s) of the constant 'a' in P(x) = a*x produce a full cycle modulo N?
- A) Happens when 'a' and 'N' are relatively prime if their GCD is equal to one. Hence, when GCD(a, N)=1 the probing function P(X) will be able to generate a complete cycle ,and we will always be able to find an empty bucket.
- Therefore, P(x) = 1x is the most popular because GCD of (1, N) will always be 1.

- Empty has table, we want to insert some (k, v) pairs with Linear Probing and the table has P(x) = 5x, Fixed table size: N=12, Max Load factor alpha = 0.35. Threshold before resize = N*alpha = 4
- But when we insert 4 elements, we will have to resize the array to N = 24, then rehash every element, new threshold will be = N*alpha = 8

## Quadratic Probing
- Let P(x) = x^2, keep the table size a prime number > 3 also keep alpha <= 0.5
- Let P(x) = (x^2 + x)/2 and keep the table size a power of two
- Let P(x) = (-1^x)*x^2 and keep the table size a prime N where N = 3 mod 4

