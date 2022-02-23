#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int i = 0;
        for(int i=0,j=0;i<dominoes.size();)
        {
            j=i;
            //找一下一张已经倒下的骨牌
            while(dominoes[j]=='.'&&j<dominoes.size())
            {
                j++;
            }
            //没有了
            if(j==dominoes.size()) return dominoes;
            //下一张骨牌向左倒,则都向左倒
            if(dominoes[j]=='L')
            {
                while(i<j)
                {
                    dominoes[i]='L';
                    i++;
                }
                i++;
            }
            // 如果下一张骨牌向右倒的，则再去找下一张骨牌
            else if(dominoes[j]=='R')
            {
                i = j+1;
                j++;
                while(dominoes[j]=='.'&&j<dominoes.size())
                {
                    j++;
                }
                if(j==dominoes.size())//如果下一张没有了
                {
                    while(i<j)
                    {
                        dominoes[i] = 'R';
                        i++;
                    }
                    return dominoes;
                }
                if(dominoes[j] == 'R') // 如果下一张还是R，那就往右去了
                {
                    while(i<j)
                    {
                        dominoes[i] = 'R';
                        i++;
                    }
                }
                else if(dominoes[j] == 'L')
                {
                    for(int m=0;m<(j-i)/2;m++)
                    {
                        dominoes[i+m]='R';
                        dominoes[j-1-m]='L';
                    }
                    i=j+1;
                }
            }
            cout<<i<<" : "<<dominoes<<endl;
        }
        return dominoes;
    }
};

int main()
{
    Solution slv;
    string dominoes = 
    "..L..L.R.L....R.....R...L...R...L...L...R..";
    string ans = slv.pushDominoes(dominoes);
    cout<<ans;
    return 0;
}