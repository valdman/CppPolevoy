#include "ssv_service.h"

using namespace std;

int ui(bool isDataLoaded) {
    int responseCode(-1);


    return responseCode;
}

int main() {
    SsvService ssvService;
    Ssv ssv;

    cout << "Enter .csv filepath: ";
    string filePath;
    std::getline(cin, filePath);

    ssv = ssvService.parseSsvFromFile(filePath);

    ssvService.printSsv(cout, ssv, 10);

    return 0;
}