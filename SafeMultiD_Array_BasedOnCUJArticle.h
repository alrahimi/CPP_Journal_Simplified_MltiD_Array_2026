
/*
Based On publsihed in the following July 1997
https://jacobfilipp.com/DrDobbs/articles/CUJ/1997/9707/rahimi/list1.htm
https://jacobfilipp.com/DrDobbs/articles/CUJ/1997/9707/rahimi/list2.htm


*/

#include<iostream>

using namespace std;

//Listing 1: Defines template array class


/*
make it like boost.Just type and size are declared
typedef boost::multi_array<double, 2> array_type;
*/

class RangeException
{
public:
 RangeException(int dim,int low, int high, int index) 
 {
  m_dim = dim;
  m_low = low;
  m_high = high;
  m_index = index;
 }
     
 int m_dim,m_low,m_high,m_index;
};
     
template <class Type,
size_t size ,int D=1> class A1D 
{
public:
int low=0;
int high = size -1;
int m_dim =1;
     
 Type& operator[](const int i)
 {
  if(i>=size)
  {
    //throw(RangeException(m_dim,0,size-1,i));
    throw(RangeException(dim(),0,size-1,i));
  }
     
  return element[i];
 }
     
     
 int begin() const {return low;}
 int end()   const {return high;}
 int dim()   const {return m_dim;}
     
private:
 Type element[size];
};
     
template <class Type,  
 size_t size_1,
 size_t size_2,int D=2> 
 class A2D : public A1D<A1D<Type,size_2>,size_1,D>
{
  int m_dim =2;
  public:
  int dim()   const {return m_dim;}
     
     
};
     
template <class Type, 
 size_t size_1,
 size_t size_2,
 size_t size_3, int D=3> 
 class A3D : public A1D<A2D<Type,size_2,size_3>,size_1>
{
  int m_dim =3;
  public:
  int dim()   const {return m_dim;}
     
 
     
};

template <class Type, 
 size_t size_1,
 size_t size_2,
 size_t size_3,
 size_t size_4,
 int D=4> 
 class A4D : public A1D<A3D<Type,size_2,size_3,size_4>,size_1>
{
  int m_dim =4;
  public:
  int dim()   const {return m_dim;}
     
};    
     
     
//End of File

