int count = 0;
int speeds = 85;
int speedl = 72;
int d = 100;
int yanascount = 0;

int distancevalue = 19;

int command;

bool parking = false;
bool yanas = false;
bool onpark = false;
bool leftpark = false;

// connect motor controller pins to Arduino digital pins
// motor Sol Ön
int enA = 8;
int in1 = 9;
int in2 = 10;

// motor Sol Arka
int enB = 13;
int in3 = 11;
int in4 = 12;

// motor Sağ Ön
int enB2 = 2;
int in32 = 4;
int in42 = 3;

// motor Sağ Arka
int enA2 = 7;
int in12 = 6;
int in22 = 5;

//Sol Ön sensör
const int trigPin_sol_on = 31; // Pin numaraları
const int echoPin_sol_on = 30; // Pin numaraları

long duration_sol_on; //variables
int distance_sol_on; //variables


//Sağ Arka sensör
const int trigPin_sag_arka =  25; // Pin numaraları
const int echoPin_sag_arka = 24; // Pin numaraları

long duration_sag_arka; //variables
int distance_sag_arka; //variables

//Sağ Ön sensör
const int trigPin_sag_on =  23; // Pin numaraları
const int echoPin_sag_on = 22; // Pin numaraları

long duration_sag_on; //variables
int distance_sag_on; //variables


//Sol Arka sensör
const int trigPin_sol_arka =  27; // Pin numaraları
const int echoPin_sol_arka = 26; // Pin numaraları

long duration_sol_arka; //variables
int distance_sol_arka; //variables

//Ön sensör
const int trigPin_on =  33; // Pin numaraları
const int echoPin_on = 32; // Pin numaraları

long duration_on; //variables
int distance_on; //variables

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA2, OUTPUT);
  pinMode(enB2, OUTPUT);
  pinMode(in12, OUTPUT);
  pinMode(in22, OUTPUT);
  pinMode(in32, OUTPUT);
  pinMode(in42, OUTPUT);

  //Sağ Ön  Sensor
  pinMode(trigPin_sag_on, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_sag_on, INPUT); // Sets the echoPin as an Input

  //Sol Arka Sensor
  pinMode(trigPin_sol_arka, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_sol_arka, INPUT); // Sets the echoPin as an Input

  //Sağ Arka Sensor
  pinMode(trigPin_sag_arka, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_sag_arka, INPUT); // Sets the echoPin as an Input

  //Sol Ön Sensor
  pinMode(trigPin_sol_on, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_sol_on, INPUT); // Sets the echoPin as an Input

  //Ön Sensor
  pinMode(trigPin_on, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin_on, INPUT); // Sets the echoPin as an Input

  Serial.begin(115200);
}

int sensorDistance(const int echoPin, const int trigPin, long duration, int distance) {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Returns the distance on the Serial Monitor
  return distance;
}

void rotateRight() {
  //Bu kısım için maksimum hız limiti 255

  //Sol ön motor saat yönünün tersi yönde döner
  Serial.print("arac saat yönğnde yonde dönüyor");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speeds);

  //Sol arka motor saat yönünün tersi yönde döner
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speeds);

  //Sağ arka motor saat yönünde döner
  digitalWrite(in12, LOW);
  digitalWrite(in22, HIGH);
  analogWrite(enA2, speedl);

  //Sağ ön motor saat yönünde döner
  digitalWrite(in32, LOW);
  digitalWrite(in42, HIGH);
  analogWrite(enB2, speedl);

}

void rotateLeft() {
  //Bu kısım için maksimum hız limiti 255

  //Sol ön motor saat yönünün tersi yönde döner
  Serial.print("arac saat yönğnde yonde dönüyor");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speeds);

  //Sol arka motor saat yönünün tersi yönde döner
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speeds);

  //Sağ arka motor saat yönünde döner
  digitalWrite(in12, HIGH);
  digitalWrite(in22, LOW);
  analogWrite(enA2, speedl);

  //Sağ ön motor saat yönünde döner
  digitalWrite(in32, HIGH);
  digitalWrite(in42, LOW);
  analogWrite(enB2, speedl);

}

void Return() {
  //Bu kısım için maksimum hız limiti 255
  //Araç geri geri gider
  Serial.print("arac geri yonde gidiyor");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speeds);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speeds);

  digitalWrite(in12, LOW);
  digitalWrite(in22, HIGH);
  analogWrite(enA2, speedl);

  digitalWrite(in32, LOW);
  digitalWrite(in42, HIGH);
  analogWrite(enB2, speedl);

}

void Drive() {
  //Bu kısım için maksimum hız limiti 255
  //Araç ileri yönde gider
  Serial.print("arac ileri yonde gidiyor");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speeds);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speeds);

  digitalWrite(in12, HIGH);
  digitalWrite(in22, LOW);
  analogWrite(enA2, speedl);

  digitalWrite(in32, HIGH);
  digitalWrite(in42, LOW);
  analogWrite(enB2, speedl);
}
void Stop() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, speeds);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, speeds);

  digitalWrite(in12, LOW);
  digitalWrite(in22, LOW);
  analogWrite(enA2, speedl);

  digitalWrite(in32, LOW);
  digitalWrite(in42, LOW);
  analogWrite(enB2, speedl);
  Serial.println("DURRRRRR");

}

void loop()
{
  

  if (Serial.available() > 0) {

    command = Serial.read();
   /* Serial.print("Command: ");
    Serial.println(command);
    Serial.println(parking);
    Serial.println(yanas);*/
    switch (command) {
      case 'F': Drive(); break;
      case 'B': Return(); break;
      case 'L': rotateLeft(); break;
      case 'R': rotateRight(); break;
      case 'S': Stop(); break;
      case 'V': parking = true; count = 0; break;
      case 'v': parking = false; break;
      case 'W': yanas = true; break;
      case 'w': yanas = false; break;
      case 'G': leftpark = true; break;
      case 'I': leftpark = false; break;
      case 'H': onpark = true; break;
      case 'J': onpark = false; break;
    }
  }

  if (onpark == true) {
    // ON PARK
    yanas = false;
    parking = false;
    distance_sag_on = sensorDistance(echoPin_sag_on, trigPin_sag_on, duration_sag_on, distance_sag_on);
    Serial.println("Sağ Ön Sensör Değeri: ");
    Serial.println(distance_sag_on);
    delay(4);

    distance_sol_arka = sensorDistance(echoPin_sol_arka, trigPin_sol_arka, duration_sol_arka, distance_sol_arka);
    Serial.println("Sol Arka Sensör Değeri: ");
    Serial.println(distance_sol_arka);
    delay(4);

    distance_sag_arka = sensorDistance(echoPin_sag_arka, trigPin_sag_arka, duration_sag_arka, distance_sag_arka);
    Serial.println("Sağ Arka Sensör Değeri: ");
    Serial.println(distance_sag_arka);
    delay(4);

    distance_sol_on = sensorDistance(echoPin_sol_on, trigPin_sol_on, duration_sol_on, distance_sol_on);
    Serial.println("Sol Ön Sensör Değeri: ");
    Serial.println(distance_sol_on);
    delay(4);

    distance_on = sensorDistance(echoPin_on, trigPin_on, duration_on, distance_on);
    Serial.println("Ön Sensör Değeri: ");
    Serial.println(distance_on);
    delay(4);

    if (distance_on < 3) {
      Stop();
    }

    else if (distance_sol_on < distancevalue && distance_sol_arka < distancevalue && distance_on > 10 && count == 0) {
      Drive();
      delay(d);
      count  = 0;
      Stop();
    }

    else if (distance_sol_on > distancevalue && distance_sol_arka < distancevalue && distance_on > 10 && (count == 0 || count == 1)) {
      Drive();
      delay(d);
      count = 1;
    }
    else if (distance_sol_on > distancevalue && distance_sol_arka > distancevalue && distance_on > 10 && (count == 1)) {

      Return();
      delay(100);
      count = 2;
      Stop();
      rotateLeft();
      delay(600);
    }

    else if ((distance_on > 5) && (count == 2 || count == 3)) {
      Drive();
      delay(d/3);
      Stop();
      rotateLeft();
      delay(d / 9);
      Stop();
      //Serial.println("CASE 4 - GERİ GİDİYOR");
      count = 3;
    }


    else if (distance_on <= 5 && distance_on >  3 && (count == 3)) {
      rotateRight();
      delay(720);
      Stop();
      //Serial.println("CASE 4 - GERİ GİDİYOR");
      count = 4;
    }
    else if (distance_on >  4 && (count == 4)) {
      Drive();
      delay(40);
      Stop();
      //Serial.println("CASE 4 - GERİ GİDİYOR");
      count = 4;
    }

    Stop();

  }

  if (parking == true && leftpark == true) {
    yanas = false;
    onpark = false;
    distance_sag_on = sensorDistance(echoPin_sag_on, trigPin_sag_on, duration_sag_on, distance_sag_on);
    Serial.println("Sağ Ön Sensör Değeri: ");
    Serial.println(distance_sag_on);
    delay(4);

    distance_sol_arka = sensorDistance(echoPin_sol_arka, trigPin_sol_arka, duration_sol_arka, distance_sol_arka);
    Serial.println("Sol Arka Sensör Değeri: ");
    Serial.println(distance_sol_arka);
    delay(4);

    distance_sag_arka = sensorDistance(echoPin_sag_arka, trigPin_sag_arka, duration_sag_arka, distance_sag_arka);
    Serial.println("Sağ Arka Sensör Değeri: ");
    Serial.println(distance_sag_arka);
    delay(4);

    distance_sol_on = sensorDistance(echoPin_sol_on, trigPin_sol_on, duration_sol_on, distance_sol_on);
    Serial.println("Sol Ön Sensör Değeri: ");
    Serial.println(distance_sol_on);
    delay(4);

    distance_on = sensorDistance(echoPin_on, trigPin_on, duration_on, distance_on);
    Serial.println("Ön Sensör Değeri: ");
    Serial.println(distance_on);
    delay(4);

    if (distance_on < 3
       ) {
      Stop();
    }

    else if (distance_sol_on < distancevalue && distance_sol_arka < distancevalue && distance_on > 10 && count == 0) {
      Drive();
      delay(d);
      count  = 0;
    }

    else if (distance_sol_on > distancevalue && distance_sol_arka < distancevalue && distance_on > 10 && (count == 0 || count == 1)) {
      Drive();
      delay(d);
      count = 1;
    }
    else if (distance_sol_on > distancevalue && distance_sol_arka > distancevalue && distance_on > 10 && (count == 1 || count == 2)) {

      Drive();
      delay(d);
      count = 2;
    }

    else if (distance_sol_on < distancevalue && distance_sol_arka > 14 && distance_on > distancevalue && (count == 2 || count == 3)) {
      Drive();
      delay(d);
      Stop();
      count = 3;
    }

    else if (distance_sol_arka < distancevalue && distance_sol_arka > 2 && (count == 3 || count == 4)) {
      Return();
      delay(d);
      Stop();
      //Serial.println("CASE 4 - GERİ GİDİYOR");
      count = 4;
    }

    else if (distance_sol_arka > distancevalue && distance_sol_on < distancevalue && distance_sol_on > 5 && (count == 4 || count == 5)) {
      Return();
      delay(350);

      rotateRight();
      delay(600);

      Return();
      delay(500);

      rotateLeft();
      delay(670);

      Stop();
      count = 6;
      parking = false;
    }

    Stop();

  }

  if (parking == true && leftpark == false) { // SAG PARK
    yanas = false;
    distance_sag_on = sensorDistance(echoPin_sag_on, trigPin_sag_on, duration_sag_on, distance_sag_on);
    Serial.println("Sağ Ön Sensör Değeri: ");
    Serial.println(distance_sag_on);
    delay(4);

    distance_sol_arka = sensorDistance(echoPin_sol_arka, trigPin_sol_arka, duration_sol_arka, distance_sol_arka);
    Serial.println("Sol Arka Sensör Değeri: ");
    Serial.println(distance_sol_arka);
    delay(4);

    distance_sag_arka = sensorDistance(echoPin_sag_arka, trigPin_sag_arka, duration_sag_arka, distance_sag_arka);
    Serial.println("Sağ Arka Sensör Değeri: ");
    Serial.println(distance_sag_arka);
    delay(4);

    distance_sol_on = sensorDistance(echoPin_sol_on, trigPin_sol_on, duration_sol_on, distance_sol_on);
    Serial.println("Sol Ön Sensör Değeri: ");
    Serial.println(distance_sol_on);
    delay(4);

    distance_on = sensorDistance(echoPin_on, trigPin_on, duration_on, distance_on);
    Serial.println("Ön Sensör Değeri: ");
    Serial.println(distance_on);
    delay(4);

    if (distance_on < 3
       ) {
      Stop();
    }

    else if (distance_sag_on < distancevalue && distance_sag_arka < distancevalue && distance_on > 10 && count == 0) {
      Drive();
      delay(d);
      count  = 0;
    }

    else if (distance_sag_on > distancevalue && distance_sag_arka < distancevalue && distance_on > 10 && (count == 0 || count == 1)) {
      Drive();
      delay(d);
      count = 1;
    }
    else if (distance_sag_on > distancevalue && distance_sag_arka > distancevalue && distance_on > 10 && (count == 1 || count == 2)) {

      Drive();
      delay(d);
      count = 2;
    }

    else if (distance_sag_on < distancevalue && distance_sag_arka > distancevalue && distance_on > 14 && (count == 2 || count == 3)) {
      Drive();
      delay(d);
      Stop();
      count = 3;
    }

    else if (distance_sag_arka < distancevalue && distance_sag_arka > 2 && (count == 3 || count == 4)) {
      Return();
      delay(d);
      Stop();
      //Serial.println("CASE 4 - GERİ GİDİYOR");
      count = 4;
    }

    else if (distance_sag_arka > distancevalue && distance_sag_on < distancevalue && distance_sag_on > 5 && (count == 4 || count == 5)) {
      Return();
      delay(350);

      rotateLeft();
      delay(650);

      Return();
      delay(500);

      rotateRight();
      delay(600);

      Stop();
      count = 6;
      parking = false;
    }

    Stop();
  }
  Serial.print ("YANAS: ");
  Serial.println (yanas);

  Serial.print ("LEFTPARK: ");
  Serial.println (yanas);
  if (yanas == true && leftpark == true) { // SOLA YANAS
    Serial.print ("MESAJ: ");
    Serial.println ("MEKANDAYIM");
    parking = false;

    distance_sag_on = sensorDistance(echoPin_sag_on, trigPin_sag_on, duration_sag_on, distance_sag_on);
    Serial.println("Sağ Ön Sensör Değeri: ");
    Serial.println(distance_sag_on);
    delay(4);

    distance_sol_arka = sensorDistance(echoPin_sol_arka, trigPin_sol_arka, duration_sol_arka, distance_sol_arka);
    Serial.println("Sol Arka Sensör Değeri: ");
    Serial.println(distance_sol_arka);
    delay(4);

    distance_sag_arka = sensorDistance(echoPin_sag_arka, trigPin_sag_arka, duration_sag_arka, distance_sag_arka);
    Serial.println("Sağ Arka Sensör Değeri: ");
    Serial.println(distance_sag_arka);
    delay(4);

    distance_sol_on = sensorDistance(echoPin_sol_on, trigPin_sol_on, duration_sol_on, distance_sol_on);
    Serial.println("Sol Ön Sensör Değeri: ");
    Serial.println(distance_sol_on);
    delay(4);

    distance_on = sensorDistance(echoPin_on, trigPin_on, duration_on, distance_on);
    Serial.println("Ön Sensör Değeri: ");
    Serial.println(distance_on);
    delay(4);

    
    //ilk şart eğer araba açıktaysa ve sol tarafında park edebileceği bir yer var mı diye bakıyor
    if (distance_sol_on > distancevalue &&  distance_sol_arka > distancevalue && distance_on > 10 && (yanascount == 0 || yanascount == 1)) {
      // araba duvara doğru yaklaşıyor mesefe 20 a düşene kadar
      rotateLeft();
      delay(170);
      Stop();
      Drive();
      delay(200);
      rotateRight();
      delay(160);
      Stop();
      yanascount = 1;
    }

    else if ( (distance_sol_on + 3 < distance_sol_arka) && (yanascount == 1 || yanascount == 2)) {
      rotateRight();
      delay(10);
      Stop();
      yanascount = 2;
    }
    else if ( (distance_sol_on > distance_sol_arka + 3) && (yanascount == 1 || yanascount == 2)) {
      rotateLeft();
      delay(10);
      Stop();
      yanascount = 2;

    }

    else if ((distance_sol_on - distance_sol_arka <3) && (distance_sol_arka - distance_sol_on  < 3)  && (yanascount == 1 || yanascount == 2)) {
      yanascount = 3;
      yanas = false;

    }
  }

}
