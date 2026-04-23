```
START

↓
Kya array sorted hai?

↓
YES ------------------------ NO
↓                           ↓
left = 0, right = n-1     Kya sort kar sakte ho?
                           ↓
                        YES → sort + continue
                        NO  → sliding window / special case

↓
Problem type identify karo:

-----------------------------------------
Pair / Sum           → Q1, Q8
Remove / Shift       → Q2, Q9
Square / Transform   → Q3
Triplet (3Sum)       → Q4, Q5, Q6
Merge                → Q7
Max/Min              → Q10
Water Trap           → Q11
3 Pointer (DNF)      → Q12
-----------------------------------------

↓
Apply logic:

PAIR SUM:
  sum < target → left++
  sum > target → right--

REMOVE / MOVE:
  slow-fast use karo

SQUARE:
  bigger abs → fill from end

3SUM:
  fix i + left/right

MERGE:
  fill from back

MAX AREA:
  smaller height move

RAIN WATER:
  leftMax vs rightMax

SORT COLORS:
  low, mid, high

↓
Loop end

↓
Return answer
```
