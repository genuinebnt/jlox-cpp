cd build/

echo "Building project with cmake"

cmake .. -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
cmake --build . && ./tests/jlox-cpp-tests

cd ..