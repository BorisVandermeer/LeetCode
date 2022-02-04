#include<iostream>
#include<vector>

using namespace std;

// 能求解更多
class Solution_1 {
private:
    vector<int> F_List;
public:
    int findMinFibonacciNumbers(int k){
        F_List.push_back(0);
        F_List.push_back(1);
        int tmp = 1;
        int Listsize = 2;
        while(tmp<=k)
        {
            tmp = F_List[Listsize-1]+F_List[Listsize-2];
            F_List.push_back(tmp);
            Listsize++;
        }
        // for(auto t:F_List)
        // {
        //     cout<<t<<' ';
        // }
        //cout<<endl<<"FindNumber : "<<F_List[Listsize-2]<<endl;
        return (GetMinFibonacciNumbers(k-F_List[Listsize-2],Listsize-2)+1);
    }

    int GetMinFibonacciNumbers(int k,int end)
    {
        if(k==0) return 0;
        if(k==1) return 1;
        int begin = 0;
        // 使用二分法查找那个比它小的那一个
        while(begin != end)
        {
            int cur = (begin+end)/2;
            //cout<<"    From "<<begin<<" To "<<end<<" Chose "<<F_List[cur]<<" To COMP with "<<k<<endl;
            if(F_List[cur]==k) return 1;
            if(F_List[cur]>k) end = cur;
            if(F_List[cur]<k)
            {
                if(begin==cur) begin = end;
                else begin = cur;
            }
        }
        //cout<<"FindNumber : "<<F_List[begin-1]<<endl;
        return (1+GetMinFibonacciNumbers(k-F_List[begin-1],begin));
    }
};

// 先枚举然后搜
class Solution
{
    vector<int> F_List= {
            1, 2, 3, 5, 8,
            13, 21, 34, 55, 89,
            144, 233, 377, 610, 987,
            1597, 2584, 4181, 6765,
            10946, 17711, 28657, 46368, 75025,
            121393, 196418, 317811, 514229, 832040,
            1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986,
            102334155, 165580141, 267914296, 433494437, 701408733,1134903170
    };
public:
    int findMinFibonacciNumbers(int k){
        for(auto t:F_List)
        {
            cout<<t<<' ';
        }
        cout<<endl;
        return GetMinFibonacciNumbers(k,F_List.size()-1);
    }

    int GetMinFibonacciNumbers(int k,int end)
    {
        if(k==0) return 0;
        if(k==1) return 1;
        int begin = 0;
        // 使用二分法查找那个比它小的那一个
        while(begin != end)
        {
            int cur = (begin+end)/2;
            //cout<<"    From "<<begin<<" To "<<end<<" Chose "<<F_List[cur]<<" To COMP with "<<k<<endl;
            if(F_List[cur]==k) return 1;
            if(F_List[cur]>k) end = cur;
            if(F_List[cur]<k)
            {
                if(begin==cur) begin = end;
                else begin = cur;
            }
        }
        cout<<"FindNumber : "<<F_List[begin-1]<<"  Remains"<<k-F_List[begin-1]<<endl;
        return (1+GetMinFibonacciNumbers(k-F_List[begin-1],begin));
    }

};

int main()
{
    Solution slv;
    int k = 40;
    cout<<433494437+701408733<<endl;
    return slv.findMinFibonacciNumbers(991244035);
}