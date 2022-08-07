//Ejercicio 1 nodos verdes
//Dado un arbol binario calcular (devolver) el número de nodos que tienen exactamente 3 nietos.


template <typename T> int nodos_verdes_3_nietos(const Abin<T> &A)
{
	return nodos_verdes_3_nietos_rec(A.raiz(),A);
}

template <typename> int nodos_verdes_3_nietos_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(nietos_nodo(n,A) == 3)
		{
			return 1 + nodos_verdes_3_nietos_rec(A.hijoIzqdo(n),A) + nodos_verdes_3_nietos_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return nodos_verdes_3_nietos_rec(A.hijoIzqdo(n),A) + nodos_verdes_3_nietos_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int nietos_nodo(typename Abin<T>::nodo n, const Abin<T> &A)
{
	int num_nietos = 0;
	if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)
	{
		return num_nietos;
	}
	else
	{
		if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
		{
			if(A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO)
			{
				num_nietos++;
			}
			if(A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO)
			{
				num_nietos++;
			}
		}

		if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
		{
			if(A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO)
			{
				num_nietos++;
			}
			if(A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO)
			{
				num_nietos++;
			}
		}
	}
	return num_nietos;
}