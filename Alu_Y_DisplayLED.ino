int EstadoA = 0;
int EstadoB = 0;

int w = 0;
int x = 0;
int y = 0;
int z = 0;

void encender(int a, int b, int c, int d, int e, int f, int g)
{
  //Asigna un segmento del display a cada pin
  digitalWrite(2, a);  //Asigna el segmento 'a' al pin 2
  digitalWrite(3, b);  //Asigna el segmento 'b' al pin 3
  digitalWrite(4, c);  //Asigna el segmento 'c' al pin 4
  digitalWrite(5, d);  //Asigna el segmento 'd' al pin 5
  digitalWrite(6, e);  //Asigna el segmento 'e' al pin 6
  digitalWrite(7, f);  //Asigna el segmento 'f' al pin 7
  digitalWrite(8, g);  //Asigna el segmento 'g' al pin 8
}
void setup() {
  //Pines de entrada para A, B, w, x, y, z
  pinMode(A1, INPUT); //A
  pinMode(A2, INPUT); //B
  pinMode(9, INPUT); //w
  pinMode(10, INPUT); //x
  pinMode(11, INPUT); //y
  pinMode(12, INPUT); //z
  //Pines de salida para cada operación
  //SUMA, RESTA, DIVISION, MULTIPLICACION
  pinMode(2, OUTPUT); //'a'
  pinMode(3, OUTPUT); //'b' 
  pinMode(4, OUTPUT); //'c' 
  pinMode(5, OUTPUT); //'d'
  pinMode(6, OUTPUT); //'e'
  pinMode(7, OUTPUT); //'f'
  pinMode(8, OUTPUT); //'g'
}

void loop() {

  EstadoA = digitalRead(A1); // Leer valor de A
  EstadoB = digitalRead(A2); // Leer valor de B
  w = digitalRead(9);
  x = digitalRead(10);
  y = digitalRead(11);
  z = digitalRead(12);

  //CERO INICIAL
  if ((!EstadoA && !EstadoB)&&(!z && !y && !x && !w)){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }
  if ((!EstadoA && !EstadoB)&&(!z && !y && !x && w)){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }
  // SUMA
  if ((EstadoA ^ EstadoB)&&(!z && !y && !x && w)) {
    encender (0, 0, 1, 0, 0, 0, 1);//Muestra el numero 1
  }
  // ACARREO
  if ((EstadoA && EstadoB)&&(!z && !y && !x && w)) {
    encender (1, 0, 1, 1, 1, 1, 1); //Muestra el numero 10(A)
  }
  //RESTA
  if ((!EstadoA && !EstadoB)&&(!z && !y && x && !w)) {
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }
  if ((EstadoA && EstadoB)&&(!z && !y && x && !w)) {
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }

  if ((EstadoA && !EstadoB)&&(!z && !y && x && !w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1
  }
  if ((!EstadoA && EstadoB)&&(!z && !y && x && !w)) {
    encender (1, 1, 1, 1, 1, 0, 0); //Muestra el numero 11(B)
  }

  //MULTIPLICACION
  
  if ((EstadoA && EstadoB)&&(!z && !y && x && w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1
  }
  if ((!EstadoA && !EstadoB)&&(w && x && !y && !z)){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }

  //DIVISION
  if ((EstadoA && EstadoB)&&(!z && y && !x && !w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1
  }
  // (!A AND !B) INDEFINIDO
  if ((!EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    encender (1, 1, 0, 0, 1, 1, 0); //Muestra el numero 12(C)
  }
  // (A AND !B) INFINITO
  if ((EstadoA && !EstadoB)&&(!z && y && !x && !w)) {
    encender (1, 1, 1, 1, 0, 0, 1); //Muestra el numero 13(D)
  }

  // COMPUERTAS LÓGICAS
  // AND
  if ((!EstadoA && !EstadoB)&&(w && !x && y && !z)){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }
  if ((EstadoA && EstadoB) && (!z && y && !x && w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1
  }

  // OR
  if ((!EstadoA && !EstadoB)&&(!w && x && y && !z)){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }
  if ((EstadoA || EstadoB) && (!z && y && x && !w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1
  }

  // NOT (solo A)
if ((!z && y && x && w)) {
    if (!EstadoA) {
      encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1

    } else {
      encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
    }
  }

  // XOR
  if ((!EstadoA && !EstadoB)&&(!w && !x && !y && z)){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }
  if ((EstadoA ^ EstadoB) && (z && !y && !x && !w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1

  }

  // XNOR
  if ((!EstadoA && !EstadoB)&&(w && !x && !y && z)){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }
  if (!(EstadoA ^ EstadoB) && (z && !y && !x && w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1
  }

  // NAND
  if (!(EstadoA && EstadoB) && (z && !y && x && !w)) {
    encender (0, 0, 1, 0, 0, 0, 1);//Muestra el numero 1

  }
  if ((EstadoA && EstadoB) && (z && !y && x && !w)) {
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }

  // NOR
  if (!(EstadoA || EstadoB) && (z && !y && x && w)) {
    encender (0, 0, 1, 0, 0, 0, 1); //Muestra el numero 1
  }
  if ((EstadoA || EstadoB) && (z && !y && x && w)) {
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
    
  }
}