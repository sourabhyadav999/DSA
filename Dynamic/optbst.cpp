#include <bits/stdc++.h>
using namespace std;

int m[100][100][2];

int sum(int i, int j, vector<int> freq)
{
    int s=0;
    for(int k=i;k<=j;k++)
    {
        s+= freq[k];
    }
    return s;
}
int matrixsetvalues(int n, int m[100][100][2], vector<int> freq)
{
    for(int i=0;i<n;i++)
    {
        m[i][i][0] = freq[i];
        m[i][i][1] = i+1;

    }


    for (int L = 2; L <= n; L++)
    {

        for (int i = 0; i <= n-L+1; i++)
        {

            int j = i+L-1;
            m[i][j][0] = INT_MAX;
             int weight = sum(i,j,freq);


            for (int r = i; r <= j; r++)
            {
                int c;

           if(r>i && r<j)
           {
               c=  m[i][r-1][0]+ m[r+1][j][0]+weight;
           }
           else if( r>i && r>=j)
           {
               c = m[i][r-1][0]+ weight;
           }
           else if( r<=i && r<j)
           {
                c = m[r+1][j][0]+ weight;

           }
           else if(r<=i && r>=j)
           {
               c = weight;
           }
           if (c < m[i][j][0])
                m[i][j][0] = c;
                m[i][j][1]=r;
            }
        }
    }
    cout<<"COST matrix \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m[i][j][0]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n KEY matrix \n";

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m[i][j][1]<<"\t";
        }
        cout<<"\n";
    }
    int min_cost  = m[0][n-1][0];

    return min_cost;
}
typedef struct OBST
{
 int KEY;
 struct OBST *left, *right;
}
OBST;


OBST *CONSTRUCT_OBST(int i, int j, int key[], int n)
{
 OBST *p;
 if(i == j)
 p = NULL;
 else
 {
 p = new OBST;
 p->KEY = key[m[i][j][1]];
 p->left = CONSTRUCT_OBST(i, m[i][j][1] - 1,key,n); //left subtree
 p->right = CONSTRUCT_OBST(m[i][j][1], j,key,n); //right subtree
 }
 return p;
}


void DISPLAY(OBST *ROOT, int nivel)
{
 int i;
 if(ROOT != 0)
 {
 DISPLAY(ROOT->right, nivel+1);
 for(i = 0; i <= nivel; i++)
 {
     printf(" ");
 }

 printf("%d\n", ROOT->KEY);
 DISPLAY(ROOT->left, nivel + 1);

 }
}




int main()
{

    int key[10];
    vector<int> freq;
    int n;
    cout<<"Enter number of nodes ::";
    cin>>n;
    cout<<"Enter keys ::";
    for(int i=0;i<n;i++)
    {
        cin>>key[i];
    }
    cout<<"Enter frequency::";
    for(int i=0;i<n;i++)
    {
        int n;
        cin>>n;
        freq.push_back(n);
    }
    int cost = matrixsetvalues(n,m,freq);
    cout<<"Minimum cost of constructing BST::"<<cost;
    OBST *ROOT = CONSTRUCT_OBST(0, n,key,n);
    DISPLAY(ROOT,0);
}
