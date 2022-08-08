//Ejercicio nodos verdes
//devolver el numero de nodos de un arbol que son hojas

template <typename T> int nodos_verdes_hojas(const Abin<T> &A)
{
	return nodos_verdes_hojas_rec(A.raiz(),A);
}

template <typename T> int nodos_verdes_hojas_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(nodo_es_hoja(n,A))
		{
			return 1 + nodos_verdes_hojas_rec(A.hijoIzqdo(n),A) + nodos_verdes_hojas_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return nodos_verdes_hojas_rec(A.hijoIzqdo(n),A) + nodos_verdes_hojas_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> bool nodo_es_hoja(typename Abin<T>::nodo n, Abin<T> &A)
{
	return A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO;
}