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
**lcm = (A*B)/gcd;**                 
```
```int k = to_string(num).length()
sum += pow(ld, k);
 return sum == num ? true : false;```
---
```
my appproach 
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum = 0;
        for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0){
                //cout <<"divisor" << j << endl;
                sum+=j;
                //cout <<" sum "<< sum << endl;
            }
        }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends```
```actual case:
sum = sum+(i*(N/i));
```

```prime
                                
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

// Function to check if a
// given number is prime.
bool checkPrime(int n){ 

    // Initialize a counter variable to
    // count the number of factors.
    int cnt = 0;

    // Loop through numbers from 1
    // to the square root of n.
    for(int i = 1; i <= sqrt(n); i++){ 

        // If n is divisible by i
        // without any remainder.
        if(n % i == 0){ 

            // Increment the counter.
            cnt = cnt + 1;

            // If n is not a perfect square,
            // count its reciprocal factor.
            if(n / i != i){
                cnt = cnt + 1;
            }
        }
    }

    // If the number of
    // factors is exactly 2.
    if(cnt == 2){
         // Return true, indicating
         // that the number is prime.
        return true;
    }
    // If the number of
    // factors is not 2.
    else{ 
        // Return false, indicating
        // that the number is not prime.
        return false; 
    }
}


int main() {
    int n = 1483;
    bool isPrime = checkPrime(n);
    if(isPrime){
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
                                
```
```
    public:
    int c=1;
    //Complete this function
    void printNos(int N)
    {
        cout << c << " ";
        if(N==1) return;
        //cout << N <<" ";
        c++;
        printNos(N-1);
        //Your code here
    }
};
```

Whenever recursion calls are executed, they’re simultaneously stored in a recursion stack where they wait for the completion of the recursive function. A recursive function can only be completed if a base condition is fulfilled and the control returns to the parent function. 

But, when there is no base condition given for a particular recursive function, it gets called indefinitely which results in a Stack Overflow i.e, exceeding the memory limit of the recursion stack and hence the program terminates giving a Segmentation Fault error. 

```
class Solution {
  public:
  long long sum;
    long long sumOfSeries(long long n) {
        // code here
        //a = n*(n+1)/2;
        //return a*a;
        if(n==1){
            return 1;
        }
        return n*n*n + sumOfSeries(n-1);
        //do not use mathematical functions like pow, increasestiem complexity and do not forget recursion stack;
    }
};
```
```
class Solution
{
public:
vector<long long> v;

    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        for(long long i=1;i<=N;i++){
            long long fact = factorial(i);
           if(fact <=N){
               v.push_back(fact);
           }
           else{
               return v;
           }
        }
    }
    long long factorial(long long N){
        if(N==1) return 1;
        return N * factorial(N-1);
    }
};
```
```
The above led to segmentation error
class Solution
{
public:
vector<long long> v;
long long fact =1;

    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        for(long long i=1;i<=N;i++){
            fact *= i;
            v.push_back(fact); //if(fact <= N){v.push_back(fact)}
            if(v[i-1] > N){//else{return v; break;} //also led to segmentation fault
                v.pop_back();
                break;
            }
           }
            return v;
    }

};
```

```void reverseArray(int arr[], int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArray(arr, start + 1, end - 1);
   }
}
```

```
class Solution {
public:
    bool isPalindrome(string s) {
        int left =0;
        int right = s.length()-1;
        while(left<right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};



bool palindrome(int i, string& s){
    
    // Base Condition
    // If i exceeds half of the string means all the elements 
    // are compared, we return true.
    if(i>=s.length()/2) return true;
    
    // If the start is not equal to the end, not the palindrome.
    if(s[i]!=s[s.length()-i-1]) return false;
    
    // If both characters are the same, increment i and check start+1 and end-1.
    return palindrome(i+1,s);
}
```
```
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;//possibility of 0 so n<=1
        return fib(n-1) + fib(n-2);
        
    }
};
```
When given ele should be greater than N, enforce that condition


2. k = k % n;

This line performs the modulo operation (%) on k. The modulo operation gives the remainder when k is divided by n.
This step ensures k stays within the valid range for rotating the array.
Imagine nums has 5 elements (n = 5) and you want to rotate by 8 (k = 8). Rotating by 8 is the same as rotating by 3 (8 positions to the right is the same as 5 positions to the right and then wrapping around).
By performing k % n, you get k = 3, which is a valid rotation distance within the array size.
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //int j=0;
        int n = nums.size();
        k = k % n; 
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

#include <iostream>
using namespace std;
void Rotatetoright(int arr[], int n, int k)
{
  if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  int temp[k];
  for (int i = n - k; i < n; i++)
  {
    temp[i - n + k] = arr[i];
  }
  for (int i = n - k - 1; i >= 0; i--)
  {
    arr[i + k] = arr[i];
  }
  for (int i = 0; i < k; i++)
  {
    arr[i] = temp[i];
  }
}
int main()
{
  int n = 7;
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int k = 2;
  Rotatetoright(arr, n, k);
  cout << "After Rotating the elements to right " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}
```

# Two pointer
Used when minimization of two loops to one; two variables in two loops; one loop constant other changed and then the itial one changed depedning ona  conditon


---
```
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector <int> output;
        set <int> s;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
        }
        for(int i=0;i<m;i++){
            s.insert(arr2[i]);
        }
        for(auto it:s){
            output.push_back(it);
        }
        return output;
        //Your code here
        //return vector with correct order of elements
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
```
https://leetcode.com/problems/missing-number/ : Can use mathematical formula or bitwise operations;
