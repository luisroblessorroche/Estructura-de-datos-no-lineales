//Practica 2 Ejercicio 2
//. Para un árbol binario B, podemos construir el árbol binario reflejado B_sub_r cambiando los
//subárboles izquierdo y derecho en cada nodo. Implementa un subprograma 
//que devuelva el árbol binario reflejado de uno dado.

template <typename T> Abin<T> abin_reflejado(const Abin<T> &A)
{
	Abin<T> B = Abin();

	if(A.raiz() != Abin<T>::NODO_NULO)
	{
		B.insertarRaiz(A.elemento(A.raiz()));
		abin_reflejado_rec(A.raiz(),A,B.raiz())
	}
	return B;
}

template <typename T> void abin_reflejado_rec( typename Abin<T>::nodo n1, Abin<T> &A, typename Abin<T>::nodo n2, Abin<T> &B)
{
	if(n1 != Abin<T>::NODO_NULO)
	{
		if(A.hijoIzqdo(n1) != Abin<T>::NODO_NULO)
		{
			B.insertarHijoDrcho(n2,A.elemento(A.hijoIzqdo(n1)));
			abin_reflejado_rec(A.hijoIzqdo(n1),A,B.hijoDrcho(n2),B);
		}

		if(A.hijoDrcho(n1) != Abin<T>::NODO_NULO)
		{
			B.insertarHijoIzqdo(n2,A.elemento(A.hijoDrcho(n1)));
			abin_reflejado_rec(A.hijoDrcho(n1),A,B.hijoIzqdo(n2),B);
		}
	}
}