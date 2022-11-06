if [ -d "build/bin" ]
then
    cd build/bin
    ./server
else
    echo "Run build.sh First"
fi       