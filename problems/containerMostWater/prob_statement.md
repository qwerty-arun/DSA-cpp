# Container with Most Water

- There is an array of heights of the container: h = [1,8,6,2,5,4,8,3,7]
- We must find a container with most water

## Brute Force
- Two Loops
- Check each loop volume and compare max volume witht current volume
- Keep updating

## Two pointer approach
- One loop is enough
- Calculate volume and compare
- Increment start or decrement end
- If current volume > max volume, update
- Use the min of the heights as they control the volume that container holds
- If lp is min, then lp++
- If rp is min, then rp--
