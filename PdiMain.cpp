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

	imshow("bin", imgBinaria);

	localizador = new Localizador(imgBinaria);

	localizador->fazerFechamento(1,2,3);
	localizador -> fazerAbertura(1,51,2);
	localizador -> fazerAbertura(1,49,2);
	//localizador -> fazerAbertura(1,1,2);

	int x;
	int y;
	localizador -> LocalizarPosicao(x,y);

	cv::Mat img = cv::imread(argv[1]);

	cv::Mat resul = localizador->marcarPlaca(img,cv::Point(x,y), cv::Point(x+257,y+50),cv::Scalar(267,21,45));
	//localizador->fazerFechamento(1,6,5);
	//localizador->fazerFechamento(1,1,6);

	//localizador ->fazerAbertura(1,1,30);
	//localizador->fazerFechamento(1,1,20);


	//imagem = procImagem->getImagem();
	imagem = localizador->getImagem();
	imshow("imagem", imagem);
	imshow("Result", resul);
	/* Manter o programa ativo enquanto nenhuma tecla for pressionada */
	int keyCode = cvWaitKey();

	return 0;
}

