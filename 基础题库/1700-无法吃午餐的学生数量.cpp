#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<string.h>


using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int curstudentidx = -1;
        int cursandwiches = 0;
        int left1 = 0;
        for(auto & t:students) if(t) left1++;
        int left0 = students.size()-left1;
        while(1)
        {
            curstudentidx++;
            if(curstudentidx>=students.size()) curstudentidx = 0;
            if(students[curstudentidx]==2) continue;
            if(students[curstudentidx]==sandwiches[cursandwiches])
            {
                if(students[curstudentidx])  left1--;
                else left0--;

                students[curstudentidx] = 2;
                cursandwiches++;
            }
            if(left1==0)
            {
                while(!sandwiches[cursandwiches])
                {
                    cursandwiches++;
                    if(cursandwiches==sandwiches.size()) return 0;
                }
                return sandwiches.size()-cursandwiches;
            }
            if(left0==0)
            {
                while(sandwiches[cursandwiches])
                {
                    cursandwiches++;
                    if(cursandwiches==sandwiches.size()) return 0;
                }
                return sandwiches.size()-cursandwiches;
            }
            
        }
    }
};

int main()
{
    Solution slv;

    vector<int> student = {1,1,1,0,0,1};
    vector<int> sandwiches = {1,0,0,0,1,1};

    auto ans = slv.countStudents(student,sandwiches);
    cout<<ans;
    return 0;
}