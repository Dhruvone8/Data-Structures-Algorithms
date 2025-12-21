
# 🔗 Linked List

## What is a Linked List?
A **Linked List** is a linear data structure where elements (called **nodes**) are **linked using pointers**. Each node stores:
1. **Data**
2. A **pointer** (or reference) to the **next node** in the list.

The data in linked lists is **not stored in contiguous memory locations**.

---

## 📦 Structure of a Node
```
class Node {
public:
    int data;
    Node* next;
};
```

---

## 📚 Types of Linked Lists
1. **Singly Linked List** - Points only to next node.
2. **Doubly Linked List** - Points to both previous and next node.
3. **Circular Linked List** - Last node points back to the first.

---

## 🔁 Why Use Linked Lists?
- **Dynamic memory allocation**
- **Efficient insertion/deletion**
- Better for **frequent resizing**

---

## ❌ Arrays vs. Linked Lists

| Feature              | Array                       | Linked List               |
|----------------------|-----------------------------|---------------------------|
| Memory Allocation    | Fixed (contiguous)          | Dynamic (non-contiguous)  |
| Insertion/Deletion   | Costly (shift needed)       | Efficient (pointer change)|
| Access (Random)      | O(1)                        | O(n) (sequential access)  |
| Memory Overhead      | Less                        | More (extra pointer)      |

---

## 🧠 Basic Linked List Operations

| Operation        | Time Complexity | Description                         |
|------------------|------------------|-------------------------------------|
| Insert at Head   | O(1)             | Add node at beginning               |
| Insert at Tail   | O(n)             | Add node at end                     |
| Delete a Node    | O(n)             | Need to find node first             |
| Search           | O(n)             | Linear traversal                    |
| Traverse         | O(n)             | Visit each node                     |

---
---

## 📌 Key Terms
- **Head**: First node.
- **Tail**: Last node (points to `nullptr`).
- **NULL / nullptr**: Indicates end of list.
- **Dynamic Memory (new/delete)**: Used to allocate/deallocate nodes.

---