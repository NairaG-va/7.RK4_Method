//Метод Рунге-Кутта 4-го порядка
#include <iostream>
#include <math.h>
#include <vector> 

void function();

int main(){
	
	function();
	
	return 0;
}

void function(){
	
	double k1, k2, k3, k4;
	double h = 0.2;
	double f;
	double pogr, max_pogr = 0;
	
	std::vector<double> y(12);
	y[0] = 3;
	
	for (int i = 1; i != 6; i++)
	 {
		 k1 = y[i-1] - ((i-1)*0.2)*((i-1)*0.2);
		 k2 = y[i-1] + (h/2.0)*k1 - ((i-1)*0.2+(h/2.0))*((i-1)*0.2+(h/2.0));
		 k3 = y[i-1] + (h/2.0)*k2 - ((i-1)*0.2+(h/2.0))*((i-1)*0.2+(h/2.0));
		 k4 = y[i-1] + h*k3 - ((i-1)*0.2 + h)*((i-1)*0.2 + h);
		 
		 y[i] = y[i-1] + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
		 
		 f = exp(i*0.2) + (i*0.2)*(i*0.2) + 2.0*(i*0.2) + 2.0;
		 
		 pogr = (fabs(f-y[i])/f)*100.0;
		 
		 if (max_pogr < pogr) max_pogr = pogr;
		
		 std::cout << " k1 = " << k1 <<  " k2 = " << k2 << " k3 = " << k3 << " k4 = " << k4 << "\n";
		 std::cout << " y[i] = " << y[i] << " f = " << f << " pogr = " << pogr << " max_pogr = " << max_pogr << "\n";
	
	 }	
}
