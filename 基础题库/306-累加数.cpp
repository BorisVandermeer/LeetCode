#include<iostream>
#include<vector>
#include<string>

using namespace std;

//无法解决int存储不下的问题
//使用了long long 才存储下
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int v;
        if(num.length()<3) return false;
        long long val_1 = 0;
        for(int i=0;i<num.length()/2;i++)
        {
            val_1 = val_1*10+ (int)num[i]-(int)'0';
            long long val_2 = 0;
            for(int j = i+1; j<=(num.length()/2-i/2)+i; j++)
            {
                //选取第二个数字
                val_2 = val_2*10+ (int)num[j]-(int)'0';
                //处理这两个数字为基础可以处理一系列数字
                long long posval = val_2;
                long long posposval = val_1;
                int cur_idx = j;
                while(1)
                {
                    int breakflag = 0;
                    //计算出下个目标数
                    int tarval = posval+posposval;
                    int tarval_backup = tarval;
                    int realval = 0;
                    //获取一个数
                    if(!tarval)
                    {
                        cur_idx++;
                        realval = realval*10+(int)num[cur_idx]-(int)'0'; 
                    }
                    else if(num[cur_idx+1]=='0')
                    {
                        realval=0;
                        cur_idx++;
                    }
                    else while(tarval)
                    {
                        cur_idx++;
                        if(cur_idx>num.length()) break;
                        tarval /= 10;
                        realval = realval*10+(int)num[cur_idx]-(int)'0';  
                    }
                    tarval = tarval_backup;
                    cout<<"pospos:"<<posposval<<"; pos:"<<posval<<"; target:"<<tarval<<"; real:"<<realval<<endl;
                    if(tarval==realval)
                    {
                        if(cur_idx==num.length()-1) return true;
                        posposval = posval;
                        posval = tarval;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                cout<<"flag-j:"<<j<<"; flag-i:"<<i<<"; val1:"<<val_1<<"; val_2:"<<val_2<<endl;
                cout<<num.length()/2-i/2<<"    "<<num.length()/2<<endl;
                if(val_2==0)
                {
                    break;
                }
            }
            if(val_1==0) break;
        }
        return false;
    }
};


int main()
{   
    Solution slv;
    auto ans = slv.isAdditiveNumber("199111992");
    cout<<endl<<endl<<ans<<endl; //String 
    return 1;
}
