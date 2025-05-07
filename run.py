import os

if os.path.exists("main"):
    os.remove("main")
os.system("g++ -fPIC main.cpp helpers.cpp -lSDL2 -lSDL2main -lSDL2_image -o main")
os.system("./main")