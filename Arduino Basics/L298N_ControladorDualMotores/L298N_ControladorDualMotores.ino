/*
 * Codigo creado por Alberto Eugenio
 * Codigo diseñado para controlar un carro en modo tanque
 */

# define motor_d_adelante 6
# define motor_d_atras 7

# define motor_i_adelante 8
# define motor_i_atras 9

void setup() 
{
  pinMode(motor_d_adelante, OUTPUT);
  pinMode(motor_d_atras, OUTPUT);
  pinMode(motor_i_adelante, OUTPUT);
  pinMode(motor_i_atras, OUTPUT);
}

void loop() 
{
  adelante();
  atras();
  derecha();
  izquierda();
}

void adelante()
  {
    digitalWrite(motor_d_adelante, HIGH);
    digitalWrite(motor_i_adelante, HIGH);
    delay(1000);
    digitalWrite(motor_d_adelante, LOW);
    digitalWrite(motor_i_adelante, LOW);
  }

void izquierda()
  {
    digitalWrite(motor_d_adelante, HIGH);
    digitalWrite(motor_i_atras, HIGH);
    delay(1000);
    digitalWrite(motor_d_adelante, LOW);
    digitalWrite(motor_i_atras, LOW);
  }

void derecha()
  {
    digitalWrite(motor_d_atras, HIGH);
    digitalWrite(motor_i_adelante, HIGH);
    delay(1000);
    digitalWrite(motor_d_atras, LOW);
    digitalWrite(motor_i_aadelante, LOW);
  }

void atras()
  {
    digitalWrite(motor_d_atras, HIGH);
    digitalWrite(motor_i_atras, HIGH);
    delay(1000);
    digitalWrite(motor_d_atras, LOW);
    digitalWrite(motor_i_atras, LOW);
  }

void alto()
  {
    digitalWrite(motor_d_adelante, LOW);
    digitalWrite(motor_i_adelante, LOW);
    digitalWrite(motor_d_atras, LOW);
    digitalWrite(motor_i_atras, LOW);
    delay(1000);
  }
