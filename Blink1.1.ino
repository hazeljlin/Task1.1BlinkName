#define LED_PIN LED_BUILTIN  // LED pin definition

// Morse Code Timing
#define DOT_DURATION 500      // Dot duration (milliseconds)
#define DASH_DURATION 1500    // Dash duration (milliseconds)
#define SYMBOL_GAP 500        // Gap between dot/dash within a letter
#define LETTER_GAP 1500       // Gap between letters

// Function to blink a dot
void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(DOT_DURATION);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP);
}

// Function to blink a dash
void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(DASH_DURATION);
  digitalWrite(LED_PIN, LOW);
  delay(SYMBOL_GAP);
}

// Function to add spacing between letters
void letterSpacing() {
  delay(LETTER_GAP);
}

// Morse Code Dictionary (A-Z)
const char* morseCode[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Function to blink Morse code for a given character
void blinkMorse(char c) {
  if (c >= 'A' && c <= 'Z') {       
    c = c - 'A';  // Convert 'A' to 0, 'B' to 1, ..., 'Z' to 25
  } else if (c >= 'a' && c <= 'z') { 
    c = c - 'a';  // Convert 'a' to 0, ..., 'z' to 25
  } else {
    return; // Ignore unsupported characters
  }

  // Retrieve the Morse code string from the lookup table
  const char* morse = morseCode[c]; 

  // Loop through each character in the Morse code string
  while (*morse) {  
    if (*morse == '.') {   
      dot();  
    } else if (*morse == '-') { 
      dash(); 
    }
    morse++;  // Move to the next Morse code symbol in the string
  }

  // Add a spacing delay between letters
  letterSpacing();
}

// Function to blink Morse code for a given message
void blinkMessage(const char* message) {
  while (*message) {   
    blinkMorse(*message);  
    message++;  
  }
}

// Setup function
void setup() {
  pinMode(LED_PIN, OUTPUT); 
  Serial.begin(9600); 
  Serial.println("Enter a name to blink in Morse code:");
}

// Loop function
void loop() {
    String input = Serial.readStringUntil('\n'); //read user input
    Serial.print("Blinking Morse Code for: ");
    Serial.println(input);
    blinkMessage(input.c_str()); //convert string to c style string for processing
    }







