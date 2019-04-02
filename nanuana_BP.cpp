#include<fstream>
using namespace std;
int S,n,B[100];

int read_data(){
    ifstream f("input.dat");
    f>>S>>n;
    for(int i=1;i<=n;i++){
        f>>B[i];
    }
}

int sort_data(){
    int loc=0;
    for(int i=1;i<=n;i++){
        int maxim=INT_MIN;
        for(int j=i;j<=n;j++){
            if(B[j]>maxim){
                maxim=B[j];
                loc=j;
            }
        }
        swap(B[i],B[loc]);
    }
}

int greedy(){
    int nr=0;
    for(int i=1;i<=n;i++){
        while(S>B[i]){
            S=S-B[i];
            nr++;
        }
    }
    return nr;
}

int print_data(){
    ofstream g("output.dat");
    g<<greedy();
}

int main(){
    read_data();
    sort_data();
    print_data();
    return 0;
}
