#include<iostream>
#include<vector>

using namespace std;

template<typename T=int>
void showvec(vector<T> vec,int flag=1)
{
    for(auto & a:vec) cout<<' '<<a;
    if(flag==1) cout<<endl;
    if(flag==2) cout<<", ";
}

template<typename T=int>
void showvec2(vector<vector<T>> vec,int D2flag=1,int D1flag=1)
{
    for(auto & a:vec) showvec<T>(a,D1flag);
    if(D2flag==1) cout<<endl;
    if(D1flag==1 && D2flag==1) cout<<endl;
}

vector<int> str2vecI(string & str)
{
    vector<int> ans;
    int flag = 0;
    int cur = 0;
    for(auto & ch:str)
    {
        if(flag == 0)
        {
            if(ch>='0'&&ch<='9')
            {
                cur+=(int)(ch-'0');
                flag = 1;
            }
        }
        else
        {
            if(ch>='0'&&ch<='9')
            {
                cur=cur*10+ch-'0';
            }
            else
            {
                flag = 0;
                ans.push_back(cur);
                cur=0;
            }
        }
    }
    return ans;
}

vector<vector<int>> str2vec2I(string & str)
{
    vector<vector<int>> ans;
    int flag;
    string str2;
    for(auto & ch:str)
    {
        str2.push_back(ch);
        if(ch==']')
        {
            if(str2.size()==1) return ans;
            vector<int> vec= str2vecI(str2);
            ans.push_back(vec);
            str2.clear();
        }
    }
    return ans;
}
// 将所有外面能够到达的全部置0
class Solution {
    int gridsize_m;
    int gridsize_n;
    void turnlandto0(vector<vector<int>>& grid,int x,int y)
    {
        if(grid[x][y]==0) return;
        grid[x][y]=0;
        if(x>0) turnlandto0(grid,x-1,y);
        if(y>0) turnlandto0(grid,x,y-1);
        if(x<gridsize_m-1) turnlandto0(grid,x+1,y);
        if(y<gridsize_n-1) turnlandto0(grid,x,y+1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        gridsize_m = grid.size();
        gridsize_n = grid[0].size();
        
        for(int i=0;i<gridsize_m;i++)
        {
            turnlandto0(grid,i,gridsize_n-1);
            turnlandto0(grid,i,0);
        }
        
        for(int i=1;i<gridsize_n-1;i++)
        {
            turnlandto0(grid,gridsize_m-1,i);
            turnlandto0(grid,0,i);
        }
        int ans=0;
        for(int i=1;i<gridsize_m-1;i++)
            for(int j=1;j<gridsize_n-1;j++)
                if(grid[i][j]==1) ans++;
        return ans;
    }
};

class UnionFind {
public:
    UnionFind(const vector<vector<int>> & grid) {
        int m = grid.size(), n = grid[0].size();
        this->parent = vector<int>(m * n);
        this->onEdge = vector<bool>(m * n, false);
        this->rank = vector<int>(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int index = i * n + j;
                    parent[index] = index;
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        onEdge[index] = true;
                    }
                }
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void uni(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
                onEdge[rootx] = onEdge[rootx] | onEdge[rooty];
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
                onEdge[rooty] = onEdge[rooty] | onEdge[rootx];
            } else {
                parent[rooty] = rootx;
                onEdge[rootx] = onEdge[rootx] | onEdge[rooty];
                rank[rootx]++;
            }
        }
    }

    bool isOnEdge(int i) {
        return onEdge[find(i)];
    }
private:
    vector<int> parent;
    vector<bool> onEdge;
    vector<int> rank;    
};

class Solution_KEY {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(grid);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int index = i * n + j;
                    if (j + 1 < n && grid[i][j + 1] == 1) {
                        uf.uni(index, index + 1);
                    }
                    if (i + 1 < m && grid[i + 1][j] == 1) {
                        uf.uni(index, index + n);
                    }
                }
            }
        }
        int enclaves = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 1 && !uf.isOnEdge(i * n + j)) {
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};

int main()
{
    Solution slv;
    string str= "[[0,0,1,1,1,0,1,1,1,0,1],[1,1,1,1,0,1,0,1,1,0,0],[0,1,0,1,1,0,0,0,0,1,0],[1,0,1,1,1,1,1,0,0,0,1],[0,0,1,0,1,1,0,0,1,0,0],[1,0,0,1,1,1,0,0,0,1,1],[0,1,0,1,1,0,0,0,1,0,0],[0,1,1,0,1,0,1,1,1,0,0],[1,1,0,1,1,1,0,0,0,0,0],[1,0,1,1,0,0,0,1,0,0,1]]";
    vector<vector<int>> grid = 
    // {
    //     {0,0,0,0},
    //     {1,0,1,0},
    //     {0,1,1,0},
    //     {0,0,0,0}
    // };
    str2vec2I(str);
    showvec2(grid);
    int ans = slv.numEnclaves(grid);
    showvec2(grid);
    return ans;
}