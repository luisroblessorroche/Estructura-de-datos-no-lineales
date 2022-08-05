//TAD Arbol binario


//OPERACIONES

//precondición:
//postcondición: Crea y devuelve un arbol vacio
Abin()

//precondición:arbol vacio
//postcondición:inserta en la raiz el contenido e
void insertarRaiz(const T& e)

//precondición: n es un nodo del arbol que no tiene hijo izquiedo
//postcondición: inserta el elemento e como hijo izquierdo de n
void insertarHijoIzqdo(nodo n, const T& e)

//precondición: n es un nodo del arbol y no tiene hijo derecho
//postcondición: inserta el elemento e como hijo derecho de n
void insertarHijoDrcho(nodo n, const T& e)

//precondición:n es un nodo del arbol, existe hijoIzqdo(n) y es una hoja
//postcondición:elimina el hijo izquierdo de n
void eliminarHijoIzqdo(nodo n)

//precondición:n es un nodo del arbol,existe hijoDrcho(n) y es una hoja
//postcondición:elimina el hijo derecho de n
void eliminarHijoDrcho(nodo n)

//precondición:el arbol no esta vacio y la raiz es una hoja
//postcondición: elimina la raiz dejando el arbol vacio
void eliminarRaiz()

//precondición:
//postcondición:devuelve true si el arbol esta vacio y false si no
bool arbolVacio() const

//precondición:n es un nodo del arbol
//postcondición: devuelve el elemento del nodo n
const T& elemento(nodo n) const
T& elemento(nodo n)

//precondición:
//postcondición:devuelve el nodo raiz del arbol, si no hay devuelve NODO_NULO
nodo raiz() const

//precondición:n es un nodo del arbol
//postcondición:devuelve el padre del nodo n, si es la raiz devuelve NODO_NULO
nodo padre(nodo n) const

//precondición:n es un nodo del arbol
//postcondición: devuelve el hijo izquierdo de n, si no hay devuelve NODO_NULO
nodo hijoIzqdo(nodo n) const

//precondición:n es un nodo del arbol
//postcondición: devuelve el hijo derecho de n, si no hay devuelve NODO_NULO
nodo hijoDrcho(nodo n) const
