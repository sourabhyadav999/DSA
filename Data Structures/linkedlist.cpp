
#include<iostream>
using namespace std;
struct node{
int data;
node *next;
}*save,*newptr,*ptr,*front,*rear;
node *create(int data)
{
    ptr = new node;
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void insert_beg(node *np)
{

    if(front==NULL)
    {
        front=np;
    }
    else{
        save=front;
        front=np;
        np->next=save;
    }
}
void insert_end(node *np)
{
    if(front==NULL)
    {
        front=rear=np;
    }
    else
    {
        rear->next=np;
        rear=np;
    }

}
void delete()
{
    if(front==NULL){cout<<"underflow\n";}
    else{
        ptr=front;
        front=front->next;
        delete ptr;
    }
}
void display(node *np)
{
    while(np!=NULL)
    {
        cout<<np->data<<"->";
        np=np->next;
    }
}
int main()
{
    front=rear=NULL;
}
