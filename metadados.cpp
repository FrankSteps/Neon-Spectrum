/*
    C++ like a boss: no namespaces >:)
*/

#include <iostream>
#include <taglib/fileref.h>
#include <taglib/tag.h>

int main (int argc, char* argv[]){
    if (argc < 2){
        std::cout << "error\n";
        return EXIT_FAILURE;
    }

    TagLib::FileRef f(argv[1]);
    if (!f.isNull() && f.tag()){
        TagLib::Tag *tag = f.tag();
        std::cout << "Title:    " << argv[1] << '\n';

        //(*tag).genre()    ::::::     tag->year()
        if (!(*tag).genre().isEmpty()){
            std::cout << "genre:    " << (*tag).genre() << '\n';
        }
        if (!(*tag).album().isEmpty()){
            std::cout << "album:    " << (*tag).album() << '\n';
        }
        if (!(*tag).artist().isEmpty()){
            std::cout << "artist:   " << (*tag).artist() << '\n';
        }
        if ((*tag).year() != 0){
            std::cout << "year:     " << (*tag).year() << '\n';
        }

        if (f.audioProperties()){
            TagLib::AudioProperties *audioProperties = f.audioProperties();
            int length {(*audioProperties).lengthInSeconds()};
            int minutes {length / 60};
            int seconds {length % 60};

            std::cout << "Duration: " << minutes << "m" << seconds << "s\n";
        }
        
    } else {
        std::cout << "error\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}