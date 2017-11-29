
//Определяем, какие порты будем использовать для управления моторами
#define M1_1 2
#define M1_2 3
#define M2_1 4
#define M2_2 5

unsigned char Forward_Speed = 129;
unsigned char Back_Speed = 129;

void setup() {

//Объявляем пины управления мостом как выходы
pinMode(M1_1, OUTPUT);
pinMode(M1_2, OUTPUT);
pinMode(M2_1, OUTPUT);
pinMode(M2_2, OUTPUT);

//Открываем сеанс serial connection
Serial.begin(9600);

}


void loop() {


if(Serial.available()){

  int data = Serial.read();

  //Врубает 1-й мотор вперёд (против часовой стрелки)
  if(data == 'w'){
    analogWrite(M1_1, Forward_Speed); 
    analogWrite(M1_2, 0);
  }

  //Врубает 1-й мотор назад (по часовой стрелке)
  if(data == 's'){
    analogWrite(M1_1, 0); 
    analogWrite(M1_2, Back_Speed);
  }

  //Врубает 2-й мотор вперёд (против часовой стрелки)
  if(data == 'a'){
    analogWrite(M2_1, Forward_Speed); 
    analogWrite(M2_2, 0);
  }

  //Врубает 2-й мотор назад (по часовой стрелке)
  if(data == 'd'){
    analogWrite(M2_1, 0); 
    analogWrite(M2_2, Back_Speed);
  }

  //Вырубает 1-й мотор
  if(data == 'x'){
    analogWrite(M1_1, 0); 
    analogWrite(M1_2, 0);
  }

  //Вырубает 2-й мотор
  if(data == 'y'){
    analogWrite(M2_1, 0); 
    analogWrite(M2_2, 0);
  }

}




}
