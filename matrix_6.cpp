/*You are required to complete this method*/
int MAH(vector<int> a,int n)
{
    vector<int>left;
    stack<pair<int,int>>s;
    int m=n;
    // int pseudo=-1;
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        {
            left.push_back(-1);
        }
        else if(s.size()>0&&s.top().first<a[i])
        {
            left.push_back(s.top().second);
        }
        else if(s.size()>0&&s.top().first>=a[i])
        {
            while(s.size()>0&&s.top().first>=a[i])
            {
                s.pop();
            }
            if(s.size()==0)
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(s.top().second);
            }
        }
        s.push({a[i],i});
    }
    vector<int>right;
    stack<pair<int,int>>s1;
    // int pseudo=n;
    for(int i=n-1;i>=0;i--)
    {
        if(s1.size()==0)
        {
            right.push_back(m);
        }
        else if(s1.size()>0&&s1.top().first<a[i])
        {
            right.push_back(s1.top().second);
        }
        else if(s1.size()>0&&s1.top().first>=a[i])
        {
            while(s1.size()>0&&s1.top().first>=a[i])
            {
                s1.pop();
            }
            if(s1.size()==0)
            {
                right.push_back(m);
            }
            else
            {
                right.push_back(s.top().second);
            }
        }
        s1.push({a[i],i});
    }
    
    reverse(right.begin(),right.end());
    
    int width[n];
    for(int i=0;i<n;i++)
    {
        width[i]=right[i]-left[i]-1;
    }
    int ans[n];
    for(int i=0;i<n;i++)
    {
        ans[i]=a[i]*width[i];
    }
    int mx=ans[0];
    for(int i=1;i<m;i++)
    {
        mx=max(mx,ans[i]);
    }
    return mx;
}

int maxArea(int M[MAX][MAX], int n, int m) 
{
    vector<int> v;
    int mx;
    for(int j=0; j<m; j++)
    {
        v.push_back(M[0][j]);
        mx=MAH(v,m);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j] = 0)
            {
                v[j]=0;
            }
            else
            {
                v[j]=v[j]+M[i][j];
                
            }
        }
        mx=max(mx,MAH(v,m));
        
    }
    return mx; 
    
}
