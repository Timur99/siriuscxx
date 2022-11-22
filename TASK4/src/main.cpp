#include <iostream>
#include <lodepng.h>
#include <vector>
#include <cstdint>
#include <string>
using namespace std;

void decodeFromPng(std::vector<unsigned char>& image, const char* filename, unsigned height, unsigned width) {
    /*
     * Функция для чтения png файла
     */
    std::vector<unsigned char> png;
    //load and decode
    unsigned error = lodepng::load_file(png, filename);
    if(!error) error = lodepng::decode(image, width, height, png);

    //if there's an error, display it
    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ... 
}

void getBlueChannel(const std::vector<unsigned char>& image, int** arr, int rows, int cols) {
    /*
     * Функция, которая выделяет синий канал из одномерного вектора и
     * заполняет им двумерный массив
     */
    for (int i = 2, j = 0, k = 0; i < image.size(); i += 4, ++k) {
        if (k == cols) {
            k = 0; // обнуляем номер столбца
            ++j; // увеличиваем номер строки
        }
        arr[j][k] = int(image[i]);
    }
}
void printArray(int** arr, int rows, int cols) { 
    /*
     * Функция для вывода массива в консоль
     */
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;    
    }
}

void drawPath(const vector<int>& path, vector<unsigned char>& image, int rows, int cols, const char* output_file) {
    int i = 0, j = -1;
    int previousPoint = -1;
    for (auto& e : path) {
        if (previousPoint == e)
            ++i;
        else
            j = e;
        previousPoint = e;
        // draw red path R = 255, G = 0, B = 0
        int index = (i*cols + j)*4;
        image[index] = (unsigned char)255;
        image[++index] = (unsigned char)0;
        image[++index] = (unsigned char)0;
    }


    
    //Encode the image
    unsigned error = lodepng::encode(output_file, image, cols, rows);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

void findOptimalPath(int** arr, vector<int>& path, int x_i, int x_f, int rows, int cols) {
    //--------------------------------------------------------------------------------
    // Напишите ваш код здесь

    int** dist_array = new int*[rows];
    int** path_array = new int*[rows];
    for (int i = 0; i < rows; i++ ){
        dist_array[i] = new int[cols];
        path_array[i] = new int[cols];
    }
    *((*dist_array) + x_i) = 0;
    for (int i = x_i + 1; i < cols; i++){
        *((*dist_array) + i) = *((*dist_array) + i - 1) + (1 + *((*arr) + i));
        path_array[0][i] = 3;
    }

    for (int i = x_i - 1; i >= 0; i--){
        *((*dist_array) + i) = *((*dist_array) + i + 1) + (1 + *((*arr) + i));
        path_array[0][i] = 1;
    }

    for (int i = 1; i < rows; i++){
        *(*(dist_array + i)) = *(*(dist_array + i - 1)) + *(*(arr + i)) + 1;
        path_array[i][0] = 2;
        for (int j = 1; j < cols; j++){
            if  (*(*(dist_array + i) + j - 1) < *(*(dist_array + i - 1) + j)){
                *(*(dist_array + i) + j) = *(*(dist_array + i) + j - 1) + *(*(arr + i) + j) + 1;
                path_array[i][j] = 3;
            } else {
                *(*(dist_array + i) + j) = *(*(dist_array + i - 1) + j) + *(*(arr + i) + j) + 1;
                path_array[i][j] = 2;
            }
        }

        for (int j = cols - 1; j >= 0; j--){
            if (*(*(dist_array + i) + j) > *(*(dist_array + i) + j + 1) + *(*(arr + i) + j) + 1){
                *(*(dist_array + i) + j) = *(*(dist_array + i) + j + 1) + *(*(arr + i) + j) + 1;
                path_array[i][j] = 1;
            }
        }
    }
    int i = cols - 1;
    int j = x_f;
    vector<int> reverse_path = vector<int>();
    while (!(i == 0 && j == x_i)){
        reverse_path.push_back(j);
        if (path_array[i][j] == 1){
            j++;
        }
        else if (path_array[i][j] == 2){
            i--;
        }
        else if (path_array[i][j] == 3){
            j--;
        }
    }

    reverse_path.push_back(j);

    for (int i = reverse_path.size() - 1; i >= 0; i--){
        path.push_back(reverse_path[i]);
    }

    for (int row = 0; row < rows; ++row ){
        delete[] dist_array[row];
    }
    delete dist_array;

    for (int row = 0; row < rows; ++row ){
        delete[] path_array[row];
    }
    delete path_array;
    return;




    //path.push_back();
    //--------------------------------------------------------------------------------
}

int main(int argc, char* argv[]) {
    
    if (argc != 7) {
        cerr << "Wrong input arguments" << endl;
        return -1;
    }
    int rows = stoi(argv[2]), cols = stoi(argv[3]); // определение строк и столбцов как у матрицы в математике
    int x_i = stoi(argv[4]), x_f = stoi(argv[5]);
    char *input_file = argv[1], *output_file = argv[6];
    // читаем png изображение
    std::vector<unsigned char> image; // vector to store value of pixels with all 4 channels RGBA
    decodeFromPng(image, input_file, rows, cols); // read png file
    
    // способ 3 стр. 115 создания двумерного массива
    // выделяем память
    
    int** arr = new int*[rows];
    for (int row = 0; row < rows; ++row )
        arr[row] = new int[cols];

    // инициализируем выделенный массив arr синим каналом нашего изображения
    getBlueChannel(image, arr, rows, cols);  

    // можно опционально выводить массив в консоль для отладки 
    printArray(arr, rows, cols);  
    
    //функцию ниже вам нужно реализовать
    //-----------------------------------------------------------------------------
    vector<int> path;  // вектор к которому нужно делать push_back для добавления точек пути 
    findOptimalPath(arr, path, x_i, x_f, rows, cols);
   //------------------------------------------------------------------------------


    // далее можно отрисовать path используя фукцию ниже
    drawPath(path, image, rows, cols, output_file);

    // очищаем память
    for (int row = 0; row < rows; ++row )
        delete[] arr[row];
    delete arr;
    getchar();
}

