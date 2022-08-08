//Ejercicios extra
//implementar un subprograma que dado un arbol binario, pode los nodos que tengan un solo hijo

template <typename T> void poda_nodos_1_hijo(const Abin<T> &A)
{
	poda_nodos_1_hijo_rec(A.raiz(),A);
}

template <typename T> void poda_nodos_1_hijo_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n != Abin<T>::NODO_NULO)
	{
		if(nodo_tiene_un_hijo(n,A))
		{
			if(hijo_es_hoja(n,A))
			{
				poda_nodos_1_hijo_rec(A.hijoIzqdo(n),A);
				poda_nodos_1_hijo_rec(A.hijoDrcho(n),A);
				eliminar_hijo(n,A);
			}
			else
			{
				poda_nodos_1_hijo_rec(A.hijoIzqdo(n),A);
				poda_nodos_1_hijo_rec(A.hijoDrcho(n),A);	
			}
		}
		else
		{
			poda_nodos_1_hijo_rec(A.hijoIzqdo(n),A);
			poda_nodos_1_hijo_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> bool nodo_tiene_un_hijo(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return ((A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO) || 
			 A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO);
}

template <typename T> bool hijo_es_hoja(typename Abin<T>::nodo n, const Abin<T> &A)
{
	bool es_hoja = false;
	if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
	{
		if(A.hijoIzqdo(A.hijoIzqdo(n) == Abin<T>::NODO_NULO) && A.hijoDrcho(A.hijoIzqdo(n) == Abin<T>::NODO_NULO))
		{
			es_hoja = true;
		}
	}
	else
	{
		if(A.hijoIzqdo(A.hijoDrcho(n) == Abin<T>::NODO_NULO) && A.hijoDrcho(A.hijoDrcho(n) == Abin<T>::NODO_NULO))
		{
			es_hoja = true;
		}
	}
	return es_hoja;
}



template <typename T> void eliminar_hijo(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
	{
		A.eliminarHijoIzqdo(n);
	}
	else
	{
		A.eliminarHijoDrcho(n);
	}
}