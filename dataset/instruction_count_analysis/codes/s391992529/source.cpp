#include <cstdio>

#include <cmath>



int main() {



	double x1, x2, x3;

	double y1, y2, y3;

	double a, b, c;

	double r1, r2, r3;

	double d,e,f;

	double r, s;

	double ix, iy;



	scanf("%lf %lf", &x1, &y1);

	scanf("%lf %lf", &x2, &y2);

	scanf("%lf %lf", &x3, &y3);



    while( x1 != 0 || x2 != 0 || x3 != 0 ||

    	   y1 != 0 || y2 != 0 || y3 != 0){



    	// from wikipedia: https://en.wikipedia.org/wiki/Malfatti_circles#Radius_formula

    	c = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

     	a = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));

    	b = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));

    	// std::cout << a << " " << b << " " << c << std::endl;



    	s = (a+b+c) / 2;

    	// std::cout << s <<std::endl;



    	// formula for incenter of a triange

    	// http://mathworld.wolfram.com/Incenter.html

    	ix = (a*x1 + b*x2 + c*x3) / (a+b+c);

    	iy = (a*y1 + b*y2 + c*y3) / (a+b+c);



    	// std::cout << ix << " " << iy << std::endl;

    	d = sqrt((ix-x1)*(ix-x1) + (iy-y1)*(iy-y1));

    	e = sqrt((ix-x2)*(ix-x2) + (iy-y2)*(iy-y2));

    	f = sqrt((ix-x3)*(ix-x3) + (iy-y3)*(iy-y3));



    	// std::cout << d << " " << e << " " << f << std::endl;



    	r=sqrt(s*(s-a)*(s-b)*(s-c))/s;



    	r1 = r*(s-r+d-e-f)/(2*(s-a));

    	r2 = r*(s-r-d+e-f)/(2*(s-b));

    	r3 = r*(s-r-d-e+f)/(2*(s-c));



    	printf("%lf %lf %lf\n", r1, r2, r3);

	    

		scanf("%lf %lf", &x1, &y1);

		scanf("%lf %lf", &x2, &y2);

		scanf("%lf %lf", &x3, &y3);

    }

    return 0;

}




