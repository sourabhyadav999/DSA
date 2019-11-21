#include<iostream>
using namespace std;
int top=-1;
void push(int stack[], int ele)
{
    if(top==49)
    {
      return;
    }
        top++;
        stack[top]=ele;
}
int pop(int stack[])
{
    int ret;
    if(top==-1){
        return -1;
    }
       else{
        ret=stack[top];
        top--;
       }
       return ret;
}
void display(int stack[])
{
    int y=top;

    if(top==-1)
    {

        return;
    }
    else{
        while(y!=0)
        {
            cout<<stack[y]<<" ";
            y--;
        }
    }
}

 int main()

 {
     int stack[50],n;
     char y='y';
     do
     {

     }while(y=='y'||y=='Y');

 }
