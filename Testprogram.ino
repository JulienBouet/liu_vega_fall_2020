#include <math.h>
int Q1_pin=A0;
int Q2_pin=A3;
int Q3_pin=A2;
int Q4_pin=A1;
int Q1=0;
int Q2=0;
int Q3=0;
int Q4=0;
double alpha = 0;
double beta = 0;
const double alpha_max = 58;
const double beta_max = 58;

double Sa = 0;
double Sb = 0;
double voltage_sum = 0;
void setup() {
    Serial.begin(9600);
}

void loop() {
  Q1 = analogRead(Q1_pin);  // read the input pin
  Q2 = analogRead(Q2_pin);  // read the input pin
  Q3 = analogRead(Q3_pin);  // read the input pin
  Q4 = analogRead(Q4_pin);  // read the input pin
  // calculate the tangent
  voltage_sum = Q1 + Q2 + Q3 + Q4;
  Sa = ( Q1 + Q4 - (Q2 + Q3))/voltage_sum;
  Sb = ( Q1 + Q2 - (Q3 + Q4))/voltage_sum;
  alpha = atan(Sa*tan(alpha_max));
  beta = atan(Sb*tan(beta_max));
  Serial.print("Q1 = ");
  Serial.println(Q1);
  Serial.print("Q2 = ");
  Serial.println(Q2);
  Serial.print("Q3 = ");
  Serial.println(Q3);
  Serial.print("Q4 = ");
  Serial.println(Q4);
  Serial.println("_________");
  delay(1000);

}
