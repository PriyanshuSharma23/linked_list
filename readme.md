# Linked List
Geeks for Geeks: https://www.geeksforgeeks.org/data-structures/linked-list/

Linked List is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers as shown in the below image:

![Linked List](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)
> source: https://media.geeksforgeeks.org/

## Types of Linked List
There are two types of linked list:
1. Singly Linked List
2. Doubly Linked List

In this article, we will discuss singly linked list. First, let's compare the difference between array and linked list.

## Array vs Linked List

| Array | Linked List |
| --- | --- |
| 1. Elements are stored in contiguous memory locations. | 1. Elements are not stored in contiguous memory locations. |
| 2. Random access is allowed. | 2. Random access is not allowed. We have to access elements sequentially starting from the first node. |
| 3. Inserting a new element in an array of elements is expensive because room has to be created for the new elements and to create room existing elements have to shifted. | 3. Inserting a new element in a linked list is easier as we just need to modify the next pointer. |
| 4. Size of the array is fixed: so we must know the upper limit on the number of elements in advance. Also, generally, the allocated memory is equal to the upper limit irrespective of the usage. | 4. Size of the linked list is not fixed, so we can grow and shrink the list during the execution of the program. |

## Advantages of Linked List
1. Dynamic size
2. Faster insertion/deletion
3. Memory efficient
4. Easy to implement


## Disadvantages of Linked List
1. Slow Access
2. Pointer overhead
   - Linked lists use pointers to reference the next node, which can make them more complex to understand and use compared to arrays. This complexity can make linked lists more difficult to debug and maintain.
3. Higher Memory Usage
   - Linked lists require more memory than arrays because of the extra memory needed to store the pointers. This extra memory can be significant when the data stored in the list is small, such as a list of integers.
4. Not cache friendly
   - Linked lists are cache-inefficient because the memory is not contiguous. This means that when you traverse a linked list, you are not likely to get the data you need in the cache, leading to cache misses and slow performance.


## Implementation
For ease of understanding, we will implement a singly linked list with `int` data. The implementation will be in C++.
### Node
```cpp
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
```

Let's understand the basic operations on a linked list by referencing `linked_list.cpp`.

Now let's work upon the some important problems on linked list. We will be going through the following problems:

1. Reverse a Linked List (Iterative and Recursive) in `reverse.cpp`
2. Check if a Linked List is Palindrome in `check_palindrome.cpp`
3. Detect Loop in a Linked List in `detect_loops.cpp`
