// Linked_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;


//here we are defining our own data type.But the memory hasn't been allocated yet.
class LinkedList 
{

    struct Node
    {
        int data;
        Node* next;

        Node(int d) 
        { //CONSTRUCTOR.
            data = d;
            next = NULL;
        }
    };
    Node* head,*tail; //using tail to solve it in O(1) rather than O(n)
public:
    LinkedList() 
    {
        head = NULL;
        tail = NULL;
    }

    void insertBegining(int data) 
    {
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node* newNode = new Node(data); //creating a new node where we will store data..
        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else

        {
            //this will solve in O(1)..
            tail->next = newNode;
            tail = tail->next;

            /* //this will insert in O(n)
              Node* current = head;
            while (current->next != NULL) //ham check kr rhe hai k kya current(mean the jaha present hm hai) node ka next NULL hai agr nahi,to use shift kardo to the next node.
            {
                current = current->next;
            }
            current->next = newNode; //when condition false from while loops , means we're ate the last node.
            */
        }
    }

    void insertAtKNode(int k, int data)
    {
        if (k < 0)
        {
            cout << "INVALID VALUE" << endl;
            return;
        }

        if (isEmpty())
        {
            cout << "List is Empty" << endl;
            return;
        }

        //creating the newNode
        Node* newNode = new Node(data);

        if (k == 0) //inserting in the beginning.
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        else
        {
            Node* current = head;
            while (current != NULL && --k)
            {
                current = current->next;
            }
            if (k == 0)
            {
                newNode->next = current->next;
                current->next = newNode;
            }
            else
            {
                cout << "Position doesn't exist" << endl;
                return; 
            }
        }


    }

    void deleteNode(int dataToDel) {
        Node* current = head;

        if (isEmpty()) {
            cout << "List is Empty...";
            return;
        }
        else if (head->data == dataToDel) {
            head = head->next;
            free(current);
            return;
        }
        else 
        {
            while (current->next != NULL && current->next->data != dataToDel) 
            {
                current = current->next;
            }
            if (current->next == NULL) 
            {
                cout << "Data doesn't exist." << endl;
                return;
            }
            else
            {
                Node* NodeToDel = current->next;
                current->next = current->next->next;
                free(NodeToDel);
            }
        }
    }


    //REVERSING A LINKED LIST


    void print()
    {
        if (isEmpty())
        {
            cout << "List is empty";
            return;
        }
        else
        {
            Node* current = head;
            while (current!= NULL) //check for condition.
            {
                cout << current->data << " -> "; //printing data..
                current = current->next;  //updating current.
            }
            cout <<"NULL" << endl;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

};


int main()
{
    LinkedList ll =  LinkedList();
    ll.insertAtEnd(23);
    ll.insertAtEnd(24);
    ll.insertAtEnd(11);
    ll.insertBegining(10);
    ll.insertBegining(100);
    ll.print();
    ll.deleteNode(100);
    ll.print();
    ll.insertAtKNode(0, 0);
    ll.print();
    ll.insertAtKNode(3, 3);
    ll.print();
    ll.insertAtKNode(6, 8);
    ll.print();


    return 0;
}

