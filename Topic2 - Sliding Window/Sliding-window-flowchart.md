Sliding Window

low → left
high → right

-----------------------------------
high++  → Expand window
low++   → Shrink window
-----------------------------------

Flow Chart:

Array / String
      ↓
Subarray / Substring (continuous hona chahiye)
      ↓
Linked List ❌
Subsequence ❌
Non-contiguous ❌

      ↓
Check kya find karna hai:
-----------------------------------
Maximum
Minimum
Longest
Shortest
Sum / Count / Average
At most K / At least K / Exactly K
-----------------------------------

      ↓
Sliding Window Type:
-----------------------------------
1. Fixed Size (k given)
2. Variable Size (condition based)
-----------------------------------

      ↓
Initialize:
left = 0
right = 0

      ↓
while(right < n):

    window me include:
    → arr[right]

    ↓
    Condition check karo:

    VALID:
        → answer update

        Fixed:
            → size == k
            → remove arr[left]
            → left++
            → right++

        Variable:
            → expand (right++)

    INVALID:
        → shrink
        → remove arr[left]
        → left++

-----------------------------------

End → answer return