//ejercicio  extra: calcular el porcentaje de descendientes propios de un arbol general que sean multiplos de 3

float porcentaje_multiplos_3(const Agen<int> &A)
{
	if(!A.vacio())
	{
		return porcentaje_multiplos_3_rec(A.raiz(),A)/num_nodos(A.raiz(),A) * 100;
	}
	else
	{
		return 0;
	}
}

int porcentaje_multiplos_3_rec(typename Agen<int>::nodo n, const Agen<int> &A)
{
	if(n == Agen<int>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(es_multiplo_de_3(n,A))
		{
			return 1 + porcentaje_multiplos_3_rec(A.hijoIzqdo(n),A) + porcentaje_multiplos_3_rec(A.hermDrcho(n),A);
		}
		else
		{
			return porcentaje_multiplos_3_rec(A.hijoIzqdo(n),A) + porcentaje_multiplos_3_rec(A.hermDrcho(n),A);
		}
	}
}

bool es_multiplo_de_3(typename Agen<int>::nodo n, const Agen<int> &A)
{
	return A.elemento(n)%3 == 0;
}


int num_nodos(typename Agen<int>::nodo n, const Agen<int> &A)
{
	if(n == Agen<int>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return 1 + num_nodos(A.hijoIzqdo(n),A) + num_nodos(A.hermDrcho(n),A);
	}
}