int Solution::solve(vector<int> &A, int B) {
    int i, n, left, right, mx = INT_MIN;
    vector<int> lsum(A.begin(),A.end()), rsum(A.begin(),A.end());
    
    n = A.size();
     
    //populate the left sum
    for(i=1; i<n; i++)
    {
        lsum[i] += lsum[i-1];
    }
    
    //populate the right sum
    for(i=n-2; i>=0; i--)
    {
        rsum[i] += rsum[i+1];
    }
    
    //calculate the ans
    for(i=0; i<=B; i++)
    {
        // take 0 or max B element form left
        left = i == 0 ? 0 : lsum[i-1];
        
        //take 0 or max B remaining element from right
        right = i == B ? 0 : rsum[n-(B-i)];
        
        mx = max(mx, left + right);
    }
    
    return mx;
    
    
}
