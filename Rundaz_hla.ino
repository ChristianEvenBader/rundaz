/*
to do:
- Taster debouncen; Frage: Durch Abfrage LED gelöst?
*/


//Anschluesse
int t1 = 10;
int t2 = 11;
int l1 = 12;
int l2 = 13;
//Anschluesse 7-Seg
int seg7[] = {2, 3, 4, 5, 6, 7, 8, 9};
//Zaehlervariablen
int runde = 0;
int zug = 1;

void setup() {
  pinMode(t1, INPUT);	//Taster Zug Spieler 1
  pinMode(t2, INPUT);	//Taster Zug Spieler 2
  for (int i=0; i<8; i++){		// Output: 7-Segment-Anzeige für Runde
  	pinMode(seg7[i], OUTPUT);}
  pinMode(l1, OUTPUT);	//LED1 Spieler 1
  pinMode(l2, OUTPUT);	//LED2 Spieler 2
  Serial.begin(9600);
  digitalWrite(l1, LOW);	//beides als default in anzeige() setzen und aufrufen?
  digitalWrite(l2, LOW);
}

void taster(){
  //Serial.println("Ok"); funzt
  if (digitalRead(t1) == 1 && digitalRead(l1) == LOW){
  	rundenzaehler(1);			//von Spieler 1
    Serial.println("Spieler 1");
  	} else if (digitalRead(t2) == 1 && digitalRead(l2) == LOW){
  		rundenzaehler(2);		//von Spieler 2
		Serial.println("Spieler 2");
  		}
}

//Aufruf, wenn Taster gedrückt
int rundenzaehler(int spieler){
  if (zug % 2 == 0){
    runde++;
    }
  zug++;
  Serial.println("Funktion Rundenzähler:");
  Serial.println(runde, spieler);     //Kontrolle
  anzeige(runde, spieler);
}

//Anzeige Runde, Spieler
int anzeige(int r, int spieler){
  int seg_7[9][8] = {{0, 1, 1, 0, 0, 0, 0, 1}, //1  
  				 {1, 1, 0, 1, 1, 0, 1, 1}, //2
  				 {1, 1, 1, 1, 0, 0, 1, 1}, //3
  				 {0, 1, 1, 0, 0, 1, 1, 1}, //4
  				 {1, 0, 1, 1, 1, 0, 1, 1}, //5
  				 {1, 0, 1, 1, 1, 1, 1, 1}, //6
  				 {1, 1, 1, 0, 0, 0, 0, 1}, //7
  				 {1, 1, 1, 1, 1, 1, 1, 1}, //8
  				 {1, 1, 1, 1, 0, 1, 1, 1}, //9
  				 };
  switch (spieler) {		//LED1 oder LED2
  	case 1:
  		digitalWrite(l1, HIGH);
  		digitalWrite(l2, LOW);
  		break;
  	case 2:
  		digitalWrite(l1, LOW);
  		digitalWrite(l2, HIGH);
  		break;
  }
  //Anzeige der Runden durch 7-Seg-Anzeige
  Serial.println("Funktion Ausgabe:");
  Serial.println(r, spieler);
}

void loop() {
  taster();			//taster() -> rundenzaehler() -> anzeige()
}
