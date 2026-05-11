#define botao 0
#define tempo 1000
#define som 8
#define frequencia 100
#define c 264 //Dó 528
#define d 296 //Ré 592
#define e 332 //Mi 665
#define f 352 //Fá 704
#define g 395 //Sol 790
#define a 444 //Lá 888
#define b 498 //Si 996

int notas[] = {c, d, e, g, g, e, f, f,0, c, d, e, g, g, f, e, 0, c, c, d, e, g, 0, g, f, e, c, f, 0, f, e, d, d, e, 0, d, d, c, c, 0};   
int tempos[] = {4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 1, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 1, 6}; 
int tamanho = 0, i;   


void setup()
{
  pinMode(som, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  tamanho = sizeof(notas) / 2;
  for (i = 0; i < tamanho; i++){
    tempos[i] = tempo / tempos[i];
  }
}

void loop(){
  bool estado_botao = digitalRead(botao);
  if (estado_botao == LOW) {
    for (i = 0; i < tamanho; i++){
      if (notas[i] == 0) {
        noTone(som);
        delay(tempos[i]);
        }
          else {
            tone(som, notas[i]);
            delay(tempos[i]);
          }
      }
  }
}