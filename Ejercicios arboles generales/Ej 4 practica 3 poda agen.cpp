//Ejercicio 4 practica 3
// Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
//la poda de A a partir de x. Se asume que no hay elementos repetidos en A.

template <typename T> void poda_agen_a_partir_de_nodo(typename Agen<T>::nodo n, Agen<T> &A)
{
	poda_arbol(n,A);

	if(A.padre(n) == Agen<T>::NODO_NULO)
	{
		A.eliminarRaiz();
	}
	else
	{
		Agen<T>::nodo n2 = n;
		n = A.hijoIzqdo(A.padre(n));
		bool encontrado = false;
		while(n != Agen<T>::NODO_NULO || !encontrado)
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

template <typename T> void poda_arbol(typename Agen<T>::nodo n, Agen<T> &A)
{
	if(n != Agen<T>::NODO_NULO)
	{
		while(A.hijoIzqdo(n) != Agen<T>::NODO_NULO)
		{
			poda_arbol(A.hijoIzqdo(n),A);
			A.eliminarHijoIzqdo(n);
		}
	}
}
