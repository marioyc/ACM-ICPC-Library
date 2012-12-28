#include<iostream>
#include<string>

#define MAX_SIZE 10000

using namespace std;

int f[MAX_SIZE][26];

void compute_transition_function(string P){
    int m=P.size();
    string Pq,aux;
    bool check;
    
    for(int q=0;q<=m;q++){
        Pq=P.substr(0,q);
        
        for(char c='a';c<='z';c++){
            int k=min(m,q+1);
            
            aux=Pq+c;
            
            while(1){
                check=true;
                
                for(int i=0;i<k;i++) if(aux[q-i]!=P[k-1-i]) check=false;
                
                if(check) break;
                k--;
            }
            
            f[q][c-'a']=k;
        }
    }
}

void finite_automata_matcher(string T, int m){
    int n=T.size(),q=0;
    
    for(int i=0;i<n;i++){
        q=f[q][T[i]-'a'];
        if(q==m) cout<<"Pattern occurs with shift "<<i+1-m<<endl;
    }
}

int main(){
    string P,T;
    
    cout<<"Text :"; cin>>T;
    cout<<endl;
    cout<<"Pattern : "; cin>>P;
    cout<<endl;
    
    compute_transition_function(P); //asumiendo que el alfabeto son las letras minusculas
    finite_automata_matcher(T,P.size());
    
    system("pause");
    
    return 0;
}
