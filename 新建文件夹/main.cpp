#include<iostream>
#include<vector>
#include<unordered_map>
// #include "test.hpp"
// #include "test1.hpp"
using namespace std;

extern int a;
int getAns(vector<vector<int>> &nums){
    
    int M = 0x7ffffff;
    int n = nums.size();
    vector<vector<int>> dp(1<<n, vector<int>(n,M));
    dp[1][0] = 0;
    for(int i=1; i<n; i++) dp[1<<i][i] = M;
    for(int i=1; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(dp[i][j]!=M){
                for(int k=0; k<n; k++){
                    if((i&(1<<k))==0){
                        dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k], dp[i][j]+nums[j][k]);
                    }
                }
            }
        }
    }
    int ans = M;
    for(int i=1; i<n; i++){
        ans = min(ans, dp[(1<<n)-1][i]+nums[i][0]);
    }
    return ans;
}
class xx
{
public:
    static int p;
};
int xx::p = 10;
int main(){
    cout << a << endl;
    cout << xx::p << endl;
    // int n;
    // while(cin>>n){
    //     vector<vector<int>> edges(n,vector<int>(n,0));
    //     int x;
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<n; j++){
    //             cin>>edges[i][j];
    //         }
    //     }
    //     cout<<getAns(edges)<<endl;
    // }
    return 0;
}
