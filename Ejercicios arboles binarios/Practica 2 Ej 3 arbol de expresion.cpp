//Practica 2 Ejercicio 3
/*
El TAD árbol binario puede albergar expresiones matemáticas mediante un árbol de
expresión. Dentro del árbol binario los nodos hojas contendrán los operandos, y el resto
de los nodos los operadores.
a) Define el tipo de los elementos del árbol para que los nodos puedan almacenar
operadores y operandos.
b) Implementa una función que tome un árbol binario de expresión (aritmética) y
devuelva el resultado de la misma. Por simplificar el problema se puede asumir que el
árbol representa una expresión correcta. Los operadores binarios posibles en la expresión
aritmética serán suma, resta, multiplicación y división.
*/

//Apartado A:
//Vamos a elegir una estructuara op para poder operar tanto con operadores como con operandos
struct op
{
	char operador;
	int operando;
}

//Apartado B:
float abin_expresion(const Abin<op> &A)
{
	return abin_expresion_rec(A.raiz(),A);
}

float abin_expresion_rec(typename Abin<op>::nodo n,const Abin<op> &A)
{
	if(A.hijoIzqdo(n) == Abin<op>::NODO_NULO && A.hijoDrcho(n) == Abin<op>::NODO_NULO)
	{
		return A.elemento(n).operando;
	}
	else
	{
		switch(A.elemento(n).operador)
		{
			case '+': abin_expresion_rec(A.hijoIzqdo(n),A) + abin_expresion_rec(A.hijoDrcho(n),A);
			break;

			case '-': abin_expresion_rec(A.hijoIzqdo(n),A) - abin_expresion_rec(A.hijoDrcho(n),A);
			break;

			case '*': abin_expresion_rec(A.hijoIzqdo(n),A) * abin_expresion_rec(A.hijoDrcho(n),A);
			break;
			
			case '/': abin_expresion_rec(A.hijoIzqdo(n),A) / abin_expresion_rec(A.hijoDrcho(n),A);
			break;
		}
	}
}