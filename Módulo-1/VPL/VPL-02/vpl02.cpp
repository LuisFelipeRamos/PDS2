#include <iostream>
#include <string>

void printWithoutDuplicates(int v[], int vCount){
    for (int i = 0; i < vCount; i++){
        int count = 0;
        for (int j = 0; j < i; j++){
            if (v[i] == v[j]){
                count++;
            }
        }
        if (count == 0){
            std::cout << v[i] << ' ';
        }
    }
}

int main(){
    int even[20];
    int odd[20];
    int evenCount = 0;
    int oddCount = 0;
    int aux;
    while (std::cin >> aux){
        if (aux % 2 == 0){
            even[evenCount] = aux;
            evenCount++;
        }
        else{
            odd[oddCount] = aux;
            oddCount++;
        }
    }

    printWithoutDuplicates(even, evenCount);
    std::cout << std::endl;
    printWithoutDuplicates(odd, oddCount);
    return 0;
}

