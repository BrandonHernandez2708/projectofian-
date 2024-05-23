//Proyecto Grupo #7
// Semáforo con botón de encendido/apagado
// Declarando parámetros
int led_verde = 11;
int led_amarillo = 12;
int led_rojo = 13;
int buttonPin = 10;
int buttonState = 0;
bool semaforoEncendido = false;
bool primerPresion = true; // Para controlar la primera presión del botón

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);

  // Se indica que cada pin es de salida OUTPUT.
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(buttonPin, INPUT);
  // Se apagan todos los LEDs
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarillo, LOW);
  digitalWrite(led_rojo, LOW);
  // Pines 2-8 encienden LEDs del visualizador de segmentos
  pinMode(2, OUTPUT); // a
  pinMode(3, OUTPUT); // b
  pinMode(4, OUTPUT); // c
  pinMode(5, OUTPUT); // d
  pinMode(6, OUTPUT); // e
  pinMode(7, OUTPUT); // f
  pinMode(8, OUTPUT); // g
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    if (primerPresion) { // Si es la primera presión, enciende el semáforo
      semaforoEncendido = true;
      primerPresion = false; // Cambia el estado para la próxima presión
    } else { // Si no es la primera presión, apaga el semáforo
      semaforoEncendido = false;
      primerPresion = true; // Cambia el estado para la próxima presión
    }
    delay(200); // Retardo para evitar el rebote del botón
  }

  if (semaforoEncendido) {
    // Encender LED verde y contar 9 segundos
    digitalWrite(led_verde, HIGH);
    Serial.println("LED Verde: ON");
    for (int i = 9; i >= 0; i--) {
      funcNum(i);
      delay(1000);
    }
    digitalWrite(led_verde, LOW); // Apagar LED verde
    Serial.println("LED Verde: OFF");

    // Parpadear LED amarillo 3 veces
    for (int i = 0; i < 3; i++) {
      digitalWrite(led_amarillo, HIGH);
      Serial.println("LED Amarillo: ON");
      delay(500);
      digitalWrite(led_amarillo, LOW);
      Serial.println("LED Amarillo: OFF");
      delay(500);
    }

    // Encender LED rojo y contar 9 segundos
    digitalWrite(led_rojo, HIGH);
    Serial.println("LED Rojo: ON");
    for (int i = 9; i >= 0; i--) {
      funcNum(i);
      delay(1000);
    }
    digitalWrite(led_rojo, LOW); // Apagar LED rojo
    Serial.println("LED Rojo: OFF");
  } else {
    // Apagar todos los LEDs
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amarillo, LOW);
    digitalWrite(led_rojo, LOW);
    // Apagar display de 7 segmentos
    funcNum(-1); // Función para apagar el display
    Serial.println("Semaforo: OFF");
  }
}

// Función para encender los segmentos del visualizador de 7 segmentos
void funcNum(int x) {
  // Si x es -1, apagar todos los segmentos
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
