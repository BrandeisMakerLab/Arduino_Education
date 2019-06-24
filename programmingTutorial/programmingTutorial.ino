/*Jacob Smith Brandeis Makerlab 6.8.2019
Tutorial to help high school studnets learn programming concepts*/

void setup() {
  // put your setup code here, to run once:
  //establish serial connection
  Serial.begin(9600);
  while(!Serial){}
  
  Serial.println("Arrays Practice");
  Serial.println("\tCreating Array of 5 0s");
  int apple[5];
  for(int i=0;i<5;i++){
    apple[i]=0;
  }
  printArr(apple,5);
  Serial.println("\tSetting 3rd element to 1");
  apple[2]=1;
  printArr(apple,5);

  Serial.println("Parameters vs Arguments Practice");
  int myNumber=2;
  //printing initial number
  Serial.print("\t myNumber=");
  Serial.println(myNumber);

  //printing reult of add
  Serial.print("\t myNumber=");
  Serial.println(add(myNumber));

  //printing number variable again
  Serial.print("\t myNumber=");
  Serial.println(myNumber);

  //printing assigned number variable
  myNumber=add(myNumber);
  Serial.print("\t myNumber=");
  Serial.println(myNumber);
}

void loop() {}

int add(int num){
  num+=5;
  return num;
}

void printArr(int apple[],int arrSize){
  for(int i=0;i<arrSize;i++){
    Serial.print("\t");
    Serial.println(apple[i]);
  }
}
