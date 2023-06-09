#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

int N = 5;

double linear_reg(const double x[], const double y[]) {
	double x_mean = 0, y_mean= 0;

	#pragma omp parallel for reduction(+: x_mean, y_mean)
	for(int i = 0; i < N; i++) {
		x_mean += x[i];
		y_mean += y[i];	
	}
	
	double n = N;
	x_mean /= n;
	y_mean /= n;

	double num = 0, den = 0;
	

	#pragma omp parallel for reduction(+: num, den)
	for( int i = 0; i < N; i++) {
		num += (x[i] - x_mean) * (y[i] - y_mean);
		den += (x[i] - x_mean) * (x[i] - x_mean);
	}

	return num / den;
}

int main() {
	double x[N], y[N];
	cout << "Enter co-ordinates(x, y) of " << N <<" points" <<endl;
	for(int i = 0 ; i < N; i ++) {
		cin >> x[i] >> y[i];	
	}

	cout << "Linear Regression line has slope : " << linear_reg(x, y) <<endl;

	return 0;
}
