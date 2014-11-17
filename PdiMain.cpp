#include "ProcImagem.hpp"
#include"Localizador.hpp"
using namespace std;

int main(int argc, char **argv) {

	ProcImagem* procImagem;
	Localizador* localizador;

	cv::Mat imgBinaria;
	cv::Mat imagem;

	procImagem = new ProcImagem(argv[1]);

	procImagem->transformarCinza();

	procImagem->realcarBordas(2,13);

	procImagem->binarizarImagem();

	imgBinaria = procImagem -> getImagem();


	localizador = new Localizador(imgBinaria);

	localizador->fazerFechamento(1,1,14);

	localizador -> fazerAbertura(1,35,2);
	localizador -> fazerAbertura(1,25,2);



	//localizador->fazerFechamento(1,6,5);
	//localizador->fazerFechamento(1,1,6);

	//localizador ->fazerAbertura(1,1,30);
	//localizador->fazerFechamento(1,1,20);


	//imagem = procImagem->getImagem();
	imagem = localizador->getImagem();
	imshow("imagem", imagem);

	/* Manter o programa ativo enquanto nenhuma tecla for pressionada */
	int keyCode = cvWaitKey();

	return 0;
}

