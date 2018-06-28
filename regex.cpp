#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

/* Program to find the regular expression 
   from a given finite automata */

string regex(int p, int q, int k)
{
if (k == 0)
{	if (p == 1 && q==1)
     { return "e";  }
 
     if (p == 1 && q == 2)
     { return "a+b";}
      
	 if ( p == 1 && q== 3)
      { return "O"; }     //O represents null
	
     if (p == 2 && q==1)
      {  return "O"; }    //O represents null

     if (p == 2 && q==2)
      { return "a+e"; }
  
      if (p == 2 && q==3)
      {  return "b";   }
  
     if (p == 3 && q==1)
     {    return "a";  }
    
     if (p == 3 && q == 2)
     {   return "b";   }
 	
	 if (p == 3 && q == 3)
     {    return "e";  }
 }

 else
 {
	 while (k>0)
	 {
return "(" + regex(p,q,k-1) + ") U " + "(" + regex(p,k,k-1) + ")" + "(" + regex(k,k,k-1) + ")*" +"(" + regex(k,q,k-1) + ")";
	 }
 } 

}

int main ()
{  string x, y;
x = regex(1,1,3);  // state 1 is one of the two final states
y = regex(1,3,3);  // state 3 is one of the two final states

cout<<" The regular expression is:" <<endl;
cout<<x<<" U "<<y;                            // union of both the final states

return 0;
} 