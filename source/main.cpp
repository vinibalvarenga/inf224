#include <iostream>
#include "Photo.h"
#include "Video.h"
using namespace std;

int main(int argc, const char* argv[])
{
    // Cria uma instância da classe Photo
    Photo* photo = new Photo("Foto1", "/Users/vinibalvarenga/Documentos/Telecom/1A/Creneau_D/Paradigmes/tp1/photos/drosil.jpg", 40.7128, 74.0060);
    photo->display(cout);
    photo->play();

    // Cria uma instância da classe Video
    Video* video = new Video("Video1", "/Users/vinibalvarenga/Documentos/Telecom/1A/Creneau_D/Paradigmes/tp1/Videos/video.jpeg", 120);
    video->display(cout);
    video->play();

    // Não se esqueça de deletar os objetos quando terminar de usá-los
    delete photo;
    delete video;

    return 0;
}
