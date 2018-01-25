///this code is written and tested for ncd.io wireless temperature humidity sensor with arduino due
///sensor data structure can be found here https://ncd.io/long-range-wireless-temperature-humidity-sensor/ 
/// sesnro can be found here https://store.ncd.io/shop/

  byte data[29];
  int ledpin=13;
  int chk=1;
  int k = 10;
void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop()
{
  
  if (Serial1.available())
  {
    data[0] = Serial1.read();
    delay(k);
   if(data[0]==0x7E)
{
  Serial.println("Starting1");
    while (!Serial1.available());
    data[1] = Serial1.read();
    delay(k); 
    data[2] = Serial1.read();
    data[3] = Serial1.read();
    data[4] = Serial1.read();  
    data[5] = Serial1.read();
    data[6] = Serial1.read();
    data[7] = Serial1.read(); 
    data[8] = Serial1.read();
    data[9] = Serial1.read();
    data[10] = Serial1.read();
    delay(k);
    data[11] = Serial1.read();
    data[12] = Serial1.read();
    data[13] = Serial1.read();  
    data[14] = Serial1.read();
    data[15] = Serial1.read();
    data[16] = Serial1.read(); 
    data[17] = Serial1.read();
    data[18] = Serial1.read();
    data[19] = Serial1.read();
    data[20] = Serial1.read();
    data[21] = Serial1.read();
    data[22] = Serial1.read();  
    data[23] = Serial1.read();
    data[24] = Serial1.read();
    delay(k);
    data[25] = Serial1.read(); 
    data[26] = Serial1.read();
    data[27] = Serial1.read();
    data[28] = Serial1.read();
    if(data[15]==0x7F)  /////// to check if the recive data is correct
    {
    
  if(data[22]==1)  //////// make sure the sensor type is correct
{  
  float humidity = ((((data[24]) * 256) + data[25]) /100.0);
  float cTemp = ((data[26] * 256) + (data[27])) /100.0;
  float fTemp = cTemp * 1.8 + 32;
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
   Serial.println(data[0]);
   Serial.println(data[1]);  Serial.println(data[2]);  Serial.println(data[3]);
    Serial.println(data[4]);  Serial.println(data[5]);  Serial.println(data[6]);
     Serial.println(data[7]); 
        Serial.println(data[8]);  Serial.println(data[9]);  Serial.println(data[10]);
    Serial.println(data[11]);  Serial.println(data[12]);  Serial.println(data[13]);
     Serial.println(data[14]);
        Serial.println(data[15]);  Serial.println(data[16]);  Serial.println(data[17]);
    Serial.println(data[18]);  Serial.println(data[19]);  Serial.println(data[20]);
     Serial.println(data[21]);
}
    }
  }
 
}
