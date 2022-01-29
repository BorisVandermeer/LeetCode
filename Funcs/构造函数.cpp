#include<iostream>
#include<vector>
#include<string>

using namespace std;

//解答类模板
class Solution{
public :
    int solve()
    {
        return 0;
    }
};
/********数据结构的构建**********/
//对于向量的构建
vector<int> vector_generate()
{
    vector<int> vec={0,0,0};
    return vec;
}

//字符串构建
string string_generate()
{
    string str("This is a string");
    return string();
}

/********可视化函数**********/
template<typename T>
void show_vec(vector<T> vec)
{
    for(auto i : vec) cout<<i<<endl;
}

//主函数模板
int main()
{   
    Solution slv;
    auto ans = slv.solve();
    //cout<<ans<<endl; //String 
    return 1;
}
