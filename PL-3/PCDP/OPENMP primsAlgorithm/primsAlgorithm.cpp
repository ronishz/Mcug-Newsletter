#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
	int nodes,minimum=9999,cost=0,i,j;		//Variables
	double start_time;	// Start timer
	start_time = omp_get_wtime();
	nodes=5;
	int visited[10]={0},edges[nodes][nodes],nv=1,x,y;
	cout<<"***** PRIMS ALGORITHM ******"<<endl;
	
	//Initializing the adjacency matrix
	int graph[5][5] = {{0,6,8,5,4},{6,0,3,9,1},{8,3,0,9,2},{5,9,9,0,7},{4,1,2,7,0}};
	cout<<"The Adjacency Matrix of given Graph is:"<<endl;
	
	//Printing the adjacency matrix
	for( i=0 ;i<nodes;i++) //rows
	{
		cout<<"\t";
		for( j=0 ;j<nodes;j++) //columns
		{

			cout<<graph[i][j]<<"\t";
			edges[i][j]=0;
		}
		cout<<endl;
	}
	//Select start node and mark it as visited
	visited[1]=1;
	//Iterate through the loop untill all nodes are visited	
	while(nv<nodes) {
		minimum = 9999;
		//Find nearest node
		for( i =0;i<nodes;i++) {
			if(visited[i]==1) {
			#pragma omp parallel for
				for( j=0;j<nodes;j++) {	
					if(visited[j]==0 && graph[i][j]!=0) {
					#pragma omp critical
						if(minimum>graph[i][j]) {
							minimum =graph[i][j];
							x=i;
							y=j;
						}
					}
				}
			}

		}
		//Add nearest node to the tree and mark it visited
		//Increase the cost of the tree		
		//Increment number of visited nodes
		cout<<"\n(v"<<x<<",v"<<y<<")->"<<minimum;
		cost=cost+minimum;
		edges[x][y]=minimum;
		edges[y][x]=minimum;
		visited[y]=1;
		nv++;
	}
	cout<<"\n\nThe Adjacency Matrix of Minimum Spanning Tree is:\n";
	for( i=0;i<nodes;i++)
	{
		cout<<"\t";
		for( j=0;j<nodes;j++)
		cout<<edges[i][j]<<"\t";
		cout<<"\n";
	}

	 cout<<"\nThe Total Cost of Minimum Spanning Tree = "<<cost<<endl;
	cout<<"\nTotal Execution time :\t"<<omp_get_wtime() - start_time;

cout<<"\n\n";
return 0;
}









