START
  ↓
Kya problem me "subarray / substring / contiguous" likha hai?
  ↓
NO → Sliding Window nahi (dusra approach use karo)
  ↓
YES
  ↓
Kya window size fixed hai? (k given hai?)
  ↓
        ┌─────────────── YES ───────────────┐
        ↓                                   ↓
  FIXED WINDOW                      VARIABLE WINDOW

-----------------------------       --------------------------------
FIXED WINDOW FLOW:                VARIABLE WINDOW FLOW:
-----------------------------       --------------------------------
i = 0, j = 0                       i = 0, j = 0
sum / data maintain                map / set / sum maintain

while (j < n):                     while (j < n):
  add arr[j]                         add arr[j] / update map

  if (window < k):                  check condition:
    j++                              

  else if (window == k):           ┌─────────────── VALID ───────────────┐
    update answer                  ↓                                      ↓
    remove arr[i]              answer update                        expand (j++)
    i++, j++                  (max / min / count)

                                  ┌────────────── INVALID ──────────────┐
                                  ↓                                     ↓
                             shrink window (i++)
                             remove arr[i]
                             repeat until valid

-----------------------------       --------------------------------

↓
Goal identify karo:

1. LONGEST (maximize length)
   → valid hone par update
   → invalid → shrink

2. SMALLEST (minimize length)
   → valid hone par update
   → shrink aggressively

3. COUNT subarrays
   → count += (j - i + 1)

4. EXACTLY K
   → atMost(k) - atMost(k-1)

5. DISTINCT / MAP based
   → frequency map use karo

↓
Loop end

↓
Return answer




IF k fixed → fixed window

ELSE:
  expand (j++)
  invalid → shrink (i++)
  valid → update answer

Longest → max
Smallest → shrink more
Count → + (j - i + 1)
Exactly K → atMost(k) - atMost(k-1)