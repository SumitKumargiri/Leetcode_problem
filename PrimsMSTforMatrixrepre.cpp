#include<bits/stdc++.h>
using namespace std;
#define V 5 
int minkey(int key[], bool mstset[])
{
    int min= INT_MAX ,min_index ;
    for (int  i = 0; i < V; i++)
    {
        if (mstset[i]==false && key[i]<min)
        {
            min= key[i];
            min_index=i ;
        }
        
    }
    return min_index ;
}
void printmst(int parent[], int graph[V][V])
{
    cout<<"Edge\t\tWeight\n ";
    for (int  i = 1; i < V; i++)
    {
        cout<<parent[i]<<" --"<<i<<"\t\t"<<graph[i][parent[i]]<<endl;
    }
}
void primMST(int graph[V][V])
{
    int i ,parent[V], key[V] ;
    bool mstset[V] ;
    for ( i = 0; i < V; i++)
    {
        mstset[i]=false ;
        key[i]=INT_MAX; 
    }
    key[0]=0 ;
    parent[0]=-1 ;
    for ( i = 0; i < V-1; i++)
    {
        int u= minkey(key,mstset) ;
        mstset[u]=true ;
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] && mstset[j]==false && graph[u][j]<key[j])
            {
                parent[j]=u ;
                key[j]=graph[u][j] ;
            }          
        }
        
    }
    printmst(parent,graph) ;
}
int main()
{
     int graph[V][V]= { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph) ;
    return 0 ;
}
