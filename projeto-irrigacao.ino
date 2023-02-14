 /*-------------------------INCLUIR BIBLIOTECA-------------------------*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
/*-------------------------INCLUIR BIBLIOTECA-------------------------*/

/*-----------------------MAPEAMENTO DE HARDWARE-----------------------*/
#define bomba 34
#define agua1 35
#define agua2 36
#define pinSensorA1 A0
#define pinSensorA2 A1
LiquidCrystal_I2C lcd(0x3F, 20, 4);
/*-----------------------MAPEAMENTO DE HARDWARE-----------------------*/

/*-----------------------------Variáveis------------------------------*/
int Botao_voltar = 2;
int Botao_retroceder = 3;
int Botao_avancar = 4;
int Botao_confirmar = 5;

int Numero_Menu = 0;
int Numero_titulo = 1;

char* Titulo_Menu[] = {
  "MENU",
  "Sensor de Umidade",
  "Atribuir Planta 1",
  "Atribuir Planta 2",
  "Irrigacao Manual",
  "Orquidia",
  "Rosa",
  "Margarida",
  "Orquidia",
  "Rosa",
  "Margarida",
  "Ligar",
  "Desligar",
};
/*-----------------------------Variáveis------------------------------*/

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.begin(4, 20);

  pinMode(Botao_voltar, INPUT_PULLUP);
  pinMode(Botao_retroceder, INPUT_PULLUP);
  pinMode(Botao_avancar, INPUT_PULLUP);
  pinMode(Botao_confirmar, INPUT_PULLUP);

  pinMode(bomba, OUTPUT);
  pinMode(agua1, OUTPUT);
  pinMode(agua2, OUTPUT);

  digitalWrite(bomba, HIGH);
  digitalWrite(agua1, HIGH);
  digitalWrite(agua2, HIGH);
}

void loop() {

  Pagina_Menu_0();
  Pagina_1();
  Pagina_Menu_2();
  Pagina_2_1();
  Pagina_2_2();
  Pagina_2_3();
  Pagina_Menu_3();
  Pagina_3_1();
  Pagina_3_2();
  Pagina_3_3();
  Pagina_Menu_4();
  Pagina_4_1();
  Pagina_4_2();
  delay(250);
}

void Pagina_Menu_0() {
  if (Numero_Menu == 0) {
    lcd.clear();
  }

  if (digitalRead(Botao_avancar) == LOW) {
    Numero_titulo = Numero_titulo + 1;
    delay(100);
  }

  if (Numero_titulo > 0 & Numero_titulo < 5) {
    lcd.setCursor(1, 0);
    lcd.print(Titulo_Menu[1]);
    lcd.setCursor(1, 1);
    lcd.print(Titulo_Menu[2]);
    lcd.setCursor(1, 2);
    lcd.print(Titulo_Menu[3]);
    lcd.setCursor(1, 3);
    lcd.print(Titulo_Menu[4]);
    delay(100);
  }

  if (Numero_titulo == 1) {
    lcd.setCursor(0, 0);
    lcd.print(">");
  } else if (Numero_titulo == 2) {
    lcd.setCursor(0, 1);
    lcd.print(">");
  } else if (Numero_titulo == 3) {
    lcd.setCursor(0, 2);
    lcd.print(">");
  } else if (Numero_titulo == 4) {
    lcd.setCursor(0, 3);
    lcd.print(">");
  }

  if (digitalRead(Botao_voltar) == LOW) {
  }

  if (digitalRead(Botao_avancar) == LOW) {
    if (Numero_titulo >= 1) {
      Numero_titulo = Numero_titulo + 1;
    }
    if (Numero_titulo > 4) {
      Numero_titulo = 1;
    }
  }

  if (digitalRead(Botao_retroceder) == LOW) {
    if (Numero_titulo <= 4) {
      Numero_titulo = Numero_titulo - 1;
    }
    if (Numero_titulo < 1) {
      Numero_titulo = 4;
    }
  }

  if (digitalRead(Botao_confirmar) == LOW) {
    if (Numero_titulo == 1) {
      Numero_Menu = 1;
    } else if (Numero_titulo == 2) {
      Numero_Menu = 2;
      Numero_titulo = 5;
    } else if (Numero_titulo == 3) {
      Numero_Menu = 3;
      Numero_titulo = 8;
    } else if (Numero_titulo == 4) {
      Numero_Menu = 4;
      Numero_titulo = 11;
    }
  }
}

void Pagina_1() {
  if (Numero_Menu == 1) {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("Sensor 1");
    lcd.setCursor(4, 1);
    lcd.print("Umidade: ");
    lcd.print(analogRead(pinSensorA1));
    lcd.print(" ");
    delay(250);

    lcd.setCursor(6, 2);
    lcd.print("Sensor 2");
    lcd.setCursor(4, 3);
    lcd.print("Umidade: ");
    lcd.print(analogRead(pinSensorA2));
    lcd.print(" ");
    delay(250);

    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 0;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_Menu_2() {
  if (Numero_Menu == 2) {
    lcd.clear();
    if (Numero_titulo > 4 & Numero_titulo < 8) {
      lcd.setCursor(1, 0);
      lcd.print(Titulo_Menu[5]);
      lcd.setCursor(1, 1);
      lcd.print(Titulo_Menu[6]);
      lcd.setCursor(1, 2);
      lcd.print(Titulo_Menu[7]);
      delay(100);
    }
    if (Numero_titulo == 5) {
      lcd.setCursor(0, 0);
      lcd.print(">");
    } else if (Numero_titulo == 6) {
      lcd.setCursor(0, 1);
      lcd.print(">");
    } else if (Numero_titulo == 7) {
      lcd.setCursor(0, 2);
      lcd.print(">");
    }

    if (digitalRead(Botao_avancar) == LOW) {
      if (Numero_titulo >= 5) {
        Numero_titulo = Numero_titulo + 1;
      }
      if (Numero_titulo > 7) {
        Numero_titulo = 5;
      }
    }

    if (digitalRead(Botao_retroceder) == LOW) {
      if (Numero_titulo <= 7) {
        Numero_titulo = Numero_titulo - 1;
      }
      if (Numero_titulo < 5) {
        Numero_titulo = 7;
      }
    }

    if (digitalRead(Botao_voltar) == LOW) {
      Numero_titulo = 2;
      Numero_Menu = 0;
    }

    delay(100);

    if (digitalRead(Botao_confirmar) == LOW) {
      if (Numero_titulo == 5) {
        Numero_Menu = 5;
      } else if (Numero_titulo == 6) {
        Numero_Menu = 6;
      } else if (Numero_titulo == 7) {
        Numero_Menu = 7;
      }
    }
  }
}

void Pagina_2_1() {
  if (Numero_Menu == 5) {
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print(Titulo_Menu[5]);
    lcd.setCursor(5, 2);
    lcd.print("Selecionada");
    if (analogRead(pinSensorA1) < 900) {
      digitalWrite(agua1, HIGH);
      digitalWrite(bomba, HIGH);
    } else {
      digitalWrite(agua1, LOW);
      digitalWrite(bomba, LOW);
    }
    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 2;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_2_2() {
  if (Numero_Menu == 6) {
    lcd.clear();
    lcd.setCursor(8, 1);
    lcd.print(Titulo_Menu[6]);
    lcd.setCursor(5, 2);
    lcd.print("Selecionada");
    if (analogRead(pinSensorA1) < 850) {
      digitalWrite(agua1, HIGH);
      digitalWrite(bomba, HIGH);
    } else {
      digitalWrite(agua1, LOW);
      digitalWrite(bomba, LOW);
    }
    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 2;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_2_3() {
  if (Numero_Menu == 7) {
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print(Titulo_Menu[7]);
    lcd.setCursor(5, 2);
    lcd.print("Selecionada");
    if (analogRead(pinSensorA1) < 800) {
      digitalWrite(agua1, HIGH);
      digitalWrite(bomba, HIGH);
    } else {
      digitalWrite(agua1, LOW);
      digitalWrite(bomba, LOW);
    }
    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 2;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_Menu_3() {
  if (Numero_Menu == 3) {
    lcd.clear();
    if (Numero_titulo > 7 & Numero_titulo < 11) {
      lcd.setCursor(1, 0);
      lcd.print(Titulo_Menu[8]);
      lcd.setCursor(1, 1);
      lcd.print(Titulo_Menu[9]);
      lcd.setCursor(1, 2);
      lcd.print(Titulo_Menu[10]);
      delay(100);
    }
    if (Numero_titulo == 8) {
      lcd.setCursor(0, 0);
      lcd.print(">");
    } else if (Numero_titulo == 9) {
      lcd.setCursor(0, 1);
      lcd.print(">");
    } else if (Numero_titulo == 10) {
      lcd.setCursor(0, 2);
      lcd.print(">");
    }

    if (digitalRead(Botao_avancar) == LOW) {
      if (Numero_titulo >= 8) {
        Numero_titulo = Numero_titulo + 1;
      }
      if (Numero_titulo > 10) {
        Numero_titulo = 8;
      }
    }

    if (digitalRead(Botao_retroceder) == LOW) {
      if (Numero_titulo <= 10) {
        Numero_titulo = Numero_titulo - 1;
      }
      if (Numero_titulo < 8) {
        Numero_titulo = 10;
      }
    }

    if (digitalRead(Botao_voltar) == LOW) {
      Numero_titulo = 3;
      Numero_Menu = 0;
    }

    delay(100);

    if (digitalRead(Botao_confirmar) == LOW) {
      if (Numero_titulo == 8) {
        Numero_Menu = 8;
      } else if (Numero_titulo == 9) {
        Numero_Menu = 9;
      } else if (Numero_titulo == 10) {
        Numero_Menu = 10;
      }
    }
  }
}

void Pagina_3_1() {
  if (Numero_Menu == 8) {
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print(Titulo_Menu[8]);
    lcd.setCursor(5, 2);
    lcd.print("Selecionada");
    if (analogRead(pinSensorA2) < 900) {
      digitalWrite(agua2, HIGH);
      digitalWrite(bomba, HIGH);
    } else {
      digitalWrite(agua2, LOW);
      digitalWrite(bomba, LOW);
    }
    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 3;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_3_2() {
  if (Numero_Menu == 9) {
    lcd.clear();
    lcd.setCursor(8, 1);
    lcd.print(Titulo_Menu[9]);
    lcd.setCursor(5, 2);
    lcd.print("Selecionada");
    if (analogRead(pinSensorA2) < 850) {
      digitalWrite(agua2, HIGH);
      digitalWrite(bomba, HIGH);
    } else {
      digitalWrite(agua2, LOW);
      digitalWrite(bomba, LOW);
    }
    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 3;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_3_3() {
  if (Numero_Menu == 10) {
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print(Titulo_Menu[10]);
    lcd.setCursor(5, 2);
    lcd.print("Selecionada");
    if (analogRead(pinSensorA2) < 800) {
      digitalWrite(agua2, HIGH);
      digitalWrite(bomba, HIGH);
    } else {
      digitalWrite(agua2, LOW);
      digitalWrite(bomba, LOW);
    }
    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 3;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_Menu_4() {
  if (Numero_Menu == 4) {
    lcd.clear();
    if (Numero_titulo > 10 & Numero_titulo < 13) {
      lcd.setCursor(1, 1);
      lcd.print(Titulo_Menu[11]);
      lcd.setCursor(1, 2);
      lcd.print(Titulo_Menu[12]);
      delay(100);
    }
    if (Numero_titulo == 11) {
      lcd.setCursor(0, 1);
      lcd.print(">");
    } else if (Numero_titulo == 12) {
      lcd.setCursor(0, 2);
      lcd.print(">");
    }

    if (digitalRead(Botao_avancar) == LOW) {
      if (Numero_titulo >= 11) {
        Numero_titulo = Numero_titulo + 1;
      }
      if (Numero_titulo > 12) {
        Numero_titulo = 11;
      }
    }

    if (digitalRead(Botao_retroceder) == LOW) {
      if (Numero_titulo <= 12) {
        Numero_titulo = Numero_titulo - 1;
      }
      if (Numero_titulo < 11) {
        Numero_titulo = 12;
      }
    }

    if (digitalRead(Botao_voltar) == LOW) {
      Numero_titulo = 4;
      Numero_Menu = 0;
    }

    delay(100);

    if (digitalRead(Botao_confirmar) == LOW) {
      if (Numero_titulo == 11) {
        Numero_Menu = 11;
      } else if (Numero_titulo == 12) {
        Numero_Menu = 12;
      }
    }
  }
}

void Pagina_4_1() {
  if (Numero_Menu == 11) {
    lcd.clear();
    lcd.setCursor(6, 1);
    lcd.print("Irrigacao");
    lcd.setCursor(7, 2);
    lcd.print("Ligada");
    digitalWrite(agua1, LOW);
    digitalWrite(agua2, LOW);
    digitalWrite(bomba, LOW);

    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 4;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}

void Pagina_4_2() {
  if (Numero_Menu == 12) {
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("Irrigacao");
    lcd.setCursor(5, 2);
    lcd.print("Desligada");
    digitalWrite(agua1, HIGH);
    digitalWrite(agua2, HIGH);
    digitalWrite(bomba, HIGH);
    
    if (digitalRead(Botao_voltar) == LOW) {
      Numero_Menu = 4;
    }
    if (digitalRead(Botao_confirmar) == LOW) {
    }
    if (digitalRead(Botao_avancar) == LOW) {
    }
    if (digitalRead(Botao_retroceder) == LOW) {
    }
  }
}