Webserver From Scratch
========================
# What is this?
This is a simple webserver written in C++ using unix sockets. It can serve html pages(no css or js files supported yet).

# How to use?

Make an html file in the /web directory.

```
./web/index.html
```

First build the project using shell script provided

```
./build.sh
```

Start the webserver on the desired port using the script provided

```
./start.sh <PORT>
```

Open up a browser and search for the file, for example-

```
localhost:<PORT>/web/index.html
```
