#include <iostream>
#include <string>

using namespace std;

void decrypt(const string& data, int cols){
    char matrix[100][100];
    int rows = data.length()/cols;

    if(data.length()!=rows*cols) {printf("data.length != rows * cols!\n"); return;}

    int pos = 0;
    for(int i = 0; i < rows; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < cols; j++)
            {
                matrix[i][j] = data[pos++];
            }
        }
        else
        {
            for( int j = cols -1; j >= 0; j--)
            {
                matrix[i][j] = data[pos++];
            }
        }
    }

    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            printf("%c",matrix[j][i]);
        }
    }
    printf("\n");
}

int main(){
    int N;
    string data;
    cin>>N>>data;
    decrypt(data,N);
    return 0;
}
