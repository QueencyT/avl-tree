
# AVL Tree

## Overview

AVL Tree is a custom, template-based self-balancing Binary Search Tree implementation developed from scratch in C++. The project supports insertion, deletion, searching, tree traversal, and dynamic memory management through recursive algorithms.

Unlike a conventional Binary Search Tree, an AVL Tree maintains a balanced structure by tracking node heights and performing rotations when subtree height differences exceed the permitted range. This prevents the tree from becoming excessively skewed and supports logarithmic-time searching and updates when its balancing invariants are maintained.

---

## Key Features

- **Self-Balancing Tree:** Implements height-based balancing through single and double rotations.
- **Recursive Tree Operations:** Supports insertion, deletion, and searching using recursive algorithms.
- **Height and Balance Tracking:** Maintains node heights and calculates balance factors to identify structural imbalances.
- **Tree Traversals:** Implements in-order, pre-order, and post-order traversals.
- **Deep Copy Support:** Provides copy construction and assignment for independent tree copies.
- **Dynamic Memory Management:** Recursively allocates and deallocates tree nodes.
- **Tree Merging:** Supports combining the contents of two trees through insertion.
- **Tree Visualization:** Displays tree structure, node heights, and balance factors for debugging.
- **GoogleTest Integration:** Includes test programs for tree operations and rotation behavior.

---

## Supported Operations

| Operation | Function | Description |
|-----------|----------|-------------|
| Insert | `insert()` | Inserts a value and applies balancing logic |
| Delete | `erase()` | Removes a value and applies rebalancing logic |
| Search | `contains()` / `search()` | Searches for an existing value |
| Clear | `clear()` / `clear_all()` | Removes all nodes |
| Check Empty | `empty()` | Determines whether the tree is empty |
| In-Order Traversal | `in_order()` | Visits left subtree, root, then right subtree |
| Pre-Order Traversal | `pre_order()` | Visits root, left subtree, then right subtree |
| Post-Order Traversal | `post_order()` | Visits left subtree, right subtree, then root |
| Deep Copy | Copy constructor / `operator=` | Creates an independent tree copy |
| Merge Trees | `operator+=` | Inserts elements from another tree |
| Sorted Input Construction | Array constructor | Constructs an AVL Tree from input values |

---

## Technical Implementation

### 1. <ins>AVL Tree Structure</ins>

The `AVL<T>` class provides a template-based interface for tree operations while managing the root node and its dynamically allocated children.

Each node is represented by a `tree_node<T>` structure containing:

- A stored value.
- Pointers to the left and right child nodes.
- A height value used to evaluate subtree balance.

The tree follows the Binary Search Tree ordering property, placing smaller values in the left subtree and larger values in the right subtree.

Unlike the separate BST implementation, the AVL insertion logic also rejects duplicate values.

### 2. <ins>Height and Balance Factor Tracking</ins>

The AVL Tree tracks the height of each node to determine whether structural adjustments are required.

A node's balance factor is calculated as:

```text
Balance Factor = Height(Left Subtree) - Height(Right Subtree)
```

A balanced AVL node must have a balance factor of:

```text
-1, 0, or +1
```

The implementation treats null children as having a height of `-1` and leaf nodes as having a height of `0`.

When an imbalance is detected, the appropriate rotation is selected to restore the tree's structure.

### 3. <ins>Tree Rotations</ins>

The implementation provides four rotation patterns for correcting imbalances.

| Rotation | Imbalance | Operation |
|----------|-----------|-----------|
| Left Rotation | Right-Right (RR) | Single left rotation |
| Right Rotation | Left-Left (LL) | Single right rotation |
| Left-Right Rotation | Left-Right (LR) | Left rotation followed by right rotation |
| Right-Left Rotation | Right-Left (RL) | Right rotation followed by left rotation |

**Single Rotations**

Single rotations correct imbalances where the heavier subtree leans in the same direction as its parent.

**Double Rotations**

Double rotations correct imbalances where the heavier subtree leans in the opposite direction.

The `rotate()` function examines balance factors to determine which rotation pattern to apply.

These rotations rearrange node relationships while preserving Binary Search Tree ordering.

### 4. <ins>Recursive Insertion and Deletion</ins>

Insertion and deletion use recursive algorithms to modify the tree.

**Insertion**

The insertion process:

1. Recursively locates the appropriate position for a new value.
2. Inserts a dynamically allocated node.
3. Updates node heights while returning through the recursive calls.
4. Evaluates balance factors and applies rotations when necessary.

**Deletion**

The deletion implementation handles removing nodes, replacing deleted values when necessary, and invoking balancing logic afterward.

The implementation includes a `tree_remove_max()` helper for retrieving a replacement value from the left subtree.

### 5. <ins>Tree Traversal Algorithms</ins>

The implementation supports three recursive traversal methods:

- **In-order:** Left → Root → Right
- **Pre-order:** Root → Left → Right
- **Post-order:** Left → Right → Root

For the following tree:

```text
        20
       /  \
     10    30
    /  \
   5   15
```

The traversal results are:

```text
In-order:    5, 10, 15, 20, 30
Pre-order:   20, 10, 5, 15, 30
Post-order:  5, 15, 10, 30, 20
```

In-order traversal retrieves values in sorted order, while pre-order and post-order traversals follow different visiting sequences.

### 6. <ins>Dynamic Memory Management</ins>

The implementation uses dynamically allocated nodes and provides the Rule of Three:

- **Copy Constructor:** Recursively creates an independent copy of an existing tree.
- **Copy Assignment Operator:** Replaces tree contents while handling self-assignment.
- **Destructor:** Recursively releases allocated memory.

The `tree_copy()` function duplicates tree nodes, while `tree_clear()` recursively deallocates nodes and resets pointers.

These operations demonstrate resource ownership, pointer management, and object lifecycle handling in C++.

---

## Core Components

| File | Responsibility |
|------|----------------|
| `avl.h` | Defines the templated AVL Tree class and its public interface |
| `tree_node.h` | Defines tree nodes, child pointers, height calculations, and balance factors |
| `avl_functions.h` | Implements rotations, insertion, deletion, searching, traversal, copying, and tree utilities |
| `basic_test.cpp` | Exercises AVL operations through GoogleTest |
| `testB.cpp` | Contains additional rotation experiments and debugging scenarios |

---

## Time Complexity

A correctly balanced AVL Tree maintains logarithmic height, enabling efficient search and update operations.

| Operation | Time Complexity |
|-----------|-----------------|
| Search | O(log n) |
| Insert | O(log n) |
| Delete | O(log n) |
| Tree Traversal | O(n) |
| Deep Copy | O(n) |
| Clear Tree | O(n) |

These bounds assume AVL balance is preserved during updates. Unlike an ordinary unbalanced Binary Search Tree, a correctly implemented AVL Tree maintains logarithmic height through rotations.

---

## Testing

The project includes C++ test programs using **GoogleTest** to exercise AVL Tree operations and balancing behavior.

The testing scenarios include:

- Tree initialization and insertion.
- Searching for existing values.
- Deletion and tree modifications.
- Single and double rotation experiments.
- In-order, pre-order, and post-order traversal.
- Copy construction and tree merging.
- Clearing the tree and verifying its empty state.
- Randomized input generation and tree operations.

The test programs combine GoogleTest assertions with console-based tree visualization and debugging output.

---

## Project Information

**Language:** C++  
**Data Structure:** AVL Tree (Self-Balancing Binary Search Tree)  
**Testing:** GoogleTest  
**Core Concepts:** Balanced search trees, tree rotations, recursion, dynamic memory management, templates, and object-oriented programming

**Developer:** Queency Tan

