//Caminos de costes minimos

//Algoritmo de Dijkstra

/*
sirve para calcular los caminos de coste minimo entre un origen con todos los demas vertices del grafo G
Esta formado por:
	- Un vector de costes minimos de tamaño G.numVert()
	- Un vector de vertices P de tamaño G.numVert(), tal que P[i] es el vertice anterior a i en el camino
	  de coste minimo desde origen hasta i
*/

template <typename tCoste> vector<tCoste> Dijkstra(const grafo<tCoste> &G, typename GrafoP<tCoste>::vertice origen,
vector<typename GrafoP<tCoste>::vertice> &P)
{
	typedef typename GrafoP<tCoste>::vertice vertice;
	vertice v, w;
	const size_t n = G.numVert();
	vector<bool> S(n,false); 
	vector<tCoste> D; //vector de costes minimos desde origen

	//iniciar D y P con caminos directos desde el vertice origen
	D = G[origen];
	D[origen] = 0; //coste de origen a origen es 0
	P = vector<vertice>(n,origen);

	//Calcular caminos de coste minimo hasta cada vertice
	S[origen] = true; //Incluir vertice origen en S
	for(size_t i = 1; i <= n-2; i++)
	{
		tCoste costeMin = GrafoP<tCoste>::INFINITO;
		for(v = 0; v<= n-1;v++)
		{
			if(!S[v] && D[v] <= costeMin)
			{
				costeMin = D[v];
				w = v;
			}
			S[w] = true; //incluir vertive w en vetor de booleanos S
			//recalcular coste hasta cada v no incluido en S, a traves de w
			for (v = 0; v<= n-1;v++)
			{
				if(!S[v])
				{
					tCoste Owv = suma(D[w],G[w][v]);
					if(Owv < D[v])
					{
						D[v] = Owv;
						P[v] = w;
					}
				}
			}
		}
	}
	return D:
}


template <typename tCoste> tCoste suma(tCoste x, tCoste y)
{
	const tCoste INFINITO = GrafoP<tCoste>::INFINITO;
	if(x == INFINITO || Y == INFINITO)
	{
		return INFINITO;
	}
	else
	{
		return x + y;
	}
}


//Ahora toca devolver el camino de origen a v a partir de un vector P obtenido mediante Dijkstra()
template <typename tCoste> typename GrafoP<tCoste>::tCamino camino(typename GrafoP<tCoste>::vertice orig,
typename GrafoP<tCoste>::vertice v, const vector<typename GrafoP <tCoste>::vertice> &P)
{
	typemane GrafoP<tCoste>::tCamino C;
	C.insertar(v,C.primera());
	do
	{
		C.insertar(P[v],C.primera());
		v = P[v];
	}
	while(v != orig);
	return C;
}

