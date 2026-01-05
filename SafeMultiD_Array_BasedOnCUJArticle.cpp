#include <iostream>
using namespace std;

#include <stdio.h>
#include "SafeMultiD_Array_BasedOnCUJArticle.h"
     
int main()
{
     
 try{
  A1D<int,10> va1d;
  va1d[2] = 20;

     
  A2D<int,10,5> va2d;
  va2d[2][3] = 23;
  
     
  A3D<int,4,3,2> va3d;
  va3d[2][2][1]=231;
     
  //test out range
  //va1d[11] = 110;
  //va2d[2][5] = 23;
  //va3d[5][1][1]=234;
  
  
  int dim1 =va3d.dim();
  int low1 =va3d.begin();
  int high1= va3d.end();
  
  int dim2=va3d[low1].dim();
  int low2 =va3d[low1].begin();
  int high2 = va3d[low1].end();
 
  

     
  int dim3=va3d[low1][low2].dim();
     
  int low3 =va3d[low1][low2].begin();
  int high3 =va3d[low1][low2].end();
  
  
  printf("dim1=%2d dim2=%2d dim3=%d\n",dim1,dim2,dim3);
  
  printf("dim: %dX%dX%d\n",dim1,dim2,dim3);
     
     
  for( int i= low1; i<=high1; ++i)
   for( int j=low2; j<=high2; ++j)
    for( int k=low3; k<=high3; ++k)
    va3d[i][j][k] = (i*100+j)*100+k;
     
     
  for(int i= low1; i<=high1; ++i)
   for( int j=low2; j<=high2; ++j)
    for( int k=low3; k<=high3; ++k) {
     //printf("%2d%2d%2d = %d\n",i,j,k,va3d[i][j][k]);
     if(va3d[i][j][k] != (i*100+j)*100+k)
      printf("%2d%2d%2d != %d\n",i,j,k,va3d[i][j][k]);
    }
     
     
     
  puts("\nend");
  while(1);
 }
 catch(RangeException RE)
 {
  char buf[128];
  //bug RE.m_dim is always 1 . So ignore for now
  sprintf(buf,
  //"The %d-D(sub)array:\n  The subscript %d is out of range: %d:%d\n",
  "The subscript %d is out of range: %d:%d\n",
   RE.m_index,RE.m_low,RE.m_high);
  puts(buf);
 }
     
     
}


/*
int main() 
{
    cout << "Hello, World!";
    return 0;
}
*/