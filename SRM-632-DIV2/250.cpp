#include <bits/stdc++.h>
using namespace std;

#define P first
#define Q second
#define pb push_back

typedef long long LL ;

class RunningAroundPark {
   
   public :
   int numberOfLap(int N, vector <int> d){
   	   int ans = 1 ;
   	   for (int i = 1 ; i < d.size() ; i++ )
       if( d[i] <= d[i-1] )
       ans++ ;

      return ans ;
   }
   
};
