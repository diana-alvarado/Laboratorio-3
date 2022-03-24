  #define RED_LED PF_1
  #define GREEN_LED PF_3
  #define J1 PF_4
  #define J2 PF_0
  
  #define J1_1 PB_5
  #define J1_2 PB_0
  #define J1_3 PB_1
  #define J1_4 PE_4
  #define J1_5 PE_5
  #define J1_6 PB_4
  #define J1_7 PA_5
  #define J1_8 PA_6

  #define J2_1 PD_0
  #define J2_2 PD_1
  #define J2_3 PD_2
  #define J2_4 PD_3
  #define J2_5 PE_1
  #define J2_6 PE_2
  #define J2_7 PE_3
  #define J2_8 PB_3

  int b1 = 0;
  int b2 = 0;
  int bs = 0;
  int bsem = 0;
  int J1i = 1;
  int J2i = 1;
  int cont1 = 0;
  int cont2 = 0;
  int Jr1 = 0;
  int Jr2 = 0;
 
   
  void setup() {
    
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(J1, INPUT_PULLUP);
  pinMode(J2, INPUT_PULLUP);
  
  pinMode(J1_1, OUTPUT);
  pinMode(J1_2, OUTPUT);
  pinMode(J1_3, OUTPUT);
  pinMode(J1_4, OUTPUT);
  pinMode(J1_5, OUTPUT);
  pinMode(J1_6, OUTPUT);
  pinMode(J1_7, OUTPUT);
  pinMode(J1_8, OUTPUT);
  pinMode(J2_1, OUTPUT);
  pinMode(J2_2, OUTPUT);
  pinMode(J2_3, OUTPUT);
  pinMode(J2_4, OUTPUT);
  pinMode(J2_5, OUTPUT);
  pinMode(J2_6, OUTPUT);
  pinMode(J2_7, OUTPUT);
  pinMode(J2_8, OUTPUT);  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  J1i = digitalRead(J1); //Leer el botón de J1
  J2i = digitalRead(J2); // Leer el botón de J2
//  Serial.print("J1: ");
//  Serial.print(J1i);
//  Serial.print(" J2: ");
//  Serial.println(J2i);
//  delay(500);

  Serial.print(" cont1: ");
  Serial.println(cont1);
  Serial.print(" cont2: ");
  Serial.println(cont2);
  delay(500);
  
  if((J1i == 0) || (J2i == 0) && (bs == 0)){ //Si alguno de los dos está presionado, encender bandera de inicio y de sem
     bsem = 1; //Bandera sem
     if((bsem == 1) && (bs == 0)){
      //Si la bandera sem encnedida
      sem(); //Iniciar semaforo
      bsem = 0; //Apagar bandera
      bs = 1; //Ya inicia el juego
      
  }
  }

  Jr1 = digitalRead(J1);
  Jr2 = digitalRead(J2);
  
  //Contador del Jugador 1
  if ((Jr1 == 0) && (bs == 1)){
    b1 = 1;
    //Jr1 = digitalRead(J1);
    if((b1 == 1) ){
      cont1 = cont1 + 1;
      if(cont1 == 9){
        digitalWrite(RED_LED, 1);
        delay(5000);
        bs = 0;
        cont1 = 0;
        cont2 = 0;
      }
      b1 = 0;
    }
  }

  if ((Jr2 == 0) && (bs == 1)){
    b2 = 1;
    //Jr2 = digitalRead(J2);
    if((b2 == 1)){
      cont2 = cont2 + 1;
      b2 = 0;
      if(cont2 == 9){
        digitalWrite(GREEN_LED, 1);
        delay(5000);
        bs = 0;
        cont2 = 0;
        cont1 = 0;
      }
    }
  }
  calc1(cont1);
  calc2(cont2);
}

void sem (void){
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(2000);
  digitalWrite(GREEN_LED, HIGH);
  delay(2000);
  digitalWrite(RED_LED, LOW);
  delay(2000);
  digitalWrite(GREEN_LED, LOW);
}

void calc1 (int valor){
  switch(valor){
    case(0):
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 0);
      break;
    case(1):
      digitalWrite(J1_1, 1);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 0);
      break;
    case(2):
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 1);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 0);
      break;
    case(3):
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 1);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 0);
      break;
    case(4):
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 1);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 0);
      break;
    case(5):
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 1);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 0);
      break;
    case(6):
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 1);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 0);
      break;
    case(7):
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 1);
      digitalWrite(J1_8, 0);
      break;
    case(8): 
      digitalWrite(J1_1, 0);
      digitalWrite(J1_2, 0);
      digitalWrite(J1_3, 0);
      digitalWrite(J1_4, 0);
      digitalWrite(J1_5, 0);
      digitalWrite(J1_6, 0);
      digitalWrite(J1_7, 0);
      digitalWrite(J1_8, 1);
      break;
  }
}

void calc2(int valor2){
  switch(valor2){
    case 0:
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 0);
      break;
    case(1):
      digitalWrite(J2_1, 1);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 0);
      break;
    case(2):
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 1);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 0);
      break;
    case(3):
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 1);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 0);
      break;
    case(4):
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 1);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 0);
      break;
    case(5):
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 1);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 0);
      break;
    case(6):
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 1);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 0);
      break;
    case(7):
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 1);
      digitalWrite(J2_8, 0);
      break;
    case(8):
      digitalWrite(J2_1, 0);
      digitalWrite(J2_2, 0);
      digitalWrite(J2_3, 0);
      digitalWrite(J2_4, 0);
      digitalWrite(J2_5, 0);
      digitalWrite(J2_6, 0);
      digitalWrite(J2_7, 0);
      digitalWrite(J2_8, 1);
      break;
  }
}
