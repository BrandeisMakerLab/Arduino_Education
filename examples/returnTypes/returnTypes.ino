/*
  Shows data types and returning
  Jacob Smith for Brtandeis Automation Lab 10/16/2020
*/

void setup()
{
  //start coonnection to computer
  Serial.begin(9600);
  //and wait a bit for the connection to start
  delay(1000);
  //print welcome message
  Serial.println("Demonstrates different return types");
  
  //show how different return types impact what is outputted
  //for different examples
  returnsNothing(1,2);
  
  int b=returnsInt(1,2);
  Serial.print("b is\t");
  Serial.println(b);
  
  double c=returnsDouble(1.0,2.5);
   Serial.print("c is\t");
  Serial.println(c);
  
  String d=returnsString("1.0","2.5");
  Serial.print("d is\t");
  Serial.println(d);
  boolean e=returnsBoolean(true,false);
  Serial.print("e is\t");
  Serial.println(e);
}

//not used here
void loop(){}

//showes void return type, which returns nothing
void returnsNothing(int a, int b){
	Serial.pint("a is\t");
	//note how the answer is printed here since the method does not return
	Serial.println(a+b);
}

//shows in return type, which returns integer
int returnsInt(int a, int b){
	return a+b;
}

//shows double return type, whic returns decimal number
double returnsDouble(double a, double b){
	return a+b;
}


//shows string return type which returns words
String returnsString(String a, String b){
	return a+b;
}

//shows boolean return type which returns true false (here that's 1 0)
bool returnsBoolean(bool a, bool b){
	return a|b;
}
