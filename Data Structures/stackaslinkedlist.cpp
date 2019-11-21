#include<iostream>
using namespace std;
struct node{
int data;
node *next;
}*top,*newptr,*ptr,*save;
node *create(int data)
{

    ptr= new node;
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void push(node *np)
{
    if(top==NULL)
    {
        top=np;
    }

    else
    {
        save = top;
        top=np;
        np->next=save;
    }
}
int pop()
{
    int ret;
    ret=top->data;
    if(top==NULL)
    {
        return -1;
    }
    else
    {
        ptr=top;
        top=top->next;
        delete ptr;

    }
}
void display(node *np)
{
    while(np!=NULL){
        cout<<np->data<<"->";
        np=np->next;
    }
    cout<<"!!!\n";
}

int main()
{


}
