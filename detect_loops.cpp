// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
// https://leetcode.com/problems/linked-list-cycle/
#include <iostream>
#include <unordered_set>

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

bool has_loop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

bool has_loop_using_set(Node *head)
{
    std::unordered_set<Node *> s;
    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}

int main()
{

    // 1 -> 2 -> 3 -> 4
    //       ^         |
    //       |_________|

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;

    std::cout << has_loop(head) << std::endl;

    return 0;
}
