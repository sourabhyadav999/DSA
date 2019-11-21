#include<iostream>

using namespace std;
const int size=50;
char infix[size],postfix[size];
char stack[size];
int top=-1;
int precedence(char ch)
{
    switch(ch)
    {
        case '^':return 5;break;
        case '/':return 4;break;
        case '*':return 3;break;
        case '+':return 2;break;
        case '-':return 1;break;
        default : return 0;

    }
}
char pop()
{
    char ret;
    if(top!=-1)
    {
        ret=stack[top];
        top--;

    }
    else{
        ret='#';
    }
    return ret;
}
char topelement()
{
    char ch;
    if(top!=-1){
        ch=stack[top];

    }
    else{
        ch='#';
    }
    return ch;


}
void push(char ch)
{
    if(top!=size-1)
    {
        top++;
        stack[top]=ch;
    }
}
int braces(char *s)
{
    int leftbr=0,rightbr=0,x;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='('){leftbr++;}
        else if(s[i]==')'){rightbr++;}
    }
    if(leftbr==rightbr){x=0;}
    else if(leftbr<rightbr){x=1;}
    else{
        x=-1;
    }
    return x;

}
int main()
{
    char ele,elem,st[2];
    int prep,pre,popped,j=0,chk=0;
    gets(infix);
    chk=braces(infix);
    if(chk!=0)
    {
        cout<<"unbalanced no of braces"\n;
    }
    for(int i=0;infix[i]!='\0';i++)
    {
        if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='+'&&infix[i]!='-'&&infix[i]!='*'&&infix[i]!='/'&&infix[i]!='^')
        {
            postfix[j++]=infix[i];

        }
         else if(infix[i]=='(')
            {
                elem=infix[i];
                push(elem);
            }
             else if(infix[i]==')')
            {
               while((popped=pop())!='(')
               {
                   postfix[j++]=popped;
               }
            }
            else{
                elem=infix[i];
                pre=precedence(elem);
                ele=topelement();
                prep=precedence(ele);
                if(pre>prep){push(elem)}
                else{
                    while(prep>=pre)
                    {
                        if(ele=='#'){break;}
                        popped=pop();
                        ele=topelement();
                        postfix[j++]=popped;
                        prep=precedence(ele)
                    }
                    push(elem);
                }
            }
    }
    while((popped=pop())!='#')
    {
        postfix[j++]=popped;
    }
    postfix[j]='\0';
    cout<<postfix;
}

