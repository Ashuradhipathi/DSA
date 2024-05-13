If reversing x causes the value to `go outside the signed 32-bit integer range [-231, 231 - 1],` then return 0.

- Use long for variables as it is indicating that values will go out during calculation;
- INT_MAX, INT_MIN for limits.

`when dealing with negative numbers` dont use x>0 as condition in while loop instead `use x!=0` 

when checking with original number make  a copy.

```
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//not working; time complexity error
// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        int check = min(A,B);
        long gcd = 0;
        long lcm;
        for(int i =1; i<=check; i++){
            if(A%i == 0 && B%i==0){
                if(i>gcd) gcd = i;
            }
        }
        for(int i = 1; i<=max(A,B); i++){
            if((A*i)%B == 0){
                lcm = A*i;
                break;
            }
        }
        return {lcm, gcd};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
```
