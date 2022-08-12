//Ejercicio 4 practica 3
// Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
//la poda de A a partir de x. Se asume que no hay elementos repetidos en A.

 void poda_agen_a_partir_de_nodo(int x, Agen<int> &A)
{
	poda_agen_a_partir_de_nodo_rec(int x, A.raiz(), A);
}

 void poda_agen_a_partir_de_nodo_rec(int x, typename Agen<int>::nodo n, Agen<int> &A)
{
	if(n != Agen<int>::NODO_NULO)
	{
		if(A.elemento(n) == x)
		{
			poda_arbol(n,A);

			if(A.padre(n) == Agen<int>::NODO_NULO)
			{
				A.eliminarRaiz();
			}
			else
			{
				Agen<T>::nodo n2 = n;
				n = A.hijoIzqdo(A.padre(n));
				bool encontrado = false;
				while(n != Agen<int>::NODO_NULO || !encontrado)
				{
					if(n == n2)
					{
						A.eliminarHijoIzqdo(A.padre(n));
					}
					if(A.hermDrcho(n) == n2)
					{
						A.eliminarHermDrcho(n);
					}
					n = A.hermDrcho(n);
				}

			}

		}
		else
		{
			poda_agen_a_partir_de_nodo_rec(x,A.hijoIzqdo(n),A);
			poda_agen_a_partir_de_nodo_rec(x,A.hermDrcho(n),A);
		}
	}
}

void poda_arbol(typename Agen<int>::nodo n, Agen<int> &A)
{
	if(n != Agen<int>::NODO_NULO)
	{
		while(A.hijoIzqdo(n) != Agen<int>::NODO_NULO)
		{
			poda_arbol(A.hijoIzqdo(n),A);
			A.eliminarHijoIzqdo(n);
		}
	}
}
