#ifndef COMANDOS_H
#define COMANDOS_H

#include "stm32f1xx.h"
#include <stdbool.h>

typedef enum{
    RST,
    setea_ang,
    consulta_ang,
    DESCONOCIDO
}Comandos;

typedef struct{
    Comandos comando;
    int ang;
    bool comandoValido;
}Comando_SCPI;


bool verificar_comandos(char * buffer, Comando_SCPI * cmd);

#endif