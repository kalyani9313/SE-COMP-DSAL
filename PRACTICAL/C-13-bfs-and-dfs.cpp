#include<iostream>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,visit[10],visited[10],n,m,v,front,rear,q[10];
int stk[10],top,visit1[10],visited1[10],ch;
int main()
{
	system("cls");
	char c;
	do
	{
		cout<<"\n\t1.Create\n\t2.Matrix\n\t3.BFS\n\t4.DFS";
		cout<<"\n\tEnter choice:";;
		cin>>ch;
		switch(ch)
		{
			case 1:
			cout<<"\n\tCreating a graph:";
			cout<<"\n\tEnter the number of vertices:";
			cin>>n;
			cout<<"\n\tEnter the number of edges:";
			cin>>m;
			cout<<"\n\tEnter the edges:";
			for(k=1;k<=m;k++)
			{
				cin>>i>>j;
				cost[i][j]=1;
				cost[j][i]=1;
			}
			cout<<"\n\tGraph created!";
			break;
			case 2:
			cout<<"\n\tCreating adjancey matrix:";
			cout<<"\n\tAdjancey matrix is:"<<endl;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					cout<<" "<<cost[i][j];
				}
				cout<<endl;
			}
			break;
			case 3:
				cout<<"\n\tEnter the initial vetrex:";
				cin>>v;
				cout<<"\n\tBFS is:";
				cout<<v;
				visited[v]=1;
				k=1;
				while(k<n)
				{
					for(j=1;j<=n;j++)
					{
						if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
						{
							visit[v]=1;
							q[rear++]=j;
						}
					}
					v=q[front++];
					cout<<"-->"<<v;
					k++;
					visit[v]=0;
					visited[v]=1;
				}
			break;
			case 4:	
				cout<<"\n\tEnter initial vertex:";
				cin>>v;
				cout<<"\n\tDFS ";
				cout<<v;
				visited[v]=1;
				k=1;
				while(k<n)
				{
					for(j=n;j>=1;j--)
					{
						if(cost[v][j]!=0 && visited1[j]!=1 && visit1[j]!=1)
						{
							visit1[v]=1;
							stk[top]=j;
							top++;
						}
					}
					v=stk[--top];
					cout<<"--->"<<v;
					k++;
					visit1[v]=1;
					visited1[v]=1;
				}		
		}
		cout<<"\n\tcontinue?:";
		cin>>c;
	}while(c=='y');
	return 0;
}
