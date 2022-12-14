#include <iostream>
#define PQ_SIZE 10

using namespace std;

struct PQ{
    int q[PQ_SIZE + 1];
    int n;
};

void init(PQ *q){
    q->n = -1;
}
int parent(int n){
    if (n == 0){
        return -1;
    } else{
        return (int) (n-1)/2 ;
    }
}

int child(int n){
    // cout << (2*n + 1) << endl;
    return (2*n + 1);
}


void swap(PQ *q, int x, int y){
    int tmp = q->q[x];
    q->q[x] =  q->q[y];
    q->q[y] = tmp;
}

void bubbleUp(PQ *q, int x){
    int p = parent(x);
    if (p == -1)
        return;
    if (q->q[p] > q->q[x]){
        swap(q, x, p);
        bubbleUp(q, p);
    }
}

void bubbleDown(PQ *q, int x){
    int p = parent(x);
    int minIdx = x;
    int childIdx = child(x);

    for (int i = 0; i <= 1; i++){
        if((childIdx + i) < q->n){
            childIdx = childIdx + i;
            if(q->q[minIdx] > q->q[childIdx])
                minIdx = childIdx;
        }
    }

    if (minIdx != x){
        swap(q, x, minIdx);
        bubbleDown(q, minIdx);
    }
    
    if (p == -1)
        return;
    if (q->q[p] > q->q[x]){
        swap(q, p, x);
        bubbleUp(q, p);
    }
}

void print(PQ *q){
    for(int i = 0; i <= q->n; i++){
        cout << q->q[i] << endl;
    }
}

void insert(PQ *q, int x){
    if (q->n >= PQ_SIZE)
        cout<< "Warning: priority queue overflow insert!" << endl;
    q->n += 1;
    q->q[q->n] = x;
    bubbleUp(q, q->n);
    
}

void makeHeap(PQ *q, int s[], int n){
    init(q);
    q->n = n - 1;
    for (int i=0; i<n; i++) q->q[i] = s[i];
    for (int i=q->n; i>=1; i--) bubbleDown(q,i);


    // O(n log n)
    // for (int i=0; i<n; i++){
    //     cout << "insert" << s[i] << endl;
    //     insert(q, s[i]);
    // }

}

int min(PQ *q){
    int ret = -1;
    if (q-> n == 0){
        return ret;
    } else{
        int ret = q->q[0];
        q->q[0] = q->q[q->n];
        q->n = q->n - 1;
        bubbleDown(q, 0);
        return ret;
    }
    
}



int main(){
    
    struct PQ *q = new PQ;
    int s[] = {1,2,5,33,6};
    makeHeap(q, s, 5);
    print(q);
    cout << "min: " << min(q) << endl;
    print(q);
    return 0;
}