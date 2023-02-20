#!/bin/bash

# Definir la carpeta de origen y destino

# Asignar los argumentos a variables
origen="$1"
destino="$2"

# Buscar todos los archivos con la extensión .svg en la carpeta de origen
archivos_svg=$(find $origen -type f -name "*.svg")

# Iterar sobre los archivos svg encontrados y aplicar el comando 'cat'
for archivo in $archivos_svg
do
  new_name="$(echo $archivo | sed -e 's/.svg/.png/g')"
  inkscape -w 1024 "$archivo" -o "$new_name" > /dev/null 2>&1
  echo "$new_name convertido"
  pngquant -f $new_name -o $new_name
done

# Mover los archivos svg a la carpeta de destino
mv *.png ../
echo "imagenes moved"