#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double a,b,c,degree,S;
	scanf("%lf %lf %lf",&a,&b,&degree);
	S = (0.5)*a*b*sin(M_PI*degree/180);
	c = sqrt(a*a+b*b-2*a*b*cos(M_PI*degree/180));
	printf("%.8lf\n",S);
	printf("%.8lf\n",a+b+c);
	printf("%.8lf\n",2*S/a);
}

