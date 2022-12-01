#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
template <class T>
class StackUsingArray
{
private:
    T data[MAX];
    int top;

public:
    StackUsingArray()
    {
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (top == MAX - 1)
        {
            return true;
        }
        return false;
    }
    void push(T element)
    {
        if (isFull())
        {
            cout << "Stack is Full !" << endl;
            return;
        }
        data[++top] = element;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !" << endl;
            return;
        }
        int i = top;
        while (i >= 0)
        {
            cout << data[i] << " ";
            i--;
        }
        cout << endl;
    }
    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        else
        {
            int i = top;
            top--;
            return data[i];
        }
    }
    T Top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return data[top];
    }
};

bool wellParenthesized(char infix[])
{
    StackUsingArray<char> st;
    int len = strlen(infix);
    char ch;
    for (int i = 0; i < len; i++)
    {
        if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
        {
            st.push(infix[i]);
            continue;
        }
        if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']')
        {
            if (st.isEmpty())
            {
                return false;
            }
            else
            {
                switch (infix[i])
                {
                case ')':
                    ch = st.Top();
                    if (ch == '{' || ch == '[')
                    {
                        return false;
                    }
                    st.pop();
                    
                    break;
                case '}':
                    ch = st.Top();
                    if (ch == '(' || ch == '[')
                    {
                        return false;
                    }
                    st.pop();
                    
                    break;
                case ']':
                    ch = st.Top();
                    if (ch == '(' || ch == '{')
                    {
                        return false;
                    }
                    st.pop();
                    
                    break;
                default:
                    break;
                }
            }
        }
    }
    if (st.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
void infix_to_postfix(char infix[], char postfix[], int size)
{
    StackUsingArray<char> s;
    int weight;
    int i = 0;
    int k = 0;
    char ch;
    while (i < size)
    {
        ch = infix[i];
        if (ch == '(')
        {
            s.push(ch);
            i++;
            continue;
        }
        if (ch == ')')
        {
            while (!s.isEmpty() && s.Top() != '(')
            {
                postfix[k++] = s.Top();
                s.pop();
            }
            if (!s.isEmpty())
            {
                s.pop();
            }
            i++;
            continue;
        }
        weight = precedence(ch);
        if (weight == 0)
        {
            postfix[k++] = ch;
        }
        else
        {
            if (s.isEmpty())
            {
                s.push(ch);
            }
            else
            {
                while (!s.isEmpty() && s.Top() != '(' && weight <= precedence(s.Top()))
                {
                    postfix[k++] = s.Top();
                    s.pop();
                }
                s.push(ch);
            }
        }
        i++;
    }
    while (!s.isEmpty())
    {
        postfix[k++] = s.Top();
        s.pop();
    }
    postfix[k] = '\0';
}
int evaluate(int op1, int op2, char operate)
{
    int ans;
    switch (operate)
    {
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    }
    return ans;
}
int evaluate_Postfix(char postfix[], int size)
{
    StackUsingArray<int> ep;
    int i = 0;
    char c;
    int val;
    while (i < size)
    {
        c = postfix[i];
        if (isdigit(c))
        {
            ep.push(c - '0');
        }
        else
        {
            int op1 = ep.Top();
            ep.pop();
            int op2 = ep.Top();
            ep.pop();
            val = evaluate(op1, op2, c);
            ep.push(val);
        }
        i++;
    }
    return val;
}
int main()
{
    char infix[100];
    cout << "Enter an infix expression : " << endl;
    cin >> infix;
    int size = strlen(infix);
    char postfix[size];
    if (wellParenthesized(infix))
    {
        infix_to_postfix(infix, postfix, size);
        cout << "Infix expression is : " << infix << endl;
        cout << "Postfix expression is : " << postfix << endl;
        int final_ans = evaluate_Postfix(postfix, strlen(postfix));
        cout << "Evaluation of Postfix expression : " << final_ans << endl;
    }
    else
    {
        cout << "Infix expression is not well parenthesized ." << endl;
    }
}