#include <iostream>
#include <vector>
#include <algorithm>
#include <valarray>

using namespace std;

void countcols(auto& matrix, auto& res) {
    fill(res.begin(), res.end(), 0);
    for (int i = 0; i < res.size(); ++i) {
        for (auto& it : matrix) {
            if (it[i] == 'Y') { res[i]++; }
        }
    }
}


void getways(auto matrix, auto _res, int& way){
    if(!matrix.size()){
        return;
    }
    way++;
    cout << endl;
    auto max_choose = max_element(_res.begin(), _res.end());
    erase_if(matrix, [maxelempos = max_choose - _res.begin()](auto it){
        return it[maxelempos] == 'Y';
    });
    countcols(matrix, _res);
    return getways(matrix, _res, way);
}

int choose2(auto matrix) {
    int result{0};
    int iter{0};
    vector<int> res(matrix[0].size());
    countcols(matrix, res);
    auto doonecombination = [&matrix,&res,&iter]{
        getways(matrix,res,iter);
        auto posmax = max_element(res.begin(), res.end());
        *posmax =  0;
    };
    doonecombination();
    result = iter;
    for(int i=0; i<matrix[0].size()-2; ++i){
        iter = 0;
        doonecombination();
        if(iter < result){result = iter;}
    }

    cout << endl << "Min is - ";
    return iter;
}

int main(){
    int N,B;
    cin >> N >> B;
    vector<string> chs(N);
    for(auto& it : chs){
        cin >> it;
    }
    cout << choose2(chs);
    return 0;
}