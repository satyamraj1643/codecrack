#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bk(n);
    vector<int> ans;
    map<pair<int, int>, int> pc;

    for (int i = 0; i < n; i++)
    {
        cin >> bk[i];
    }

    bool first = true;
    int k = n;
    while (k > 1)
    {
        vector<int>b;
        if(first){
            b = bk;
            first = false;
        }
        else{
            b = ans;
            ans.resize(0);
        }
        
       
        for (int i = 0; i < b.size() - 1; i++)
        {
            pair<int, int> key = make_pair(b[i], b[i + 1]);
            auto it = pc.find(key);
            if (it != pc.end())
            {
                ans.push_back(it->second);
            }
            else
            {
                pc[{b[i], b[i + 1]}] = b[i] ^ b[i + 1];
                ans.push_back(b[i] ^ b[i + 1]);
            }
        }

        for(auto it: ans)cout << it << " ";
        cout << endl;

        k--;
    }

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
