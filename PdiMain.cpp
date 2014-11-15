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

	procImagem->realcarBordas(2,11);

	procImagem->binarizarImagem();

	imgBinaria = procImagem -> getImagem();

	localizador = new Localizador(imgBinaria);

	localizador->fazerFechamento(1,1,4);

	imagem = procImagem->getImagem();
	imagem = localizador->getImagem();
	imshow("imagem", imagem);

	/* Manter o programa ativo enquanto nenhuma tecla for pressionada */
	int keyCode = cvWaitKey();

	return 0;
}

