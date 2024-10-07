 #define ledPin 8 
const int redPin = 13; 
const int yellowPin = 12; 
const int greenPin = 11; 
char receivedChar; 
// Define the durations for each state of the traffic light 
const int redDuration = 500;   // 5 seconds 
const int yellowDuration =200; // 2 seconds 
const int greenDuration = 500;  // 5 seconds 
void setup() { 
  pinMode(ledPin, OUTPUT); 
  pinMode(redPin, OUTPUT); 
  pinMode(yellowPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  digitalWrite(ledPin, LOW); 
  digitalWrite(redPin, LOW); 
  digitalWrite(yellowPin, LOW); 
  digitalWrite(greenPin, LOW); 
  Serial.begin(9600); 
} 
void loop() { 
  if (Serial.available() > 0) { 
    receivedChar = Serial.read(); 
    Serial.print("Received: "); 
    Serial.println(receivedChar); // Print received character     
    if (receivedChar == '1') { 
      // Turn on green light immediately 
      digitalWrite(redPin, LOW); 
      digitalWrite(yellowPin, LOW); 
      digitalWrite(greenPin, HIGH); 
      delay(greenDuration); // Keep green light on for its duration 
      Serial.println("Green Light On"); // Debugging output 
    } else if (receivedChar == '0') { 
      runNormalTrafficLight(); 
      Serial.println("Normal Traffic Light"); // Debugging output 
    } 
    } else if (receivedChar == '5') { 
      digitalWrite(ledPin, LOW); 
      Serial.println("LED Off"); // Debugging output 
    } else if (receivedChar == '6') { 
    digitalWrite(ledPin, HIGH); 
      Serial.println("LED On"); // Debugging output 
  } else { 
    runNormalTrafficLight(); // If no new serial input, run normal traffic light sequence 
  } 
} 
void runNormalTrafficLight() { 
  // Red light 
  digitalWrite(redPin, HIGH); 
  digitalWrite(yellowPin, LOW); 
  digitalWrite(greenPin, LOW); 
  delay(redDuration); 
  // Yellow light 
  digitalWrite(redPin, LOW); 
  digitalWrite(yellowPin, HIGH); 
  digitalWrite(greenPin, LOW); 
  delay(yellowDuration); 
  // Green light 
  digitalWrite(redPin, LOW); 
  digitalWrite(yellowPin, LOW); 
  digitalWrite(greenPin, HIGH); 
  delay(greenDuration); 
} 