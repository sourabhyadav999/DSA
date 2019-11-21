#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j;
		for ( j = i - 1;j >= 0 && arr[j] > arr[i];j--)
		{
			arr[j + 1] = arr[j];
        }
		arr[j + 1] = arr[i];
	}
}
int main()
{

	int n;
	cin>>n;
	int *arr= new int [n];
	for(int i=0;i<n;i++)
        cin>>arr[i];
    insertionSort(arr, n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

// This is code is contributed by rathbhupendra

