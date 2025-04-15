# Valid Parentheses
- Given a string 's' containing just character of brackets
- Valid if: open brackets must be closed by the same type of brackets, open brackets must be closed in correct order, every close bracket has a corresponding open bracket of same type
- Input: s = "()", Output: true
- Input: s = "{}()[]", Output: true
- Input: s = "{}(", Output: false

## Observations
- Last opening bracket should be closed first
- If a character is a closing bracket, just compare it with top of stack, if they match, then pop
- If they don't directly return false
