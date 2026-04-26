```id="k8mz4p"
START
  ↓
Kya problem me linked list / array traversal / cycle detection ka hint hai?
  ↓
NO → Fast & Slow pointer mat use karo (dusra approach dekh lo)
  ↓
YES
  ↓
Goal identify karo:
  ↓
   ┌───────────────┬──────────────────────┬──────────────────────┐
   ↓               ↓                      ↓
Cycle detect?   Middle find?         Modify / Compare?

================= MAIN FLOW =================

Initialize pointers:
slow = head
fast = head

  ↓
Loop chalao:
while (fast != NULL && fast->next != NULL)
  ↓
slow = slow->next        (1 step)
fast = fast->next->next  (2 step)

  ↓
Condition check karo:

--------------------------------------------
CASE 1: Cycle Detection?
--------------------------------------------
Agar slow == fast:
   → Cycle present
   → Break loop

Loop khatam ho gaya aur meet nahi hua:
   → No cycle

--------------------------------------------
CASE 2: Middle Element?
--------------------------------------------
Loop khatam:
   → slow hi middle pe hai

--------------------------------------------
CASE 3: Cycle ka starting point?
--------------------------------------------
Step 1: Detect cycle (upar wala)
Step 2:
   slow = head
   fast = meeting point

Dono ko 1 step se chalao:
while (slow != fast)
   slow = slow->next
   fast = fast->next

→ Jaha milenge = cycle start

--------------------------------------------
CASE 4: Palindrome Linked List?
--------------------------------------------
Step 1: Middle find karo (slow)
Step 2: Second half reverse karo
Step 3: First & second half compare karo

--------------------------------------------
CASE 5: Remove / Modify?
--------------------------------------------
Fast ko k steps aage le jao
Phir slow aur fast ko saath chalao

→ Jab fast end pe ho:
   slow required position pe hoga

================= END =================

Return result
  ↓
END
```
