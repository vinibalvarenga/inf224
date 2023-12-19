#include <iostream>
#include "Photo.h"
#include "Video.h"
using namespace std;

int main(int argc, const char* argv[])
{
   
   const int NUM_ITEMS = 4;
    Multimedia* items[NUM_ITEMS];

    items[0] = new Photo("Foto1", "/Users/vinibalvarenga/Documentos/Telecom/1A/Creneau_D/Paradigmes/tp1/photos/drosil.jpg", 40.7128, 74.0060);
    items[1] = new Video("Video1", "/Users/vinibalvarenga/Documentos/Telecom/1A/Creneau_D/Paradigmes/tp1/videos/video1.mp4", 120);
    items[2] = new Photo("Foto2", "/Users/vinibalvarenga/Documentos/Telecom/1A/Creneau_D/Paradigmes/tp1/photos/vini.jpg", 40.7128, 50);
    items[3] = new Video("Video2", "/Users/vinibalvarenga/Documentos/Telecom/1A/Creneau_D/Paradigmes/tp1/videos/video2.mp4", 120);

    for (int i = 0; i < NUM_ITEMS; i++) {
        items[i]->display(cout);
        items[i]->play();
    }

    for (int i = 0; i < NUM_ITEMS; i++) {
        delete items[i];
    }

    return 0;
}
