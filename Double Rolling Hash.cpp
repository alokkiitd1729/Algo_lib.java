/*
          https://www.spoj.com/problems/ADAPHOTO/     
          https://leetcode.com/problems/longest-common-subpath/
          
    Note - Here we are using two mod for substring s[i...j] 
    its hashing is defined from a pair <hash1,hash2> == <mod1,mod2> 
    Also no need to choose two different base (probabilty of collision is very low) 
    BUT I will say choose diff base also(will create 0 additional pain so why shouldn'e we go for it :))
    
    some ex.
    (1). Find all pairs of palindromic substring in O(NlogN) (bs at all index for largest palindrom)
    .... And many more(most of string problem!) in O(N(logN)^2) or O(NlogN) or O(N)
        
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,max=1000000;

//##################################################   (choose base, prime mod1,mod2)  #############################################################
int b1=4001,b2=13777,mod1=1000000007,mod2=1000173169;    // Note go for just single hash(1 mod) first if got WA then go for double hash
/*
          Note 
          you can choose large prime of around 15 digit and base of upto 3 digit (15+3=18 will fit in long) or (13 digit prime, upto 5 digit base)
          And then we DON'T need double hashing because probabilty of success will be much higher with 15/13 digit prime than 1e9+7. 
        
          some Beautiful primes - (15 digit)= 311111111111113, 777737777777777.
                                  (13 digit)= 3111111111113, 9999991111111.                    (just careful after base multiplication it should fit in Long)

*/
//##################################################################################################################################
vector<int> h1(max1),h2(max1);
vector<int> p1(max1),p2(max2);
void solve(){
    string s;
    cin>>s;
    n=s1.size();
    p1[0]=p2[0]=1;
    for(int i=1;i<max1;i++){
        p1[i]=1LL*p1[i-1]*b1%mod1;    // base1, mod1
        p2[i]=1LL*p2[i-1]*b2%mod2;        // base2, mod2
    }
    h1[0]=h2[0]=s[0];
    for(int i=1;i<n;i++){
        h1[i]=(1LL*h1[i-1]*b1+s[i])%mod1;
        h2[i]=(1LL*h2[i-1]*b2+s[i])%mod2;
    }
    for(int i=1;i+m1-1<n;i++){
        int curr_hash1=(h1[i+m1-1]-1LL*h1[i-1]*p1[m1])%mod1;     // hash value for length m1 starting from index = i
        int curr_hash2=(h2[i+m1-1]-1LL*h2[i-1]*p2[m1])%mod2;
        if(curr_hash1<0)curr_hash1+=mod1       // Note we are subtracting the 2nd term above so MAKE SURE IT'S POSITIVE
        if(curr_hash2<0)curr_hash1=+=mod2;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
} 
