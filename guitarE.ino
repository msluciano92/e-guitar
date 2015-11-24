//Tonos
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Define cuerdas
#define button0 23
#define button1 25
#define button2 27
#define button3 29
#define button4 31
#define button5 33

//Define parlante
#define pinSound 8

//Define sensor de distancia
#define echo 12
#define trigger 13

//Define power
#define power 10

float distancia;
float tiempo;
String control = "si";

//Lectura desde los pulsadores
int valor0 = 0;
int valor1 = 0;
int valor2 = 0;
int valor3 = 0;
int valor4 = 0;
int valor5 = 0;

//Define notes
//Default notes
int array0  [] = {NOTE_E6, NOTE_B5, NOTE_G5, NOTE_D5, NOTE_A4, NOTE_E4};

int array1  [] = {NOTE_F6, NOTE_C6, NOTE_GS5, NOTE_DS5, NOTE_AS4, NOTE_F4};
int array2  [] = {NOTE_FS6, NOTE_CS6, NOTE_A5, NOTE_E5, NOTE_B4, NOTE_FS4};
int array3  [] = {NOTE_G6, NOTE_D6, NOTE_AS5, NOTE_F5, NOTE_C5, NOTE_G4};
int array4  [] = {NOTE_GS6, NOTE_DS6, NOTE_B5, NOTE_FS5, NOTE_CS5, NOTE_GS4};
int array5  [] = {NOTE_A6, NOTE_E6, NOTE_C6, NOTE_G5, NOTE_D5, NOTE_A4};
int array6  [] = {NOTE_AS6, NOTE_F6, NOTE_CS6, NOTE_GS5, NOTE_DS5, NOTE_AS4};
int array7  [] = {NOTE_B6, NOTE_FS6, NOTE_D6, NOTE_A5, NOTE_E5, NOTE_B4};
int array8  [] = {NOTE_C7, NOTE_G6, NOTE_DS6, NOTE_AS5, NOTE_F5, NOTE_C5};
int array9  [] = {NOTE_CS7, NOTE_GS6, NOTE_E6, NOTE_B5, NOTE_FS5, NOTE_CS5};
int array10 [] = {NOTE_D7, NOTE_A6, NOTE_F6, NOTE_C6, NOTE_G5, NOTE_D5};
int array11 [] = {NOTE_DS7, NOTE_AS6, NOTE_FS6, NOTE_CS6, NOTE_GS5, NOTE_DS5};
int array12 [] = {NOTE_E7, NOTE_B6, NOTE_G6, NOTE_D6, NOTE_A5, NOTE_E5};

void setup() {
  
  pinMode(button0, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  
  pinMode(pinSound,OUTPUT);

  pinMode(power,OUTPUT);
  
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT);
  
  Serial.begin(9600);
}

void sing(int a){
    // cuerda accionada --> a
    digitalWrite(trigger,LOW); 
    delayMicroseconds(5);
    digitalWrite(trigger, HIGH); 
    delayMicroseconds(10);
    tiempo=pulseIn(echo, HIGH); 
    distancia= 0.017*tiempo;
    
    //default
    if((distancia>41 )||(distancia<=9.8 )){
      tone(pinSound, array0[a]);  
    }

    
    if((distancia<41 )&&(distancia>=37.9 )){
      tone(pinSound, array1[a]);  
    }
    if((distancia<37.9 )&&(distancia>=35 )){
      tone(pinSound, array2[a]);
    }
    if((distancia<35 )&&(distancia>=29.62 )){
      tone(pinSound, array3[a]);
    }
    if((distancia<29.62 )&&(distancia>=27 )){
      tone(pinSound, array4[a]);
    }
    if((distancia<27 )&&(distancia>=25.6 )){
      tone(pinSound, array5[a]);
    }
    if((distancia<25.6 )&&(distancia>=23.6 )){
      tone(pinSound, array6[a]);
    }
    if((distancia<23.6 )&&(distancia>=21.3 )){
      tone(pinSound, array7[a]);
    }
    if((distancia<21.3 )&&(distancia>=17.5 )){
      tone(pinSound, array8[a]);
    }
    if((distancia<17.5 )&&(distancia>=15.75 )){
      tone(pinSound, array9[a]);
    }
    if((distancia<15.75 )&&(distancia>=13.38 )){
      tone(pinSound, array10[a]);
    }
    if((distancia<13.38 )&&(distancia>=11.22 )){
      tone(pinSound, array11[a]);
    }
    if((distancia<11.22 )&&(distancia>=9.8 )){
      tone(pinSound, array12[a]);
    }
        
    delay(500);
    noTone(pinSound);
    
}

void prueba(){
  for(int i = 5; i>=0; i--){
    tone(pinSound, array0[i], 500);
    delay(500);
    tone(pinSound, array1[i], 500);
    delay(500);
    tone(pinSound, array2[i], 500);
    delay(500);
    tone(pinSound, array3[i], 500);
    delay(500);
    tone(pinSound, array4[i], 500);
    delay(500);
    tone(pinSound, array5[i], 500);
    delay(500);
    tone(pinSound, array6[i], 500);
    delay(500);
    tone(pinSound, array7[i], 500);
    delay(500);
    tone(pinSound, array8[i], 500);
    delay(500);
    tone(pinSound, array9[i], 500);
    delay(500);
    tone(pinSound, array10[i], 500);
    delay(500);
    tone(pinSound, array11[i], 500);
    delay(500);
    tone(pinSound, array12[i], 500);
    delay(500);
  }
}

void test(){
  if(control=="si"){
    digitalWrite(trigger,LOW); 
    delayMicroseconds(5);
    digitalWrite(trigger, HIGH); 
    delayMicroseconds(10);
    tiempo=pulseIn(echo, HIGH);    
    tone(pinSound, array4[3],500);
    Serial.println("Todos los sensores estan listos");
    control="no";
  }
}

void testSensor() {
  digitalWrite(trigger,LOW); 
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH); 
  delayMicroseconds(10);
  tiempo=pulseIn(echo, HIGH);    
  distancia= 0.017*tiempo;
  Serial.println(distancia);
  delay(500);
}

void loop() { 
  digitalWrite(power, HIGH);
  //testSensor();   //Testeo de distancias
  test();           //Iniciación de sensor
  valor0 = digitalRead(button0);
  valor1 = digitalRead(button1);
  valor2 = digitalRead(button2);
  valor3 = digitalRead(button3);
  valor4 = digitalRead(button4);
  valor5 = digitalRead(button5);

  if(valor0){
    sing(5);
    Serial.println("Tocó la cuerda:");    
    Serial.println(1);
  }
  if(valor1){
    sing(4);
    Serial.println("Tocó la cuerda:"); 
    Serial.println(2);
  }
  if(valor2){
    sing(3); 
    Serial.println("Tocó la cuerda:");
    Serial.println(3);   
  }
  if(valor3){
    sing(2);    
    Serial.println("Tocó la cuerda:");
    Serial.println(4);
  }
  if(valor4){
    sing(1);
    Serial.println("Tocó la cuerda:");
    Serial.println(5);    
  }
  if(valor5){
    sing(0);    
    Serial.println("Tocó la cuerda:");
    Serial.println(6);
  } 
  
}
