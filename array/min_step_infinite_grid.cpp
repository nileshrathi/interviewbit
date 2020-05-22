int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int count=0;
    for(int i=0;i<A.size()-1;i++)
    {
        int diffx=(A[i+1]-A[i]);
        int diffy=(B[i+1]-B[i]);
        int mindiff=min(abs(diffx),abs(diffy));
        int dirx=1;
        int diry=-1;
        if(diffx>=0)
        {
            dirx=1;
        }
        else
        {
            dirx=-1;
        }

        if(diffy>=0)
        {
            diry=1;
        }
        else
        {
            diry=-1;
        }

        count=count+mindiff;
        int tempx=A[i]+(dirx)*(mindiff);
        int tempy=B[i]+(diry)*(mindiff);
        if(mindiff==abs(diffx))
        {
            count=count+abs(B[i+1]-tempy);
        }
        else if(mindiff==abs(diffy))
        {
            count=count+abs(A[i+1]-tempx);
        }

            
    }
    return count;
}
