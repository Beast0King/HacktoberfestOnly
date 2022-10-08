//GFG POSD
//https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1

#include <bits/stdc++.h>
using namespace std;
class Solution {  
public:
    int solve(string st, int k)    
    {        
        unordered_map<char,int>mp;
        int cnt=0,s=0;
        for(int i=0; i<st.size(); i++)
        {
            mp[st[i]]++;    //Adding each character to map while traversing
            if(i+1 >= k)
            {
                if(mp.size() == k-1)    //If no of distinct character matches with k-1 then we increase count
                {                    
                    cnt++;                
                }
                //Deleting the previous character
                mp[st[s]]--;
                if(mp[st[s]] == 0)
                    mp.erase(st[s]);
                s++;         //Moving the window forward   
            }        
        }        
        return cnt;    
    }
    int countOfSubstrings(string S, int k) 
    {    
        return solve(S,k);
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string S;
        int K;
        cin >> S;
        cin >> K;
        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}