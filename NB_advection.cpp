#include <iostream>
using std::cout;
using std::endl;
//incializacion de las funciones que se van a usar en la derivada
void inicio(double *uv, double xiz, double dx, double N);
void cambio(double *uv, double *un, double N, double dx, double dt, double c);
void actualiza(double *uv, double *un, double N);
//funcion que inicializa los valores de u, pues hay unas condiciones para los cuales ls funcion vale 0 o 0.5
void inicio(double *uv, double xiz, double dx, double N)
{
	//variable que guarda la evolucion sobre la posicion
	double x;
	//iteraciones para evolucionar x y darle valores a los componentes en u
	for (int i =0; i < N ; i ++)
	{
		x = xiz + i*dx;
		//condiciones para las cuales u toma valores distintos de 0 
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
//funcion que realiza un cambio sobre los u para encontrar la solucion a la ecuacion diferencial
void cambio(double *uv, double *un, double N, double dx, double dt, double c)
{
	for (int i = 0; i < N; i ++)
	{
		un[i] = uv[i] - c*dt/dx*(uv[i]-uv[i-1]);
	}
}
//funcion que actualiza los valores de los u nuevos con los viejos
void actualiza(double *uv, double *un, double N)
{
	for (int i =0; i < N; i ++)
	{
		un[i] = uv[i];
	}
}

int main()
{
	//contante de la ecuacion de adveccion
	double c=1.0;
	//cambio en el tiempo seleccionado
	double dt = 0.001;
	//numero de iteraciones a realizar sobre el tiempo 
	double n = 700;
	//valor minimo que toma x
	double xiz = -2;
	//valor maximo que toma x
	double xde = 2;
	//cambios en la distancia
	double dx = 0.001;
	//numero de iteraciones a realizar sobre las posiciones
	int N = (xde - xiz)/dx;
	//variables que van a guardar los valores de u nuevos
	double *un = new double [N];
	//variable de u viejos
	double *uv = new double [N];
	//variable de posicion
	double x;
	//variable de tiempo
	double t;
	inicio (uv, xiz, dx, N);
	//iteaciones para cambiar los valores de u haciendo uso de las funciones
	for (int i = 0; i < n; i++)
	{
		cambio(uv, un, n, dx, dt, c);
		actualiza(uv, un, N);
		t += dt;
	}
	//iteraciones para imprimir los x y las funciones de u
	for (int j = 0; j < N, j++ )
	{
		x = xiz + i*dx;
		cout << un[i] << " " << x << " " << t << endl;
	}
}
