programa
{
	
	funcao inicio()
	{
		
		real reserva = 0.3
		real media = 0.0
		real capMax = 0.0
		real kmPlanejado = 0.0
		real kmAlternativo = 0.0
		real combNaAeronave = 0.0
		real x

		
		//Leitura dos Dados
		escreva("\t////CONTROLE DE ABASTECIMENTO////\n")

		escreva("Digite a média da aeronave em litros por quilômetros (3.6): ")
		leia(media)
		
		escreva("Digite a capacidade máxima de combústivel suportado pela aeronave (26020): ")
		leia(capMax)
		
		escreva("Qual a quilometragem do trecho planejado (1100) ? ")
		leia(kmPlanejado)
		
		escreva("Qual a quilometragem do trecho alternativo? ")
		leia(kmAlternativo)

		escreva("Qual a quantidade de combustível já na aeronave (1500): ")
		leia(combNaAeronave)

		escreva("A soma dos trechos é de: "+kmTotal(kmPlanejado, kmAlternativo))
		escreva("O combustível necessário é: "+combustivelNecessario(kmPlanejado, kmAlternativo, media))
		
	}

	funcao real kmTotal(real x, real y){
		retorne  x + y
	}

	funcao real addMargemSeguranca(){
		
	}
	

	//Somar trechos planejado + trecho alternativo e adicionar margem de segurança 
	funcao real combustivelNecessario (real x, real y, real z){
		real gazoza

		/* Simplificando o cálculo:
		x = 1100
		y = 400
		z = 3.6

		1 - 1100 + 400 = 1500 (Soma total dos trechos)
		2 -  3.6 * 1500 = 5400 (Total de combustível necessário)
		3 - 5400 * 0.3 = 1620 (Valor dos 30% de combustíve)
		4 - 1620 + 5400 = 7020 (Soma dos 30% mais o combustível necessário)
		*/
		gazoza = ((z * (x + y)) * 0.3) + (z * (x + y))
		
		retorne gazoza
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 995; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */