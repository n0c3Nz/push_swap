#!/bin/bash

# Ruta al directorio que contiene tus archivos .c
directorio="./"

# Obtener los códigos de color para verde y rojo
verde=$(tput setaf 2)
rojo=$(tput setaf 1)
reset=$(tput sgr0)

# Bucle para procesar cada archivo .c en el directorio
for archivo in "$directorio"/*.c; do
    # Obtener el título del archivo sin la extensión .c
    titulo=$(basename "$archivo" .c)
    
    # Contar las líneas que comienzan con 'int' o 'void' en el archivo
    num_lineas=$(grep -e '^\(int\|void\|char\|bool\|const\|t_stack\)' "$archivo" | wc -l)
    
    # Determinar el color del texto
    if [ "$num_lineas" -gt 5 ]; then
        resultado="${rojo}$num_lineas ❌${reset}"  # Rojo
    else
        resultado="${verde}$num_lineas ✅${reset}"  # Verde
    fi
    
    echo -e "Fichero:\t  $titulo"
    echo -e "Resultado: $resultado"
    echo "----------------------------------"
done
