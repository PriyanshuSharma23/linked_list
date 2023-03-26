// https://www.geeksforgeeks.org/reverse-a-linked-list/
// https://leetcode.com/problems/reverse-linked-list/
#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *reverse_ll(Node *head);
Node *reverse_ll_recursive(Node *head);
Node *reverse_ll_iterative(Node *head);

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    head = reverse_ll_iterative(head);

    temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    return 0;
}

// O(N) space / brute force
Node *reverse_ll(Node *head)
{

    Node *reverse_head = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        Node *new_node = new Node(temp->data);

        // Insert before head
        new_node->next = reverse_head;
        reverse_head = new_node;
        temp = temp->next;
    }

    // mutate the original linked list
    head = reverse_head;
    return head;
}

// O(N) run time and O(N) space recursive
Node *reverse_ll_recursive(Node *head)
{
    // base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *new_head = reverse_ll_recursive(head->next);
    Node *next = head->next;
    next->next = head;
    head->next = NULL;

    return new_head;
}

// O(N) run time and O(1) space iterative
Node *reverse_ll_iterative(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
