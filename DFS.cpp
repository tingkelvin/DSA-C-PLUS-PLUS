#include <iostream>
#include<list>
#define MAXV 10
using namespace std;

struct Graph{
    int nvertices;
    int nedges;
    int degree[MAXV+1];
    list<int> *adjlist;

};

void init_graph(Graph *g){
    g->nvertices = 0;
    g->nedges = 0;
    g->adjlist = new list<int> [MAXV];

}

void print(Graph *g){
    for(int i=0;i<MAXV;i++){
        cout<<i<<"-->";
        for(int it:g->adjlist[i]){
            cout<<it<<" ";
        }
        cout<<endl;
        }
    cout<<endl;
    }

void insert_edge(Graph *g, int from, int to){
    g->adjlist[from].push_back(to);
}

void _dfs(int n, bool* visited, Graph *g){
    visited[n] = true;
    cout<<"visiting "<<n << endl;
    for(int it:g->adjlist[n]){
        if (visited[it] == false){
            _dfs(it, visited, g);
        }
    }
    
}

void dfs(Graph *g){
    bool visited[MAXV+1];
    for(int i=0;i<MAXV;i++){
        visited[i] = false;
    }
    _dfs(0, visited, g);

    for(int i=0;i<MAXV;i++){
        cout<< visited[i] <<endl;
    }
}

int main(){
    struct Graph *g = new Graph; 
    init_graph(g);
    insert_edge(g, 1,2);
    insert_edge(g, 4,7);
    insert_edge(g, 5,2);
    insert_edge(g, 9,3);
    insert_edge(g, 2,8);
    insert_edge(g, 4,9);
    insert_edge(g, 5,7);
    insert_edge(g, 2,4);
    insert_edge(g, 3,2);
    insert_edge(g, 6,2);
    insert_edge(g, 8,4);
    insert_edge(g ,7,0);
    insert_edge(g ,0,4);
    print(g);
    dfs(g);
}