#include <iostream>
#include <unistd.h>
#include <string>
#include <memory>

#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"

using namespace std;

void testMultimedia();
void testFilm();
void testGroup();
std::string get_working_path();

const std::string PATH = get_working_path() + "/";

int main(int argc, const char* argv[])
{
    

   // testMultimedia(); 
    // testFilm();
    testGroup();

    return 0;
}

void testMultimedia() {
    const int NUM_MULTIMEDIA_ITEMS = 4;
    Multimedia* multimedia_items[NUM_MULTIMEDIA_ITEMS];

    multimedia_items[0] = new Photo("Foto1", PATH + "photos/drosil.jpg", 40, 74);
    multimedia_items[1] = new Video("Video1", PATH + "videos/video1.mp4", 120);
    multimedia_items[2] = new Photo("Foto2", PATH + "photos/vini.jpg", 40, 50);
    multimedia_items[3] = new Video("Video2", PATH + "videos/video2.mp4", 120);

    for (int i = 0; i < NUM_MULTIMEDIA_ITEMS; i++) {
        multimedia_items[i]->display(cout);
        multimedia_items[i]->play();
    }

    for (int i = 0; i < NUM_MULTIMEDIA_ITEMS; i++) {
        delete multimedia_items[i];
    }
}

void testFilm() {
    const int NUM_ITEMS = 2;
    Multimedia* film_items[NUM_ITEMS];

    int* chaptersDuration1 = new int[5]{10, 20, 30, 40, 50};
    film_items[0] = new Film("Film1", PATH + "videos/video1.mp4", 150, 5, chaptersDuration1);

    int* chaptersDuration2 = new int[5]{60, 70, 80, 90, 100};
    film_items[1] = new Film("Film2", PATH + "videos/video2.mp4", 200, 5, chaptersDuration2);

    for (int i = 0; i < NUM_ITEMS; i++) {
        film_items[i]->display(cout);
        film_items[i]->play();
    }

    // Modificar a matriz e verificar se a matriz interna não foi afetada
     chaptersDuration1[0] = 100;

    cout << "Esta é uma mensagem simples." << endl;
    film_items[0]->display(cout);

    // Limpar a memória
     for (int i = 0; i < NUM_ITEMS; i++) {
        delete film_items[i];
    }
}

void testGroup() {
    // Criar objetos
    std::shared_ptr<Photo> photo1 = std::make_shared<Photo>("Photo1", PATH + "photos/drosil.jp", 100, 200);
    std::shared_ptr<Video> video1 = std::make_shared<Video>("Video1", PATH + "videos/video1.mp4", 120);
    std::shared_ptr<Film> film1 = std::make_shared<Film>("Film1", PATH + "videos/video2.mp4", 180, 0, nullptr);

    // Criar grupos
    Group group1("Group1");
    Group group2("Group2");
    Group group3("Group3");

    // Adicionar objetos aos grupos
    group1.addElement(photo1);
    group1.addElement(video1);

    group2.addElement(video1);
    group2.addElement(film1);

    group3.addElement(photo1);
    group3.addElement(film1);

    // Exibir grupos
    cout << "Group1:" << endl;
    group1.display(cout);

    cout << "Group2:" << endl;
    group2.display(cout);

    cout << "Group3:" << endl;
    group3.display(cout);
}

std::string get_working_path()
{
   char temp[1024];
   return ( getcwd(temp, sizeof(temp)) ? std::string( temp ) : std::string("") );
}