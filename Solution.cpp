#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define ll             long long int
#define pii             pair<int, int>
#define vii              vector<long long int>
#define vi               vector<int>
#define vs              vector<string> 
#define mii             map<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define MOD             1000000007  //1e9+7
#define INF             1e18
#define PI              acos(-1)
#define fprecision(x,y) fixed<<setprecision(y)<<x
#define T()            int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr = new type[n]; //dynamic
using namespace std;

void a_s_c(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}


int main(){
    a_s_c();
    int n; cin>>n; 
    // INPUTS
    vi a; for(int i=0;i<n;i++){int val; cin>>val; a.push_back(val);}; 
    int q; cin>>q; vi query; for(int i=0;i<q;i++){int val; cin>>val; query.push_back(val);};
    //REMOVING CONTINOUS DUPLICATES
    unique(a.begin(),a.end());
    int length = a.size ();
 
    for ( size_t i = 1; i < a.size (); i++ ) {
        if ( a [i - 1] >= a [i] ) {
            length = i;
            break;
        }
    }

    for(int i=0;i<q;i++){
        bool fg = true;
        if(query[i]<=a[n-1]&& query[i]>=a[0]){ 

            int ansL = INT_MIN,ansH= INT_MAX;
            //binary search of ith query
            ll low =0,high= length;
            ll point=0;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(a[mid]<query[i]){
                    ansL = max(ansL,a[mid]);
                    low = mid+1;
                }
                else if(a[mid]>query[i]){
                    ansH = min(ansH,a[mid]);
                    high = mid-1;
                }
                else{
                    fg = false;
                    if(mid==0){
                        cout<<"X "<<a[mid+1]<<"\n";
                    }else if(mid==n-1){
                        cout<<a[mid-1]<<" "<<"X\n";
                    }else{
                        cout<<a[mid-1]<<" "<<a[mid+1]<<"\n";
                    }
                    break;
                }
            }
            if(fg) cout<<ansL<<" "<<ansH<<"\n";

        }else if(query[i]>a[n-1]){
            cout<<a[n-1]<<" X\n";
        }else{
            cout<<"X "<<a[0]<<"\n";
        }
        
        
    }
    return 0;
}
