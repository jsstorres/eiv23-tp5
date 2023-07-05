#include "comandos.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "timer_config.h"
#include "usart_config.h"

bool verificar_comandos(char * buffer, Comando_SCPI * cmd){
    if(strcmp(buffer,"reset")==0){
        cmd->comando=RST;
        cmd->ang=0;
        return true;
    //se fija si luego de la cadena "setea_ang" se introdujo UN numero entero, y luego se almacena en la variable
    //cmd->ang   
    }else if(sscanf(buffer,"setea_ang %d",&(cmd->ang))==1){    
        cmd->comando=setea_ang;
        if(cmd->ang <0 ||cmd->ang >180){
            cmd->comandoValido=false;
        }else{
            cmd->comandoValido=true;
        }
        return true;
    }else if(strcmp(buffer,"consulta_ang")==0){
        cmd->comando=consulta_ang;
        //cmd->comandoValido=true;
        return true;
    }else{
        cmd->comando=DESCONOCIDO;
        return true;
    }
}