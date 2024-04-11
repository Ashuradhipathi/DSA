/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30*/



class Solution {
public:


vector<int> generateRow(int i){
        vector<int> temp;
        temp.push_back(1);
        long long res = 1;
        
        for(int c = 1; c<i;c++){
            res = res * (i-c);
            res = res/(c);
         temp.push_back(res);
        }

        return temp;
    }
    

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
 
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));            
        }

        return ans;
    }

 

/*vector<int> generateRow(int level, vector<vector<int>> ans){
    vector<int> temp;
    for(int j=0; j<=level; j++)
    {
        if(j == 0 || j == level){
            temp.push_back(1);
        }
        else{
            //temp.push_back(ans[level-1][j-1] + ans[level-1][j]);
            temp.push_back(ans[level-1][j-1] + ans[level-1][j]);
        }
    }
return temp;
}
vector<vector<int>> generate(int numRows) {
vector<int> temp;
vector<vector<int>> ans;
temp.push_back(1);
ans.push_back(temp);

for(int level=1;level<numRows;level++){
    ans.push_back(generateRow(level, ans));
}
return ans;
}*/

};