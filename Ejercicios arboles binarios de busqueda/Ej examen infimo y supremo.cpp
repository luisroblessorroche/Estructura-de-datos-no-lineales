//ejercicio de parcial ABB
//Dado un conjunto ordenado no vacio, se define el infimo de x como el mayor elemento de A menor o igual que x
//y el supremo como el menor elemento de A mayor o igual que x.
//implementar dos funciones de O(log n) en promedio que dados un valor x y un ABB no vacio devuelva el infimo y supremo.
//si no existe el infimo devolvera el minimo del ABB y si no existe el supremo devolvera el maximo del ABB


//incluiremos la libreria limit.h para el valor min y max de enteros

#include <limits.h>

int infimo_ABB(const Abb<int> &A, int x)
{
	assert(!A.vacio());
	return infimo_ABB_rec(A,x,A.elemento());
} 



int infimo_ABB_rec(const Abb<int> &A, int x, int infimo)
{
	if(A.vacio())
	{
		if(infimo > x)
		{
			return MIN_INT;
		}
		else
		{
			return MAX_INT;
		}
	}
	else
	{
		infimo = A.elemento();

		if(infimo > x)
		{
			return min(infimo,infimo_ABB_rec(A.izqdo(),x,infimo));
		}
		else
		{
			if(infimo < x)
			{
				return max(infimo,infimo_ABB_rec(A.drcho(),x,infimo));
			}
			else
			{
				return infimo;
			}
		}
	}
}


int supremo_ABB(const Abb<int> &A, int x)
{
	assert(!A.vacio());
	return supremo_ABB_rec(A,x,A.elemento());
}

int supremo_ABB_rec(const Abb<int> &A, int x, int supremo)
{
	if(A.vacio())
	{
		if(supremo > x)
		{
			return MAX_INT;

		}
		else
		{
			return MIN_INT;
		}
	}
	else
	{
		supremo = A.elemento();
		if(supremo > x)
		{
			return min(supremo,supremo_ABB_rec(A.izqdo(),x,supremo));
		}
		else
		{
			if(supremo < x)
			{
				return max(supremo,supremo_ABB_rec(A.drcho(),x,supremo));
			}
			else
			{
				return supremo;
			}
		}
	}
}