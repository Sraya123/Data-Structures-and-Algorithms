#include <bits/stdc++.h>
using namespace std;

int calculate(char exp,int val1,int val2)
{
    switch(exp)
    {
        case '+':
        return val1+val2;

        case '-':
        return val1-val2;

        case '/':
        return val1/val2;

        case '*':
        return val1*val2;
    }
    return -1;
}
int precedence(char ch)
{
    if(ch=='+'||ch=='-')
    {
        return 1;
    }
    else if(ch=='*'||ch=='/')
    {
        return 2;
    }
    return 0;
}
int evaluate(string str)
{
    stack<char> sign;
    stack<int> value;
    for(int i=0;i<str.size();i++)
    {
        //white space
        if(str[i] == ' ')
        {
            continue;
        }
        //for digit
        else if(i<str.size() && isdigit(str[i]))
        {
            string val = "";
            while(i<str.size() && isdigit(str[i]))
            {
                val += str[i];
                i++;
            }
            i--;
            value.push(stoi(val));
        }
        //for open brace
        else if(str[i] == '(')
        {
            sign.push(str[i]);
        }
        //for close brace
        else if(str[i] == ')')
        {
            while(!sign.empty() && sign.top()!='(')
            {
                int val2 = value.top();value.pop();
                int val1 = value.top();value.pop();
                char exp = sign.top();sign.pop();
                int result = calculate(exp,val1,val2);
                value.push(result);
            }
            if(!sign.empty() && sign.top()=='(')
            {
                sign.pop();
            }
        }
        //sign
        else
        {
            
            while(!sign.empty() && precedence(str[i])<=precedence(sign.top()))
            {
                int val2 = value.top();value.pop();
                int val1 = value.top();value.pop();
                char exp = sign.top();sign.pop();
                int result = calculate(exp,val1,val2);
                value.push(result); 
            }
            if(!sign.empty() && precedence(str[i])>precedence(sign.top()))
            {
                sign.push(str[i]);
            }
            if(sign.empty())
            {
                sign.push(str[i]);
            }
            
        }
    }
    
    while(!sign.empty())
    {
        int val2 = value.top();value.pop();
        int val1 = value.top();value.pop();
        char exp = sign.top();sign.pop();
        int result = calculate(exp,val1,val2);
        value.push(result); 
    }
    return value.top();
}
int main()
{
    /*
    cout << evaluate("10 + 2 * 6") << "\n";
    cout << evaluate("100 * 2 + 12") << "\n";
    cout << evaluate("100 * ( 2 + 12 )") << "\n";
    cout << evaluate("100 * ( 2 + 12 ) / 14");
    */
    char ch = '0';
    char chh = '1';
    int val;
    val = chh - ch;
    cout << val << endl;
    float a = 2.3;
    float b = 44.3;
    double ans = b + a;
    cout << ans;
    return 0;
}