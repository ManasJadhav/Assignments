#include<iostream>
#include<string.h>
using namespace std;


class Node
{
    friend class Cinemax;
    private:
        char data;
        Node* next;
        Node* prev;
};

class Cinemax
{
    private: 
        Node* head;
    public:
        Cinemax()
        {
            head = NULL;
        }
        void InsertNode(int);
        void Display();
        void Booking(int,int,char);
        void cancel_Booking(int,int,char);
};

void Cinemax::InsertNode(int data)
{
    if(head == NULL)
    {
        Node* newnode = new Node;
        newnode-> data = data;
        newnode-> prev = newnode;
        newnode-> next = newnode;
        head = newnode;
        return;
    }

    Node* last = head->prev;
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = head;
    newnode->prev = last;
    head->prev = newnode;
    last->next = newnode;
    
};

void Cinemax::Display()
{
    Node* temp = head;

    while(temp->next != head) 
    {
        cout<<temp->data<<"    ";
        temp = temp-> next;   
    }
    cout<<temp->data<<endl;  
};



void Cinemax::Booking(int first, int last, char chr)
{
    Node* temp = head;
    if(first<=0 || last>7)
    {
        cout<<"Invalid seat number"<<endl;
        return;
    }
    for(int i = 1; i<first; i++)
    {
        temp = temp-> next;
    }
    Node* current = temp;
    for(int i = first; i<=last; i++)
    {
        current-> data = chr;
        current = current->next;   
    }
    cout<<"Seat has been booked Successfully!"<<endl;
};



void Cinemax::cancel_Booking(int first, int last, char chr)
{
    Node* temp = head;
    if(first<=0 || last>7)
    {
        cout<<"Invalid seat number"<<endl;
        return;
    }
    for(int i = 1; i<first; i++)
    {
        temp = temp-> next;
    }
    Node* current = temp;
    for(int i = first; i<=last; i++)
    {
        current->data = chr;
        current = current->next;   
    }
    cout<<"Booking has been cancelled Successfully!"<<endl;
}



int main()
{
    int n, choice;
    char l;
    string str;

    Cinemax *arr_obj;
    arr_obj = new Cinemax[10];
    
    for(int j = 0; j<10; j++)
    {
        for(int i = 0; i<7; i++)
        {
            l = '-';
            arr_obj[j].InsertNode(l);
        }
    }

    
    while(true) 
    {
        cout<<"MAIN MENU \n1.To display available seats \n2.To book seats \n3.To cancel booking of seats \n4.EXIT"<<endl;
        cout<<"---------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice== 4)
        {
            cout<<"THANK YOU FOR USING US"<<endl;
            break;
        }

        switch(choice)
        {
            case 1:
                cout<<"X : Booked seats \n- : Available seats"<<endl;
                cout<<"-----------------------------------"<<endl;
                
                cout<<"    1    2    3    4    5    6    7"<<endl;
                int j;
                j = 1;
                for(int i=0; i<10;i++)
                {
                    cout<<char(65 + i)<<":  ";
                    arr_obj[i].Display();
                    cout<<endl;
                    ++j;
                }
                cout<<"-----------------------------------"<<endl;
                cout<<"          SCREEN THIS WAY          "<<endl;
                cout<<"-----------------------------------"<<endl;
                break;
            
            case 2:
                cout<<"Enter seat numbers to be booked (eg. C2-C5). : ";
                cin>>str;
                if(str[0] > char(65+10))
                {
                    cout<<"Enter correct seat number !!"<<endl;
                }
                else
                {
                    if(str.length()>2)
                    {
                        int j;
                        for(j=0; j<10; j++)
                        {
                            if(char(65+j) == str[0])
                            {
                                break;
                            }
                        }
                        arr_obj[j].Booking(str[1]-48, str[4]-48,'X');
                    }
                    else
                    {
                        int j;
                        for(j=0; j<10; j++)
                        {
                            if(char(65+j) == str[0])
                            {
                                break;
                            }
                        }
                        arr_obj[j].Booking(str[1]-48, str[1]-48,'X');   
                                                   
                    }
                }
                cout<<"---------------------------------------------------------------------------------------------------"<<endl;
                break;

            case 3:
                cout<<"Enter seat numbers to cancel booking (eg. C2 - C5). : ";
                cin>>str;
                if(str.length() > 2)
                {
                    int j;
                    for(j = 0; j<10; j++)
                    {
                        if(char(65+j) == str[0])
                        {
                            break;
                        }
                    }
                    arr_obj[j].cancel_Booking(str[1]-48,str[4]-48,'-');
                }
                else
                {
                    int j;
                    for(j = 0; j<10; j++)
                    {
                        if (char(65+j) == str[0])
                        {
                            break;	
                        }
                    }
                    arr_obj[j].cancel_Booking(str[1]-48,str[1]-48,'-');
                }
                cout<<"---------------------------------------------------------------------------------------------------"<<endl;
                break;
        }      
    }
    delete [] arr_obj;
}