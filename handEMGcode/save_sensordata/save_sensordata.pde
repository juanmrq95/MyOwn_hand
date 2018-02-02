import processing.serial.*;

Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial po
PrintWriter output;

void setup()
{
  String portName = Serial.list()[4]; 
  //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600); 
  output = createWriter("baseline_biceps_r2.txt");
}
   
void draw()
{
  if ( myPort.available() > 0) 
  {  // If data is available,  
  String val = myPort.readStringUntil('\n'); 
  if (val != null)
  {
    output.print(val);
    println(val);
  // read it and store it in val
  }  
  }
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}