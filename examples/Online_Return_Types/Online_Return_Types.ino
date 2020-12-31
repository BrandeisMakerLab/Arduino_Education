/*Jacob Smith for Brandeis Automation Lab 10/16/2020
  Shows data types and returning
  Use with any example in online simulator
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
  //this method doesn't return an answer, no =
  returnsNothing(1,2);
   
  //this method returns a whole number
  int b=returnsInt(1,2);
  Serial.print("b is\t");
  Serial.println(b);
  
  //this method returns a decimal number
  double c=returnsDouble(1.0,2.5);
   Serial.print("c is\t");
  Serial.println(c);
  
  //this method returns a word
  String d=returnsString("1.0","2.5");
  Serial.print("d is\t");
  Serial.println(d);
  
  //this method returns 1 or 0 (tru or false)
  boolean e=returnsBoolean(true,false);
  Serial.print("e is\t");
  Serial.println(e);
}

//not used here
void loop(){}

//showes void return type, which returns nothing
void returnsNothing(int a, int b){
	Serial.print("a is\t");
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
