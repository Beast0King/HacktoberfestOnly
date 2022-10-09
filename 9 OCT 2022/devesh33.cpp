//GFG POTD 9 OCT 2022
//https://practice.geeksforgeeks.org/problems/help-ishaan5837/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	
	bool isPrime(int n) //For checking if the given number is prime or not in root n time
	{
	    if(n <=1)   return 0;
	    for(int i=2; i*i<=n; i++)
	    {
	        if(n%i == 0)    return 0;
	    }
	    return 1;
	}
	int NthTerm(int n){
	    // Code here
	    if(isPrime(n))  return 0;
	    int res1=INT_MAX;
	    int res2 = INT_MAX;
	    for(int i=n; i>=1; i--) //For checking prime number nearest to n below it
	    {
	        if(isPrime(i))
	        {
	            res1 = min(res1,n-i);
	            break;
	        }
	    }
	    for(int i=n; i<=100000; i++)//For checking prime number nearest to n above it
	    {
	        if(isPrime(i))
	        {
	            res1 = min(res1,i-n);
	            break;
	        }
	    }
	    return min(res1,res2);//Result will be minimum of the two
	}
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.NthTerm(n) << "\n";
    }
}