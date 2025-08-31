/*
    g++ neon.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    ./a.out

    Por padrão, irei trabalhar agora apenas com a resolução de 720x480 como via de regra
*/

#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <iostream>
#include <fftw3.h>
#include <vector>
#include <string>
#include <cmath>

namespace ray{
    #include <raylib.h>
}

int main(int argc, char* argv[]){
    //metadados
    if(argc < 2){
        return EXIT_FAILURE;
    }

    TagLib::FileRef f(argv[1]);
    if(!f.isNull() && f.tag()){
        TagLib::Tag *tag = f.tag();
        std::cout << "Title: " << argv[1] << '\n';

        if(!tag->genre().isEmpty()){
            std::cout << "Genre: " << tag->genre() << '\n';
        }
        if(!tag->album().isEmpty()){
            std::cout << "Album: " << tag->album() << '\n';
        }
        if(!tag->artist().isEmpty()){
            std::cout << "Artist: " << tag->artist() << '\n';
        }
        if(tag->year() != 0){
            std::cout << "Year: " << tag->year() << '\n';
        }

        if(f.audioProperties()){
            TagLib::AudioProperties *audioProperties = f.audioProperties();
            int length {
                audioProperties->lengthInSeconds()
            };
            int minutes {
                length / 60
            };
            int seconds {
                length % 60
            };
        }
    } else {
        return EXIT_FAILURE;
    }

   //window
    ray::InitWindow(720, 480, "Neon Spectrum");
    while(!ray::WindowShouldClose()){
        ray::BeginDrawing();

        ray::EndDrawing();
    }
    ray::CloseWindow();
    return EXIT_SUCCESS;
}