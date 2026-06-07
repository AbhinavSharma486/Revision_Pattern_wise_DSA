# Fast & Slow Pointer Master Flowchart

## Step 1: Identify the Pattern

```text
Does the problem involve:
- Linked List?
- Cycle Detection?
- Middle Node?
- Kth Node from End?
- Palindrome?
- Reorder List?
- Hidden Cycle in Array/Number?

NO  → Use another approach
YES → Continue
```

---

# Pattern 1: Cycle Detection

### Core Logic

```cpp
slow = head;
fast = head;

while (fast != NULL && fast->next != NULL)
{
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
        cycle found;
}
```

### Problems

- 141. Linked List Cycle

### Result

```text
slow == fast  → Cycle Exists
Loop Ends     → No Cycle
```

---

# Pattern 2: Find Cycle Start

### Step 1

Detect cycle first.

### Step 2

```cpp
slow = head;
fast = meetingPoint;

while (slow != fast)
{
    slow = slow->next;
    fast = fast->next;
}
```

### Result

```text
Meeting Node = Cycle Start
```

### Problems

- 142. Linked List Cycle II
- Remove Loop in Linked List

### Remove Loop

```text
Find cycle start

Traverse till:
node->next == cycleStart

node->next = NULL
```

---

# Pattern 3: Find Middle Node

### Core Logic

```cpp
slow = head;
fast = head;

while (fast && fast->next)
{
    slow = slow->next;
    fast = fast->next->next;
}
```

### Result

```text
slow = Middle Node
```

### Problems

- 876. Middle of the Linked List

---

# Pattern 4: Palindrome / Twin Sum

### Steps

```text
1. Find Middle
2. Reverse Second Half
3. Compare / Traverse
```

### Problems

#### 234. Palindrome Linked List

```text
Mismatch Found → false
All Match      → true
```

#### 2130. Maximum Twin Sum

```text
Twin Sum = first->val + second->val

Maintain Maximum
Return maxSum
```

---

# Pattern 5: Reorder List

### Steps

```text
1. Find Middle
2. Reverse Second Half
3. Alternate Merge
```

### Example

```text
L0 → Ln → L1 → Ln-1 → L2 → Ln-2 ...
```

### Problems

- 143. Reorder List

---

# Pattern 6: Kth Node From End

### Core Logic

```cpp
slow = head;
fast = head;

Move fast k steps ahead

while (fast != NULL)
{
    slow = slow->next;
    fast = fast->next;
}
```

### Problems

- 19. Remove Nth Node From End
- Kth From End of Linked List
- 1721. Swapping Nodes in a Linked List

### Result

```text
Remove Nth Node:
    slow reaches required previous node

Kth From End:
    slow = answer

Swap Nodes:
    kth from start + slow
    swap values
```

---

# Pattern 7: Indirect Cycle Detection

## Hidden Cycle in Array / Number

Use Floyd Cycle Detection.

---

### 287. Find Duplicate Number

```text
Treat:

index       → node
nums[index] → next node
```

```text
Cycle Start = Duplicate Number
```

---

### 202. Happy Number

```text
next(n) = sum of squares of digits
```

```cpp
slow = next(n);
fast = next(next(n));
```

```text
Reach 1      → Happy Number
Cycle ≠ 1    → Not Happy
```

---

# Not a Fast & Slow Pointer Problem

### These problems do NOT primarily use the Fast & Slow pattern:

- 725. Split Linked List in Parts
- 86. Partition List
- 61. Rotate List

### Common Techniques

```text
- Length Counting
- Multiple Pointers
- Tail Manipulation
- Separate Lists
```

---

# Fast & Slow Pointer Golden Rules

| Goal                      | Trick                     |
| ------------------------- | ------------------------- |
| Detect Cycle              | Floyd Algorithm           |
| Find Cycle Start          | Reset one pointer to head |
| Find Middle               | Slow Pointer              |
| Palindrome                | Middle + Reverse          |
| Twin Sum                  | Middle + Reverse          |
| Reorder List              | Middle + Reverse + Merge  |
| Kth From End              | Maintain k Gap            |
| Hidden Array/Number Cycle | Floyd Algorithm           |

---

## One-Line Revision

```text
Cycle        → Floyd
Cycle Start  → Reset Slow = Head
Middle       → Slow Pointer
Palindrome   → Middle + Reverse
Twin Sum     → Middle + Reverse
Reorder      → Middle + Reverse + Merge
Kth End      → k Distance Between Pointers
Duplicate    → Hidden Cycle
Happy Number → Hidden Cycle
```