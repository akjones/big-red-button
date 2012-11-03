const int buttonPin = 3;
const int ledPin = 5;
const char* launchCode = "8iAWv1dVOywXNobylMid\n";

int buttonState = 0; int ledState = HIGH;
int lastButtonState = HIGH;

long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
    if (buttonState == HIGH) {
      Serial.println(launchCode);
    }
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    buttonState = reading;
  }

  digitalWrite(ledPin, buttonState);

  lastButtonState = reading;
}
