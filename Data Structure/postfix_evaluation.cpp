#include<bits/stdc++.h>
using namespace std;
bool operatorr(char ch);
bool operand(char ch);
int operation(char ch, int op1, int op2);
int evaluate(string exp);

int main()
{
    string exp;
    getline(cin,exp);
    int result = evaluate(exp);
    cout<<"The result of the equation is: "<<result<<endl;

    return 0;
}

int evaluate(string exp)
{
    stack<int>s;
    for(int i=0; exp[i]!= NULL; i++)
    {
        if(exp[i]==' ' || exp[i]==',')
            continue;
        else if(operand(exp[i]))
        {
            int op=0;
            while(exp[i] != NULL &&  operand(exp[i]))
            {
                op=(op*10) + (exp[i]-'0');
                i++;
            }
            i--;
            s.push(op);
        }
        else if(operatorr(exp[i]))
        {
            int op2= s.top();
            s.pop();
            int op1 = s.top();
            s.pop();

            int result = operation(exp[i], op1, op2);
            s.push(result);
        }
    }
    return s.top();
}

bool operatorr(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return true;
    }
    return false;
}

bool operand(char ch)
{
    if(ch>'0'&& ch<='9')
    {
        return true;
    }
    return false;
}

int operation(char ch, int op1, int op2)
{
    if(ch == '+')
    {
        return (op1+op2);
    }
    else if(ch == '-')
    {
        return (op1-op2);
    }
    else if(ch == '*')
    {
        return (op1*op2);
    }
    else if(ch == '/')
    {
        return (op1/op2);
    }
}
