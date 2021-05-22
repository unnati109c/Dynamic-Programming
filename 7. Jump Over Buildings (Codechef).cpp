/* Jump Over Buildings 
 
There are N buildings and the heights of the buildings are h1,h2,…,hN. Poly is standing on building 1 and wants to go to building N and to do the following operation 
any number of times, If Poly is currently on building i then Poly can jump on building i+1,i+2,…,i+K. Here, a cost of |hi−hj| is incurred, where j is the building to land on.
Where K is fixed for all operations. Help Poly to find the minimum possible total cost incurred.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers h1,h2,…,hN.
Output
For each test case, print a single line containing one integer — the minimum possible total cost incurred.

Constraints
1≤T≤10
1≤N≤105
1≤K≤100
1≤hi≤109 for each valid i

Example Input
2
5 3
4 4 2 5 6
4 1
1 2 3 5
Example Output
2
4

Explanation
Example case 1: Poly can jump from building 1 to 2 and then from building 2 to 5.

Example case 2: Poly needs to jump over all the buildings.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define inf             1e18
#define vi              vector<ll>

int main() {
	
	int t;
	cin>>t;
	while(t--) {
		ll n, k;
		cin>>n>>k;

		vi h(n);
		for(int i=0;i<n;i++) 
			cin>>h[i];

		vi dp(n, inf);
		// dp[i] -> min cost to reach from 0-i
		dp[0] = 0;
		for(int i=1;i<=n-1;i++) 
		{
			for(int j=1;j<=k;j++) 
			{
				if(i - j < 0) 
					break;

				dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
			}
		}
		cout<<dp[n-1]<<endl;
	}

	return 0;
}
