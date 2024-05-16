// Declarando parámetros
int led_verde = 11;
int led_amarillo = 12;
int led_rojo = 13;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  // Configuración de pines
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);

  // Configurar pines del display de 7 segmentos como salidas
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }

  // Apaga todos los LEDs y segmentos del display
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarillo, LOW);
  digitalWrite(led_rojo, LOW);
  funcNum(-1); // Apaga todos los segmentos del display
}

void loop() {
  // Encender LED verde y contar 9 segundos
  digitalWrite(led_verde, HIGH);
  for (int i = 9; i >= 0; i--) {
    funcNum(i);
    delay(1000);
  }
  digitalWrite(led_verde, LOW); // Apagar LED verde

  // Parpadear LED amarillo 3 veces
 // Parpadear LED amarillo 3 veces
 digitalWrite(led_amarillo, HIGH);
  for (int i =3 ; i >= 0; i--) {
    funcNum(i);
    delay(1000);
  }
  digitalWrite(led_amarillo, LOW); // Apagar LED rojo
  // Apagar LED amarillo y encender LED rojo
  digitalWrite(led_amarillo, LOW);
  digitalWrite(led_rojo, HIGH);
  // Contar 9 segundos con el LED rojo encendido
  for (int i = 9; i >= 0; i--) {
    funcNum(i);
    delay(1000);
  }
  digitalWrite(led_rojo, LOW); // Apagar LED rojo

  // Envía el estado actual del semáforo por comunicación serial
  Serial.println("Semaforo: Rojo");

  // Retraso de 1 segundo antes de reiniciar el ciclo
  delay(1000);
}

// Función para encender los segmentos del visualizador de 7 segmentos
void funcNum(int x) {
  // Si x es -1, apaga todos los segmentos
  if (x == -1) {
    for (int i = 2; i <= 8; i++) {
      digitalWrite(i, LOW);
    }
    return;
  }
  switch (x) {
    case 0: // cuando el valor es 0 mostrar "0" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, HIGH); // d
      digitalWrite(6, HIGH); // e
      digitalWrite(7, HIGH); // f
      digitalWrite(8, LOW);  // g
      break;
    case 1: // cuando el valor es 1 mostrar "1" en el display
      digitalWrite(2, LOW);  // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, LOW);  // d
      digitalWrite(6, LOW);  // e
      digitalWrite(7, LOW);  // f
      digitalWrite(8, LOW);  // g
      break;
    case 2: // cuando el valor es 2 mostrar "2" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, LOW);  // c
      digitalWrite(5, HIGH); // d
      digitalWrite(6, HIGH); // e
      digitalWrite(7, LOW);  // f
      digitalWrite(8, HIGH); // g
      break;
    case 3: // cuando el valor es 3 mostrar "3" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, HIGH); // d
      digitalWrite(6, LOW);  // e
      digitalWrite(7, LOW);  // f
      digitalWrite(8, HIGH); // g
      break;
    case 4: // cuando el valor es 4 mostrar "4" en el display
      digitalWrite(2, LOW);  // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, LOW);  // d
      digitalWrite(6, LOW);  // e
      digitalWrite(7, HIGH); // f
      digitalWrite(8, HIGH); // g
      break;
    case 5: // cuando el valor es 5 mostrar "5" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, LOW);  // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, HIGH); // d
      digitalWrite(6, LOW);  // e
      digitalWrite(7, HIGH); // f
      digitalWrite(8, HIGH); // g
      break;
    case 6: // cuando el valor es 6 mostrar "6" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, LOW);  // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, HIGH); // d
      digitalWrite(6, HIGH); // e
      digitalWrite(7, HIGH); // f
      digitalWrite(8, HIGH); // g
      break;
    case 7: // cuando el valor es 7 mostrar "7" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, LOW);  // d
      digitalWrite(6, LOW);  // e
      digitalWrite(7, LOW);  // f
      digitalWrite(8, LOW);  // g
      break;
    case 8: // cuando el valor es 8 mostrar "8" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, HIGH); // d
      digitalWrite(6, HIGH); // e
      digitalWrite(7, HIGH); // f
      digitalWrite(8, HIGH); // g
      break;
    case 9: // cuando el valor es 9 mostrar "9" en el display
      digitalWrite(2, HIGH); // a
      digitalWrite(3, HIGH); // b
      digitalWrite(4, HIGH); // c
      digitalWrite(5, HIGH); // d
      digitalWrite(6, LOW);  // e
      digitalWrite(7, HIGH); // f
      digitalWrite(8, HIGH); // g
      break;
  } 
}