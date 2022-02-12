template<typename T=int>
void showvec(vector<T> vec,int flag=1)
{
    for(auto & a:vec) cout<<' '<<a;
    if(flag==1) cout<<endl;
    if(flag==2) cout<<", ";
}

template<typename T=int>
void showvec2(vector<vector<T>> vec,int flag=1)
{
    for(auto & a:vec) showvec<T>(a,2);
    if(flag==1) cout<<endl;
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