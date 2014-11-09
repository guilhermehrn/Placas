
#include "ProcImagem.hpp"
#include"Localizador.hpp"
using namespace std;

int main(int argc, char **argv) {

	ProcImagem* imagem;
	cv::Mat col;
	cv::Mat cin;
	cv::Mat bon;
	cv::Mat bin;
	cv::Mat fec;
	cv::Mat abe;
	Localizador *placa;

	imagem = new ProcImagem(argv[1]);

	col = imagem->getImgColor();
	cin = imagem->getImgCinza();
	bon = imagem->realcarBordas(0,5);
	bin = imagem->binarizarImagem(bon);

	placa = new Localizador(bin);
	fec = placa->fazerFechamento(bin,0,9);
	abe = placa->fazerAbertura(fec,0,3);


	imshow("Colorida", col);
	imshow("Cinza", cin);
	imshow("Bon", bon);
	imshow("Bim", bin);
	imshow("Fec", fec);
	imshow("abe", abe);


	/* Manter o programa ativo enquanto nenhuma tecla for pressionada */
	int keyCode = cvWaitKey();

	return 0;

}

