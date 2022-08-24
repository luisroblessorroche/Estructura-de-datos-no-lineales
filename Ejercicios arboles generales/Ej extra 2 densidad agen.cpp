//Calcular la densidad de un arbol
//La densidad es el grado maximo de un arbol entre el numero de nodos hojas del arbol

template <typename T> float densidad_agen(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(!A.vacio())
	{
		return grado_max_agen(A.raiz(),A)/num_nodos_hojas(A.raiz(),A);
	}
	else
	{
		return 0;
	}
}

template <typename T> int grado_max_agen(typename Agen<T>::nodo n, Const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return max3(grado_nodo(n,A),grado_max_agen(A.hijoIzqdo(n),A),grado_max_agen(A.hermDrcho(n),A));
	}
}

template <typename T> int grado_nodo(typename Agen<T>::nodo n, const Agen<T> &A)
{
	n = A.hijoIzqdo(n);
	int cont = 0;
	while(n != Agen<T>::NODO_NULO)
	{
		cont++;
		n = A.hermDrcho(n);
	}
	return cont;
}

template <typename T> int num_nodos_hojas(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(nodo_es_hoja(n,A))
		{
			return 1 + num_nodos_hojas(A.hijoIzqdo(n),A) + num_nodos_hojas(A.hermDrcho(n),A);
		}
		else
		{
			return num_nodos_hojas(A.hijoIzqdo(n),A) + num_nodos_hojas(A.hermDrcho(n),A);
		}
	}
}

template <typename T> bool nodo_es_hoja(typename Agen<T>::nodo n, const Agen<T> &A)
{
	return A.hijoIzqdo(n) == Agen<T>::NODO_NULO;
}