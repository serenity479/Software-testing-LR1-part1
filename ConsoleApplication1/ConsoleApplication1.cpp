#include <iostream>
#include <vector>

std::vector<double> arraySumModifier(std::vector<double>& arr) {

    if (arr.empty()) {
        throw std::invalid_argument("Error: empty array");
    }

    int n = arr.size();
    std::vector<double> sums;

    // Вычисляем суммы пар элементов
    for (int i = 0; i < n / 2; ++i) {
        sums.push_back(arr[i] + arr[n - 1 - i]);
    }

    // Умножаем центральный элемент на 2 если массив нечетный и добавим в массив сумм
    if (n % 2 != 0) {
        int centralIndex = n / 2;
        arr[centralIndex] *= 2;
        sums.push_back(arr[centralIndex]);
    }

    return sums;
}


double arrayMaxFinder(std::vector<double>& sums) {

    // Поиск максимума среди сумм
    double maxSum = std::numeric_limits<double>::lowest();
    for (double sum : sums) {
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}
  

    

int main() {
    try {
	    std::vector<double> arr = {1, 2, 4, 7, 5, 12, 27, 1, 8, 9, 14  };

	    arr = arraySumModifier(arr);
        double maxSumElem = arrayMaxFinder(arr);

        std::cout << "Modified array: ";
        for (double num : arr) {
            std::cout << num << " ";
        }

	    std::cout << "\n" << "Maximum sum elem: " << maxSumElem << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
