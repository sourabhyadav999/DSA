
  #include <bits/stdc++.h>
using namespace std;

int sum(int i, int j, vector<int> freq)
{
    int s=0;
    for(int k=i;k<=j;k++)
    {
        s+= freq[k];
    }
    return s;
}





int matrixsetvalues(int n, int m[100][100], vector<int> freq)
{


    for(int i=0;i<n;i++)
    {
        m[i][i] = freq[i];
    }


    for (int L = 2; L <= n; L++)
    {

        for (int i = 0; i <= n-L+1; i++)
        {

            int j = i+L-1;
            m[i][j] = INT_MAX;
             int weight = sum(i,j,freq);


            for (int r = i; r <= j; r++)
            {

            int c = ((r > i)? m[i][r-1]:0) +
                    ((r < j)? m[r+1][j]:0) +
                    weight;









            if (c < m[i][j])
                m[i][j] = c;
            }
        }
    }



    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }




    int min_cost  = m[0][n-1];

    return min_cost;



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





    int m[100][100];
    int cost = matrixsetvalues(n,m,freq);



    cout<<cost;







}
