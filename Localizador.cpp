/*
 * Localizador.cpp
 *
 *  Created on: Nov 6, 2014
 *      Author: guilherme
 */

#include "Localizador.hpp"

Localizador::Localizador() {
	// TODO Auto-generated constructor stub

}

Localizador::Localizador(cv::Mat imagem){
	this->imagem = imagem;
}

cv::Mat Localizador::fazerFechamento(cv::Mat imagem, int nucleo,int tamanho){
	cv::Mat img_fechada;
	cv::Mat elemento = cv::getStructuringElement(nucleo,cv::Size (2 * tamanho,2 * tamanho), cv::Point(tamanho, tamanho));

	cv::morphologyEx(imagem,img_fechada,3, elemento);
	return img_fechada;
}

cv::Mat Localizador::fazerAbertura(cv::Mat imagem, int nucleo,int tamanho){

	cv::Mat img_aberta;
		cv::Mat elemento = cv::getStructuringElement(nucleo,cv::Size (2 * tamanho,2 * tamanho), cv::Point(tamanho, tamanho));

		cv::morphologyEx(imagem,img_aberta,2, elemento);
		return img_aberta;
}


Localizador::~Localizador() {
	// TODO Auto-generated destructor stub
}

