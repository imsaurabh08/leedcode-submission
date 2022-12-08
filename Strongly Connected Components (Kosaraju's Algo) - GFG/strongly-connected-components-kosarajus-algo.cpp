//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//sorting acc to finishing time
	void dfs(int node,vector<int> adj[],vector<int>&vis,stack<int>&st)
	{
	    
	 vis[node]=1;
	 
	 for(auto adjnode:adj[node])
	 {
	     if(!vis[adjnode])
	     {
	         dfs(adjnode,adj,vis,st);
	     }
	 }
	 st.push(node);
	
	    
	}
	
	void dfs2(int node,vector<int> adjT[],vector<int>&vis)
	{
	    vis[node]=1;
	    for(auto adjnode:adjT[node])
	 {
	     if(!vis[adjnode])
	     {
	         dfs2(adjnode,adjT,vis);
	     }
	 }
	 
	}
	
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,st);
            }
        }
        
        
        //reversing the edges
        vector<int> adjT[V];
        
        for(int i=0;i<V;i++)
    {
        vis[i]=0;  //for reusing the visited array
        for(auto it:adj[i])
        {
            
            adjT[it].push_back(i);
        }
    }
    
    int scc=0;
    
    while(!st.empty())
    {
        auto t=st.top();
        st.pop();
        if(!vis[t])
        {
            dfs2(t,adjT,vis);
            scc++;
        }
    }
        return scc;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends