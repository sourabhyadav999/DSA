
#include <bits/stdc++.h>
using namespace std;
#define V 4


int travllingSalesman(vector<vector<int>> graph, int s)
{

	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);


	int min_path = INT_MAX;
	do {


		int current_pathweight = 0;


		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];


		min_path = min(min_path, current_pathweight);

	} while (next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}


int main()
{
    vector<vector<int>> graph;

    for(int i=0;i<V;i++)
    {
        vector<int> temp;
        for(int j=0;j<V;j++)
        {
            int value;
            cin>>value;
            temp.push_back(value);
        }
        graph.push_back(temp);
    }




	int s = 0;
	cout<<"Starting Point\t";
	cin>>s;
	cout << travllingSalesman(graph, s) << endl;
	return 0;
}

