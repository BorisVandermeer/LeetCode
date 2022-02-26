//showvecfuncs:
//Type = 1  means \n
//Type = 2  means ", "
//Type = 3  means " "
//else      nothing

template<typename T=int>
void showvec(vector<T> vec,int D1Type=1,int D0Type = 3)
{
    if(D0Type = 2) for(auto & a:vec) cout<<a<<", ";
    else if(D0Type = 3) for(auto & a:vec) cout<<a<<' ';
    else for(auto & a:vec) cout<<a;
    if(D1Type==1) cout<<endl;
    if(D1Type==2) cout<<", ";
    if(D1Type==3) cout<<" ";
}

template<typename T=int>
void showvec2(vector<vector<T>> vec,int D2Type = 1,int D1Type=1)
{
    for(auto & a:vec) showvec<T>(a,D1Type);
    if(D2Type==1) cout<<endl;
}

// 没有调试
template<typename T=int>
void showvec3(vector<vector<vector<T>>> vec,int D3Type=1,int D1Type=3)
{
    for(auto b:vec) for(auto & a:b) showvec<T>(a,1,D1Type);
    if(D3Type ==1) cout<<endl;
}

vector<int> str2vecI(string str)
{
    vector<int> ans;
    int flag = 0;
    int flag2 = 1;
    int cur = 0;
    for(auto & ch:str)
    {
        if(ch=='-') flag2 = -1;
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
                if(flag2==-1) cur=-cur;
                ans.push_back(cur);
                flag2=1;
                cur=0;
            }
        }
    }
    return ans;
}

vector<vector<int>> str2vec2I(string str)
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