/* Este programa tem como função calcular aproximadamente o percentual de gordura corporal
* de um ser humano. O valor aqui exibido não é substituido pela avaliação de um profissional da saúde.
* referência: https://www.simetriamuscular.com.br/calculadora-gordura-corporal
*/

#include <iostream>
#include <math.h>

void ImprimeMenu(){
    std::cout << "==============================\n";
    std::cout << "Calculadora de BF - versão 1.0\n";
    std::cout << "==============================\n";
    }

double CalculaIMC(double peso, double altura){
    return peso / ((altura/100) * (altura/100));
}

double CalculaBF(double a,double i,char s, double p, double c, double q){
    if(s=='m' || s=='M'){
        return 495/(1.0324 - 0.19077*log10(c-p) + 0.154456*log10(a)) - 450;
    }else{
         return 495/(1.29579 - 0.35004*log10(c+q-p) + 0.22100*log10(a)) - 450;
    }

}

void CalculadoraBF(){
    ImprimeMenu();
    double peso,altura,idade,pescoco,cintura,quadril;
    char sexo;
    std::cout << "Insira o seu sexo(M(masculino)/F(feminino)): ";
    std::cin >> sexo;
    std::cout << "Insira o seu peso em quilogramas: ";
    std::cin >> peso;
    std::cout << "Insira a sua altura em centímetros: ";
    std::cin >> altura;
    std::cout << "Insira a sua idade em anos: ";
    std::cin >> idade;
    std::cout << "Insira o tamanho do seu pescoço em centímetros ";
    std::cin >> pescoco;
    std::cout << "Insira o tamanho da sua cintura em centímetros ";
    std::cin >> cintura;
    if(sexo=='F' || sexo=='f'){
    std::cout << "Insira o tamanho do seu quadril em centímetros ";
    std::cin >> quadril;}
    printf("O seu percentual de gordura é: %.2lf S%% \n", CalculaBF(altura, idade, sexo, pescoco, cintura, quadril));
    std::cout <<  "o seu IMC é: "<< CalculaIMC(peso, altura) << "\n"; }    



int main(){

    char c;
    while(true){
    CalculadoraBF();
    std::cout << "Deseja realizar o calculo novamente?[S/N]\n";
    std::cin >> c;
        if(c!='S'){
            break;
            CalculadoraBF();
}
    std::cout << "\n";

}
    return 0;
}
 