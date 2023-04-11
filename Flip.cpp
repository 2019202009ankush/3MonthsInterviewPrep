vector<int> Solution::flip(string A) {
    int i, l, r, gl = -1, gr =-1, cost = 0, gcost = 0, n = A.size();
    
    // consider each zero adding a point and 1 reducing a point
    // if points goes below 0 then invalid window
    // alywas update the window only if window 
    // size becomes more than previous one
    
    l = 0;
    
    for(i=0; i<n; i++)
    {
        cost += A[i] == '0' ? 1 : -1;
        
        // cost < 0 invalid window
        if(cost < 0)
        {
            cost = 0;
            l = i+1; // this is consider the leftmost index 
            if (l == n)
                break;
        }
        else if (cost > gcost)
        {
            gcost = cost;
            gl = l;
            gr = i; //right will only update if there is cost update
        }
    }
    
    if (gl == -1) return {};
    else return {gl+1, gr+1};
    
    
}
