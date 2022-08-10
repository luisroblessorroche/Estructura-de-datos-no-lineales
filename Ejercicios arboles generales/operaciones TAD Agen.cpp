//operaciones TAD Agen


//precondición:
//postcondición: construye un arbol vacio
Agen()

//precondición: el arbol esta vacio 
//postcondición: inserta el nodo raiz de A cuyo contenido es e
void insertarRaiz(const T& e)

//precondición: n es un nodo del arbol
//postcondición: inserta el elemento e como hijo izqdo. si ya exisita hijo izqdo,
//pasará a ser el hermano derecho del nuevo nodo
void insertarHijoIzqdo(nodo n, const T& e)

//precondición: n es nodo del arbol y no es el nodo raiz
//postcondición: inserta el elemento e como herm drcho de n, si ya exisitia
//herm drcho, ese hermano pasa a ser herm drcho del nuevo
void insertarHermDrcho(nodo n, const T& e)

//precondición: n es un nodo del arbol, existe hijoIzqdo y es hoja
//postcondición: elimina el hijo izqdo de n, dejando su herm drcho como hijo izqdo de n
void eliminarHijoIzqdo(nodo n)

//precondición: n es un nodo del arbol, existe herm drcho y es hoja
//postcondición: elimina el herm drcho de n, dejando su herm drcho como nuevo herm drcho de n
void eliminarHermDrcho(nodo n)

//precondición: el arbol no esta vacio y la raiz es hoja
//postcondición: elimina la raiz dejando el arbol vacio
void eliminarRaiz()

//precondición:
//postcondición: devuelve true si esta vacio y false si no
bool arbolVacio() const

//precondición: n es un nodo del arbol
//postcondición: devuelve el elemento del nodo n
const T& elemento(nodo n) const
T& elemento(nodo n)

//precondición:
//postcondición: devuelve el nodo raiz del arbol. Si esta vacio devuelve NODO_NULO
nodo raiz() const

//precondición: n es un nodo del arbol
//postcondición: devuelve el nodo padre de n, si no existe devuelve NODO_NULO
nodo padre(nodo n) const

//precondición: n es un nodo del arbol
//postcondición: devuelve el hijo izqdo de n, si no existe, devuelve NODO_NULO
nodo hijoIzqdo(nodo n)

//precondición: n es un nodo del arbol
//postcondición: devuelve el herm drcho de n, si no existe, devuelve NODO_NULO
nodo hermDrcho(nodo n)
