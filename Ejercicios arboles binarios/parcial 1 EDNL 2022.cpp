//parcial 1 ednl 2022
//Dado un arbol binario de un tipo generico T, calcular el numero de nodos que siendo hermanos
//entre si tienen la misma raiz y sus subarboles son reflejados

template <typename T> int num_nodos_examen(const Abin<T> &A)
{
	return num_nodos_examen_rec(A.raiz(),A);
}

template <typename T> int num_nodos_examen_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if (n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(subarbol_reflejado(A.hijoIzqdo(n),A.hijoDrcho(n),A) && nodo_no_hoja(n,A))
		{
			return 2 + num_nodos_examen_rec(A.hijoIzqdo(n),A) + num_nodos_examen_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return num_nodos_examen_rec(A.hijoIzqdo(n),A) + num_nodos_examen_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> bool subarbol_reflejado(typename Abin<T>::nodo n1, typename Abin<T>::nodo n2, const Abin<T> &A)
{
	if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		if(n1 != Abin<T>::NODO_NULO && n2 != Abin<T>::NODO_NULO)
		{
			return A.elemento(n1) == A.elemento(n2) && subarbol_reflejado(A.hijoIzqdo(n1),A.hijoDrcho(n2),A) &&
				   subarbol_reflejado(A.hijoDrcho(n1),A.hijoIzqdo(n2),A);
		}
		else
		{
			return false;
		}
	}
}

template <typename T> bool nodo_no_hoja(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO;
}