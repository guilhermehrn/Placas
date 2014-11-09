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
	cv::Mat mar;
	Localizador *placa;

	imagem = new ProcImagem(argv[1]);

	col = imagem->getImgColor();
	cin = imagem->getImgCinza();
	bon = imagem->realcarBordas(0,5);
	bin = imagem->binarizarImagem(bon);

	placa = new Localizador(bin);
	fec = placa->fazerFechamento(bin,0,9);
	abe = placa->fazerAbertura(fec,0,3);
	mar = placa->marcarPlaca(col,cv::Point(100,100),cv::Point(130,130),cv::Scalar(200,150,90));



	imshow("Colorida", col);
	imshow("Cinza", cin);
	imshow("Bon", bon);
	imshow("Bim", bin);
	imshow("Fec", fec);
	imshow("abe", abe);
	imshow("Mar", mar);


	/* Manter o programa ativo enquanto nenhuma tecla for pressionada */
	int keyCode = cvWaitKey();

	return 0;

}

