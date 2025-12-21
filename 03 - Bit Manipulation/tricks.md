# Tricks in Bit Manipulation 

---
### 1. Swap 2 numbers without using third variable

```cpp
int a = 1;
int b = 2;

a = a ^ b;
b = a ^ b;
a = a ^ b;
```
---

---
### 2. Check if ith bit is set or unset

```cpp
if ((a >> i) & 1 == 0)
{
    cout << "unset" << endl;
}
else
{
    cout << "set" << endl;
}
```
---

---
### 3. Set the ith bit in the binary number

```cpp
a | (1 << i)
```
---

---
### 4. Clear the ith bit in the binary number

```cpp
a & ~(1 << i)
```
---

---
### 5. Toggle the ith bit in the binary number

```cpp
a ^ (1 << i)
```
---

---
### 6. Clear the rightmost set bit in the binary number

```cpp
int n = 40;

n & n - 1
```
---

### 7. Check if a number is power of 2 or not

```cpp
if((n & n- 1) == 0)
{
    return true;
}
else
{
    return false;
}
```
---
