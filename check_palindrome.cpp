// https://leetcode.com/problems/palindrome-linked-list/
#include <iostream>
#include <vector>

using namespace std;

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

    static Node *ll_from_vec(vector<int> &data)
    {
        Node *head = NULL;
        Node *temp = NULL;

        for (int i = 0; i < data.size(); i++)
        {
            if (head == NULL)
            {
                head = new Node(data[i]);
                temp = head;
            }
            else
            {
                temp->next = new Node(data[i]);
                temp = temp->next;
            }
        }

        return head;
    }

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

    void print_ll()
    {
        Node *temp = this;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

bool check_palindrome_brute_force(Node *head);
bool check_palindrome(Node *head);

int main()
{

    // 1 2 3 4
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(2);
    data.push_back(1);

    Node *head = Node::ll_from_vec(data);
    head->print_ll();

    cout << check_palindrome_brute_force(head) << endl;
    cout << check_palindrome(head) << endl;
}

bool check_palindrome_brute_force(Node *head)
{
    Node *temp = head;
    vector<int> data;
    while (temp != NULL)
    {
        data.push_back(temp->data);
        temp = temp->next;
    }

    int i = 0;
    int j = data.size() - 1;
    while (i < j)
    {
        if (data[i] != data[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

bool check_palindrome(Node *head)
{
    // step 1 => find the middle of the linked list
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is now at the middle of the linked list
    // step 2 => reverse the second half of the linked list
    Node *second_half = slow->next;
    slow->next = NULL;
    second_half = second_half->reverse_ll_iterative(second_half);

    // step 3 => compare the first half and the second half
    Node *first_half = head;
    while (first_half != NULL && second_half != NULL)
    {
        if (first_half->data != second_half->data)
        {
            return false;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return true;
}
