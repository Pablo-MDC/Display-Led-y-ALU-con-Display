int w = 0; //Entrada dipswitch1
int x = 0; //Entrada dipswitch2
int y = 0; //Entrada dipswitch3
int z = 0; //Entrada dipswitch4

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

  //Inicializa los pines como entradas/salidas digitales

  pinMode(2, OUTPUT); //'a'
  pinMode(3, OUTPUT); //'b' 
  pinMode(4, OUTPUT); //'c' 
  pinMode(5, OUTPUT); //'d'
  pinMode(6, OUTPUT); //'e'
  pinMode(7, OUTPUT); //'f'
  pinMode(8, OUTPUT); //'g'
  pinMode(9, INPUT); //'w'
  pinMode(10, INPUT); //'x'
  pinMode(11, INPUT); //'y'
  pinMode(12, INPUT); //'z'
}

void loop() {

  w=digitalRead(9);  //Asignar variables del dipswitch a los pines
  x=digitalRead(10);  //Asignar variables del dipswitch a los pines
  y=digitalRead(11);  //Asignar variables del dipswitch a los pines
  z=digitalRead(12);  //Asignar variables del dipswitch a los pines

  //Combinaciones del dipswitch para encender cada parte del display
  //Envia estados (1 y 0) al display dependiendo del numero a mostrar

  if (!w && !x && !y && !z){
    encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero 0
  }

  if (w && !x && !y && !z){
    encender (0, 0, 1, 0, 0, 0, 1);//Muestra el numero 1
  }

  if (!w && x && !y && !z){
    encender (1, 1, 0, 1, 0, 1, 1); //Muestra el numero 2
  }   

  if (w && x && !y && !z){
    encender (0, 1, 1, 1, 0, 1, 1); //Muestra el numero 3
  }
      
  if (!w && !x && y && !z){
    encender (0, 0, 1, 1, 1, 0, 1); //Muestra el numero 4
  }
      
  if (w && !x && y && !z){
    encender (0, 1, 1, 1, 1, 1, 0); //Muestra el numero 5
  }

  if (!w && x && y && !z){
    encender (1, 1, 1, 1, 1, 1, 0); //Muestra el numero 6
  }

  if (w && x && y && !z){
    encender (0, 0, 1, 0, 1, 1, 1); //Muestra el numero 7
  }

  if (!w && !x && !y && z){
    encender (1, 1, 1, 1, 1, 1, 1); //Muestra el numero 8
  }

  if (w && !x && !y && z){
    encender (0, 1, 1, 1, 1, 1, 1); //Muestra el numero 9
  }

  if (!w && x && !y && z){
    encender (1, 0, 1, 1, 1, 1, 1); //Muestra la letra A
  }
      
  if (w && x && !y && z){
    encender (1, 1, 1, 1, 1, 0, 0); //Muestra la letra B
  }

  if (!w && !x && y && z){
    encender (1, 1, 0, 0, 1, 1, 0); //Muestra la letra C
  }

  if (w && !x && y && z){
    encender (1, 1, 1, 1, 0, 0, 1); //Muestra la letra D
  }

  if (!w && x && y && z){
    encender (1, 1, 0, 1, 1, 1, 0); //Muestra la letra E
  }

  if (w && x && y && z){
    encender (1, 0, 0, 1, 1, 1, 0); //Muestra la letra F
  }
    
}