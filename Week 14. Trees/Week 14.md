# C Language Designing & Experiment (I)

## Week 14

## Trees

### Ancestors

From root to one node(n), all the nodes that it requires to pass through, including the root itself, are called ancestors.



### Leaf(Terminal node)

If a node has no child, we call it leaf of tree(terminal node).



### Level

After one branch, level++, the __depth(or height)__ is determined by tree's level.



### Ordered Trees & Unordered Trees

If the nodes are ordered with some specific rules, then it's called ordered tree. In the opposite, it's called Unordered tree.



### Binary Trees

One parent will only has at most 2 children(0, 1, 2). E.g. double linked list's structure.

```c
struct node{
    int data;
    struct node *left;
    struct node *right;
};
```

Traversal(Printing, searching):

Pre-order: Root->left->Right

In-order: Left->Root->Right

Post-order: Left->Right->Root

We could not make a unique binary tree without pre-order. The worst case of searching is n(depth), so the time complexity will be between n(1)~n(depth). So when we're always trying to make a __balance binary tree__ to decrease tree's depth as many as possible.