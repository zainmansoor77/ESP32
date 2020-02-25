extern "C" // Extern C is used when we are using a funtion written in "C" language in a C++ code.
{

  uint8_t temprature_sens_read(); // This function is written in C language
}

uint8_t temprature_sens_read();

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Temperature in deg Celcius: ");

  // Convert raw temperature in F to Celsius degrees
  Serial.print((temprature_sens_read() - 32) / 1.8);
  Serial.println(" C");
  delay(500);
}
