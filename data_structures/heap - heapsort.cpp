#include <iostream>
#include <algorithm>

using namespace std;

int N,heap_size;

void max_heapify(int *A, int i){
    int l,r,largest=i;
    
    do{
        i=largest;
        l=2*i+1;
        r=2*i+2;
        
        if(l<heap_size && A[l]>A[largest]) largest=l;
        if(r<heap_size && A[r]>A[largest]) largest=r;
        
        swap(A[largest],A[i]);
    }while(largest != i);
}

void build_max_heap(int *A){
    heap_size=N;
    
    for(int i=N/2;i>=0;i--)
        max_heapify(A,i);
}

int main(){    
    cout<<"N = ";
    cin>>N;
    
    int A[N];
    
    for(int i=0;i<N;i++){
        cout<<"A["<<i<<"] = ";
        cin>>A[i];
    }
    
    build_max_heap(A);
    
    //Mostar la max_heap
    
    for(int i=0,x=2;i<N;i++){
        cout<<A[i]<<" ";
        
        if(i==x-2){
            x*=2;
            cout<<endl;
        }else if(i==N-1) cout<<endl;
    }
    
    //heapsort
    
    for(int i=N-1;i>=0;i--){
        swap(A[i],A[0]);
        heap_size--;
        max_heapify(A,0);
    }
    
    //mostrar arreglo ordenado
    
    for(int i=0;i<N;i++) cout<<A[i]<<" ";
    cout<<endl;
    
    system("pause");
}
