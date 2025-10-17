#!/usr/bin/env sh

cd assets/shaders/ || exit

for dir in */ ; do
    cd "$dir" || exit
    for file in *.vert *.frag; do
        [ -e "$file" ] || continue
        glslc "$file" -o "${file}.spv"
    done
    cd .. || exit
done

cd .. || exit
