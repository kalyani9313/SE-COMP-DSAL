a#include <iostream>
using namespace std;

void maxheapify(int heap[],int i, int n)
{
	int left=2*i;
	int right=(2*i)+1;
	int largest=i;
	
	if(left<=n && heap[i]<heap[left])
	{
		largest=left;
	}
	 if(right<=n && heap[largest]<heap[right])
	{
		largest=right;
	}
	if(largest!=i)
	{
		int temp=heap[largest];
		heap[largest]=heap[i];
		heap[i]=temp;
		maxheapify(heap,largest,n);
	}
}

void buildheap(int heap[],int n)
{
	for(int i=n/2;i>=1;i--)
	{
		maxheapify(heap,i,n);
	}
}

int main()
{
	
	int i,n;
	cout<<"\nEnter the total no. of students: ";
	cin>>n;
	int heap[n+1];
	cout<<"\nEnter the marks: ";
	for(i=1;i<=n;i++)
	{
		cin>>heap[i];
	}
	
	buildheap(heap,n);
	int heapsize=n;
	for(i=n;i>=2;i--)
	{
		int temp = heap[1];
		heap[1] = heap[i];
		heap[i] = temp;
		heapsize--;
		maxheapify(heap,1,heapsize);
	}
	
	cout<<"\nAfter Sorting: ";
	for(i=1;i<=n;i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<"\nMinimum: "<<heap[1];
	cout<<"\nMaximum: "<<heap[n];
	
	
}
