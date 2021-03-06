// O(sum*n)

#include<stdio.h>

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum_re(int set[], int n, int sum)
{
    // Base Cases
    if(sum == 0)
        return true;
    if(n ==0 && sum != 0)
       return false;
    
    // If last element is greater than sum, then ignore it
    if(set[n-1] > sum)
        return isSubsetSum_re(set, n-1, sum);
        
    /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
    return isSubsetSum_re(set, n-1, sum) || isSubsetSum_re(set, n-1, sum - set[n-1]);
}

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum_dp(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    bool subset[sum+1][n+1];
    
    // If sum is 0, then answer is true
    for(int i=0; i<=n; i++)
        subset[0][i] = true;
    
    // If sum is not 0 and set is empty, then answer is false
    for(int i=1; i <=sum; i++)
        subset[i][0] = false;
    
     // Fill the subset table in botton up manner
    for(int i=1; i<=sum; i++)
    {
        for(int j =1; j<=n; j++)
        {
            subset[i][j] = subset[i][j-1];
            if(i >= set[j-1])
                subset[i][j] = subset[i][j] || subset[i - set[j-1] ] [j-1];
        }
    }
}

// Driver program to test above function
int main()
{
  int set[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(set)/sizeof(set[0]);
  
  if (isSubsetSum_re(set, n, sum) == true)
     printf("Recursive: Found a subset with given sum\n");
  else
     printf("Recursive: No subset with given sum\n");
   
   if (isSubsetSum_dp(set, n, sum) == true)
     printf("DP: Found a subset with given sum\n");
  else
     printf("DP: No subset with given sum\n");
  return 0;
}