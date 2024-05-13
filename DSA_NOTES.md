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
```
striver code

                                
#include <iostream>
#include <algorithm>

using namespace std;

int findGcd(int a, int b) {
    // Continue loop as long as both
    // a and b are greater than 0
    while(a > 0 && b > 0) {
        // If a is greater than b,
        // subtract b from a and update a
        if(a > b) {
             // Update a to the remainder
             // of a divided by b
            a = a % b;
        }
        // If b is greater than or equal
        // to a, subtract a from b and update b
        else {
            // Update b to the remainder
            // of b divided by a
            b = b % a; 
        }
    }
    // Check if a becomes 0,
    // if so, return b as the GCD
    if(a == 0) {
        return b;
    }
    // If a is not 0,
    // return a as the GCD
    return a;
}




int main() {
    int n1 = 20, n2 = 15;
    
    // Find the GCD of n1 and n2
    int gcd = findGcd(n1, n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

    return 0;
}
    
                                
                            ```

