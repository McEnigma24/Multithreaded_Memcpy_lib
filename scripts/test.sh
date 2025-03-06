#!/bin/bash

DIR_BUILD="build"

if ls | grep $DIR_BUILD; then

    cmake -S . -B $DIR_BUILD; cmake --build $DIR_BUILD
    cd $DIR_BUILD
    ctest --rerun-failed --output-on-failure

else
    echo "wrong directory - cd scripts"
fi