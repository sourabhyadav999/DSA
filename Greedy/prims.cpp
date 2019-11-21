
#include <bits/stdc++.h>
using namespace std;

#define n 5


int minKey(int key[], bool mstSet[])
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


void printMST(int parent[] , int graph[n][n])
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < n; i++)
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[][n])
{

	int parent[n];


	int key[n];


	bool mstSet[n];


	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;


	key[0] = 0;
	parent[0] = -1;


	for (int count = 0; count < n - 1; count++)
	{

		int u = minKey(key, mstSet);


		mstSet[u] = true;

		for (int v = 0; v < n; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}


	printMST(parent, graph);
}


int main()
{


	int graph[n][n];
	cout<<"Enter Graph weights";
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            cin>>graph[i][j];
        }
    }


	primMST(graph);

	return 0;
}



