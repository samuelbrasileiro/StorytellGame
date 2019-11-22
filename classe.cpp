#include "classe.h"

linhas::linhas(int id, int *escolhas, std::string texto){
	this->id = id;
	for(int i=0;i<4;i++){
		this->escolhas[i]= escolhas[i];
	}
	this->texto = texto;
}
void linhas::error_msg(char *text){
        al_show_native_message_box(NULL,"ERRO",
            "Ocorreu o seguinte erro e o programa sera finalizado:",
            text,NULL,ALLEGRO_MESSAGEBOX_ERROR);
    }

int linhas::inicializar(char *my_audio){
		std::cout << my_audio << std::endl;
        if(!al_init()){
            error_msg("Falha ao inicializar a Allegro");
            return 0;
        }
     
        //addon de audio
        if(!al_install_audio()){
            error_msg("Falha ao inicializar o audio");
            return 0;
        }
     
        //addon que da suporte as extensoes de audio
        if(!al_init_acodec_addon()){
            error_msg("Falha ao inicializar o codec de audio");
            return 0;
        }
     
        //cria o mixer (e torna ele o mixer padrao), e adciona 5 samples de audio nele
        if (!al_reserve_samples(5)){
            error_msg("Falha ao reservar amostrar de audio");
            return 0;
        }
     
        this->som = al_load_audio_stream(my_audio, 4, 1024);

        return 1;
    }
 /*void linhas::play_audio(){
 	std::cout << "cheguei\n";
 	al_play_sample(som, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
 	//al_destroy_sample(som);
 }*/