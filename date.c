#include <stdio.h>

int main ()
{
    int cont = 0;
    int repetir = 1;
    signed long dia_inicial = 0, mes_inicial = 0, ano_inicial = 0, dia_final = 0, mes_final = 0, ano_final = 0, dias_a_calcular = 0, opcao = -1;


        /*declarando funcoes*/
        int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);
        void captura_e_valida_dados_do_teclado(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);
        void validar_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);
        void ler_arquivo_gas_txt();

     while(repetir == 1)
     {
        //chamando funcoes
        //printf("\nvalores da funcao %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, \n", dia_inicial, mes_inicial, ano_inicial, dia_final, mes_final, ano_final, dias_a_calcular, opcao);
        captura_e_valida_dados_do_teclado(&dia_inicial, &mes_inicial, &ano_inicial, &dia_final, &mes_final, &ano_final, &dias_a_calcular, &opcao);

        printf("\nDeseja realizar outro calculo? ""1""(sim) ou ""0""(nao).\n");
        scanf("%d", &repetir);
        opcao = -1;
     }

    return 0;
}

void captura_e_valida_dados_do_teclado(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao)
{
    //signed long cont_anos, cont_meses, opcao_resto, dias_remanescentes, cont_semanas, cont_dias;
    //signed long dia_inicial_r, dia_final_r, mes_inicial_r, mes_final_r, ano_inicial_r, ano_final_r, dias_a_calcular_r, opcao_r;
    //signed long opcao_bissexta, quant_anos_bissextos;


    /*Declarando funcao validar_datas*/
    void validar_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);

    /*Declarando variaveis temporarias para a troca de datas*/
    signed long temp_dia_inicial, temp_mes_inicial, temp_ano_inicial;

    /*declarando a funcao calculadora de datas*/
    int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);



    /*if para pedir a opcao so 1 vez*/
    if(*popcao == -1)
    {
        printf("\nCalculadora de datas.\n");
        printf("Escolha a operacao que deseja realizar.\n");
        printf("Digite 1 para calcular a diferenca em dias entre duas datas.\n");
        printf("Digite 2 para adcionar dias apartir de uma data.\n");
        printf("Digite 3 para subtrair dias apartir de uma data.\n");
        printf("Digite 4 para calcular o dia da semana de uma data.\n");
        printf("Digite 5 para saber se um ano eh bissexto.\n");
        printf("Digite 6 para saber anos bissextos dentro de um intervalo.\n");
        scanf("%lu", &*popcao);

        //Validando opcao.
        while((*popcao < 1) || (*popcao > 6))
        {
            printf("\n\nOpcao invalida.\n\n");
            printf("\nCalculadora de datas.\n");
            printf("Escolha a operacao que deseja realizar.\n");
            printf("Digite 1 para calcular a diferenca em dias entre duas datas.\n");
            printf("Digite 2 para adcionar dias apartir de uma data.\n");
            printf("Digite 3 para subtrair dias apartir de uma data.\n");
            printf("Digite 4 para calcular o dia da semana de uma data.\n");
            printf("Digite 5 para saber se um ano eh bissexto.\n");
            printf("Digite 6 para saber anos bissextos dentro de um intervalo.\n");
            scanf("%lu", &*popcao);
        }
    }


    if(*popcao == 1)
    {
         printf("\nCalcular diferencas entre duas datas em dias.\n");
         printf("Digite as datas no formato dd/mm/aaaa exemplo 21/05/1989.\n\n");
         printf("Digite a data inicial.\n");
         scanf("%lu/%lu/%lu", &*pdia_inicial, &*pmes_inicial, &*pano_inicial);
         printf("Digite a data final.\n");
         scanf("%lu/%lu/%lu", &*pdia_final, &*pmes_final, &*pano_final);

         /*troca de posicao caso a primeira data seja maior que a segunda data*/
         if((*pano_inicial > *pano_final) || ((*pano_inicial == *pano_final) && (*pmes_inicial > *pmes_final)) || ((*pano_inicial == *pano_final) && (*pmes_inicial == *pmes_final) && (*pdia_inicial > *pdia_final)))
         {
             temp_dia_inicial = *pdia_inicial;
             temp_mes_inicial = *pmes_inicial;
             temp_ano_inicial = *pano_inicial;

             *pdia_inicial = *pdia_final;
             *pmes_inicial = *pmes_final;
             *pano_inicial = *pano_final;

             *pdia_final = temp_dia_inicial;
             *pmes_final = temp_mes_inicial;
             *pano_final = temp_ano_inicial;
         }

         validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

    }
    else if(*popcao == 2)
    {
        printf("\nAdicionar dias a uma data especifica.\n");
        printf("Digite a data no formato dd/mm/aaaa exemplo 21/05/1989.\n\n");
        printf("Digite a data inicial.\n");
        scanf("%lu/%lu/%lu", &*pdia_inicial, &*pmes_inicial, &*pano_inicial);
        printf("Digite os dias que serao acrescentados.\n");
        scanf("%lu", &*pdias_a_calcular);

        *pdia_final = 31;
        *pmes_final = 12;
        *pano_final = 9999999;

        validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

        //chamando a funcao que calcula datas
        //calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
    }
    else if(*popcao == 3)
    {
        printf("\nsubtrair dias de uma data.\n");
        printf("Digite a data no formato dd/mm/aaaa exemplo 21/05/1989.\n\n");
        printf("Digite a data.\n");
        scanf("%lu/%lu/%lu", &*pdia_final, &*pmes_final, &*pano_final);
        printf("Digite os dias que serao subtraidos.\n");
        scanf("%lu", &*pdias_a_calcular);
        *pdia_inicial = 1;
        *pmes_inicial = 1;
        *pano_inicial = 1;

        validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

        //chamando a funcao que calcula datas
        //calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
    }
    else if(*popcao == 4)
    {
        printf("\nCalcular o dia da semana de uma data.\n");
        printf("Digite a data no formato dd/mm/aaaa exemplo 21/05/1989.\n\n");
        printf("Digite a data.\n");
        scanf("%lu/%lu/%lu", &*pdia_final, &*pmes_final, &*pano_final);

        *pdia_inicial = 1;
        *pmes_inicial = 1;
        *pano_inicial = 1;
        *pdias_a_calcular = 0;
        //printf("\nvalores da funcao capturar_dados_do_teclado, else if(*popcao == 4) = %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, \n", *pdia_inicial, *pmes_inicial, *pano_inicial, *pdia_final, *pmes_final, *pano_final, *pdias_a_calcular, *popcao);
        validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
        //*popcao = 2;
        //calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

        //chamando a funcao que calcula datas
        //calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
    }
     else if(*popcao == 5)
    {
        printf("\nSaber se um ano eh bissexto.\n");
        printf("Digite o ano no formato aaaa exemplo 1989.\n\n");
        printf("Digite o ano.\n");
        scanf("%lu", &*pano_final);
        *pdia_inicial = 01;
        *pmes_inicial = 01;
        *pano_inicial = 01;
        *pdia_final = 31;
        *pmes_final = 12;
        //*pano_final = 9;
        validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
    }
    else if(*popcao == 6)
    {
        printf("\nSaber anos bissextos dentro de um intervalo.\n");
        printf("Digite o ano inicial no formato aaaa exemplo 1989.\n\n");
        printf("Digite o ano.\n");
        scanf("%lu", &*pano_inicial);
        printf("Digite o ano final no formato aaaa exemplo 1989.\n\n");
        printf("Digite o ano.\n");
        scanf("%lu", &*pano_final);

        *pdia_inicial = 01;
        *pmes_inicial = 01;
        *pdia_final = 31;
        *pmes_final = 12;

        printf("\nOs anos bissextos entre %lu e %lu sao:\n\n", *pano_inicial, *pano_final);

        validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

        while(*pano_inicial >= *pano_final)
        {
            printf("\nErro. Ano inicial maior ou igual ao ano final.\n\n");
            printf("\nDigite o ano inicial no formato aaaa exemplo 1989.\n\n");
            printf("Digite o ano.\n");
            scanf("%lu", &*pano_inicial);
            printf("Digite o ano final no formato aaaa exemplo 1989.\n\n");
            printf("Digite o ano.\n");
            scanf("%lu", &*pano_final);

            *pdia_inicial = 01;
            *pmes_inicial = 01;
            *pdia_final = 31;
            *pmes_final = 12;

            printf("\nOs anos bissextos entre %lu e %lu sao:\n\n", *pano_inicial, *pano_final);

            validar_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
        }

    }

}

 void validar_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao)
 {
     int erro = 0, *cont = 0;
    /*declarando a funcao calculadora_de_datas*/
    int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);

    /*declarando a funcao capturar dados_do_teclado*/
    void captura_e_valida_dados_do_teclado(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao);

     /*Validando opcao
     while(*popcao != 1 && *popcao != 2 && *popcao != 3 && *popcao != 4)
     {
         printf("\nOpcao invalida.\n\n");
         scanf("%lu", &*popcao);
     }
     //calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
     */
    //*pdia_inicial = 01;
    //*pmes_inicial = 01;
    //*pano_inicial = 01;
    //*pdia_final = 31;
    //*pmes_final = 12;
    //*pano_final = 9;

        //Digite apenas numeros inteiros positivos para adicionar ou subtrair dias.
        if(*pdias_a_calcular < 0)
        {
            printf("\nDigite apenas numeros inteiros positivos para adicionar ou subtrair dias.\n\n");
            erro++;
        }

        //Os anos nao podem ser negativos e nem serem maiores que 9999999.
        if((*pano_inicial < 1) || (*pano_inicial > 9999999) || (*pano_final < 1) || (*pano_final > 9999999))
        {
            //printf("\nvalores da funcao %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, \n", *pdia_inicial, *pmes_inicial, *pano_inicial, *pdia_final, *pmes_final, *pano_final, *pdias_a_calcular, *popcao);
            printf("\nData invalida. Verifique os anos.\n\n");
            erro++;
        }

        //Os meses nao podem ser negativos e nem maiores que 12.
        if((*pmes_inicial < 1) || (*pmes_inicial > 12) || (*pmes_final < 1) || (*pmes_final > 12))
        {
            printf("\nData invalida. Verifique os meses.\n\n");
            erro++;
        }

        //Os dias nao podem ser negativos.
        if((*pdia_inicial < 1) || (*pdia_final < 1))
        {
            printf("\nData invalida. Verifique os dias.\nOs dias devem ser numeros inteiros maiores que 0.\n\n");
            erro++;
        }





        //Se o ano for bissexto, entao o mes de fevereiro tera 29 dias. Se nao, tera 28 dias.
        if(((*pmes_inicial == 2) && ((*pano_inicial%4 == 0) && (*pano_inicial%100 != 0) || (*pano_inicial%400 == 0))) || ((*pmes_final == 2) && ((*pano_final%4 == 0) && (*pano_final%100 != 0) || (*pano_final%400 == 0))))
        {
            if((*pdia_inicial > 29) || (*pdia_final > 29))
            {
                printf("\nData invalida. Verifique os dias. Em um ano bissexto fevereiro tem 29 dias.\n\n");
                erro++;
            }

        }
        else
        {
            if(((*pmes_inicial == 2) || (*pmes_final == 2)) && ((*pdia_inicial > 28) || (*pdia_final > 28)))
            {
                printf("\nData invalida. Verifique os dias. Em um ano nao bissexto fevereiro tem 28 dias.\n\n");
                erro++;
            }

        }

        //Se o mes for abril, ou junho, ou setembro, ou novembro, entao o mes tera 30 dias. Se nao, tera 31 dias.
        if((*pmes_inicial == 4) || (*pmes_inicial == 6) || (*pmes_inicial == 9) || (*pmes_inicial == 11))
        {
            if(*pdia_inicial > 30)
            {
                printf("\nData invalida. Verifique os dias.\nOs meses de abril, junho, setembro e novembro sao de 30 dias.\n\n\n");
                erro++;
                printf("*pdia_inicial = %lu\n*pdia_final = %lu\n", *pdia_inicial, *pdia_final);
            }
        }
        else if((*pmes_final == 4) || (*pmes_final == 6) || (*pmes_final == 9) || (*pmes_final == 11))
        {
            if(*pdia_final > 30)
            {
                printf("\nData invalida. Verifique os dias.\nOs meses de abril, junho, setembro e novembro sao de 30 dias.\n\n\n");
                erro++;
                printf("*pdia_inicial = %lu\n*pdia_final = %lu\n", *pdia_inicial, *pdia_final);
            }
        }
        else
        {
            if((*pdia_inicial > 31) || (*pdia_final > 31))
            {
                printf("\nData invalida. Verifique os dias.\nOs meses de janeiro, marco, maio, julho, agosto, outubro e dezembro\nsao de 31 dias.\n\n\n");
                erro++;
            }
        }


        //Se nao houver erro, entao chama a funcao de calculo de dat
        if(erro == 0)
        {
             //captura_e_valida_dados_do_teclado(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);


            //*pdia_inicial = 1;
            printf("\nvalores da funcao validar_datas, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu.\n", *pdia_inicial, *pmes_inicial, *pano_inicial, *pdia_final, *pmes_final, *pano_final, *pdias_a_calcular, *popcao);
            calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
            //printf("\nA funcao calculadora_de_datas foi chamada.\n");

            //*cont++;
            //printf("\ncont = %d", cont);
        }
        else
        {
            captura_e_valida_dados_do_teclado(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);
        }

        //erro == 0;
 }

int calculadora_de_datas(signed long *pdia_inicial, signed long *pmes_inicial, signed long *pano_inicial, signed long *pdia_final, signed long *pmes_final, signed long *pano_final, signed long *pdias_a_calcular, signed long *popcao)
{
    signed long i, j, dias_do_mes, mes_do_ano, dia_da_semana = 0, opcaozero = 0;
    signed long ano, mes, primeiro_dia_do_mes, cont_dias = 0, k;
    signed long maiores_dias, menores_dias, x_dias;
    signed long quant_anos = 0, guarda_dia_inicial, guarda_mes_inicial, quant_meses = 0, quant_dias = 0, quant_anos_bissextos = 0, quant_semanas = 0;
    signed long dia_inicial_r, dia_final_r, mes_inicial_r, mes_final_r, ano_inicial_r, ano_final_r, dias_a_calcular_r, opcao_r, temp_dia_r, temp_mes_r;
    signed long opcao_bissexta, dias_menos_anos;
    signed long opcao_resto, dias_remanescentes, cont_semanas;
    signed long a, m, ano_desconto, mes_desconto;
    signed long dia_inicial_d, mes_inicial_d, ano_inicial_d, dias_a_calcular_d, opcao_d;// opcao para calcular a quant_dias

    //variaveis criadas para o calcula do dia da semana.
    //todas elas tem o final _s.
    signed long dia_inicial_s, mes_inicial_s, ano_inicial_s, dia_final_s, mes_final_s, ano_final_s, dias_a_calcular_s, opcaozero_s = 0;
    signed long dia_inicial_sub, mes_inicial_sub, ano_inicial_sub, dia_final_sub, mes_final_sub, ano_final_sub, dias_a_calcular_sub, opcao_sub = 0;
    signed long dia_inicial_md, mes_inicial_md, ano_inicial_md, dia_final_md, mes_final_md, ano_final_md, dias_a_calcular_md, opcao_md;
    signed long temp_dia_inicial, temp_mes_inicial, temp_ano_inicial;

    // primeiro definir uma funcao que calcula void dia_da_semana();
    /*Fazer verificacao de entrada de dados*/

    ano = *pano_inicial;
    primeiro_dia_do_mes = *pdia_inicial;

    guarda_dia_inicial = *pdia_inicial;
    guarda_mes_inicial = *pmes_inicial;

    for(i = ano; i <= *pano_final; i++)
    {
        if(i > *pano_inicial)
        {
            quant_anos++;
        }


        if(i != *pano_final)
        {
            mes = 12;
        }
        else
        {
            mes = *pmes_final;
        }
        for(j = *pmes_inicial; j <= mes; j++)
        {
            if(j == 1)
            {

                dias_do_mes = 31;
                 /*Condicao para nao ir para o proximo mes.*/
                if (j == *pmes_final && i == *pano_final)
                {
                    j = 13;
                    primeiro_dia_do_mes = 0;
                    dias_do_mes = 0;
                    cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                }
                else
                {
                    if (cont_dias == 0)
                    {
                        primeiro_dia_do_mes = *pdia_inicial;
                    }
                    else
                    {
                        primeiro_dia_do_mes = 0;
                    }
                }

            }
            else
            {
                if(j == 2)
                {
                    //Verificar se o ano eh bissexto.
                    if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
                    {
                        dias_do_mes = 29;
                        quant_anos_bissextos++;
                        if (*popcao == 6)
                        {
                            printf("%lu\n", i);
                        }
                    }
                    else
                    {
                        dias_do_mes = 28;
                    }

                    /*Condicao para nao ir para o proximo mes.*/
                    if (j == *pmes_final && i == *pano_final)
                    {
                        j = 13;
                        primeiro_dia_do_mes = 0;
                        dias_do_mes = 0;
                        cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                    }
                    else
                    {
                        if (cont_dias == 0)
                        {
                            primeiro_dia_do_mes = *pdia_inicial;
                        }
                        else
                        {
                            primeiro_dia_do_mes = 0;
                        }
                    }
                }
                else
                {
                    if(j == 3)
                    {

                        dias_do_mes = 31;
                        /*Condicao para nao ir para o proximo mes.*/
                        if (j == *pmes_final && i == *pano_final)
                        {
                            j = 13;
                            primeiro_dia_do_mes = 0;
                            dias_do_mes = 0;
                            cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                        }
                        else
                        {
                            if (cont_dias == 0)
                            {
                                primeiro_dia_do_mes = *pdia_inicial;
                            }
                            else
                            {
                                primeiro_dia_do_mes = 0;
                            }
                        }
                    }
                    else
                    {
                        if(j == 4)
                        {

                            dias_do_mes = 30;
                             /*Condicao para nao ir para o proximo mes.*/
                            if (j == *pmes_final && i == *pano_final)
                            {
                                j = 13;
                                primeiro_dia_do_mes = 0;
                                dias_do_mes = 0;
                                cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                            }
                            else
                            {
                                if (cont_dias == 0)
                                {
                                    primeiro_dia_do_mes = *pdia_inicial;
                                }
                                else
                                {
                                    if (cont_dias == 0)
                                    {
                                        primeiro_dia_do_mes = *pdia_inicial;
                                    }
                                    else
                                    {
                                        primeiro_dia_do_mes = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (j == 5)
                            {

                                dias_do_mes = 31;
                                 /*Condicao para nao ir para o proximo mes.*/
                                if (j == *pmes_final && i == *pano_final)
                                {
                                    j = 13;
                                    primeiro_dia_do_mes = 0;
                                    dias_do_mes = 0;
                                    cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                }
                                else
                                {
                                    if (cont_dias == 0)
                                    {
                                        primeiro_dia_do_mes = *pdia_inicial;
                                    }
                                    else
                                    {
                                        if (cont_dias == 0)
                                        {
                                            primeiro_dia_do_mes = *pdia_inicial;
                                        }
                                        else
                                        {
                                            primeiro_dia_do_mes = 0;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (j == 6)
                                {

                                    dias_do_mes = 30;
                                     /*Condicao para nao ir para o proximo mes.*/
                                    if (j == *pmes_final && i == *pano_final)
                                    {
                                        j = 13;
                                        primeiro_dia_do_mes = 0;
                                        dias_do_mes = 0;
                                        cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                    }
                                    else
                                    {
                                        if (cont_dias == 0)
                                        {
                                            primeiro_dia_do_mes = *pdia_inicial;
                                        }
                                        else
                                        {
                                            if (cont_dias == 0)
                                            {
                                                primeiro_dia_do_mes = *pdia_inicial;
                                            }
                                            else
                                            {
                                                primeiro_dia_do_mes = 0;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if(j == 7)
                                    {

                                        dias_do_mes = 31;
                                         /*Condicao para nao ir para o proximo mes.*/
                                        if (j == *pmes_final && i == *pano_final)
                                        {
                                            j = 13;
                                            primeiro_dia_do_mes = 0;
                                            dias_do_mes = 0;
                                            cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                        }
                                        else
                                        {
                                            if (cont_dias == 0)
                                            {
                                                primeiro_dia_do_mes = *pdia_inicial;
                                            }
                                            else
                                            {
                                                if (cont_dias == 0)
                                                {
                                                    primeiro_dia_do_mes = *pdia_inicial;
                                                }
                                                else
                                                {
                                                    primeiro_dia_do_mes = 0;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (j == 8)
                                        {

                                            dias_do_mes = 31;
                                             /*Condicao para nao ir para o proximo mes.*/
                                            if (j == *pmes_final && i == *pano_final)
                                            {
                                                j = 13;
                                                primeiro_dia_do_mes = 0;
                                                dias_do_mes = 0;
                                                cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                            }
                                            else
                                            {
                                                if (cont_dias == 0)
                                                {
                                                    primeiro_dia_do_mes = *pdia_inicial;
                                                }
                                                else
                                                {
                                                    primeiro_dia_do_mes = 0;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (j == 9)
                                            {

                                                dias_do_mes = 30;
                                                 /*Condicao para nao ir para o proximo mes.*/
                                                if (j == *pmes_final && i == *pano_final)
                                                {
                                                    j = 13;
                                                    primeiro_dia_do_mes = 0;
                                                    dias_do_mes = 0;
                                                    cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                }
                                                else
                                                {
                                                    if (cont_dias == 0)
                                                    {
                                                        primeiro_dia_do_mes = *pdia_inicial;
                                                    }
                                                    else
                                                    {
                                                        primeiro_dia_do_mes = 0;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (j == 10)
                                                {

                                                    dias_do_mes = 31;
                                                     /*Condicao para nao ir para o proximo mes.*/
                                                    if (j == *pmes_final && i == *pano_final)
                                                    {
                                                        j = 13;
                                                        primeiro_dia_do_mes = 0;
                                                        dias_do_mes = 0;
                                                        cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                    }
                                                    else
                                                    {
                                                        if (cont_dias == 0)
                                                        {
                                                            primeiro_dia_do_mes = *pdia_inicial;
                                                        }
                                                        else
                                                        {
                                                            primeiro_dia_do_mes = 0;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    if (j == 11)
                                                    {

                                                        dias_do_mes = 30;
                                                         /*Condicao para nao ir para o proximo mes.*/
                                                        if (j == *pmes_final && i == *pano_final)
                                                        {
                                                            j = 13;
                                                            primeiro_dia_do_mes = 0;
                                                            dias_do_mes = 0;
                                                            cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                        }
                                                        else
                                                        {
                                                            if (cont_dias == 0)
                                                            {
                                                                primeiro_dia_do_mes = *pdia_inicial;
                                                            }
                                                            else
                                                            {
                                                                primeiro_dia_do_mes = 0;
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (j == 12)
                                                        {

                                                            dias_do_mes = 31;
                                                             /*Condicao para nao ir para o proximo mes.*/
                                                            if (j == *pmes_final && i == *pano_final)
                                                            {
                                                                j = 13;
                                                                primeiro_dia_do_mes = 0;
                                                                dias_do_mes = 0;
                                                                cont_dias = cont_dias + (*pdia_final - *pdia_inicial);
                                                            }
                                                            else
                                                            {
                                                                if (cont_dias == 0)
                                                                {
                                                                    primeiro_dia_do_mes = *pdia_inicial;
                                                                }
                                                                else
                                                                {
                                                                    primeiro_dia_do_mes = 0;
                                                                }
                                                            }

                                                            *pmes_inicial = 1;

                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            for(k = primeiro_dia_do_mes; k < dias_do_mes; k++)
            {
                cont_dias++;

                //contador de anos.
                if((k == 21) && (j == 5))
                {//esta condicional vai contar todos os anos. restara menos de 366 dias para a contagem dos meses, das semanas e dos dias.
                    //quant_anos++;
                    //printf("\n%lu\n", i);
                }
                if((k == guarda_dia_inicial))//tera que ser feito pelo menos um decremento, pq k ja inicia com o valor de *pdia_inicial.
                {
                    quant_meses++;
                }

                if(k <= *pdia_final)
                {
                    quant_dias++;
                    if(quant_dias % 7 == 0)
                    {
                        quant_semanas++;
                    }
                }



                if (*popcao == 2 && (*pdias_a_calcular == cont_dias))
                {
                    *pdia_final = k + 1;
                    *pmes_final = j;
                    *pano_final = i;

                    k = dias_do_mes + 1;
                    j = 13;
                    i = *pano_final + 1;
                }

            }

            *pdia_inicial = 0;

        }
    }



    //imprindo resultado
    if (*popcao == 0)
    {
        return (int)cont_dias;
    }
    else if (*popcao == 1)
    {


        /*
        if(((*pdia_final < guarda_dia_inicial) && (*pmes_final <= guarda_mes_inicial)) || ((*pdia_final == guarda_dia_inicial) && (*pmes_final == guarda_mes_inicial)))
        {
            quant_anos = quant_anos - 1;
            printf("\nquant_anos - 1");
        }
        */
        quant_anos = quant_anos - 1;

        quant_meses = (quant_meses - (quant_anos * 12));
        printf("\n\ndia_inicial_d = %lu,\nguarda_dia_inicial = %lu,\nmes_inicial_d = %lu,\nguarda_mes_inicial = %lu,\nquant_meses = %lu,\nano_inicial_d = %lu,\n*pano_inicial = %lu,\nquant_anos = %lu,\ndias_a_calcular_d = %lu,\nopcao_d = %lu.\n\n",dia_inicial_d, guarda_dia_inicial, mes_inicial_d, guarda_mes_inicial, quant_meses, ano_inicial_d, *pano_inicial, quant_anos, dias_a_calcular_d, opcao_d);

        if(*pdia_final < guarda_dia_inicial)
        {
            quant_meses = quant_meses - 1;
        }

        dia_inicial_d = guarda_dia_inicial;
        mes_inicial_d = guarda_mes_inicial + quant_meses;
        ano_inicial_d = *pano_inicial + quant_anos;
        printf("\nVerificando ano_inicial_d = %lu\nquant_anos = %lu\n", ano_inicial_d, quant_anos);
        dias_a_calcular_d = 0;
        opcao_d = 0;

        if(quant_meses >= 12)
        {
            quant_meses = quant_meses % 12;
            quant_anos++;
        }


        if(mes_inicial_d > 12)
        {
            printf("\nEntrou na condicional mes_inicial_d >= 12.\n");
            ano_inicial_d = ano_inicial_d + 1;
            mes_inicial_d = mes_inicial_d % 12;
            if(mes_inicial_d == 0)
            {
                mes_inicial_d = 12;
            }
        }
        printf("\n\ndia_inicial_d = %lu,\nguarda_dia_inicial = %lu,\nmes_inicial_d = %lu,\nguarda_mes_inicial = %lu,\nquant_meses = %lu,\nano_inicial_d = %lu,\n*pano_inicial = %lu,\nquant_anos = %lu,\ndias_a_calcular_d = %lu,\nopcao_d = %lu.\n\n",dia_inicial_d, guarda_dia_inicial, mes_inicial_d, guarda_mes_inicial, quant_meses, ano_inicial_d, *pano_inicial, quant_anos, dias_a_calcular_d, opcao_d);

        /*troca de posicao caso a primeira data seja maior que a segunda data*/
         if((ano_inicial_d > *pano_final) || ((ano_inicial_d == *pano_final) && (mes_inicial_d > *pmes_final)) || ((ano_inicial_d == *pano_final) && (mes_inicial_d == *pmes_final) && (dia_inicial_d > *pdia_final)))
         {
             printf("\nHouve troca calculadora opcao 1.\n");
             temp_dia_inicial = dia_inicial_d;
             temp_mes_inicial = mes_inicial_d;
             temp_ano_inicial = ano_inicial_d;

             dia_inicial_d = *pdia_final;
             mes_inicial_d = *pmes_final;
             ano_inicial_d = *pano_final;

             *pdia_final = temp_dia_inicial;
             *pmes_final = temp_mes_inicial;
             *pano_final = temp_ano_inicial;
         }


        printf("\nvalores da funcao calculadora_de_datas, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, \n", dia_inicial_d, mes_inicial_d, ano_inicial_d, *pdia_final, *pmes_final, *pano_final, dias_a_calcular_d, opcao_d);

        quant_dias = (calculadora_de_datas(&dia_inicial_d, &mes_inicial_d, &ano_inicial_d, &*pdia_final, &*pmes_final, &*pano_final, &dias_a_calcular_d, &opcao_d));

        quant_semanas = quant_dias / 7;

        quant_dias = quant_dias % 7;

        printf("\n");
        printf("*******************************************************************************\n");

        if(quant_anos > 0)
        {
            if(quant_anos == 1)
            {
                printf("%lu Ano ", quant_anos);
            }
            else
            {
                printf("%lu Anos ", quant_anos);
            }
        }
        if(quant_meses > 0)
        {
            if(quant_meses == 1)
            {
                printf("%lu Mes ", quant_meses);
            }
            else
            {
                printf("%lu Meses ", quant_meses);
            }

        }
        if(quant_semanas > 0)
        {
            if(quant_semanas == 1)
            {
                printf("%lu Semana ", quant_semanas);
            }
            else
            {
                printf("%lu Semanas ", quant_semanas);
            }
        }
        if(quant_dias > 0)
        {
            if(quant_dias == 1)
            {
                printf("%lu Dia ", quant_dias);
            }
            else
            {
                printf("%lu Dias ", quant_dias);
            }

        }
        if(cont_dias > 0)
        {
            printf("\nDiferenca em dias = %lu\n", cont_dias);
        }
        if(quant_anos == 0 && quant_meses == 0 && quant_semanas == 0 && quant_dias == 0 && cont_dias == 0)
        {
            printf("\nDatas iguais.\n\n");
        }

        printf("*******************************************************************************\n");





         return 0;
    }
    else if (*popcao == 2)
    {
        //calculando dia da semana.
        //o dia da semana da data 01/01/0001 eh domingo.
        //vamos chamar a funcao calculadora_de_datas e calcular a diferenca em dias ate a data inicial.
        //o resto da divisao entre os dias e 7 determinarao o dia da semana.
        //vamos passar outras variaveis para funcao afim de nao alterar o valor original.
        //o final _s identifica as variaveis que foram alteradas para o calculo do dia da semana.
        dia_final_s = *pdia_final;
        mes_final_s = *pmes_final;
        ano_final_s = *pano_final;
        dia_inicial_s = 1;
        mes_inicial_s = 1;
        ano_inicial_s = 1;
        dias_a_calcular_s = 0;
        opcaozero_s = 0;

        dia_da_semana = (calculadora_de_datas(&dia_inicial_s, &mes_inicial_s, &ano_inicial_s, &dia_final_s, &mes_final_s, &ano_final_s, &dias_a_calcular_s, &opcaozero_s) % 7);

        /*
        Na data terca-feira 01/01/0001
        Pegamos o dia da data e fazemos o seguinte calculo:
        01 % 7 = 1 (resto da divisao entre 21 e 7 eh igual a 1)
        Entao toda vez que o dia % 7 = 1 sera terca-feira.
        Se dia % 7 = 2 sera quarta-feira.
        Se dia % 7 = 3 sera quinta-feira.
        Se dia % 7 = 6 sera domingo.
        Assim por diante.
        Isto vale para qualquer data.
        */

        //dia da semana
        if(dia_da_semana == 0)
        {
            printf("\nSegunda-feira ");
        }
        else if(dia_da_semana == 1)
        {
            printf("\nTerca-feira ");
        }
        else if(dia_da_semana == 2)
        {
            printf("\nQuarta-feira ");
        }
        else if(dia_da_semana == 3)
        {
            printf("\nQuinta-feira ");
        }
        else if(dia_da_semana == 4)
        {
            printf("\nSexta-feira ");
        }
        else if(dia_da_semana == 5)
        {
            printf("\nSabado ");
        }
        else if(dia_da_semana == 6)
        {
            printf("\nDomingo ");
        }


        printf(" %02lu/%02lu/%lu\n" ,*pdia_final, *pmes_final, *pano_final);
        return 0;
    }
     else if (*popcao == 3)
    {
        //maiores_dias, diferenca em dias entre 01/01/0001 e a data digitada pelo usuario.
        //variaveis alteradas com final _md
        dia_inicial_md = 1;
        mes_inicial_md = 1;
        ano_inicial_md = 1;
        dia_final_md = *pdia_final;
        mes_final_md = *pmes_final;
        ano_final_md = *pano_final;
        dias_a_calcular_md = *pdias_a_calcular;
        opcao_md = 0;

        maiores_dias = calculadora_de_datas(&dia_inicial_md, &mes_inicial_md, &ano_inicial_md, &dia_final_md, &mes_final_md, &ano_final_md, &dias_a_calcular_md, &opcao_md);

        /*menores_dias, diferenca em dias entre a data x (data procurada) e a data digitada pelo usuario.*/
        /*essa diferenca eh informada diretamente pelo usuario quando o mesmo informa os dias a subtrair.*/
        menores_dias = *pdias_a_calcular;

        /*x_dias, diferenca entre maiores_dias e menores dias.*/
        x_dias = maiores_dias - menores_dias;

        /*vamos chamar a funcao calculadora_de_datas para calcular a data 01/01/0001 acrescentando x_dias.
        *variaveis alteradas para para nao interferir em outros calculos final _sub.
        */
        dia_final_sub = 31;
        mes_final_sub = 12;
        ano_final_sub = 9999999;

        dia_inicial_sub = 1;
        mes_inicial_sub = 1;
        ano_inicial_sub = 1;
        dias_a_calcular_sub = *pdias_a_calcular;
        opcao_sub = 2;

        calculadora_de_datas(&dia_inicial_sub, &mes_inicial_sub, &ano_inicial_sub, &dia_final_sub, &mes_final_sub, &ano_final_sub, &x_dias, &opcao_sub);

        return 0;
    }
    else if (*popcao == 4)
    {
        *pdia_inicial = 1;
        *pmes_inicial = 1;
        *pano_inicial = 1;
        *pdias_a_calcular = 0;
        *popcao = 2;
        //printf("\nvalores da funcao calculadora_de_datas, else if (*popcao == 4)...%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, \n", *pdia_inicial, *pmes_inicial, *pano_inicial, *pdia_final, *pmes_final, *pano_final, *pdias_a_calcular, *popcao);
        calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

        return 0;
    }
    else if (*popcao == 5)
    {
        //Verificar se o ano eh bissexto.
        if ((*pano_final % 4 == 0) && (*pano_final % 100 != 0) || (*pano_final % 400 == 0))
        {
            printf("\nSim. O ano %lu eh bissexto.\n", *pano_final);
        }
        else
        {
            printf("\nNao. O ano %lu nao eh bissexto.\n", *pano_final);
        }
        return 0;
    }
    else if (*popcao == 6)
    {
       // *pdia_inicial = 01;
       // *pmes_inicial = 01;
       // *pdia_final = 31;
       // *pmes_final = 12;
       // *popcao == 1;
       // calculadora_de_datas(&*pdia_inicial, &*pmes_inicial, &*pano_inicial, &*pdia_final, &*pmes_final, &*pano_final, &*pdias_a_calcular, &*popcao);

        return 0;
    }


}















    void ler_arquivo_gas_txt()
    {
        printf("\nFUNCAO LER_ARQUIVO_GAS_TXT.\n");
        signed long i, j;
        signed long id, data, dia_inicial, mes_inicial, ano_inicial,texto;
        char local_da_compra[10];


        /*criando a variavel ponteiro para o arquivo.*/
        FILE *file;

        /* "a+"	Abre um arquivo texto para gravacao e leitura. Os dados serao adicionados no fim do arquivo se ele ja existir, ou um novo arquivo sera criado, no caso de arquivo nao existente anteriormente.*/
        file = fopen("gas.txt","a+");

        /*
        if(file == NULL)
        {
            printf("\n\tERRO.\n");
            printf("\n\tArquivo nao pode ser aberto.\n");
            printf("\tO arquivo glass.data e o codigo fonte podem nao estar na mesma pasta.\n");
            exit(0);
        }
        else
        {
            printf("\n\tArquivo aberto com sucesso.\n\tDados copiados na memoria.\n\tArquivo fechado.\n\n");
        }
        */

        /*Preenchendo a matriz com os valores do arquivo.*/
        for(i = 0; i < 1; i++)
        {
            fscanf(file, "ID: %s.\n", &local_da_compra);

            printf("\nTEXTO: %s\n", local_da_compra);
        }

        /*fechando o arquivo*/
        fclose(file);

    }