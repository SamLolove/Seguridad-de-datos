#Mouse changer: Cambia el mouse color del mouse del usuario y agranda su puntero
----
#include <DigiKeyboard.h>

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(5000); // Tiempo para conectar
}

void loop() {
  // === ABRIR MENÚ DE INICIO (se mantiene) ===
  DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT);
  DigiKeyboard.delay(2000);

  // === ESCRIBIR BÚSQUEDA (se mantiene) ===
  DigiKeyboard.print("mouse pointer and touch");
  DigiKeyboard.delay(3000);

  // === ENTER (reducido) ===
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000); // antes 5000

  // === 6 TABs (acelerados) ===
  for(int i = 0; i < 6; i++) {
    DigiKeyboard.sendKeyStroke(43);
    DigiKeyboard.delay(200); // antes 800
  }

  // === 3 FLECHAS DERECHA (aceleradas) ===
  for(int i = 0; i < 3; i++) {
    DigiKeyboard.sendKeyStroke(79);
    DigiKeyboard.delay(200); // antes 600
  }

  // === ENTER (reducido) ===
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500); // antes 1000

  // === 2 TABs (acelerados) ===
  for(int i = 0; i < 2; i++) {
    DigiKeyboard.sendKeyStroke(43);
    DigiKeyboard.delay(200); // antes 800
  }

  // === 14 FLECHAS DERECHA (aceleradas al máximo) ===
  for(int i = 0; i < 14; i++) {
    DigiKeyboard.sendKeyStroke(79);
    DigiKeyboard.delay(100); // antes 500, ahora más rápido
  }

  // Pequeña pausa antes de cerrar
  DigiKeyboard.delay(500); // antes 2000

  // === CERRAR VENTANA (ALT+F4) ===
  DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);
  DigiKeyboard.delay(500); // antes 2000

  // === DETENER PARA NO REPETIR ===
  while(1) { 
    DigiKeyboard.delay(10000); 
  }
}
