#include "/Users/dimazhylko/CPPProjects/bits/stdc++.h"
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define inf (1<<30) - 1

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector< string > S(n);

    for(int i = 0;i<n;i++){
    	cin>>S[i];
    }

    string s;
    cin>>s;

    vector<int> DP(s.length()+1, inf);
    DP[0] = 0;

    for(int i = 1;i<=s.length();i++){
    	for(int j = 0;j<n;j++){
    		if(S[j].length()>i)continue;

    		if(s.substr(i-S[j].length(), S[j].length()) == S[j]){
    			DP[i] = min( DP[i-S[j].length()] + 1, DP[i] );
    		}
    	}
    }

    if(DP[s.length()] < inf)cout<<DP[s.length()]<<endl;
    else cout<<"Nie da się"<<endl;

	return 0;
}