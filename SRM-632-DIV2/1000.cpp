#include <bits/stdc++.h>
using namespace std;

#define P first
#define Q second
#define pb push_back

#define MOD 1000000007
typedef long long LL ;
typedef pair < int , int > ii ;
map < ii , int > DP ;


vector < int > A ;

int rec ( int cur , LL prod , LL GD , int size ){

	if( prod > GD )
	return 0 ; 
    
    if( prod > 0 && GD%prod != 0)
    return 0 ;
   
    if( prod == GD && cur > size )
    return 1 ;
   
    if( cur > size )
    return 0 ;
    
    ii state = ii(cur,prod) ;
    if( DP.count(state) == 0)
    DP[state] = -1;
    
   //cout << cur <<" "<<prod<<" "<<GD<<" "<<size << endl;
    if( DP[state] != -1)
    return DP[state] ;
    DP[state] = 0 ; 
    if( prod == 0){
            DP[state] += rec(cur+1 , 0 , GD , size) ;
		    
		    DP[state] += rec( cur+1 , A[cur], GD , size) ;
		    if(DP[state] >= MOD)
     	    DP[state] -= MOD ; 
		    
    }  
    else{
     DP[state] += rec(cur+1 , prod*A[cur] , GD , size) ;
     DP[state] += rec( cur+1 ,prod, GD , size) ;
        if(DP[state] >= MOD)
     	DP[state] -= MOD ;
    }
    return DP[state] ;
}

class  GoodSubset {
   
   public :
   int numberOfSubsets(int goodValue, vector <int> d){
      LL GD = goodValue ;
      for ( int i = 0 ; i < d.size() ;i++)
      A.pb(d[i]) ;
      bool f =true ;
      int ans = rec(0,0,GD , d.size()-1 );
      ans = ans%MOD ; 
     // cout <<DP.size() << endl;
      return (int)ans ;

   }

};
