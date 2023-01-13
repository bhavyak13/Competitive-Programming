#include <bits/stdc++.h> 
using namespace std;
bool knows(int A, int B){
    return true;
}
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

    bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int>stk;
	for(int i=0;i<n;i++){
		stk.push(i);
	}
	while(stk.size()>1){
		auto a=stk.top();
		stk.pop();
		auto b=stk.top();
		stk.pop();
		int x=knows(a,b);
		int y=knows(b,a);
		// if a knows b -> a is not our answer
		if(x)stk.push(b);
		// if b knows a -> b is not our answer
		else if(y)stk.push(a);
		// else both doesnt know eachother, none of them can be celeb as if A would have been celeb B must know A, and vice versa
	}
	if(stk.empty())return -1;
	auto x=stk.top();
	for(int i=0;i<n;i++){
		if(i!=x){
			if(!knows(i,x)||(knows(x,i)))return -1;
		}
	}
	return x;
}