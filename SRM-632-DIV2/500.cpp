#include <bits/stdc++.h>
using namespace std;

#define P first
#define Q second
#define pb push_back
typedef pair < int , int > ii ;
typedef long long LL ;

class PotentialGeometricSequence   {
   
   public :
   int numberOfSubsequences(vector <int> d){
   	   int sz , i, j, k, l ;
   	   sz = d.size() ;
   	   set < ii > ans ;
   	   for ( i = 0 ; i < sz ;i++)
   	   ans.insert(ii(i,i)) ;
       //cout <<"ayay\n" ;
   	   for ( j = 1 ; j < sz ;j++)
   	   ans.insert(ii(j-1,j)) ;

   	   for ( i = 0 ; i < sz ; i++){
   	   	   for ( j = 2 ; j < sz-i ; j++){
               // cout << i << " "<< j << endl;
                int diff = d[i+1]-d[i] ;
                int end = i + j ;
                bool yes = true ;
                while ( end > i ){
                    if( d[end]-d[end-1] != diff){ yes = false ; break ; };
                	end--;
                }
                if( yes ){
                	ans.insert(ii(i,i+j)) ;
                }
   	   	   }
   	   }
   	     //for ( set < ii > ::iterator it = ans.begin() ; it != ans.end() ; it++ ){
   	    //	cout << (*it).P <<" "<<(*it).Q << endl;
   	    
   	    return ans.size() ;
   }
};
