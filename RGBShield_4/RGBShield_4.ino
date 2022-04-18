/**
 * Ejemplo de uso de RGBShield
 * Desplaza texto a través de los leds
 * Hace uso de las librerías
 *  Adafruit_GFX
 *  Adafruit_NeoMatrix
 *  Adafruit_NeoPixel
 */

 #include <Adafruit_GFX.h>
 #include <Adafruit_NeoMatrix.h>
 #include <Adafruit_NeoPixel.h>

#define CONTROL_PIN 6
#define VERTICAL    1

// Seleccionar como se ubica la matriz de LEDs
#ifdef VERTICAL
  #define WIDTH    5
  #define HEIGHT   8
#elif
  #define WIDTH    8
  #define HEIGHT   5
#endif

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(WIDTH, HEIGHT, CONTROL_PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

// El texto se mostrará en el primer color, después en el segundo etc
const uint16_t colors[] = {
    matrix.Color(255, 0, 0),    // rojo
    matrix.Color(0, 255, 0),    // verde
    matrix.Color(0, 0, 255),    // azul
    matrix.Color(128, 0, 128)   // morado
  };
#define COLOR_QTY (sizeof(colors)/sizeof(uint16_t))

/**
 * Configuración
 */
 void setup()
{ 
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
}


int x = 0;
int pass = 0;

void loop()
{
  matrix.fillScreen(0);
  matrix.setCursor(x, 0); // Coordenada en la matriz de led 
  matrix.print(F("Prueba"));
  if( --x < -36 ){
    x = matrix.width();
    if(++pass >= COLOR_QTY) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(150);
}
