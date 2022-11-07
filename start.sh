if [ -d "build/bin" ]
then
    cd build/bin
    ./server "$1"
else
    echo "Run build.sh First"
fi       