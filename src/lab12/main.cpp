//clang         Работа с бинарными файлами      Запись      Листинг #1
#include <fstream>

using namespace std;

int main() {
   const char* FName = "test.txt";       //Путь к файлу

    int x = 100;                                //Переменные для записи
    double y = 5.988;

   /*РАБОТА С БИНАРНЫМ ФАЙЛОМ*/
   fstream out(FName, fstream::out | fstream::binary);            //Ставим режим "бинарный файл"
        out.write((char*)&x,sizeof(int));    
        out.write((char*)&y,sizeof(double));      
  
   out.close();                                 //Сохраняем файл
   /*КОНЕЦ РАБОТЫ С БИНАРНЫМ ФАЙЛОМ*/
}