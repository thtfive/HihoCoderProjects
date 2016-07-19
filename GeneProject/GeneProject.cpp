#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    map<char,int>chToInt;
    chToInt['A']=0;
    chToInt['C']=1;
    chToInt['G']=2;
    chToInt['T']=3;
    int T;
    freopen("input.txt","r",stdin);
    cin >> T;
    while (T--)
    {
        string geneStr;
        int L;
        cin >> geneStr >> L;
        int len = geneStr.length();
        int times[4];
        vector<bool>flag(len,false);
        int result = 0;
        for (int i = 0; i < L; ++i)
        {
            if(flag[i]==false)
            {
                memset(times,0,sizeof times);
                int counter = 1;
                flag[i] = true;
                int k = len - L + i;
                times[chToInt[geneStr[i]]]=1;
                while (k >=0 && k < len && flag[k] == false)
                {
                    flag[k] = true;
                    ++times[chToInt[geneStr[k]]];
                    ++counter;
                    k += len - L;
                }
                int maxnum = 0;
                for (int j = 0; j < 4; ++j)
                {
                    maxnum = max(maxnum,times[j]);
                }
                result += counter - maxnum;
            }
        }
        cout << result << endl;
    }
    return 0;
}
