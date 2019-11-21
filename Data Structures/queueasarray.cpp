#include<iostream>
using namespace std;
int front=-1,rear=-1;
void insert(int queue[],int data)
{
    if(rear==49)
    {
        return;
    }
    else if(rear==-1){
            front=0;rear=0;
    queue[rear]=data;

    }
    else{
        rear++;
        queue[rear]=data;
    }

}
int delete()
{
    int ret;
    if(front==-1)
    {

        ret=-1;
    }
    else
    {
        ret=queue[front];
        if(front==rear){front=rear=-1;}
        else{front++}

    }
    return ret;
}
void display(int queue[])
{
    if(front==-1){return;}
    else{
        for{int i=front;i<=rear;i++}
        {
            cout<<queue[i]<<"<-";
        }
    }
}
int main()
{


}
