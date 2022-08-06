//Ejercicio 7 practica 1
//Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
//En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
//del mismo cada uno de los nodos tiene dos hijos o ninguno.

template<typename T> bool abin_pseudocompleto(const Abin<T> &A)
{
	int altura = altura_abin(A.raiz(),A);
	if(altura == 0 || altura == -1)
	{
		return false;
	}
	else
	{
		return abin_pseudocompleto(A.raiz(),A,altura);
	}
}

template <typename T> int altura_abin(const Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1+ max(altura_abin(A.hijoIzqdo(n),A),altura_abin(A.hijoDrcho(n),A));
	}
}

template <typename T> bool abin_pseudocompleto(const Abin<T>::nodo n, const Abin<T> &A, int altura)
{
	if(profundidad_nodo(n,A) == altura -1)
	{
		return (nodo_tiene_dos_o_cero_hijos(n,A));
	}
	else
	{
		return abin_pseudocompleto(A.hijoIzqdo(n),A) && abin_pseudocompleto(A.hijoDrcho(n),A);
	}
}


template <typename T> int profundidad_nodo(const Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad_nodo(A.padre(n),A);
	}
}

template <typename T> bool nodo_tiene_dos_o_cero_hijos(const Abin<T>nodo n, const Abin<T> &A)
{
	return ((A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO) ||
			(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO));
}

