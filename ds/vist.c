#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],visted[20],reach[10],n,i,j,f=0,r=1,count=0;
void bfs(int v)
{
	for(i=1;i<=n;i++)
		if(a[v][i]&&!visted[i])
			q[++r]=i;
	if(f<=r)
	{
		visted[q[f]]=1;
		bfs(q[f++]);
	}
}
void dfs(int v)
{
	int i;reach[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]&&!reach[i])
		{
			printf("\n%d->%d",v,i);
			count++;
			dfs(i);
		}
	}
}
void main()
{
	int v,choice;
	printf("\nenter the no of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		q[i]=0;
		visted[i]=0;
	}
	for(i=1;i<=n;i++)
		reach[i]=0;
	printf("\n enter graph data in matrix form:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("1.BFS\n2.DFS\n3.exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\nenter the starting vertex:");
			scanf("%d",&v);
			bfs(v);
			if((v<1)||(v>n))
			{
				printf("\nBFS is not possible");
			}
			else
			{
				printf("\n the nodes which are reachable from%d:\n",v);
				for(i=0;i<n;i++)
					if(visted[i])
						printf("%d\t",i);
			}
			break;
		case 2:
			dfs(1);
			if(count==n-1)
				printf("\ngraph is connected");
			else
				printf("\ngraph is not connected");
			break;
		case 3:
			exit(0);
	}
}



