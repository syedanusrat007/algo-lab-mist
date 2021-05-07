/*
0 1 0 0
0 1 1 1
1 0 0 1
0 0 1 0

starting point = 3
 output = 3 2 0 1
 */


#include <stdio.h>
#include <stdlib.h>

int queue[100];
int front, end;
void enqueue(int v);
int dequeue();

void bfs(int adj[][100], int n, int source);

int main(void)
{
    int n,i,j,adj[100][100],start;
    printf ("Enter the number of vertex: \n");
    scanf ("%d",&n);
    printf ("Plot the graph in adjacent matrix form:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf ("%d",&adj[i][j]);
        }
    }
    printf ("Enter the starting point:\n");
    scanf ("%d",&start);
	bfs(adj, n, start);

	return 0;
}

void bfs(int adj[][100], int n, int source)
{
	int i, j;
	int visited[100];


	front = 0, end = 0;

	for(i = 0; i < n; i++)
    {
		visited[i] = 0;
	}

	visited[source] = 1;

	enqueue(source);

	printf("%d ", source);

	while(front <= end)
    {
		i = dequeue();

		for(j = 0; j < n; j++)
        {
			if(visited[j] == 0 && adj[i][j] == 1)
            {
				visited[j] = 1;

				enqueue(j);

				printf("%d ", j);
			}
		}
	}
	printf("\n");
}

void enqueue(int v)
{
	queue[end] = v;
	end++;
}

int dequeue()
{
	int index = front;
	front++;
	return queue[index];
}
