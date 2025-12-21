
# Bitwise Operators in C++

Bitwise operators work on **bits** and perform operations bit by bit.

---

## 1. Bitwise AND (`&`)

- Compares each bit of two numbers.
- Returns 1 only if both bits are 1.

**Example:**

```
5 & 3 → 101 & 011 = 001 → 1
```

---

## 2. Bitwise OR (`|`)

- Compares each bit of two numbers.
- Returns 1 if at least one bit is 1.

**Example:**

```
5 | 3 → 101 | 011 = 111 → 7
```

---

## 3. Bitwise XOR (`^`)

- Compares each bit of two numbers.
- Returns 1 if the bits are different.

**Example:**

```
5 ^ 3 → 101 ^ 011 = 110 → 6
```

---

## 4. Bitwise NOT (`~`)

- Inverts each bit of the number.
- For signed integers, gives the 2's complement.
- Else Stops

**Example:**

```
~5 → ~(00000101) = 11111010 → -6 (in 8-bit signed)
```

---

## 5. Left Shift (`<<`)

- Shifts bits to the left by the given number of positions.
- Fills 0s from the right.

**Example:**

```
5 << 1 → 00000101 << 1 = 00001010 → 10
```

---

## 6. Right Shift (`>>`)

- Shifts bits to the right by the given number of positions.
- For positive numbers, fills 0s from the left.

**Example:**

```
5 >> 1 → 00000101 >> 1 = 00000010 → 2
```
## 7. Operator Precedence (High to Low)

1. `~` (Bitwise NOT)
2. `<<`, `>>` (Shifts)
3. `&`, `^`, `|` (AND, XOR, OR)

⚠️ **Note:** Always use parentheses `()` to ensure the intended order of operations.

---
