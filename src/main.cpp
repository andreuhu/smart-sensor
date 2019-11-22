#include <avr/io.h>
#include "adc.h"

//array untuk 3 data sensor
uint16_t sensor[3];
uint16_t smin[3] = {1024, 1024, 1024};
uint16_t smax[3] = {0, 0, 0};
uint16_t sthreshold[3];
uint16_t Dnilai[3];

void read_sensor();
void kalibrasi();
void digital_RAW();

int main(){
    ADC_Init();

    while(1){

    }

}

//deklar fungsi pembacaan sensor
void read_sensor(){
  for(int i=0; i<3; i++){
    sensor[i]=ADC_Read(i);
  }

}

void kalibrasi(){
  read_sensor();

  for (int i = 0; i < 3; i++)
  {
    if (sensor[i] < smin[i])
    {
      smin[i]= sensor[i];
    }
    if (sensor[i] > smax[i])
    {
      smax[i] = sensor[i];
    }
    
    sthreshold[i] = (smin[i]+smax[i]) / 2; 
  }
}

void digital_RAW(){
  read_sensor();
  for (int i = 0; i < 3; i++)
{
  if(sensor[i] > sthreshold[i])
  Dnilai[i]= 1;
  
  else 
  Dnilai[i] = 0;
}
}