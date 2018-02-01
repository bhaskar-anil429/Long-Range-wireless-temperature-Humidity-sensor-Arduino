///this code is written and tested for ncd.io wireless temperature humidity sensor with arduino due
///sensor data structure can be found here https://ncd.io/long-range-wireless-temperature-humidity-sensor/ 
/// sesnro can be found here https://store.ncd.io/shop/

  uint8_t data[29];
  int k = 10;
  int i;
void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial.println("ncd.io IoT Arduino wireless temperature Humidity sensor");
}

void loop()
{
  
  if (Serial1.available())
  {
    data[0] = Serial1.read();
    delay(k);
   if(data[0]==0x7E)
    {
    while (!Serial1.available());
    for ( i = 1; i< 29; i++)
      {
      data[i] = Serial1.read();
      delay(1);
      }
    if(data[15]==0x7F)  /////// to check if the recive data is correct
      {
  if(data[22]==1)  //////// make sure the sensor type is correct
         {  
  float humidity = ((((data[24]) * 256) + data[25]) /100.0);
  int16_t cTempint = (((unit16_t)/data[26])<<8)| data[27];
  float cTemp = (float)cTempint /100.0;
  float fTemp = cTemp * 1.8 + 32;
  float battery = ((data[18] * 256) + data[19]);
  float voltage = 0.00322 * battery;
  Serial.print("Sensor Number  ");
  Serial.println(data[16]);
  Serial.print("Sensor Type  ");
  Serial.println(data[22]);
  Serial.print("Firmware Version  ");
  Serial.println(data[17]);
  Serial.print("Relative Humidity :");
  Serial.print(humidity);
  Serial.println(" %RH");
  Serial.print("Temperature in Celsius :");
  Serial.print(cTemp);
  Serial.println(" C");
  Serial.print("Temperature in Fahrenheit :");
  Serial.print(fTemp);
  Serial.println(" F");
  Serial.print("ADC value:");
  Serial.println(battery);
  Serial.print("Battery Voltage:");
  Serial.print(voltage);
  Serial.println("\n");
  if (voltage < 1)
          {
    Serial.println("Time to Replace The Battery");
          }
  
        }
      }
else
{
      for ( i = 0; i< 29; i++)
    {
      Serial.print(data[i]);
      Serial.print(" , ");
      delay(1);
    }
}
    }
  }
 
}
