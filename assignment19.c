/************************ prologue *******************/
/* University of California Extension, Santa Cruz */
/* Advanced C Programming */
/* Instructor: Rajainder A. */
/* Author: Divya Hassan Ravindrakumar */
/* Assignment Number: 19 */
/* Topic: Shortest Path Algorithm */
/* File name: assignment15.c*/
/* Date: August 26, 2017 */
/* Objective: Dijkstra's algorithm*/
/* OS - macOS Sierra 10.12.5 */
/* Compiler - gcc */
/****************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
 
// Number of vertices in the graph
#define V 8
#define false 0
#define true 1

typedef int bool;

FILE *fp;
// A utility function to find the vertex with minimum distance
// value, from the set of vertices not yet included in shortest
// path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;
 
    printPath(parent, parent[j]);
 
    fprintf(fp,"%d ", j);
    fflush(fp);
}
 
// A utility function to print the constructed distance
// array
int printSolution(int dist[], int n, int parent[])
{
    int src = 0;
    fprintf(fp,"Vertex\t  Distance\tPath");
    for (int i = 1; i < V; i++)
    {
        fprintf(fp,"\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        fflush(fp);
        printPath(parent, i);
    }
    fprintf(fp,"\n\n");
    return 0;
}
 
// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V], int src)
{
    int dist[V];  // The output array. dist[i] will hold
                  // the shortest distance from src to i
 
    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[V];
 
    // Parent array to store shortest path tree
    int parent[V];
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to src
        // in first iteration.
        int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is
            // an edge from u to v, and total weight of path from
            // src to v through u is smaller than current value of
            // dist[v]
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }  
    }
 
    // print the constructed distance array
    printSolution(dist, V, parent);
}
 
// driver program to test above function
int main()
{
    int srcnode, dstnode, distance=0;
    char ch;
    fp = fopen("assignment19out.doc","w+");
    int igraph[V][V];
    for(int i=0; i < V; i++){
        for(int j=0; j< V; j++){
            igraph[i][j]=0;
        }
    }

    fprintf(fp,"Do you want to enter distance between vertices (y/n)? ");
    fflush(fp);
    scanf("%c", &ch);
    fprintf(fp,"%c\n", ch);
    while(1)
    {
        if(ch == 'n')
            break;
        fprintf(fp,"Enter source node: ");
        fflush(fp);
        scanf("%d%*c", &srcnode);
        fprintf(fp,"%d\n",srcnode);
        fprintf(fp,"Enter destination node: ");
        fflush(fp);
        scanf("%d%*c", &dstnode);
        fprintf(fp,"%d\n",dstnode);
        fprintf(fp,"Enter weight from sourcenode to destinationnode: ");
        fflush(fp);
        scanf("%d%*c", &distance);
        fprintf(fp,"%d\n",distance);

//        fprintf(fp,"Enter src-node->dst-node=weight Eg <0->1=20> : ");
//        scanf("%d->%d=%d",&srcnode, &dstnode, &distance);

        igraph[srcnode][dstnode] = distance;
        //stdin = freopen(NULL,"r",stdin);
        fprintf(fp,"Do you want to enter distance between vertices (y/n)? ");
        fflush(fp);
        scanf("%c%*c", &ch);
        fprintf(fp,"%c\n", ch);
    }
    fprintf(fp,"Weight Matrix\n");
    fprintf(fp,"\t");
    fflush(fp);
    for(int i=0; i < V; i++){
        fprintf(fp,"%d\t", i);
        fflush(fp);
    }
    fprintf(fp,"\n");
    for (int i = 0; i < V; i++){
        fprintf(fp,"%d\t",i);
        fflush(fp);
        for (int j = 0; j < V; j++){
            fprintf(fp,"%d\t", igraph[i][j]);
            fflush(fp);
            //fprintf(fp,"%d -> %d \t\t %d\n", i,j, graph[i][j]);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"Enter From-Node: ");
    fflush(fp);
    scanf("%d%*c", &srcnode);
    fprintf(fp,"%d\n",srcnode);
    fprintf(fp,"Enter To-Node: ");
    fflush(fp);
    scanf("%d%*c", &dstnode);
    fprintf(fp,"%d\n",dstnode);

    fprintf(fp,"\nShortest Path using dijkstra's algorithm from %d to %d\n", srcnode, dstnode);
    dijkstra(igraph, 0);
    return 0;
}
