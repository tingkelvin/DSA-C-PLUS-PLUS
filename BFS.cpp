#include <iostream>
#include<list>
#include <queue>

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

void bfs(Graph *g){
    queue<int> q;
    bool visited[MAXV+1];
    q.push(0);

    for(int i=0;i<MAXV;i++){
        visited[i] = false;
    }

    while (!q.empty()){
        int p = q.front();
        q.pop();
        visited[p] = true;
        cout << "visiting: " << p <<endl;
        for(int it:g->adjlist[p]){
            if (visited[it] != true){
                q.push(it);
            }
        }
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
    bfs(g);
}