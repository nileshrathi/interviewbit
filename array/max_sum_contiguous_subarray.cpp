int Solution::maxSubArray(const vector<int> &A) {

    int start=0;
    int end=0;
    int currmax=0;
    int max=0;
    while(end<A.size()-1)
    {
        currmax=currmax+A[end];
        end++;

        if(currmax>max)
        {
            max=currmax;
        }

        while(currmax<0)
        {
            currmax=currmax-A[start];
            start++;    
        }

        if(start>end)
        {
            end=start;
        }
    }

    if(max==0)
    {
        return *min_element(A.begin(),A.end());
    }
    return max;
    
    
}
