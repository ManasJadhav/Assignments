#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


class node
{
    friend class linkedList;
    friend class operations;
    int roll;
    node* next;

    node(int x)
    {
        roll = x;
        next = NULL;
    }
};

class linkedList
{
    friend class operations;
    node* head;
    public:
    
        linkedList()
        {
            head = NULL;
        }

        void add(int x)
        {
            node *p;
            node *temp;

            p = new node(x);

            if(head == NULL)
            {
                head = p;
            }
            else
            {
                temp = head;
                while(temp->next != NULL)
                {
                    temp = temp -> next;
                }
                temp->next = p; 
            }
        }   


        void show()
        {
            node* temp = head;
    	    while(temp->next != NULL)
            {
                printf("%d\t", temp->roll);
                temp = temp->next;
            }
            printf("%d",temp->roll);
            printf("\n");
        };  

        
};

class operations
{
    public:
        int is_member(linkedList l1, int member)
        {
            node* temp = l1.head;
            while(temp->next != NULL)
            {
                if(temp->roll == member)
                {
                    return 1;
                }
                temp = temp->next;
            }
            if(temp->roll == member)
            {
                return 1;
            }

            return 0;
        }

        void Intersection(linkedList l1, linkedList l2)
        {
            node* temp1 = l1.head; 
            node* temp2 = l2.head; 

            linkedList intersection;

            while(temp2->next != NULL)
            {
                if(is_member(l1, temp2->roll))
                {
                    intersection.add(temp2->roll);
                }
                temp2 = temp2->next;
            }
            if(is_member(l1, temp2->roll))
            {
                intersection.add(temp2->roll);
            }
            intersection.show();
        }

        void Not_Both(linkedList l1, linkedList l2)
        {
            node* temp1 = l1.head;
            node* temp2 = l2.head;

            linkedList notBoth;

            while(temp1->next != NULL)
            {
                if(!(is_member(l2,temp1->roll)))
                    notBoth.add(temp1->roll);
                temp1 = temp1->next;
            }
            if(!(is_member(l2,temp1->roll)))
                notBoth.add(temp1->roll);

            temp1 = l1.head;

            while(temp2->next != NULL)
            {
                if(!(is_member(l1,temp2->roll)))
                    notBoth.add(temp2->roll);
                temp2 = temp2->next;
            }
            if(!(is_member(l1,temp2->roll)))
                notBoth.add(temp2->roll);

            notBoth.show();
        }

        void Neither(linkedList l1, linkedList l2, linkedList l3)
        {
            node* temp1 = l1.head;
            node* temp2 = l2.head;
            node* temp3 = l3.head;

            linkedList neither;
            while(temp3->next != NULL)
            {
                if(!(is_member(l1,temp3->roll)) && !(is_member(l2,temp3->roll)))
                    neither.add(temp3->roll);
                temp3 = temp3->next;
            }
            if(!(is_member(l1,temp3->roll)) && !(is_member(l2,temp3->roll)))
                neither.add(temp3->roll);

            neither.show();
        }

};

int main()
{
    int students,choice,roll,count = 0;
    int icecream;

    linkedList Student;
    linkedList vanilla;
    linkedList butterscotch;
    operations O;

    cout<<"Enter the number of students: ";
    cin>>students;

    cout<<"Enter\n'1' for vanilla\n'2' for butterscotch\n'3' for both\n'4' for neither\n";

    for(int i = 0; i<students; i++)
    {
        cout<<"Enter the roll number of student "<<i+1<<" : ";
        cin>>roll;
        Student.add(roll);
        label:
        cout<<"Enter the ice cream Roll number "<<roll<<" likes : ";
        cin>>icecream;

        if(icecream == 1)
            vanilla.add(roll);
        else if(icecream == 2)
            butterscotch.add(roll);
        else if (icecream == 3)
        {
            vanilla.add(roll);
            butterscotch.add(roll);
        }
        else if (icecream == 4)
            count++;
        else
        {
            cout<<"Enter correct choice: ";
            goto label;
        }
    }

    cout<<"********************************************\n";
    cout<<"Vanilla      = ";
    vanilla.show();
    cout<<"Butterscotch = ";
    butterscotch.show();
    cout<<"********************************************\n";

    do
    {
        cout<<"---------------MENU----------------\n";
        cout<<"1.Student who like both Vanilla and Butterscotch\n2.Student who like either Vanilla and Butterscotch but not both\n";
        cout<<"3.Number of student who like neither Vanilla nor Butterscotch\n4.EXIT";
        cout<<"\n-----------------------------------\n";
        
        cout<<"Enter you choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            O.Intersection(vanilla, butterscotch);
            break;

        case 2:
            O.Not_Both(vanilla, butterscotch);
            break;

        case 3:
            cout<<"Number of Students: "<<count<<"\n";
            O.Neither(vanilla, butterscotch,Student);
            break;

        case 4:
            cout<<"\n Thank You...\n";
            exit(0);
            break;

        default:
            cout<<"\nEnter correct choice between 1-4\n";
            break;
        }
        
    } while (choice != 4);
};
