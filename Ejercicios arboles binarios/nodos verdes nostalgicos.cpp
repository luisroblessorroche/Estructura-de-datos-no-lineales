// ejercicio 1 nodos verdes
//Devolver el número de nodos "nostálgicos" de un árbol.
//Un nodo nostálgico sería aquel que tiene más pasado que futuro, es decir, que tiene más antecesores propios que descendientes propios.

template <typename T> int nodos_verdes_nostalgicos(const Abin<T> &A)
{
	return nodos_verdes_nostalgicos_rec(A.raiz(),A);
}

template <typename T> int nodos_verdes_nostalgicos_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(num_antencesores(n,A) > num_sucesores(n,A) - 1)
		{
			return 1 + nodos_verdes_nostalgicos_rec(A.hijoIzqdo(n),A) + nodos_verdes_nostalgicos_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return nodos_verdes_nostalgicos_rec(A.hijoIzqdo(n),A) + nodos_verdes_nostalgicos_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int num_antencesores(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + num_antencesores(A.padre(n),A);
	} 
}

template <typename T> int num_sucesores(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return 1 + num_sucesores(A.hijoIzqdo(n),A) + num_sucesores(A.hijoDrcho(n),A);
	}
}