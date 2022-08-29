//Ejercicio parcial de EDNL febrero 2021

template <typename T> void febrero_2021(Abin<T> &A)
{
	return febrero_2021_rec(A.raiz(),A);
}

template <typename T> void febrero_2021_rec(typename Abin<T>::nodo n, Abin<T> &A)
{
	if(n != Abin<T>::NODO_NULO)
	{
		if(sum_ancestros(A.padre(n),A) >= A.elemento(n) && (sum_descendientes(A.hijoIzqdo(n),A) + sum_descendientes(A.hijoDrcho(n),A)) <= A.elemento(n))
		{
			podar_descendientes(n,A);
		}
		else
		{
			febrero_2021_rec(A.hijoIzqdo(n),A);
			febrero_2021_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int sum_ancestros(typename Abin<T>::nodo n, Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return A.elemento(n) + sum_ancestros(A.padre(n),A);
	}
}

template <typename T> int sum_descendientes(typename Abin<T>::nodo n, Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return A.elemento(n) + sum_descendientes(A.hijoIzqdo(n),A) + sum_descendientes(A.hijoDrcho(n),A);
	}
}

template <typename T> void podar_descendientes(Abin<T>::nodo n, Abin<T> &A)
{

	if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
	{
		podar_descendientes(A.hijoIzqdo(n),A);
		A.eliminarHijoIzqdo(n);
	}
	if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
	{
		podar_descendientes(A.hijoDrcho(n),A);
		A.eliminarHijoDrcho(n);
	}
}
