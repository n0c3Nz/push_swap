#!/bin/bash

# Ruta al directorio que contiene tus archivos .c
directorio="./"

# Bucle para procesar cada archivo .c en el directorio
for archivo in "$directorio"/*.c; do
    # Obtener el título del archivo sin la extensión .c
    titulo=$(basename "$archivo" .c)
    
    # Contar las líneas que comienzan con 'int' o 'void' en el archivo
    num_lineas=$(grep -e '^\(int\|void\)' "$archivo" | wc -l)
    
    # Determinar si mostrar ❌ o ✅
    if [ "$num_lineas" -gt 5 ]; then
        resultado="$num_lineas ❌"
    else
        resultado="$num_lineas ✅"
    fi
    
    echo -e "Fichero:\t  $titulo"
    echo "Resultado: $resultado"
    echo "----------------------------------"
done
