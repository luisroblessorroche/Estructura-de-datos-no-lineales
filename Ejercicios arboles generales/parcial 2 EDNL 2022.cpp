//parcial 2 arboles generales

/*
Se da un arbol general, cuyos nodos pueden estar vivos o muertos, y tienen una cantidad
de riquezas. Se pide una funcion que tome un nodo vivo del arbol, lo mate y redistribuya
su riqueza con sus herederos.
Los herederos de un nodo son sus hijos vivos y los hijos muertos que tengan descendientes
vivos. Cuando se tenga que distribuir las riquezas, se dividiran a partes iguales
para todos los herederos. Si se da riqueza a un nodo muerto, se redistribuira a
sus descendenientes vivos
*/



//estructura de datos
struct persona
{
	bool vivo;
	float riqueza;
}

void matar_y_redistribuir(Agen<persona>::nodo n, Agen<persona> &A)
{
	assert(A.elemento(n).vivo);
	float riqueza = A.elemento(n).riqueza;
	A.elemento(n).vivo = false;
	A.elemento(n).riqueza = 0;
	redistribuir_riqueza(A.hijoIzqdo(n),A,riqueza);
}

void redistribuir_riqueza(Agen<persona>::nodo n, Agen<persona> &A, float riqueza)
{
	int num_nodos = contar_num_nodos_herencia(n,A);
	riqueza = riqueza/num_nodos;
	while (n != Agen<persona>::NODO_NULO)
	{
		if(A.elemento(n).vivo)
		{
			A.elemento(n).riqueza = A.elemento(n).riqueza + riqueza;
		}
		else
		{
			if(candidato:heredar(n,A))
			{
				redistribuir_riqueza(A.hijoIzqdo(n),A,riqueza);
			}
		}
		n = A.hermDrcho(n);
	}
}


int contar_num_nodos_herencia(Agen<persona>::nodo n, Agen<persona> &A)
{
	int cont = 0;
	while(n != Agen<persona>::NODO_NULO)
	{
		if(candidato_heredar(n,A))
		{
			cont++;	
		}
		n = A.hermDrcho(n);
	}
	return cont;
}

bool candidato_heredar(Agen<persona>::nodo n, Agen<persona> &A)
{
	if(n == Agen<persona>::NODO_NULO)
	{
		return false;
	}
	else
	{
		if(A.elemento(n).vivo)
		{
			return true;
		}
		else
		{
			if(A.hijoIzqdo(n) == Agen<persona>::NODO_NULO)
			{
				return false;
			}
			else
			{
				n = A.hijoIzqdo(n);
			}
			while(n != Agen<persona>::NODO_NULO)
			{
				return candidato_heredar(n,A) || candidato_heredar(A.hermDrcho(n),A);
				n = A.hermDrcho(n);
			}
		}
	}
}