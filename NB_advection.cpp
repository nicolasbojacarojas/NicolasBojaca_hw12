#include <iostream>
using std::cout;
using std::endl;
void inicio(double *uv, double xiz, double dx, double N);
void cambio(double *uv, double *un, double N, double dx, double dt, double c);
void actualiza(double *uv, double *un, double N);

void inicio(double *uv, double xiz, double dx, double N)
{
	double x;
	for (int i =0; i < N ; i ++)
	{
		x = xiz + i*dx;
		if (x<=0.5 && x >=-0.5)
		{
			uv[i] = 0.5;
		}
		else
		{
			uv[i]=0;
		}
	}	
}

void cambio(double *uv, double *un, double N, double dx, double dt, double c)
{
	for (int i = 0; i < N; i ++)
	{
		un[i] = uv[i] - c*dt/dx*(uv[i]-uv[i-1]);
	}
}

void actualiza(double *uv, double *un, double N)
{
	for (int i =0; i < N; i ++)
	{
		un[i] = uv[i];
	}
}

int main()
{
	double c=1.0;
	double dt = 0.001;
	double n = 700;
	double xiz = -2;
	double xde = 2;
	double dx = 0.001;
	int N = (xde - xiz)/dx;
	double *un = new double [N];
	double *uv = new double [N];
	double x;
	double t;
	inicio (uv, xiz, dx, N);
	for (int i = 0; i < n; i++)
	{
		cambio(uv, un, n, dx, dt, c);
		actualiza(uv, un, N);
		t += dt;
	}
	for (int i = 0; i < N; i++)
	{
		x = xiz + i*dx;
		cout << un[i] << " " << x << endl;
	}
}
