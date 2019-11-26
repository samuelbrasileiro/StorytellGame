#ifndef CLASSE_H
#define CLASSE_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>	
#include <iostream>

class linhas{
	public:
		linhas(int id, int *escolhas, std::string texto);
		void error_msg(char *text);
		void inicializar(char *my_audio);
		void play_audio();
		ALLEGRO_AUDIO_STREAM *som = NULL;
		int escolhas[3];
		std::string texto;
		int id;
		
};
#endif