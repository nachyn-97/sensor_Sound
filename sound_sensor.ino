const int sensorD0 = 8;                      // Пин Arduino к которому подключен выход D0 датчика
const int diod = 9;                          // Пин Arduino к которому подключен светодиод
int diodState = LOW;                         // Статус светодиода "выключен"
long soundTime=0;                            // время первого хлопка
 
void setup (){
 Serial.begin (9600);

pinMode(diod, OUTPUT);                       // устанавливаем цифровой пин 2 в режим выхода 
}
 
void loop ()
{
int sensorValue = digitalRead(sensorD0);     // получаем сигнал с датчика
 
if (sensorValue == 1 && diodState == LOW)    //если порог громкости достигнут и светодиод был ВЫКЛЮЧЕН
{
long diodTime=millis();                      // записываем текущее время
 

if((millis()>soundTime) && ((diodTime-soundTime)>100) && ((diodTime-soundTime)<1000))
{
digitalWrite(diod, HIGH);                    // включаем светодиод
diodState = HIGH;                            // устанавливаем статус светодиода "включен"
delay(100);                                  // небольшая задержка для фильтрации помех
}
soundTime=millis();                          //записываем время последнего хлопка
}
else                                         // иначе
{
if (sensorValue == 1 && diodState == HIGH)   // если порог громкости достигнут и светодиод был ВКЛЮЧЕН
{
digitalWrite(diod, LOW);                     // выключаем светодиод
diodState = LOW;                             // устанавливаем статус светодиода "выключен"
delay(1000);                                 // небольшая задержка для фильтрации помех
}
}   
}
