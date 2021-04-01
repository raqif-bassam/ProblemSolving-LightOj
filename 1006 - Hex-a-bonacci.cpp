#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>

#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define i64 __int64
#define i32 __int32
#define i16 __int16
#define i8 __int8

/*
#define i64 long long int
#define %I64d %lld
*/

#define ll long long
#define u unsigned

#define pi acos(-1)
#define EFS -2147483650
#define INF 4294967295
#define EFS64 -4611686018427387905
#define INF64 9223372036854775807

#define SIZE 1000
#define MAX 100000

/*
int a, b, c, d, e, f;
int fn( int n ) {
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) );
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) );
    }
    return 0;
}
*/

int main()
{
	int test,cs,i;
	cin>>test;
	for(cs=1;cs<=test;cs++)
	{
		int x;
		u res[10005];
		for(i=0;i<6;i++) cin>>res[i];
		cin>>x;
		for(i=6;i<=x;i++)
			res[i]=(res[i-1]+res[i-2]+res[i-3]+res[i-4]+res[i-5]+res[i-6])%10000007;
		printf("Case %d: %u\n",cs,res[x]%10000007);
	}
	return 0;
}
