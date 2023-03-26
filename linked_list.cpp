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

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        this->head = NULL;
    }

    // insert at last
    void insert(int data)
    {
        Node *new_node = new Node(data);
        if (this->head == NULL)
        {
            this->head = new_node;
        }
        else
        {
            Node *temp = this->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    // insert with index
    void insert(int index, int data)
    {
        Node *new_node = new Node(data);
        if (index == 0)
        {
            new_node->next = this->head;
            this->head = new_node;
        }
        else
        {
            Node *temp = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;

                if (temp == NULL)
                {
                    std::cout << "Index out of range" << std::endl;
                    return;
                }
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    // search with value
    Node *search(int data)
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // search with index
    Node *get(int index)
    {
        Node *temp = this->head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                std::cout << "Index out of range" << std::endl;
                return NULL;
            }
        }
        return temp;
    }

    // delete with value
    int delete_node_with_value(int data)
    {
        Node *temp = this->head;
        if (temp->data == data)
        {
            this->head = temp->next;
            delete temp;
            return data;
        }
        while (temp->next != NULL)
        {
            if (temp->next->data == data)
            {
                Node *temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                return data;
            }
            temp = temp->next;
        }
        return -1;
    }

    // delete with index
    int delete_node_with_index(int index)
    {
        Node *temp = this->head;
        if (index == 0)
        {
            this->head = temp->next;
            delete temp;
            return index;
        }
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                std::cout << "Index out of range" << std::endl;
                return -1;
            }
        }
        Node *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        return index;
    }

    // print
    void print()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main()
{

    LinkedList *list = new LinkedList();
    list->insert(1);
    list->insert(2);
    list->insert(3);
    list->insert(4);

    list->print();

    list->insert(0, 0);
    list->insert(5, 5);

    list->print();

    std::cout << list->search(3)->data << std::endl;
    std::cout << list->get(3)->data << std::endl;

    list->delete_node_with_value(0);
    list->delete_node_with_value(5);

    list->print();

    list->delete_node_with_index(0);
    list->delete_node_with_index(2);

    list->print();

    return 0;
}
