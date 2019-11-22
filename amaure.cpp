#define ALLEGRO_NO_MAGIC_MAIN
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "classe.h"
#include <string.h>
#include <iostream>
#include <vector>

#define N_AUDIOS 2
#define wave ".wav"

using namespace std;

ALLEGRO_AUDIO_STREAM *musica = NULL; 
 
int main(){
   char a[] = "a.wav", b[] = "b.wav";
   int meuvetor[] = {0,1,1,0}; //na verdade seria uma matriz
   int id = 0;
   int minhaEscolha = -1;
   vector<linhas> mylines;
   for(int i = 0; i < N_AUDIOS; i++){
      mylines.push_back(linhas(i, meuvetor, ""));
   }
   cout << "Inicializei o vector de linhas" << endl;
   for(int i=0; i<N_AUDIOS; i++){
      char aux[10] = " ";
      aux[0] = i + '0';
      strcat(aux, wave);
      cout << aux << endl;
      mylines[i].inicializar(aux);
   }
   while(id != -1){
      cout << "ID igual a " << id << endl;
      //poe audio no buffer lido pelo drive de som
      al_attach_audio_stream_to_mixer(mylines[id].som, al_get_default_mixer());
      //seta playmode (uma vez)
      al_set_audio_stream_playmode(mylines[id].som, ALLEGRO_PLAYMODE_ONCE);
      //toca audio
      al_set_audio_stream_playing(mylines[id].som, true);
      //espera audio acabar
      while(al_get_audio_stream_playing(mylines[id].som)){}
      cout << "Sai do loop com sucesso" << endl;
      al_detach_audio_stream(mylines[id].som);
      //esperar leitura do driver de botao aqui
      cin >> minhaEscolha;
      switch(minhaEscolha){
         case 0: 
            id = mylines[id].escolhas[0];
            break;
         case 1:
            id = mylines[id].escolhas[1];
            break;
         case 2:
            id = mylines[id].escolhas[2];
            break;
         case 3:
            id = id;
            al_rewind_audio_stream(mylines[id].som);
            break;
         default:
            id = -1;
      }
   }
    //al_destroy_sample(som_azul);
    //al_destroy_sample(som_verm);
   for(int i=0; i<N_AUDIOS; i++){
      al_destroy_audio_stream(mylines[i].som);
   }

    return 0;
}