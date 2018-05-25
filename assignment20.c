// A C / C++ program for Prim's Minimum Spanning Tree (MST) algorithm. 
// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <limits.h>
FILE *fp;
// Number of vertices in the graph
#define V 8
#define false 0
#define true 1
#define DIVYA 1

typedef int bool;
 
// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed MST stored in parent[]
int printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
    return 0;
}
 
// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
     int parent[V]; // Array to store constructed MST
     int key[V];   // Key values used to pick minimum weight edge in cut
     bool mstSet[V];  // To represent set of vertices not yet included in MST

#ifdef DIVYA
    {
        int i=0, j=0, n =8;
        for(i=0; i < n; i++)
            for(j=0;j<n;j++)
            {
                printf("g[%d][%d]=%d\n",i, j,graph[i][j]);
            }
//
//        for(i=0; i < n; i++)
//            for(j=0;j<n;j++)
//            {
//                printf("Cost[%d][%d]=%d, spanning[%d][%d]= %d\n",i, j,cost[i][j], i,j,spanning[i][j] );
//            }
    }
#endif
     // Initialize all keys as INFINITE
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
     // Always include first 1st vertex in MST.
     key[0] = 0;     // Make key 0 so that this vertex is picked as first vertex
//     parent[0] = -1; // First node is always root of MST
     parent[0] = 0; // First node is always root of MST

     // The MST will have V vertices
     for (int count = 0; count < V; count++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; v++){
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] !=0 && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
            printf("Key %d\n", key[v]);
        }
 
     }
 
     // print the constructed MST
     printMST(parent, V, graph);
}

int main()
{

    {
        int graph[V][V] = {
                {0, 25, 65, 85, 0, 0, 0, 0},
                {0, 0, 30, 40, 0, 0, 0, 0},
                {0, 0, 0, 0, 60, 0, 120, 0},
                {0, 0, 0, 0, 75, 90, 130, 0},
                {0, 0, 0, 0, 0, 0, 55, 0},
                {0, 0, 0, 0, 0, 0, 50, 70},
                {0, 0, 0, 0, 0, 0, 0, 40}
        };

        // Print the solution
        primMST(graph);

        return 0;
    }

    #ifdef MAIN
    {
    int srcnode, dstnode, distance=0;
    char ch;
    fp = fopen("assignment20out.doc","w+");
    int igraph[V][V];
    for(int i=0; i < V; i++){
        for(int j=0; j< V; j++){
            igraph[i][j]= 0;
        }
    }

    printf("Do you want to enter distance between vertices (y/n)? ");
    fflush(fp);
    scanf("%c", &ch);
    printf("%c\n", ch);
    while(1)
    {
        if(ch == 'n')
            break;
        printf("Enter source node: ");
        fflush(fp);
        scanf("%d%*c", &srcnode);
        printf("%d\n",srcnode);
        printf("Enter destination node: ");
        fflush(fp);
        scanf("%d%*c", &dstnode);
        printf("%d\n",dstnode);
        printf("Enter weight from sourcenode to destinationnode: ");
        fflush(fp);
        scanf("%d%*c", &distance);
        printf("%d\n",distance);

//        printf("Enter src-node->dst-node=weight Eg <0->1=20> : ");
//        scanf("%d->%d=%d",&srcnode, &dstnode, &distance);

        igraph[srcnode][dstnode] = distance;
        //stdin = freopen(NULL,"r",stdin);
        printf("Do you want to enter distance between vertices (y/n)? ");
        fflush(fp);
        scanf("%c%*c", &ch);
        printf("%c\n", ch);
    }
    printf("Weight Matrix\n");
    printf("\t");
    fflush(fp);
    for(int i=0; i < V; i++){
        printf("%d\t", i);
        fflush(fp);
    }
    printf("\n");
    for (int i = 0; i < V; i++){
        printf("%d\t",i);
        fflush(fp);
        for (int j = 0; j < V; j++){
            printf("%d\t", igraph[i][j]);
            fflush(fp);
            //printf("%d -> %d \t\t %d\n", i,j, graph[i][j]);
        }
        printf("\n");
    }
    printf("Minimum Spanning tree for the above graph\n");
    // Print the solution
    primMST(igraph);

    return 0;
    }
    #endif
}

