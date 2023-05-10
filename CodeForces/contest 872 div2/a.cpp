#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cnt[30];
    bool f;
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        // apple
        Node* r=root;
        for(auto i:word){
            if(!r->links[i-'a']){//null
                Node *ref=new Node();
                r->links[i-'a']=ref;
                r=ref;
                r->cnt[i-'a']++;
            }else{
                r=r->links[i-'a'];
                r->cnt[i-'a']++;
            }
        }
        r->f=true;
    }
    int startsWith(string prefix) {
        Node*r=root;
        for(auto i:prefix){
            if(r->links[i-'a']){
                r=r->links[i-'a'];
            }else{
                return 0;
            }
        }
        return r->cnt[prefix[prefix.size()-1]-'a'];
    }
    
};
int main()
{
    Trie *nxw=new Trie();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(a=="add"){
            nxw->insert(b);
        }else{
            cout<<nxw->startsWith(b)<<endl;;
        }
    }
    
    return 0;
}










// Sieve of Eratosthenes
/*
int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}


//vector<string> split(string s, char delimeter) {
//	vector <string> tokens; stringstream check1(s);
//	string intermediate;
//	while (getline(check1, intermediate, delimeter)) {
//		tokens.push_back(intermediate);
//	} 
//	return tokens;
//}

// factorize using seive

int N=10000007;
vi spf;
void seive(){
    spf.assign(N+1,1);
    for (int i = 2; i <= N; i++) {
        if (spf[i]==1) {// if i is prime
            spf[i]=i;
            for (int j = i * i; j <= N; j += i)
                if(spf[j]==1)spf[j] = i;
        }
    }
}
vi factorize(int n){
    vi ans;
    while(n>1){
        int fact=spf[n];
        ans.pb(fact);
        while(n%fact==0){
            n/=fact;
        }
    }
    return ans;
}
*/
// sum = xor + (2 * and)
/*

// NCR code
int MAXN;
vi factorial;
long long binomial_coefficient(int n, int k) {
    return factorial[n] * inv(factorial[k] * factorial[n - k] % mod) % mod;
}
void precomputeFactorials(){
    MAXN=100006;// give max n here
    factorial.assign(MAXN+5,1);
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    }
}
*/

// vector<int>prime_factors(int n){
// 	vector<int>ans;
// 	if(!(n%2))ans.push_back(2);
// 	while(!(n%2))n/=2;
// 	for(int i=3;i*i<=n;i+=2){
// 		if(n%i==0)ans.push_back(i);
// 		while(n%i==0)n/=i;
// 	}
// 	if(n>1)ans.push_back(n);
// 	return ans;
// }