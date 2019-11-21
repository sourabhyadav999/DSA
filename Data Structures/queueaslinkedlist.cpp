#include<iostream>
using namespace std;
struct node{
int data;
node *next;
}*save,*front,*rear,*newptr,*ptr;
node *create(int data)
{
    ptr=new node;
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void insert(node *np)
{
    if(front==NULL){front=rear=np;}
    else{
        rear->next=np;
        rear=np;
    }
}
int delete()
{
    int y=front->data;
    if(front==NULL)
    {
        return;
    }
    else{
        ptr=front;
        front=front->next;
        delete ptr;

    }

}
void display(node *np)
{
    while(np!=NULL){
        cout<<np->data<<"<-";
        np=np->next;
    }
    cout<<"!!!\n";
}
int main()
{
    front=NULL;
    rear=NULL;


}

