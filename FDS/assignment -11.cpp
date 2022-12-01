#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class qNode
{   
    string data;
    qNode* next;

    qNode(string id)
    {
        data = id;
        next = NULL;
    }

    friend class Queue;
};


class Queue
{
    int Size = 0;
    qNode* front = NULL;
    qNode* rear = NULL;

    public:
        int isEmpty()
        {
            if(front == NULL)
                return 1;
            return 0;
        }

        int isFull()
        {
            if(Size > 10)
                return 1;
            return 0;
        }

        void InsertJob(string Id)
        {
            if(isFull())
            {
                cout<<"Queue is Full !!\n";
                return;
            }
            Size += 1;

            if(rear == NULL)
            {
                qNode* newJob = new qNode(Id);
                front = newJob;
                rear = newJob;
                cout<<"\nThe Job has been added Successfully\n";
                return;
            }
            qNode *newJob = new qNode(Id);
            rear -> next = newJob;
            rear = newJob;
            cout<<"\nThe Job has been added Successfully\n";
        }

        void Display()
        {
            qNode* temp = front;
            while(temp != NULL)
            {
                cout<<temp->data <<"\n";
                temp = temp->next;
            }
            delete temp;
        }

        void Delete()
        {
            if(isEmpty())
            {
                cout<<"Queue is Empty !!\n";
                return;
            }
            Size -= 1;

            qNode* temp = front;
            front = front->next;
            if(front == NULL)
            {
                rear == NULL;
            } 
            cout<<"\nJob has been deleted Successfully\n";
            delete temp;
        }
};

int main()
{
    string Job;
    Queue j;
    int ch;

    while(1)
    {
        cout<<"\n\nMain-Menu\n\n";
        cout<<"1.To add a new job in Queue\n2.To delete a job from Queue\n3.To display Queue of Jobs\n4.Exit\n";

        cout<<"\nEnter your Choice : ";
        cin>>ch;

        if(ch == 4)
            break;

        switch(ch)
        {
            case 1:
                cout<<"Enter the Job you want to add : ";
                cin>>Job;
                j.InsertJob(Job);
                break;
            
            case 2:
                j.Delete();
                break;

            case 3:
                cout<<"Queue of jobs:\n";
                j.Display();
                break;

            default:
                cout<<"\nEnter correct choice\n";
        }
    }
}

