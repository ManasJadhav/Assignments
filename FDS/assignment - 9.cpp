#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

class node 
{
    private:
        friend class linkedList;
        node *next;
        char data;

    public:
        node(char x)
        {
            next = NULL;
            data = x;
        }
};

class linkedList
{
    friend class Stack;
    node* head;
    public:
        linkedList()
        {
            head = NULL;
        }

        void push(char x)
        {
            node *temp = head;
            node *p = new node(x);
            if(head == NULL)
            {
                head = p;
            }
            else
            {        
                head = p;
                p->next = temp;
            }
        };

        void pop()
        {
            node *temp = head;

            head = temp->next;
            delete temp;
        }

        void display()
        {
            node *temp = head;
            while(temp->next != NULL)
            {   
                printf("%c\t",temp->data);
                temp = temp->next;
            }
            printf("%c\n",temp->data);
        }

        char peek()
        {
            node *temp = head;
            return temp->data;
        }
};


class Stack
{
    public:
        char bracket;
        linkedList stack;
        int count = 0;
        void checkWellness(string x)
        {
            int i = 0;
            while(x[i] != '\0')
            {
                if(x[i] == '{' || x[i] == '(' || x[i] == '[')
                {
                    stack.push(x[i]);
                    count++;
                }
                else if(x[i] == '}' || x[i] == ')' || x[i] == ']')
                {
                    char element = stack.peek();
                    switch (element)
                    {
                    case '{':
                        bracket = '}';
                        break;

                    case '(':
                        bracket = ')';
                        break;
                    
                    case '[':
                        bracket = ']';
                        break;
                    default:
                        break;
                    }
                    if(bracket == x[i])
                    {
                        stack.pop();
                        count--;
                    }
                    else
                    {
                        cout<<"-----------------------------------\n";
                        printf("%s\n","Equation is not well formed");
                        cout<<"-----------------------------------\n";
                        return;
                    }
                }
                i++;
            }
            if(count)
            {
                cout<<"-----------------------------------\n";
                cout<<"Equation is not well formed\n";
                cout<<"-----------------------------------\n";
            }
            else
            {
                cout<<"-----------------------------------\n";   
                cout<<"Equation is well formed\n";
                cout<<"-----------------------------------\n";
            }
        }
};

int main()
{
    int ch;
    string Equation;
    Stack S;
    
    while(1)
    {
        cout<<"1. check well-formness of equation\n0. EXIT\n";
        cout<<"Enter option: ";
        cin>>ch;
        if(!ch)
        {
            cout<<"Thank you...";
            break;
        }
        cout<<"Enter the Equation : ";
        cin>>Equation;
        S.checkWellness(Equation);
    };
}