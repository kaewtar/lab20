#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect A , Rect B){

	double a1, a2, b1, b2, c1, c2, d1, d2;

	a1 = A.x;	a2 = A.x + A.w; 	b1 = B.x; 	b2 = B.x + B.w;
	c1 = A.y;	c2 = A.y - A.h; 	d1 = B.y; 	d2 = B.y - B.h;

	double  Xmax = a1 ,Xmin = a2 ,upper = c1 , lower = c2 ;
	
	if( b1 > a1 )	Xmax = b1;
	if( b2 < a2 )	Xmin = b2;
	if( d1 < c1 )	upper = d1;
	if( d2 > c2 )	lower = d2;

	double  k, s;
	k = Xmin - Xmax;
	s = upper - lower;
	
	if(k <= 0 || s <=0  ) return 0;
	else return k*s;

}
int main ()
{

	Rect R1 = {-1,2,6.9,9.6};
	Rect R2 = {0,0,1.2,2.5};
	cout << overlap(R1,R2);
	return 0;	
}