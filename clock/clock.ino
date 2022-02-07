// COORDINATES // use char_hand_drawing_for_arduino.html to draw characters
int x_coords_0[] = {1,1,2,3,5,7,9,12,15,18,21,24,25,26,26,26,26,24,20,18,15,12,8,6,4,2,2,2,2,2};
int x_coords_1[] = {1,4,7,9,10,12,12,12,12,12,12,13,13,13,10,6,2,3,8,12,15,18,20};
int x_coords_2[] = {1,3,5,8,10,12,15,18,22,22,22,21,18,16,13,10,7,4,1,4,9,16,19,22};
int x_coords_3[] = {1,3,6,9,12,15,18,20,21,21,21,21,19,17,15,12,10,11,15,18,19,20,21,21,21,19,17,13,9,7,5,4};
int x_coords_4[] = {17,14,10,7,5,4,2,0,0,5,12,16,19,20,20,20,20,20,20,20,20,20,21,21,21,21,21};
int x_coords_5[] = {25,21,17,14,11,9,6,4,4,4,4,4,5,6,8,11,14,16,19,21,23,23,23,22,20,18,15,12,9,8,7};
int x_coords_6[] = {20,17,14,10,8,5,4,2,1,0,0,0,2,4,6,9,12,15,17,19,19,20,19,18,15,12,9,7,5,4};
int x_coords_7[] = {2,5,8,11,14,16,19,22,23,21,20,19,17,17,14,14,12,11,10,9,8,8};
int x_coords_8[] = {19,16,13,10,7,6,4,3,2,2,3,5,8,11,16,18,20,20,19,15,13,10,9,6,5,4,4,4,5,7,10,13,16,18,20,21,22,22,21,19};
int x_coords_9[] = {21,21,20,18,15,13,11,8,6,4,2,2,2,2,4,5,8,12,16,20,22,23,25,25,25,25,24,24,24,24,24,24,25,25,25,26};
int x_coords_colon[] = {2,4,4};
int y_coords_0[] = {75,78,80,83,85,86,87,88,89,89,86,82,78,73,69,64,60,56,52,50,50,50,53,55,57,59,63,66,69,72};
int y_coords_1[] = {1,4,7,9,10,12,12,12,12,12,12,13,13,13,10,6,2,3,8,12,15,18,20};
int y_coords_2[] = {1,3,5,8,10,12,15,18,22,22,22,21,18,16,13,10,7,4,1,4,9,16,19,22};
int y_coords_3[] = {79,82,84,86,86,86,86,85,83,80,77,74,71,70,68,67,65,65,65,65,63,59,57,54,50,48,46,46,46,47,49,51};
int y_coords_4[] = {88,86,84,82,80,78,77,74,73,73,73,73,73,75,81,87,90,86,78,73,68,65,61,57,54,51,48};
int y_coords_5[] = {89,89,90,90,90,91,91,90,87,84,81,78,75,71,70,71,73,74,74,72,70,67,64,61,59,57,56,56,56,58,60};
int y_coords_6[] = {87,87,87,86,84,83,81,77,74,71,68,64,60,56,53,52,51,51,52,53,57,59,61,63,63,63,63,62,61,58};
int y_coords_7[] = {89,89,89,89,89,90,90,90,88,87,84,81,79,76,73,70,68,65,63,61,59,56};
int y_coords_8[] = {88,89,89,89,88,85,83,80,77,74,71,68,67,66,65,61,57,54,51,49,48,48,50,52,55,58,62,65,67,69,70,72,74,76,78,80,82,85,87,88};
int y_coords_9[] = {81,84,86,87,87,88,89,89,88,87,85,82,79,75,72,69,67,67,67,69,72,75,79,82,85,88,86,80,75,71,67,64,61,58,55,52};
int y_coords_colon[] = {55,56,53};
int greatest;
int index;
// LENGTH CONSTANT // may require adjustment // length of arms (both must be same)
const float len = 90.0;
float theta1, theta2;

unsigned long start_time; 
unsigned long timed_event = 60000;
unsigned long current_time;
// CURRENT TIME // time is hard-coded // set to time at upload with hrs being hours and mins being minutes (include first 0 for mins if applicable, but not for hrs)
int hrs = 11;
int mins = 45;

#include <Servo.h>

Servo crane; // raises/lowers
Servo arm; // base arm
Servo pointer; // arm connected to base

void plot_point(int x, int y, float l) {
  x = float(x);
  y = float(y);
  theta1 = acos((sqrt(pow(x,2) + pow(y,2))/2)/l) + acos(x/sqrt(pow(x,2) + pow(y,2)));
  theta2 = 2*acos((sqrt(pow(x,2) + pow(y,2))/2)/l);
  write_arm(theta1*180/3.141592653589793238);
  write_pointer(theta2*180/3.141592653589793238);
}

void raise_crane() {
  crane.write(90);
  delay(15);
}

void lower_crane() {
  crane.write(0);
  delay(15);
}

void write_arm(float value) {
  arm.write(value);
  delay(15);
}

void write_pointer(float value) {
  pointer.write(value);
  delay(15);
}

void draw_time(int t) {
  greatest = 0;
  String chars = String(t);
  if (sizeof(t)/sizeof(char) > 3) {
    draw_char(chars.charAt(0));
    draw_char(chars.charAt(1));
    draw_char(':');
    draw_char(chars.charAt(2));
    draw_char(chars.charAt(3));
  }
  else {
    draw_char(chars.charAt(0));
    draw_char(':');
    draw_char(chars.charAt(1));
    draw_char(chars.charAt(2));
  }
}

void draw_char(char value) {
  index = 0;
  switch (value) {
    case '0':
      pl(x_coords_0, y_coords_0);
      break;
    case '1':
      pl(x_coords_1, y_coords_1);
      break;
    case '2':
      pl(x_coords_2, y_coords_2);
      break;
    case '3':
      pl(x_coords_3, y_coords_3);
      break;
    case '4':
      pl(x_coords_4, y_coords_4);
      break;
    case '5':
      pl(x_coords_5, y_coords_5);
      break;
    case '6':
      pl(x_coords_6, y_coords_6);
      break;
    case '7':
      pl(x_coords_7, y_coords_7);
      break;
    case '8':
      pl(x_coords_8, y_coords_8);
      break;
    case '9':
      pl(x_coords_9, y_coords_9);
      break;
    case ':':
      pl(x_coords_colon, y_coords_colon);
      break;
  }
}

void pl(int *x_coords, int *y_coords) {
  raise_crane();
  int x = (x_coords[0] + greatest + 10)/10;
  int y = x_coords[0]/10;
  plot_point(x, y, len);
  lower_crane();
  for (int i = 1; i < sizeof(x_coords)/sizeof(int); i++) {
    int x = (x_coords[i] + greatest + 10)/10;
    int y = x_coords[i]/10;
    plot_point(x, y, len);
  }
  raise_crane();
  for (int i = 0; i < sizeof(x_coords)/sizeof(int); i++)
  {
    if (x_coords[i] > greatest) greatest += x_coords[i];
  }
}

void setup() {
  // attach servos to respective pins
  crane.attach(9);
  arm.attach(10);
  pointer.attach(11);
  raise_crane();
  current_time = millis();
  start_time = current_time; 
}

void loop() {
  current_time = millis();
  if (current_time - start_time >= timed_event) {
    start_time = current_time;
    if (mins == 59) {
      if (hrs != 12) hrs += 1;
      else hrs = 1;
      mins = 0;
    }
    else mins += 1;
    draw_time(hrs*100 + mins);
  }
}
