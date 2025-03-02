#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <fichier>"
    exit 1
fi

input_file="$1"

if [ ! -f "$input_file" ]; then
    echo "Erreur: fichier non trouvé"
    exit 1
fi

sed -i -E 's/ - .*\.out/.out/g' "$input_file"
sed -i -E 's/\.out//g' "$input_file"
sed -i -E 's/Result:.*//g' "$input_file"

diff test_reference "$input_file"
