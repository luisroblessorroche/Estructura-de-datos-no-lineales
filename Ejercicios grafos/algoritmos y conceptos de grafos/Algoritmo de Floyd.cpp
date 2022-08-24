//Caminos de costes minimos

//Algoritmo de Floyd

template  <typename tCoste> matriz<tCoste> Floyd(const Grafop<tCoste> &G,
matriz<typename GrafoP<tCoste>::vertice> &P)
{
	typedef typename GrafoP<tCoste>::vertice vertice;
	const size_t n = G.numVert();
	matriz<tCoste> A(n); //matriz de costes minimos
	//iniciar A y P con caminos directos entre cada par de vertices

	P = matriz<vertice>(n);
	for(vertice i = 0; i<= n-1; i++)
	{
		A[i] = G[i]; //copia de costes del grafo
		A[i][i] = 0; //diagonal 0
		P[i] = vector<vertice>(n,i); //caminos directos
	}

//Calcular costes mínimos y caminos correspondientes entre cualquier
//par de vértices i,j

	for(vertice k = 0; k <= n-1;k++)
	{
		for(vertice i = 0; i <= n-1; i++)
		{
			for(vertice j = 0; j<=n-1;j++)
			{
				tCoste ikj = suma(A[i][k], A[k][j]);
			}
			if(ikj < A[i][j])
			{
				A[i][j] = ikj;
				P[i][j] = k;
			}
		}
	}
	return A;
}


//Devuelve el camino de coste minimo entre v y w a partir de una matriz P obtenida
//mediante la funcion floyd()

template <typename tCoste >typename GrafoP<tCoste>::tCamino caminoAux(typename GrafoP<tCoste>::vertice v,
typename GrafoP<tCoste>::vertice w, const matriz<typename GrafoP<tCoste>::vertice> &P)
{
	typename GrafoP<tCoste>::tCamino C1, C2;
	typename GrafoP<tCoste>::vertice u;

	u = P[v][w];
	if(u != v)
	{
		C1 = caminoAux<tCoste>(v,u,P);
		C1.insertar(u,c1.fin());
		C2 = caminoAux<tCoste>(u,w,P);
		C1 += C2;
	}
	return C1;
}



//Devuelve el camino de coste minimo desde v hasta w a partir de una matriz P
//obtenida mediante la funcion floyd()

template<typename tCoste> typename GrafoP<tCoste>::tCamino camino(typename GrafoP<tCoste>::vertice v,
typename GrafoP<tCoste>::vertice w, const matriz<typename GrafoP<tCoste>::vertice> &P)
{
	typename GrafoP<tCoste>::tCamino C;
	C = caminoAux<tCoste>(v,w,P);
	C.insertar(v,C.primera());
	C.insertar(w,C.fin());
	return C;
}














